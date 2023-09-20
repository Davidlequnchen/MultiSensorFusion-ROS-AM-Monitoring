cmake_minimum_required(VERSION 2.8.3)
project(multimodal_monitoring_GUI)
find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  sensor_msgs
  message_generation
)

# add_message_files(FILES
#                    MsgDefect.msg)

# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
