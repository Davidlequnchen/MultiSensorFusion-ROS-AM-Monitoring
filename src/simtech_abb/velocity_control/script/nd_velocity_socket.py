#!/usr/bin/env python

import socket
import logging
import os
import glob
import rospkg
import rospy

from velocity_control.msg import MsgSpeedOverride

from velocity_controller.velocity_socket import SimpleConnection

log = logging.getLogger(__name__)
log.addHandler(logging.NullHandler())



laser_ip = '192.168.125.1'  # the robot ip address that you want to connect
PORT = 10002      # the port used by velocity socket server


class Nd_socket():
    def __init__(self):
        rospy.init_node('velocity_control_socket')
        # create client socket and establish connection with velocity socket server
        self.velocity_connection = SimpleConnection()
        self.velocity_connection.estab_connect(laser_ip)

        rospy.Subscriber(
            '/velocity_control/SpeedOverride', MsgSpeedOverride, self.cb_SpeedOverride, queue_size=20)

        

        rospy.spin()
        self.velocity_connection.close()
 


    def cb_SpeedOverride(self, msg_SpeedOverride):
        '''
        The node receive the message of controled value of SpeedOverride,
        then send the value to the velocity server socket 
        '''

        #set power analog value
        #convert the value(float32) to only one decimal place string
        self.send_SpeedOverride = "%.2f" % msg_SpeedOverride.value     
        
        self.SpeedOverride_controlled = self.velocity_connection.set_SpeedOverride(self.send_SpeedOverride)
        rospy.loginfo("SpeedOverride has been set:" + str(self.SpeedOverride_controlled))


 

if __name__ == '__main__':
    try:
        Nd_socket()
    except rospy.ROSInterruptException:
        pass
   


