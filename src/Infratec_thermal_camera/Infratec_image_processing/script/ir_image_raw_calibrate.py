#!/usr/bin/env python
'''
This program calibrate the thermal images temperature readings
'''

import os
import cv2
import rospy
import rospkg
import numpy as np
import ros_numpy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


class NdThermalImage():
    def __init__(self):
        rospy.init_node('thermal camera temperature value calibration')

        image_topic = rospy.get_param('~thermal_image', '/infratec/image_raw')
        publish_image_topic = rospy.get_param('~thermal_image_calibrated', '/infratec/image_raw_calibrated')
        publish_crop_image_topic = rospy.get_param('~thermal_image_calibrated_cropped', '/infratec/image_raw_calibrated_cropped')
        self.epsilon_original = rospy.get_param('~epsilon_original',0.35 )
        self.epsilon_new = rospy.get_param('~epsilon_new', 0.4)

        ## set the thermal camera parameters------------------------------------------
        if rospy.has_param('/infratec_image_convert_mono'):
            self.set_thermal_camera_parameters(rospy.get_param('/infratec_image_convert_mono'))
        else:
            print ("thermal camera image parameter missing, load default")
            self.top_left_y = int(rospy.get_param('~top_left_y', '173'))
            self.height = int(rospy.get_param('~height', '69'))
            self.top_left_x = int(rospy.get_param('~top_left_x', '275'))
            self.width = int(rospy.get_param('~width', '75'))
        #-----------------------------------------------------------
        

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=5)
        self.bridge = CvBridge()
        self.pub_thermal_image_converted = rospy.Publisher(publish_image_topic, Image, queue_size=10)
        self.pub_thermal_image_converted_cropped = rospy.Publisher(publish_crop_image_topic, Image, queue_size=10)
        
        rospy.spin()
    
    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            frame = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type

            # convert image message to numpy
            # frame = ros_numpy.numpify(msg_image)
            # calibration
            # frame_calibrated = (np.power(frame, 4)*(self.epsilon_original/self.epsilon_new))**0.25
            frame_calibrated = ((frame**4)*(self.epsilon_original/self.epsilon_new))**0.25
            '''Crop the image'''
            frame_calibrated_cropped = frame_calibrated[self.top_left_y:self.top_left_y+self.height, self.top_left_x:self.top_left_x+self.width]

            publish_image_msg = self.bridge.cv2_to_imgmsg(frame_calibrated) 
            publish_image_cropp_msg = self.bridge.cv2_to_imgmsg(frame_calibrated_cropped) 
            self.pub_thermal_image_converted.publish(publish_image_msg)
            self.pub_thermal_image_converted_cropped.publish(publish_image_cropp_msg)


        except CvBridgeError as e:
            rospy.loginfo(e)

    def set_thermal_camera_parameters(self, params):
        self.top_left_y = int(params['top_left_y'])
        self.height = int(params['height'])
        self.top_left_x = int(params['top_left_x'])
        self.width = int(params['width'])

        


if __name__ == '__main__':
    try:
        NdThermalImage()
    except rospy.ROSInterruptException:
        pass
