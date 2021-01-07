execute_process(COMMAND "/home/chenlequn/SIMTech_ws/build/ROS_perception/vision_opencv/image_geometry/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/chenlequn/SIMTech_ws/build/ROS_perception/vision_opencv/image_geometry/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
