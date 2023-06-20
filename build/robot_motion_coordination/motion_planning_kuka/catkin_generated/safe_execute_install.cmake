execute_process(COMMAND "/home/artc/GitHub/SIMTech_ws/build/robot_motion_coordination/motion_planning_kuka/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/artc/GitHub/SIMTech_ws/build/robot_motion_coordination/motion_planning_kuka/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
