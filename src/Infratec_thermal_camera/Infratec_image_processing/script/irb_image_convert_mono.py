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

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=1)
        self.bridge = CvBridge()
        self.msg_histogram = MsgHistogram()

        # publisher 
        # self.pub_melt_pool = rospy.Publisher("/infratec/melt_pool", MsgMeltpool, queue_size=10)
        # self.pub_thermal_image_colour = rospy.Publisher('/infratec/image_colour', Image, queue_size=10)
        self.pub_histogram = rospy.Publisher('/infratec/image_converted_mono/histogram', MsgHistogram, queue_size=10)
        self.pub_thermal_image_converted = rospy.Publisher('/infratec/image_converted_mono', Image, queue_size=10)
        self.pub_bin_image = rospy.Publisher('/infratec/image_bin', Image, queue_size=10)
        
        rospy.spin()
    
    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            frame = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type

            '''convert the float number to usigned int8 (8-bits)'''
            frame = np.squeeze(frame)
            # frame_normalized = (frame-frame.min())/(frame.max()-frame.min())*256**2
            # frame_uint = (frame*25).astype(np.uint8)
            frame_normalized = (frame-frame.min())/(frame.max()-frame.min())*256
            frame_uint = frame_normalized.astype(np.uint8)    
            converted_msg = self.bridge.cv2_to_imgmsg(frame_uint, "mono8") # convert back to mono scale
            self.pub_thermal_image_converted.publish(converted_msg)

            # calculate frequency of pixels in range 0-255
            histg = cv2.calcHist([frame_uint],[0],None,[255],[0,255]) 
            self.msg_histogram.header.stamp = stamp
            self.msg_histogram.histogram = histg
            self.pub_histogram.publish(self.msg_histogram)



        except CvBridgeError as e:
            rospy.loginfo(e)

    def binarize(self, frame):
        img_bin = np.zeros(frame.shape, dtype=np.uint8)
        img_bin[frame > self.threshold] = 255
        return img_bin


if __name__ == '__main__':
    try:
        NdThermalImage()
    except rospy.ROSInterruptException:
        pass
