cmake_minimum_required(VERSION 2.8.3)
project(point_cloud_processing)
# c++ version needs to be c++14
add_definitions(-std=c++14)


find_package(catkin REQUIRED COMPONENTS
  tf
  roscpp
  pcl_ros
  pcl_conversions
  sensor_msgs
  std_msgs
  message_generation
)

find_package(PCL 1.7.2 REQUIRED)
find_package( OpenCV REQUIRED )
# find qt lib and headers
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(Qt5 REQUIRED Widgets)
ADD_DEFINITIONS      (${QT_DEFINITIONS})





catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

include_directories(${OpenCV_INCLUDE_DIRS})


include_directories (${PCL_INCLUDE_DIRS})
link_directories    (${PCL_LIBRARY_DIRS})
add_definitions     (${PCL_DEFINITIONS})


set  (project_SOURCES src/qt_pcl_processing.cpp src/pclviewer.cpp src/LmdFuncs.cpp)
#src/pcl_visualizer_demo.cpp
set  (project_HEADERS include/pclviewer.h include/LmdFuncs.h include/ui_pclviewer.h)
set  (project_FORMS   resources/pclviewer.ui)

QT5_WRAP_CPP (project_HEADERS_MOC   ${project_HEADERS})
QT5_WRAP_UI  (project_FORMS_HEADERS ${project_FORMS})




#catkin_python_setup()


ADD_EXECUTABLE  (point_cloud_processing ${project_SOURCES}
                                        ${project_FORMS_HEADERS}
                                        ${project_HEADERS_MOC})


target_link_libraries(point_cloud_processing Qt5::Widgets Qt5::Core Qt5::Gui)
target_link_libraries( point_cloud_processing ${OpenCV_LIBS} )
target_link_libraries( point_cloud_processing ${PCL_LIBRARIES})
target_link_libraries( point_cloud_processing ${catkin_LIBRARIES})


#add_executable(qt_pcl_processing src/qt_pcl_processing.cpp)
#target_link_libraries(qt_pcl_processing ${catkin_LIBRARIES})




