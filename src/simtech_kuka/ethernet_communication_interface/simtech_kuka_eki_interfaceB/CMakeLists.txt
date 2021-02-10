cmake_minimum_required(VERSION 2.8.3)
project(simtech_kuka_eki_interfaceB)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  angles
  cmake_modules
  controller_manager
  hardware_interface
  joint_limits_interface
  roscpp
  std_msgs
  message_generation
)

find_package(Boost REQUIRED COMPONENTS system)
find_package(TinyXML REQUIRED)

add_service_files(
  FILES
  SrvRobotCommand.srv
)


generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS
    include
  LIBRARIES
    simtech_kuka_eki_interfaceB
  CATKIN_DEPENDS
    controller_manager
    hardware_interface
    joint_limits_interface
    roscpp
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


add_library(simtech_kuka_eki_interfaceB
  src/simtech_kuka_eki_interfaceB.cpp
)


target_link_libraries(simtech_kuka_eki_interfaceB
  ${catkin_LIBRARIES}
  ${Boost_LIBRARIES}
  ${TinyXML_LIBRARIES}
)


add_executable(simtech_kuka_eki_interfaceB_node
  src/simtech_kuka_eki_interfaceB_node.cpp
)


target_link_libraries(simtech_kuka_eki_interfaceB_node
  simtech_kuka_eki_interfaceB
)



install(
  TARGETS simtech_kuka_eki_interfaceB
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})

install(
  TARGETS simtech_kuka_eki_interfaceB_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

