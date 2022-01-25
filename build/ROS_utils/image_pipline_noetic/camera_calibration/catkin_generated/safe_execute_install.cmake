execute_process(COMMAND "/home/lequn/Documents/GitHub/SIMTech_ws/build/ROS_utils/image_pipline_noetic/camera_calibration/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/lequn/Documents/GitHub/SIMTech_ws/build/ROS_utils/image_pipline_noetic/camera_calibration/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
