cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
add_definitions(-std=c++14)

project(pcl_simple_visualizer)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (pcl_simple_visualizer pcl_simple_visualizer.cpp)
target_link_libraries (pcl_simple_visualizer ${PCL_LIBRARIES})

