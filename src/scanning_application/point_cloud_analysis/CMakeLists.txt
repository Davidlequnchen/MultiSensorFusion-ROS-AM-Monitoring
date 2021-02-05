cmake_minimum_required(VERSION 2.8.3)
project(point_cloud_analysis)
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

find_package(PCL 1.7.2 REQUIRED)

add_message_files(FILES
                   MsgPointCloudScan.msg
                   MsgHeightMonitoring.msg)

generate_messages(
  DEPENDENCIES
  std_msgs
)


ADD_DEFINITIONS      (${QT_DEFINITIONS})

catkin_package(
  CATKIN_DEPENDS roscpp sensor_msgs std_msgs message_runtime
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)


include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})


add_executable(nd_point_cloud_analysis src/nd_point_cloud_analysis.cpp)
target_link_libraries(nd_point_cloud_analysis ${catkin_LIBRARIES})
