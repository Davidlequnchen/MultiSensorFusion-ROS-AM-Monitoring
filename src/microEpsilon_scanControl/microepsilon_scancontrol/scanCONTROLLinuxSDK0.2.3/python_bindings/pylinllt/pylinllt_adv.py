#
# scanCONTROL Linux Python Bindings
#
# MIT License
#
# Copyright (c) 2017-2018 Micro-Epsilon Messtechnik GmbH & Co. KG
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#
#

from .pylinllt_basic import llt
from .llt_datatypes import *

# Callback
buffer_cb_func = ct.CFUNCTYPE(None, ct.c_void_p, ct.c_uint, ct.c_void_p)
buffer_cl_func = ct.CFUNCTYPE(None, ct.c_void_p, ct.c_void_p)

create_llt_device = llt['create_llt_device']
create_llt_device.restype = ct.POINTER(LLT)
create_llt_device.argtypes = []

del_device = llt['del_device']
del_device.restype = ct.c_int
del_device.argtypes = [ct.POINTER(LLT)]

connect = llt['connect_llt']
connect.restype = ct.c_int
connect.argtypes = [ct.POINTER(LLT)]

disconnect = llt['disconnect_llt']
disconnect.restype = ct.c_int
disconnect.argtypes = [ct.POINTER(LLT)]

set_device_interface = llt['set_device_interface']
set_device_interface.restype = ct.c_int
set_device_interface.argtypes = [ct.POINTER(LLT), ct.c_char_p]

set_path_device_properties = llt['set_path_device_properties']
set_path_device_properties.restype = ct.c_int
set_path_device_properties.argtypes = [ct.POINTER(LLT), ct.c_char_p]

# ID functions
get_llt_type = llt['get_llt_type']
get_llt_type.restype = ct.c_int
get_llt_type.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_int)]

get_device_name = llt['get_device_name']
get_device_name.restype = ct.c_int
get_device_name.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_char_p), ct.POINTER(ct.c_char_p)]

get_llt_versions = llt['get_llt_versions']
get_llt_versions.restype = ct.c_int
get_llt_versions.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

get_medevice_data = llt['get_medevice_data']
get_medevice_data.restype = ct.c_int
get_medevice_data.argtypes = [ct.POINTER(LLT), ct.POINTER(MEDeviceData)]

get_arv_device = llt['get_arv_device']
get_arv_device.restype = ct.c_int
get_arv_device.argtypes = [ct.POINTER(LLT), ct.POINTER(ArvDevice)]

get_stream_statistics = llt['get_stream_statistics']
get_stream_statistics.restype = ct.c_int
get_stream_statistics.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_ulong), ct.POINTER(ct.c_ulong), ct.POINTER(ct.c_ulong)]

get_profile_config = llt['get_profile_config']
get_profile_config.restype = ct.c_int
get_profile_config.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_int)]

get_feature = llt['get_feature']
get_feature.restype = ct.c_int
get_feature.argtypes = [ct.POINTER(LLT), ct.c_uint, ct.POINTER(ct.c_uint)]

get_partial_profile = llt['get_partial_profile']
get_partial_profile.restype = ct.c_int
get_partial_profile.argtypes = [ct.POINTER(LLT), ct.POINTER(TPartialProfile)]

get_profile_container_size = llt['get_profile_container_size']
get_profile_container_size.restype = ct.c_int
get_profile_container_size.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

get_max_profile_container_size = llt['get_max_profile_container_size']
get_max_profile_container_size.restype = ct.c_int
get_max_profile_container_size.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

get_buffer_count = llt['get_buffer_count']
get_buffer_count.restype = ct.c_int
get_buffer_count.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_resolutions = llt['get_resolutions']
get_resolutions.restype = ct.c_int
get_resolutions.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.c_uint]

get_resolution = llt['get_resolution']
get_resolution.restype = ct.c_int
get_resolution.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_partial_profile_unit_size = llt['get_partial_profile_unit_size']
get_partial_profile_unit_size.restype = ct.c_int
get_partial_profile_unit_size.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

get_min_max_packet_size = llt['get_min_max_packet_size']
get_min_max_packet_size.restype = ct.c_int
get_min_max_packet_size.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

get_packet_size = llt['get_packet_size']
get_packet_size.restype = ct.c_int
get_packet_size.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_stream_nice_value = llt['get_stream_nice_value']
get_stream_nice_value.restype = ct.c_int
get_stream_nice_value.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_stream_priority = llt['get_stream_priority']
get_stream_priority.restype = ct.c_int
get_stream_priority.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_ethernet_heartbeat_timeout = llt['get_ethernet_heartbeat_timeout']
get_ethernet_heartbeat_timeout.restype = ct.c_int
get_ethernet_heartbeat_timeout.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_llt_scaling_and_offset = llt['get_llt_scaling_and_offset']
get_llt_scaling_and_offset.restype = ct.c_int
get_llt_scaling_and_offset.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

get_hold_buffers_for_polling = llt['get_hold_buffers_for_polling']
get_hold_buffers_for_polling.restype = ct.c_int
get_hold_buffers_for_polling.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint)]

get_stream_priority_state = llt['get_stream_priority_state']
get_stream_priority_state.restype = ct.c_int
get_stream_priority_state.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_int)]

# Set functions
set_profile_config = llt['set_profile_config']
set_profile_config.restype = ct.c_int
set_profile_config.argtypes = [ct.POINTER(LLT), ct.c_int]

set_feature = llt['set_feature']
set_feature.restype = ct.c_int
set_feature.argtypes = [ct.POINTER(LLT), ct.c_uint, ct.c_uint]

set_resolution = llt['set_resolution']
set_resolution.restype = ct.c_int
set_resolution.argtypes = [ct.POINTER(LLT), ct.c_uint]

set_profile_container_size = llt['set_profile_container_size']
set_profile_container_size.restype = ct.c_int
set_profile_container_size.argtypes = [ct.POINTER(LLT), ct.c_uint, ct.c_uint]

set_partial_profile = llt['set_partial_profile']
set_partial_profile.restype = ct.c_int
set_partial_profile.argtypes = [ct.POINTER(LLT), ct.POINTER(TPartialProfile)]

set_buffer_count = llt['set_buffer_count']
set_buffer_count.restype = ct.c_int
set_buffer_count.argtypes = [ct.POINTER(LLT), ct.c_uint]

set_packet_size = llt['set_packet_size']
set_packet_size.restype = ct.c_int
set_packet_size.argtypes = [ct.POINTER(LLT), ct.c_uint]

set_stream_nice_value = llt['set_stream_nice_value']
set_stream_nice_value.restype = ct.c_int
set_stream_nice_value.argtypes = [ct.POINTER(LLT), ct.c_uint]

set_stream_priority = llt['set_stream_priority']
set_stream_priority.restype = ct.c_int
set_stream_priority.argtypes = [ct.POINTER(LLT), ct.c_uint]

set_ethernet_heartbeat_timeout = llt['set_ethernet_heartbeat_timeout']
set_ethernet_heartbeat_timeout.restype = ct.c_int
set_ethernet_heartbeat_timeout.argtypes = [ct.POINTER(LLT), ct.c_uint]

set_hold_buffers_for_polling = llt['set_hold_buffers_for_polling']
set_hold_buffers_for_polling.restype = ct.c_int
set_hold_buffers_for_polling.argtypes = [ct.POINTER(LLT), ct.c_uint]

# Maintenance

get_actual_usermode = llt['get_actual_usermode']
get_actual_usermode.restype = ct.c_int
get_actual_usermode.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

read_write_usermodes = llt['read_write_usermodes']
read_write_usermodes.restype = ct.c_int
read_write_usermodes.argtypes = [ct.POINTER(LLT), ct.c_bool, ct.c_uint]

save_global_parameter = llt['set_persistent_ip']
save_global_parameter.restype = ct.c_int
save_global_parameter.argtypes = [ct.POINTER(LLT), ct.c_char_p, ct.c_char_p, ct.c_char_p]

save_global_parameter = llt['save_global_parameter']
save_global_parameter.restype = ct.c_int
save_global_parameter.argtypes = [ct.POINTER(LLT)]

set_custom_calibration = llt['set_custom_calibration']
set_custom_calibration.restype = ct.c_int
set_custom_calibration.argtypes = [ct.POINTER(LLT), ct.c_double, ct.c_double, ct.c_double, ct.c_double, ct.c_double]

reset_custom_calibration = llt['reset_custom_calibration']
reset_custom_calibration.restype = ct.c_int
reset_custom_calibration.argtypes = [ct.POINTER(LLT)]

# Register Functions

register_buffer_callback = llt['register_buffer_callback']
register_buffer_callback.restype = ct.c_int
register_buffer_callback.argtypes = [ct.POINTER(LLT), buffer_cb_func, ct.c_void_p]

register_control_lost_callback = llt['register_control_lost_callback']
register_control_lost_callback.restype = ct.c_int
register_control_lost_callback.argtypes = [ct.POINTER(LLT), buffer_cl_func, ct.c_void_p]

# Transfer

transfer_video_stream = llt['transfer_video_stream']
transfer_video_stream.restype = ct.c_int
transfer_video_stream.argtypes = [ct.POINTER(LLT), ct.c_int, ct.c_bool, ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]

transfer_profiles = llt['transfer_profiles']
transfer_profiles.restype = ct.c_int
transfer_profiles.argtypes = [ct.POINTER(LLT), ct.c_int, ct.c_bool]

get_actual_profile = llt['get_actual_profile']
get_actual_profile.restype = ct.c_int
get_actual_profile.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_ubyte), ct.c_uint, ct.c_int, ct.POINTER(ct.c_uint)]

# Advanced

trigger_profile = llt['trigger_profile']
trigger_profile.restype = ct.c_int
trigger_profile.argtypes = [ct.POINTER(LLT)]

set_peak_filter = llt['set_peak_filter']
set_peak_filter.restype = ct.c_int
set_peak_filter.argtypes = [ct.POINTER(LLT), ct.c_ushort, ct.c_ushort, ct.c_ushort, ct.c_ushort]

set_free_measuring_field = llt['set_free_measuring_field']
set_free_measuring_field.restype = ct.c_int
set_free_measuring_field.argtypes = [ct.POINTER(LLT), ct.c_ushort, ct.c_ushort, ct.c_ushort, ct.c_ushort]

set_dynamic_measuring_field_tracking = llt['set_dynamic_measuring_field_tracking']
set_dynamic_measuring_field_tracking.restype = ct.c_int
set_dynamic_measuring_field_tracking.argtypes = [ct.POINTER(LLT), ct.c_ushort, ct.c_ushort, ct.c_ushort, ct.c_ushort]

export_llt_config = llt['export_llt_config']
export_llt_config.restype = ct.c_int
export_llt_config.argtypes = [ct.POINTER(LLT), ct.c_char_p]

export_llt_config_string = llt['export_llt_config_string']
export_llt_config_string.restype = ct.c_int
export_llt_config_string.argtypes = [ct.POINTER(LLT), ct.c_char_p, ct.c_int]

import_llt_config = llt['import_llt_config']
import_llt_config.restype = ct.c_int
import_llt_config.argtypes = [ct.POINTER(LLT), ct.c_char_p, ct.c_int]

import_llt_config_string = llt['import_llt_config_string']
import_llt_config_string.restype = ct.c_int
import_llt_config_string.argtypes = [ct.POINTER(LLT), ct.c_char_p, ct.c_int, ct.c_int]

# PostProcessing

read_post_processing_parameter = llt['read_post_processing_parameter']
read_post_processing_parameter.restype = ct.c_int
read_post_processing_parameter.argtypes = [ct.c_uint, ct.POINTER(ct.c_uint), ct.c_uint]

write_post_processing_parameter = llt['write_post_processing_parameter']
write_post_processing_parameter.restype = ct.c_int
write_post_processing_parameter.argtypes = [ct.c_uint, ct.POINTER(ct.c_uint), ct.c_uint]
