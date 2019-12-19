# Install script for directory: C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/MI/Desktop/Github/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/srv" TYPE FILE FILES "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/srv/SrvRobotCommand.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/msg" TYPE FILE FILES
    "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/msg/MsgPower.msg"
    "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/msg/MsgStart.msg"
    "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/msg/MsgControl.msg"
    "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/msg/MsgInfo.msg"
    "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/msg/MsgEmission.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/cmake" TYPE FILE FILES "C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_control-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "C:/Users/MI/Desktop/Github/devel/include/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "C:/Users/MI/Desktop/Github/devel/share/roseus/ros/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "C:/Users/MI/Desktop/Github/devel/share/common-lisp/ros/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "C:/Users/MI/Desktop/Github/devel/share/gennodejs/ros/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "C:/Opt/python27amd64/python.exe" -m compileall "C:/Users/MI/Desktop/Github/devel/lib/site-packages/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/site-packages" TYPE DIRECTORY FILES "C:/Users/MI/Desktop/Github/devel/lib/site-packages/simtech_robot_laser_control")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_control.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/cmake" TYPE FILE FILES "C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_control-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control/cmake" TYPE FILE FILES
    "C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_controlConfig.cmake"
    "C:/Users/MI/Desktop/Github/build/simtech_abb/simtech_robot_laser_control/catkin_generated/installspace/simtech_robot_laser_controlConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_robot_laser_control" TYPE FILE FILES "C:/Users/MI/Desktop/Github/src/simtech_abb/simtech_robot_laser_control/package.xml")
endif()

