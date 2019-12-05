#!/usr/bin/env python
import pcl
import pcl.pcl_visualization
import os
import rospkg
import rospy
import std_msgs.msg
import numpy as np

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2

import os
import logging
import signal
import subprocess
import shlex

rospack = rospkg.RosPack()
path = rospack.get_path('scanning_robviz')


class NdPCLHandler():
    def __init__(self):
        rospy.init_node('pcl_subprocess_handler', anonymous=True)
        
        # create a pcl object
        self.pcl_data = pcl.PointCloud()
       

        self.stamp = rospy.Time.now()  #current time 
        
        self.interval = rospy.Duration(5) # duration between each subprocess

        
        self.points_list = [] #list for storing PCL XYZ for each subprocess
        
        # create a subscriber to subscribe point cloud message(after statistical filtering), with a call back function
        rospy.Subscriber(
            '/usb_cam/scan', PointCloud2, self.sub_cloud_topic, queue_size=10)
        # rospy.Subscriber(
        #     '/statistical_outlier_removal/output', PointCloud2, self.sub_cloud_topic, queue_size=10)

        self.visual = pcl.pcl_visualization.CloudViewing()
        v = True
        while v:
            v = not(self.visual.WasStopped())
    
        rospy.spin()




    def sub_cloud_topic(self, data):
        """ Converts a ROS PointCloud2 message to a pcl PointXYZ
            Args:
                data (PointCloud2): ROS PointCloud2 message
            Returns:
                pcl.PointCloud: PCL XYZ point cloud saved into a pcd file
        """
  
        stamp = rospy.Time.now() # current time of the message
        
        self.pcd_file = str(self.stamp) + ".pcd"
        self.pcd_processed_file = str(self.stamp) +"segmented.pcd"
        
        
        # loop to save all points(xyz) from point cloud message into a list 
        # in every interval(5 seconds default)
        if (stamp - self.stamp < self.interval):
            # read all the points(x,y,z) from PointCloud2 and store them in a list
            for points in pc2.read_points(data, skip_nans=False):
                self.points_list.append(points) #append xyz to list
            # for points in pc2.read_points(data):
            #     self.points_list.append([points[0], points[1], points[2]]) #append xyz to list
               
        else: 
            # if(len(self.points_list) > 0):
            self.pcl_data.from_list(self.points_list) # get the points from the list
            self.pcl_data.to_file(os.path.join(path, 'pcl', self.pcd_file))# store the data into a pcd file
            # else:
            #     logging.info("no point cloud data stored in the list")
            
            
            #----subprocess for segmentation program-----------------------------------------
            # define the executable program and set all the parameters here
            #Usage: ./PCL_segmentation [options] [-load filename] [-save filename] [-leafsize /float] [-DistanceThre /float] [-Stddev /float]
            executable = os.path.join(path, 'PCL_segmentation/build', "PCL_segmentation")
            option = " -multiPlannarSeg" # other options: -NormalSegmentation, -largestPlane, -ShapeSeg, -sfilter
            loadfile = " -load " + os.path.join(path, 'pcl', self.pcd_file)
            savefile = " -save " + os.path.join(path, 'pcl', self.pcd_processed_file)
            parameters = " -DistanceThre 0.003 -Stddev 1.0"

            command_line =  executable + option + loadfile + savefile + parameters
            args = shlex.split(command_line) 
            #p = subprocess.Popen(args)
            subprocess.call(args)
            #------------subprocess end------------------------------------------------------
          
            try:
                self.seg_data = pcl.load(os.path.join(path, 'pcl', self.pcd_processed_file)) 
                self.visual.ShowMonochromeCloud(self.seg_data, b'cloud')
            
                #----subprocess for visualizing the segmented cloud--------------------------------------
                # command line call the pcd_to_pointcloud node: $ rosrun pcl_ros pcd_to_pointcloud <file.pcd> [ <interval> ]
                ros_command = "rosrun pcl_ros pcd_to_pointcloud "
                pcdFile = os.path.join(path, 'pcl', self.pcd_processed_file)
                interval = " 0.1 " # publish 10 times a second, If <interval> is zero or not specified the message is published once. 
                frame = " _frame_id:=/workobject"

                command = ros_command + pcdFile + interval + frame
                arg = shlex.split(command)
                s = subprocess.Popen(arg)
                #------------subprocess end---------------------------------------------------
            
            except:
                self.seg_data = pcl.load(os.path.join(path, 'empty', "empty_cloud.pcd"))
                self.visual.ShowMonochromeCloud(self.seg_data, b'cloud')
            
                #----subprocess for visualizing the segmented cloud--------------------------------------
                # command line call the pcd_to_pointcloud node: $ rosrun pcl_ros pcd_to_pointcloud <file.pcd> [ <interval> ]
                ros_command = "rosrun pcl_ros pcd_to_pointcloud "
                pcdFile = os.path.join(path, 'empty', "empty_cloud.pcd")
                interval = " 0.1 " # publish 10 times a second, If <interval> is zero or not specified the message is published once. 
                frame = " _frame_id:=/workobject"

                command = ros_command + pcdFile + interval + frame
                arg = shlex.split(command)
                s = subprocess.Popen(arg)
                #------------subprocess end---------------------------------------------------

             


            self.stamp = rospy.Time.now() #stamp
            self.points_list = []
            #self.points_array = np.array([0,0,0], dtype=np.float32 )
            

      
if __name__ == '__main__':
    NdPCLHandler()