cmake_minimum_required(VERSION 2.8.3)
project(microepsilon_scancontrol)

find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs std_srvs std_msgs)

find_package(Boost REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  rospy
  tf
  pcl_ros
  pcl_conversions
  message_generation
  tf2
  tf2_eigen
  tf2_ros
  geometry_msgs
  message_filters
  pcl_msgs
  rosbag
  rosconsole
  roslib
)

find_package(PCL 1.7.2 REQUIRED)

find_package (PkgConfig REQUIRED)
pkg_check_modules (ARAVIS REQUIRED aravis-0.6)

add_message_files(
  FILES
  MsgCommand.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs
)




### BUILD ###
#include_directories(common/include /usr/local/include/libllt  /usr/local/include/libmescan  ${ARAVIS_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
include_directories(common/include /usr/local/include/mescan ${ARAVIS_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
FIND_LIBRARY(LLT_LIBRARY  llt)
FIND_LIBRARY(MESCAN_LIBRARY  mescan)



catkin_package(
   #INCLUDE_DIRS common/include /usr/local/include/libllt  /usr/local/include/libmescan
   INCLUDE_DIRS common/include /usr/local/include/mescan  
   LIBRARIES ${PROJECT_NAME} ${LLT_LIBRARY} ${MESCAN_LIBRARY} SIMPLE_NODE
   CATKIN_DEPENDS roscpp sensor_msgs std_srvs std_msgs message_runtime
   DEPENDS Boost ARAVIS)



include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})



add_library(${PROJECT_NAME} common/src/${PROJECT_NAME}.cpp)
add_executable(${PROJECT_NAME}_node ros/src/${PROJECT_NAME}_node.cpp)
add_executable(${PROJECT_NAME}_node_AutoDED ros/src/${PROJECT_NAME}_node_AutoDED.cpp)  # added for AutoDED
add_executable(cloud_transformation_node ros/src/cloud_transformation_node.cpp)
target_link_libraries(cloud_transformation_node ${catkin_LIBRARIES})


add_dependencies(${PROJECT_NAME}_node ${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
add_dependencies(${PROJECT_NAME}_node_AutoDED ${PROJECT_NAME} ${catkin_EXPORTED_TARGETS}) # added for AutoDED
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${LLT_LIBRARY} ${MESCAN_LIBRARY} ${ARAVIS_LIBRARIES} )
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node ${PROJECT_NAME} ${catkin_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_node_AutoDED ${PROJECT_NAME} ${catkin_LIBRARIES}) # added for AutoDED


### INSTALL ###
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node_AutoDED
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY common/include/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  PATTERN ".svn" EXCLUDE)




# add_library(SIMPLE_NODE common/src/simple_node_src.cpp)
# add_executable(SIMPLE_NODE ros/src/Simple_Node.cpp)
# target_link_libraries(SIMPLE_NODE ${catkin_LIBRARIES} ${LLT_LIBRARY} ${MESCAN_LIBRARY} ${ARAVIS_LIBRARIES})
