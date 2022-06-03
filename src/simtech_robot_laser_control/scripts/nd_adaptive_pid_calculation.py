#!/usr/bin/env python3
import os
import rospy
import rospkg

from laser_control.msg import MsgControl
from laser_control.msg import MsgPower

from camera_measures.msg import MsgGeometry
from camera_measures.msg import MsgVelocityStatus
from camera_measures.msg import MsgStatus
from camera_measures.msg import MsgVelocity


from control.control import Control
from control.control import PID
import numpy as np


'''
This node subscribe velocity and melt pool geometry message,
and then calculates the PID parameters, and adaptively updates it according to real-time speed changes: 
set kp ki kd value as a rospram, which will be read by the nd_control node.
(it is similar to the way qt program sets pid parameters)
'''

class NdPIDCalculation():
    def __init__(self):
        rospy.init_node('PID calculation')
        # subscribe the melt pool width
        rospy.Subscriber(
            '/usb_cam/geometry', MsgGeometry, self.cb_geometry, queue_size=10)
        # subscribe velocity
        rospy.Subscriber(
            '/velocity', MsgVelocity, self.cb_velocity, queue_size=5)
        
        # be careful: please check the launch file to choose either MsgVelocityStatus or MsgStatus
        # rospy.Subscriber(
        #     '/supervisor/velocity_status', MsgVelocityStatus, self.cbStatus, queue_size=5)
        # rospy.Subscriber(
        #     '/supervisor/status', MsgStatus, self.cbStatus, queue_size=1)
        
        
        self.set_calculation_coefficient(rospy.get_param('/adaptive_calculation/pid_calculation_coefficient'))
        # get current nominal width. This value is specified initially from config->control_parameters.yaml file
        # this value is then changed based on Qt setting (when you click to change pid value, the rosparm also changes)
        self.get_setpoint_width(rospy.get_param('/control_parameters/automatic'))
        self.get_nominal_speed(rospy.get_param('/adaptive_calculation/nominal_speed')) #get nominal speed as set in parms.yaml file(can be found in launch)
        self.get_nominal_pid_parameters(rospy.get_param('/control_parameters/pid_parameters'))
        
        self.speed = 0
        
        
        rospy.spin()


    def cb_velocity(self, msg_velocity):
        # real-time speed callback 
        self.v_x = msg_velocity.vx
        self.v_y = msg_velocity.vy
        self.v_z = msg_velocity.vz
        self.speed = msg_velocity.speed
    
    def cbStatus(self, msg_velocityStatus):
        self.is_running = msg_velocityStatus.running
        
    # def cbStatus(self, msg_status):
    #     self.is_running = msg_status.running


    def cb_geometry(self, msg_geo):
        # stamp = msg_geo.header.stamp
        # time = stamp.to_sec()
        self.minor_axis = msg_geo.minor_axis_average
        
        
        if (self.speed - self.nominal_speed) > 0: # if current speed is larger than nominal speed 
            if self.minor_axis > self.nominal_width:
                self.Kp = self.Kp_nominal - self.coefficient_1 * (self.speed - self.nominal_speed)
            else:
                self.Kp = self.Kp_nominal + self.coefficient_2 * (self.speed - self.nominal_speed)

        else:
            if self.minor_axis > self.nominal_width:
                self.Kp = self.Kp_nominal - self.coefficient_3 * (self.nominal_speed - self.speed)
            else:  
                self.Kp = self.Kp_nominal + self.coefficient_4 * (self.nominal_speed - self.speed)
                
        self.Ki = self.Ki_nominal
        self.Kd = self.Kd_nominal

        

        param = self.get_pid_params() # get the updated pid parameters
        rospy.set_param('/control_parameters/pid_parameters', param)



    def get_setpoint_width(self, params):
        self.nominal_width = params['width']

    def get_nominal_speed(self, params):
        self.nominal_speed = params['speed']
        
    def get_nominal_pid_parameters(self, params):
        self.Kp_nominal = params['Kp']
        self.Ki_nominal = params['Ki']
        self.Kd_nominal = params['Kd']



    def set_calculation_coefficient(self, params):
        self.coefficient_1 = params['coefficient_1']
        self.coefficient_2 = params['coefficient_2']
        self.coefficient_3 = params['coefficient_3']
        self.coefficient_4 = params['coefficient_4']


    def get_pid_params(self):
        # get parameters calculated
        params = {'Kp': self.Kp,
                  'Ki': self.Ki,
                  'Kd': self.Kd}
        return params
    

if __name__ == '__main__':
    try:
        NdPIDCalculation()
    except rospy.ROSInterruptException:
        pass
