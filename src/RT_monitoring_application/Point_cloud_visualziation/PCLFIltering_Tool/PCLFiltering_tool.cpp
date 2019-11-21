#include <iostream>
#include <thread>
#include <iostream>
#include <vector>

#include <pcl/ModelCoefficients.h>
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

//Boost Library
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>



using namespace std::literals::chrono_literals;

// --------------
// -----Help-----
// --------------

// define global values
pcl::PointXYZ min_pt, max_pt;

std::string loadfilename = "flatfast.pcd";
std::string savefilename = "flatfast_filtered.txt";




// ------------------------------------
// -----Create global point cloud pointer-----
// ------------------------------------
pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr color_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
//cloud_filtered stores cloud after filtering (inliers)
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
// filtered_part stores removal parts after filtering
pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_part (new pcl::PointCloud<pcl::PointXYZRGB>);



// ------------------------------------
// ----------local functions
// ------------------------------------
void
printUsage (const char* progName)
{
  std::cout << "\n\nUsage: "<<progName<<" [options]\n\n"
            << "Options:\n"
            << "-------------------------------------------\n"
            << "-h           this help\n"
            << "-s           Simple visualisation\n"
            << "-r           RGB point cloud visualisation\n"
            << "-sfilter     apply statistical filter\n"
            << "-sandsave    apply statistical filter and save the result \n"
            << "-rfilter     apply radius outlier removal filter\n"
            << "-randsave    apply radius outlier removal filter and save the result \n"
            << "-vfilter     apply voxel grid removal filter\n"
            << "-vandsave    apply voxel grid removal filter and save\n"
            << "-pfilter     apply passthrough filter\n"
            << "-pandsave    apply passthrough filter and save\n"

            << "\n\n";
}

// Load a point cloud to normal cloud pointer from a 'pcd' file, with fileName as a parameter
// return RGB point cloud pointer 
pcl::PointCloud<pcl::PointXYZRGB>::Ptr  LoadPointFile (std::string fileName) {
    try
    {   // local cloud pointer to store point cloud temporarily
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_RGB (new pcl::PointCloud<pcl::PointXYZRGB>);

        //load pcd file into this cloud pointer
        pcl::io::loadPCDFile (fileName, *cloud);

        pcl::copyPointCloud(*cloud,*cloud_RGB);

        return (cloud_RGB);
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


// prameters in: the filename to be saved, and the point cloud
void savePointFile (std::string fileName, pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud) {
    try
    {   
        if ((cloud->width * cloud->height) > 0) {
              // save the point cloud(cloud) into the file
              pcl::io::savePCDFileASCII(fileName, *cloud);
          } else {
              PCL_ERROR("Point cloud empty \n");
              throw "Point cloud empty";
          }
    }
    catch(char const* error)
    {
        std::cout << "save error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown save exception.";
    }
}







pcl::visualization::PCLVisualizer::Ptr simpleVis (pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->addCoordinateSystem (0.2);
  viewer->initCameraParameters ();
  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr rgbVis (pcl::PointCloud<pcl::PointXYZRGB>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
  viewer->addPointCloud<pcl::PointXYZRGB> (cloud, rgb, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  return (viewer);
}

// input: point cloud 
// output: point cloud visualizer(viewer) pointer
pcl::visualization::PCLVisualizer::Ptr  StatisticalFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // -------------------------------------------------------
  // -----read the point cloud and apply statistical filtering
  // -----return the cloud after filtering(inlier) and filtered part(outlier)in red----
  // -----Open the 3D viewer and show the filtered cloud--------------------------
  // ---------------------------------------------------------

  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // define a color cloud to stored the filtered part
  //pcl::PointCloud<pcl::PointXYZRGB>::Ptr filtered_part (new pcl::PointCloud<pcl::PointXYZRGB>);
  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black
  
  // Create the filtering object
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (50);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (1.0); // set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud_filtered); // return the cloud after filtering(inlier) and store it into cloud_filtered

  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  
  // sor.setNegative (true);// This is to get the outlier(the filtered part)
  // sor.filter (*cloud_filtered);

 // pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud);
 // viewer->addPointCloud<pcl::PointXYZRGB> (cloud_filtered, rgb, "filtered part"); // add rgb points into the viewer
 // viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
  viewer->addCoordinateSystem (0.2);
  viewer->initCameraParameters ();

  return (viewer);
}


pcl::visualization::PCLVisualizer::Ptr  RadiusOutlierRemovalFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  //---The user specifies a number of neighbors which every index -----------------
  //---must have within a specified radius to remain in the PointCloud. ----------


  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background blacks

  //create a filter object
  pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
  // build the filter
  outrem.setInputCloud(cloud);
  outrem.setRadiusSearch(0.9);
  outrem.setMinNeighborsInRadius (2);
  // apply filter
  outrem.filter (*cloud_filtered);

  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  viewer->addCoordinateSystem (0.2);
  viewer->initCameraParameters ();

  return (viewer);

}

pcl::visualization::PCLVisualizer::Ptr  VoxelGridFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background blacks

   // Create the filtering object
  pcl::VoxelGrid<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  // downsampling leaf size of 1cm
  sor.setLeafSize (0.002f, 0.002f, 0.002f);
  sor.filter (*cloud_filtered);


  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  viewer->addCoordinateSystem (0.2);
  viewer->initCameraParameters ();

  return (viewer);

}


pcl::visualization::PCLVisualizer::Ptr  PassThroughFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background blacks

  // Create the filtering object
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (0.0, 1.0);
  //pass.setFilterLimitsNegative (true);
  pass.filter (*cloud_filtered);


  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  viewer->addCoordinateSystem (0.2);
  viewer->initCameraParameters ();

  return (viewer);

}











// --------------
// -----Main-----
// --------------
int
main (int argc, char** argv)
{

  // --------------------------------------
  // -----Parse Command Line Arguments-----
  // --------------------------------------
  if (pcl::console::find_argument (argc, argv, "-h") >= 0)
  {
    printUsage (argv[0]);
    return 0;
  }
  bool simple(false), rgb(false), statistical(false), radiusOutlierRemoval(false);
  bool sFilterAndSave(false), rFilterAndSave(false), VoxelGrid(false), VFilterAndSave(false), Passthrough(false), PFilterAndSave(false);

  if (pcl::console::find_argument (argc, argv, "-s") >= 0)
  {
    simple = true;
    std::cout << "Simple visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-r") >= 0)
  {
    rgb = true;
    std::cout << "RGB colour visualisation example\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-sfilter") >= 0)
  {
    statistical = true;
    std::cout << "apply statistical filter\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-rfilter") >= 0)
  {
    radiusOutlierRemoval = true;
    std::cout << "apply radius outlier removal filter\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-sandsave") >= 0)
  {
    sFilterAndSave = true;
    std::cout << "apply statistical outlier removal filter and save the results into .pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-randsave") >= 0)
  {
    rFilterAndSave = true;
    std::cout << "apply radius outlier removal filter and save the results into .pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-vfilter") >= 0)
  {
    VoxelGrid = true;
    std::cout << "apply voxel grid filter\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-pfilter") >= 0)
  {
    Passthrough = true;
    std::cout << "apply voxel grid filter and save the results into .pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-pandsave") >= 0)
  {
    PFilterAndSave = true;
    std::cout << "apply voxel grid filter and save the results into .pcd file\n";
  }
  else
  {
    printUsage (argv[0]);
    return 0;
  }



  color_cloud_ptr = LoadPointFile(loadfilename);







  // create a visualzer for each situation, pass the point cloud pointer to each function 
  pcl::visualization::PCLVisualizer::Ptr viewer;
  if (simple)
  {
    viewer = simpleVis(color_cloud_ptr);
  }
  else if (rgb)
  {
    viewer = rgbVis(color_cloud_ptr);
  }
  else if (statistical)
  {
    viewer = StatisticalFilter(basic_cloud_ptr);
  }
  else if (radiusOutlierRemoval)
  {
    viewer = RadiusOutlierRemovalFilter(basic_cloud_ptr);
  }
  else if (sFilterAndSave)
  {
    viewer = StatisticalFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (rFilterAndSave)
  {
    viewer = RadiusOutlierRemovalFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (VoxelGrid)
  {
    viewer = VoxelGridFilter(basic_cloud_ptr);
  }
  else if (VFilterAndSave)
  {
    viewer = VoxelGridFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (Passthrough)
  {
    viewer = PassThroughFilter(basic_cloud_ptr);
  }
  else if (PFilterAndSave)
  {
    viewer = PassThroughFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  


  //--------------------
  // -----Main loop-----
  //--------------------
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce (10);
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
  }
}