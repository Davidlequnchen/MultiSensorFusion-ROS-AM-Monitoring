#!/usr/bin/env python
import tf
import rospy
import numpy as np

from camera_measures.msg import MsgVelocity
from measures.velocity import Velocity
from camera_measures.msg import MsgPosition
from camera_measures.msg import MsgAcceleration
from camera_measures.msg import MsgTwist

class NdVelocity():
    def __init__(self):
        rospy.init_node('velocity')

        self.velocity_pub = rospy.Publisher(
            '/velocity', MsgVelocity, queue_size=10)
        
        self.position_pub = rospy.Publisher(
            '/position', MsgPosition, queue_size=10)
 
        self.twist_pub = rospy.Publisher(
            '/twist', MsgTwist, queue_size=10)
        
        self.acceleration_pub = rospy.Publisher(
            '/acceleration', MsgAcceleration, queue_size=10)
        
        self.twist_acceleration_pub = rospy.Publisher(
            '/twist_acceleration', MsgAcceleration, queue_size=10)

        self.velocity = Velocity()
        self.msg_velocity = MsgVelocity()
        self.msg_position = MsgPosition()
        self.msg_acceleration = MsgAcceleration()
        self.msg_twist_acceleration = MsgAcceleration()
        self.msg_twist = MsgTwist()
        self.listener = tf.TransformListener()
        
        self.twsit_speed = 0

        r = rospy.Rate(30)
        while not rospy.is_shutdown():
            self.pub_velocity()
            r.sleep()

    def pub_velocity(self):
        try:
            stamp = rospy.Time.now()
            self.listener.waitForTransform(
                "/tcp0", "/world", stamp, rospy.Duration(1.0))
            position, quaternion = self.listener.lookupTransform(
                "/tcp0", "/world", stamp)

            linear_velocity, angular_velocity = self.listener.lookupTwist(
                "/tcp0", "/world", stamp, rospy.Duration(0.1))
            
            # publishing the twist (linear velocity)
            self.twsit_speed = np.sqrt(linear_velocity[0] * linear_velocity[0] 
                                       + linear_velocity[1] * linear_velocity[1] 
                                       + linear_velocity[2] * linear_velocity[2] )
            self.msg_twist.header.stamp = stamp
            self.msg_twist.linear_x = linear_velocity[0]
            self.msg_twist.linear_y = linear_velocity[1]
            self.msg_twist.linear_z = linear_velocity[2]
            self.msg_twist.linear_speed = self.twsit_speed
            self.twist_pub.publish(self.msg_twist)
            
            
            # calculate the acceleration calculated by twist change
            twist_acceleration = self.velocity.twist_acceleration(
                stamp.to_sec(), self.twsit_speed)
            self.msg_twist_acceleration.header.stamp = stamp
            self.msg_twist_acceleration.acceleration = twist_acceleration
            self.twist_acceleration_pub.publish (self.msg_twist_acceleration)


            #position[0] = self.velocity.truncate(position[0], 2)
            #position[1] = self.velocity.truncate(position[1], 2)
            #position[2] = self.velocity.truncate(position[2], 2)
            self.msg_position.header.stamp = stamp
            self.msg_position.x = position[0]
            self.msg_position.y = position[1]
            self.msg_position.z = position[2]
            self.position_pub.publish(self.msg_position)
            '''
            After truncate, the position value will not change if the robot is not move,
            but it's not two decimals
            '''
            
            # calculate the velocity and speed using the position data
            speed, velocity = self.velocity.instantaneous(
                stamp.to_sec(), np.array(position))
            self.msg_velocity.header.stamp = stamp
            self.msg_velocity.speed = speed
            self.msg_velocity.vx = velocity[0]
            self.msg_velocity.vy = velocity[1]
            self.msg_velocity.vz = velocity[2]
            self.velocity_pub.publish(self.msg_velocity)
            
            # calculate the acceleration using the velocity data
            acceleration = self.velocity.acceleration(
                stamp.to_sec(), speed)
            self.msg_acceleration.header.stamp = stamp
            self.msg_acceleration.acceleration = acceleration
            self.acceleration_pub.publish (self.msg_acceleration)
            
            

        except (tf.Exception, tf.LookupException, tf.ConnectivityException,
                tf.ExtrapolationException):
            rospy.loginfo("TF Exception")


if __name__ == '__main__':
    try:
        NdVelocity()
    except rospy.ROSInterruptException:
        pass
