#!/usr/bin/env python
import os
import tf
import cv2
import rospy
import numpy as np
import sensor_msgs.msg
# from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

from robscan.profile import Profile
from icv.calibration import CameraCalibration
from icv.calibration import LaserCalibration
from icv.calibration import HandEyeCalibration

import rospkg

rospack = rospkg.RosPack()
path = rospack.get_path('calib_ros_run')


"""
The functionality of this node:
1. subscribed topics: sensor_msgs/Image     /usb_cam/image_raw
2. callback function in rospy.Subscriber: 
    - Converting ROS image messages to OpenCV images, called frame (cv_bridge method)
    - convert inage to gray scale
    - Show chessboard and line detection 
3. SetMouseCallback:
when right click the mouse, the program will do 
- save the image into the folder "data", and call it frame..png
- In the real program, (we ignore this part as we don't record the physical robot at the moment):
it will also record the pose of the camera w.r.t. the robot linkages (baselink) frame
using tf transform library(data/pose.txt). Thus, it record the image and camera positionan the same time.
4. on_shutdown:
 -destroy windows
 TODO in calib.py (optional here)-------------------------------------------------------------------------------------------
 - Fix changes in the Calibration module:
   - find_calibration_3d(image): - get the camera parameters(cam_mat,distor_coeff..)-- CalibrateCamera
                                 - get chessboard 3D pose coordinate
                                 - In each image, get the laser line 3D coordinate corresponding to the chessboard plane, using homographic projection method
                                 - find_best_line2d
                                 - find_best_plane, find the lase plane 3D coordinate
   - save parameter (homographic transformation matrix, rotational and translation matrix, etc) into config/profile3d.yaml. 
"""


class ImageViewer():
    def __init__(self):
        rospy.init_node('Imviewer', anonymous=True)
       

        image_topic = rospy.get_param('~image', '/usb_cam/image_rect')
        # Pattern parameters
        pattern_rows = rospy.get_param('~pattern_rows', 8)
        pattern_cols = rospy.get_param('~pattern_cols', 5)
        pattern_size = rospy.get_param('~pattern_size', 0.01089) #10.89 cm^2, 33mm for side

        self.config_file = rospy.get_param('~config', 'profile3d.yaml')

        # cv2.namedWindow('viewer')
        rospy.Subscriber(image_topic, sensor_msgs.msg.Image, self.callback, queue_size=10)
        # cv2.setMouseCallback('viewer', self.on_mouse)
        rospy.on_shutdown(self.on_shutdown_hook)

        self.counter = 0
        self.bridge = CvBridge()
        # listen to tf transform, receive tf topic published by the robot state publisher
        self.listener = tf.TransformListener()

        self.square_size = pattern_size
        self.grid_size = (pattern_cols-1, pattern_rows-1)

        self.laser_profile = Profile(axis=1, thr=180, method='pcog')
        self.camera_calibration = CameraCalibration(grid_size=self.grid_size, square_size=self.square_size)

        
        # cv2.namedWindow('viewer')
        # cv2.setMouseCallback('viewer', self.on_mouse)
        
        
        rospy.spin()

    def on_shutdown_hook(self):
        cv2.destroyWindow('viewer')
        #TODO: Fix changes in the Calibration module.
        calibration = LaserCalibration(grid_size=self.grid_size, square_size=self.square_size, profile=self.laser_profile)
        print os.path.join(path, 'data', 'frame*.png')
        calibration.find_calibration_3d(os.path.join(path, 'data', 'frame*.png'))
        calibration.save_parameters(os.path.join(path, 'config', self.config_file))

    def on_mouse(self, event, x, y, flags, params):
        if event == cv2.EVENT_RBUTTONDOWN:
            self.counter += 1
            filename = os.path.join(path, 'data', 'frame%04i.png' %self.counter)
            
            cv2.imwrite(filename, self.frame)
            rospy.loginfo(filename)
            
            '''
            record the tf transform data between base link and tool0, for hand eye calibration
            '''
            try:
                #listen to transform between base_link and tool0(the transformation matrix)
                self.listener.waitForTransform("/base_link", "/tool0", self.stamp, rospy.Duration(1.0))
                transform = self.listener.lookupTransform("/base_link", "/tool0", self.stamp) #(trans, rot)
                filename = os.path.join(path, 'data', 'pose%04i.txt' %self.counter)
                with open(filename, 'w') as f:
                    f.write(str(transform))
                rospy.loginfo(transform)
            except:
                rospy.loginfo('The transformation is not accesible.') 


    def callback(self, data):
        try:
            self.stamp = data.header.stamp
            # Converting ROS image messages to OpenCV images
            self.frame = self.bridge.imgmsg_to_cv2(data)
            #TODO: Change to work with gray images
            if data.encoding == 'mono8':
                self.frame = cv2.cvtColor(self.frame, cv2.COLOR_GRAY2BGR)
            # self.frame = cv2.cvtColor(self.frame, cv2.COLOR_GRAY2BGR)
            #TODO: Show chessboard and line detection.
            frame = cv2.resize(self.frame, (self.frame.shape[1]/2, self.frame.shape[0]/2))
            grid = self.camera_calibration.find_chessboard(frame)
            if grid is not None:
                self.camera_calibration.draw_chessboard(frame, grid)
            gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            
            cv2.namedWindow('viewer')
            cv2.imshow('viewer', gray)
            cv2.setMouseCallback('viewer', self.on_mouse)
            cv2.waitKey(10)
           
        except CvBridgeError, e:
            print e



if __name__ == '__main__':
    ImageViewer()
