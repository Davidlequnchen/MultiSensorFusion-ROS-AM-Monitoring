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

#ifndef MESCANADV_H
#define MESCANADV_H

#include <mescan_basic.h>

// instance handling
LLT *create_llt_device();
gint32 del_device(LLT *hllt);

// init and connect
gint32 connect_llt(LLT *hllt);
gint32 disconnect_llt(LLT *hllt);
gint32 set_device_interface(LLT *hllt, const char *device_interface);
gint32 set_path_device_properties(LLT *hllt, const char *path_to_dev_prop);

// get info, features and current parameter settings
gint32 get_medevice_data(LLT *hllt, MEDeviceData **device_data);
gint32 get_arv_device(LLT *hllt, ArvDevice **device);
gint32 get_stream_statistics(LLT *hllt, guint64 *completed_buffers, guint64 *failures, guint64 *underruns);
gint32 get_llt_type(LLT *hllt, TScannerType *scanner_type);
gint32 get_device_name(LLT *hllt, char *device_name, guint32 dev_name_size, char *vendor_name, guint32 ven_name_size);
gint32 get_llt_versions(LLT *hllt, guint32 *dsp, guint32 *fpga1, guint32 *fpga2);

gint32 get_profile_config(LLT *hllt, TProfileConfig *profile_config);
gint32 get_feature(LLT *hllt, guint32 register_address, guint32 *value);
gint32 get_partial_profile(LLT *hllt, TPartialProfile *partial_profile);
gint32 get_profile_container_size(LLT *hllt, guint32 *width, guint32 *height);
gint32 get_max_profile_container_size(LLT *hllt, guint32 *max_width, guint32 *max_height);
gint32 get_buffer_count(LLT *hllt, guint32 *buffer_count);
gint32 get_resolutions(LLT *hllt, guint32 *resolutions, guint32 resolutions_size);
gint32 get_resolution(LLT *hllt, guint32 *resolution);
gint32 get_partial_profile_unit_size(LLT *hllt, guint32 *unit_size_point, guint32 *unit_size_point_data);
gint32 get_min_max_packet_size(LLT *hllt, guint32 *min_packet_size, guint32 *max_packet_size);
gint32 get_packet_size(LLT *hllt, guint32 *packet_size);
gint32 get_stream_nice_value(LLT *hllt, guint32 *nice_value);
gint32 get_stream_priority(LLT *hllt, guint32 *realtime_priority);
gint32 get_llt_scaling_and_offset(LLT *hllt, double *scaling, double *offset);
gint32 get_hold_buffers_for_polling(LLT *hllt, guint32 *holding_buffer_ct);
gint32 get_stream_priority_state(LLT *hllt, TStreamPriorityState *stream_priority_state);
gint32 get_ethernet_heartbeat_timeout(LLT *hllt, guint32 *timeout_in_ms);

// set features and parameters
gint32 set_profile_config(LLT *hllt, TProfileConfig profile_config);
gint32 set_feature(LLT *hllt, guint32 register_address, guint32 value);
gint32 set_resolution(LLT *hllt, guint32 resolution);
gint32 set_profile_container_size(LLT *hllt, guint32 width, guint32 height);
gint32 set_partial_profile(LLT *hllt, TPartialProfile *partial_profile);
gint32 set_buffer_count(LLT *hllt, guint32 buffer_count);
gint32 set_packet_size(LLT *hllt, guint32 packet_size);
gint32 set_stream_nice_value(LLT *hllt, guint32 nice);
gint32 set_stream_priority(LLT *hllt, guint32 priority);
gint32 set_hold_buffers_for_polling(LLT *hllt, guint32 holding_buffer_ct);
gint32 set_ethernet_heartbeat_timeout(LLT *hllt, guint32 timeout_in_ms);

// usermode handling
gint32 get_actual_usermode(LLT *hllt, guint32 *current_usermode, guint32 *available_usermodes);
gint32 read_write_usermodes(LLT *hllt, gboolean read_write, guint32 usermode);

// calibration
gint32 set_custom_calibration(LLT *hllt, double center_x, double center_z, double angle, double shift_x,
                              double shift_z);
gint32 reset_custom_calibration(LLT *hllt);

// callback handling
gint32 register_buffer_callback(LLT *hllt, gpointer buffer_callback_function, gpointer user_data);
gint32 register_control_lost_callback(LLT *hllt, gpointer control_lost_callback_function, gpointer user_data);

// transmission
gint32 transfer_profiles(LLT *hllt, TTransferProfileType transfer_profile_type, gboolean is_active);
gint32 transfer_video_stream(LLT *hllt, TTransferVideoType video_type, gboolean is_active, guint32 *width, guint32 *height);
gint32 get_actual_profile(LLT *hllt, unsigned char *buffer, gint32 buffer_size, TProfileConfig profile_config,
                          guint32 *lost_profiles);

// advanced functions
gint32 set_persistent_ip(LLT *hllt, const char *sensor_ip, const char *sensor_subnet, const char *sensor_gateway);
gint32 save_global_parameter(LLT *hllt);
gint32 trigger_profile(LLT *hllt);
gint32 trigger_container(LLT *hllt);
gint32 container_trigger_enable(LLT *hllt);
gint32 container_trigger_disable(LLT *hllt);
gint32 set_peak_filter(LLT *hllt, gushort min_width, gushort max_width, gushort min_intensity, gushort max_intensity);
gint32 set_free_measuring_field(LLT *hllt, gushort start_x, gushort size_x, gushort start_z, gushort size_z);
gint32 set_dynamic_measuring_field_tracking(LLT *hllt, gushort div_x, gushort div_z, gushort multi_x, gushort multi_z);

// misc
gint32 export_llt_config(LLT *hllt, const char *file_name);
gint32 export_llt_config_string(LLT *hllt, char *data_array, gint32 size);
gint32 import_llt_config(LLT *hllt, const char *file_name, gboolean ignore_calibration);
gint32 import_llt_config_string(LLT *hllt, const char *data_array, gint32 size, gboolean ignore_calibration);

// post processing
gint32 read_post_processing_parameter(LLT *hllt, guint32 *ppp_data, guint32 size);
gint32 write_post_processing_parameter(LLT *hllt, guint32 *ppp_data, guint32 size);

#endif // MESCANADV_H
