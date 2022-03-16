#!/usr/bin/env python

import socket
import logging
import os
import glob
import rospkg
import rospy
from defects_identification.msg import MsgDefects

from socket_laser_velocity.velocity_socket import SocketConnection

log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())



controller_ip = '192.168.125.1'  # the robot ip address that you want to connect
VELOCITY_PORT = 10002            # the port used by velocity socket server
LASER_PORT = 10001                # the port used by laser server socket



class Nd_socket():
    def __init__(self):
        # initiate node with name
        rospy.init_node('laser_robot_stop')
        # create client socket and establish connection with velocity socket server
        self.velocity_socket_client = SocketConnection(controller_ip,VELOCITY_PORT )
        self.velocity_socket_client.estab_connect()
        
        self.laser_socket = SocketConnection (controller_ip, LASER_PORT)
        self.laser_socket.estab_connect()

        rospy.Subscriber(
            '/plane_defects_identification', MsgDefects, self.cb_defects, queue_size=20)

        

        rospy.spin() # go into an infinite loop until it receives a shutdown signal 
        
        self.velocity_socket_client.close()
        self.laser_socket.close()
 


    def cb_defects(self, msg_defects):
        '''
        The node receive the message of defects identification results,
        As long as the result is not 0 (i.e., either 1,2,3 ridge or dent defects)
        It will issue stop command to both laser and velocity server
        to make the process stop
        '''
         
        # only if defects is not 0 (defects exists)
        if msg_defects.defectsType != 0:
            # stop the laser and robot by setting power and velocity zero
            
            #set the veloctiy value zero 
            #convert the value(float32) to only one decimal place string    
            self.SpeedOverride_send = self.velocity_socket_client.set_SpeedOverride( "0.0" )
            rospy.loginfo("SpeedOverride has been set:" + str(self.SpeedOverride_send))
            
            #set power analog value zero 
            #convert the value(float32) to only one decimal place string   
            self.power_send = self.laser_socket.set_analog_power("0.0")
            rospy.loginfo("power has been set:" + str(self.power_send))




    

if __name__ == '__main__':
    try:
        Nd_socket()
    except rospy.ROSInterruptException:
        pass
   


