#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg
import numpy as np
import ros_numpy
from scipy.stats import skew
import scipy.stats as stats
from scipy.stats import kurtosis

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from infratec_image_processing.msg import TemperatureFeature


class NdThermalFeature():
    def __init__(self):
        rospy.init_node('extract temperature distrubution features from raw IR thermal images')
        image_topic = rospy.get_param('~thermal_image', '/infratec/image_raw_calibrated_cropped')

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=3)
        self.bridge = CvBridge()

        # publisher 
        self.pub_temperature_feature = rospy.Publisher('/infratec/temperature_feature', TemperatureFeature, queue_size = 10)
        
        rospy.spin()
    

    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            msg_temperature_feature = TemperatureFeature()
            msg_temperature_feature.header.stamp = stamp
            # convert image message to numpy
            np_img = ros_numpy.numpify(msg_image)
            # convert the ros image to OpenCV image for processing
            # cv_img = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type
            msg_temperature_feature.highest = np.max(np_img)
            msg_temperature_feature.mean = np.mean(np_img)
            msg_temperature_feature.lowest = np.min(np_img)
            msg_temperature_feature.variance = np.var(np_img)
            msg_temperature_feature.skewness = skew(np_img.flatten())
            msg_temperature_feature.kurtosis = kurtosis(np_img.flatten(), fisher=True)

            self.pub_temperature_feature.publish(msg_temperature_feature)


        except CvBridgeError as e:
            rospy.loginfo(e)



if __name__ == '__main__':
    try:
        NdThermalFeature()
    except rospy.ROSInterruptException:
        pass
