import os
import glob
import numpy as np
# import cupy

from robscan.profile import Profile
from calib.calibration import CameraCalibration
from calib.calibration import LaserCalibration
from calib.calibration import HandEyeCalibration

from calib.image import *
import calib.calculate as calc
from calib.calibration import read_calibration_data


np.set_printoptions(precision=4, suppress=True)


path = '../'
# should change accordingly with the actual size of the chessboard
pattern_rows = 8
pattern_cols = 5
pattern_size = 0.033 #33mm for side
# config_file = 'runprofile3d.yaml'
# camera_file = 'runcamera.yaml'
"""
In this section, the previous saved pictures by positon recorder will be read,
It will perform hand eye calibration based on pos.txt(transformatin matrix betweem world to tool0)
and also each pictures (frame.txt), 
"""

dirname = '../data'
# images, tool_poses = read_calibration_data(dirname)
images = read_calibration_data(dirname)  # read the frame.png files one by one (sorted order) and do not consider about camera pose here. the pose is used for Hand eye calibration

# change the format of the image to solve the src is not a numpy array, neither a scalar problem

square_size = pattern_size
grid_size = (pattern_cols-1, pattern_rows-1)

# initialize a camera_calibration and laser_calibration object
laser_profile = Profile(axis=1, thr=180, method='pcog')
camera_calibration = CameraCalibration(grid_size=grid_size,
                                       square_size=square_size)
laser_calibration = LaserCalibration(grid_size=grid_size,
                                     square_size=square_size,
                                     profile=laser_profile)

# laser calibration and camera calibration process                             
# laser_calibration.find_calibration_3d(images) # no need to run laser calibration here
# laser_calibration.save_camera_parameters(os.path.join(path, 'config',camera_file))
# laser_calibration.save_parameters(os.path.join(path, 'config', config_file))


for image in images:
    show_images([image])



# for the pose of the camera in robot coordinate system (Hand-eye calibration)

filenames = sorted(glob.glob('../data/pose*.txt'))
ks = [int(filename[-8:-4]) for filename in filenames]
poses_checker, poses_tool = [], []
poses_ichecker, poses_itool = [], []
for k in ks:
    print ('Frame: %i' % k)
    img = read_image('../data/frame%04i.png' % k)
    # find chessboard corners
    grid = camera_calibration.find_chessboard(img)
    pose_checker = None
    if grid is not None:
        # Gets the estimated pose for the calibration chessboard
        pose_checker = laser_calibration.get_chessboard_pose(grid)

        # get homogeneous transformation matrix from the pose (R, t)
        pose_checker = calc.pose_to_matrix((pose_checker[0], pose_checker[1]))

        img = camera_calibration.draw_chessboard(img, grid)
    show_images([img])

    with open('../data/pose%04i.txt' % k, 'r') as f:
        pose = eval(f.read())

        # read the pose for tool0, rotation(quaternion) and translation
        quatpose_tool0 = (np.array(pose[0]), np.array(pose[1]))

        # convert the quaternion to rotation matrix
        pose_tool0 = calc.quatpose_to_matrix(*quatpose_tool0)

    if pose_checker is not None:
        poses_checker.append(pose_checker)
        poses_tool.append(pose_tool0)
        # Returns the inverted transformation matrix
        poses_ichecker.append(calc.matrix_invert(pose_checker))
        poses_itool.append(calc.matrix_invert(pose_tool0))
print ('Poses:', len(poses_checker), len(poses_tool))

print ('Hand Eye Calibration Solution')

#perform the hand eye calibration
tlc = HandEyeCalibration()
# tool0 to camera transformation
T2C = tlc.solve(poses_tool, poses_checker)
W2K = tlc.solve(poses_itool, poses_ichecker)
print ('t2c>', T2C, calc.matrix_to_rpypose(T2C))
# from work object to tool 0
print ('w2k>', W2K, calc.matrix_to_rpypose(W2K))

