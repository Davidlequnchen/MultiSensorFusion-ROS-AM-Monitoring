#!/usr/bin/env python
import time
import ctypes as ct
import numpy as np
from matplotlib import pyplot as plt
import pylinllt as llt

import os
import tf
import cv2
import rospy
import numpy as np
import sensor_msgs.msg
# from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

from robscan.profile import Profile
from calib.calibration import CameraCalibration
from calib.calibration import LaserCalibration
from calib.calibration import HandEyeCalibration

import rospkg

rospack = rospkg.RosPack()
path = rospack.get_path('microepsilon_calibration')

'''
This node subscribe microepsilon raw camera image 'microepsilon/image_raw'
This is the node to record robot position and picture when right click the image
the data will be saved into the data folder for further hand-eye calibration.
after running this node, you should click around ten times before you proceed to 
run the runcalib.py to perform hand-eye calibation

'''





class ImageViewer():
    def __init__(self):
        rospy.init_node('position recorder', anonymous=True)

        image_topic = rospy.get_param('~image', 'microepsilon/image_raw')
        # Pattern parameters, need to change accordingly with the actual chessboard
        pattern_rows = rospy.get_param('~pattern_rows', 8)
        pattern_cols = rospy.get_param('~pattern_cols', 5)
        pattern_size = rospy.get_param('~pattern_size', 0.01089) #10.89 cm^2, 33mm for side

        self.config_file = rospy.get_param('~config', 'profile3d.yaml')

        rospy.Subscriber(image_topic, sensor_msgs.msg.Image, self.callback, queue_size=10)
        
        # shut down condition
        rospy.on_shutdown(self.on_shutdown_hook)

        self.counter = 0
        self.bridge = CvBridge()
        # listen to tf transform, receive tf topic published by the robot state publisher
        self.listener = tf.TransformListener()

        self.square_size = pattern_size
        self.grid_size = (pattern_cols-1, pattern_rows-1)
 
        # initialize a camera calibration object
        self.laser_profile = Profile(axis=1, thr=180, method='pcog')
        self.camera_calibration = CameraCalibration(grid_size=self.grid_size, square_size=self.square_size)


        rospy.spin()


    def on_shutdown_hook(self):
        cv2.destroyWindow('viewer')
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
                #listen to transform between base_link and tool0( return the transformation matrix)
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
            # Change to work with gray images
            if data.encoding == 'mono8':
                self.frame = cv2.cvtColor(self.frame, cv2.COLOR_GRAY2BGR)
            # self.frame = cv2.cvtColor(self.frame, cv2.COLOR_GRAY2BGR)
            # Show chessboard and line detection.
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
