#!/usr/bin/env python
import os
import rospy
import rospkg


from simtech_robot_laser_control.msg import MsgPower

from camera_measures.msg import MsgGeometry
from camera_measures.msg import MsgVelocity
from camera_measures.msg import MsgTwist


import numpy as np




class NdVelocityPowerControl():
    def __init__(self):
        rospy.init_node('Velocity-Power Control')
        
        # subscribe velocity
        # rospy.Subscriber(
            # '/velocity', MsgVelocity, self.cb_velocity, queue_size=5)
        rospy.Subscriber(
            '/twist', MsgTwist, self.cb_twist, queue_size=5)
        
        self.pub_power = rospy.Publisher(
            '/control/power', MsgPower, queue_size=10)
        
        # set power min max limit
        self.setPowerParameters(rospy.get_param('/control_parameters/power'))
        
        self.msg_power = MsgPower()
        self.speed = 0
        
        
        rospy.spin()

    
    def cb_velocity(self, msg_velocity):
        # real-time speed callback 
        stamp = msg_velocity.header.stamp
        # time = stamp.to_sec()
        # self.v_x = msg_velocity.vx
        # self.v_y = msg_velocity.vy
        # self.v_z = msg_velocity.vz
        self.speed = msg_velocity.speed
        
        v_min = 0.005
        v_max = 0.032
        
        # power calculation
        power = self.power_min + (self.power_max - self.power_min)/(v_max - v_min) * (self.speed - v_min)
        
        # power = 7.1889 - 77.78 * self.speed
        power = self.range(power)
        
        self.msg_power.header.stamp = stamp
        
        self.msg_power.value = power
        
        rospy.set_param('/control/power', power)
        
        self.pub_power.publish (self.msg_power)
        
        
        
    def cb_twist(self, msg_twist):
        # real-time speed callback 
        stamp = msg_twist.header.stamp
        # time = stamp.to_sec()
        # self.v_x = msg_twist.linear_x
        # self.v_y = msg_twist.linear_y
        # self.v_z = msg_twist.linear_z
        self.speed = msg_twist.linear_speed
        
        v_min = 0.016
        v_max = 0.026
        
        # power calculation
        power = self.power_min + (self.power_max - self.power_min)/(v_max - v_min) * (self.speed - v_min)
        
        # power = 7.1889 - 77.78 * self.speed
        power = self.range(power)
        
        self.msg_power.header.stamp = stamp
        
        self.msg_power.value = power
        
        rospy.set_param('/control/power', power)
        
        self.pub_power.publish (self.msg_power)
        
   

    def get_setpoint_width(self, params):
        self.nominal_width = params['width']

   
   
    def range(self, value):
        if value < self.power_min:
            value = self.power_min
        elif value > self.power_max:
            value = self.power_max
        #if  not self.status:
        #    value = 0
        return value
    
    def setPowerParameters(self, params):
        self.power_min = params['min']
        self.power_max = params['max']
   

if __name__ == '__main__':
    try:
        NdVelocityPowerControl()
    except rospy.ROSInterruptException:
        pass
