# Install script for directory: /home/artc/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_kuka_rsi_hw_interface/msg" TYPE FILE FILES
    "/home/artc/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/msg/MsgCartPosition.msg"
    "/home/artc/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/msg/MsgCartVelocity.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_kuka_rsi_hw_interface/cmake" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/catkin_generated/installspace/simtech_kuka_rsi_hw_interface-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/include/simtech_kuka_rsi_hw_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/roseus/ros/simtech_kuka_rsi_hw_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/common-lisp/ros/simtech_kuka_rsi_hw_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/gennodejs/ros/simtech_kuka_rsi_hw_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/artc/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/simtech_kuka_rsi_hw_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/simtech_kuka_rsi_hw_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/catkin_generated/installspace/simtech_kuka_rsi_hw_interface.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_kuka_rsi_hw_interface/cmake" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/catkin_generated/installspace/simtech_kuka_rsi_hw_interface-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_kuka_rsi_hw_interface/cmake" TYPE FILE FILES
    "/home/artc/GitHub/SIMTech_ws/build/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/catkin_generated/installspace/simtech_kuka_rsi_hw_interfaceConfig.cmake"
    "/home/artc/GitHub/SIMTech_ws/build/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/catkin_generated/installspace/simtech_kuka_rsi_hw_interfaceConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/simtech_kuka_rsi_hw_interface" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_rsi_hw_interface/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/artc/GitHub/SIMTech_ws/devel/lib/libsimtech_kuka_rsi_hw_interface.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so"
         OLD_RPATH "/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsimtech_kuka_rsi_hw_interface.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface" TYPE EXECUTABLE FILES "/home/artc/GitHub/SIMTech_ws/devel/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node"
         OLD_RPATH "/home/artc/GitHub/SIMTech_ws/devel/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface_node")
    endif()
  endif()
endif()

