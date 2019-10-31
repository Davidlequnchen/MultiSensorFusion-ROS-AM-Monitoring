execute_process(COMMAND "/home/david/Simtech_ws/build/etna/Laser_calibration/calib_ros_run/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/david/Simtech_ws/build/etna/Laser_calibration/calib_ros_run/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
