cmake_minimum_required(VERSION 2.8.3)
project(acoustic_feature_extraction)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  cv_bridge
  sensor_msgs
  image_transport
  message_generation
  audio_capture
  rospy
)


#add_message_files(FILES
#                  MsgAcoustic.msg)

# catkin_python_setup()

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
