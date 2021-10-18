# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "dnb_msgs: 2 messages, 1 services")

set(MSG_I_FLAGS "-Idnb_msgs:/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(dnb_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" NAME_WE)
add_custom_target(_dnb_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dnb_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" NAME_WE)
add_custom_target(_dnb_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dnb_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" "std_msgs/MultiArrayDimension:std_msgs/MultiArrayLayout"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" NAME_WE)
add_custom_target(_dnb_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dnb_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dnb_msgs
)
_generate_msg_cpp(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dnb_msgs
)

### Generating Services
_generate_srv_cpp(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dnb_msgs
)

### Generating Module File
_generate_module_cpp(dnb_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dnb_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(dnb_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(dnb_msgs_generate_messages dnb_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_cpp _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_cpp _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_cpp _dnb_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dnb_msgs_gencpp)
add_dependencies(dnb_msgs_gencpp dnb_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dnb_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dnb_msgs
)
_generate_msg_eus(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dnb_msgs
)

### Generating Services
_generate_srv_eus(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dnb_msgs
)

### Generating Module File
_generate_module_eus(dnb_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dnb_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(dnb_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(dnb_msgs_generate_messages dnb_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_eus _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_eus _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_eus _dnb_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dnb_msgs_geneus)
add_dependencies(dnb_msgs_geneus dnb_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dnb_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dnb_msgs
)
_generate_msg_lisp(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dnb_msgs
)

### Generating Services
_generate_srv_lisp(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dnb_msgs
)

### Generating Module File
_generate_module_lisp(dnb_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dnb_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(dnb_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(dnb_msgs_generate_messages dnb_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_lisp _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_lisp _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_lisp _dnb_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dnb_msgs_genlisp)
add_dependencies(dnb_msgs_genlisp dnb_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dnb_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dnb_msgs
)
_generate_msg_nodejs(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dnb_msgs
)

### Generating Services
_generate_srv_nodejs(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dnb_msgs
)

### Generating Module File
_generate_module_nodejs(dnb_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dnb_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(dnb_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(dnb_msgs_generate_messages dnb_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_nodejs _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_nodejs _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_nodejs _dnb_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dnb_msgs_gennodejs)
add_dependencies(dnb_msgs_gennodejs dnb_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dnb_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs
)
_generate_msg_py(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs
)

### Generating Services
_generate_srv_py(dnb_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs
)

### Generating Module File
_generate_module_py(dnb_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(dnb_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(dnb_msgs_generate_messages dnb_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/ComponentStatus.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_py _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/msg/StringMultiArray.msg" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_py _dnb_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/dragandbot_common/dnb_msgs/srv/SetString.srv" NAME_WE)
add_dependencies(dnb_msgs_generate_messages_py _dnb_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dnb_msgs_genpy)
add_dependencies(dnb_msgs_genpy dnb_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dnb_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dnb_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dnb_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(dnb_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dnb_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/dnb_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(dnb_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dnb_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dnb_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(dnb_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dnb_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/dnb_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(dnb_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dnb_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(dnb_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
