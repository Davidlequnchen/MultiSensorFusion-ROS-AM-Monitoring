#!/usr/bin/env python
import tf
import rospy
import rospkg
import numpy as np

from camera_measures.msg import MsgVelocity
from measures.velocity import Velocity
# from camera_measures.msg import MsgPosition
from simtech_kuka_rsi_hw_interface.msg import MsgCartPosition
from camera_measures.msg import MsgAcceleration
# from camera_measures.msg import MsgTwist

class NdVelocity():
    def __init__(self):
        rospy.init_node('kuka motion monitoring')

        # subscribe the cartesian coordinate of the tcp
        rospy.Subscriber("/cartesian_position", MsgCartPosition, self.cb_position, queue_size=10)

        self.velocity_pub = rospy.Publisher(
            '/kuka_velocity', MsgVelocity, queue_size=10)

        self.acceleration_pub = rospy.Publisher(
            '/kuka_acceleration', MsgAcceleration, queue_size=10)
 
        
        self.velocity = Velocity()
        self.msg_velocity = MsgVelocity()
        self.msg_acceleration = MsgAcceleration()

        self.acceleration_list = []
        self.averaged_acceleration = 0

        # r = rospy.Rate(500)
        # while not rospy.is_shutdown():
        #     self.pub_velocity()
        #     r.sleep()
        rospy.spin()



    def cb_position(self, msg_cart_position):
        try:
            position = [None] * 3
            position[0] = msg_cart_position.X
            position[1] = msg_cart_position.Y
            position[2] = msg_cart_position.Z


            stamp = rospy.Time.now()
            # calculate the velocity and speed using the position data
            speed, velocity = self.velocity.instantaneous(
                stamp.to_sec(), np.array(position))
            self.msg_velocity.header.stamp = stamp
            self.msg_velocity.speed = speed
            self.msg_velocity.vx = velocity[0]
            self.msg_velocity.vy = velocity[1]
            self.msg_velocity.vz = velocity[2]
            self.velocity_pub.publish(self.msg_velocity)
            
            stamp = rospy.Time.now()
            # calculate the acceleration using the velocity data
            acceleration = self.velocity.acceleration(
                stamp.to_sec(), speed)
            self.msg_acceleration.header.stamp = stamp
            self.msg_acceleration.acceleration = acceleration
            self.acceleration_moving_average(acceleration)
            self.msg_acceleration.acceleration_averaged = self.averaged_acceleration
            self.acceleration_pub.publish (self.msg_acceleration)
            
            

        except (tf.Exception, tf.LookupException, tf.ConnectivityException,
                tf.ExtrapolationException):
            rospy.loginfo("TF Exception")
            
            
              
    def acceleration_moving_average(self, accelertation):
        frames = 5
        if len(self.acceleration_list) == 4:
            self.acceleration_list.append(accelertation) 
            self.averaged_acceleration = sum(self.acceleration_list)/frames
            self.acceleration_list.pop(0) # remove the first item in the list
        else:
            self.acceleration_list.append(accelertation)
            
               
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
