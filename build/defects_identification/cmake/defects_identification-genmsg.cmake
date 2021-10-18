# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "defects_identification: 1 messages, 0 services")

set(MSG_I_FLAGS "-Idefects_identification:/home/chenlequn/SIMTech_ws/src/defects_identification/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(defects_identification_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" NAME_WE)
add_custom_target(_defects_identification_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "defects_identification" "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(defects_identification
  "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/defects_identification
)

### Generating Services

### Generating Module File
_generate_module_cpp(defects_identification
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/defects_identification
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(defects_identification_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(defects_identification_generate_messages defects_identification_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" NAME_WE)
add_dependencies(defects_identification_generate_messages_cpp _defects_identification_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(defects_identification_gencpp)
add_dependencies(defects_identification_gencpp defects_identification_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS defects_identification_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(defects_identification
  "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/defects_identification
)

### Generating Services

### Generating Module File
_generate_module_eus(defects_identification
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/defects_identification
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(defects_identification_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(defects_identification_generate_messages defects_identification_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" NAME_WE)
add_dependencies(defects_identification_generate_messages_eus _defects_identification_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(defects_identification_geneus)
add_dependencies(defects_identification_geneus defects_identification_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS defects_identification_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(defects_identification
  "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/defects_identification
)

### Generating Services

### Generating Module File
_generate_module_lisp(defects_identification
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/defects_identification
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(defects_identification_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(defects_identification_generate_messages defects_identification_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" NAME_WE)
add_dependencies(defects_identification_generate_messages_lisp _defects_identification_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(defects_identification_genlisp)
add_dependencies(defects_identification_genlisp defects_identification_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS defects_identification_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(defects_identification
  "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/defects_identification
)

### Generating Services

### Generating Module File
_generate_module_nodejs(defects_identification
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/defects_identification
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(defects_identification_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(defects_identification_generate_messages defects_identification_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" NAME_WE)
add_dependencies(defects_identification_generate_messages_nodejs _defects_identification_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(defects_identification_gennodejs)
add_dependencies(defects_identification_gennodejs defects_identification_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS defects_identification_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(defects_identification
  "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/defects_identification
)

### Generating Services

### Generating Module File
_generate_module_py(defects_identification
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/defects_identification
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(defects_identification_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(defects_identification_generate_messages defects_identification_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/defects_identification/msg/MsgDefects.msg" NAME_WE)
add_dependencies(defects_identification_generate_messages_py _defects_identification_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(defects_identification_genpy)
add_dependencies(defects_identification_genpy defects_identification_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS defects_identification_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/defects_identification)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/defects_identification
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(defects_identification_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/defects_identification)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/defects_identification
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(defects_identification_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/defects_identification)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/defects_identification
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(defects_identification_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/defects_identification)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/defects_identification
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(defects_identification_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/defects_identification)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/defects_identification\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/defects_identification
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(defects_identification_generate_messages_py std_msgs_generate_messages_py)
endif()
