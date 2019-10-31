#!/usr/bin/env python
import tf
import rospy
import numpy as np

from camera_measures.msg import MsgVelocity
from measures.velocity import Velocity


class NdVelocity():
    def __init__(self):
        rospy.init_node('velocity')

        self.velocity_pub = rospy.Publisher(
            '/velocity', MsgVelocity, queue_size=10)

        self.velocity = Velocity()
        self.msg_velocity = MsgVelocity()
        self.listener = tf.TransformListener()

        r = rospy.Rate(25)
        while not rospy.is_shutdown():
            self.pub_velocity()
            r.sleep()

    def pub_velocity(self):
        try:
            stamp = rospy.Time.now()
            self.listener.waitForTransform(
                "/world", "/tcp0", stamp, rospy.Duration(1.0))
            position, quaternion = self.listener.lookupTransform(
                "/world", "/tcp0", stamp)
            speed, velocity = self.velocity.instantaneous(
                stamp.to_sec(), np.array(position))
            self.msg_velocity.header.stamp = stamp
            self.msg_velocity.speed = speed
            self.msg_velocity.vx = velocity[0]
            self.msg_velocity.vy = velocity[1]
            self.msg_velocity.vz = velocity[2]
            self.velocity_pub.publish(self.msg_velocity)
        except (tf.Exception, tf.LookupException, tf.ConnectivityException,
                tf.ExtrapolationException):
            rospy.loginfo("TF Exception")


if __name__ == '__main__':
    try:
        NdVelocity()
    except rospy.ROSInterruptException:
        pass
