#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg
import numpy as np

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
# from infratec_image_processing.msg import MsgHistogram
# from infratec_image_processing.msg import MsgROISize

class NdThermalImage():
    def __init__(self):
        rospy.init_node('thermal camera image conversion mono scale')

        image_topic = rospy.get_param('~thermal_image', '/infratec/image_raw')
        
        ## set the thermal camera parameters------------------------------------------
        if rospy.has_param('/infratec_image_convert_mono'):
            self.set_thermal_camera_parameters(rospy.get_param('/infratec_image_convert_mono'))
            pass
        else:
            print ("thermal camera image parameter missing, load default")
            self.max_temperature = float(rospy.get_param('~max_temp', '320'))
            self.min_temperature = float(rospy.get_param('~min_temp', '290'))
            self.top_left_y = int(rospy.get_param('~top_left_y', '100'))
            self.height = int(rospy.get_param('~height', '160'))
            self.top_left_x = int(rospy.get_param('~top_left_x', '350'))
            self.width = int(rospy.get_param('~width', '200'))
        #-----------------------------------------------------------


        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=1)
        self.bridge = CvBridge()
        # self.msg_histogram = MsgHistogram()

        # publisher 
        # self.pub_melt_pool = rospy.Publisher("/infratec/melt_pool", MsgMeltpool, queue_size=10)
        # self.pub_thermal_image_colour = rospy.Publisher('/infratec/image_colour', Image, queue_size=10)
        # self.pub_histogram = rospy.Publisher('/infratec/image_converted_mono/histogram', MsgHistogram, queue_size=10)
        self.pub_thermal_image_converted = rospy.Publisher('/infratec/image_converted_mono8', Image, queue_size=10)
        
        
        
        rospy.spin()
    
    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            frame = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type

            '''Crop the image'''
            frame = frame[self.top_left_y:self.top_left_y+self.height, self.top_left_x:self.top_left_x+self.width]

            '''convert the float number to usigned int8 (8-bits)'''
            frame = np.squeeze(frame)
            # frame_normalized = (frame-frame.min())/(frame.max()-frame.min())*256**2
            # frame_uint = (frame*25).astype(np.uint8)

            # frame_normalized = (frame-frame.min())/(frame.max()-frame.min())*256   # only do this for testing purpose
            frame_normalized = (frame-self.min_temperature)/(self.max_temperature-self.min_temperature)*256 # normalize temperature according to max, min
            frame_uint = frame_normalized.astype(np.uint8)    
            # frame_uint = frame.astype(np.uint8)
            converted_msg = self.bridge.cv2_to_imgmsg(frame_uint, "mono8") # convert back to mono scale
            self.pub_thermal_image_converted.publish(converted_msg)

            # calculate frequency of pixels in range 0-255
            # histg = cv2.calcHist([frame_uint],[0],None,[255],[0,255]) 
            # self.msg_histogram.header.stamp = stamp
            # self.msg_histogram.histogram = histg
            # self.pub_histogram.publish(self.msg_histogram)


        except CvBridgeError as e:
            rospy.loginfo(e)

    def set_thermal_camera_parameters(self, params):
        self.max_temperature = float(params['max_temp'])
        self.min_temperature = float(params['min_temp'])
        self.top_left_y = int(params['top_left_y'])
        self.height = int(params['height'])
        self.top_left_x = int(params['top_left_x'])
        self.width = int(params['width'])
        


if __name__ == '__main__':
    try:
        NdThermalImage()
    except rospy.ROSInterruptException:
        pass
