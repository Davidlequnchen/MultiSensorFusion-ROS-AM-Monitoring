execute_process(COMMAND "C:/Users/MI/Desktop/Github/build/Monitoring/laser_scanning/catkin_generated/python_distutils_install.bat" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(C:/Users/MI/Desktop/Github/build/Monitoring/laser_scanning/catkin_generated/python_distutils_install.bat) returned error code ")
endif()
