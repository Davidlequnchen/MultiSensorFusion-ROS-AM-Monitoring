execute_process(COMMAND "/home/david/SIMTech_ws/build/etna/etna_calib/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/david/SIMTech_ws/build/etna/etna_calib/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
