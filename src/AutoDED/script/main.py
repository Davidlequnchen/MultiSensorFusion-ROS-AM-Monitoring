#! /usr/bin/env python

'''
main ROS program
'''

# from control.laser_socket import SimpleConnection
# from control_connection.simple_socket import SimpleConnection
from simple_socket import SimpleConnection
from auto_control.msg import MsgCommand


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

srv_client_scanning_ = None
srv_client_control_ = None
command_message=MsgCommand()
cmd_publisher_= None
last_command = 0

def change_state(state):
    global state_, state_desc_
    global srv_client_control_, srv_client_scanning_
    state_ = state
    log = "state changed: %s" % state_desc_[state]
    print (log)
    if state_ == 0: # idle mode
        resp = srv_client_scanning_(False)
        # resp = srv_client_control_(False)
    if state_ == 1: # surface scanning
        resp = srv_client_scanning_(True)
        # resp = srv_client_control_(False)
    if state_ == 2: # process control
        resp = srv_client_scanning_(False)
        # resp = srv_client_control_(True)
    
    
    

        
        
def check_command_change(command):
    global last_command
    if command - last_command ==0:
        return True
    else:
        last_command = command
        return False
    

    


def main():
    global state_, last_command, cmd_publisher_
    global srv_client_control_, srv_client_scanning_
    
    
    rospy.init_node('main task')
    
    print ("1")
    
    # establish tcp socket connections
    connection = SimpleConnection()
    connection.estab_connect(robot_ip)
    print ("2: connection established")
    
    # ROS service
    # # Wait until a service becomes available
    # rospy.wait_for_service('scanning_switch') #----------------------------------need
    # # rospy.wait_for_service('/process_control_switch')
    # print ("3")
    
    
    # # Create a callable proxy to a service.
    # srv_client_scanning_ = rospy.ServiceProxy('scanning_switch', SetBool) #----------------------------------need
    # # srv_client_control_ = rospy.ServiceProxy('/process_control_switch', SetBool)
    # print ("4")
    
    ## Publisher
    cmd_publisher_ = rospy.Publisher ('/main_command', MsgCommand, queue_size=5)

    
    
    # recved = connection.s.recv(1024)
    # last_command = float(recved.decode())
    # command_message.command = last_command
    # cmd_publisher_.publish(command_message)
    
    
    rate = rospy.Rate(60)
    while not rospy.is_shutdown():
    # while True:
        recved = connection.s.recv(512)
        
        # print (recved.decode())   #------------------verified can
        recved = float(recved.decode()) # change the data from string to float number
        # print ("command received")  #------------------verified can
        
        # command_changed = check_command_change(recved)
        
        
        # if command_changed:
            
        #     if recved == 0.0:
        #         change_state(0)
        #         print("current state is idle")
        #     elif recved == 1.0:
        #         change_state(1)
        #         print ("current state is scanning")
        #     elif recved == 2.0:
        #         change_state(2)
        #         print ("current state is control")
        #     else:
        #         change_state(0)
            
        command_message.command = recved
        cmd_publisher_.publish(command_message)
            
        rate.sleep()
        
            
            
    


if __name__ == "__main__":
    main()
