#!/usr/bin/env python
import os
import rospy
import rospkg

from laser_control.msg import MsgControl
from laser_control.msg import MsgPower

from camera_measures.msg import MsgGeometry
from camera_measures.msg import MsgVelocityStatus
from camera_measures.msg import MsgVelocity


from control.control import Control
from control.control import PID
import numpy as np


'''
This node subscribe velocity and melt pool geometry message,
and then calculates the PID parameters: set kp ki kd value as a rospram, which will be read by the nd_control node.
'''

class NdPIDCalculation():
    def __init__(self):
        rospy.init_node('PID calculation')
        # subscribe the melt pool width
        rospy.Subscriber(
            '/usb_cam/geometry', MsgGeometry, self.cb_geometry, queue_size=1)
        # subscribe velocity
        rospy.Subscriber(
            '/velocity', MsgVelocity, self.cb_velocity, queue_size=1)
        rospy.Subscriber(
            '/supervisor/velocity_status', MsgVelocityStatus, self.cbStatus, queue_size=1)



    def cb_velocity(self, msg_velocity):
        self.v_x = msg_velocity.vx
        self.v_y = msg_velocity.vy
        self.v_z = msg_velocity.vz
        self.speed = msg_velocity.speed
    
    def cbStatus(self, msg_velocityStatus):
        self.is_running = msg_velocityStatus.running


    def cb_geometry(self, msg_geo):
        # stamp = msg_geo.header.stamp
        # time = stamp.to_sec()
        self.minor_axis = msg_geo.minor_axis
        self.getNominal_PID_Parameters(rospy.get_param('/control_parameters/automatic')) # get current nominal width
        self.getNominalSpeed(rospy.get_param('/process')) #get nominal speed as set in parms.yaml file(can be found in launch)
        self.calculation_coefficient(1,2,3,4)
        if (self.speed - self.nominal_speed) > 0: # if current speed is larger than nominal speed 
            if self.minor_axis > self.nominal_width:
                self.kd = self.coefficient_d1 / (self.speed - self.nominal_speed)
            else:
                self.kd = self.coefficient_d2 * (self.speed - self.nominal_speed)

        else:
            if self.minor_axis > self.nominal_width:
                self.kd = self.coefficient_d3 * (self.speed - self.nominal_speed)
            else:  
                self.kd = self.coefficient_d4 / (self.speed - self.nominal_speed)

        self.kp = 0 # set temporary value for now
        self.ki = 0

        param = self.getParameters()
        rospy.set_param('/control_parameters/pid_parameters', param)



    def getNominal_PID_Parameters(self, params):
        self.nominal_width = params['width']

    def getNominalSpeed(self, params):
        self.nominal_speed = params['speed']



    def calculation_coefficient(self, d1, d2, d3, d4):
        self.coefficient_d1 = d1
        self.coefficient_d2 = d2
        self.coefficient_d3 = d3
        self.coefficient_d4 = d4


    def getParameters(self):
        # get parameters calculated
        params = {'Kp': self.kp,
                  'Ki': self.ki,
                  'Kd': self.kd}
        return params
    

if __name__ == '__main__':
    try:
        NdPIDCalculation()
    except rospy.ROSInterruptException:
        pass
