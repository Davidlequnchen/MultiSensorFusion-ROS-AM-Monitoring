# Install script for directory: /home/david/SIMTech_ws/src/Monitoring/moveit_actions

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/david/SIMTech_ws/install")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/david/SIMTech_ws/build/Monitoring/moveit_actions/catkin_generated/installspace/moveit_actions.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_actions/cmake" TYPE FILE FILES
    "/home/david/SIMTech_ws/build/Monitoring/moveit_actions/catkin_generated/installspace/moveit_actionsConfig.cmake"
    "/home/david/SIMTech_ws/build/Monitoring/moveit_actions/catkin_generated/installspace/moveit_actionsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_actions" TYPE FILE FILES "/home/david/SIMTech_ws/src/Monitoring/moveit_actions/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/kinematics/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/robot_model_and_robot_state/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/planning/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/planning_scene/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/planning_scene_ros_api/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/motion_planning_api/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/motion_planning_pipeline/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/visualizing_collisions/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/move_group_interface/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/move_group_python_interface/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/state_display/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/interactivity/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/pick_place/cmake_install.cmake")
  include("/home/david/SIMTech_ws/build/Monitoring/moveit_actions/doc/perception_pipeline/cmake_install.cmake")

endif()

