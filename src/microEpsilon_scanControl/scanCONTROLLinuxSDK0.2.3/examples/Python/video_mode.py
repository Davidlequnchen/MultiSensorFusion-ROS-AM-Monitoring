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
import numpy as np
from matplotlib import pyplot as plt
import pylinllt as llt

# Parametrize transmission --- Important: make sure this is compliant to sensor
scanner_type = ct.c_int(0)
null_ptr_int = ct.POINTER(ct.c_uint)()

# Init profile buffer and timestamp info
available_resolutions = (ct.c_uint*4)()
available_interfaces = [ct.create_string_buffer(8) for i in range(6)]
available_interfaces_p = (ct.c_char_p * 6)(*map(ct.addressof, available_interfaces))
lost_profiles = ct.c_uint()

# Create instance and set IP address
hLLT = llt.create_llt_device()

# Get available interfaces
ret = llt.get_device_interfaces(available_interfaces_p, len(available_interfaces))
if ret < 1:
    raise ValueError("Error getting interfaces : " + str(ret))

ret = llt.set_device_interface(hLLT, available_interfaces[0], 0)
if ret < 1:
    raise ValueError("Error setting device interface: " + str(ret))

# Connect
ret = llt.connect(hLLT)
if ret < 1:
    raise ConnectionError("Error connect: " + str(ret))

# Scanner type
ret = llt.get_llt_type(hLLT, ct.byref(scanner_type))
if ret < 1:
    raise ValueError("Error scanner type: " + str(ret))

# Set exposure time
ret = llt.set_feature(hLLT, llt.FEATURE_FUNCTION_EXPOSURE_TIME, 100)
if ret < 1:
    raise ValueError("Error setting exposure time: " + str(ret))

# Set idle time
ret = llt.set_feature(hLLT, llt.FEATURE_FUNCTION_IDLE_TIME, 3900)
if ret < 1:
    raise ValueError("Error idle time: " + str(ret))

# Set profile config
ret = llt.set_profile_config(hLLT, llt.TProfileConfig.VIDEO_IMAGE)
if ret < 1:
    raise ValueError("Error setting profile config: " + str(ret))

height = ct.c_uint(0)
width = ct.c_uint(0)

# use VIDEO_MODE_0 for scanCONTROL 30xx series, to save bandwidth
video_type = llt.TTransferVideoType.VIDEO_MODE_1
if llt.TScannerType.scanCONTROL30xx_25 <= scanner_type.value <= llt.TScannerType.scanCONTROL30xx_xxx:
    video_type = llt.TTransferVideoType.VIDEO_MODE_0

# Start transfer
ret = llt.transfer_video_stream(hLLT, video_type, 1, ct.byref(width), ct.byref(height))
if ret < 1:
    raise ValueError("Error starting transfer profiles: " + str(ret))

# Allocate profile buffer
profile_buffer = (ct.c_ubyte * (width.value * height.value))()

# Warm-up time
time.sleep(0.2)

ret = llt.get_actual_profile(hLLT, profile_buffer, len(profile_buffer), llt.TProfileConfig.VIDEO_IMAGE,
                           ct.byref(lost_profiles))
if ret != len(profile_buffer):
    raise ValueError("Error get profile buffer data: " + str(ret))

# Stop Video Stream
ret = llt.transfer_video_stream(hLLT, video_type, 0, null_ptr_int, null_ptr_int)
if ret < 1:
    raise ValueError("Error stopping transfer profiles: " + str(ret))

# Disconnect
ret = llt.disconnect(hLLT)
if ret < 1:
    raise ConnectionAbortedError("Error while disconnect: "  + str(ret))

# Disconnect
ret = llt.del_device(hLLT)
if ret < 1:
    raise ConnectionAbortedError("Error while delete: " + str(ret))

image = np.frombuffer(profile_buffer, dtype='uint8').reshape((height.value, width.value))
plt.figure()
plt.imshow(image, 'gray', origin='lower')
plt.show()