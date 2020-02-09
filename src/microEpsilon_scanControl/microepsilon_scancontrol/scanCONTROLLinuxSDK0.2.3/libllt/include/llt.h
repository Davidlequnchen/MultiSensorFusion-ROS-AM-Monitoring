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

#ifndef LLT_H
#define LLT_H

#ifdef __cplusplus
extern "C" {
#endif
#include <mescan.h>
#ifdef __cplusplus
}
#endif

// LLT Interface Class
class CInterfaceLLT
{
  public:
    explicit CInterfaceLLT();
    ~CInterfaceLLT();

    // Init and connect
    gint32 Connect();
    gint32 Disconnect();
    gint32 SetDeviceInterface(const char *device_interface);
    gint32 SetPathDeviceProperties(const char *path_device_properties);

    // Get info, features and current parameter settings
    gint32 GetMEDeviceData(MEDeviceData **device_data);
    gint32 GetArvDevice(ArvDevice **device);

    gint32 GetStreamStatistics(guint64 *completed_buffers, guint64 *failures, guint64 *underruns);
    gint32 GetLLTType(TScannerType *scanner_type);
    gint32 GetDeviceName(char *device_name, guint32 dev_name_size, char *vendor_name, guint32 ven_name_size);
    gint32 GetLLTVersions(guint32 *dsp, guint32 *fpga1, guint32 *fpga2);
    gint32 GetProfileConfig(TProfileConfig *profile_config);
    gint32 GetFeature(guint32 register_address, guint32 *value);
    gint32 GetPartialProfile(TPartialProfile *partial_profile);
    gint32 GetProfileContainerSize(guint32 *width, guint32 *height);
    gint32 GetMaxProfileContainerSize(guint32 *max_width, guint32 *max_height);
    gint32 GetBufferCount(guint32 *buffer_count);
    gint32 GetResolutions(guint32 *resolutions, guint32 resolutions_size);
    gint32 GetResolution(guint32 *resolution);
    gint32 GetPartialProfileUnitSize(guint32 *unit_size_point, guint32 *unit_size_point_data);
    gint32 GetMinMaxPacketSize(guint32 *min_packet_size, guint32 *max_packet_size);
    gint32 GetPacketSize(guint32 *packet_size);
    gint32 GetStreamPriority(guint32 *realtime_priority);
    gint32 GetStreamNiceValue(guint32 *nice_value);
    gint32 GetStreamPriorityState(TStreamPriorityState *stream_priority_state);
    gint32 GetLLTScalingAndOffset(double *offset, double *scaling);
    gint32 GetHoldBufferForPolling(guint32 *holding_buffer_ct);
    gint32 GetEthernetHeartbeatTimeout(guint32 *timeout_in_ms);
    gint32 GetActualProfile(guint8 *buffer, gint32 buffer_size, TProfileConfig profile_config, guint32 *lost_profiles);

    // Set features and parameters
    gint32 SetProfileConfig(TProfileConfig profile_config);
    gint32 SetFeature(guint32 register_address, guint32 value);
    gint32 SetResolution(guint32 resolution);
    gint32 SetProfileContainerSize(guint32 width, guint32 height);
    gint32 SetPartialProfile(TPartialProfile *partial_profile);
    gint32 SetBufferCount(guint32 buffer_count);
    gint32 SetPacketSize(guint32 packet_size);
    gint32 SetStreamNiceValue(guint32 nice);
    gint32 SetStreamPriority(guint32 priority);
    gint32 SetHoldBufferForPolling(guint32 holding_buffer_ct);
    gint32 SetEthernetHeartbeatTimeout(guint32 timeout_in_ms);

    // Usermode handling
    gint32 GetActualUserMode(guint32 *current_usermode, guint32 *available_usermodes);
    gint32 ReadWriteUserModes(gboolean read_write, guint32 usermode);
    gint32 SaveGlobalParameter();

    // Calibration
    gint32 SetCustomCalibration(double center_x, double center_z, double angle, double shift_x, double shift_z);
    gint32 ResetCustomCalibration();

    // Advanced
    gint32 TriggerProfile();
    gint32 TriggerContainer();
    gint32 ContainerTriggerEnable();
    gint32 ContainerTriggerDisable();
    gint32 SetPeakFilter(gushort min_width, gushort max_width, gushort min_intensity, gushort max_intensity);
    gint32 SetFreeMeasuringField(gushort start_x, gushort size_x, gushort start_z, gushort size_z);
    gint32 SetDynamicMeasuringFieldTracking(gushort div_x, gushort div_z, gushort multi_x, gushort multi_z);

    // Callback handling
    gint32 RegisterBufferCallback(gpointer buffer_callback_function, gpointer user_data);
    gint32 RegisterControlLostCallback(gpointer control_lost_callback_function, gpointer user_data);

    // Transmission
    gint32 TransferProfiles(TTransferProfileType transfer_profile_type, gboolean active);
    gint32 TransferVideoStream(TTransferVideoType video_type, gboolean is_active, guint32 *width, guint32 *height);

    // Misc
    gint32 ExportLLTConfig(const char *file_name);
    gint32 ExportLLTConfigString(char *data_array, gint32 array_size);
    gint32 ImportLLTConfig(const char *file_name, gboolean ignore_calibration);
    gint32 ImportLLTConfigString(const char *config_string, gint32 string_size, gboolean ignore_calibration);
    gint32 SetPersistentIp(const char *sensor_ip, const char *sensor_subnet, const char *sensor_gateway);

    // Post Processing
    gint32 ReadPostProcessingParameter(guint32 *ppp_data, guint32 size);
    gint32 WritePostProcessingParameter(guint32 *ppp_data, guint32 size);

    // Static functions
    static gint32 GetDeviceInterfaces(char *interfaces[], guint32 interfaces_size);
    static gint32 GetDeviceInfos(const char *host_ip, sensor_info_t *sensor_info, guint32 size, const char *eth_if);
    static gint32 SetDeviceTemporaryIp(const char *host_ip, const char *mac_address, const char *sensor_ip,
                                       const char *sensor_subnet, const char *sensor_gateway, const char *eth_if);
    static gint32 ConvertProfile2Values(const guint8 *data, guint32 buffer_size, guint32 resolution,
                                        TProfileConfig profile_config, TScannerType scanner_type, guint32 reflection,
                                        gushort *width, gushort *intensity, gushort *threshold, double *x, double *z,
                                        guint32 *m0, guint32 *m1);
    static gint32 ConvertRearrangedContainer2Values(const guint8 *data, guint32 buffer_size, guint32 rearrangement,
                                                    guint32 number_profiles, TScannerType scanner_type,
                                                    guint32 reflection, gushort *width, gushort *intensity,
                                                    gushort *threshold, double *x, double *z);
    static gint32 ConvertPartProfile2Values(const guint8 *data, guint32 buffer_size, TPartialProfile *partial_profile,
                                            TScannerType scanner_type, guint32 reflection, gushort *width,
                                            gushort *intensity, gushort *threshold, double *x, double *z, guint32 *m0,
                                            guint32 *m1);
    static gint32 Timestamp2TimeAndCount(const guint8 *data, double *ts_shutter_opened, double *ts_shutter_closed,
                                         guint32 *profile_number, gushort *enc_times2_or_digin);
    static gint32 InitDevice(const char *camera_name, MEDeviceData *data, const char *path);
    static gint32 GetLLTTypeByName(const char *full_model_name, TScannerType *scanner_type);
    static gint32 GetScalingAndOffsetByType(TScannerType scanner_type, double *scaling, double *offset);
    static gint32 TranslateErrorValue(gint32 error_value, char *error_string, guint32 string_size);

    static EHANDLE *CreateEvent();
    static void SetEvent(EHANDLE *event_handle);
    static void ResetEvent(EHANDLE *event_handle);
    static void FreeEvent(EHANDLE *event_handle);
    static gint32 WaitForSingleObject(EHANDLE *event_handle, guint32 timeout);

  private:
    // LLT handle
    LLT *hllt;
};

#endif // LLT_H
