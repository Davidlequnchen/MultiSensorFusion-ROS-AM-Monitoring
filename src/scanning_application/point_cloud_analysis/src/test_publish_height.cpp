/*
Created by Chen Lequn
This program will analyze the point cloud produced by micro-epsilon sensor.
After each scanning, it will read the segmented point cloud file and other 
information such as plane coefficient.
The point cloud data are preprocessed by "scanning_robviz" node

Input:
- first scanning - reference substrate plane (segmentedCloud_0.pcd, coefficientPlane_0.pcd)
- from second scanning onwards: (segmentedCloud_x.pcd, coefficientPlane_x.pcd ) 

Output:
- height data file - the distance from scanned plane to the substrate reference plane
- Standard deviation of the height
- deviation from scanned plane coordinate with reference substrate frame 

Functionality:
- apply voxel grid filter to reduce the number of point for the pcd from second scanning onwards
- calculate point to reference plane (substrate) distance for each point in the cloud -- height data
- caluclate standard deiviations of the distance
- check if the difference between reference frame and scanned plane is too large
- future development: 1. check the height data with CAD model　2. ROS publisher: height -overbuild, underbuild, ok

ROS:
- publisher:

- subscribe:


*/


#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>

#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/common/common_headers.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/features/normal_3d.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/common.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_line.h>
#include <pcl/filters/extract_indices.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/pcd_io.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>

// include the created message
#include <point_cloud_analysis/MsgPointCloudScan.h>  
#include <point_cloud_analysis/MsgHeightMonitoring.h>  

#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iostream> //std::cout
#include <string>  //std::string, std::to_string




std::string path_robviz = ros::package::getPath("scanning_robviz");
std::string path_point_cloud_analysis = ros::package::getPath("point_cloud_analysis");

typedef pcl::PointXYZ Point;
typedef pcl::PointCloud<Point> PointCloud;


/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "height_publisher");

  ros::NodeHandle nh;

  // ROS pubisher
  ros::Publisher pub_height_monitoring_info = nh.advertise<point_cloud_analysis::MsgHeightMonitoring>("/height_monitoring_info", 10);

  ros::Rate loop_rate(10);

  
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */

    point_cloud_analysis::MsgHeightMonitoring height_info;

    height_info.plane_id = 1;
    height_info.height_std = 0.232;
    height_info.height_mean = 5.123;
    height_info.heighest_max_min_difference = 2.0;
    height_info.tilt_angle = 12.5;
    
    pub_height_monitoring_info.publish(height_info);


    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}





