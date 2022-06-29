# Install script for directory: /home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/msg" TYPE FILE FILES
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgGeometry.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgVelocity.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgStatus.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgPosition.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgTwist.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgVelocityStatus.msg"
    "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/msg/MsgAcceleration.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/lequn/Documents/GitHub/SIMTech_ws/build/camera_measures/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/cmake" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/build/camera_measures/catkin_generated/installspace/camera_measures-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/include/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/share/roseus/ros/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/share/common-lisp/ros/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/share/gennodejs/ros/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/lequn/Documents/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/lequn/Documents/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/camera_measures")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/build/camera_measures/catkin_generated/installspace/camera_measures.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/cmake" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/build/camera_measures/catkin_generated/installspace/camera_measures-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures/cmake" TYPE FILE FILES
    "/home/lequn/Documents/GitHub/SIMTech_ws/build/camera_measures/catkin_generated/installspace/camera_measuresConfig.cmake"
    "/home/lequn/Documents/GitHub/SIMTech_ws/build/camera_measures/catkin_generated/installspace/camera_measuresConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/camera_measures" TYPE FILE FILES "/home/lequn/Documents/GitHub/SIMTech_ws/src/camera_measures/package.xml")
endif()

