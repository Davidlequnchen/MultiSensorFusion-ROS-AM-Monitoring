cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
add_definitions(-std=c++11)

project(boost_cpp_socket_example)

find_package(Boost REQUIRED COMPONENTS system)


add_executable (client_socket client_socket.cpp)
add_executable (server_socket server_socket.cpp)

target_link_libraries(client_socket
  ${Boost_LIBRARIES}
)
target_link_libraries(server_socket
  ${Boost_LIBRARIES}
)
