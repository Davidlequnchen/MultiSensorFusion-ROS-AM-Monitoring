cmake_minimum_required(VERSION 2.8.3)
project(scanning_robviz)
add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  pcl_ros
  pcl_conversions
  sensor_msgs
  message_generation
  tf2
  tf2_eigen
  tf2_ros
  geometry_msgs
  message_filters
  pcl_msgs
  rosbag
  rosconsole
  roslib
)

find_package(PCL 1.7.2 REQUIRED)
# find_package( OpenCV REQUIRED )
# find qt lib and headers
# find_package(Qt5Widgets)
# find_package(Qt5Gui)
# find_package(Qt5Core)
# find_package(Qt5 REQUIRED Widgets)


ADD_DEFINITIONS      (${QT_DEFINITIONS})

catkin_package()


include_directories(
  ${catkin_INCLUDE_DIRS}
)
# include_directories(${OpenCV_INCLUDE_DIRS})

include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})


# QT5_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
# QT5_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})


add_executable(nd_subprocess_handler src/nd_subprocess_handler.cpp)
target_link_libraries(nd_subprocess_handler ${catkin_LIBRARIES})