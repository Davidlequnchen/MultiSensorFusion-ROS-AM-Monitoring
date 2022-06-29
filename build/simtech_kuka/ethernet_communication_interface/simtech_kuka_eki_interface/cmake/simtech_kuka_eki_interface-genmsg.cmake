# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "simtech_kuka_eki_interface: 0 messages, 1 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(simtech_kuka_eki_interface_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" NAME_WE)
add_custom_target(_simtech_kuka_eki_interface_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simtech_kuka_eki_interface" "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(simtech_kuka_eki_interface
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simtech_kuka_eki_interface
)

### Generating Module File
_generate_module_cpp(simtech_kuka_eki_interface
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simtech_kuka_eki_interface
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(simtech_kuka_eki_interface_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(simtech_kuka_eki_interface_generate_messages simtech_kuka_eki_interface_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(simtech_kuka_eki_interface_generate_messages_cpp _simtech_kuka_eki_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simtech_kuka_eki_interface_gencpp)
add_dependencies(simtech_kuka_eki_interface_gencpp simtech_kuka_eki_interface_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simtech_kuka_eki_interface_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(simtech_kuka_eki_interface
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simtech_kuka_eki_interface
)

### Generating Module File
_generate_module_eus(simtech_kuka_eki_interface
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simtech_kuka_eki_interface
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(simtech_kuka_eki_interface_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(simtech_kuka_eki_interface_generate_messages simtech_kuka_eki_interface_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(simtech_kuka_eki_interface_generate_messages_eus _simtech_kuka_eki_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simtech_kuka_eki_interface_geneus)
add_dependencies(simtech_kuka_eki_interface_geneus simtech_kuka_eki_interface_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simtech_kuka_eki_interface_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(simtech_kuka_eki_interface
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simtech_kuka_eki_interface
)

### Generating Module File
_generate_module_lisp(simtech_kuka_eki_interface
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simtech_kuka_eki_interface
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(simtech_kuka_eki_interface_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(simtech_kuka_eki_interface_generate_messages simtech_kuka_eki_interface_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(simtech_kuka_eki_interface_generate_messages_lisp _simtech_kuka_eki_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simtech_kuka_eki_interface_genlisp)
add_dependencies(simtech_kuka_eki_interface_genlisp simtech_kuka_eki_interface_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simtech_kuka_eki_interface_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(simtech_kuka_eki_interface
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simtech_kuka_eki_interface
)

### Generating Module File
_generate_module_nodejs(simtech_kuka_eki_interface
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simtech_kuka_eki_interface
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(simtech_kuka_eki_interface_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(simtech_kuka_eki_interface_generate_messages simtech_kuka_eki_interface_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(simtech_kuka_eki_interface_generate_messages_nodejs _simtech_kuka_eki_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simtech_kuka_eki_interface_gennodejs)
add_dependencies(simtech_kuka_eki_interface_gennodejs simtech_kuka_eki_interface_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simtech_kuka_eki_interface_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(simtech_kuka_eki_interface
  "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simtech_kuka_eki_interface
)

### Generating Module File
_generate_module_py(simtech_kuka_eki_interface
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simtech_kuka_eki_interface
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(simtech_kuka_eki_interface_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(simtech_kuka_eki_interface_generate_messages simtech_kuka_eki_interface_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lequn/Documents/GitHub/SIMTech_ws/src/simtech_kuka/ethernet_communication_interface/simtech_kuka_eki_interface/srv/SrvRobotCommand.srv" NAME_WE)
add_dependencies(simtech_kuka_eki_interface_generate_messages_py _simtech_kuka_eki_interface_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simtech_kuka_eki_interface_genpy)
add_dependencies(simtech_kuka_eki_interface_genpy simtech_kuka_eki_interface_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simtech_kuka_eki_interface_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simtech_kuka_eki_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simtech_kuka_eki_interface
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(simtech_kuka_eki_interface_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simtech_kuka_eki_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simtech_kuka_eki_interface
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(simtech_kuka_eki_interface_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simtech_kuka_eki_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simtech_kuka_eki_interface
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(simtech_kuka_eki_interface_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simtech_kuka_eki_interface)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simtech_kuka_eki_interface
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(simtech_kuka_eki_interface_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simtech_kuka_eki_interface)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simtech_kuka_eki_interface\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simtech_kuka_eki_interface
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(simtech_kuka_eki_interface_generate_messages_py std_msgs_generate_messages_py)
endif()
