cmake_minimum_required(VERSION 2.8.3)
project(multisense_gui)
find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  sensor_msgs
  cv_bridge
  message_generation
  acoustic_monitoring_msgs
  # opencv_apps
  audio_capture
)



catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
