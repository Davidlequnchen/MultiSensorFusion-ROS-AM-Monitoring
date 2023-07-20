/*
 * scanCONTROL Linux SDK
 *
 * MIT License
 *
 * Copyright © 2017-2018 Micro-Epsilon Messtechnik GmbH & Co. KG
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "get_profiles_callback.h"

gint32 main()
{
    gint32 ret = 0;

    char *interfaces[MAX_INTERFACE_COUNT];
    guint32 available_resolutions[MAX_RESOLUTION];
    guint32 interface_count = 0;

    guint32 idle_time = 3900;
    guint32 exposure_time = 100;

    ret = get_device_interfaces(&interfaces[0], MAX_INTERFACE_COUNT);
    if (ret == ERROR_GETDEVINTERFACE_REQUEST_COUNT) {
        printf("There are more than %d scanCONTROL connected\n", MAX_INTERFACE_COUNT);
        interface_count = MAX_INTERFACE_COUNT;
    } else if (ret < 1) {
        printf("A error occured during searching for connected scanCONTROL\n");
        interface_count = 0;
    } else {
        interface_count = ret;
    }

    if (interface_count == 0) {
        printf("There is no scanCONTROL connected - Exiting\n");
        exit(0);
    } else if (interface_count == 1) {
        printf("There is 1 scanCONTROL connected\n");
    } else {
        printf("There are %d scanCONTROL connected\n", interface_count);
    }

    for (guint32 i = 0; i < interface_count; i++) {
        printf("%s\n", interfaces[i]);
    }

    hLLT = create_llt_device();
    event = create_event();

    if ((set_device_interface(hLLT, interfaces[0])) < GENERAL_FUNCTION_OK) {
        printf("Error while setting dev id!\n");
        goto cleanup;
    }

    // connect to sensor
    if ((ret = connect_llt(hLLT)) < GENERAL_FUNCTION_OK) {
        printf("Error while connecting to camera - Error  %d!\n", ret);
        goto cleanup;
    }

    if ((ret = get_llt_type(hLLT, &llt_type)) < GENERAL_FUNCTION_OK) {
        printf("Error while GetLLTType!\n");
        goto cleanup;
    }

    if (ret == GENERAL_FUNCTION_DEVICE_NAME_NOT_SUPPORTED) {
        printf("Can't decode scanCONTROL type. Please contact Micro Epsilon for a newer version of "
               "the library.\n");
        goto cleanup;
    }

    if (llt_type >= scanCONTROL27xx_25 && llt_type <= scanCONTROL27xx_xxx) {
        printf("The scanCONTROL is a scanCONTROL27xx\n");
    } else if (llt_type >= scanCONTROL26xx_25 && llt_type <= scanCONTROL26xx_xxx) {
        printf("The scanCONTROL is a scanCONTROL26xx\n");
    } else if (llt_type >= scanCONTROL29xx_25 && llt_type <= scanCONTROL29xx_xxx) {
        printf("The scanCONTROL is a scanCONTROL29xx\n");
    } else if (llt_type >= scanCONTROL30xx_25 && llt_type <= scanCONTROL30xx_xxx) {
        printf("The scanCONTROL is a scanCONTROL30xx\n");
    } else if (llt_type >= scanCONTROL25xx_25 && llt_type <= scanCONTROL25xx_xxx) {
        printf("The scanCONTROL is a scanCONTROL25xx\n");
    } else {
        printf("The scanCONTROL is a undefined type\nPlease contact Micro-Epsilon for a newer SDK\n");
        goto cleanup;
    }

    printf("Get all possible resolutions\n");
    if ((ret = get_resolutions(hLLT, &available_resolutions[0], MAX_RESOLUTION)) < GENERAL_FUNCTION_OK) {
        printf("Error GetResolutions!\n");
        goto cleanup;
    }

    resolution = available_resolutions[0];

    if (set_resolution(hLLT, resolution) < GENERAL_FUNCTION_OK) {
        printf("Error while setting transmission mode!\n");
        goto cleanup;
    }

    if (set_profile_config(hLLT, PROFILE) < GENERAL_FUNCTION_OK) {
        printf("Error while setting SetProfileConfig!\n");
        goto cleanup;
    }

    if (set_feature(hLLT, FEATURE_FUNCTION_IDLE_TIME, idle_time) < GENERAL_FUNCTION_OK) {
        printf("Error while setting FEATURE_FUNCTION_IDLE_TIME!\n");
        goto cleanup;
    }

    if (set_feature(hLLT, FEATURE_FUNCTION_EXPOSURE_TIME, exposure_time) < GENERAL_FUNCTION_OK) {
        printf("Error while setting FEATURE_FUNCTION_EXPOSURE_TIME!\n");
        goto cleanup;
    }

    if (set_feature(hLLT, FEATURE_FUNCTION_TRIGGER, TRIG_INTERNAL) < GENERAL_FUNCTION_OK) {
        printf("Error while setting FEATURE_FUNCTION_TRIGGER!\n");
        goto cleanup;
    }

    printf("Register callbacks\n");

    // register callbacks
    if ((register_buffer_callback(hLLT, (gpointer)&new_profile_cb, NULL)) < GENERAL_FUNCTION_OK) {
        printf("Error while registering buffer callback!\n");
        goto cleanup;
    }

    if ((register_control_lost_callback(hLLT, (gpointer)&control_lost_cb, NULL)) < GENERAL_FUNCTION_OK) {
        printf("Error while registering control lost callback!\n");
        goto cleanup;
    }

    if (get_profiles_callback() < GENERAL_FUNCTION_OK) {
        printf("Error in GetProfiles_Callback!\n");
        goto cleanup;
    }

    // disconnect from sensor
    printf("Disconnect\n");
    if ((ret = disconnect_llt(hLLT)) < GENERAL_FUNCTION_OK) {
        printf("Error while disconnecting to camera - Error  %d!\n", ret);
    }

cleanup:
    // delete device handle
    if ((ret = del_device(hLLT)) < GENERAL_FUNCTION_OK) {
        printf("Error while deleting device - Error  %d!\n", ret);
    }
    free_event(event);
}

gint32 get_profiles_callback()
{
    gint32 ret = 0;
    profile_count = 0;

    double value_x[resolution], value_z[resolution];
    needed_profile_count = 100;

    printf("Get profiles via callback\n");

    profile_size = resolution * 64;
    profile_buffer = malloc(profile_size * sizeof(guint8));

    reset_event(event);

    // setup transfer of multiple profiles
    if ((ret = transfer_profiles(hLLT, NORMAL_TRANSFER, true)) < GENERAL_FUNCTION_OK) {
        printf("Error in profile transfer! - Error  %d!\n", ret);
        goto freebuffer;
    }

    printf("Start acquisition of profiles\n");
    if (wait_for_single_object(event, 5000) != WAIT_OBJECT_0) {
        printf("Timeout!\n");
    }

    // stop transfer
    if ((ret = transfer_profiles(hLLT, NORMAL_TRANSFER, false)) < GENERAL_FUNCTION_OK) {
        printf("Error while stopping transmission\n!");
        goto freebuffer;
    }

    if (profile_count == needed_profile_count && received_data_size == profile_size) {
        printf("1: All %d profiles reveived with correct size\n", profile_count);
    } else {
        printf("1: Wrong profile count: %d or data size %d\n", profile_count, received_data_size);
        ret = ERROR_PROFTRANS_WRONG_DATA_SIZE;
        goto freebuffer;
    }

    // display example points
    if ((ret = convert_profile_2_values(&profile_buffer[0], profile_size, resolution, PROFILE, llt_type, 0, NULL, NULL, NULL,
                                        &value_x[0], &value_z[0], NULL, NULL)) != (CONVERT_X | CONVERT_Z)) {
        printf("Error while extracting profiles\n");
        goto freebuffer;
    }

    display_profiles(&value_x[0], &value_z[0], resolution);
    display_timestamp(&profile_buffer[(resolution * 64) - 16]);

freebuffer:
    free(profile_buffer);
    return ret;
}

void new_profile_cb(const void *data, size_t size, gpointer user_data)
{
    if (size == profile_size && profile_count < needed_profile_count) {
        received_data_size = size;
        memcpy(&profile_buffer[0], data, size);
        profile_count++;

        timestamp_2_time_and_count(&profile_buffer[(resolution * 64) - 16], &shutter_closed, &shutter_opened,
                                   &current_profile_count, NULL);
        if (first_trans > 3) {
            if ((current_profile_count != old_profile_count + 1) ||
                !(current_profile_count == 0 && old_profile_count == 16777215)) {
                lost_profiles += current_profile_count - old_profile_count - 1;
            }
        } else {
            first_trans++;
        }
        old_profile_count = current_profile_count;
        fprintf(stderr, "PC: %d LP: %d \r", current_profile_count, lost_profiles);
    }
    if (profile_count >= needed_profile_count) {
        set_event(event);
    }
}

void control_lost_cb(gpointer user_data)
{
    // control of the device is lost. Display a message and exit!
    printf("Control lost\n");
    exit(0);
}

void display_profiles(double *x, double *z, guint32 number_points)
{
    for (guint32 i = 0; i < number_points; i++) {
        printf("\rX: %.3f Z: %.3f", x[i], z[i]);
        usleep(1250);
    }
    printf("\n");
}

void display_timestamp(guchar *timestamp)
{
    double shutter_open = 0.0, shutter_close = 0.0;
    guint32 profile_ct = 0;
    timestamp_2_time_and_count(&timestamp[0], &shutter_open, &shutter_close, &profile_ct, NULL);
    printf("Profile Count: %d ShutterOpen: %.5f ShutterClose: %.5f\n", profile_ct, shutter_open, shutter_close);
}
