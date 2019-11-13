# cmake needs this line
cmake_minimum_required(VERSION 2.8)

project(pcl_find_plane)

find_package(PCL 1.2 REQUIRED)
find_package(OpenCV REQUIRED)

if(CMAKE_VERSION VERSION_LESS "2.8.11")
  # Add OpenCV headers location to your include paths
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (find_plane find_plane.cpp)
target_link_libraries (find_plane ${PCL_LIBRARIES})
