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

import ctypes as ct
import time
import matplotlib.animation as animation
import numpy as np
from scipy.optimize import leastsq
from matplotlib import pyplot as plt
import matplotlib.patches as patches
import pylinllt as llt

def calc_radius(x, y, xc, yc):
    """ calculate the distance of each 2D points from the center (xc, yc) """
    return np.sqrt((x-xc)**2 + (y-yc)**2)


def f(c, x, y):
    """ calculate the algebraic distance between the data points and the mean circle centered at c=(xc, yc) """
    r_i = calc_radius(x, y, *c)
    return r_i - r_i.mean()


def leastsq_circle(x,y):
    ''' approximates center coo and radius of a circle '''
    # coordinates of the barycenter
    x_m = np.mean(x)
    y_m = np.mean(y)
    center_estimate = x_m, y_m
    center, ier = leastsq(f, center_estimate, args=(x,y))
    xc, yc = center
    r_i = calc_radius(x, y, *center)
    r = r_i.mean()
    residuals = np.sum((r_i - r)**2)
    return xc, yc, r, residuals

# Init circle fit data
xc, zc, r, residuals = 0, 0, 0, 0

# Circle ROI ---- Important: make sure there are valid points in the ROI
upper_z_limit = 90.0
lower_z_limit = 85.0
upper_x_limit = 15.0
lower_x_limit = -15.0

# Parametrize transmission
start_data = 0
data_width = 8
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

# Declare measuring data array
x = np.empty(resolution, dtype=float) # (ct.c_double * resolution)()
z = np.empty(resolution, dtype=float) # (ct.c_double * resolution)()
x_p = x.ctypes.data_as(ct.POINTER(ct.c_double))
z_p = z.ctypes.data_as(ct.POINTER(ct.c_double))
threshold = (ct.c_ushort * resolution)()
intensities = (ct.c_ushort * resolution)()
width = (ct.c_ushort * resolution)()
# mom0 = (ct.c_uint * resolution)()
# mom1 = (ct.c_uint * resolution)()

# Null pointer if data not necessary
null_ptr_short = ct.POINTER(ct.c_ushort)()
null_ptr_int = ct.POINTER(ct.c_uint)()

# Create instance and set IP address
hLLT = llt.create_llt_device()

# Get available interfaces
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


ret = llt.get_resolutions(hLLT, available_resolutions, len(available_resolutions))
if ret < 1:
    raise ValueError("Error getting resolutions : " + str(ret))

# Set max. resolution
resolution = available_resolutions[0]
ret = llt.set_resolution(hLLT, resolution)
if ret < 1:
    raise ValueError("Error getting resolutions : " + str(ret))

# Declare measuring data array
profile_buffer = (ct.c_ubyte*(resolution*data_width))()
x = np.empty(resolution, dtype=float) # (ct.c_double * resolution)()
z = np.empty(resolution, dtype=float) # (ct.c_double * resolution)()
x_p = x.ctypes.data_as(ct.POINTER(ct.c_double))
z_p = z.ctypes.data_as(ct.POINTER(ct.c_double))
threshold = (ct.c_ushort * resolution)()
intensities = (ct.c_ushort * resolution)()
width = (ct.c_ushort * resolution)()
# mom0 = (ct.c_uint * resolution)()
# mom1 = (ct.c_uint * resolution)()

# Partial profile struct
partial_profile_struct = llt.TPartialProfile(0, start_data, resolution, data_width)

# Scanner type
ret = llt.get_llt_type(hLLT, ct.byref(scanner_type))
if ret < 1:
    raise ValueError("Error scanner type: " + str(ret))

# Set partial profile to profile config
ret = llt.set_profile_config(hLLT, llt.TProfileConfig.PARTIAL_PROFILE)
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

# Set partial profile
ret = llt.set_partial_profile(hLLT, ct.byref(partial_profile_struct))
if ret < 1:
    raise ValueError("Error setting partial profile: " + str(ret))

# Start transfer
ret = llt.transfer_profiles(hLLT, llt.TTransferProfileType.NORMAL_TRANSFER, 1)
if ret < 1:
    raise ValueError("Error starting transfer profiles: " + str(ret))

# Warm-up time
time.sleep(0.2)

# Init animation plot
fig, ax = plt.subplots(facecolor='white')
line1, = ax.plot([], [], 'b-', label="fitted circle", lw=2)
line2, = ax.plot([], [], 'bD', mec='y', mew=1)
line3, = ax.plot([], [], 'g.', label="data", mew=1)
ax.grid()
ax.set_xlim(-60, 60)
ax.set_ylim(55, 125)
ax.add_patch(
    patches.Rectangle(
        (lower_x_limit, lower_z_limit),  # (x,y)
        upper_x_limit - lower_x_limit,  # width
        upper_z_limit - lower_z_limit,  # height
        edgecolor="#0000ff",
        facecolor="#0000ee",
        alpha = 0.1
    )
)


def data_gen(*args):
    fret = llt.get_actual_profile(hLLT, profile_buffer, len(profile_buffer), llt.TProfileConfig.PARTIAL_PROFILE,
                               ct.byref(lost_profiles))
    if fret != len(profile_buffer):
        print("Error get profile buffer data: " + str(ret))

    fret = llt.convert_part_profile_2_values(profile_buffer, len(profile_buffer), ct.byref(partial_profile_struct), scanner_type, 0,
                                         null_ptr_short, null_ptr_short, null_ptr_short, x_p, z_p, null_ptr_int, null_ptr_int)
    if fret & llt.CONVERT_X is 0 or fret & llt.CONVERT_Z is 0:
        raise ValueError("Error converting data: " + str(ret))

    for i in range(16):
        timestamp[i] = profile_buffer[resolution * data_width - 16 + i]

    llt.timestamp_2_time_and_count(timestamp, ct.byref(shutter_opened), ct.byref(shutter_closed), ct.byref(profile_count), null_ptr_short)

    # Adjust ROI to area with circle
    x_roi = x[(x > lower_x_limit) & (x < upper_x_limit) & (z > lower_z_limit) & (z < upper_z_limit)]
    z_roi = z[(x > lower_x_limit) & (x < upper_x_limit) & (z > lower_z_limit) & (z < upper_z_limit)]

    # Fitting
    xc, zc, r, residuals = leastsq_circle(x_roi, z_roi)
    theta_fit = np.linspace(-np.pi, np.pi, 90)

    print("Radius[mm]:\t\t",round(r, 3))
    print("Center(x|z)[mm]:\t",round(xc, 3), "|", round(zc, 3))
    print("Residual:\t\t", round(residuals, 3),"\n")

    # Prepare draw data
    x_fit = xc + r*np.cos(theta_fit)
    z_fit = zc + r*np.sin(theta_fit)

    time.sleep(0.1)

    # yield iterator
    yield x, z, xc, zc, x_fit, z_fit


# data update for animation func
def update(data):
    x_roi, z_roi, xc, zc, x_fit, z_fit = data
    line1.set_data(x_fit, z_fit)
    line2.set_data([xc], [zc])
    line3.set_data(x, z)
    return line1, line2, line3,

# animation setup
ani = animation.FuncAnimation(fig, update, frames=data_gen, interval=250)
plt.show()

# Stop transmission
ret = llt.transfer_profiles(hLLT, llt.TTransferProfileType.NORMAL_TRANSFER, 0)
if ret < 1:
    raise ValueError("Error stopping transfer profiles: " + str(ret))

# Disconnect
ret = llt.disconnect(hLLT)
if ret < 1:
    raise ConnectionAbortedError("Error while disconnect: "  + str(ret))

# Delete
ret = llt.del_device(hLLT)
if ret < 1:
    raise ConnectionAbortedError("Error while delete: "  + str(ret))