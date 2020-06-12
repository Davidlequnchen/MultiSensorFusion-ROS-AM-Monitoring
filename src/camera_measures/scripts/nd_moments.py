#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from camera_measures.msg import MsgGeometry

from measures.moments import Moments
from measures.projection import Projection
from measures.geometry import Geometry

class NdMoments():
    def __init__(self):
        rospy.init_node('moments')

        image_topic = rospy.get_param('~image', '/usb_cam/image_raw')
        rospy.Subscriber(image_topic, Image, self.cb_image, queue_size=1)
        self.bridge = CvBridge()

        

        geo_topic = '/%s/moments' % image_topic.split('/')[1]
        self.pub_geo = rospy.Publisher(geo_topic, MsgGeometry, queue_size=10)
        self.msg_geo = MsgGeometry()

        threshold = rospy.get_param('~threshold', 127)
        path = rospkg.RosPack().get_path('camera_measures')
        '''
        config = rospy.get_param(
            '~config', os.path.join(path, 'config', 'tachyon.yaml'))
        '''
        
        # self.projection = Projection(config)

        self.geometry = Geometry(threshold)
        self.moments = Moments(threshold)

        rospy.spin()

    def cb_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            seconds = stamp.secs
            nseconds = stamp.nsecs
            # convert the ros image to OpenCV image for further processing
            frame = self.bridge.imgmsg_to_cv2(msg_image)
            if msg_image.encoding == 'rgb8':
                frame = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY) # convert into gray color
            center, axis, angle = self.moments.find_geometry(frame)


            # mask the frame into the circlular shape
            frame = self.geometry.mask(frame)

            frame = self.geometry.binarize(frame)


            ellipse = center, axis, angle 

            # draw the moments geometry on the frame 
            frame = self.geometry.draw_geometry(frame, ellipse)

            # cv2.namedWindow('moments', cv2.WINDOW_NORMAL)

            # cv2.imshow('moments',frame)

            # k = cv2.waitKey(10)
            # if k == 27:         # wait for ESC key to exit
            #     cv2.destroyAllWindows()
            # elif k == ord('s'): # wait for 's' key to save and exit
            #     cv2.destroyAllWindows()

            #if axis[1] > 0:
             #   center, axis, angle = self.projection.transform_ellipse(center, axis, angle)
            self.msg_geo.header.stamp = stamp
            self.msg_geo.header.stamp.secs = seconds
            self.msg_geo.header.stamp.nsecs = nseconds
            self.msg_geo.x = center[0]
            self.msg_geo.y = center[1]
            self.msg_geo.major_axis = axis[0]
            self.msg_geo.minor_axis = axis[1]
            self.msg_geo.orientation = angle
            self.pub_geo.publish(self.msg_geo)
        except CvBridgeError, e:
            rospy.loginfo("CvBridge Exception")


if __name__ == '__main__':
    try:
        NdMoments()
    except rospy.ROSInterruptException:
        pass
