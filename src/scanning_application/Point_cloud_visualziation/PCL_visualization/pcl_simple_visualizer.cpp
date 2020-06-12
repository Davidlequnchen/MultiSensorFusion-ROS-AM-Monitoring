#include <iostream>
#include <thread>
#include <iostream>
#include <vector>

#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

//Boost Library
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>



pcl::visualization::PCLVisualizer::Ptr LoadFile()
{
    try
    {   
        pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
        viewer->setBackgroundColor (0, 0, 0); // set background black
        
        // create a colored cloud pointer
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
        //load pcd file into this cloud pointer
        pcl::io::loadPCDFile ("test_proper.pcd", *cloud);

        std::vector<pcl::visualization::Camera> cam;
      
        

        viewer->addCoordinateSystem(0.15);//"workobject"
        

        pcl::PointXYZ min_pt, max_pt;
        pcl::getMinMax3D(*cloud, min_pt, max_pt);

        viewer->getCameras(cam);
        cam[0].pos[0] = (max_pt.x + min_pt.x) / 2;
        cam[0].pos[1] = (max_pt.y + min_pt.y) / 2;
        cam[0].focal[0] = (max_pt.x + min_pt.x) / 2;
        cam[0].focal[1] = (max_pt.y + min_pt.y) / 2;
        cam[0].focal[2] = max_pt.z;
        viewer->setCameraParameters(cam[0]);

        
        
        viewer->addPointCloud (cloud, "cloud");
        viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud");
       

        std::cout << "Camara:" << std::endl << " - pos: (" << cam[0].pos[0] << ", "    << cam[0].pos[1] << ", "    << cam[0].pos[2] << ")" << endl
                  << " - view: ("    << cam[0].view[0] << ", "   << cam[0].view[1] << ", "   << cam[0].view[2] << ")"    << endl
                  << " - focal: ("   << cam[0].focal[0] << ", "  << cam[0].focal[1] << ", "  << cam[0].focal[2] << ")"   << endl;
        return (viewer);
    }
    catch(char const* error)
    {
        std::cout << "Load error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown load exception.";
    }

}


// --------------
// -----Main-----
// --------------
int
main (int argc, char** argv)
{


  // create a visualzer for each situation, pass the point cloud pointer to each function 
  pcl::visualization::PCLVisualizer::Ptr viewer;
  
  viewer = LoadFile();

  //--------------------
  // -----Main loop-----
  //--------------------
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce (100);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
}

