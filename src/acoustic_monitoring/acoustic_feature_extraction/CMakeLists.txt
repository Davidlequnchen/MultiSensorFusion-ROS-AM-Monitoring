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
# pkg_check_modules(ESSENTIA essentia)
include_directories(${ESSENTIA_INCLUDE_DIRS})
include_directories(/usr/local/include/essentia)
include_directories(/usr/local/include/essentia/scheduler)
include_directories(/usr/local/include/essentia/streaming)
include_directories(/usr/local/include/essentia/utils)
include_directories(/usr/include/taglib)
include_directories(/usr/local/include/gaia2)
include_directories(/usr/include/qt4)
include_directories(/usr/include/qt4/QtCore)
include_directories(/usr/include/eigen3)

set(ADDITIONAL_LIBRARIES
    essentia
    fftw3
    yaml
    avcodec
    avformat
    avutil
    samplerate
    tag
    fftw3f
    # qt4
    gaia2
    chromaprint
    avresample
    swresample
)


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
target_link_libraries(acoustic_feature_extraction_node ${catkin_LIBRARIES} ${ESSENTIA_LIBRARIES} ${ADDITIONAL_LIBRARIES})
