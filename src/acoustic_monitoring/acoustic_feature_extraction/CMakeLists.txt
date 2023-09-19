cmake_minimum_required(VERSION 2.8.3)
project(acoustic_feature_extraction)
# ADD_COMPILE_OPTIONS(-std=c++14 )

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
  acoustic_monitoring_msgs
)

# Find Essentia
find_package(PkgConfig)
pkg_check_modules(ESSENTIA essentia)

include_directories(${ESSENTIA_INCLUDE_DIRS})


#add_message_files(FILES
#                  MsgAcoustic.msg)

# catkin_python_setup()

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp sensor_msgs std_msgs message_runtime
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(acoustic_feature_extraction_node src/acoustic_feature_extraction_node.cpp)
target_link_libraries(acoustic_feature_extraction_node ${catkin_LIBRARIES} ${ESSENTIA_LIBRARIES})
