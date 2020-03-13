cmake_minimum_required(VERSION 2.8.3)
project(defects_identification)
add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  pcl_ros
  pcl_conversions
  sensor_msgs
  message_generation
  tf2
  tf2_eigen
  tf2_ros
  geometry_msgs
  message_filters
  pcl_msgs
  rosbag
  rosconsole
  roslib
)

add_message_files(
  FILES
  MsgDefects.msg
  MsgPointHeight.msg
)


generate_messages(
  DEPENDENCIES
  std_msgs
)

find_package(PCL 1.7.2 REQUIRED)


catkin_package(
  CATKIN_DEPENDS message_runtime
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)


include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})



