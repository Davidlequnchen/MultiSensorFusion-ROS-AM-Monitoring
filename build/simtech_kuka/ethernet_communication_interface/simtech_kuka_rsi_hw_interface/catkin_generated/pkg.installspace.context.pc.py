# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include;/usr/include".split(';') if "${prefix}/include;/usr/include" != "" else []
PROJECT_CATKIN_DEPENDS = "controller_manager;hardware_interface;joint_limits_interface;roscpp;std_msgs;message_runtime".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lsimtech_kuka_rsi_hw_interface;/usr/lib/x86_64-linux-gnu/libtinyxml.so".split(';') if "-lsimtech_kuka_rsi_hw_interface;/usr/lib/x86_64-linux-gnu/libtinyxml.so" != "" else []
PROJECT_NAME = "simtech_kuka_rsi_hw_interface"
PROJECT_SPACE_DIR = "/home/artc/GitHub/SIMTech_ws/install"
PROJECT_VERSION = "0.1.0"
