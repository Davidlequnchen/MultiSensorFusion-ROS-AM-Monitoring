#include "../include/pclviewer.h"
#include "../include/LmdFuncs.h"
#include <QApplication>
#include <QMainWindow>
#include <pcl/visualization/pcl_visualizer.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main (int argc, char *argv[])
{

  // initialize node
  ros::init(argc, argv, "pcl_processing_interface");

  ros::NodeHandle n;


  //OpenLmd::PointCloudProcess pointProcess;

  QApplication a (argc, argv);
  PCLViewer w;

  w.show ();

  return a.exec ();
}


