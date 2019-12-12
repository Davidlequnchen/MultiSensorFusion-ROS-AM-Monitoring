execute_process(COMMAND "/home/yaoxl/Documents/GitHub/SIMTech_ws/build/simtech_abb/velocity_control/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/yaoxl/Documents/GitHub/SIMTech_ws/build/simtech_abb/velocity_control/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
