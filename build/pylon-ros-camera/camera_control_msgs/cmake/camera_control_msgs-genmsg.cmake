# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "camera_control_msgs: 22 messages, 11 services")

set(MSG_I_FLAGS "-Icamera_control_msgs:/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg;-Icamera_control_msgs:/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg;-Iactionlib_msgs:/opt/ros/melodic/share/actionlib_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(camera_control_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" "sensor_msgs/RegionOfInterest"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" "camera_control_msgs/GrabAndSaveImageActionResult:actionlib_msgs/GoalID:camera_control_msgs/GrabAndSaveImageGoal:actionlib_msgs/GoalStatus:camera_control_msgs/GrabAndSaveImageFeedback:camera_control_msgs/GrabAndSaveImageResult:camera_control_msgs/GrabAndSaveImageActionFeedback:camera_control_msgs/GrabAndSaveImageActionGoal:std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" "actionlib_msgs/GoalID:std_msgs/Header:camera_control_msgs/GrabAndSaveImageGoal"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" "actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:std_msgs/Header:camera_control_msgs/GrabAndSaveImageResult"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" "actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:std_msgs/Header:camera_control_msgs/GrabAndSaveImageFeedback"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" "actionlib_msgs/GoalID:sensor_msgs/CameraInfo:sensor_msgs/RegionOfInterest:camera_control_msgs/GrabHDRImageResult:camera_control_msgs/GrabHDRImageActionGoal:camera_control_msgs/GrabHDRImageFeedback:actionlib_msgs/GoalStatus:camera_control_msgs/GrabHDRImageGoal:camera_control_msgs/GrabHDRImageActionResult:sensor_msgs/Image:camera_control_msgs/GrabHDRImageActionFeedback:std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" "camera_control_msgs/GrabHDRImageGoal:actionlib_msgs/GoalID:std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" "actionlib_msgs/GoalID:sensor_msgs/CameraInfo:sensor_msgs/RegionOfInterest:camera_control_msgs/GrabHDRImageResult:actionlib_msgs/GoalStatus:sensor_msgs/Image:std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" "actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:std_msgs/Header:camera_control_msgs/GrabHDRImageFeedback"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" "sensor_msgs/CameraInfo:std_msgs/Header:sensor_msgs/Image:sensor_msgs/RegionOfInterest"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" "camera_control_msgs/GrabImagesActionResult:actionlib_msgs/GoalID:sensor_msgs/CameraInfo:sensor_msgs/RegionOfInterest:camera_control_msgs/GrabImagesGoal:camera_control_msgs/GrabImagesFeedback:actionlib_msgs/GoalStatus:camera_control_msgs/GrabImagesResult:sensor_msgs/Image:std_msgs/Header:camera_control_msgs/GrabImagesActionFeedback:camera_control_msgs/GrabImagesActionGoal"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" "actionlib_msgs/GoalID:std_msgs/Header:camera_control_msgs/GrabImagesGoal"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" "actionlib_msgs/GoalID:sensor_msgs/CameraInfo:sensor_msgs/RegionOfInterest:actionlib_msgs/GoalStatus:camera_control_msgs/GrabImagesResult:sensor_msgs/Image:std_msgs/Header"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" "actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:std_msgs/Header:camera_control_msgs/GrabImagesFeedback"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" "sensor_msgs/CameraInfo:std_msgs/Header:sensor_msgs/Image:sensor_msgs/RegionOfInterest"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" "sensor_msgs/RegionOfInterest"
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" ""
)

get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" NAME_WE)
add_custom_target(_camera_control_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "camera_control_msgs" "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)

### Generating Services
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_cpp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
)

### Generating Module File
_generate_module_cpp(camera_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(camera_control_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(camera_control_msgs_generate_messages camera_control_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_cpp _camera_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera_control_msgs_gencpp)
add_dependencies(camera_control_msgs_gencpp camera_control_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera_control_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)

### Generating Services
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_eus(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
)

### Generating Module File
_generate_module_eus(camera_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(camera_control_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(camera_control_msgs_generate_messages camera_control_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_eus _camera_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera_control_msgs_geneus)
add_dependencies(camera_control_msgs_geneus camera_control_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera_control_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)

### Generating Services
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_lisp(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
)

### Generating Module File
_generate_module_lisp(camera_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(camera_control_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(camera_control_msgs_generate_messages camera_control_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_lisp _camera_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera_control_msgs_genlisp)
add_dependencies(camera_control_msgs_genlisp camera_control_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera_control_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)

### Generating Services
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_nodejs(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
)

### Generating Module File
_generate_module_nodejs(camera_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(camera_control_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(camera_control_msgs_generate_messages camera_control_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_nodejs _camera_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera_control_msgs_gennodejs)
add_dependencies(camera_control_msgs_gennodejs camera_control_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera_control_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg"
  "${MSG_I_FLAGS}"
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/melodic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/CameraInfo.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_msg_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)

### Generating Services
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)
_generate_srv_py(camera_control_msgs
  "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
)

### Generating Module File
_generate_module_py(camera_control_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(camera_control_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(camera_control_msgs_generate_messages camera_control_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/msg/currentParams.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabAndSaveImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabHDRImageFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesAction.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesActionFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesGoal.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesResult.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/devel/share/camera_control_msgs/msg/GrabImagesFeedback.msg" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/GetCamProperties.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBinning.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetBrightness.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetExposure.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetFloatValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGain.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetGamma.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetIntegerValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetROI.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetSleeping.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/chenlequn/SIMTech_ws/src/pylon-ros-camera/camera_control_msgs/srv/SetStringValue.srv" NAME_WE)
add_dependencies(camera_control_msgs_generate_messages_py _camera_control_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(camera_control_msgs_genpy)
add_dependencies(camera_control_msgs_genpy camera_control_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS camera_control_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/camera_control_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(camera_control_msgs_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(camera_control_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/camera_control_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(camera_control_msgs_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(camera_control_msgs_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/camera_control_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(camera_control_msgs_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(camera_control_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/camera_control_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(camera_control_msgs_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(camera_control_msgs_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/camera_control_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(camera_control_msgs_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(camera_control_msgs_generate_messages_py sensor_msgs_generate_messages_py)
endif()
