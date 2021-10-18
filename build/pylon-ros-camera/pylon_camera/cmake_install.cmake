# Install script for directory: /home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/chenlequn/SIMTech_ws/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/chenlequn/SIMTech_ws/build/pylon-ros-camera/pylon_camera/catkin_generated/installspace/pylon_camera.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pylon_camera/cmake" TYPE FILE FILES
    "/home/chenlequn/SIMTech_ws/build/pylon-ros-camera/pylon_camera/catkin_generated/installspace/pylon_cameraConfig.cmake"
    "/home/chenlequn/SIMTech_ws/build/pylon-ros-camera/pylon_camera/catkin_generated/installspace/pylon_cameraConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pylon_camera" TYPE FILE FILES "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/chenlequn/SIMTech_ws/build/pylon-ros-camera/pylon_camera/catkin_generated/safe_execute_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pylon_camera/launch" TYPE DIRECTORY FILES "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/launch/" FILES_MATCHING REGEX "/[^/]*\\.launch$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pylon_camera/config" TYPE DIRECTORY FILES "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/config/" FILES_MATCHING REGEX "/[^/]*\\.yaml$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/pylon_camera/module_config" TYPE DIRECTORY FILES "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/module_config/" FILES_MATCHING REGEX "/[^/]*\\.yaml$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pylon_camera" TYPE PROGRAM FILES
    "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/scripts/file_sequencer.py"
    "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/scripts/grab_and_save_image_action_server.py"
    "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/scripts/result_bag_to_action.py"
    "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/scripts/sequence_to_file.py"
    "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/scripts/toggle_camera"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so"
         RPATH "/opt/pylon/lib:/home/chenlequn/SIMTech_ws/devel/lib:/opt/ros/melodic/lib:/usr/local/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/chenlequn/SIMTech_ws/devel/lib/libpylon_camera.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so"
         OLD_RPATH "/opt/pylon/lib:/home/chenlequn/SIMTech_ws/devel/lib:/opt/ros/melodic/lib:/usr/local/lib:"
         NEW_RPATH "/opt/pylon/lib:/home/chenlequn/SIMTech_ws/devel/lib:/opt/ros/melodic/lib:/usr/local/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libpylon_camera.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node"
         RPATH "/opt/pylon/lib:/home/chenlequn/SIMTech_ws/devel/lib:/opt/ros/melodic/lib:/usr/local/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pylon_camera" TYPE EXECUTABLE FILES "/home/chenlequn/SIMTech_ws/devel/lib/pylon_camera/pylon_camera_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node"
         OLD_RPATH "/opt/pylon/lib:/home/chenlequn/SIMTech_ws/devel/lib:/opt/ros/melodic/lib:/usr/local/lib:"
         NEW_RPATH "/opt/pylon/lib:/home/chenlequn/SIMTech_ws/devel/lib:/opt/ros/melodic/lib:/usr/local/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/pylon_camera_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera"
         RPATH "/opt/pylon/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pylon_camera" TYPE EXECUTABLE FILES "/home/chenlequn/SIMTech_ws/devel/lib/pylon_camera/write_device_user_id_to_camera")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera"
         OLD_RPATH "/opt/pylon/lib:"
         NEW_RPATH "/opt/pylon/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/write_device_user_id_to_camera")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto"
         RPATH "/opt/pylon/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pylon_camera" TYPE EXECUTABLE FILES "/home/chenlequn/SIMTech_ws/devel/lib/pylon_camera/IPConfigAuto")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto"
         OLD_RPATH "/opt/pylon/lib:"
         NEW_RPATH "/opt/pylon/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/pylon_camera/IPConfigAuto")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/pylon_camera" TYPE DIRECTORY FILES "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/pylon_camera/include/pylon_camera/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/internal$" EXCLUDE)
endif()

