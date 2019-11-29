#!/usr/bin/env python
import pcl
import pcl.pcl_visualization
import os
import glob
import yaml
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

        # cloud_topic = rospy.get_param('~cloud', '/usb_cam/cloud')
        
        # create a pcl object
        self.pcl_data= pcl.PointCloud()

        self.stamp = rospy.Time.now().secs  #current time in seconds
        #self.interval = 5.0
        self.interval = rospy.Duration(10) # ten seconds duration
        self.points_list = [] #list for storing PCL XYZ, reinitialized in every loop

        # create a subscriber to subscribe point cloud message(after statistical filtering), with a call back function
        # rospy.Subscriber(
        #     '/usb_cam/cloud', PointCloud2, self.sub_cloud_topic, queue_size=10)
        rospy.Subscriber(
            '/statistical_outlier_removal/output', PointCloud2, self.sub_cloud_topic, queue_size=10)


        
        # self.visual = pcl.pcl_visualization.CloudViewing()
        # v = True
        # while v:
        #     v = not(self.visual.WasStopped())
    
        rospy.spin()




    def sub_cloud_topic(self, data):
        """ Converts a ROS PointCloud2 message to a pcl PointXYZ
            Args:
                data (PointCloud2): ROS PointCloud2 message
            Returns:
                pcl.PointCloud: PCL XYZ point cloud saved into a pcd file
        """
       
        #stamp = data.header.stamp.secs # current time of the message
        stamp = rospy.Time.now().secs
        # loop to save all points(xyz) from point cloud message into a list 
        # in every interval(5 seconds default)
        while (stamp - self.stamp < self.interval):
            # read all the points(x,y,z) from PointCloud2 and store them in a list
            for points in pc2.read_points(data, field_names = ("x", "y", "z"), skip_nans=True):
            #for points in pc2.read_points(data):
                #self.points_list.append([points[0], points[1], points[2]]) #append xyz to list
                self.points_list.append(points) #append xyz to list
        
        self.pcd_file = str(self.stamp) + ".pcd"

        if(len(self.points_list) > 0):
            self.pcl_data.from_list(self.points_list) # get the points from the list
            self.pcl_data.to_file(self.pcd_file)# store the data into a pcd file
        else:
            logging.info("no point cloud data stored in the list")


        #self.save_pointCloud(os.path.join(path, 'pcl', self.pcd_file))
        
        self.stamp = stamp
        self.points_list = []
        self.pcd_processed_file = str(self.stamp) +"segmented.pcd"
        

        
        #----subprocess for segmentation program----
        # define the executable program and set all the parameters here
        command_line = "/home/david/SIMTech_ws/src/RT_monitoring_application/Point_cloud_visualziation/PCLFIltering_Tool/build/PCLFiltering_tool \
                       -load " + self.pcd_file + "-ShapeSeg -DistanceThre 0.003 \
                        -Stddev 1.0 -save " + self.pcd_processed_file
        args = shlex.split(command_line)
        print(args)
        p = subprocess.Popen(args, stdout=subprocess.PIPE,stderr=subprocess.STDOUT) 
        
        
        # self.visual.ShowMonochromeCloud(self.pcl_data, b'cloud')
        #self.p = pcl.PointCloud(10)  # "empty" point cloud

        
       
       
    def save_pointCloud(self, filename):
        data = self.points_list
        with open(filename, 'w') as f:
            for point in data:
                f.write(str(point) + '\n')


      
if __name__ == '__main__':
    NdPCLHandler()