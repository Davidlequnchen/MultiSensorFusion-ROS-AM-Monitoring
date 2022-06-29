# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "audio_utils: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iaudio_utils:/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(audio_utils_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" NAME_WE)
add_custom_target(_audio_utils_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "audio_utils" "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(audio_utils
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/audio_utils
)

### Generating Services

### Generating Module File
_generate_module_cpp(audio_utils
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/audio_utils
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(audio_utils_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(audio_utils_generate_messages audio_utils_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" NAME_WE)
add_dependencies(audio_utils_generate_messages_cpp _audio_utils_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(audio_utils_gencpp)
add_dependencies(audio_utils_gencpp audio_utils_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS audio_utils_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(audio_utils
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/audio_utils
)

### Generating Services

### Generating Module File
_generate_module_eus(audio_utils
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/audio_utils
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(audio_utils_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(audio_utils_generate_messages audio_utils_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" NAME_WE)
add_dependencies(audio_utils_generate_messages_eus _audio_utils_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(audio_utils_geneus)
add_dependencies(audio_utils_geneus audio_utils_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS audio_utils_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(audio_utils
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/audio_utils
)

### Generating Services

### Generating Module File
_generate_module_lisp(audio_utils
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/audio_utils
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(audio_utils_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(audio_utils_generate_messages audio_utils_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" NAME_WE)
add_dependencies(audio_utils_generate_messages_lisp _audio_utils_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(audio_utils_genlisp)
add_dependencies(audio_utils_genlisp audio_utils_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS audio_utils_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(audio_utils
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/audio_utils
)

### Generating Services

### Generating Module File
_generate_module_nodejs(audio_utils
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/audio_utils
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(audio_utils_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(audio_utils_generate_messages audio_utils_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" NAME_WE)
add_dependencies(audio_utils_generate_messages_nodejs _audio_utils_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(audio_utils_gennodejs)
add_dependencies(audio_utils_gennodejs audio_utils_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS audio_utils_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(audio_utils
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils
)

### Generating Services

### Generating Module File
_generate_module_py(audio_utils
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(audio_utils_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(audio_utils_generate_messages audio_utils_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/acoustic_monitoring/acoustic_utils/audio_utils-main/msg/AudioFrame.msg" NAME_WE)
add_dependencies(audio_utils_generate_messages_py _audio_utils_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(audio_utils_genpy)
add_dependencies(audio_utils_genpy audio_utils_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS audio_utils_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/audio_utils)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/audio_utils
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(audio_utils_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/audio_utils)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/audio_utils
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(audio_utils_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/audio_utils)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/audio_utils
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(audio_utils_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/audio_utils)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/audio_utils
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(audio_utils_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/audio_utils/.+/__init__.pyc?$"
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(audio_utils_generate_messages_py std_msgs_generate_messages_py)
endif()
