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

import os.path
from .llt_datatypes import *

lib_name = "libmescan.so"
lib_path = "/usr/local/lib" + os.path.sep + lib_name

# DLL Loader
llt = ct.CDLL(lib_path)

get_device_interfaces = llt['get_device_interfaces']
get_device_interfaces.restype = ct.c_int
get_device_interfaces.argtypes = [ct.POINTER(ct.c_char_p), ct.c_uint]

# Init Device
init_device = llt['init_device']
init_device.restype = ct.c_int
init_device.argtypes = [ct.c_char_p, ct.POINTER(MEDeviceData), ct.c_char_p]

set_device_temporary_ip = llt['set_device_temporary_ip']
set_device_temporary_ip.restype = ct.c_int
set_device_temporary_ip.argtypes = [ct.c_char_p, ct.c_char_p, ct.c_char_p,
                                ct.c_char_p, ct.c_char_p, ct.c_char_p]

# Getter
get_llt_type_by_name = llt['get_llt_type_by_name']
get_llt_type_by_name.restype = ct.c_int
get_llt_type_by_name.argtypes = [ct.c_char_p, ct.POINTER(ct.c_int)]

get_scaling_and_offset_by_type = llt['get_scaling_and_offset_by_type']
get_scaling_and_offset_by_type.restype = ct.c_int
get_scaling_and_offset_by_type.argtypes = [ct.c_int, ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]

# Convert Profiles
convert_profile_2_values = llt['convert_profile_2_values']
convert_profile_2_values.restype = ct.c_int
convert_profile_2_values.argtypes = [ct.POINTER(ct.c_ubyte), ct.c_uint, ct.c_uint, ct.c_int, TScannerType, 
                                  ct.c_uint, ct.POINTER(ct.c_ushort), ct.POINTER(ct.c_ushort), ct.POINTER(ct.c_ushort),
                                  ct.POINTER(ct.c_double), ct.POINTER(ct.c_double), ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]


convert_part_profile_2_values = llt['convert_part_profile_2_values']
convert_part_profile_2_values.restype = ct.c_int
convert_part_profile_2_values.argtypes = [ct.POINTER(ct.c_ubyte), ct.c_uint, ct.POINTER(TPartialProfile), TScannerType,
                                      ct.c_uint, ct.POINTER(ct.c_ushort), ct.POINTER(ct.c_ushort),
                                      ct.POINTER(ct.c_ushort), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double),
                                      ct.POINTER(ct.c_uint), ct.POINTER(ct.c_uint)]


convert_rearranged_container_2_values = llt['convert_rearranged_container_2_values']
convert_rearranged_container_2_values.restype = ct.c_int
convert_rearranged_container_2_values.argtypes = [ct.POINTER(ct.c_ubyte), ct.c_uint, ct.c_uint, ct.c_uint, TScannerType,
                                      ct.c_uint, ct.POINTER(ct.c_ushort), ct.POINTER(ct.c_ushort),
                                      ct.POINTER(ct.c_ushort), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double)]


# Timestamp
timestamp_2_time_and_count = llt['timestamp_2_time_and_count']
timestamp_2_time_and_count.restype = None
timestamp_2_time_and_count.argtypes = [ct.POINTER(ct.c_ubyte), ct.POINTER(ct.c_double), ct.POINTER(ct.c_double),
                                   ct.POINTER(ct.c_uint), ct.POINTER(ct.c_ushort)]

# MISC

translate_error_value = llt['translate_error_value']
translate_error_value.restype = ct.c_int
translate_error_value.argtypes = [ct.POINTER(LLT), ct.POINTER(ct.c_char_p), ct.c_uint]

# Event funcs
create_event = llt['create_event']
create_event.restype = ct.POINTER(EHANDLE)
create_event.argtypes = []

set_event = llt['set_event']
set_event.argtypes = [ct.POINTER(EHANDLE)]

reset_event = llt['reset_event']
reset_event.argtypes = [ct.POINTER(EHANDLE)]

free_event = llt['free_event']
free_event.argtypes = [ct.POINTER(EHANDLE)]

wait_for_single_object = llt['wait_for_single_object']
wait_for_single_object.restype = ct.c_int
wait_for_single_object.argtypes = [ct.POINTER(EHANDLE), ct.c_uint]
