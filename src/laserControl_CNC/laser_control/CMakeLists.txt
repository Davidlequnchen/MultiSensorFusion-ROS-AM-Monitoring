cmake_minimum_required(VERSION 2.8.3)
project(laser_control)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  sensor_msgs
  message_generation
)

add_message_files(
  FILES
  MsgPower.msg
  MsgStart.msg
  MsgControl.msg
  MsgInfo.msg
  MsgEmission.msg
)

catkin_python_setup()

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
