cmake_minimum_required(VERSION 2.8.3)
project(microepsilon_calibration)

find_package(catkin REQUIRED COMPONENTS
  rospy
  tf
  message_generation
  tf2
  tf2_eigen
  tf2_ros
  geometry_msgs
  message_filters
  rosbag
  rosconsole
  roslib
  roscpp
  std_msgs
  cv_bridge
  sensor_msgs
  image_transport
)

find_package(OpenCV REQUIRED)

catkin_python_setup()

include_directories(
  ${catkin_INCLUDE_DIRS},
  ${OpenCV_INCLUDE_DIRS}
)

### BUILD ###
#include_directories(common/include /usr/local/include/libllt  /usr/local/include/libmescan  ${ARAVIS_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
include_directories(common/include /usr/local/include/mescan ${ARAVIS_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
FIND_LIBRARY(LLT_LIBRARY  llt)
FIND_LIBRARY(MESCAN_LIBRARY  mescan)


# catkin_package()
catkin_package(
   #INCLUDE_DIRS common/include /usr/local/include/libllt  /usr/local/include/libmescan
   INCLUDE_DIRS common/include /usr/local/include/mescan  
   LIBRARIES ${PROJECT_NAME} ${LLT_LIBRARY} ${MESCAN_LIBRARY} 
   CATKIN_DEPENDS roscpp sensor_msgs std_srvs std_msgs
   DEPENDS Boost ARAVIS)


