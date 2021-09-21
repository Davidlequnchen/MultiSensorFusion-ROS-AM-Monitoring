cmake_minimum_required(VERSION 2.8.3)
project(acoustic_monitoring_msgs)

find_package(catkin REQUIRED COMPONENTS
    message_generation
    std_msgs
)


## Generate messages in the 'msg' folder
add_message_files(
  FILES
  MsgAcousticFeature.msg
  AudioDataStamped.msg
)


## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs  # Or other packages containing msgs
)
catkin_package(
  CATKIN_DEPENDS message_runtime
)


## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)