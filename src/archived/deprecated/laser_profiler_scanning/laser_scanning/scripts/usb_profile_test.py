#!/usr/bin/env python
import rospy
import std_msgs.msg
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2, PointField
from sensor_msgs.msg import CameraInfo

from icv.calibration import CameraCalibration
from robscan.profile import Profile

#import struct
import os
import signal
import subprocess




class NdProfile():
    def __init__(self):
        rospy.init_node('pub_profile3d', anonymous=True)

        image_topic = rospy.get_param('~image', '/usb_cam/image_raw')
        cloud_topic = rospy.get_param('~cloud', '/usb_cam/cloud')
        config_file = rospy.get_param('~config', 'profile3d.yaml')
        camera_file = rospy.get_param('~config', 'runcamera.yaml')

        #peaks_topic = rospy.get_param('~peaks', '/camera/peaks')
        #self.image_pub = rospy.Publisher(peaks_topic, Image, queue_size=10)

        rospy.Subscriber(
            image_topic, Image, self.sub_image_topic, queue_size=1)

        self.sequence = 0
        self.bridge = CvBridge()
        self.pcloud = PointCloud2()

        self.cloud_pub = rospy.Publisher(
            cloud_topic, PointCloud2, queue_size=10)

        self.profile = Profile()
        self.profile.load_configuration(config_file)

        #self.camera = CameraCalibration()
        #self.camera.load_camera_parameters(camera_file)
        

        rospy.spin()

    def pub_point_cloud(self, stamp, profile3d):
        self.sequence = self.sequence + 1
        # print(profile3d)
        #translation matrix
        #translation = np.float32([0, 0.7*self.sequence, 0])

        #profile3d = np.float32([np.float32([x, y, z]) + translation for x, y, z in profile3d])
        
        #Homogenrous transformation matrices, transform the profile3d points from tool coordinate to camera, based on hand eye calibration(fixed value) (4x4)
        transform_tcp2cam = np.float32([[1.0, 0.0, 0.0, 0.0],
                                        [0.0, 1.0, 0.0, 0.0],
                                        [0.0, 0.0, 1.0, 0.0],
                                        [0.0, 0.0, 0.0, 1.0]])

        # Homogeneous transformation matrix, from world frame(base) to tool0, this is changing, (data received from robot)(4x4)
        transform_world2tcp = np.float32([[1.0, 0.0, 0.0, 0.0],
                                          [0.0, 1.0, 0.0, 0.0],
                                          [0.0, 0.0, 1.0, 0.0],
                                          [0.0, 0.0, 0.0, 1.0]])
        
        
       
        # 3D point cloud in base frame (world frame)
        profile3d_base = np.copy(profile3d)
        for i, point in enumerate(profile3d):
            #print point
            result = np.linalg.multi_dot([transform_world2tcp, transform_tcp2cam, np.float32([point[0],point[1],point[2],1.0])])
            profile3d_base[i] = np.float32([result[0],result[1], result[2]])
            
            #profile3d_base[i] = np.float32([np.linalg.multi_dot(transform_cam2tcp, np.float32([x, y, z, 1])) for x, y, z in point])
        #print profile3d_base

        

        self.pcloud = pc2.create_cloud_xyz32(self.pcloud.header, profile3d_base)
        #self.pcloud = pc2.create_cloud_xyz32(self.pcloud.header, profile3d)
        '''
        create_cloud_xyz function Create a L{sensor_msgs.msg.PointCloud2} message with 3 float32 fields (x, y, z).
        (create a instance of Header)
        @param header: The point cloud header.
        @type  header: L{std_msgs.msg.Header}
        @param points: The point cloud points.
        @type  points: iterable
        @return: The point cloud.
        @rtype:  L{sensor_msgs.msg.PointCloud2}

        A structured point cloud is a 3D grid with axes [image height, image rows, point cloud channel], 
        importantly they are sparse so can contain null points, represented as either NaN values or the zero point depending on the datatype used. 

        '''
        self.pcloud.header = std_msgs.msg.Header(
                                                 stamp=stamp,
                                                 seq=self.sequence)
        self.cloud_pub.publish(self.pcloud)

    # def image_pub_peak(self, stamp, image):
    #     image_msg = self.bridge.cv2_to_imgmsg(image, encoding='bgr8')
    #     image_msg.header.stamp = stamp
    #     self.image_pub.publish(image_msg)

    def sub_image_topic(self, data):
        try:
            #stamp = rospy.Time.now()
            image = self.bridge.imgmsg_to_cv2(data)
            #image = undistort_image(image)
            #rospy.loginfo(stamp)
            stamp = data.header.stamp
            #rospy.loginfo(stamp)
            """
            (1) points_profile:(functionality)
            Gets the laser coordinate points in the camera frame from the peak
            profile detection in the image. Projects the laser profile on a plane.

            def points_profile(self, image, homography=None, pose=None):
                profile = self.profile_points(image)
                if homography is None or pose is None:
                    points3d = self.profile_to_points3d(profile, self.homography, self.pose)
                    #points3d = self.transform_profile(profile)
                else:
                    points3d = self.profile_to_points3d(profile, homography, pose)
                return points3d, profile

            (2) This function is to get the peak profile (using center of gravity method)

            def profile_points(self, image):
                blur = cv2.blur(image, (3, 3))
                gray = self.threshold_image(blur)
                profile = self.peak_profile(gray)
            return profile

            (3) profile_to_points3d(profile, self.homography, self.pose)
              Transforms the profile image points of the laser (on the image) using
              1. the homography transformation and 
              2. the pose of the laser plane(laser plane 3D coordinate relative to the camera coordinate frame) 
              => to get the points 3D coordinates in the camera frame, we call them profile3d.

            def profile_to_points3d(self, profile, homography, pose, minz=0, maxz=1000):
                points3d = []
                if len(profile) > 0:
                    pnts = np.float32([np.dot(homography,
                                            np.float32([x, y, 1])) for x, y in profile])
                    points = np.float32([pnt / pnt[2] for pnt in pnts])
                    points3d = np.float32([np.dot(pose[0],
                                        np.float32([x, y, 0])) + pose[1] for x, y in points[:, :2]])
                    #points3d = points3d[points3d[:, 2] > minz]
                    #points3d = points3d[points3d[:, 2] < maxz]
                return points3d

            """
            
            profile3d, profile2d = self.profile.points_profile(image)
 
            
            if len(profile3d) > 0:
                self.pub_point_cloud(stamp, profile3d)
        except CvBridgeError, e:
            rospy.loginfo("CvBridge Exception")


if __name__ == '__main__':
    NdProfile()
