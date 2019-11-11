#!/usr/bin/env python
import tf
import rospy
import numpy as np

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2


class NdCloud():
    def __init__(self):
        rospy.init_node('cloud')

        rospy.Subscriber(
            '/ueye/cloud', PointCloud2, self.cb_point_cloud, queue_size=5)

        self.pub_cloud = rospy.Publisher(
            '/ueye/scan', PointCloud2, queue_size=1)

        self.listener = tf.TransformListener()

        rospy.spin()

    def transform_point_cloud(self, matrix, cloud):
        points = np.hstack((cloud, np.ones((len(cloud), 1))))
        cloud = np.float32([np.dot(matrix, point)[:3] for point in points])
        return cloud

    def transform_matrix(self, target, source, stamp):
        self.listener.waitForTransform(
            target, source, stamp, rospy.Duration(1.0))
        (position, quaternion) = self.listener.lookupTransform(
            target, source, stamp)
        matrix = tf.transformations.quaternion_matrix(quaternion)
        matrix[:3, 3] = position
        return matrix

    def cb_point_cloud(self, msg_cloud):
        try:
            stamp = msg_cloud.header.stamp
            points = pc2.read_points(msg_cloud, skip_nans=False)
            points3d = np.float32([point for point in points])
            matrix1 = self.transform_matrix('/base_link', '/camera0', stamp)
            matrix2 = self.transform_matrix('/base_link', '/workobject', stamp)
            matrix = np.dot(np.linalg.inv(matrix2), matrix1)
            points3d = self.transform_point_cloud(matrix, points3d)
            # rospy.loginfo(points3d)
            cloud_out = PointCloud2()
            cloud_out.header.stamp = stamp
            cloud_out.header.frame_id = "/workobject"
            cloud_out = pc2.create_cloud_xyz32(cloud_out.header, points3d)
            self.pub_cloud.publish(cloud_out)
        except tf.Exception as error:
            print error


if __name__ == '__main__':
    try:
        NdCloud()
    except rospy.ROSInterruptException:
        pass
