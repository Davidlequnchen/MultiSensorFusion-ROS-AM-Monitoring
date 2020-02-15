#
# scanCONTROL Linux SDK - example code
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

import time
import ctypes as ct
from matplotlib import pyplot as plt
import pylinllt as llt

scanner_type = ct.c_int(0)

# Init profile buffer and timestamp info
timestamp = (ct.c_ubyte*16)()
available_resolutions = (ct.c_uint*4)()
available_interfaces = [ct.create_string_buffer(8) for i in range(6)]
available_interfaces_p = (ct.c_char_p * 6)(*map(ct.addressof, available_interfaces))

lost_profiles = ct.c_uint()
shutter_opened = ct.c_double(0.0)
shutter_closed = ct.c_double(0.0)
profile_count = ct.c_uint(0)

# Null pointer if data not necessary
null_ptr_short = ct.POINTER(ct.c_ushort)()
null_ptr_int = ct.POINTER(ct.c_uint)()

hLLT = llt.create_llt_device()

ret = llt.get_device_interfaces(available_interfaces_p, len(available_interfaces))
if ret < 1:
    raise ValueError("Error getting interfaces : " + str(ret))

ret = llt.set_device_interface(hLLT, available_interfaces[0])
if ret < 1:
    raise ValueError("Error setting device interface: " + str(ret))

# Connect
ret = llt.connect(hLLT)
if ret < 1:
    raise ConnectionError("Error connect: " + str(ret))

# Get available resolutions
ret = llt.get_resolutions(hLLT, available_resolutions, len(available_resolutions))
if ret < 1:
    raise ValueError("Error getting resolutions : " + str(ret))

# Set max. resolution
resolution = available_resolutions[0]
ret = llt.set_resolution(hLLT, resolution)
if ret < 1:
    raise ValueError("Error getting resolutions : " + str(ret))

# Declare measuring data arrays
profile_buffer = (ct.c_ubyte*(resolution*64))()
x = (ct.c_double * resolution)()
z = (ct.c_double * resolution)()
intensities = (ct.c_ushort * resolution)()

# Scanner type
ret = llt.get_llt_type(hLLT, ct.byref(scanner_type))
if ret < 1:
    raise ValueError("Error scanner type: " + str(ret))

# Scanner type
ret = llt.set_resolution(hLLT, resolution)
if ret < 1:
    raise ValueError("Error setting resolution: " + str(ret))

# Set profile config
ret = llt.set_profile_config(hLLT, llt.TProfileConfig.PROFILE)
if ret < 1:
    raise ValueError("Error setting profile config: " + str(ret))

# Set trigger
ret = llt.set_feature(hLLT, llt.FEATURE_FUNCTION_TRIGGER, llt.TRIG_INTERNAL)
if ret < 1:
    raise ValueError("Error setting trigger: " + str(ret))

# Set exposure time
ret = llt.set_feature(hLLT, llt.FEATURE_FUNCTION_EXPOSURE_TIME, 100)
if ret < 1:
    raise ValueError("Error setting exposure time: " + str(ret))

# Set idle time
ret = llt.set_feature(hLLT, llt.FEATURE_FUNCTION_IDLE_TIME, 3900)
if ret < 1:
    raise ValueError("Error idle time: " + str(ret))

# Start transfer
ret = llt.transfer_profiles(hLLT, llt.TTransferProfileType.NORMAL_TRANSFER, 1)
if ret < 1:
    raise ValueError("Error starting transfer profiles: " + str(ret))

# Warm-up time
time.sleep(0.2)

ret = llt.get_actual_profile(hLLT, profile_buffer, len(profile_buffer), llt.TProfileConfig.PROFILE,
                           ct.byref(lost_profiles))
if ret != len(profile_buffer):
    raise ValueError("Error get profile buffer data: " + str(ret))

ret = llt.convert_profile_2_values(profile_buffer, len(profile_buffer), resolution, llt.TProfileConfig.PROFILE, scanner_type, 0,
                                null_ptr_short, intensities, null_ptr_short, x, z, null_ptr_int, null_ptr_int)
if ret & llt.CONVERT_X is 0 or ret & llt.CONVERT_Z is 0 or ret & llt.CONVERT_MAXIMUM is 0:
    raise ValueError("Error converting data: " + str(ret))

for i in range(16):
    timestamp[i] = profile_buffer[resolution * 64 - 16 + i]

llt.timestamp_2_time_and_count(timestamp, ct.byref(shutter_opened), ct.byref(shutter_closed), ct.byref(profile_count), null_ptr_short)

# Stop transmission
ret = llt.transfer_profiles(hLLT, llt.TTransferProfileType.NORMAL_TRANSFER, 0)
if ret < 1:
    raise ValueError("Error stopping transfer profiles: " + str(ret))

# Disconnect
ret = llt.disconnect(hLLT)
if ret < 1:
    raise ConnectionAbortedError("Error while disconnect: " + str(ret))

# Delete
ret = llt.del_device(hLLT)
if ret < 1:
    raise ConnectionAbortedError("Error while delete: " + str(ret))

plt.figure(facecolor='white')
plt.subplot(211)
plt.grid()
plt.xlabel('x')
plt.ylabel('z')
plt.xlim(-60, 60)
plt.ylim(25, 350)
plt.plot(x, z, 'g.', label="z", lw=2)
plt.subplot(212)
plt.grid()
plt.xlabel('x')
plt.ylabel('intensities')
plt.xlim(-30, 30)
plt.ylim(0, 1200)
plt.plot(x, intensities, 'r.', label="intensities", lw=1)
plt.show()