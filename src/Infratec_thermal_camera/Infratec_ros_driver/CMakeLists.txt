cmake_minimum_required(VERSION 2.8.3)
project(infratec_ros_driver)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS 
image_transport roscpp rospy std_msgs std_srvs sensor_msgs cv_bridge camera_info_manager)

## pkg-config libraries
# find_package(PkgConfig REQUIRED)
catkin_python_setup()


###################################################
## Declare things to be passed to other projects ##
###################################################
ADD_DEFINITIONS      (${QT_DEFINITIONS})

## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS
)


###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)
