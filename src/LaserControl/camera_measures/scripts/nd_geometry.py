#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from camera_measures.msg import MsgGeometry

from measures.geometry import Geometry
from measures.projection import Projection

# config_file = "LaserControl.yaml"

# path = '../'

class NdGeometry():
    def __init__(self):
        rospy.init_node('geometry')

        image_topic = rospy.get_param('~image', '/usb_cam/image_raw')

        # subscribe the image topic and use callback function for further process
        rospy.Subscriber(image_topic, Image, self.cb_image, queue_size=1)
        self.bridge = CvBridge()

        geo_topic = '/%s/geometry' % image_topic.split('/')[1]

        # declare a publisher for Publishing the Geometry topic that contains info about minor axis.
        self.pub_geo = rospy.Publisher(geo_topic, MsgGeometry, queue_size=10) # the publisher will be used in callback function cb_image
        self.msg_geo = MsgGeometry()
        
        # set defult threshold value that distinguish balck and white
        threshold = rospy.get_param('~threshold', 127)
        # path = rospkg.RosPack().get_path('camera_measures')
        '''
        config = rospy.get_param(
            '~config', os.path.join(path, 'config', 'tachyon.yaml'))
        '''

        # declare a geometry and projection instance
        self.geometry = Geometry(threshold)
        # self.projection = Projection(config)

        rospy.spin()

    def save_configuration(self, filename):
        data = dict(minor_axis=self.msg_geo.minor_axis,
                    major_axis=self.msg_geo.major_axis,
                    x=self.msg_geo.x,
                    y=self.msg_geo.y,
                    orientation=self.msg_geo.orientation)
        with open(filename, 'w') as f:
            f.write(yaml.dump(data))
        return data

    def cb_image(self, msg_image):
        try:
            stamp = msg_image.header.stamp
            frame = self.bridge.imgmsg_to_cv2(msg_image) # convert the ros image to OpenCV image for processing
            if msg_image.encoding == 'rgb8':
                frame = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY) # convert the image into gray scale pixel value between (0, 255)
            
            # get the center, axis and angle by calling the funtion find_geomerty
            center, axis, angle = self.geometry.find_geometry(frame)

            

            # mask the frame into the circlular shape
            frame = self.geometry.mask(frame)

            frame = self.geometry.binarize(frame)

            
            
            ellipse = center, axis, angle 
            # draw the geometry on the frame 
            frame = self.geometry.draw_geometry(frame, ellipse)

            cv2.namedWindow('geometry', cv2.WINDOW_NORMAL)

            cv2.imshow('geometry',frame)

            k = cv2.waitKey(10)
            if k == 27:         # wait for ESC key to exit
                cv2.destroyAllWindows()
            elif k == ord('s'): # wait for 's' key to save and exit
                cv2.destroyAllWindows()

            # align the value into the same coordinate system
            # center, axis, angle = self.projection.transform_ellipse(center, axis, angle)

            self.msg_geo.header.stamp = stamp
            self.msg_geo.header.stamp.secs= stamp.secs
            self.msg_geo.x = center[0]
            self.msg_geo.y = center[1]
            self.msg_geo.major_axis = axis[0]
            self.msg_geo.minor_axis = axis[1]
            self.msg_geo.orientation = angle
            # publish the geometry message 
            self.pub_geo.publish(self.msg_geo)

            # self.save_configuration(os.path.join(path, 'config', 'LaserControl.yaml'))

        except CvBridgeError, e:
            rospy.loginfo("CvBridge Exception")


if __name__ == '__main__':
    try:
        NdGeometry()
    except rospy.ROSInterruptException:
        pass
