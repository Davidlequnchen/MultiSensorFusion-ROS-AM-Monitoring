# Install script for directory: /home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lequn/Documents/GitHub/SIMTech_ws/install")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/lequn/Documents/GitHub/SIMTech_ws/build/simtech_robot_laser_control/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/srv" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/srv/SrvRobotCommand.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/msg" TYPE FILE FILES
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/msg/MsgPower.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/msg/MsgStart.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/msg/MsgControl.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/msg/MsgInfo.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/msg/MsgEmission.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/msg/MsgSetpoint.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/cmake" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/build/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_control-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/include/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/share/roseus/ros/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/share/common-lisp/ros/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/share/gennodejs/ros/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/lequn/Documents/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/build/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_control.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/cmake" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/build/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_control-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/cmake" TYPE FILE FILES
    "/home/lequn/Documents/GitHub/SIMTech_ws/build/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_controlConfig.cmake"
    "/home/lequn/Documents/GitHub/SIMTech_ws/build/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_controlConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_robot_laser_control/package.xml")
endif()

