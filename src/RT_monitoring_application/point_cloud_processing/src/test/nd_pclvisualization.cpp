#include "../include/pclviewer.h"
#include "../include/ui_pclviewer.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>

#include <sstream>
#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;
// point cloud definition
typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
// namspace
using namespace std;
using namespace sensor_msgs;


struct callback_args{
  // structure used to pass arguments to the callback function
  pcl::PointCloud<pcl::PointXYZ>::Ptr clicked_points_3d;
  pcl::PointCloud<pcl::PointXYZ>::Ptr distance_points;
  pcl::visualization::PCLVisualizer::Ptr viewerPtr;
  bool plane;
};

struct callback_args_class{
  OpenLmd::PointCloudProcess *pointProcessPtr;
  pcl::visualization::PCLVisualizer::Ptr viewerPtr;
};

void  pp_callback_plane (const pcl::visualization::PointPickingEvent& event, void* args);
void  pp_callback_points (const pcl::visualization::PointPickingEvent& event, void* args);



//Callback of the function to select the points of the plane++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void pp_callback(const pcl::visualization::PointPickingEvent& event, void* args)
{
    try
    {
        struct callback_args_class* data = (struct callback_args_class *)args;
        if (event.getPointIndex () == -1)
            return;
        pcl::PointXYZ current_point;
        event.getPoint(current_point.x, current_point.y, current_point.z);
        data->pointProcessPtr->AddPoint(current_point);

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        data->pointProcessPtr->getSelPoints(cloud);
        // Draw clicked points in yellow:
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green_handler (cloud, 0, 255, 0);
        data->viewerPtr->removePointCloud("distance_clicked_points");
        data->viewerPtr->addPointCloud(cloud, green_handler, "distance_clicked_points");
        data->viewerPtr->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "distance_clicked_points");
    }
    catch(char const* error)
    {
        std::cout << "Point picking error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown picking exception.";
    }
}



class PCLVisualization
{
public:
    // class constructor
    PCLVisualization() : cloud_in_topic("/filtered_cloud")
    {   
        // create a subscribe, subscribe the cloud topic after filtering
        sub = n.subscribe (cloud_in_topic, 30,
                           &PCLVisualization::pclviewer_callback, this);

        //print some info about the node
        std::string r_ct = n.resolveName (cloud_in_topic);
        ROS_INFO_STREAM("Listening for incoming data on topic " << r_ct );

    }
    
    //call back function
    void pclviewer_callback(const sensor_msgs::PointCloud2ConstPtr& pCloud)
    {
        // new cloud formation with color elements
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
        pcl::fromROSMsg (*pCloud, *cloud); // convert ros message cloud into point cloud
        // cloud is now the cloud we are interested

        if (cloud->height <= 1)
        {
        ROS_ERROR("Input point cloud is not organized, ignoring!");
        return;
        }
        try
        {
          // set up the point cloud visualization viewer(initialization)
          viewer.reset (new pcl::visualization::PCLVisualizer ("3D Point cloud Visualizer", true));
   
          viewer->setBackgroundColor (0, 0, 0); //background black
          viewer->addPointCloud (cloud, "cloud"); // add the point from cloud message into the visualizer
          viewer->resetCamera ();
          viewer->addCoordinateSystem (0.2);
          cb_args_class.viewerPtr = pcl::visualization::PCLVisualizer::Ptr(viewer);
          cb_args_class.pointProcessPtr = &pointProcess;
          //viewer->registerPointPickingCallback (pp_callback, (void*)&cb_args_class);
          //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_cloud_size->value(), "cloud");
          //viewer->initCameraParameters ();
          viewer->spinOnce(1); // update the screen
          std::this_thread::sleep_for(std::chrono::milliseconds(2));
        }
        catch (std::runtime_error &e)
        {
        ROS_ERROR_STREAM("Error in converting cloud to image message: "
                            << e.what());
        }
    }



private:
  ros::NodeHandle n;
  
  std::string cloud_in_topic; //default input
  
  ros::Subscriber sub; //cloud subscriber
  
protected:
  // initalize the pcl visualizer shared pointer
  //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Point cloud Visualizer"));
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;// shared pointer definition
  OpenLmd::PointCloudProcess pointProcess;
};






int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "pcl_visualizer");

 
  PCLVisualization pcl; //this initialize the node

  ros::Rate rate(30); // frequency of operation

  ros::spin();

  return 0;
}