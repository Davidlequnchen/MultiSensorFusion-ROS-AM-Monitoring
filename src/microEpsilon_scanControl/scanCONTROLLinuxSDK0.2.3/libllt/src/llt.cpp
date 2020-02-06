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

#include "llt.h"

/**
 * SECTION: libllt
 * @short_description: C++ wrapper for libmescan and aravis.
 *
 * #libllt is a wrapper class for aravis and mescan which allows advanced control and data handling
 * of scanCONTROL sensors It is to be used with mescan and the aravis framework and tries to mimic
 * the API of LLT.dll
 */

/**
 * CInterfaceLLT:
 *
 * Constructor for scanCONTROL instances
 *
 * Returns: A LLT instance
 *
 * Since: 0.2.0
 */
CInterfaceLLT::CInterfaceLLT()
{
     hllt = create_llt_device();
}

/**
 * ~CInterfaceLLT:
 *
 * Destructor for scanCONTROL instances
 *
 * Since: 0.2.0
 */
CInterfaceLLT::~CInterfaceLLT()
{
    del_device(hllt);
}

/**
 * GetMEDeviceData:
 *
 * Getter for scanCONTROL device data
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetMEDeviceData(MEDeviceData **device_data)
{
    return get_medevice_data(hllt, device_data);
}

/**
 * GetArvDevice:
 *
 * Getter for ArvDevice data of LLT; helpful for Genicam interfacing
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetArvDevice(ArvDevice **device)
{
    return get_arv_device(hllt, device);
}

/**
 * GetStreamPriorityState:
 *
 * Getter for scheduler priority state. Informs about status of stream thread priority.
 * To be called after transmission was started.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetStreamPriorityState(TStreamPriorityState *stream_priority_state)
{
    return get_stream_priority_state(hllt, stream_priority_state);
}

/**
 * GetStreamPriority:
 *
 * Getter for scheduler priority value. Higher values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetStreamPriority(guint32 *realtime_priority)
{
    return get_stream_priority(hllt, realtime_priority);
}

/**
 * GetStreamNiceValue:
 *
 * Getter for user nice value. Negative values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetStreamNiceValue(guint32 *nice_value)
{
    return get_stream_nice_value(hllt, nice_value);
}

/**
 * SetStreamNiceValue:
 * @nice: nice value to set
 *
 * Setter for user nice value. Negative values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::SetStreamNiceValue(guint32 nice)
{
    return set_stream_nice_value(hllt, nice);
}

/**
 * SetStreamPriority:
 * @priority: prio to set
 *
 * Setter for scheduler priority value. Higher values reduce chance for profile loss.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::SetStreamPriority(guint32 priority)
{
    return set_stream_priority(hllt, priority);
}

/**
 * SetEthernetHeartbeatTimeout:
 * @timeout_in_ms: timeout to set in ms
 *
 * Setter for ethernet heartbeat timeout. Value must be between 500 and
 * 1000000000 ms.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::SetEthernetHeartbeatTimeout(guint32 timeout_in_ms)
{
    return set_ethernet_heartbeat_timeout(hllt, timeout_in_ms);
}

/**
 * GetEthernetHeartbeatTimeout:
 * @timeout_in_ms: timeout in ms
 *
 * Getter for ethernet heartbeat timeout.
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetEthernetHeartbeatTimeout(guint32 *timeout_in_ms)
{
    return get_ethernet_heartbeat_timeout(hllt, timeout_in_ms);
}

/**
 * GetStreamStatistics:
 *
 * @completed_buffers: pointer to completed buffer variable
 * @failures: pointer to failure variable
 * @underruns: pointer to underruns variable
 *
 * Outputs the stream statistics of current transmission
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetStreamStatistics(guint64 *completed_buffers, guint64 *failures, guint64 *underruns)
{
    return get_stream_statistics(hllt, completed_buffers, failures, underruns);
}

/**
 * GetLLTOffsetAndScaling:
 * @scanner_type: pointer to a TScannerType variable
 *
 * Gets the model type of the connected scanCONTROL sensor
 *
 * Returns: success or error code
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetLLTScalingAndOffset(double *offset, double *scaling)
{
    return get_llt_scaling_and_offset(hllt, offset, scaling);
}

/**
 * SetPathDeviceProperties:
 * @path_device_properties: path to device_properties.dat file
 *
 * Sets the path to the device_properties.dat file which holds ME scanner informations
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::SetPathDeviceProperties(const char *path_device_properties)
{
    return set_path_device_properties(hllt, path_device_properties);
}

/**
 * Connect:
 *
 * Connects to a scanner with the given device id (set by SetDeviceInterface)
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 **/
gint32 CInterfaceLLT::Connect()
{
    return connect_llt(hllt);
}

/**
 * Disconnect:
 *
 * Disconnects the scanner connected to this instance
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::Disconnect()
{
    return disconnect_llt(hllt);
}

/**
 * SetDeviceInterface:
 * @nInterface: camera name string
 *
 * Matches a camera to this instance via camera name
 *
 * Returns error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetDeviceInterface(const char *device_interface)
{
    return set_device_interface(hllt, device_interface);
}

/**
 * GetLLTType:
 * @scanner_type: a TScannerType
 *
 * Gets the model type of the connected scanCONTROL sensor
 *
 * Returns: success or error code
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetLLTType(TScannerType *scanner_type)
{
    return get_llt_type(hllt, scanner_type);
}

/**
 * GetDeviceName:
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
gint32 CInterfaceLLT::GetDeviceName(char *device_name, guint32 dev_name_size, char *vendor_name, guint32 ven_name_size)
{
    return get_device_name(hllt, device_name, dev_name_size, vendor_name, ven_name_size);
}

/**
 * GetLLTVersions:
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
gint32 CInterfaceLLT::GetLLTVersions(guint32 *dsp, guint32 *fpga1, guint32 *fpga2)
{
    return get_llt_versions(hllt, dsp, fpga1, fpga2);
}

/**
 * GetProfileConfig:
 * @profile_config: pointer to a TProfileConfig
 *
 * Gets the current profile config
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetProfileConfig(TProfileConfig *profile_config)
{
    return get_profile_config(hllt, profile_config);
}

/**
 * GetFeature:
 * @register_address: register to read from
 * @value: pointer to value variable
 *
 * Reads status and control register of scanCONTROL
 *
 * Returns: error code or succes
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetFeature(guint32 register_address, guint32 *value)
{
    return get_feature(hllt, register_address, value);
}

/**
 * GetPartialProfile:
 * @tPartialProfile: pointer to a TPartialProfile
 *
 * Gets the currently set partial profile config
 *
 * Returns: error code and success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetPartialProfile(TPartialProfile *partial_profile)
{
    return get_partial_profile(hllt, partial_profile);
}

/**
 * GetProfileContainerSize:
 * @pWidth: pointer to width variable
 * @pHeight: pointer to heigth variable
 *
 * Gets the currently set container size
 *
 * Returns: error codes and success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetProfileContainerSize(guint32 *width, guint32 *height)
{
    return get_profile_container_size(hllt, width, height);
}

/**
 * GetMaxProfileContainerSize
 * @pWidth: pointer to max width variable
 * @pHeight: pointer to max heigth variable
 *
 * Gets the maximum possible size for a container for the connected scanCONTROL
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetMaxProfileContainerSize(guint32 *max_width, guint32 *max_height)
{
    return get_max_profile_container_size(hllt, max_width, max_height);
}

/**
 * GetBufferCount:
 * @buffer_count: pointer to buffer count variable
 *
 * Reads the current number of pushed profile buffers
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetBufferCount(guint32 *buffer_count) { return get_buffer_count(hllt, buffer_count); }

/**
 * GetResolutions
 * @resolutions: resolution array
 * @resolutions_size: resolution array size
 *
 * Reads the available resolutions for connected scanner
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetResolutions(guint32 *resolutions, guint32 resolutions_size)
{
    return get_resolutions(hllt, resolutions, resolutions_size);
}

/**
 * GetResolution:
 * @resolution: pointer to resolution variable
 *
 * Gets the currently set scanner resolution
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetResolution(guint32 *resolution)
{
    return get_resolution(hllt, resolution);
}

/**
 * GetPartialProfileUnitSize
 * @unit_size_point: pointer to variable for point count unit size
 * @unit_size_point_data: pointer to variable for data width unit size
 *
 * Gets the min unit sizes to define partial profiles
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetPartialProfileUnitSize(guint32 *unit_size_point, guint32 *unit_size_data)
{
    return get_partial_profile_unit_size(hllt, unit_size_point, unit_size_data);
}

/**
 * GetMinMaxPacketSize:
 * @min_packet_size: pointer to the min packet size variable
 * @max_packet_size: pointer to the max packet size variable
 *
 * Gets the maximum and minimum packet size applicable for this scanner type
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetMinMaxPacketSize(guint32 *min_packet_size, guint32 *max_packet_size)
{
    return get_min_max_packet_size(hllt, min_packet_size, max_packet_size);
}

/**
 * GetPacketSize:
 * @packet_size: pointer to packet size variable
 *
 * Reads the packet size set at the scanner
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetPacketSize(guint32 *packet_size)
{
    return get_packet_size(hllt, packet_size);
}

/**
 * SetProfileConfig:
 * @profile_config: a TProfileConfig
 *
 * Sets the current profile config
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetProfileConfig(TProfileConfig profile_config)
{
    return set_profile_config(hllt, profile_config);
}

/**
 * SetFeature:
 * @register_address: register to change
 * @value: value to set
 *
 * Writes status and control register of scanCONTROL
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetFeature(guint32 register_address, guint32 value)
{
    return set_feature(hllt, register_address, value);
}

/**
 * SetResolution:
 * @resolution: resolution to set
 *
 * Sets the scanner resolution
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetResolution(guint32 resolution)
{
    return set_resolution(hllt, resolution);
}

/**
 * SetProfileContainerSize:
 * @width: container width to set
 * @height: container height to set
 *
 * Sets the size of a container for container mode transmission
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetProfileContainerSize(guint32 width, guint32 height)
{
    return set_profile_container_size(hllt, width, height);
}

/**
 * SetPartialProfile:
 * @partial_profile: a TPartialProfile
 *
 * Set partial profile size
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetPartialProfile(TPartialProfile *partial_profile)
{
    return set_partial_profile(hllt, partial_profile);
}

/**
 * SetBufferCount:
 * @buffer_count: buffer count to set
 *
 * Sets the number of pushed buffers
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetBufferCount(guint32 buffer_count)
{
    return set_buffer_count(hllt, buffer_count);
}

/**
 * SetHoldBufferForPolling:
 * @holding_buffer_ct: pointer to holdbuffer count
 *
 * Sets number of FIFO holding buffers for polling with get_actual_profile
 *
 * Returns: error code or succes
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::SetHoldBufferForPolling(guint32 holding_buffer_ct)
{
    return set_hold_buffers_for_polling(hllt, holding_buffer_ct);
}

/**
 * GetHoldBufferForPolling:
 * @holding_buffer_ct: pointer to holdbuffer count
 *
 * Reads number of FIFO holding buffers for polling with get_actual_profile
 *
 * Returns: error code or succes
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetHoldBufferForPolling(guint32 *holding_buffer_ct)
{
    return get_hold_buffers_for_polling(hllt, holding_buffer_ct);
}

/**
 * GetActualProfile:
 * @buffer: user defined data buffer
 * @buffer_size: size of data buffer
 * @profile_config: intended profile config
 * @lost_profiles: lost profile since last function call
 *
 * Reads profile data from holding buffer. Holding buffer operates in FIFO.
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::GetActualProfile(guint8 *buffer, gint32 buffer_size, TProfileConfig profile_config,
                                       guint32 *lost_profiles)
{
    return get_actual_profile(hllt, buffer, buffer_size, profile_config, lost_profiles);
}

/**
 * SetPacketSize:
 * @packet_size: packet size to set
 *
 * Sets the packet size
 *
 * Returns: error code or size
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetPacketSize(guint32 packet_size)
{
    return set_packet_size(hllt, packet_size);
}

/**
 * GetActualUserMode:
 * @current_usermode: pointer to current usermode variable
 * @available_usermodes: pointer to usermode count variable
 *
 * Reads the current user mode and how many user modes are available
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetActualUserMode(guint32 *current_usermode, guint32 *available_usermodes)
{
    return get_actual_usermode(hllt, current_usermode, available_usermodes);
}

/**
 * ReadWriteUserModes:
 * @read_write: specify if usermode is written or loaded
 * @usermode: which usermode is written to or loaded
 *
 * Saves or loads an user mode
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::ReadWriteUserModes(gboolean read_write, guint32 usermode)
{
    return read_write_usermodes(hllt, read_write, usermode);
}

/**
 * SetCustomCalibration
 * @center_x: X Coordinate of rotation center
 * @center_z: Z Coordinate of rotation center
 * @angle: rotation angle
 * @shift_x: translation in X
 * @shift_z: translation in Z
 *
 * Sets calibration of sensor position
 *
 * Returns: error codes or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::SetCustomCalibration(double center_x, double center_z, double angle, double shift_x,
                                           double shift_z)
{
    return set_custom_calibration(hllt, center_x, center_z, angle, shift_x, shift_z);
}

/**
 * ResetCustomCalibration:
 *
 * Resets calibration of sensor position
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::ResetCustomCalibration() { return reset_custom_calibration(hllt); }

/**
 * RegisterBufferCallback:
 * @buffer_callback_function: user buffer callback function to register
 * @user_data: flexible user_data pointer
 *
 * Registers the user buffer callback function
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::RegisterBufferCallback(gpointer buffer_callback_function, gpointer user_data)
{
    return register_buffer_callback(hllt, buffer_callback_function, user_data);
}

/**
 * RegisterControlLostCallback:
 * @control_lost_callback_function: user control lost callback function to register
 * @user_data: flexible user_data pointer
 *
 * Registers the user buffer callback function
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::RegisterControlLostCallback(gpointer control_lost_callback_function, gpointer user_data)
{
    return register_control_lost_callback(hllt, control_lost_callback_function, user_data);
}

/**
 * TransferProfiles:
 * @transfer_profile_type: a TTransferProfileType
 * @active: flag if transfer is to be activated or deactivated
 *
 * Controls the transmission status of a LLT
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::TransferProfiles(TTransferProfileType transfer_profile_type, gboolean active)
{
    return transfer_profiles(hllt, transfer_profile_type, active);
}

/**
 * TransferVideoStream:
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
gint32 CInterfaceLLT::TransferVideoStream(TTransferVideoType video_type, gboolean is_active, guint32 *width,
                                          guint32 *height)
{
    return transfer_video_stream(hllt, video_type, is_active, width, height);
}

/**
 * TriggerProfile
 *
 * Send one Software trigger
 *
 * Returns: error codes or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::TriggerProfile()
{
    return trigger_profile(hllt);
}

/**
 * TriggerContainer
 *
 * Send a frame/container trigger
 *
 * Returns: error codes or success
 *
 * Since: 0.2.1
 */
gint32 CInterfaceLLT::TriggerContainer()
{
    return trigger_container(hllt);
}

/**
 * ContainerModeEnable
 *
 * Activate frame trigger mode
 *
 * Returns: error codes or success
 *
 * Since: 0.2.1
 */
gint32 CInterfaceLLT::ContainerTriggerEnable()
{
    return container_trigger_enable(hllt);
}

/**
 * ContainerModeDisable
 *
 * Deactivate frame trigger mode
 *
 * Returns: error codes or success
 *
 * Since: 0.2.1
 */
gint32 CInterfaceLLT::ContainerTriggerDisable()
{
    return container_trigger_disable(hllt);
}

/**
 * SaveGlobalParameter
 *
 * Saves global / user mode independent settings like IP and Calibration
 *
 * Returns: error codes or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::SaveGlobalParameter()
{
    return save_global_parameter(hllt);
}

/**
 * SetPeakFilter:
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
gint32 CInterfaceLLT::SetPeakFilter(gushort min_width, gushort max_width, gushort min_intensity, gushort max_intensity)
{
    return set_peak_filter(hllt, min_width, max_width, min_intensity, max_intensity);
}

/**
 * SetFreeMeasuringField:
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
gint32 CInterfaceLLT::SetFreeMeasuringField(gushort start_x, gushort size_x, gushort start_z, gushort size_z)
{
    return set_free_measuring_field(hllt, start_x, size_x, start_z, size_z);
}

/**
 * SetDynamicMeasuringFieldTracking:
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
gint32 CInterfaceLLT::SetDynamicMeasuringFieldTracking(gushort div_x, gushort div_z, gushort multi_x, gushort multi_z)
{
    return set_dynamic_measuring_field_tracking(hllt, div_x, div_z, multi_x, multi_z);
}

/**
 * ImportLLTConfig:
 * @file_name: path + filename of dump file
 * @ignore_calibration: ignore calibration registers
 *
 * Reads a .sc1 or .txt file and sets the features to the sensor
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::ImportLLTConfig(const char *file_name, gboolean ignore_calibration)
{
    return import_llt_config(hllt, file_name, ignore_calibration);
}

/**
 * ImportLLTConfigString:
 * @config_string: char array with config string
 * @string_size: char array size
 * @ignore_calibration: ignore calibration registers
 *
 * Reads a char array and sets the features to the sensor
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::ImportLLTConfigString(const char *config_string, gint32 string_size, gboolean ignore_calibration)
{
    return import_llt_config_string(hllt, config_string, string_size, ignore_calibration);
}

/**
 * ExportLLTConfig:
 * @file_name: path + filename of dump file
 *
 * Dumps the current sensor configuration to a txt file
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::ExportLLTConfig(const char *file_name)
{ 
    return export_llt_config(hllt, file_name);
}

/**
 * ExportLLTConfigString:
 * @config_data_array: char buffer
 * @array_size: char buffer size
 *
 * Dumps the current sensor configuration to char buffer
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::ExportLLTConfigString(char *data_array, gint32 array_size)
{
    return export_llt_config_string(hllt, data_array, array_size);
}

/**
 * SetPersistentIp:
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
gint32 CInterfaceLLT::SetPersistentIp(const char *sensor_ip, const char *sensor_subnet, const char *sensor_gateway)
{
    return set_persistent_ip(hllt, sensor_ip, sensor_subnet, sensor_gateway);
}

/**
 * ReadPostProcessingParameter:
 * @ppp_data: array for postprocessing data
 * @size: size of array (must be >1024)
 *
 * Reads the sensors current postprocessing parameter to array
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::ReadPostProcessingParameter(guint32 *ppp_data, guint32 size)
{
    return read_post_processing_parameter(hllt, ppp_data, size);
}

/**
 * WritePostProcessingParameter:
 * @ppp_data: array with postprocessing data
 * @size: size of array (must be >1024)
 *
 * Writes the postprocessing parameter in array to the sensor
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::WritePostProcessingParameter(guint32 *ppp_data, guint32 size)
{
    return write_post_processing_parameter(hllt, ppp_data, size);
}

// Static functions

/**
 * GetDeviceInterfaces:
 * @interfaces: array for found interfaces
 * @interfaces_size: size of interfaces array
 *
 * Find available scanCONTROL sensors on interface
 *
 * Returns: number of found devices or error code
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::GetDeviceInterfaces(char *interfaces[], guint32 interfaces_size)
{
    return get_device_interfaces(interfaces, interfaces_size);
}

/*
 * GetDeviceInfos:
 * @host_ip: IP address of host network interface
 * @sensor_info: array with sensor_info struct
 * @size: size of sensor_info array
 * @eth_if: name of network device (if NULL choose interface automatically)
 *
 * Searches scanner in network via broadcast and collects all available info. If eth_if is NULL, the network device the
 * broadcast is sent through is chosen randomly by the OS. If eth_if is defined, the stated device is bound to the
 * socket. This requires root access.
 *
 * Returns: number of found devices or error code
 *
 * Since: 0.2.1
 */
gint32 CInterfaceLLT::GetDeviceInfos(const char *host_ip, sensor_info_t *sensor_info, guint32 size, const char *eth_if)
{
    return get_device_infos(host_ip, sensor_info, size, eth_if);
}

/*
 * SetDeviceTemporaryIp:
 * @host_ip: IP address of host network interface
 * @mac_address: target MAC address of sensor
 * @sensor_ip: new sensor IP
 * @sensor_subnet: new sensor subnet
 * @sensor_gateway: new sensor gateway
 * @eth_if: name of network device (if NULL choose interface automatically)
 *
 * Sets temporary IP config to sensor with the given MAC address via broadcast. If eth_if is NULL, the network device
 * the broadcast is sent through is chosen randomly by the OS. If eth_if is defined, the stated device is bound to the
 * socket. This requires root access.
 *
 * Returns: error code or success
 *
 * Since: 0.2.1
 */
gint32 CInterfaceLLT::SetDeviceTemporaryIp(const char *host_ip, const char *mac_address, const char *sensor_ip,
                                           const char *sensor_subnet, const char *sensor_gateway, const char *eth_if)
{
    return set_device_temporary_ip(host_ip, mac_address, sensor_ip, sensor_subnet, sensor_gateway, eth_if);
}

/**
 * ConvertProfile2Values:
 * @data: pointer to scanCONTROL data buffer
 * @buffer_size: size of scanCONTROL data buffer
 * @resolution: set resolution of sensor
 * @scanner_type: scanCONTROL Type
 * @reflection: reflection to evaluate
 * @width: reflection width of each point
 * @intensity: intensity of each point
 * @threshold: threshold of each point
 * @x: x value of each point
 * @z: z value of each point
 * @m0: moment 0 of each point
 * @m1: moment 1 of each point
 *
 * Converts the raw data of a full profile received from the sensor to
 * valid result values
 *
 * Returns: information about which data was extracted
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::ConvertProfile2Values(const guint8 *data, guint32 buffer_size, guint32 resolution,
                                            TProfileConfig profile_config, TScannerType scanner_type,
                                            guint32 reflection, gushort *width, gushort *intensity, gushort *threshold,
                                            double *x, double *z, guint32 *m0, guint32 *m1)
{
    return convert_profile_2_values(data, buffer_size, resolution, profile_config, scanner_type, reflection, width,
                                    intensity, threshold, x, z, m0, m1);
}

/**
 * ConvertRearrangedContainer2Values:
 * @data: pointer to scanCONTROL data buffer
 * @buffer_size: size of scanCONTROL data buffer
 * @rearrangement: value of rearrangement register
 * @number_profiles: number of profiles in container
 * @scanner_type: scanCONTROL Type
 * @reflection: reflection to evaluate
 * @width: reflection width of each point
 * @intensity: intensity of each point
 * @threshold: threshold of each point
 * @x: x value of each point
 * @z: z value of each point
 * @m0: moment 0 of each point
 * @m1: moment 1 of each point
 *
 * Converts the raw data of a rearranged container received from the sensor to
 * valid result values
 *
 * Returns: information about which data was extracted
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::ConvertRearrangedContainer2Values(const guint8 *data, guint32 buffer_size, guint32 rearrangement,
                                                        guint32 number_profiles, TScannerType scanner_type,
                                                        guint32 reflection, gushort *width, gushort *intensity,
                                                        gushort *threshold, double *x, double *z)
{
    return convert_rearranged_container_2_values(data, buffer_size, rearrangement, number_profiles, scanner_type,
                                                 reflection, width, intensity, threshold, x, z);
}

/**
 * ConvertPartProfile2Values:
 * @data: pointer to scanCONTROL data buffer
 * @buffer_size: size of scanCONTROL data buffer
 * @partial_profile: TPartialProfile with information about image size
 * @scanner_type: scanCONTROL Type
 * @reflection: reflection to evaluate
 * @width: reflection width of each point
 * @intensity: intensity of each point
 * @threshold: threshold of each point
 * @x: x value of each point
 * @z: z value of each point
 * @m0: moment 0 of each point
 * @m1: moment 1 of each point
 *
 * Converts the raw data of a partial profile received from the sensor to
 * valid result values
 *
 * Returns: information about which data was extracted
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::ConvertPartProfile2Values(const guint8 *data, guint32 buffer_size,
                                                TPartialProfile *partial_profile, TScannerType scanner_type,
                                                guint32 reflection, gushort *width, gushort *intensity,
                                                gushort *threshold, double *x, double *z, guint32 *m0, guint32 *m1)
{
    return convert_part_profile_2_values(data, buffer_size, partial_profile, scanner_type, reflection, width, intensity,
                                         threshold, x, z, m0, m1);
}

/**
 * Timestamp2TimeAndCount:
 * @data: buffer with timestamp raw data (must be 16 bytes)
 * @ts_shutter_opened: absolute timestamp of integration start
 * @ts_shutter_closed: absolute timestamp of integration end
 * @profile_number: profile number of current profile
 *
 * Extracts the most important data from 16 byte timestamp raw data
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::Timestamp2TimeAndCount(const guint8 *data, double *ts_shutter_opened, double *ts_shutter_closed,
                                             guint32 *profile_number, gushort *enc_times2_or_digin)
{
    return timestamp_2_time_and_count(data, ts_shutter_opened, ts_shutter_closed, profile_number, enc_times2_or_digin);
}

/**
 * InitDevice:
 * @camera_name: name string of found scanCONTROL
 * @data: a *MEDeviceData
 * @path: path to device_properties.dat
 *
 * Initializes ME device properties
 *
 * Returns: error code or success
 *
 * Since: 0.1.0
 */
gint32 CInterfaceLLT::InitDevice(const char *camera_name, MEDeviceData *data, const char *path)
{
    return init_device(camera_name, data, path);
}

/**
 * CreateEvent:
 *
 * Initializes Windows-esque event handling
 *
 * Returns: an EHANDLE
 *
 * Since: 0.1.0
 */
EHANDLE *CInterfaceLLT::CreateEvent()
{
    return create_event();
}

/**
 * SetEvent:
 * @event_handle: a *EHANDLE
 *
 * Set the event to signal condition change
 *
 * Since: 0.1.0
 */
void CInterfaceLLT::SetEvent(EHANDLE *event_handle)
{
    return set_event(event_handle);
}

/**
 * ResetEvent:
 * @event_handle: a *EHANDLE
 *
 * Reset event to inital condition
 *
 * Since: 0.1.0
 */
void CInterfaceLLT::ResetEvent(EHANDLE *event_handle)
{
    return reset_event(event_handle);
}

/**
 * FreeEvent:
 * @event_handle: a *EHANDLE
 *
 * Free event handle resources
 *
 * Since: 0.1.0
 */
void CInterfaceLLT::FreeEvent(EHANDLE *event_handle)
{
    return free_event(event_handle);
}

/**
 * WaitForSingleObject:
 * @event_handle: a *EHANDLE
 * @timeout: timeout in milleseconds
 *
 * Waits for event to be set or until timeout is reached.
 *
 * Returns: 0 if successful otherwise an error number
 */
gint32 CInterfaceLLT::WaitForSingleObject(EHANDLE *event_handle, guint32 timeout)
{
    return wait_for_single_object(event_handle, timeout);
}

/**
 * GetLLTTypeByName:
 * @full_model_name: scanCONTROL name as read by aravis
 * @scanner_type: pointer to TScannerType
 *
 * Extracts scanner type from device name
 *
 * Returns: error code or success
 */
gint32 CInterfaceLLT::GetLLTTypeByName(const char *full_model_name, TScannerType *scanner_type)
{
    return get_llt_type_by_name(full_model_name, scanner_type);
}

/**
 * GetScalingAndOffsetByType:
 * @scanner_type: TScannerType
 * @scaling: pointer for scaling value
 * @offset: pointer for offset value
 *
 * Gets scaling and offset factor for scanner type
 *
 * Returns: error code or success
 */
gint32 CInterfaceLLT::GetScalingAndOffsetByType(TScannerType scanner_type, double *scaling, double *offset)
{
    return get_scaling_and_offset_by_type(scanner_type, scaling, offset);
}

/**
 * TranslateErrorValue:
 * @error_value: error value to translate
 * @error_string: pointer to string buffer
 * @string_size: string buffer size
 *
 * Translates error value to more readable error string
 *
 * Returns: error code or success
 *
 * Since: 0.2.0
 */
gint32 CInterfaceLLT::TranslateErrorValue(gint32 error_value, char *error_string, guint32 string_size)
{
    return translate_error_value(error_value, error_string, string_size);
}
