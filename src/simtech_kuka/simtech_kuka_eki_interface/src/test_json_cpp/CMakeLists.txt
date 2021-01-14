cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
add_definitions(-std=c++14)

project(json_nlohmann_test)

find_package(Boost REQUIRED COMPONENTS system)


add_executable (json_test json_test.cpp)


target_link_libraries(json_test
  ${Boost_LIBRARIES}
)

