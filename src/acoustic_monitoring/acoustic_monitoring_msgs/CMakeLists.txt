cmake_minimum_required(VERSION 2.8.3)
project(acoustic_monitoring_msgs)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    message_generation
    std_msgs
    message_filters
    sensor_msgs
)


## Generate messages in the 'msg' folder
add_message_files(
  FILES
  MsgAcousticFeature.msg
  AudioDataStamped.msg
  MsgAcousticFeaturePython.msg
)


## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp sensor_msgs std_msgs message_runtime
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)