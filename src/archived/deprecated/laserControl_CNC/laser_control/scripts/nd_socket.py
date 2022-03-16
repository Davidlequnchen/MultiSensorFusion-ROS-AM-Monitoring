#!/usr/bin/env python

import socket
import logging
import os
import glob
import rospkg
import rospy

from laser_control.msg import MsgControl
from laser_control.msg import MsgPower
from laser_control.msg import MsgInfo
from laser_control.msg import MsgStart
from laser_control.msg import MsgEmission                                           #20191011

from control.laser_socket import SimpleConnection

log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())



laser_ip = '10.0.0.230'  # the laser ip address that you want to connect
PORT = 10001      # the port used by laser socket server

path = '../'

filename = os.path.join(path, 'data', 'data.txt')


class Nd_socket():
    def __init__(self):
        rospy.init_node('PC_communication')
        # create client socket and establish connection with laser socket server
        self.laser_connection = SimpleConnection()
        self.laser_connection.estab_connect(laser_ip)

         # disable external control                                                              #20191011 add
        self.external_control =  self.laser_connection.disable_external_control()
        print("external control disabled:" + str(self.external_control))

        # disable the hardware emmision
        self.hardware_emmision = self.laser_connection.disable_hardware_emmision()                #20191011 add
        print("hardware emission disabled:" + str(self.hardware_emmision))

        rospy.Subscriber(
            '/control/power', MsgPower, self.cb_power, queue_size=1)
        rospy.Subscriber(
            '/control/start', MsgStart, self.cb_start, queue_size=1)
        rospy.Subscriber(
            '/control/emission', MsgEmission, self.cb_emission, queue_size=1)                     #20191011
       
 
        #If the external control is enabled
        self.external_control = True

        #If the hardware emission is enabled
        self.hardware_emmision = True

        #If the diode current is controlled
        self.current_control = False

        self.diode_current = 0.0
        self.current_setpoint = 0.0
        self.current_laser_power = 0.0

        rospy.spin()
        self.laser_connection.close()

    def cb_emission(self, msg_emission):
        if msg_emission.emission is True:
            self.emission_on = self.laser_connection.start_emission()
            log.info('emission is on: ' + self.emission_on)                                       #20191011


    def cb_power(self, msg_power):
        '''
        The node receive the message of controled value of power,
        then send the value to the laser server socket 
        '''

        # disable external control
        #self.external_control =  self.laser_connection.disable_external_control()
        #print("external control disabled:" + str(self.external_control))

        # disable the hardware emmision
        #self.hardware_emmision = self.laser_connection.disable_hardware_emmision()
        #print("hardware emission disabled:" + str(self.hardware_emmision))

        #set diode current
        #convert the value(float32) to only one decimal place string
        self.diode_current = "%.1f" % msg_power.value     
        #self.diode_current = str(msg_power.value)
        #self.diode_current = str(70.0)
        self.current_control = self.laser_connection.set_diode_current(self.diode_current)
        print("diode current has been set:" + str(self.current_control))


        #enable hardware emission control
        #self.hardware_emmision = self.laser_connection.enable_hardware_emmision()                  #20191011 comment out
        #print("hardware emission control enabled:" + str(self.hardware_emmision))


    def cb_start(self, msg_start):
        if msg_start.control is True:
            #read current setpoint by requesting from the client socket
            self.current_setpoint = self.laser_connection.read_current_setpoint()
            print('The current setpoint is ' + repr(self.current_setpoint))

            #read the actual power
            self.power = self.laser_connection.read_power()
            print("the current laser power is" + str(self.power))

if __name__ == '__main__':
    try:
        Nd_socket()
    except rospy.ROSInterruptException:
        pass
   


