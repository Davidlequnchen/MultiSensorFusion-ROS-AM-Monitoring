#!/usr/bin/env python
import rospy
import numpy as np

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2


class PubCloud():
    def __init__(self):
        rospy.init_node('pub_cloud')

        cloud_topic = rospy.get_param('~cloud', '/camera/points')
        self.cloud_pub = rospy.Publisher(
            cloud_topic, PointCloud2, queue_size=5)

        r = rospy.Rate(10)
        while not rospy.is_shutdown():
            self.pub_point_cloud()
            r.sleep()

    def pub_point_cloud(self):
        stamp = rospy.Time.now()
        points3d = np.random.random((100, 3))
        points3d[:, 0] = 0.01 * points3d[:, 1]
        points3d[:, 1] = np.linspace(-0.1, 0.1, 100)
        points3d[:, 2] = 0.05 * points3d[:, 2] + 0.25
        #rospy.loginfo(points3d)
        cloud_out = PointCloud2()
        cloud_out.header.stamp = stamp
        cloud_out.header.frame_id = "/camera0"
        cloud_out = pc2.create_cloud_xyz32(cloud_out.header, points3d)
        self.cloud_pub.publish(cloud_out)


if __name__ == '__main__':
    try:
        PubCloud()
    except rospy.ROSInterruptException:
        pass
