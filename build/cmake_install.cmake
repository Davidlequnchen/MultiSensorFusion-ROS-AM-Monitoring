# Install script for directory: /home/chenlequn/SIMTech_ws/src

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
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chenlequn/SIMTech_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/chenlequn/SIMTech_ws/install" TYPE PROGRAM FILES "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chenlequn/SIMTech_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/chenlequn/SIMTech_ws/install" TYPE PROGRAM FILES "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chenlequn/SIMTech_ws/install/setup.bash;/home/chenlequn/SIMTech_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/chenlequn/SIMTech_ws/install" TYPE FILE FILES
    "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/setup.bash"
    "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chenlequn/SIMTech_ws/install/setup.sh;/home/chenlequn/SIMTech_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/chenlequn/SIMTech_ws/install" TYPE FILE FILES
    "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/setup.sh"
    "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chenlequn/SIMTech_ws/install/setup.zsh;/home/chenlequn/SIMTech_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/chenlequn/SIMTech_ws/install" TYPE FILE FILES
    "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/setup.zsh"
    "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/chenlequn/SIMTech_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/chenlequn/SIMTech_ws/install" TYPE FILE FILES "/home/chenlequn/SIMTech_ws/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/chenlequn/SIMTech_ws/build/gtest/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/image_pipeline/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/vision_opencv/opencv_tests/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/perception_pcl/perception_pcl/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/simtech_abb/simtech/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/simtech_abb/simtech_abb/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/vision_opencv/vision_opencv/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/microEpsilon_scanControl/microepsilon_workcell/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/monitoring/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/scanning_application/monitoring_json/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/camera_calibration/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/scanning_application/scanning_workcell/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/simtech_moveit_config/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/simtech_abb/simtech_workcell/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/vision_opencv/cv_bridge/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/Laser_calibration/calib_ros_run/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/Laser_calibration/calib_ros_test/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/vision_opencv/image_geometry/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/image_proc/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/image_publisher/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/laserControl_CNC/laser_control/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/laser_scanning/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/pcl_msgs/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/perception_pcl/pcl_conversions/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/simtech_abb/simtech_driver/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/simtech_robot_laser_control/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/image_view/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/stereo_image_proc/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/depth_image_proc/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/camera_measures/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/perception_pcl/pcl_ros/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/defects_identification/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/microEpsilon_scanControl/microepsilon_calibration/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/microEpsilon_scanControl/microepsilon_scancontrol/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/scanning_application/point_cloud_scanning/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/scanning_application/scanning_robviz/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/image_pipeline/image_rotate/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/ROS_perception/usb_cam/cmake_install.cmake")
  include("/home/chenlequn/SIMTech_ws/build/velocity_control/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/chenlequn/SIMTech_ws/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
