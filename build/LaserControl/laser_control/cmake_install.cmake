# Install script for directory: /home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/yaoxl/Documents/GitHub/SIMTech_ws/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/laser_control/msg" TYPE FILE FILES
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control/msg/MsgPower.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control/msg/MsgStart.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control/msg/MsgControl.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control/msg/MsgInfo.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control/msg/MsgEmission.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/laser_control/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/laser_control/cmake" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/laser_control/catkin_generated/installspace/laser_control-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/include/laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/share/roseus/ros/laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/share/common-lisp/ros/laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/share/gennodejs/ros/laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/lib/python2.7/dist-packages/laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/lib/python2.7/dist-packages/laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/laser_control/catkin_generated/installspace/laser_control.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/laser_control/cmake" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/laser_control/catkin_generated/installspace/laser_control-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/laser_control/cmake" TYPE FILE FILES
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/laser_control/catkin_generated/installspace/laser_controlConfig.cmake"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/laser_control/catkin_generated/installspace/laser_controlConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/laser_control" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/laser_control/package.xml")
endif()

