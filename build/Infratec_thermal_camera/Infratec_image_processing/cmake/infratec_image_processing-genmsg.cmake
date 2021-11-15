# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "infratec_image_processing: 5 messages, 0 services")

set(MSG_I_FLAGS "-Iinfratec_image_processing:/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(infratec_image_processing_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" NAME_WE)
add_custom_target(_infratec_image_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "infratec_image_processing" "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" NAME_WE)
add_custom_target(_infratec_image_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "infratec_image_processing" "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" NAME_WE)
add_custom_target(_infratec_image_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "infratec_image_processing" "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" NAME_WE)
add_custom_target(_infratec_image_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "infratec_image_processing" "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" NAME_WE)
add_custom_target(_infratec_image_processing_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "infratec_image_processing" "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_cpp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_cpp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_cpp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_cpp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
)

### Generating Services

### Generating Module File
_generate_module_cpp(infratec_image_processing
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(infratec_image_processing_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(infratec_image_processing_generate_messages infratec_image_processing_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_cpp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_cpp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_cpp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_cpp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_cpp _infratec_image_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(infratec_image_processing_gencpp)
add_dependencies(infratec_image_processing_gencpp infratec_image_processing_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS infratec_image_processing_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_eus(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_eus(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_eus(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_eus(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
)

### Generating Services

### Generating Module File
_generate_module_eus(infratec_image_processing
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(infratec_image_processing_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(infratec_image_processing_generate_messages infratec_image_processing_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_eus _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_eus _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_eus _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_eus _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_eus _infratec_image_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(infratec_image_processing_geneus)
add_dependencies(infratec_image_processing_geneus infratec_image_processing_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS infratec_image_processing_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_lisp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_lisp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_lisp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_lisp(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
)

### Generating Services

### Generating Module File
_generate_module_lisp(infratec_image_processing
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(infratec_image_processing_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(infratec_image_processing_generate_messages infratec_image_processing_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_lisp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_lisp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_lisp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_lisp _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_lisp _infratec_image_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(infratec_image_processing_genlisp)
add_dependencies(infratec_image_processing_genlisp infratec_image_processing_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS infratec_image_processing_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_nodejs(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_nodejs(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_nodejs(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_nodejs(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
)

### Generating Services

### Generating Module File
_generate_module_nodejs(infratec_image_processing
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(infratec_image_processing_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(infratec_image_processing_generate_messages infratec_image_processing_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_nodejs _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_nodejs _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_nodejs _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_nodejs _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_nodejs _infratec_image_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(infratec_image_processing_gennodejs)
add_dependencies(infratec_image_processing_gennodejs infratec_image_processing_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS infratec_image_processing_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_py(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_py(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_py(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
)
_generate_msg_py(infratec_image_processing
  "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
)

### Generating Services

### Generating Module File
_generate_module_py(infratec_image_processing
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(infratec_image_processing_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(infratec_image_processing_generate_messages infratec_image_processing_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpoolWidth.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_py _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgMeltpool.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_py _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgROISize.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_py _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgHistogram.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_py _infratec_image_processing_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/Infratec_thermal_camera/Infratec_image_processing/msg/MsgThreshold.msg" NAME_WE)
add_dependencies(infratec_image_processing_generate_messages_py _infratec_image_processing_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(infratec_image_processing_genpy)
add_dependencies(infratec_image_processing_genpy infratec_image_processing_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS infratec_image_processing_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/infratec_image_processing
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(infratec_image_processing_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/infratec_image_processing
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(infratec_image_processing_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/infratec_image_processing
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(infratec_image_processing_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/infratec_image_processing
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(infratec_image_processing_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/infratec_image_processing
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(infratec_image_processing_generate_messages_py std_msgs_generate_messages_py)
endif()
