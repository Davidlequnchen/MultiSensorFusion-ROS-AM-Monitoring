#!/usr/bin/env python
import os
import rospy
import rospkg
import numpy as np

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

from mashes_measures.msg import MsgGeometry
from mashes_measures.msg import MsgVelocity

from measures.registration import Registration


class NdRegistration():
    def __init__(self):
        rospy.init_node('registration')

        self.bridge = CvBridge()

        path = rospkg.RosPack().get_path('mashes_measures')
        self.registration = Registration()
        self.registration.p_camera.load_configuration(
            os.path.join(path, 'config', 'camera.yaml'))
        self.registration.p_tachyon.load_configuration(
            os.path.join(path, 'config', 'tachyon.yaml'))

        rospy.Subscriber('/tachyon/image', Image,
                         self.cb_image_tachyon, queue_size=1)
        rospy.Subscriber('/camera/image', Image,
                         self.cb_image_camera, queue_size=1)
        rospy.Subscriber('/tachyon/geometry', MsgGeometry,
                         self.cb_geometry_tachyon, queue_size=1)
        rospy.Subscriber('/velocity', MsgVelocity,
                         self.cb_velocity, queue_size=1)

        self.pub_image = rospy.Publisher(
            '/measures/image', Image, queue_size=10)

        r = rospy.Rate(10)  # 10hz
        while not rospy.is_shutdown():
            image = self.registration.paint_images()
            self.pub_image.publish(self.bridge.cv2_to_imgmsg(image, "bgr8"))
            r.sleep()

    def cb_image_tachyon(self, msg_image):
        try:
            self.stamp = msg_image.header.stamp
            self.registration.img_tachyon = self.bridge.imgmsg_to_cv2(msg_image)
        except CvBridgeError, e:
            rospy.loginfo("CvBridge Exception")

    def cb_image_camera(self, msg_image):
        try:
            self.stamp1 = msg_image.header.stamp
            image = self.bridge.imgmsg_to_cv2(msg_image)
            if msg_image.encoding == 'mono16':
                self.registration.img_camera = np.uint8(image>>4)
        except CvBridgeError, e:
            rospy.loginfo("CvBridge Exception")

    def cb_geometry_tachyon(self, msg_geometry):
        self.registration.ellipse = (
            (msg_geometry.x, msg_geometry.y),
            (msg_geometry.major_axis, msg_geometry.minor_axis),
            msg_geometry.orientation)

    def cb_velocity(self, msg_velocity):
        # velocity/speed in mm/s
        self.registration.speed = msg_velocity.speed * 1000
        self.registration.velocity = (msg_velocity.vx * 1000,
                                      msg_velocity.vy * 1000,
                                      msg_velocity.vz * 1000)


if __name__ == '__main__':
    try:
        NdRegistration()
    except rospy.ROSInterruptException:
        pass
