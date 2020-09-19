#! /usr/bin/env python

'''
main ROS program

Communicating with Socket routine (the semistaick background task socket in robot controller)
Send: whether there is defects (1) or not (0) based on machine learning prediction
Receive: the current state of the printing process: ['idle', 'surface scanning', 'process control'] (--0/1/2)

Publish: '/main_command', MsgCommand ---- the current state, if it is 1 (scanning), then the microepsilon will be turned on
Subscribe: /plane_defects_identification", MsgDefects ---- (published by point cloud machine learning node)


'''


from simple_socket import SimpleConnection
from auto_control.msg import MsgCommand
from defects_identification.msg import MsgDefects


# import ros library
import rospy
# import ros message
from std_msgs.msg import Bool
# import ros service
from std_srvs.srv import *
import math
import logging


## define: 
## 0-- idel state (no control, no scanning)
## 1: -- surface scanning node (turn on the microepsilon driver to produce point cloud)
## 2. -- process control mode (microepsilon scanner turned off, only process control is applied)

robot_ip = '192.168.125.1'  # the robot controller ip address that you want to connect

## define some global variables:
state_desc_ = ['idle', 'surface scanning', 'process control']
state_ = 0


is_defects = 0 #0-no defects, 1 - have defects

        
    
class NdAutoControl():
    def __init__(self):
        rospy.init_node('main task')
        # create client socket and establish connection with laser socket server
        self.socket_connection = SimpleConnection()
        self.socket_connection.estab_connect(robot_ip)
        
        #  -------Publisher------------
        self.cmd_publisher_ = rospy.Publisher ('/main_command', MsgCommand, queue_size=5)
        # -------subscribers ------------
        rospy.Subscriber("/plane_defects_identification", MsgDefects, self.defects_idendification_callback, queue_size=1)
        
        self.command_message = MsgCommand()
        
        self.is_defects = 0 #0-no defects, 1 - have defects
        
        
        rospy.spin() # defualt spin -- 30 Hz
        self.socket_connection.close()
        
        
            
    def defects_idendification_callback(self, msg_defects):
        if msg_defects.defectsType == 0:
            self.is_defects = 0
        else: # else could be dent/bulge/wavy defects
            self.is_defects = 1
            
        
        recved = self.socket_connection.set_defects_result(str(self.is_defects)) # Send whether there is defects (1) or not (0)
        # while sending this info, it also receive data showing the current printing state (0/1/2, 1 is scanning)
        recved = float(recved.decode()) # the received value should be the state the process is currently in, needs to be decoded and converted
        # recved should be either 0/1/2

            
        self.command_message.command = recved
        self.cmd_publisher_.publish(self.command_message) #either 0/1/2, indicate the state -- idle, scanning, control
        
    
    


if __name__ == "__main__":
    try:
        NdAutoControl()
    except rospy.ROSInterruptException:
        pass
   
