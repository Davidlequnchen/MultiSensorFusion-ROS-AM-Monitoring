# Install script for directory: /home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/infratec_image_processing/msg" TYPE FILE FILES
    "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg"
    "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg"
    "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg"
    "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg"
    "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg"
    "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/TemperatureFeature.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/infratec_image_processing/cmake" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/Infratec_thermal_camera/Infratec_image_processing/catkin_generated/installspace/infratec_image_processing-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/include/infratec_image_processing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/roseus/ros/infratec_image_processing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/common-lisp/ros/infratec_image_processing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/share/gennodejs/ros/infratec_image_processing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/artc/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/infratec_image_processing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/artc/GitHub/SIMTech_ws/devel/lib/python3/dist-packages/infratec_image_processing")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/Infratec_thermal_camera/Infratec_image_processing/catkin_generated/installspace/infratec_image_processing.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/infratec_image_processing/cmake" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/build/Infratec_thermal_camera/Infratec_image_processing/catkin_generated/installspace/infratec_image_processing-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/infratec_image_processing/cmake" TYPE FILE FILES
    "/home/artc/GitHub/SIMTech_ws/build/Infratec_thermal_camera/Infratec_image_processing/catkin_generated/installspace/infratec_image_processingConfig.cmake"
    "/home/artc/GitHub/SIMTech_ws/build/Infratec_thermal_camera/Infratec_image_processing/catkin_generated/installspace/infratec_image_processingConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/infratec_image_processing" TYPE FILE FILES "/home/artc/GitHub/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/package.xml")
endif()

