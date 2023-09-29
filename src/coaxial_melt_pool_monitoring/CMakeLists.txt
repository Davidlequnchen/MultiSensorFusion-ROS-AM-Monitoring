cmake_minimum_required(VERSION 2.8.3)
project(coaxial_melt_pool_monitoring)

find_package(catkin REQUIRED COMPONENTS
  tf
  rospy
  roscpp
  std_msgs
  cv_bridge
  sensor_msgs
  image_transport
  message_generation
)

add_message_files(FILES
                  MsgCoaxialMeltPoolFeatures.msg)

# catkin_python_setup()

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)


add_executable(coaxial_meltpool_feature_extraction_node src/coaxial_meltpool_feature_extraction_node.cpp)
target_link_libraries(coaxial_meltpool_feature_extraction_node ${catkin_LIBRARIES})
add_dependencies(coaxial_meltpool_feature_extraction_node ${${PROJECT_NAME}_EXPORTED_TARGETS})

include_directories(
  ${catkin_INCLUDE_DIRS}
)
