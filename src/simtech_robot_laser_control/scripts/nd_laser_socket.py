#!/usr/bin/env python

import socket
import logging
import os
import glob
import rospkg
import rospy

from simtech_robot_laser_control.msg import MsgControl
from simtech_robot_laser_control.msg import MsgPower
from simtech_robot_laser_control.msg import MsgInfo
from simtech_robot_laser_control.msg import MsgStart
from simtech_robot_laser_control.msg import MsgEmission                                           #20191011
from camera_measures.msg import MsgStatus


from control.laser_socket import SimpleConnection

log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())



laser_ip = '192.168.125.1'  # the laser ip address that you want to connect
PORT = 10001      # the port used by laser socket server

path = '../'

filename = os.path.join(path, 'data', 'data.txt')


class Nd_socket():
    def __init__(self):
        rospy.init_node('laser_control')
        # create client socket and establish connection with laser socket server
        self.laser_connection = SimpleConnection()
        self.laser_connection.estab_connect(laser_ip)

        rospy.Subscriber(
            '/control/power', MsgPower, self.cb_power, queue_size=1)

        '''
        rospy.Subscriber(
            '/control/start', MsgStart, self.cb_start, queue_size=1)
        
        rospy.Subscriber(
            '/supervisor/status', MsgStatus, self.cb_status, queue_size=1)
        '''

        rospy.spin()
        self.laser_connection.close()
 
 
    '''
    def cb_velocity(self, msg_velocity):
        speed = 0
        running = False
        if msg_velocity.speed > 0.0005:
            running = True
            speed = 1000 * msg_velocity.speed
        self.msg_status.running = running
        self.msg_status.speed = speed
    '''



    def cb_power(self, msg_power):
        '''
        The node receive the message of controled value of power,
        then send the value to the laser server socket 
        '''

        #set power analog value
        #convert the value(float32) to only one decimal place string
        self.send_power = "%.1f" % msg_power.value   
        # print("send_power =  " + self.send_power)  
        #self.send_power = str(msg_power.value)
        #self.send_power = str(70.0)
        self.power_controlled = self.laser_connection.set_analog_power(self.send_power)
        # print("power has been set:" + str(self.power_controlled))


        #enable hardware emission control
        #self.hardware_emmision = self.laser_connection.enable_hardware_emmision()                  #20191011 comment out
        #print("hardware emission control enabled:" + str(self.hardware_emmision))

    '''
    def cb_start(self, msg_start):
        if msg_start.control is True:
            #read current setpoint by requesting from the client socket
            self.current_setpoint = self.laser_connection.read_current_setpoint()
            print('The current setpoint is ' + repr(self.current_setpoint))

            #read the actual power
            self.power = self.laser_connection.read_power()
            print("the current laser power is" + str(self.power))
    '''

if __name__ == '__main__':
    try:
        Nd_socket()
    except rospy.ROSInterruptException:
        pass
   


