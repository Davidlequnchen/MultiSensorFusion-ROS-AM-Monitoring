execute_process(COMMAND "/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/Laser_calibration/calib_ros_run/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/chenlequn/SIMTech_ws/build/laser_profiler_scanning/Laser_calibration/calib_ros_run/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
