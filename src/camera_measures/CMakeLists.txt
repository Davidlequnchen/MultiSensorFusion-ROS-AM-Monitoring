cmake_minimum_required(VERSION 2.8.3)
project(camera_measures)

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
                   MsgGeometry.msg
                   MsgVelocity.msg
                   MsgStatus.msg
                   MsgPosition.msg
                   MsgTwist.msg
                   MsgVelocityStatus.msg
                   MsgAcceleration.msg)

catkin_python_setup()

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)


add_executable(kuka_velocity_measures_node src/kuka_velocity_measures_node.cpp)
target_link_libraries(kuka_velocity_measures_node ${catkin_LIBRARIES})
add_dependencies(kuka_velocity_measures_node ${${PROJECT_NAME}_EXPORTED_TARGETS})

include_directories(
  ${catkin_INCLUDE_DIRS}
)
