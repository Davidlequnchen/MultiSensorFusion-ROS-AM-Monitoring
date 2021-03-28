cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
add_definitions(-std=c++14)

project(test_point_cloud_analysis)


find_package(PCL 1.7.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (test_point_cloud_analysis test_point_cloud_analysis.cpp)
target_link_libraries (test_point_cloud_analysis ${PCL_LIBRARIES})

