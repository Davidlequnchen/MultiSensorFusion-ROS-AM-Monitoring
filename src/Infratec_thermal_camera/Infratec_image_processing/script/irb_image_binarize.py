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
from infratec_image_processing.msg import MsgThreshold

class NdThermalImageBin():
    def __init__(self):
        rospy.init_node('thermal camera image binarize')

        image_topic = rospy.get_param('~thermal_image', '/infratec/image_raw')

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_thermal_image, queue_size=1)
        # rospy.Subscriber('/infratec/meltpool_threshold', MsgThreshold, self.cb_meltpool_threshold, queue_size=1)
        self.meltpool_threshold = 300
        # rospy.Subscriber('/infratec/HAZ_threshold', MsgThreshold, self.cb_HAZ_threshold, queue_size=1)
        # publisher 
        self.pub_bin_meltpool_image = rospy.Publisher('/infratec/image_meltpool_bin', Image, queue_size=10)
        self.pub_meltpool_size = rospy.Publisher('/infratec/meltpool_size', MsgROISize, queue_size=10)
        self.pub_HAZ_size = rospy.Publisher('/infratec/HAZ_size', MsgROISize, queue_size=10)


        self.bridge = CvBridge()
        self.msg_histogram = MsgHistogram()
        self.msg_meltpool_size = MsgROISize()
        self.msg_haz_size = MsgROISize()
        
        rospy.spin()

    def cb_HAZ_threshold(self, msg_haz_threshold):
        self.HAZ_threshold = msg_haz_threshold.threshold

    def cb_meltpool_threshold(self, msg_meltpool_threshold):
        self.meltpool_threshold = msg_meltpool_threshold.threshold
    
    def cb_thermal_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            # convert the ros image to OpenCV image for processing
            frame = self.bridge.imgmsg_to_cv2(msg_image) # right now it is 32FC1 type
            
            ret,thresh_img=cv2.threshold(frame,self.meltpool_threshold,255,cv2.THRESH_BINARY)
            self.msg_meltpool_size.pixels =  cv2.countNonZero(thresh_img)
            self.msg_meltpool_size.header.stamp = stamp
            self.pub_meltpool_size.publish(self.msg_meltpool_size)

            frame_uint = thresh_img.astype(np.uint8)    
            converted_msg = self.bridge.cv2_to_imgmsg(frame_uint, "mono8") # convert back to mono scale
            self.pub_bin_meltpool_image.publish(converted_msg)


            # cv2.namedWindow('binary', cv2.WINDOW_NORMAL)
            # cv2.imshow('binary',thresh_img)
            # k = cv2.waitKey(10)
            # if k == 27:         # wait for ESC key to exit
            #     cv2.destroyAllWindows()
            # elif k == ord('s'): # wait for 's' key to save and exit
            #     cv2.destroyAllWindows()



        except CvBridgeError as e:
            rospy.loginfo(e)

    def binarize(self, frame):
        img_bin = np.zeros(frame.shape, dtype=np.uint8)
        img_bin[frame > self.meltpool_threshold] = 255
        return img_bin


if __name__ == '__main__':
    try:
        NdThermalImageBin()
    except rospy.ROSInterruptException:
        pass
