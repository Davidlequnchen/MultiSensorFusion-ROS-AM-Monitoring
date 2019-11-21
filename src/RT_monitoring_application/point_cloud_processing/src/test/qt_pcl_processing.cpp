#include "../include/pclviewer.h"
#include "../include/LmdFuncs.h"
#include <QApplication>
#include <QMainWindow>
#include <pcl/visualization/pcl_visualizer.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <iostream>
#include <thread>
//#include "qt_pcl_processing.moc"

using namespace std::literals::chrono_literals;



int main (int argc, char *argv[])
{

  // initialize node
  ros::init(argc, argv, "pcl_processing_interface");

  

  while (ros::ok())
  {
    //OpenLmd::PointCloudProcess pointProcess;
    
    QApplication a (argc, argv);

    PCLViewer w;

    //w.showMinimized();
    w.show ();
    //w.cloud_Vis();
    //w.cloud_visualization();
    
    a.exec();
    ros::spinOnce();
    //loop_rate.sleep();
    
    //return a.exec ();
  }
  
  return 0;
}


