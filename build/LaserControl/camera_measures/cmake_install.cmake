# Install script for directory: /home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/msg" TYPE FILE FILES
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/msg/MsgGeometry.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/msg/MsgVelocity.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/msg/MsgStatus.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/msg/MsgPosition.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/msg/MsgTwist.msg"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/msg/MsgVelocityStatus.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/camera_measures/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/cmake" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/camera_measures/catkin_generated/installspace/camera_measures-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/include/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/share/roseus/ros/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/share/common-lisp/ros/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/share/gennodejs/ros/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/lib/python2.7/dist-packages/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/devel/lib/python2.7/dist-packages/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/camera_measures/catkin_generated/installspace/camera_measures.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/cmake" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/camera_measures/catkin_generated/installspace/camera_measures-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/cmake" TYPE FILE FILES
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/camera_measures/catkin_generated/installspace/camera_measuresConfig.cmake"
    "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/LaserControl/camera_measures/catkin_generated/installspace/camera_measuresConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures" TYPE FILE FILES "/home/yaoxl/Documents/GitHub/SIMTech_ws/src/LaserControl/camera_measures/package.xml")
endif()

