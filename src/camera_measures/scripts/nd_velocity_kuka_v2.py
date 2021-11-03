#!/usr/bin/env python
import tf
import rospy
import numpy as np

from camera_measures.msg import MsgVelocity
from measures.velocity import Velocity
from camera_measures.msg import MsgPosition
from camera_measures.msg import MsgAcceleration
from camera_measures.msg import MsgTwist
from simtech_kuka_rsi_hw_interface.msg import MsgCartPosition

class NdVelocity():
    def __init__(self):
        rospy.init_node('kuka_velocity')


        # subscribe the cartesian coordinate of the tcp
        rospy.Subscriber("/cartesian_position", MsgCartPosition, self.cb_position, queue_size=10)

        # self.velocity_pub = rospy.Publisher(
        #     '/velocity', MsgVelocity, queue_size=10)
        
        self.position_pub = rospy.Publisher(
            '/position', MsgPosition, queue_size=10)
 
        # self.twist_pub = rospy.Publisher(
        #     '/twist', MsgTwist, queue_size=10)
        
        # self.acceleration_pub = rospy.Publisher(
        #     '/acceleration', MsgAcceleration, queue_size=10)
        
        # self.twist_acceleration_pub = rospy.Publisher(
        #     '/twist_acceleration', MsgAcceleration, queue_size=10)

        self.velocity = Velocity()
        self.msg_velocity = MsgVelocity()
        self.msg_position = MsgPosition()
        self.msg_acceleration = MsgAcceleration()
        self.msg_twist_acceleration = MsgAcceleration()
        self.msg_twist = MsgTwist()
        self.listener = tf.TransformListener()
        
        self.twist_speed = 0
        self.averaged_twist_acceleration = 0
        self.twist_acceleration_list = []
        self.twist_speed_list = []
        self.averaged_twist_speed = 0

        # r = rospy.Rate(1000)
        # while not rospy.is_shutdown():
        #     self.pub_velocity()
        #     r.sleep()

        rospy.spin()


    def cb_position(self, msg):
        try:
            stamp = rospy.Time.now()
            self.listener.waitForTransform(
                "/tcp_link", "/world", stamp, rospy.Duration(1.0))
            position, quaternion = self.listener.lookupTransform(
                "/tcp_link", "/world", stamp)

            # linear_velocity, angular_velocity = self.listener.lookupTwist(
            #     "/tcp0", "/world", stamp, rospy.Duration(0.01))
            '''
            # publishing the twist (linear velocity)
            self.twist_speed = np.sqrt(linear_velocity[0] * linear_velocity[0] 
                                       + linear_velocity[1] * linear_velocity[1] 
                                       + linear_velocity[2] * linear_velocity[2] )
            self.msg_twist.header.stamp = stamp
            self.msg_twist.linear_x = linear_velocity[0]
            self.msg_twist.linear_y = linear_velocity[1]
            self.msg_twist.linear_z = linear_velocity[2]
            self.msg_twist.linear_speed = self.twist_speed
            self.speed_moving_average (self.twist_speed)
            self.msg_twist.speed_averaged = self.averaged_twist_speed
            self.twist_pub.publish(self.msg_twist)
            
            
            # calculate the acceleration calculated by twist change
            # twist_acceleration = self.velocity.twist_acceleration(
            #     stamp.to_sec(), self.twist_speed)
            twist_acceleration = self.velocity.twist_acceleration(
                stamp.to_sec(), self.averaged_twist_speed)
            self.msg_twist_acceleration.header.stamp = stamp
            self.msg_twist_acceleration.acceleration = twist_acceleration
            self.acceleration_moving_average(twist_acceleration)
            self.msg_twist_acceleration.acceleration_averaged = self.averaged_twist_acceleration
            self.twist_acceleration_pub.publish (self.msg_twist_acceleration)
            '''

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
            '''
            

        except (tf.Exception, tf.LookupException, tf.ConnectivityException,
                tf.ExtrapolationException):
            rospy.loginfo("TF Exception")
            
            
            
              
    def acceleration_moving_average(self, accelertation):
        frames = 5
        if len(self.twist_acceleration_list) == 4:
            self.twist_acceleration_list.append(accelertation) 
            self.averaged_twist_acceleration = sum(self.twist_acceleration_list)/frames
            self.twist_acceleration_list.pop(0) # remove the first item in the list
        else:
            self.twist_acceleration_list.append(accelertation)
            
               
    def speed_moving_average(self, speed):
        frames = 5
        if len(self.twist_speed_list) == 4:
            self.twist_speed_list.append(speed)
            self.averaged_twist_speed = sum(self.twist_speed_list)/frames
            self.twist_speed_list.pop(0) # remove the first item in the list
        else:
            self.twist_speed_list.append(speed)






if __name__ == '__main__':
    try:
        NdVelocity()
    except rospy.ROSInterruptException:
        pass
