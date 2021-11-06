cmake_minimum_required(VERSION 2.8.3)
project(simtech_kuka_rsi_hw_interface)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  controller_manager
  hardware_interface
  joint_limits_interface
  realtime_tools
  roscpp
  std_msgs
  message_generation
)

find_package(Boost REQUIRED COMPONENTS system)
find_package(TinyXML REQUIRED)


add_message_files(FILES
                  MsgCartPosition.msg
                  MsgCartVelocity.msg)

generate_messages(
                  DEPENDENCIES
                  std_msgs
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    simtech_kuka_rsi_hw_interface
  CATKIN_DEPENDS
    controller_manager
    hardware_interface
    joint_limits_interface
    roscpp
    std_msgs
    message_runtime
  DEPENDS
    TinyXML
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${TinyXML_INCLUDE_DIRS}
)

add_library(simtech_kuka_rsi_hw_interface
  src/simtech_kuka_rsi_hw_interface.cpp
)

target_link_libraries(simtech_kuka_rsi_hw_interface
  ${catkin_LIBRARIES}
  ${Boost_LIBRARIES}
  ${TinyXML_LIBRARIES}
)

add_executable(simtech_kuka_rsi_hw_interface_node
  src/simtech_kuka_rsi_hw_interface_node.cpp
)

target_link_libraries(simtech_kuka_rsi_hw_interface_node
simtech_kuka_rsi_hw_interface
)

add_dependencies(simtech_kuka_rsi_hw_interface_node ${${PROJECT_NAME}_EXPORTED_TARGETS})

install(
  TARGETS simtech_kuka_rsi_hw_interface
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})

install(
  TARGETS simtech_kuka_rsi_hw_interface_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
