#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg
import numpy as np

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from infratec_image_processing.msg import MsgHistogram
from infratec_image_processing.msg import MsgROISize

class NdThermalImage():
    def __init__(self):
        rospy.init_node('thermal camera image conversion mono scale')

        image_topic = rospy.get_param('~thermal_image', '/infratec/image_raw')
        self.temperature_threshold_1 = rospy.get_param('~temperature_threshold_1', '600') # solid-liquid transition temperature
        self.temperature_threshold_2 = rospy.get_param('~temperature_threshold_2', '1000') # liquid metal
        self.temperature_threshold_3 = rospy.get_param('~temperature_threshold_3', '1300') # heat affected zone
        self.max_temp = rospy.get_param('~max_temp', '1800') # Maximum temperature in the scale bar
        self.min_temp = rospy.get_param('~min_temp', '0') # Minimum temperature in the scale bar
        

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=1)
        self.bridge = CvBridge()

        # publisher
        self.pub_thermal_image_converted = rospy.Publisher('/infratec/image_converted_mono_distribution', Image, queue_size=10)
        
        rospy.spin()
    
    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            frame = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type

            '''convert the float number to usigned int8 (8-bits)'''
            frame = np.squeeze(frame)
   
            # frame_normalized = (frame-frame.min())/(frame.max()-frame.min())*256

            # frame = (frame-self.temperature_threshold_1)/(self.max_temp-self.temperature_threshold_1)*256
            frame = (frame-self.temperature_threshold_1)/(500)*256*2
            # frame[frame<self.temperature_threshold_1] = frame1
            # frame_normalized = (frame-self.temperature_threshold_1)/(self.temperature_threshold_2-self.temperature_threshold_1)*256
            # frame_uint = frame_normalized.astype(np.uint8)    
            frame_uint = frame.astype(np.uint8)
            converted_msg = self.bridge.cv2_to_imgmsg(frame_uint, "mono8") # convert back to mono scale
            self.pub_thermal_image_converted.publish(converted_msg)


        except CvBridgeError as e:
            rospy.loginfo(e)



if __name__ == '__main__':
    try:
        NdThermalImage()
    except rospy.ROSInterruptException:
        pass
