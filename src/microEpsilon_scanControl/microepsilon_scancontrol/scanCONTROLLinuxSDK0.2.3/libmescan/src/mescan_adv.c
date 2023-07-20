/*
 * This file is part of linllt.
 *
 * Copyright (C) Micro-Epsilon Messtechnik GmbH & Co. KG
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA or visit https://www.gnu.org/licenses/
 * lgpl.html.
 * 
 */

#include <mescan.h>

/*
 * define structs
 */

// polling buffer data&state struct
typedef struct polling_buffer_t {
    void *buffer;     // data buffer
    void *buffer_end; // end of data buffer
    size_t capacity;  // maximum number of items in the buffer
    size_t count;     // number of items in the buffer
    size_t item_size; // size of each item in the buffer
    guint32 overwritten_data;
    void *head; // pointer to head
    void *tail; // pointer to tail
} polling_buffer_t;

// LLT struct with scanner state
struct LLT {
    ArvCamera *camera;
    ArvStream *stream;
    ArvDevice *device;
    const char *device_id;

    gboolean is_transmitting;
    gboolean is_connected;
    TProfileConfig profile_config;

    TTransferProfileType profile_type;
    TScannerType scanner_type;

    guint32 resolution;
    guint32 buffer_ct;
    guint32 holding_buffer_ct;
    const char *path_device_properties;

    MEDeviceData device_data;
    TPartialProfile partial_profile;

    double scaling;
    double offset;

    gpointer user_data_buffer_callback;
    gpointer user_data_control_lost_callback;

    polling_buffer_t holding_buffer;

    void (*cast_register_buffer_callback)(const void *, size_t, gpointer);
    void (*cast_register_control_lost_callback)(gpointer);

    guint32 nice_value;
    guint32 realtime_priority;
    TStreamPriorityState stream_priority_state;
};

/*
 * aravis callbacks
 */
static void stream_callback(void *user_data, ArvStreamCallbackType, ArvBuffer *);
static void buffer_callback(ArvStream *stream, LLT *hllt);
static void control_lost_callback(ArvGvDevice *device, LLT *hllt);

/*
 * functions for polling buffer (FIFO)
 */
static gint32 pb_init(polling_buffer_t *pb, size_t capacity, size_t item_size);
static void pb_free(polling_buffer_t *pb);
static void pb_insert_data_to_head(polling_buffer_t *pb, const void *item);
static gint32 pb_get_data_from_tail(polling_buffer_t *pb, void *item);
static void pb_set_buffer_size(polling_buffer_t *pb, size_t holding_buffer_ct, size_t data_size);

// Allocate and init polling buffer
gint32 pb_init(polling_buffer_t *pb, size_t capacity, size_t item_size)
{
    pb->buffer = malloc(capacity * item_size);
    if (pb->buffer == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    pb->buffer_end = (char *)pb->buffer + capacity * item_size;
    pb->capacity = capacity;
    pb->count = 0;
    pb->overwritten_data = 0;
    pb->item_size = item_size;
    pb->head = pb->buffer;
    pb->tail = pb->buffer;
    return GENERAL_FUNCTION_OK;
}

// create new empty polling buffer with new size
gint32 pb_free_and_resize(polling_buffer_t *pb, size_t capacity, size_t item_size)
{
    free(pb->buffer);
    pb->buffer = malloc(capacity * item_size);
    if (pb->buffer == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    pb->buffer_end = (char *)pb->buffer + capacity * item_size;
    pb->capacity = capacity;
    pb->count = 0;
    pb->item_size = item_size;
    pb->head = pb->buffer;
    pb->tail = pb->buffer;
    return GENERAL_FUNCTION_OK;
}

// free polling buffer
void pb_free(polling_buffer_t *pb)
{
    free(pb->buffer);
    pb->buffer = NULL;
    pb->head = NULL;
    pb->tail = NULL;
    pb->buffer_end = NULL;
}

// insert data to polling buffer
void pb_insert_data_to_head(polling_buffer_t *pb, const void *item)
{
    if (pb->count == pb->capacity) {
        pb->overwritten_data++;
    }
    memcpy(pb->head, item, pb->item_size);
    pb->head = (char *)pb->head + pb->item_size;
    if (pb->head == pb->buffer_end) {
        pb->head = pb->buffer;
    }
    pb->count++;
}

// get data from polling buffer
gint32 pb_get_data_from_tail(polling_buffer_t *pb, void *item)
{
    if (pb->count == 0) {
        return ERROR_PROFTRANS_NO_NEW_PROFILE;
    }
    memcpy(item, pb->tail, pb->item_size);
    pb->tail = (char *)pb->tail + pb->item_size;
    if (pb->tail == pb->buffer_end) {
        pb->tail = pb->buffer;
    }
    pb->count--;
    pb->overwritten_data = 0;
    return pb->item_size;
}

// set polling buffer size
void pb_set_buffer_size(polling_buffer_t *pb, size_t holding_buffer_ct, size_t data_size)
{
    if (pb->buffer == NULL) {
        pb_init(pb, holding_buffer_ct, data_size);
    } else if (pb->capacity != holding_buffer_ct || pb->item_size != data_size) {
        pb_free_and_resize(pb, holding_buffer_ct, data_size);
    }
}

/*
 * functions for writing to sequectial register of sensor (EXTRA parameter / Sharpness)
 */

static gint32 write_value(LLT *hllt, gushort value, guint32 *toggle);
static gint32 write_command(LLT *hllt, guint32 command, guint32 data, guint32 *toggle);

// write command for sequenciell register
gint32 write_command(LLT *hllt, guint32 command, guint32 data, guint32 *toggle)
{
    gint32 ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, (guint32)(command << 9) + (*toggle << 8) + data);
    if (*toggle == 1) {
        *toggle = 0;
    } else {
        *toggle = 1;
    }
    return ret;
}

// write value in sequenciell register
gint32 write_value(LLT *hllt, gushort value, guint32 *toggle)
{
    gint32 ret = 0;
    if ((ret = write_command(hllt, 1, (guint32)(value / 256), toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_command(hllt, 1, (guint32)(value % 256), toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    return GENERAL_FUNCTION_OK;
}

/*
 * function for reading/writing dump file
 */

static gint32 write_register_to_string(LLT *hllt, char *str, guint32 register_address, const char *comment);

gint32 write_register_to_string(LLT *hllt, char *str, guint32 register_address, const char *comment)
{
    gint32 ret = 0;
    guint32 feature = 0;
    int pos = 0;
    if ((ret = get_feature(hllt, register_address, &feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // write string in hex
    if (comment != NULL) {
        pos += sprintf(str, "setq 0x%08x 0x%08x #%s\n", register_address, feature, comment);
    } else {
        pos += sprintf(str, "setq 0x%08x 0x%08x\n", register_address, feature);
    }
    return pos;
}

/**
 * SECTION: mescan_adv
 * @short_description: Advanced control and data handling of scanCONTROL sensors
 *
 * #mescan_adv contains function for advanced control and data handling of scanCONTROL sensors
 * It is to be used with the aravis framework
 */

/**
 * create_llt_device:
 *
 * Constructor for scanCONTROL instances
 *
 * Returns: a LLT instance
 *
 * Since: 0.2.0
 */
LLT *create_llt_device()
{
    LLT *hllt = malloc(sizeof(LLT));

    hllt->camera = NULL;
    hllt->device = NULL;
    hllt->stream = NULL;
    hllt->device_id = NULL;

    hllt->is_connected = false;
    hllt->is_transmitting = false;
    hllt->profile_config = NONE;
    hllt->profile_type = NONE_TRANSFER;
    hllt->scanner_type = StandardType;

    hllt->resolution = 0;
    hllt->buffer_ct = 0;
    hllt->holding_buffer_ct = 0;
    hllt->path_device_properties = NULL;

    memset(&hllt->device_data, 0, sizeof(MEDeviceData));
    memset(&hllt->partial_profile, 0, sizeof(TPartialProfile));
    memset(&hllt->holding_buffer, 0, sizeof(polling_buffer_t));

    hllt->scaling = 0.0;
    hllt->offset = 0.0;

    hllt->user_data_buffer_callback = NULL;
    hllt->cast_register_buffer_callback = NULL;
    hllt->user_data_control_lost_callback = NULL;
    hllt->cast_register_control_lost_callback = NULL;

    hllt->nice_value = -10;
    hllt->realtime_priority = 10;
    hllt->realtime_priority = PRIO_NOT_SET;

    return hllt;
}

/**
 * del_device:
 * @hllt: a LLT instance
 *
 * Destructor for scanCONTROL instances
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 del_device(LLT *hllt)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->is_connected) {
        disconnect_llt(hllt);
    }
    free(hllt);
    return GENERAL_FUNCTION_OK;
}

/**
 * get_medevice_data:
 * @hllt: a LLT instance
 *
 * Getter for scanCONTROL device data
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 get_medevice_data(LLT *hllt, MEDeviceData **device_data)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (device_data != NULL) {
        *device_data = &hllt->device_data;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_stream_statistics:
 * @hllt: a LLT instance
 * @completed_buffers: pointer to completed buffer variable
 * @failures: pointer to failure variable
 * @underruns: pointer to underruns variable
 *
 * Outputs the stream statistics of current transmission.
 * To be called while transmission is running.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 get_stream_statistics(LLT *hllt, guint64 *completed_buffers, guint64 *failures, guint64 *underruns)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (hllt->stream == NULL) {
        return ERROR_TRANSMISSION_CANCEL_NO_TRANSMISSION_ACTIVE;
    }
    arv_stream_get_statistics(hllt->stream, completed_buffers, failures, underruns);
    return GENERAL_FUNCTION_OK;
}

/**
 * get_stream_nice_value:
 * @hllt: a LLT instance
 *
 * Getter for user nice value. Negative values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 get_stream_nice_value(LLT *hllt, guint32 *nice_value)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (nice_value != NULL) {
        *nice_value = hllt->nice_value;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_stream_priority:
 * @hllt: a LLT instance
 *
 * Getter for scheduler priority value. Higher values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 get_stream_priority(LLT *hllt, guint32 *realtime_priority)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (realtime_priority != NULL) {
        *realtime_priority = hllt->realtime_priority;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_stream_priority_state:
 * @hllt: a LLT instance
 *
 * Getter for scheduler priority state. Informs about status of stream thread priority.
 * To be called after transmission was started.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 get_stream_priority_state(LLT *hllt, TStreamPriorityState *stream_priority_state)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (stream_priority_state != NULL) {
        *stream_priority_state = hllt->stream_priority_state;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_stream_nice_value:
 * @hllt: a LLT instance
 * @nice: nice value to set
 *
 * Setter for user nice value. Negative values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 set_stream_nice_value(LLT *hllt, guint32 nice)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (nice < -20 || nice > 19) {
        return ERROR_GENERAL_VALUE_NOT_ALLOWED;
    }
    hllt->nice_value = nice;
    return GENERAL_FUNCTION_OK;
}

/**
 * set_stream_priority:
 * @hllt: a LLT instance
 * @priority: prio to set
 *
 * Setter for scheduler priority value. Higher values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 set_stream_priority(LLT *hllt, guint32 priority)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (priority > 99) {
        return ERROR_GENERAL_VALUE_NOT_ALLOWED;
    }
    hllt->realtime_priority = priority;
    return GENERAL_FUNCTION_OK;
}

/**
 * set_ethernet_heartbeat_timeout:
 * @hllt: a LLT instance
 * @timeout_in_ms: timeout to set in ms
 *
 * Setter for ethernet heartbeat timeout. Value must be between 500 and
 * 1000000000 ms.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 set_ethernet_heartbeat_timeout(LLT *hllt, guint32 timeout_in_ms)
{
    if (timeout_in_ms < 500 || timeout_in_ms > 1000000000) {
        return ERROR_SETGETFUNCITONS_HEARTBEAT_TOO_HIGH;
    }
    return set_feature(hllt, 0x00000938, timeout_in_ms * 3);
}

/**
 * get_ethernet_heartbeat_timeout:
 * @hllt: a LLT instance
 * @timeout_in_ms: timeout in ms
 *
 * Getter for ethernet heartbeat timeout.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 get_ethernet_heartbeat_timeout(LLT *hllt, guint32 *timeout_in_ms)
{
    gint32 ret = 0;
    guint32 feature = 0;

    if ((ret = get_feature(hllt, 0x00000938, &feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (timeout_in_ms != NULL) {
        *timeout_in_ms = feature / 3;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_arv_device:
 * @hllt: a LLT instance
 *
 * Getter for ArvDevice data of LLT; helpful for Genicam interfacing
 *
 * Returns: pointer to ArvDevice
 *
 * Since: 0.2.0
 */
gint32 get_arv_device(LLT *hllt, ArvDevice **device)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (device != NULL) {
        *device = hllt->device;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_path_to_devprop:
 * @path: path to device_prpoerties.dat file
 *
 * Sets the path to the device_properties.dat file which holds ME scanner informations
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_path_device_properties(LLT *hllt, const char *path_device_properties)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (path_device_properties == NULL) {
        return ERROR_DEVPROP_NOT_FOUND;
    }
    hllt->path_device_properties = path_device_properties;
    return GENERAL_FUNCTION_OK;
}

/**
 * set_device_interface:
 * @hllt: a LLT instance
 * @interface: camera name string
 *
 * Matches a camera to this instance via camera name
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_device_interface(LLT *hllt, const char *device_interface)
{
    if (hllt == NULL || device_interface == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    hllt->device_id = device_interface;
    return GENERAL_FUNCTION_OK;
}

/**
 * connect_llt:
 * @hllt: a LLT instance
 *
 * Connects to a scanner with the given device id (set by SetDeviceInterface)
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 **/
gint32 connect_llt(LLT *hllt)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }

    gint32 ret = 0;
    hllt->buffer_ct = 50;
    hllt->holding_buffer_ct = 25;
    hllt->is_transmitting = false;
    hllt->profile_config = PROFILE;
    const char *camera_name = NULL;

#ifndef ARAVIS_CHECK_VERSION
    printf("Warning: aravis version could not be verified\n");
#elif !ARAVIS_CHECK_VERSION(0, 5, 8)
    printf("Warning: aravis version >=0.5.8 recommended\n");
#endif

    if (hllt->is_connected) {
        return ERROR_CONNECT_ALREADY_CONNECTED;
    }
    if (hllt->device_id == NULL) {
        return ERROR_CONNECT_INVALID_DEVICE_ID;
    }
    // instantiation of the camera with given device id
    hllt->camera = arv_camera_new(hllt->device_id);
    if (hllt->camera == NULL) {
        return ERROR_CONNECT_SELECTED_LLT;
    }
    hllt->is_connected = true;

    // get device instance and camera name
    hllt->device = arv_camera_get_device(hllt->camera);
    camera_name = arv_camera_get_model_name(hllt->camera);
    if (hllt->device == NULL || camera_name == NULL) {
        camera_name = NULL;
        disconnect_llt(hllt);
        return ERROR_CONNECT_SELECTED_LLT;
    }

    // get LLT type and set it to struct variable (is used by many functions!)
    if ((ret = get_llt_type(hllt, &hllt->scanner_type)) < GENERAL_FUNCTION_OK) {
        goto l_disconnect;
    }

    // connect control lost callback
    g_signal_connect(hllt->device, "control-lost", G_CALLBACK(control_lost_callback), hllt);

    // set standard packet size of 1024
    if ((ret = set_packet_size(hllt, 1024)) < GENERAL_FUNCTION_OK) {
        goto l_disconnect;
    }

    // set standard heartbeat timeout of 1000 ms
    if ((ret = set_ethernet_heartbeat_timeout(hllt, 1000)) < GENERAL_FUNCTION_OK) {
        goto l_disconnect;
    }

    // reset scanner image format to Standard PROFILE config
    arv_device_set_string_feature_value(hllt->device, "TransmissionType", "TypeProfile");
    arv_device_set_string_feature_value(hllt->device, "PixelFormat", "Mono8");
    arv_device_set_integer_feature_value(hllt->device, "OffsetX", 0);
    arv_device_set_integer_feature_value(hllt->device, "OffsetY", 0);
    arv_device_set_integer_feature_value(hllt->device, "Width", 64);

    // read device_properties.dat and read info if path set
    if (hllt->path_device_properties != NULL) {
        if ((ret = init_device(camera_name, &hllt->device_data, hllt->path_device_properties)) < GENERAL_FUNCTION_OK) {
            goto l_disconnect;
        }
        // set sensor scaling factors read from device_properties.dat
        if (hllt->device_data.scaling > 0 && hllt->device_data.offset > 0) {
            hllt->scaling = hllt->device_data.scaling;
            hllt->offset = hllt->device_data.offset;
        } else {
            ret = ERROR_DEVPROP_READ_FAILURE;
            goto l_disconnect;
        }
    } else {
        // use scanner name to set offset and scaling
        if ((ret = get_llt_scaling_and_offset(hllt, &hllt->offset, &hllt->scaling)) < GENERAL_FUNCTION_OK) {
            goto l_disconnect;
        }        
    }

    // get initial scanner resolution
    guint32 inital_resolution = 0;
    if ((ret = get_resolution(hllt, &inital_resolution)) < GENERAL_FUNCTION_NOT_AVAILABLE) {
        goto l_disconnect;
    } else {
        hllt->resolution = inital_resolution;
    }

    // deactivate UserMode switching via digital inputs by default while connected
    if (hllt->scanner_type >= scanCONTROL26xx_25 && hllt->scanner_type <= scanCONTROL25xx_xxx) {
        guint32 maintenance = 0;
        if ((ret = get_feature(hllt, FEATURE_FUNCTION_MAINTENANCEFUNCTIONS, &maintenance)) < GENERAL_FUNCTION_OK) {
            goto l_disconnect;
        }
        maintenance |= MAINTENANCE_UM_SUPPRESS_UNTIL_REBOOT_GVCP_CLOSE;
        if ((ret = set_feature(hllt, FEATURE_FUNCTION_MAINTENANCEFUNCTIONS, maintenance)) < GENERAL_FUNCTION_OK) {
            goto l_disconnect;
        }
    }
    return GENERAL_FUNCTION_OK;

l_disconnect:
    disconnect_llt(hllt);
    return ret;
}

/**
 * disconnect_llt:
 * @hllt: a LLT instance
 *
 * Disconnects the scanner connected to this instance
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 disconnect_llt(LLT *hllt)
{
    gint32 ret = GENERAL_FUNCTION_OK;

    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (hllt->is_transmitting) {
        ret = transfer_profiles(hllt, hllt->profile_type, false);
    }
    if (hllt->holding_buffer.buffer != NULL) {
        pb_free(&hllt->holding_buffer);
    }
    // unref camera
    g_object_unref(hllt->camera);
    hllt->camera = NULL;
    hllt->device = NULL;
    hllt->is_connected = false;

    return ret;
}

/**
 * get_llt_type:
 * @hllt: a LLT instance
 * @scanner_type: pointer to a TScannerType variable
 *
 * Gets the model type of the connected scanCONTROL sensor
 *
 * Returns: success or error code
 *
 * Since: 0.1.0
 */
gint32 get_llt_type(LLT *hllt, TScannerType *scanner_type)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    // get model name via GeniCam
    const char *full_model_name = arv_device_get_string_feature_value(hllt->device, "DeviceModelName");
    if (full_model_name == NULL) {
        return ERROR_GENERAL_DEVICE_BUSY;
    }
    return get_llt_type_by_name(full_model_name, scanner_type);
}

/**
 * get_llt_offset_and_scaling:
 * @hllt: a LLT instance
 * @offset: pointer to offset
 * @scaling: pointer to scaling
 *
 * Gets the model type of the connected scanCONTROL sensor
 *
 * Returns: success or error code
 *
 * Since: 0.1.0
 */
gint32 get_llt_scaling_and_offset(LLT *hllt, double *scaling, double *offset)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    gint32 ret = 0;

    // sC 3000 series allows scaling & offset readout from registers
    if (hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx) {
        guint32 scaling_nm = 0;
        guint32 offset_nm = 0;
        if ((ret = get_feature(hllt, FEATURE_FUNCTION_CALIBRATION_SCALE, &scaling_nm)) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        if ((ret = get_feature(hllt, FEATURE_FUNCTION_CALIBRATION_OFFSET, &offset_nm)) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        if (scaling != NULL) {
            *scaling = scaling_nm / 1000000.0;
        }
        if (offset != NULL) {
            *offset = offset_nm / 1000000.0;
        }
        return GENERAL_FUNCTION_OK;
    } else if ((hllt->scanner_type >= scanCONTROL27xx_25 && hllt->scanner_type <= scanCONTROL29xx_xxx) || (hllt->scanner_type >= scanCONTROL25xx_25 && hllt->scanner_type <= scanCONTROL25xx_xxx)) {
        return get_scaling_and_offset_by_type(hllt->scanner_type, scaling, offset);
    } else {
        return GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED;
    }    
}

/**
 * get_device_name:
 * @hllt: a LLT instance
 * @device_name: device name string
 * @dev_name_size: size of passed device array
 * @vendor_name: vendor name string
 * @dev_name_size: size of passed vendor array
 *
 * Gets the device and vendor name via GeniCam
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_device_name(LLT *hllt, char *device_name, guint32 dev_name_size, char *vendor_name, guint32 ven_name_size)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (device_name != NULL) {
        if (dev_name_size < 75) {
            return ERROR_GETDEVICENAME_SIZE_TOO_LOW;
        }
        memset(device_name, 0, dev_name_size);
        strncpy(device_name, arv_device_get_string_feature_value(hllt->device, "DeviceModelName"), 45);
        strncat(device_name, arv_device_get_string_feature_value(hllt->device, "DeviceVersion"), 30);
    }
    if (vendor_name != NULL) {
        if (dev_name_size < 75) {
            return ERROR_GETDEVICENAME_SIZE_TOO_LOW;
        }
        strncpy(vendor_name, arv_device_get_string_feature_value(hllt->device, "DeviceVendorName"), 75);
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_llt_versions:
 * @hllt: a LLT instance
 * @dsp: pointer for dsp fw version
 * @fpga1: pointer to fpga major fw version
 * @fpga2: pointer to fpga minor fw version
 *
 * Gets the FW version (DSP, FPGAs)
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_llt_versions(LLT *hllt, guint32 *dsp, guint32 *fpga1, guint32 *fpga2)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    const char *version = arv_device_get_string_feature_value(hllt->device, "DeviceVersion");
    if (version == NULL) {
        return ERROR_GENERAL_DEVICE_BUSY;
    }

    char dsp_string[3], fpga1_string[2], fpga2_string[2];
    // null terminate arrays
    dsp_string[2] = '\0';
    fpga1_string[1] = '\0';
    fpga2_string[1] = '\0';
    // extract chars from expected position
    strncpy(dsp_string, &version[1], 2);
    strncpy(fpga1_string, &version[4], 1);
    strncpy(fpga2_string, &version[5], 1);
    // convert chars to int
    *dsp = atoi(dsp_string);
    *fpga1 = atoi(fpga1_string);
    *fpga2 = atoi(fpga2_string);

    return GENERAL_FUNCTION_OK;
}

/**
 * get_resolutions
 * @hllt: a LLT instance
 * @resolutions: resolution array
 * @resolutions_size: resolution array size
 *
 * Reads the available resolutions for connected scanner
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_resolutions(LLT *hllt, guint32 *resolutions, guint32 resolutions_size)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    // #TODO: read values via GigE, but _only_ if elegant solution.
    // Problems:
    // 1. The Resolution node in the Genicam XML does not contain the actual resolution values
    // 2. The max value of the Width/Height node changes depending on the Transmission type/Resolution setting.
    // ==> to get the possible resolutions you have to remember the current resolution and transmission type
    //     and then change the actual sensor setting, and finally reset everything. Not very nice...

    if (resolutions != NULL && resolutions_size >= 4) {
        gint64 max_resolution = 0;
        if (hllt->scanner_type >= scanCONTROL27xx_25 && hllt->scanner_type <= scanCONTROL27xx_xxx) {
            max_resolution = 640;
        } else if (hllt->scanner_type >= scanCONTROL26xx_25 && hllt->scanner_type <= scanCONTROL26xx_xxx) {
            max_resolution = 640;
        } else if (hllt->scanner_type >= scanCONTROL29xx_25 && hllt->scanner_type <= scanCONTROL29xx_xxx) {
            max_resolution = 1280;
        } else if (hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx) {
            max_resolution = 2048;
        } else if (hllt->scanner_type >= scanCONTROL25xx_25 && hllt->scanner_type <= scanCONTROL25xx_xxx) {
            max_resolution = 640;
        } else {
            return GENERAL_FUNCTION_NOT_AVAILABLE;
        }
        // write resolution values to array
        resolutions[0] = max_resolution;
        resolutions[1] = max_resolution / 2;
        resolutions[2] = max_resolution / 4;
        if (hllt->scanner_type >= scanCONTROL25xx_25 && hllt->scanner_type <= scanCONTROL25xx_xxx) 
            return 3;
        else {
            resolutions[3] = max_resolution / 8;
            return 4;
        }
    } else {
        return ERROR_SETGETFUNCTIONS_SIZE_TOO_LOW;
    }
}

/**
 * set_resolution:
 * @hllt: a LLT instance
 * @resolution: resolution to set
 *
 * Sets the scanner resolution
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_resolution(LLT *hllt, guint32 resolution)
{
    gint32 ret = 0;
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
    }
    // set the correct resolution depending on scanner type (maxheight)
    if (hllt->scanner_type >= scanCONTROL29xx_25 && hllt->scanner_type <= scanCONTROL29xx_xxx) {
        switch (resolution) {
            case 1280:
                if ((ret = set_feature(hllt, 0xf0f00604, 0x40000000)) < GENERAL_FUNCTION_OK) {
                    return ret;
                }
                break; // workaround due to XML bug - delete if bug is fixed
            case 160:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode13Vita");
                break;
            case 320:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode12Vita");
                break;
            case 640:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode11Vita");
                break;
            /* case 1280:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode10Vita");
                break; // 2 - 1280 / 640 // comment in if XML bug is fixed */
            default:
                return ERROR_SETGETFUNCTIONS_NOT_SUPPORTED_RESOLUTION;
                break;
        }
        hllt->resolution = resolution;
        return GENERAL_FUNCTION_OK;
    } 
    if (hllt->scanner_type >= scanCONTROL25xx_25 && hllt->scanner_type <= scanCONTROL25xx_xxx) {
        switch (resolution) {
            case 160:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode13Vita");
                break;
            case 320:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode12Vita");
                break;
            case 640:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode11Vita");
                break;
            default:
                return ERROR_SETGETFUNCTIONS_NOT_SUPPORTED_RESOLUTION;
                break;
        }
        hllt->resolution = resolution;
        return GENERAL_FUNCTION_OK;
    } else if (hllt->scanner_type >= scanCONTROL27xx_25 && hllt->scanner_type <= scanCONTROL26xx_xxx) {
        switch (resolution) {
            case 640:
                if ((ret = set_feature(hllt, 0xf0f00604, 0x40000000)) < GENERAL_FUNCTION_OK) {
                    return ret;
                }
                break; // workaround due to XML bug - delete if bug is fixed
            case 80:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode13");
                break;
            case 160:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode12");
                break;
            case 320:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode11");
                break;
            /*case 640:
                arv_device_set_string_feature_value(hllt->device, "Resolution", "VideoMode10");
                break; // comment in if XML bug is fixed */
            default:
                return ERROR_SETGETFUNCTIONS_NOT_SUPPORTED_RESOLUTION;
                break;
        }
        hllt->resolution = resolution;
        return GENERAL_FUNCTION_OK;
    } else if (hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx) {
        switch (resolution) {
            case 256:
                arv_device_set_string_feature_value(hllt->device, "ProfileResolution", "Profile256");
                break;
            case 512:
                arv_device_set_string_feature_value(hllt->device, "ProfileResolution", "Profile512");
                break;
            case 1024:
                arv_device_set_string_feature_value(hllt->device, "ProfileResolution", "Profile1024");
                break;
            case 2048:
                arv_device_set_string_feature_value(hllt->device, "ProfileResolution", "Profile2048");
                break;
            default:
                return ERROR_SETGETFUNCTIONS_NOT_SUPPORTED_RESOLUTION;
                break;
        }
        hllt->resolution = resolution;
        return GENERAL_FUNCTION_OK;
    } else {
        return GENERAL_FUNCTION_NOT_AVAILABLE;
    }
}

/**
 * get_resolution:
 * @hllt: a LLT instance
 * @resolution: pointer to resolution variable
 *
 * Gets the currently set scanner resolution
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_resolution(LLT *hllt, guint32 *resolution)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (resolution != NULL) {
        const char *profile_resolution;
        if (hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx) {
            profile_resolution = arv_device_get_string_feature_value(hllt->device, "ProfileResolution");
        } else {
            profile_resolution = arv_device_get_string_feature_value(hllt->device, "Resolution");
        }

        // get current video mode # workaround due to XML bug - delete if bug is fixed        
        if (profile_resolution == NULL) {
            if (hllt->scanner_type >= scanCONTROL29xx_25 && hllt->scanner_type <= scanCONTROL29xx_xxx) {
                *resolution = 1280;
            } else if (hllt->scanner_type >= scanCONTROL27xx_25 && hllt->scanner_type <= scanCONTROL26xx_xxx) {
                *resolution = 640;
            } else if (hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx) {
                *resolution = 2048;
            } else if (hllt->scanner_type >= scanCONTROL25xx_25 && hllt->scanner_type <= scanCONTROL25xx_xxx) {
                *resolution = 640;
            } else {
                return GENERAL_FUNCTION_NOT_AVAILABLE;
            }
        } else {
            if (strcmp(profile_resolution, "VideoMode10") == 0) {
                *resolution = 640;
            } else if (strcmp(profile_resolution, "VideoMode11") == 0) {
                *resolution = 320;
            } else if (strcmp(profile_resolution, "VideoMode12") == 0) {
                *resolution = 160;
            } else if (strcmp(profile_resolution, "VideoMode13") == 0) {
                *resolution = 80;
            } else if (strcmp(profile_resolution, "VideoMode10Vita") == 0) {
                *resolution = 1280;
            } else if (strcmp(profile_resolution, "VideoMode11Vita") == 0) {
                *resolution = 640;
            } else if (strcmp(profile_resolution, "VideoMode12Vita") == 0) {
                *resolution = 320;
            } else if (strcmp(profile_resolution, "VideoMode13Vita") == 0) {
                *resolution = 160;
            } else if (strcmp(profile_resolution, "Profile2048") == 0) {
                *resolution = 2048;
            } else if (strcmp(profile_resolution, "Profile1024") == 0) {
                *resolution = 1024;
            } else if (strcmp(profile_resolution, "Profile512") == 0) {
                *resolution = 512;
            } else if (strcmp(profile_resolution, "Profile256") == 0) {
                *resolution = 256;
            } else {
                return ERROR_GENERAL_DEVICE_BUSY;
            }
        }
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_profile_container_size:
 * @hllt: a LLT instance
 * @width: container width to set
 * @height: container height to set
 *
 * Sets the size of a container for container mode transmission
 * If width is 0, the container width is calculated automatically
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_profile_container_size(LLT *hllt, guint32 width, guint32 height)
{
    if (width >= 32768 && height >= 4096) {
        return ERROR_SETGETFUNCTIONS_WRONG_PROFILE_SIZE;
    }    

    if (width == 0) {
        gint32 ret = 0;
        guint32 rearrangement = 0;
        if ((ret = get_feature(hllt, FEATURE_FUNCTION_PROFILE_REARRANGEMENT, &rearrangement)) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        // calculate amount of data per point of container
        guint32 number_stripes =    ((rearrangement & CONTAINER_STRIPE_1) >> 20) +
                                    ((rearrangement & CONTAINER_STRIPE_2) >> 21) +
                                    ((rearrangement & CONTAINER_STRIPE_3) >> 22) +
                                    ((rearrangement & CONTAINER_STRIPE_4) >> 23);

        guint32 data_fields =   (rearrangement & CONTAINER_DATA_Z) + 
                                ((rearrangement & CONTAINER_DATA_X) >> 1) +
                                ((rearrangement & CONTAINER_DATA_THRES) >> 2) +
                                ((rearrangement & CONTAINER_DATA_INTENS) >> 3) +
                                ((rearrangement & CONTAINER_DATA_WIDTH) >> 4) +
                                ((rearrangement & CONTAINER_DATA_MOM1L) >> 5) +
                                ((rearrangement & CONTAINER_DATA_MOM1U) >> 6) +
                                ((rearrangement & CONTAINER_DATA_MOM0L) >> 7) +
                                ((rearrangement & CONTAINER_DATA_MOM0U) >> 8);

        guint32 once_per_profile_data = ((rearrangement & CONTAINER_DATA_LOOPBACK) >> 9) * 4 +
                                        ((rearrangement & CONTAINER_DATA_EMPTYFIELD4TS) >> 10);

        // calculate point resolution of container
        guint32 resolution_bits = (rearrangement & 0x0000F000) >> 12;
        guint32 container_resolution = 0;
        bool is_llt3000 = hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx;
        switch (resolution_bits) {
            case 6:
                container_resolution = 80;
                break;
            case 7:
                container_resolution = 160;
                break;
            case 8:
                container_resolution = is_llt3000 ? 256 : 320;
                break;
            case 9:
                container_resolution = is_llt3000 ? 512 : 640;
                break;
            case 10:
                container_resolution = is_llt3000 ? 1024 : 1280;
                break;
            case 11:
                container_resolution = 2048;
                break;
            default:
                return ERROR_SETGETFUNCTIONS_WRONG_PROFILE_SIZE;
        }

        // calculate width automatically
        width = (number_stripes * data_fields + once_per_profile_data) * container_resolution;
    
    } else if (width % 4 == 0) {
        return ERROR_SETGETFUNCTIONS_MOD_4; 
    }

    // set height and width for containers from sensor
    return set_feature(hllt, 0xf0e0070c, (width << 16) | height);    
}

/**
 * get_profile_container_size:
 * @hllt: a LLT instance
 * @width: pointer to width variable
 * @height: pointer to heigth variable
 *
 * Gets the currently set container size
 *
 * Returns: error codes or success
 *
 * Since: 0.1.0
 */
gint32 get_profile_container_size(LLT *hllt, guint32 *width, guint32 *height)
{
    gint32 ret = 0;
    guint32 container_size = 0;
    // read height and width for containers from sensor
    if ((ret = get_feature(hllt, 0xf0e0070c, &container_size)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (width != NULL) {
        *width = (container_size & 0xFFFF0000) >> 16;
    }
    if (height != NULL) {
        *height = container_size & 0x0000FFFF;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_max_profile_container_size
 * @hllt: a LLT instance
 * @max_width: pointer to max width variable
 * @max_height: pointer to max h// Read currently set resolution as backup
 *
 * Gets the maximum possible size for a container for the connected scanCONTROL
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_max_profile_container_size(LLT *hllt, guint32 *max_width, guint32 *max_height)
{
    gint32 ret = 0;
    guint32 max_container_size = 0;
    // read max height and width for containers from sensor
    if ((ret = get_feature(hllt, 0xf0e00700, &max_container_size)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (max_width != NULL) {
        *max_width = (max_container_size & 0xFFFF0000) >> 16;
    }
    if (max_height != NULL) {
        *max_height = max_container_size & 0x0000FFFF;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_hold_buffers_for_polling:
 * @hllt: a LLT instance
 * @holding_buffer_ct: pointer to holdbuffer count
 *
 * Reads number of FIFO holding buffers for polling with get_actual_profile
 *
 * Returns: error code or succes
 *
 * Since: 0.2.0
 */
gint32 get_hold_buffers_for_polling(LLT *hllt, guint32 *holding_buffer_ct)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (holding_buffer_ct != NULL) {
        *holding_buffer_ct = hllt->holding_buffer_ct;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_hold_buffers_for_polling:
 * @hllt: a LLT instance
 * @holding_buffer_ct: pointer to holdbuffer count
 *
 * Sets number of FIFO holding buffers for polling with get_actual_profile
 *
 * Returns: error code or succes
 *
 * Since: 0.2.0
 */
gint32 set_hold_buffers_for_polling(LLT *hllt, guint32 holding_buffer_ct)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
    }
    if (holding_buffer_ct > hllt->buffer_ct / 2) {
        return ERROR_SETGETFUNCTIONS_WRONG_BUFFER_COUNT;
    }
    hllt->holding_buffer_ct = holding_buffer_ct;
    return GENERAL_FUNCTION_OK;
}

/**
 * get_feature:
 * @hllt: a LLT instance
 * @register_address: register to read from
 * @value: pointer to value variable
 *
 * Reads status and control register of scanCONTROL
 *
 * Returns: error code or succes
 *
 * Since: 0.1.0
 */
gint32 get_feature(LLT *hllt, guint32 register_address, guint32 *value)
{
    if (hllt == NULL || value == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    gboolean ret = FALSE;
    GError *error = NULL;
    ret = arv_device_read_register(hllt->device, register_address, value, &error);
    if (error != NULL) {
        g_clear_error(&error);
        return ERROR_GENERAL_GET_SET_ADDRESS;
    }
    if (ret) {
        return GENERAL_FUNCTION_OK;
    } else {
        return ERROR_SETGETFUNCTIONS_WRONG_FEATURE_ADRESS;
    }
}

/**
 * set_feature:
 * @hllt: a LLT instance
 * @register_address: register to change
 * @value: value to set
 *
 * Writes status and control register of scanCONTROL
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_feature(LLT *hllt, guint32 register_address, guint32 value)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    // if rearrangement is set, check if minium one stripe and one data field is set
    if (register_address == FEATURE_FUNCTION_PROFILE_REARRANGEMENT && (value & 0x000F0000) == 0 &&
        (value & 0x0000FFFF) == 0) {
        return ERROR_SETGETFUNCTIONS_REARRANGEMENT_PROFILE;
    }

    gboolean ret = FALSE;
    GError *error = NULL;
    ret = arv_device_write_register(hllt->device, register_address, value, &error);
    if (error != NULL) {
        g_clear_error(&error);
        return ERROR_GENERAL_GET_SET_ADDRESS;
    }
    if (ret) {
        return GENERAL_FUNCTION_OK;
    } else {
        return ERROR_SETGETFUNCTIONS_WRONG_FEATURE_ADRESS;
    }
}

/**
 * set_partial_profile:
 * @hllt: a LLT instance
 * @partial_profile: a TPartialProfile
 *
 * Set partial profile size
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_partial_profile(LLT *hllt, TPartialProfile *partial_profile)
{
    if (hllt == NULL || partial_profile == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (hllt->profile_config != PARTIAL_PROFILE) {
        return ERROR_PARTPROFILE_NO_PART_PROF;
    }

    if ((partial_profile->nPointDataWidth + partial_profile->nStartPointData) > 64) {
        return ERROR_PARTPROFILE_TOO_MUCH_BYTES;
    }
    if ((partial_profile->nStartPoint + partial_profile->nPointCount) > hllt->resolution) {
        return ERROR_PARTPROFILE_TOO_MUCH_POINTS;
    }
    if (partial_profile->nPointCount == 0 || partial_profile->nPointDataWidth == 0) {
        return ERROR_PARTPROFILE_NO_POINT_COUNT;
    }

    arv_device_set_string_feature_value(hllt->device, "TransmissionType", "TypeProfile");
    arv_device_set_string_feature_value(hllt->device, "PixelFormat", "Mono8");

    guint32 point_unit_size = 0, data_unit_size = 0;
    gint32 ret = 0;

    if ((ret = get_partial_profile_unit_size(hllt, &point_unit_size, &data_unit_size)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (partial_profile->nStartPoint % 4 != 0 || partial_profile->nPointCount % 4 != 0) {
        return ERROR_PARTPROFILE_NOT_MOD_UNITSIZE_POINT;
    }
    if (partial_profile->nStartPointData % 4 != 0 || partial_profile->nPointDataWidth % 4 != 0) {
        return ERROR_PARTPROFILE_NOT_MOD_UNITSIZE_DATA;
    }

    arv_device_set_integer_feature_value(hllt->device, "OffsetX", partial_profile->nStartPointData);
    arv_device_set_integer_feature_value(hllt->device, "OffsetY", partial_profile->nStartPoint);
    arv_device_set_integer_feature_value(hllt->device, "Width", partial_profile->nPointDataWidth);
    arv_device_set_integer_feature_value(hllt->device, "Height", partial_profile->nPointCount);

    hllt->partial_profile = *partial_profile;

    return GENERAL_FUNCTION_OK;
}

/**
 * get_partial_profile:
 * @partial_profile: pointer to a TPartialProfile
 *
 * Gets the currently set partial profile config
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_partial_profile(LLT *hllt, TPartialProfile *partial_profile)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (partial_profile != NULL) {
        *partial_profile = hllt->partial_profile;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_partial_profile_unit_size
 * @hllt: a LLT instance
 * @unit_size_point: pointer to variable for point count unit size
 * @unit_size_point_data: pointer to variable for data width unit size
 *
 * Gets the min unit sizes to define partial profiles
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_partial_profile_unit_size(LLT *hllt, guint32 *unit_size_point, guint32 *unit_size_point_data)
{
    gint32 ret = 0;
    guint32 current_transmission_mode = 0;
    guint32 unit_size = 0;

    // get current transmission mode
    if ((ret = get_feature(hllt, 0xf0f00604, &current_transmission_mode)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // return unit size depending on transmission mode
    switch (current_transmission_mode) {
        case 0x40000000:
            ret = get_feature(hllt, 0xf0e00204, &unit_size);
            break;
        case 0x60000000:
            ret = get_feature(hllt, 0xf0e00304, &unit_size);
            break;
        case 0x80000000:
            ret = get_feature(hllt, 0xf0e00404, &unit_size);
            break;
        case 0xa0000000:
            ret = get_feature(hllt, 0xf0e00504, &unit_size);
            break;
        default:
            return ERROR_SETGETFUNCTIONS_WRONG_FEATURE_ADRESS;
            break;
    }
    if (ret < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (unit_size_point != NULL) {
        *unit_size_point = (guint32)(unit_size & 0xFFFF0000);
    }
    if (unit_size_point_data != NULL) {
        *unit_size_point_data = (guint32)(unit_size & 0x0000FFFF);
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_buffer_count:
 * @hllt: a LLT instance
 * @buffer_count: pointer to buffer count variable
 *
 * Reads the current number of pushed profile buffers
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_buffer_count(LLT *hllt, guint32 *buffer_count)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (buffer_count != NULL) {
        *buffer_count = hllt->buffer_ct;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_buffer_count:
 * @hllt: a LLT instance
 * @buffer_count: buffer count to set
 *
 * Sets the number of pushed buffers
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_buffer_count(LLT *hllt, guint32 buffer_count)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
    }
    if (buffer_count < 2 || buffer_count > 200) {
        return ERROR_SETGETFUNCTIONS_WRONG_BUFFER_COUNT;
    }
    hllt->buffer_ct = buffer_count;
    return GENERAL_FUNCTION_OK;
}

/**
 * set_profile_config:
 * @hllt: a LLT instance
 * @profile_config: a TProfileConfig
 *
 * Sets the current profile config
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 set_profile_config(LLT *hllt, TProfileConfig profile_config)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
    }
    if (!(profile_config == CONTAINER || profile_config == PARTIAL_PROFILE || profile_config == PROFILE ||
          profile_config == VIDEO_IMAGE)) {
        return ERROR_SETGETFUNCTIONS_WRONG_PROFILE_CONFIG;
    }
    hllt->profile_config = profile_config;
    return GENERAL_FUNCTION_OK;
}

/**
 * get_profile_config:
 * @hllt: a LLT instance
 * @profile_config: pointer to a TProfileConfig
 *
 * Gets the current profile config
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_profile_config(LLT *hllt, TProfileConfig *profile_config)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (profile_config != NULL) {
        *profile_config = hllt->profile_config;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_min_max_packet_size:
 * @hllt: a LLT instance
 * @min_packet_size: pointer to the min packet size variable
 * @max_packet_size: pointer to the max packet size variable
 *
 * Gets the maximum and minimum packet size applicable for this scanner type
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_min_max_packet_size(LLT *hllt, guint32 *min_packet_size, guint32 *max_packet_size)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    gint64 min_packet_size_header = 0, max_packet_size_header = 0;

    arv_device_get_integer_feature_bounds(hllt->device, "GevSCPSPacketSize", &min_packet_size_header,
                                          &max_packet_size_header);

    if (min_packet_size != NULL) {
        *min_packet_size = min_packet_size_header - 36;
    }
    if (max_packet_size != NULL) {
        *max_packet_size = max_packet_size_header - 36;
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * get_packet_size:
 * @hllt: a LLT instance
 * @packet_size: pointer to packet size variable
 *
 * Reads the packet size set at the scanner
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_packet_size(LLT *hllt, guint32 *packet_size)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (packet_size != NULL) {
        *packet_size = arv_device_get_integer_feature_value(hllt->device, "GevSCPSPacketSize") - 36;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * get_actual_usermode:
 * @hllt: a LLT instance
 * @current_usermode: pointer to current usermode variable
 * @available_usermodes: pointer to usermode count variable
 *
 * Reads the current user mode and how many user modes are available
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 get_actual_usermode(LLT *hllt, guint32 *current_usermode, guint32 *available_usermodes)
{
    gint32 ret = 0;
    guint32 register_value = 0;

    if ((ret = get_feature(hllt, 0xf0f00624, &register_value)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (current_usermode != NULL) {
        *current_usermode = (register_value & 0xF0000000) >> 28;
    }
    if ((ret = get_feature(hllt, 0xf0f00400, &register_value)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (available_usermodes != NULL) {
        *available_usermodes = register_value & 0x0000000F;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * read_write_usermodes:
 * @read_write: specify if usermode is written or loaded
 * @usermode: which usermode is written to or loaded
 *
 * Saves or loads an user mode
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 read_write_usermodes(LLT *hllt, gboolean read_write, guint32 usermode)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
    }

    gint32 ret = 0;
    guint32 register_value = 0;

    if ((ret = get_feature(hllt, 0xf0f00400, &register_value)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if (usermode > (register_value & 0x0000000F)) {
        return ERROR_SETGETFUNCTIONS_USER_MODE_TOO_HIGH;
    }
    if (usermode == 0 && read_write) {
        return ERROR_SETGETFUNCITONS_USER_MODE_FACTORY_DEFAULT;
    }
    if (read_write) {
        if ((ret = set_feature(hllt, 0xf0f00620, ((usermode & 0x0000000F) << 28))) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        if ((ret = set_feature(hllt, 0xf0f00618, 0x80000000)) < GENERAL_FUNCTION_OK) {
            return ret;
        }
    } else {
        if ((ret = set_feature(hllt, 0xf0f00624, ((usermode & 0x0000000F) << 28))) < GENERAL_FUNCTION_OK) {
            return ret;
        }
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_packet_size:
 * @hllt: a LLT instance
 * @packet_size: packet size to set
 *
 * Sets the packet size
 *
 * Returns: error code or size
 *
 * Since: 0.1.0
 */
gint32 set_packet_size(LLT *hllt, guint32 packet_size)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
    }
    gint32 ret = 0;
    guint32 min_packet_size = 0, max_packet_size = 0;
    if ((ret = get_min_max_packet_size(hllt, &min_packet_size, &max_packet_size)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((packet_size < min_packet_size) || (packet_size > max_packet_size) || (packet_size % 4 != 0)) {
        return ERROR_SETGETFUNCTIONS_PACKET_SIZE;
    }
    arv_device_set_integer_feature_value(hllt->device, "GevSCPSPacketSize", packet_size + 36);
    return GENERAL_FUNCTION_OK;
}

/**
 * get_actual_profile:
 * @hllt: a LLT instance
 * @buffer: user defined data buffer
 * @buffer_size: size of data buffer
 * @profile_config: intended profile config
 * @lost_profiles: lost profile since last function call
 *
 * Reads profile data from holding buffer. Holding buffer operates in FIFO.
 *
 * Since: 0.2.0
 */
gint32 get_actual_profile(LLT *hllt, guint8 *buffer, gint32 buffer_size, TProfileConfig profile_config,
                          guint32 *lost_profiles)
{
    if (hllt == NULL || buffer == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (buffer_size >= hllt->holding_buffer.item_size) {
        if (profile_config == hllt->profile_config) {
            if (lost_profiles != NULL) {
                *lost_profiles = hllt->holding_buffer.overwritten_data;
            }
            return pb_get_data_from_tail(&hllt->holding_buffer, buffer);
        } else {
            return ERROR_PROFTRANS_WRONG_TRANSFER_CONFIG;
        }
    } else {
        return ERROR_PROFTRANS_BUFFER_SIZE_TOO_LOW;
    }
}

/**
 * buffer_callback (static):
 * @stream: current ArvStream
 * @hllt: a LLT instance
 *
 * Buffer callback which is executed every time a profile is received
 *
 * Since: 0.1.0
 */
static void buffer_callback(ArvStream *stream, LLT *hllt)
{
    if (stream == NULL) {
        return;
    }
    // pop data stream into buffer
    ArvBuffer *buffer = arv_stream_try_pop_buffer(stream);
    if (buffer != NULL) {
        if (arv_buffer_get_status(buffer) == ARV_BUFFER_STATUS_SUCCESS) {
            size_t buffer_size = 0;
            // get image data - data_ptr points to array with 8-bit entries
            const void *buffer_data = arv_buffer_get_data(buffer, &buffer_size);
            // execute user registered callback function or memcpy to polling buffer
            if (hllt->cast_register_buffer_callback != NULL) {
                hllt->cast_register_buffer_callback(buffer_data, buffer_size, hllt->user_data_buffer_callback);
            } else if (hllt->holding_buffer.buffer != NULL && hllt->holding_buffer.item_size == buffer_size) {
                pb_insert_data_to_head(&hllt->holding_buffer, buffer_data);
            }
        }
        arv_stream_push_buffer(stream, buffer);
    }
}

/*
 * control_lost_callback (static):
 * @gv_device: current ArvGvDevice
 * @hllt: a LLT instance
 *
 * Control lost callback which is executed when the sensor connection is lost
 *
 * Since: 0.1.0
 */
static void control_lost_callback(ArvGvDevice *gv_device, LLT *hllt)
{
    // user callback
    hllt->cast_register_control_lost_callback(hllt->user_data_control_lost_callback);

    // cleanup
    if (hllt->camera != NULL) {
        if (hllt->is_transmitting) {
            hllt->is_transmitting = false;
        }
        // unref camera
        // g_object_unref(hllt->camera); // leads to deadlock if commented in
        hllt->camera = NULL;
        hllt->device = NULL;
        hllt->is_connected = false;
    }
}

/**
 * stream_callback (static):
 * @user_data: user data pointer
 * @type: a ArvCallbackType
 * @buffer: a ArvBuffer
 *
 * Stream callback; set priorities/realtime during init
 *
 * Since: 0.1.0
 */
static void stream_callback(void *user_data, ArvStreamCallbackType type, ArvBuffer *buffer)
{
    if (type == ARV_STREAM_CALLBACK_TYPE_INIT) {
        LLT *hllt = (LLT *)user_data;
        gint32 local_state = 0;
        if (!arv_make_thread_high_priority(hllt->nice_value)) {
            local_state += 1;
        }
        if (!arv_make_thread_realtime(hllt->realtime_priority)) {
            local_state += 2;
        }
        switch (local_state) {
            case 0:
                hllt->stream_priority_state = PRIO_SET_SUCCESS;
                break;
            case 1:
                hllt->stream_priority_state = PRIO_SET_NICE_FAILED;
                break;
            case 2:
                hllt->stream_priority_state = PRIO_SET_RT_FAILED;
                break;
            case 3:
                hllt->stream_priority_state = PRIO_SET_FAILED;
                break;
            default:
                hllt->stream_priority_state = PRIO_NOT_SET;
                break;
        }
    }
}

/**
 * transfer_video_stream:
 * @hllt: a LLT instance
 * @video_type: type of video transmission
 * @active: flag if transfer is to be activated or deactivated
 * @width: width of video image
 * @height: height of video image
 *
 * Controls the transmission status of a LLTs video mode
 *
 * Returns: error code or success
 *
 * Since: 0.2.1
 */
gint32 transfer_video_stream(LLT *hllt, TTransferVideoType video_type, gboolean is_active, guint32 *width, guint32 *height)
{
    
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (hllt->profile_config != VIDEO_IMAGE) {
        return ERROR_SETGETFUNCTIONS_WRONG_PROFILE_CONFIG;
    }

    bool is_llt3000 = hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx;

    if (is_active) {
        if (hllt->is_transmitting) {
            return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
        }
                              
        if (is_llt3000) {
            if (video_type == VIDEO_MODE_0) {
                arv_device_set_string_feature_value(hllt->device, "TransmissionType", "LowRes");
            } else {
                arv_device_set_string_feature_value(hllt->device, "TransmissionType", "HighRes");
            }
        } else {
            arv_device_set_string_feature_value(hllt->device, "TransmissionType", "TypeVideo");            
        }

        gint64 max_width = 0, max_height = 0;        
        arv_device_set_string_feature_value(hllt->device, "PixelFormat", "Mono8");
        arv_device_set_integer_feature_value(hllt->device, "OffsetX", 0);
        arv_device_set_integer_feature_value(hllt->device, "OffsetY", 0);
        arv_device_get_integer_feature_bounds(hllt->device, "Width", NULL, &max_width);
        arv_device_get_integer_feature_bounds(hllt->device, "Height", NULL, &max_height);
        arv_device_set_integer_feature_value(hllt->device, "Width", max_width);
        arv_device_set_integer_feature_value(hllt->device, "Height", max_height);        

        if (hllt->cast_register_buffer_callback == NULL) {
            size_t data_size = max_width * max_height;
            pb_set_buffer_size(&hllt->holding_buffer, hllt->holding_buffer_ct, data_size);
        }
        hllt->profile_type = NORMAL_TRANSFER;

        if (width != NULL) {
            *width = (guint32)max_width;
        }
        if (height != NULL) {
            *height = (guint32)max_height;
        }
    }

    return transfer_profiles(hllt, NORMAL_TRANSFER, is_active);
}

/**
 * transfer_profiles:
 * @hllt: a LLT instance
 * @transfer_profile_type: a TTransferProfileType
 * @active: flag if transfer is to be activated or deactivated
 *
 * Controls the transmission status of a LLT
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 transfer_profiles(LLT *hllt, TTransferProfileType transfer_profile_type, gboolean is_active)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    bool is_llt3000 = hllt->scanner_type >= scanCONTROL30xx_25 && hllt->scanner_type <= scanCONTROL30xx_xxx;

    if (is_active) {
        if (hllt->is_transmitting) {
            return ERROR_TRANSMISSION_CANCEL_TRANSMISSION_ACTIVE;
        }
        if (transfer_profile_type == NORMAL_CONTAINER_MODE && hllt->profile_config == CONTAINER) {
            if(is_llt3000) {
                arv_device_set_string_feature_value(hllt->device, "TransmissionType", "Container");
            } else {
                arv_device_set_string_feature_value(hllt->device, "TransmissionType", "TypeContainer");
            }
            arv_device_set_string_feature_value(hllt->device, "PixelFormat", "Mono16");

            if (hllt->cast_register_buffer_callback == NULL) {
                guint32 width = 0, height = 0;
                get_profile_container_size(hllt, &width, &height);
                size_t data_size = width * height * 2; // 16 bit per point
                pb_set_buffer_size(&hllt->holding_buffer, hllt->holding_buffer_ct, data_size);
            }
            hllt->profile_type = NORMAL_CONTAINER_MODE;

        } else if (transfer_profile_type == NORMAL_TRANSFER && hllt->profile_config == PROFILE) {
            if(is_llt3000) {
                arv_device_set_string_feature_value(hllt->device, "TransmissionType", "Profile");
            } else {
                arv_device_set_string_feature_value(hllt->device, "TransmissionType", "TypeProfile");
            }
            arv_device_set_string_feature_value(hllt->device, "PixelFormat", "Mono8");
            arv_device_set_integer_feature_value(hllt->device, "Width", 64);
            arv_device_set_integer_feature_value(hllt->device, "OffsetX", 0);
            arv_device_set_integer_feature_value(hllt->device, "OffsetY", 0);
            set_resolution(hllt, hllt->resolution);
            if (hllt->cast_register_buffer_callback == NULL) {
                size_t data_size = hllt->resolution * 64;
                pb_set_buffer_size(&hllt->holding_buffer, hllt->holding_buffer_ct, data_size);
            }
            hllt->profile_type = NORMAL_TRANSFER;

        } else if (transfer_profile_type == NORMAL_TRANSFER && hllt->profile_config == PARTIAL_PROFILE) {
            gint32 ret = 0;
            if ((ret = set_partial_profile(hllt, &hllt->partial_profile)) < GENERAL_FUNCTION_OK) {
                return ret;
            }
            if (hllt->cast_register_buffer_callback == NULL) {
                size_t data_size = hllt->partial_profile.nPointCount * hllt->partial_profile.nPointDataWidth;
                pb_set_buffer_size(&hllt->holding_buffer, hllt->holding_buffer_ct, data_size);
            }
            hllt->profile_type = NORMAL_TRANSFER;

        } else if (hllt->profile_config != VIDEO_IMAGE) {
            return ERROR_SETGETFUNCTIONS_WRONG_PROFILE_CONFIG;
        }
        // start aravis transmission setup
        guint32 payload = arv_camera_get_payload(hllt->camera);
        hllt->stream = arv_camera_create_stream(hllt->camera, stream_callback, (void *)hllt);
        if (hllt->stream != NULL) {
            // suppress packet resend
            g_object_set(hllt->stream, "packet-resend", ARV_GV_STREAM_PACKET_RESEND_NEVER, NULL);
            // push buffers in the stream input buffer queue
            for (guint32 j = 0; j < hllt->buffer_ct; j++) {
                arv_stream_push_buffer(hllt->stream, arv_buffer_new(payload, NULL));
            }
            // connect buffer callback function
            g_signal_connect(hllt->stream, "new-buffer", G_CALLBACK(buffer_callback), hllt);
            // start the video stream
            arv_camera_start_acquisition(hllt->camera);
            hllt->is_transmitting = true;
            // warm up transmission
            usleep(2500);
            // emit signals to fire callback
            arv_stream_set_emit_signals(hllt->stream, true);
            return payload;
        } else {
            return ERROR_TRANSMISSION_CANCEL_NO_CAM;
        }
    } else {
        if (hllt->is_transmitting && hllt->stream != NULL) {
            // stop transmission
            arv_camera_stop_acquisition(hllt->camera);
            hllt->is_transmitting = false;
            // signal must be inhibited to avoid stream thread running after the last unref
            arv_stream_set_emit_signals(hllt->stream, false);
            // i still dont trust aravis concerning the race condition (Issue #50 (Closed) on Github)
            // thus the usleep
            usleep(2500);
            g_clear_object(&hllt->stream);
        } else {
            return ERROR_TRANSMISSION_CANCEL_NO_TRANSMISSION_ACTIVE;
        }
        return GENERAL_FUNCTION_OK;
    }
    return GENERAL_FUNCTION_NOT_AVAILABLE;
}

/**
 * trigger_profile
 * @hllt: a LLT instance
 *
 * Send one Software trigger
 *
 * Returns: error codes or success
 *
 * Since: 0.2.0
 */
gint32 trigger_profile(LLT *hllt)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (!hllt->is_transmitting) {
        return ERROR_TRANSMISSION_CANCEL_NO_TRANSMISSION_ACTIVE;
    }
    // The register 0xf0d00300 triggers the sensor once
    return set_feature(hllt, 0xf0d00300, 0x80000000);
}

/**
 * trigger_container
 * @hllt: a LLT instance
 *
 * Send a frame/container trigger
 *
 * Returns: error codes or success
 *
 * Since: 0.2.1
 */
gint32 trigger_container(LLT *hllt)
{
    return set_feature(hllt, 0xf0d00300, 0x10000000);
}

/**
 * container_trigger_enable
 * @hllt: a LLT instance
 *
 * Activate frame trigger mode
 *
 * Returns: error codes or success
 *
 * Since: 0.2.1
 */
gint32 container_trigger_enable(LLT *hllt)
{
    return set_feature(hllt, 0xf0d00300, 0x08000001);   
}

/**
 * container_trigger_disable
 * @hllt: a LLT instance
 *
 * Deactivate frame trigger mode
 *
 * Returns: error codes or success
 *
 * Since: 0.2.1
 */
gint32 container_trigger_disable(LLT *hllt)
{
    return set_feature(hllt, 0xf0d00300, 0x08000000);
}

/**
 * save_global_parameter
 * @hllt: a LLT instance
 *
 * Saves global / user mode independent settings like IP and Calibration
 *
 * Returns: error codes or success
 *
 * Since: 0.2.0
 */
gint32 save_global_parameter(LLT *hllt) { return set_feature(hllt, 0xf0f00618, 0x80000000); }

/**
 * set_custom_calibration
 * @hllt: a LLT instance
 * @center_x: x coordinate of rotation center
 * @center_z: z coordinate of rotation center
 * @angle: rotation angle
 * @shift_x: translation in x
 * @shift_z: translation in z
 *
 * Sets calibration of sensor position
 *
 * Returns: error codes or success
 *
 * Since: 0.1.0
 */
gint32 set_custom_calibration(LLT *hllt, double center_x, double center_z, double angle, double shift_x, double shift_z)
{
    gint32 ret = 0;
    guint32 tmp = 0;
    double PI = 3.14159265;
    double offset = hllt->offset;
    double scaling = hllt->scaling;
    double rotate_angle = angle;
    double xTrans = -shift_x;
	double zTrans = offset - shift_z;

    if (offset == 0 || scaling == 0) {
        printf("Offset or Scaling not defined! Abort calibration!\n");
        return -1;
    }

    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0000)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0100)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0420)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0305)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0204)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0308)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0280)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    // Read current state of invert_x and invert_z from sensor
	if ((ret = get_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, &tmp)) < GENERAL_FUNCTION_OK)
	{
		return ret;
	}
	guint32 uiInvertX = (tmp & PROC_FLIP_POSITION) >> 7;
	guint32 uiInvertZ = (tmp & PROC_FLIP_DISTANCE) >> 6;

	// invert angle if necessary
	if (uiInvertX != uiInvertZ)
	{
		rotate_angle = -angle;
	}
	double sinus = sin(rotate_angle * PI / 180);
	double cosinus = cos(rotate_angle * PI / 180);

	// Rotation angle
	if (rotate_angle < 0)
	{
		rotate_angle = floor(65536 + rotate_angle / 0.01 + 0.5);
	}
	else
	{
		rotate_angle = floor(rotate_angle / 0.01 + 0.5);
	}

	// Rotation center 1 for rotating
	double x1 = center_x / scaling + 32768;
	double z1 = (center_z - offset) / scaling + 32768;

	// Rotation center 2 for translating
	double x2 = xTrans / scaling + 32768;
	double z2 = 65536 - ((zTrans - offset) / scaling + 32768);

	// Calculate the combined rotation center
	double x3 = x1 + (x2 - 32768) * cosinus + (z2 - 32768) * sinus;
	double z3 = z1 + (z2 - 32768) * cosinus - (x2 - 32768) * sinus;
	xTrans = floor(x3 + 0.5);
	zTrans = floor(z3 + 0.5);

	// Saturation
	if (xTrans < 0) xTrans = 0; else if (xTrans > 65535) xTrans = 65535;
	if (zTrans < 0) zTrans = 0; else if (zTrans > 65535) zTrans = 65535;
	if (rotate_angle < 0) rotate_angle = 0; else if (rotate_angle > 65535) rotate_angle = 65535;

	guint32 a = (guint32)xTrans;
	guint32 b = (guint32)zTrans;

    // output
    // x high
    tmp = 0x300 | ((a & 0xFF00) >> 8);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // x low
    tmp = 0x200 | (a & 0xFF);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // z high
    tmp = 0x300 | ((b & 0xFF00) >> 8);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // z low
    tmp = 0x200 | (b & 0xFF);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    
    a = 0;
    b = (guint32) rotate_angle;

    // output
    // x high
    tmp = 0x300 | ((a & 0xFF00) >> 8);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // x low
    tmp = 0x200 | (a & 0xFF);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // z high
    tmp = 0x300 | ((b & 0xFF00) >> 8);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // z low
    tmp = 0x200 | (b & 0xFF);
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, tmp)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // final steps
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0100)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * reset_custom_calibration:
 * @hllt: a LLT instance
 *
 * Resets calibration of sensor position
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 reset_custom_calibration(LLT *hllt)
{
    gint32 ret = 0;
    // reset register values
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0000)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0100)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0420)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0300)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0200)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0x0100)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_peak_filter:
 * @hllt: a LLT instance
 * @min_width: minimum evaluated width
 * @max_width: maximum evaluated width
 * @min_intensity: minimum evaluated intensity
 * @max_intensity: maximum evaluated intensity
 *
 * Sets intensity and width peak filter
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 set_peak_filter(LLT *hllt, gushort min_width, gushort max_width, gushort min_intensity, gushort max_intensity)
{
    gint32 ret = 0;
    guint32 toggle = 0;
    // initalize serializes write process
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // write function values
    if ((ret = write_value(hllt, max_width, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, min_width, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, max_intensity, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, min_intensity, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // finalize write process
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_free_measuring_field:
 * @hllt: a LLT instance
 * @start_z: start Z value of measuring field
 * @size_z: Z size of measuring field
 * @start_x: start Xvalue of measuring field
 * @size_x:  size of measuring field
 *
 * Sets free measuring field, depending on matrix orientation
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 set_free_measuring_field(LLT *hllt, gushort start_x, gushort size_x, gushort start_z, gushort size_z)
{
    gint32 ret = 0;
    guint32 toggle = 0;
    // initalize serializes write process
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // go to function specific register
    if ((ret = write_command(hllt, 2, 8, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // write function values
    if ((ret = write_value(hllt, start_z, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, size_z, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, start_x, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, size_x, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // finalize write process
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * set_dynamic_measuring_field_tracking:
 * @hllt: a LLT instance
 * @div_x: -
 * @div_z: -
 * @multi_x: -
 * @multi_z:  -
 *
 * Sets the encoder dependent measuring field tracking
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 set_dynamic_measuring_field_tracking(LLT *hllt, gushort div_x, gushort div_z, gushort multi_x, gushort multi_z)
{
    gint32 ret = 0;
    guint32 toggle = 0;
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // go to function specific register
    if ((ret = write_command(hllt, 2, 16, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // write function values
    if ((ret = write_value(hllt, div_x, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, div_z, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, multi_x, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    if ((ret = write_value(hllt, multi_z, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // finalize write process
    if ((ret = write_command(hllt, 0, 0, &toggle)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    return GENERAL_FUNCTION_OK;
}

/**
 * register_buffer_callback:
 * @hllt: a LLT instance
 * @buffer_callback_function: user buffer callback function to register
 * @user_data: flexible user_data pointer
 *
 * Registers the user buffer callback function
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 register_buffer_callback(LLT *hllt, gpointer buffer_callback_function, gpointer user_data)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    hllt->user_data_buffer_callback = user_data;
    hllt->cast_register_buffer_callback = (void (*)(const void *, size_t, gpointer))buffer_callback_function;
    return GENERAL_FUNCTION_OK;
}

/**
 * register_control_lost_callback:
 * @hllt: a LLT instance
 * @control_lost_callback_function: user control lost callback function to register
 * @user_data: flexible user_data pointer
 *
 * Registers the user buffer callback function
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 register_control_lost_callback(LLT *hllt, gpointer control_lost_callback_function, gpointer user_data)
{
    if (hllt == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    hllt->user_data_control_lost_callback = user_data;
    hllt->cast_register_control_lost_callback = (void (*)(gpointer))control_lost_callback_function;
    return GENERAL_FUNCTION_OK;
}

/**
 * import_llt_config_string:
 * @hllt: a LLT instance
 * @config_data: char array with config string
 * @string_size: char array size
 * @ignore_calibration: ignore calibration registers
 *
 * Reads a char array and sets the features to the sensor
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 import_llt_config_string(LLT *hllt, const char *config_data, gint32 string_size, gboolean ignore_calibration)
{
    gint32 ret = 0;
    gboolean header_found = false;
    gboolean trailer_found = false;

    // copy to temporary buffer to avoid changing the original data
    char *tmp_buffer = malloc(string_size * sizeof(*tmp_buffer));
    if (tmp_buffer == NULL) {
        return ERROR_GENERAL_DEVICE_BUSY;
    }
    memcpy(tmp_buffer, config_data, string_size);

    // split into string tokens for every new line
    char *line = strtok(tmp_buffer, "\n");
    while (line) {
        if (strstr(line, "#### BEGIN LLT REGISTER CONFIG ####")) {
            header_found = true;
        }
        if (strstr(line, "#### END LLT REGISTER CONFIG ####")) {
            trailer_found = true;
            break;
        }
        if (header_found) {
            // search for setq which indicates a register value pair
            if (strstr(line, "setq")) {
                char feature_register_str[11] = "";
                char feature_value_str[11] = "";

                // copy relevant line positions with feature & value
                strncpy(feature_register_str, &line[5], 10);
                strncpy(feature_value_str, &line[16], 10);

                // make sure strings are null terminated
                feature_register_str[10] = '\0';
                feature_value_str[10] = '\0';

                // convert string to base 16 unsigned int numbers
                guint32 feature_register = (guint32)strtol(feature_register_str, NULL, 16);
                guint32 feature_value = (guint32)strtol(feature_value_str, NULL, 16);

                // write register (depending on import_calibration flag)
                if (!(ignore_calibration && feature_register >= FEATURE_FUNCTION_CALIBRATION_0 &&
                      feature_register <= FEATURE_FUNCTION_CALIBRATION_7)) {
                    if ((ret = set_feature(hllt, feature_register, feature_value)) < GENERAL_FUNCTION_OK) {
                        break;
                    }
                }
            }
        }
        line = strtok(NULL, "\n");
    }
    free(tmp_buffer);

    if (header_found && ret < GENERAL_FUNCTION_OK) {
        return ret;
    }

    if (!(header_found && trailer_found)) {
        return ERROR_READWRITECONFIG_UNKNOWN_FILE;
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * import_llt_config:
 * @hllt: a LLT instance
 * @file_name: path + filename of dump file
 * @ignore_calibration: ignore calibration registers
 *
 * Reads a .sc1 or .txt file and sets the features to the sensor
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 import_llt_config(LLT *hllt, const char *file_name, gboolean ignore_calibration)
{
    if (hllt == NULL || file_name == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    FILE *f = 0;
    gint64 file_size = 0;
    gint32 ret = 0;

    f = fopen(file_name, "rb");
    if (f == NULL) {
        return ERROR_READWRITECONFIG_CANT_OPEN_FILE;
    }

    // get file size
    fseek(f, 0L, SEEK_END);
    file_size = ftell(f);
    rewind(f);

    if (file_size == 0) {
        fclose(f);
        return ERROR_READWRITECONFIG_FILE_EMPTY;
    }

    // allocate string buffer
    char *buffer = malloc((file_size + 1) * sizeof(*buffer));
    if (buffer == NULL) {
        fclose(f);
        return ERROR_GENERAL_DEVICE_BUSY;
    }

    // write file to string buffer
    if (fread(buffer, file_size, 1, f) != 1) {
        fclose(f);
        free(buffer);
        return ERROR_GENERAL_DEVICE_BUSY;
    }
    fclose(f);

    // use string import to write settings to sensor
    ret = import_llt_config_string(hllt, buffer, file_size + 1, ignore_calibration);

    free(buffer);
    return ret;
}

/**
 * export_llt_config:
 * @hllt: a LLT instance
 * @file_name: path + filename of dump file
 *
 * Dumps the current sensor configuration to a txt file
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 export_llt_config(LLT *hllt, const char *file_name)
{
    if (hllt == NULL || file_name == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    gint32 array_size = 29941; // size of export data
    gint32 ret = 0;
    char *data_array = calloc(array_size, sizeof(*data_array));
    if (data_array == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }

    if ((ret = export_llt_config_string(hllt, data_array, array_size)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    // write to file
    FILE *f = 0;
    f = fopen(file_name, "w");
    if (f == NULL) {
        return ERROR_READWRITECONFIG_CANT_CREATE_FILE;
    }
    fprintf(f, "%s", data_array);

    fclose(f);
    free(data_array);

    return ret;
}

/**
 * export_llt_config_string:
 * @hllt: a LLT instance
 * @config_data_array: char buffer
 * @array_size: char buffer size
 *
 * Dumps the current sensor configuration to char buffer
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 export_llt_config_string(LLT *hllt, char *config_data_array, gint32 array_size)
{
    if (hllt == NULL || config_data_array == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }
    if (array_size < 29941) {
        return ERROR_READWRITECONFIG_QUEUE_TO_SMALL;
    }

    gint32 ret = 0;
    char *pos = config_data_array;
    guint32 feature = 0;

    // write header
    if ((ret = get_feature(hllt, FEATURE_FUNCTION_SERIAL, &feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    const char *full_model_name = arv_device_get_string_feature_value(hllt->device, "DeviceModelName");
    const char *version = arv_device_get_string_feature_value(hllt->device, "DeviceVersion");

    // get version number
    char raw_version[3];
    strncpy(raw_version, version + 1, 2);
    raw_version[2] = '\0';
    gint32 version_number = atoi(raw_version);

    pos += sprintf(pos, "#### BEGIN LLT REGISTER CONFIG ####\n");
    pos += sprintf(pos, "#Exported from scanCONTROL with serial number %d\n", feature);
    pos += sprintf(pos, "#Device name: %s %s\n", full_model_name, version);

    // write feature registers to file

    // clear iso enable
    if ((ret = set_feature(hllt, 0xf0f00614, 0)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // clear multi shots
    if ((ret = set_feature(hllt, 0xf0f0061c, 0)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // reset peak filter
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_EXTRA_PARAMETER, 0)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // reset parameter queue
    if ((ret = set_feature(hllt, 0xf0f00884, 0)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    // disable CMM trigger
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_CMM_TRIGGER, 0)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    if ((ret = write_register_to_string(hllt, pos, 0xf0f00614, "Clear Iso Enable")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0f0061c, "Clear Multi Shots")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_EXTRA_PARAMETER, "Reset Peak Filter")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0f00884, "Reset Parameter Queue")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_CMM_TRIGGER, "Disable CMM-Trigger")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_IDLE_TIME, "Idle Time")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_PROFILE_PROCESSING, "Processing of Profile Data")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_PROFILE_REARRANGEMENT, "Rearrangement of Profile Data")) <
        GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_THRESHOLD, "Threshold")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_PROFILE_FILTER, "Profile Filter")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_EXPOSURE_TIME, "Shutter Time")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_LASER, "Laser Power")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_TRIGGER, "External Trigger Input")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_ROI1_PRESET, "Measuring Field")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_MAINTENANCE, "Maintenance Functions")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_DIGITAL_IO, "RS422 Interface Function")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0f00604, "Current Video Mode")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00008, "VM 0 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0000c, "VM 0 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00108, "VM 1 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0010c, "VM 1 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00208, "VM 2 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0020c, "VM 2 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00308, "VM 3 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0030c, "VM 3 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00408, "VM 4 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0040c, "VM 4 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00508, "VM 5 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0050c, "VM 5 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00608, "VM 6 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0060c, "VM 6 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e00708, "VM 7 Image position")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;
    if ((ret = write_register_to_string(hllt, pos, 0xf0e0070c, "VM 7 Image Size")) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    pos += ret;

    pos += sprintf(pos, "\n#Postprocessing parameter:\n");

    // disable post processing if activated
    if ((ret = get_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, &feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    gboolean post_processing_active = (feature | 0x00000020) >> 5;

    if (post_processing_active) {
        feature &= 0xFFFFFFDF;
        if ((ret = set_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, feature)) < GENERAL_FUNCTION_OK) {
            return ret;
        }

        if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_PROFILE_PROCESSING, "Disable Post Processing")) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        pos += ret;
    }

    // write PPP to file
    gint32 queue_size = 1024;
    for (gint32 i = 0; i < 4 * queue_size; i += 4) {
        if ((ret = write_register_to_string(hllt, pos, 0xf0b00000 + i, NULL)) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        pos += ret;
    }

    if (post_processing_active) {
        // renable post processing
        feature |= 0x00000020;
        if ((ret = set_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, feature)) < GENERAL_FUNCTION_OK) {
            return ret;
        }

        if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_PROFILE_PROCESSING, "Reenable Post Processing")) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        pos += ret;
    }

    if (version_number >= 43) {
        pos += sprintf(pos, "\n#Extra parameter:\n");

        // write extra parameter
        for (gint32 i = 0; i < 4 * 16; i += 4) {
            if ((ret = write_register_to_string(hllt, pos, FEATURE_FUNCTION_PEAKFILTER_WIDTH + i, NULL)) < GENERAL_FUNCTION_OK) {
                return ret;
            }
            pos += ret;
        }
    }

    sprintf(pos, "#### END LLT REGISTER CONFIG ####\n");

    return GENERAL_FUNCTION_OK;
}

/**
 * read_post_processing_parameter:
 * @hllt: a LLT instance
 * @ppp_data: array for postprocessing data
 * @size: size of array (must be >1024)
 *
 * Reads the sensors current postprocessing parameter to array
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 read_post_processing_parameter(LLT *hllt, guint32 *ppp_data, guint32 size)
{
    if (hllt == NULL || ppp_data == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    gint32 ret = 0;
    guint32 feature = 0;
    guint32 ppp_register = 0;

    if (size < 1024) {
        return ERROR_SETGETFUNCTIONS_SIZE_TOO_LOW;
    }

    // disable post processing
    if ((ret = get_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, &feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    feature &= 0xFFFFFFDF;
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    // read PPP
    size = 1024;
    for (gint32 i = 0; i < 4 * size; i += 4) {
        if ((ret = get_feature(hllt, 0xf0b00000 + i, &ppp_register)) < GENERAL_FUNCTION_OK) {
            return ret;
        }
        ppp_data[i / 4] = ppp_register;
    }

    // reenable post processing
    feature |= 0x00000020;
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * write_post_processing_parameter:
 * @hllt: a LLT instance
 * @ppp_data: array with postprocessing data
 * @size: size of array (must be >1024)
 *
 * Writes the postprocessing parameter in array to the sensor
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 write_post_processing_parameter(LLT *hllt, guint32 *ppp_data, guint32 size)
{
    if (hllt == NULL || ppp_data == NULL) {
        return ERROR_GENERAL_POINTER_MISSING;
    }
    if (hllt->camera == NULL || hllt->device == NULL || !hllt->is_connected) {
        return ERROR_GENERAL_NOT_CONNECTED;
    }

    if (size < 1024) {
        return ERROR_SETGETFUNCTIONS_SIZE_TOO_LOW;
    }    
        
    gint32 ret = 0;
    guint32 feature = 0;

    // disable post processing
    if ((ret = get_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, &feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }
    feature &= 0xFFFFFFDF;
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    // write PPP
    size = 1024;
    for (gint32 i = 0; i < 4 * size; i += 4) {
        if ((ret = set_feature(hllt, 0xf0b00000 + i, ppp_data[i / 4])) < GENERAL_FUNCTION_OK) {
            return ret;
        }
    }

    // reenable post processing
    feature |= 0x00000020;
    if ((ret = set_feature(hllt, FEATURE_FUNCTION_PROFILE_PROCESSING, feature)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    return GENERAL_FUNCTION_OK;
}

/**
 * set_persistent_ip:
 * @hllt: a LLT instance
 * @sensor_ip: new sensor IP
 * @sensor_subnet: new sensor subnet
 * @sensor_gateway: new sensor gateway
 *
 * Sets persistent IP config to sensor.
 *
 * Returns: error code or success
 *
 * Since: 0.2.1
 */
gint32 set_persistent_ip(LLT *hllt, const char *sensor_ip, const char *sensor_subnet, const char *sensor_gateway)
{
    gint32 ret = 0;

    guint32 new_ip = inet_network(sensor_ip);
    if (new_ip < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }
    guint32 new_subnet = inet_network(sensor_subnet);
    if (new_subnet < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }
    guint32 new_gateway = inet_network(sensor_gateway);
    if (new_gateway < 0) {
        return ERROR_GETSETDEV_IP_INVALID;
    }

    if ((ret = set_feature(hllt, BOOTSTRAP_REG_IP, new_ip)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    if ((ret = set_feature(hllt, BOOTSTRAP_REG_SUBNET, new_subnet)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    if ((ret = set_feature(hllt, BOOTSTRAP_REG_GATEWAY, new_gateway)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    if ((ret = set_feature(hllt, BOOTSTRAP_REG_IP_CONFIG, IP_CONFIG_PERISTENT | IP_CONFIG_LOCALHOST)) <
        GENERAL_FUNCTION_OK) {
        return ret;
    }

    if ((ret = save_global_parameter(hllt)) < GENERAL_FUNCTION_OK) {
        return ret;
    }

    return GENERAL_FUNCTION_OK;
}
