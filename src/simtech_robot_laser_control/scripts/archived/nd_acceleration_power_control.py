#!/usr/bin/env python
import os
import rospy
import rospkg


from simtech_robot_laser_control.msg import MsgPower

from camera_measures.msg import MsgAcceleration

import numpy as np




class NdAccelerationPowerControl():
    def __init__(self):
        rospy.init_node('Acceleration-Power Control')
        
        # subscribe velocity
        # rospy.Subscriber(
            # '/acceleration', MsgAcceleration, self.cb_acceleration, queue_size=5)
        rospy.Subscriber(
            "/twist_acceleration", MsgAcceleration, self.cb_twist_acceleration, queue_size=5)
        
        
        self.pub_power = rospy.Publisher(
            '/control/power', MsgPower, queue_size=10)
        
        # set power min max limit
        self.setPowerParameters(rospy.get_param('/control_parameters/power'))
        # set nominal power value
        self.get_nominal_power(rospy.get_param('/control_parameters/manual'))
        
        self.msg_power = MsgPower()
        self.acceleration = 0

        
        
        rospy.spin()


    def cb_acceleration(self, msg_acceleration):
        # real-time acceleration callback 
        stamp = msg_acceleration.header.stamp
        # time = stamp.to_sec()
        # self.v_x = msg_velocity.vx
        # self.v_y = msg_velocity.vy
        # self.v_z = msg_velocity.vz
        self.acceleration = msg_acceleration.acceleration
        a_min = -0.12 # m/s^2
        a_max = 0.12
        
        # power calculation
        power = self.power_min + (self.power_max - self.power_min) / (a_max - a_min) * (self.acceleration - a_min)
        
        power = self.range(power)
        
        self.msg_power.header.stamp = stamp
        
        self.msg_power.value = power
        
        rospy.set_param('/control/power', power)
        
        self.pub_power.publish (self.msg_power)
        
        
    def cb_twist_acceleration(self, msg_twist_acceleration):
        # real-time acceleration callback 
        stamp = msg_twist_acceleration.header.stamp
        # time = stamp.to_sec()
        # self.v_x = msg_velocity.vx
        # self.v_y = msg_velocity.vy
        # self.v_z = msg_velocity.vz
        self.acceleration = msg_twist_acceleration.acceleration
        # self.acceleration = msg_twist_acceleration.acceleration_averaged
        a_min = -0.02 # m/s^2
        a_max = 0.02
        
        # power calculation
        power = self.power_min + (self.power_max - self.power_min) / (a_max - a_min) * (self.acceleration - a_min)
        
        power = self.range(power)
        
        self.msg_power.header.stamp = stamp
        
        self.msg_power.value = power
        
        rospy.set_param('/control/power', power)
        
        self.pub_power.publish (self.msg_power)
        
   

   
    def get_nominal_power(self, params):
        self.nominal_power = params['power']

   
   
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
        NdAccelerationPowerControl()
    except rospy.ROSInterruptException:
        pass
