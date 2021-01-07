#!/usr/bin/env python3

'''
run in python3
To complie the workspace: catkin_make -DPYTHON_EXECUTABLE=/usr/bin/python3
This makes the python2 works together with python3 in ROS
'''
import os
import rospy
import rospkg

# from laser_control.msg import MsgControl
from laser_control.msg import MsgPower

from camera_measures.msg import MsgGeometry
from camera_measures.msg import MsgVelocityStatus
from camera_measures.msg import MsgStatus
from camera_measures.msg import MsgVelocity


# from control.control import Control
# from control.control import PID


# Import required python libraries
import numpy as np  # important package for scientific computing
from scipy import signal  # signal processing library
# import matplotlib.pyplot as plt  # library to plot graphics
import vrft  # vrft package


'''
This node subscribe melt pool geometry message,
and then calculates the PID parameters, and adaptively updates it in real-time by VRFT method
it set kp ki kd value as a rospram, which will be read by the nd_control node.
(it is similar to the way that qt program sets pid parameters)
'''

BUFFER_INTERVAL = 10 # save the buffer every XX secods
BUFFER_LENGTH = 300 # 1 seconds - 30 data points

class NdPIDVRFT():
    def __init__(self):
        rospy.init_node('adaptive PID-VRFT calculation')
        
        
        # I/O data buffer; create two empty numpy array list
        self.power_list = np.array([])
        self.minor_axis_list = np.array([])
            
        # initialize the time stamp as current ROS time
        self.last_geometry_stamp = rospy.Time.now().to_sec()
        self.last_power_stamp = rospy.Time.now().to_sec()
        # self.last_geometry_stamp = 0
        # self.last_power_stamp = 0
        
        self.output_data_ready_to_use = False
        self.input_data_ready_to_use = False
        
             
        # subscribe the melt pool width
        rospy.Subscriber(
            '/usb_cam/geometry', MsgGeometry, self.cb_geometry, queue_size=10)
        rospy.Subscriber(
            '/control/power', MsgPower, self.cb_power, queue_size=10)
        
        
        self.rate = rospy.Rate(30) # 30 Hz freqency
        while not rospy.is_shutdown():
       
            # # subscribe velocity
            # rospy.Subscriber(
            #     '/velocity', MsgVelocity, self.cb_velocity, queue_size=5)
            
            # be careful: please check the launch file to choose either MsgVelocityStatus or MsgStatus
            # rospy.Subscriber(
            #     '/supervisor/velocity_status', MsgVelocityStatus, self.cbStatus, queue_size=5)
            # rospy.Subscriber(
            #     '/supervisor/status', MsgStatus, self.cbStatus, queue_size=1)
            
            # if self.output_data_ready_to_use and self.input_data_ready_to_use:
            self.vrft_pid_update()
            
        
    
            self.rate.sleep()
        
        # self.vrft_pid_update()
        # rospy.spin()



    def cb_geometry(self, msg_geo):
        # current_time = msg_geo.header.stamp.to_sec()
        # if current_time - self.last_geometry_stamp < BUFFER_INTERVAL:
        #     # print ("append data")
        #     if self.output_data_ready_to_use is False:
        #         # print ("append data")
        #         # store the minor_axis into a Buffer 
        #         self.minor_axis_list = np.append(self.minor_axis_list, msg_geo.minor_axis) #msg_geo.minor_axis_average
        if self.minor_axis_list.size < BUFFER_LENGTH:
            if self.output_data_ready_to_use is False:
                # store the minor_axis into a Buffer 
                self.minor_axis_list = np.append(self.minor_axis_list, msg_geo.minor_axis_average) #msg_geo.minor_axis_average
            
                
        else:
            # set output data ready
            # print("data ready")
            self.output_data_ready_to_use = True
            # self.last_geometry_stamp = current_time
            
            
            
            


    def cb_power(self, msg_power):
        # current_time = msg_power.header.stamp.to_sec()
        # if current_time - self.last_power_stamp < BUFFER_INTERVAL:
        if self.power_list.size < BUFFER_LENGTH:
            if self.input_data_ready_to_use is False:
                # store the power into a Buffer
                self.power_list = np.append(self.power_list, msg_power.value)
                # print(self.power_list)
        else:
            self.input_data_ready_to_use = True
            # self.last_power_stamp = current_time
           
            
            
    def vrft_pid_update(self):
        # only do the calculation when both I/O data is ready
        if self.output_data_ready_to_use and self.input_data_ready_to_use:
            y = self.minor_axis_list[np.newaxis].T # output of the plant
            u = self.power_list[np.newaxis].T       # input of the plant
            # print(y)
            # data preprocessing: remove the first
            # -----------------------------------Controller design:---------------------------------------
            # declaration of the transfer fuction of the reference model Td(z)
            # Suggestions: referer to the paper "Deterministic VRFT-PID" and use python control library to compute this reference model
            # the below TF has countinous-time counterpart: 1/0.02s+1 (backward Euler transformed)
            Td = signal.TransferFunction([0.7769], [1, -0.2231], dt=0.03) # notice that we MUST use discret format!! Do Not put continuous format here            
            # ------------------------choosing the VRFT method filter-------------------------------
            # L = signal.TransferFunction([0.7769], [1, -0.2231], dt=0.03)
            L = signal.TransferFunction([1], [1], dt=0.03)
            
            #------------------------Definition of the PID controller structure------------------------
            # Biliear transform / Backward Euler transform would be prefered discretization method
            C = [
                [signal.TransferFunction([1], [1], dt=0.03)], # P term
            #     [signal.TransferFunction([1, 1], [2, -2], dt=0.03)], # "tustin transform" for I term
                [signal.TransferFunction([1], [1, -1], dt=0.03)], # backward Euler for I term
            #     [signal.TransferFunction([1, -1], [3, -1], dt=0.03)], # D-term, "tustin" method 
            ]  # PI(D) controller structure
            
            # ----------------------MAIN function call: Compute the PID parameter----------------------
            # VRFT with least squares
            try: 
                p = vrft.design(u, y, y, Td, C, L)
                print("p=", p) # the result p will be look like: p= [[0.02602434][0.05202102]]
                if p[0,0].item() > 0 and p[1,0].item() > 0:
                    self.Kp = p[0,0].item()
                    self.Ki = p[1,0].item()
                # print(self.Ki)
                self.Kd = 0 # let Kd be zero here as D causes instability
            
                #---------------------set the parameters to the ROS param ---------------------------------
                param = self.get_pid_params() # get the updated pid parameters
                # print("parameters got")
                rospy.set_param('/control_parameters/pid_parameters', param)
                # print("parameter set")
                    
            except Exception as e: # work on python 3.x
                print('Calculation error: '+ str(e))
            
            
            self.minor_axis_list = np.array([]) # make the array empty again
            self.power_list = np.array([]) # make the buffer array empty again
            self.output_data_ready_to_use = False
            self.input_data_ready_to_use = False
        
            
            
  
    def get_pid_params(self):
        # get parameters calculated
        params = {'Kp': self.Kp,
                  'Ki': self.Ki,
                  'Kd': self.Kd}
        print(params)
        return params
    

if __name__ == '__main__':
    try:
        NdPIDVRFT()
    except rospy.ROSInterruptException:
        pass
