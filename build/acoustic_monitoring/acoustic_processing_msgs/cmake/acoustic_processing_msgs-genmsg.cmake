# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "acoustic_processing_msgs: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iacoustic_processing_msgs:/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(acoustic_processing_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" NAME_WE)
add_custom_target(_acoustic_processing_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "acoustic_processing_msgs" "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(acoustic_processing_msgs
  "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/acoustic_processing_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(acoustic_processing_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/acoustic_processing_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(acoustic_processing_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(acoustic_processing_msgs_generate_messages acoustic_processing_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" NAME_WE)
add_dependencies(acoustic_processing_msgs_generate_messages_cpp _acoustic_processing_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(acoustic_processing_msgs_gencpp)
add_dependencies(acoustic_processing_msgs_gencpp acoustic_processing_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS acoustic_processing_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(acoustic_processing_msgs
  "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/acoustic_processing_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(acoustic_processing_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/acoustic_processing_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(acoustic_processing_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(acoustic_processing_msgs_generate_messages acoustic_processing_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" NAME_WE)
add_dependencies(acoustic_processing_msgs_generate_messages_eus _acoustic_processing_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(acoustic_processing_msgs_geneus)
add_dependencies(acoustic_processing_msgs_geneus acoustic_processing_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS acoustic_processing_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(acoustic_processing_msgs
  "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/acoustic_processing_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(acoustic_processing_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/acoustic_processing_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(acoustic_processing_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(acoustic_processing_msgs_generate_messages acoustic_processing_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" NAME_WE)
add_dependencies(acoustic_processing_msgs_generate_messages_lisp _acoustic_processing_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(acoustic_processing_msgs_genlisp)
add_dependencies(acoustic_processing_msgs_genlisp acoustic_processing_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS acoustic_processing_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(acoustic_processing_msgs
  "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/acoustic_processing_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(acoustic_processing_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/acoustic_processing_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(acoustic_processing_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(acoustic_processing_msgs_generate_messages acoustic_processing_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" NAME_WE)
add_dependencies(acoustic_processing_msgs_generate_messages_nodejs _acoustic_processing_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(acoustic_processing_msgs_gennodejs)
add_dependencies(acoustic_processing_msgs_gennodejs acoustic_processing_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS acoustic_processing_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(acoustic_processing_msgs
  "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/acoustic_processing_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(acoustic_processing_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/acoustic_processing_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(acoustic_processing_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(acoustic_processing_msgs_generate_messages acoustic_processing_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/acoustic_monitoring/acoustic_processing_msgs/msg/MsgAcousticFeature.msg" NAME_WE)
add_dependencies(acoustic_processing_msgs_generate_messages_py _acoustic_processing_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(acoustic_processing_msgs_genpy)
add_dependencies(acoustic_processing_msgs_genpy acoustic_processing_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS acoustic_processing_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/acoustic_processing_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/acoustic_processing_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/acoustic_processing_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/acoustic_processing_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/acoustic_processing_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/acoustic_processing_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/acoustic_processing_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/acoustic_processing_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/acoustic_processing_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/acoustic_processing_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/acoustic_processing_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
