#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg
import numpy as np

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from infratec_image_processing.msg import MsgHistogram

class NdThermalImageConvertRGB():
    def __init__(self):
        rospy.init_node('thermal camera image conversion rgb scale')

        image_topic = rospy.get_param('~thermal_image', '/infratec/image_raw')

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=2)
        self.bridge = CvBridge()

        # publisher 
        # self.pub_melt_pool = rospy.Publisher("/infratec/melt_pool", MsgMeltpool, queue_size=10)
        self.pub_thermal_image_colour = rospy.Publisher('/infratec/image_converted_rgb', Image, queue_size=10)
        
        rospy.spin()
    
    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            frame = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type

            frame = np.squeeze(frame)
            frame_normalized = (frame-frame.min())/(frame.max()-frame.min())*256
            red_channel = (frame_normalized * 1).astype(np.uint8)
            green_channel = (frame_normalized * 0.4).astype(np.uint8)
            blue_channel = (frame_normalized * 0.4).astype(np.uint8)
            frame_colour = np.dstack((red_channel,green_channel,blue_channel)) 

            # frame = np.frombuffer(msg_image.data, dtype=np.uint8).reshape(msg_image.height, msg_image.width, -1)
            # frame_colour = cv2.cvtColor(frame_colour,cv2.COLOR_GRAY2RGB) # convert to colour scale

            converted_msg = self.bridge.cv2_to_imgmsg(frame_colour, "rgb8") # convert back to mono8 scale
            self.pub_thermal_image_colour.publish(converted_msg)



        except CvBridgeError as e:
            rospy.loginfo(e)


if __name__ == '__main__':
    try:
        NdThermalImageConvertRGB()
    except rospy.ROSInterruptException:
        pass
