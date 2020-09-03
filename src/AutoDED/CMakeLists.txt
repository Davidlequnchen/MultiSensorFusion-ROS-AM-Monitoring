cmake_minimum_required(VERSION 2.8.3)
project(auto_control)


find_package(catkin REQUIRED COMPONENTS
  rospy
  std_msgs
  roscpp
  message_generation
  std_msgs
)


catkin_python_setup()

add_message_files(
  FILES
  MsgCommand.msg
)


generate_messages(
  DEPENDENCIES
  std_msgs
)


catkin_package(
  CATKIN_DEPENDS rospy std_msgs message_runtime
)


include_directories(
  ${catkin_INCLUDE_DIRS}
)

