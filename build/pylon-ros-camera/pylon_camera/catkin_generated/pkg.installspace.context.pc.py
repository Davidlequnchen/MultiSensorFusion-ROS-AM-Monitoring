# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "actionlib;camera_control_msgs;camera_info_manager;cv_bridge;diagnostic_updater;image_geometry;image_transport;roscpp;roslaunch;sensor_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lpylon_camera".split(';') if "-lpylon_camera" != "" else []
PROJECT_NAME = "pylon_camera"
PROJECT_SPACE_DIR = "/home/chenlequn/SIMTech_ws/install"
PROJECT_VERSION = "0.16.4"
