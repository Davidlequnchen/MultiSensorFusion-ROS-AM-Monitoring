#!/usr/bin/env python
import os
import cv2
import rospy
import rospkg
import numpy as np

from sensor_msgs.msg import Image

from mashes_measures.msg import MsgStatus
from mashes_measures.msg import MsgVelocity

from cv_bridge import CvBridge, CvBridgeError

from measures.coolrate import CoolRate
from measures.projection import Projection


class NdCoolRate():
    def __init__(self):
        rospy.init_node('coolrate')

        self.start = False
        self.laser_on = False

        path = rospkg.RosPack().get_path('mashes_measures')
        self.p_NIT = Projection()
        self.p_NIT.load_configuration(
            os.path.join(path, 'config/NIT_config.yaml'))

        image_topic = rospy.get_param('~image', '/tachyon/image')
        rospy.Subscriber(image_topic, Image, self.cb_image, queue_size=1)
        self.bridge = CvBridge()

        rospy.Subscriber(
            'velocity', MsgVelocity, self.cb_velocity, queue_size=1)
        rospy.Subscriber(
            '/supervisor/status', MsgStatus, self.cb_status, queue_size=1)

        self.coolrate = CoolRate()

        rospy.spin()

    def cb_image(self, msg_image):
        try:
            frame = self.bridge.imgmsg_to_cv2(msg_image)
            if msg_image.encoding == 'rgb8':
                frame = cv2.cvtColor(frame, cv2.COLOR_RGB2GRAY)
            self.image = self.p_NIT.project_image(frame, self.p_NIT.hom_vis)
            if not self.start:
                self.start = True
        except CvBridgeError, e:
            print e

    def cb_status(self, msg_status):
        if msg_status.laser_on:
            self.laser_on = True
        else:
            self.laser_on = False

    def cb_velocity(self, msg_velocity):
        stamp = msg_velocity.header.stamp
        vel = np.float32([msg_velocity.vx * 1000,
                          msg_velocity.vy * 1000,
                          msg_velocity.vz * 1000])
        if self.start and self.laser_on:
            self.coolrate.instantaneous(stamp.to_sec(), vel)
            gradient_values = []
            for u in range(250, 251):
                for v in range(250, 251):
                    pxl = np.float32([[u, v]])
                    pxl_2 = self.p_NIT.transform(self.p_NIT.inv_hom_vis, pxl)
                    pos = self.p_NIT.transform(self.p_NIT.inv_hom, pxl_2)
                    gradient = self.get_gradient(vel, stamp, pos)
                    print "gradient:", gradient
                    if gradient is not None:
                        gradient_values.append(self.convert_value(gradient))
            print "Gradient:", gradient_values

    def convert_value(self, gradient, inf_limit=-1200, sup_limit=1200):
        dp = 255.0/(sup_limit-inf_limit)
        grad = (gradient + 1200) * dp
        return grad

    def get_gradient(self, vel, stamp, pos=np.float32([[0, 0]])):
        position_0 = np.float32([[pos[0][0], pos[0][1], 0]])
        # cv2.imshow("Image final", self.image)
        # cv2.waitKey(1)
        frame_1 = self.image
        position_1 = self.coolrate.position(position_0)
        if position_1 is not None:
            #get value of the pixel in:
                #frame_1: position_1
            pxl_position_0 = self.p_NIT.transform(self.p_NIT.hom, position_0)
            pxl_position_0_vis = self.p_NIT.transform(
                self.p_NIT.hom_vis, pxl_position_0)
            intensity_0 = self.get_value_pixel(
                self.frame_0, pxl_position_0_vis[0])
                #frame_0: position_0
            pxl_position_1 = self.p_NIT.transform(self.p_NIT.hom, position_1)
            pxl_position_1_vis = self.p_NIT.transform(
                self.p_NIT.hom_vis, pxl_position_1)
            intensity_1 = self.get_value_pixel(frame_1, pxl_position_1_vis[0])

            gradient = (intensity_1 - intensity_0)/self.coolrate.dt
            self.frame_0 = frame_1
            return gradient

        else:
            self.frame_0 = frame_1
            return None

    def get_value_pixel(self, frame, pxl, rng=3):
        intensity = 0
        limits = (rng - 1)/2
        for i in range(-limits, limits+1):
            for j in range(-limits, limits+1):
                index_i = pxl[0] + i
                index_j = pxl[1] + j
                intensity = intensity + frame[index_i, index_j]
        intensity = intensity/(rng*rng)
        return intensity


if __name__ == '__main__':
    try:
        NdCoolRate()
    except rospy.ROSInterruptException:
        pass
