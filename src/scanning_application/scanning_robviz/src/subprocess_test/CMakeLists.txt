cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
add_definitions(-std=c++14)

project(subprocess_test)



add_executable (subprocess_test subprocess_test.cpp)
target_link_libraries (subprocess_test)

