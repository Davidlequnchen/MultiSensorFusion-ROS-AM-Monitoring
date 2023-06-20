# Install script for directory: /home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/artc/GitHub/SIMTech_ws/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_msgs/msg" TYPE FILE FILES
    "/home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs/msg/ModelCoefficients.msg"
    "/home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs/msg/PointIndices.msg"
    "/home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs/msg/PolygonMesh.msg"
    "/home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs/msg/Vertices.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_msgs/srv" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs/srv/UpdateFilename.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_msgs/cmake" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/ROS_utils/ROS_perception/pcl_msgs/catkin_generated/installspace/pcl_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/include/pcl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/roseus/ros/pcl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/common-lisp/ros/pcl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/gennodejs/ros/pcl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/artc/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/pcl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/pcl_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/ROS_utils/ROS_perception/pcl_msgs/catkin_generated/installspace/pcl_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_msgs/cmake" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/ROS_utils/ROS_perception/pcl_msgs/catkin_generated/installspace/pcl_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_msgs/cmake" TYPE FILE FILES
    "/home/artc/GitHub/SIMTech_ws/build/ROS_utils/ROS_perception/pcl_msgs/catkin_generated/installspace/pcl_msgsConfig.cmake"
    "/home/artc/GitHub/SIMTech_ws/build/ROS_utils/ROS_perception/pcl_msgs/catkin_generated/installspace/pcl_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pcl_msgs" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/src/ROS_utils/ROS_perception/pcl_msgs/package.xml")
endif()

