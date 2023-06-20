#include <ros/ros.h>

#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>

#include <tf/transform_listener.h>


class NdCloud {
private:
  ros::NodeHandle nh;
  ros::Subscriber sub_cloud;
  ros::Publisher pub_cloud;

  tf::TransformListener *tf_listener;
  tf::StampedTransform transform;

  Eigen::Matrix4f matrix;
  Eigen::Matrix4f matrix1;
  Eigen::Matrix4f matrix2;
public:
  typedef pcl::PointXYZ Point;
  typedef pcl::PointCloud<Point> PointCloud;

  NdCloud() {
    sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("/arm/laser_scan", 5,  &NdCloud::cbPointCloud, this);

    pub_cloud = nh.advertise<sensor_msgs::PointCloud2>("laser_scan_transformed", 50);

    tf_listener = new tf::TransformListener();
  }

  ~NdCloud() {}

  void cbPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
    // PointCloud cloud;
    // pcl::fromROSMsg(*cloud_msg, cloud);

    try {
      sensor_msgs::PointCloud2 cloud_out;

      // ROS_INFO_STREAM("Frame_id: " << (*cloud_msg).header.frame_id);
      // ROS_INFO_STREAM("Stamp: " << (*cloud_msg).header.stamp);
      // ROS_INFO_STREAM("Time: " << ros::Time::now());

      ros::Time stamp = (*cloud_msg).header.stamp;
      tf_listener->waitForTransform("/world", "/mill_tool_mill_laser_origin_link", stamp, ros::Duration(1.0));
      tf_listener->lookupTransform("/world", "/mill_tool_mill_laser_origin_link", stamp, transform);
      pcl_ros::transformAsMatrix(transform, matrix1); 
      // matrix1 is the transformation(trans, rot) between world frame and camera frame
      tf_listener->waitForTransform("/world", "/workobject", stamp, ros::Duration(1.0));
      tf_listener->lookupTransform("/world", "/workobject", stamp, transform);
      pcl_ros::transformAsMatrix(transform, matrix2);
      matrix = matrix2.inverse() * matrix1;
      // the matrix calculated based on matrix1 and matrix2 is the transformation matrix from workobject to camera0
      pcl_ros::transformPointCloud(matrix, *cloud_msg, cloud_out);
      // Transform a sensor_msgs::PointCloud2 dataset using an Eigen 4x4 matrix.
      ROS_INFO_STREAM("Transform:" << matrix);

      cloud_out.header.frame_id = "/workobject";
      pub_cloud.publish(cloud_out);
    } catch (tf::TransformException ex) {
      ROS_ERROR("%s",ex.what());
    }

    // sensor_msgs::PointCloud2 output;
    // pcl::toROSMsg(cloud, output);
    // pub_cloud.publish(output);
  }
};


int main (int argc, char** argv) {
  ros::init(argc, argv, "microEpsilon_scanning_transform");

  NdCloud nd_cloud;

  ros::spin();
}
