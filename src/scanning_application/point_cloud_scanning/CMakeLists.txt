cmake_minimum_required(VERSION 2.8.3)
project(point_cloud_scanning)

ADD_COMPILE_OPTIONS(-std=c++11 )
ADD_COMPILE_OPTIONS(-std=c++14 )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )


find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  pcl_ros
  pcl_conversions
  sensor_msgs
  std_msgs
)

find_package(octomap REQUIRED)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

include_directories(${OCTOMAP_INCLUDE_DIRS})

link_libraries(${OCTOMAP_LIBRARIES})

catkin_python_setup()

## Declare a cpp library
# add_library(cloud src/cloud.cpp)

#add_executable(nd_talker src/nd_talker.cpp)
#target_link_libraries(nd_talker ${catkin_LIBRARIES})

add_executable(nd_height src/nd_height.cpp)
target_link_libraries(nd_height ${catkin_LIBRARIES})

#add_executable(nd_listener src/nd_listener.cpp)
#target_link_libraries(nd_listener ${catkin_LIBRARIES})

add_executable(nd_cloud src/nd_cloud.cpp)
target_link_libraries(nd_cloud ${catkin_LIBRARIES})

#add_executable(find_plane src/find_plane.cpp)
#target_link_libraries(find_plane ${catkin_LIBRARIES})
