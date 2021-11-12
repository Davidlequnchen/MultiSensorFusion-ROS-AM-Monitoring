cmake_minimum_required(VERSION 2.8.3)
project(infratec_image_processing)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS 
tf image_transport roscpp rospy std_msgs std_srvs sensor_msgs cv_bridge camera_info_manager message_generation)

add_message_files(FILES
                  MsgMeltpool.msg
                  MsgHistogram.msg
                  MsgROISize.msg
                  MsgThreshold.msg)

## pkg-config libraries
# find_package(PkgConfig REQUIRED)
# catkin_python_setup()


generate_messages(
  DEPENDENCIES
  std_msgs
)

###################################################
## Declare things to be passed to other projects ##
###################################################
ADD_DEFINITIONS      (${QT_DEFINITIONS})

## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS message_runtime
)


###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)
