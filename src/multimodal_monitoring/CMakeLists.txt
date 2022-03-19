cmake_minimum_required(VERSION 2.8.3)
project(multimodal_monitoring)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
