#! /usr/bin/env python

'''
main ROS program
'''

# from control.laser_socket import SimpleConnection
# from control_connection.simple_socket import SimpleConnection
from simple_socket import SimpleConnection

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

    
def main():
    
    rospy.init_node('main task')
    
    # establish tcp socket connections
    connection = SimpleConnection()
    connection.estab_connect(robot_ip)
 
    rate = rospy.Rate(60)
    while not rospy.is_shutdown():
    # while True:
        recved = connection.s.recv(512)
     
        print ("command received")
        print (recved.decode())
        recved = float(recved.decode()) # change the data from string to float number
        print ("received converted to float: ")
        print (recved)
        
        

        if recved == 0.0:
            print("current state is idle")
        elif recved == 1.0:
            print ("current state is scanning")
        elif recved == 2.0:
            print("current state is control")
            # logging.info ("current state is control")
        else:
            print ("not known")
            
            
        rate.sleep()
        
            
            
    


if __name__ == "__main__":
    main()
