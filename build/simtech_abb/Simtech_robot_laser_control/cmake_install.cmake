# Install script for directory: /home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/david/SIMTech_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  include("/home/david/SIMTech_ws/build/simtech_abb/Simtech_robot_laser_control/catkin_generated/safe_execute_install.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Simtech_robot_laser_control/srv" TYPE FILE FILES "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Simtech_robot_laser_control/msg" TYPE FILE FILES
    "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg"
    "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg"
    "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg"
    "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg"
    "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Simtech_robot_laser_control/cmake" TYPE FILE FILES "/home/david/SIMTech_ws/build/simtech_abb/Simtech_robot_laser_control/catkin_generated/installspace/Simtech_robot_laser_control-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/david/SIMTech_ws/devel/include/Simtech_robot_laser_control")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/david/SIMTech_ws/devel/share/roseus/ros/Simtech_robot_laser_control")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/david/SIMTech_ws/devel/share/common-lisp/ros/Simtech_robot_laser_control")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/david/SIMTech_ws/devel/share/gennodejs/ros/Simtech_robot_laser_control")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/david/SIMTech_ws/devel/lib/python2.7/dist-packages/Simtech_robot_laser_control")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/david/SIMTech_ws/devel/lib/python2.7/dist-packages/Simtech_robot_laser_control")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/david/SIMTech_ws/build/simtech_abb/Simtech_robot_laser_control/catkin_generated/installspace/Simtech_robot_laser_control.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Simtech_robot_laser_control/cmake" TYPE FILE FILES "/home/david/SIMTech_ws/build/simtech_abb/Simtech_robot_laser_control/catkin_generated/installspace/Simtech_robot_laser_control-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Simtech_robot_laser_control/cmake" TYPE FILE FILES
    "/home/david/SIMTech_ws/build/simtech_abb/Simtech_robot_laser_control/catkin_generated/installspace/Simtech_robot_laser_controlConfig.cmake"
    "/home/david/SIMTech_ws/build/simtech_abb/Simtech_robot_laser_control/catkin_generated/installspace/Simtech_robot_laser_controlConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Simtech_robot_laser_control" TYPE FILE FILES "/home/david/SIMTech_ws/src/simtech_abb/Simtech_robot_laser_control/package.xml")
endif()

