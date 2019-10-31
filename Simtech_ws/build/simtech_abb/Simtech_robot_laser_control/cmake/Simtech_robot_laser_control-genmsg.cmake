# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "Simtech_robot_laser_control: 5 messages, 1 services")

set(MSG_I_FLAGS "-ISimtech_robot_laser_control:/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(Simtech_robot_laser_control_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" NAME_WE)
add_custom_target(_Simtech_robot_laser_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Simtech_robot_laser_control" "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" ""
)

get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" NAME_WE)
add_custom_target(_Simtech_robot_laser_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Simtech_robot_laser_control" "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" NAME_WE)
add_custom_target(_Simtech_robot_laser_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Simtech_robot_laser_control" "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" ""
)

get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" NAME_WE)
add_custom_target(_Simtech_robot_laser_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Simtech_robot_laser_control" "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" ""
)

get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" NAME_WE)
add_custom_target(_Simtech_robot_laser_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Simtech_robot_laser_control" "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" NAME_WE)
add_custom_target(_Simtech_robot_laser_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "Simtech_robot_laser_control" "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_cpp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_cpp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_cpp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_cpp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Services
_generate_srv_cpp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Module File
_generate_module_cpp(Simtech_robot_laser_control
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(Simtech_robot_laser_control_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(Simtech_robot_laser_control_generate_messages Simtech_robot_laser_control_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_cpp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_cpp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_cpp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_cpp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_cpp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_cpp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Simtech_robot_laser_control_gencpp)
add_dependencies(Simtech_robot_laser_control_gencpp Simtech_robot_laser_control_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Simtech_robot_laser_control_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_eus(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_eus(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_eus(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_eus(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Services
_generate_srv_eus(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Module File
_generate_module_eus(Simtech_robot_laser_control
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(Simtech_robot_laser_control_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(Simtech_robot_laser_control_generate_messages Simtech_robot_laser_control_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_eus _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_eus _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_eus _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_eus _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_eus _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_eus _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Simtech_robot_laser_control_geneus)
add_dependencies(Simtech_robot_laser_control_geneus Simtech_robot_laser_control_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Simtech_robot_laser_control_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_lisp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_lisp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_lisp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_lisp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Services
_generate_srv_lisp(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Module File
_generate_module_lisp(Simtech_robot_laser_control
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(Simtech_robot_laser_control_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(Simtech_robot_laser_control_generate_messages Simtech_robot_laser_control_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_lisp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_lisp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_lisp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_lisp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_lisp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_lisp _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Simtech_robot_laser_control_genlisp)
add_dependencies(Simtech_robot_laser_control_genlisp Simtech_robot_laser_control_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Simtech_robot_laser_control_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_nodejs(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_nodejs(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_nodejs(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_nodejs(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Services
_generate_srv_nodejs(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Module File
_generate_module_nodejs(Simtech_robot_laser_control
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(Simtech_robot_laser_control_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(Simtech_robot_laser_control_generate_messages Simtech_robot_laser_control_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Simtech_robot_laser_control_gennodejs)
add_dependencies(Simtech_robot_laser_control_gennodejs Simtech_robot_laser_control_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Simtech_robot_laser_control_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_py(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_py(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_py(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
)
_generate_msg_py(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Services
_generate_srv_py(Simtech_robot_laser_control
  "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
)

### Generating Module File
_generate_module_py(Simtech_robot_laser_control
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(Simtech_robot_laser_control_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(Simtech_robot_laser_control_generate_messages Simtech_robot_laser_control_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgStart.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_py _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgInfo.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_py _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgEmission.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_py _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgControl.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_py _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/msg/MsgPower.msg" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_py _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/david/Simtech_ws/src/simtech_abb/Simtech_robot_laser_control/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(Simtech_robot_laser_control_generate_messages_py _Simtech_robot_laser_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(Simtech_robot_laser_control_genpy)
add_dependencies(Simtech_robot_laser_control_genpy Simtech_robot_laser_control_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Simtech_robot_laser_control_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Simtech_robot_laser_control
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(Simtech_robot_laser_control_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/Simtech_robot_laser_control
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(Simtech_robot_laser_control_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Simtech_robot_laser_control
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(Simtech_robot_laser_control_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/Simtech_robot_laser_control
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(Simtech_robot_laser_control_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Simtech_robot_laser_control
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(Simtech_robot_laser_control_generate_messages_py std_msgs_generate_messages_py)
endif()
