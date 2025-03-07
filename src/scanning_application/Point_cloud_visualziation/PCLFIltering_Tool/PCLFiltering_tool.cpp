#include <iostream>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <fstream>
 
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
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/kdtree/kdtree.h>

//Boost Library
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#define MAX_PLANE_NUMBER 10


//using namespace std::literals::chrono_literals;

// define global values
pcl::PointXYZ min_pt, max_pt;

std::string loadfilename = "flatslow.pcd";
std::string savefilename = "test_filtered.txt";
std::string plane_coefficient_filename = "plane_coefficient_filename.txt";
std::string PointToPlaneDistance_filename = "PointToPlaneDistance_filename.txt";
std::string NormalEstimation_filename = "NormalEstimation_filename.txt";

float leafsize = 0.0002f; // m
float StddevMulThresh = 1.5; // this parameter is for statistical filter 
float DistanceThreshold = 0.0013; // this parameter is for plannar segmentation
float CylinderDistanceThreshold = 0.1;
float zmin = -0.237;
float zmax = 0;
float CylinderRadiusLimit = 0.1; // 1m
int highest_plane_index = 0;

float planeheight[MAX_PLANE_NUMBER] = {}; // define an array with maximum 10 members to store the value of the plane height for each plane found
//pcl::ModelCoefficients::Ptr coefficients_plane_list[MAX_PLANE_NUMBER] = {}; // define an Array of Pointers, stores the coefficent of the plane that been segmented
//pcl::PointIndices::Ptr inliers_plane_list[MAX_PLANE_NUMBER] = {}; // define a pointer array to stores the inliers indices of the segmented plane
//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_lst[MAX_PLANE_NUMBER] (new pcl::PointCloud<pcl::PointXYZ>); // store the segmented cloud
std::vector < pcl::PointCloud<pcl::PointXYZ>::Ptr, Eigen::aligned_allocator <pcl::PointCloud<pcl::PointXYZ>::Ptr > > sourceClouds;
// std::vector <pcl::PointCloud<pcl::PointXYZ>, Eigen::aligned_allocator<pcl::PointXYZ> > sourceClouds; 
// vector to store the coefficient plane pointer
std::vector < pcl::ModelCoefficients::Ptr, Eigen::aligned_allocator <pcl::ModelCoefficients::Ptr> > plane_coefficient_vector;
pcl::ModelCoefficients::Ptr plane_coefficient_top (new pcl::ModelCoefficients); // this is for passthrough segementation
// vector to store the point to Plane distance
std::vector < double > point_to_plane_distance_vector;
// vector to store the estimated normal vector
// std::vector < double point_normal[4] > normal_estimation_vector;
std::vector < std::array<float, 4> > normal_estimation_vector ;



// global point cloud viewer for viewing target plane
pcl::visualization::PCLVisualizer::Ptr target_viewer (new pcl::visualization::PCLVisualizer ("tartget plane after segmentation"));




// -------------------------------------------
// -----Create global point cloud pointer-----
// -------------------------------------------
pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr color_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
//cloud_filtered stores cloud after filtering (inliers)
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
// filtered_part stores removal parts after filtering
pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_part (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr bottom_plate (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_stored (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PCDWriter writer;

// required dataset
pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients), coefficients_cylinder (new pcl::ModelCoefficients), coefficients_sphere(new pcl::ModelCoefficients);
pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices), inliers_cylinder (new pcl::PointIndices), inliers_sphere(new pcl::PointIndices);
pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);// norms for all the points
pcl::PointCloud<pcl::Normal>::Ptr cloud_normals_nonplanner (new pcl::PointCloud<pcl::Normal>);// normals for non-planner part
pcl::PointCloud<pcl::Normal>::Ptr cloud_normals_nonplannerorcylinder (new pcl::PointCloud<pcl::Normal>);// normals for non-planner, non-cylinder part
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_nonplanner (new pcl::PointCloud<pcl::PointXYZ>);// stores the non planner part after first filterig
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_nonplanerorcylinder (new pcl::PointCloud<pcl::PointXYZ>);// stores the non planner, non-sylinder part after first filterig




// ------------------------------------
// ----------local functions
// ------------------------------------
void
printUsage (const char* progName)
{
  // --------------
  // -----Help-----
  // --------------

  std::cout << "\n\nUsage: "<<progName<<" [options] [-load filename] [-save filename] [-saveCoefficientPlaneName plane_coefficient_filename]\n"
            << "[-savePointToPlaneDistance PointToPlaneDistance_filename] [-saveNormalEstimation NormalEstimation_filename][-leafsize /float] [-DistanceThre /float]"
            << "[-Stddev /float] [-zmin /float] [-zmax /float]\n\n"
            << "default parameters: -leafsize 0.0002 -DistanceThre 0.0013 -Stddev 1.5"
            << "Options:\n"
            << "-------------------------------------------\n"
            << "-h                    this help\n"
            << "-s                    Simple visualisation\n"
            << "-sfilter              apply statistical filter\n"
            << "-rfilter              apply radius outlier removal filter\n"
            << "-vfilter              apply voxel grid removal filter\n"
            << "-pfilter              apply passthrough filter\n"
            << "-NormalSegmentation   normal segmentation, get planer cylindrical and sphere surfaces\n"
            << "-largestPlane         planner segmentation filter(return largest plane)\n"
            << "-multiPlannarSeg      multiple plannar segmentation to get all the plane\n"
            << "-passThroughSeg       pass though segmentation to get the top plane\n"
            << "-EuclideanExtraction  Apply Euclidean Clustering Extraction method to segment point cloud\n"
            << "-ShapeSeg             remove the largest plane and return the desired shape\n"
            << "-curveSeg             find the cylindrical curve shape\n"


            << "\n\n";
}

// Load a point cloud to normal cloud pointer from a 'pcd' file, with fileName as a parameter
// return point cloud pointer 
pcl::PointCloud<pcl::PointXYZ>::Ptr  LoadPointFile (std::string fileName) 
{
    try
    {   // local cloud pointer to store point cloud temporarily
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
        

        //load pcd file into this cloud pointer
        pcl::io::loadPCDFile (fileName, *cloud);


        return (cloud);
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
void savePointFile (std::string fileName, pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud) 
{
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



// save the highest plane coefficient a,b,c,d into a txt file
void saveCoefficientPlane (std::string filename, pcl::ModelCoefficients::Ptr coefficients_plane )
{
  // define a output file object
  std::ofstream outfile;
  // std::ios_base::app -- All output operations are performed at the end of the file, appending the content to the current content of the file
  outfile.open(filename, std::ios_base::app);//std::ios_base::app
  // write a b c d coefficeint of the plane into this file
  outfile << coefficients_plane->values[0] << " " << coefficients_plane->values[1] << " " << coefficients_plane->values[2] << " " << coefficients_plane->values[3];
}


// save the point to plane distance value into a txt file
void savePointToPlaneDistance (std::string filename, std::vector< double > distance )
{
  std::ofstream output_file(filename);
  std::ostream_iterator<double> output_iterator(output_file, "\n");
  std::copy(distance.begin(), distance.end(), output_iterator);
}

// save the normal estimation results(normal vector and curvature) into a txt file
void saveNormalEstimation (std::string filename, std::vector < std::array<float, 4> > normal_estimation_vector)
{ 
  // method of put a vector into a txt file
  std::ofstream output_file;
  output_file.open(filename, std::ios_base::app);//std::ios_base::app
  int i = 0;
  while (i < normal_estimation_vector.size())
  {
    output_file << normal_estimation_vector[i][0] << " " << normal_estimation_vector[i][1]  << " " << normal_estimation_vector[i][2]  << " " << normal_estimation_vector[i][3] << "\n";
    i++; 
  }
  
}





// Function to find distance between point and a plane (here we calculate distance between origin 0,0,0 and plane ax+by+cz+d=0) 
float shortest_distance(float a, float b, float c, float d) // pass in 4 plane coefficient
{ //Distance = (| a*x1 + b*y1 + c*z1 + d |) / (sqrt( a*a + b*b + c*c))
  d = fabs((d)); 
  float e = sqrt(a * a + b * b + c * c); 
  float distance = d/e;
  std::cout << "Perpendicular distance is " << distance <<std::endl; 
  return distance; 
} 



pcl::visualization::PCLVisualizer::Ptr simpleVis (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // --------------------------------------------
  // -----Open 3D viewer and add point cloud-----
  // --------------------------------------------
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud<pcl::PointXYZ> (cloud, "sample cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();
  return (viewer);
}


// ------------------------------------
// ----------Point Cloud Filter--------
// ------------------------------------

// input: point cloud 
// output: point cloud visualizer(viewer) pointer
pcl::visualization::PCLVisualizer::Ptr  StatisticalFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // -------------------------------------------------------
  // -----read the point cloud and apply statistical filtering
  // -----return the cloud after filtering(inlier) and filtered part(outlier)in red----
  // -----Open the 3D viewer and show the filtered cloud--------------------------
  // ---------------------------------------------------------

  // initialize the point cloud filter for future usage
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black
  
  // Create the filtering object
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (1.5); // set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud_filtered); // return the cloud after filtering(inlier) and store it into cloud_filtered

  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  // This is to get the outlier(the filtered part)
  sor.setNegative (true);
  sor.filter (*filtered_part);
  
  // show the filtered part in red
  //pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (filtered_part, 255, 0, 0);
  //viewer->addPointCloud(filtered_part, red_handler, "filtered part");
  //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "filtered part");
  viewer->addCoordinateSystem (0.02);
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

  // This is to get the outlier(the filtered part)
  outrem.setNegative (true);
  outrem.filter (*filtered_part);


  viewer->addCoordinateSystem (0.02);
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
  sor.setLeafSize (leafsize, leafsize, leafsize);
  sor.filter (*cloud_filtered);

  
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_handler (cloud_filtered, 255, 255, 255);
  viewer->addPointCloud(cloud_filtered, color_handler, "cloud after filtering");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  // viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  // viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  // This is to get the outlier(the filtered part)
  //sor.setNegative (true);
  //sor.filter (*filtered_part);


  viewer->addCoordinateSystem (0.02);
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
  pass.setFilterLimits (-0.238, 0);
  //pass.setFilterLimitsNegative (true);
  pass.filter (*cloud_filtered);


  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();

  return (viewer);

}


// ----------------------------------------
// ----------Segmentation functions--------
// ----------------------------------------


pcl::visualization::PCLVisualizer::Ptr normal_segmentation (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::ExtractIndices<pcl::Normal> extract_normals;
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg; 

  // required dataset resets
  cloud_filtered.reset (new pcl::PointCloud<pcl::PointXYZ>); // planner part result
  filtered_part.reset (new pcl::PointCloud<pcl::PointXYZ>); // the part be removed(noise)
  cloud_stored.reset (new pcl::PointCloud<pcl::PointXYZ>);
  coefficients_plane.reset (new pcl::ModelCoefficients);
  coefficients_cylinder.reset (new pcl::ModelCoefficients);
  coefficients_sphere.reset (new pcl::ModelCoefficients);
  inliers_plane.reset (new pcl::PointIndices);
  inliers_cylinder.reset (new pcl::PointIndices);
  inliers_sphere.reset (new pcl::PointIndices);
  cloud_normals.reset (new pcl::PointCloud<pcl::Normal>); // stores norms for all the points
  cloud_normals_nonplanner.reset (new pcl::PointCloud<pcl::Normal>); // normals for non-planner part 
  cloud_normals_nonplannerorcylinder.reset (new pcl::PointCloud<pcl::Normal>); 
  cloud_nonplanner.reset (new pcl::PointCloud<pcl::PointXYZ>);// stores the non planner part after first filterig
  cloud_nonplanerorcylinder.reset (new pcl::PointCloud<pcl::PointXYZ>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("normal segmentation viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black

  // apply statistical outlier removal to get rid of the noise 
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (StddevMulThresh); // defalt 1.5, set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud); // return the cloud after filtering(inlier) and store it into cloud


  // Estimate point normals(all points)
  ne.setSearchMethod (tree);
  ne.setInputCloud (cloud);
  ne.setKSearch (100);              // value for K, set the value here
  ne.compute (*cloud_normals);

  //----------------------------------------------------------------------------
  //---------------------- extract all the plannar part---- --------------------
  //----------------------------------------------------------------------------

  // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_NORMAL_PLANE); // a model for determining plane models using an additional constraint: the surface normals at each inlier point
                                                  // has to be parallel to the surface normal of the output plane, within a maximum specified angular deviation
  seg.setNormalDistanceWeight (0.1);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (100);
  seg.setDistanceThreshold (0.001); //1cm
  seg.setInputCloud (cloud);
  seg.setInputNormals (cloud_normals);
  // get the inliers plane indices after segmentation
  seg.segment (*inliers_plane, *coefficients_plane);
  std::cerr << "Plane coefficients: " << *coefficients_plane << std::endl;

  // Extract the planar inliers from the input cloud
  extract.setInputCloud (cloud);
  extract.setIndices (inliers_plane);
  extract.setNegative (false);
  // Write the planar inliers to disk
  extract.filter (*cloud_filtered);

  *cloud_stored = *cloud_filtered;
  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "planer cloud"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "planer cloud");// visualize the planer cloud in white
  

  //----------------------------------------------------------------------------
  //---------------------- extract cylinder from non-planer --------------------
  //----------------------------------------------------------------------------

  extract.setNegative(true);// extract the outlier (removal part)
  extract.filter(*cloud_nonplanner); // now cloud_nonplanner  is the non-planer part
  //filtered_part = cloud_nonplanner;
  // extract.setNegative(true);// extract the outlier (removal part)
  // extract.filter(*filtered_part); 

  extract_normals.setNegative (true);
  extract_normals.setInputCloud (cloud_normals);
  extract_normals.setIndices (inliers_plane);
  extract_normals.filter (*cloud_normals_nonplanner); //extract the norm for non-planner part(get rid of the inliers)


  // Create the segmentation object for cylinder segmentation and set all the parameters
  seg.setOptimizeCoefficients (true);
  seg.setModelType (pcl::SACMODEL_CYLINDER);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setNormalDistanceWeight (0.1); //set the surface normals influence to a weight of 0.1
  seg.setMaxIterations (10000);
  seg.setDistanceThreshold (0.2); // imposing a distance threshold from each inlier point to the model no greater than xx
  seg.setRadiusLimits (0, 0.1);// limit the radius of the cylindrical model to be smaller than 10cm.
  seg.setInputCloud (cloud_nonplanner); // input cloud is the outlier (non-planner part)
  seg.setInputNormals (cloud_normals_nonplanner);

  // Obtain the cylinder inliers and coefficients
  seg.segment (*inliers_cylinder, *coefficients_cylinder);
  std::cerr << "Cylinder coefficients: " << *coefficients_cylinder << std::endl;

  // Write the cylinder inliers to disk
  extract.setInputCloud (cloud_nonplanner);
  extract.setIndices (inliers_cylinder);
  extract.setNegative (false);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cylinder (new pcl::PointCloud<pcl::PointXYZ>);
  extract.filter (*cloud_cylinder);
  
  if (cloud_cylinder->points.empty ()) 
    std::cerr << "Can't find the cylindrical component." << std::endl;
  else
  {
    *cloud_stored += *cloud_cylinder;
    // we will show the cylinder in green color
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green_handler (cloud_cylinder, 0, 255, 0);
    viewer->addPointCloud(cloud_cylinder, green_handler, "cylinder");
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cylinder");

	  std::cerr << "PointCloud representing the cylindrical component: " << cloud_cylinder->points.size () << " data points." << std::endl;
	  // extract.setNegative (true);
    // extract.filter (*filtered_part); // the rest part are the removal(abandoned part), we will show this part in red   
  }


  //----------------------------------------------------------------------------
  //---------------------- extract sphere from the rest --------------------
  //----------------------------------------------------------------------------
  

  extract.setNegative(true);// extract the outlier (non planar, non cylinder)
  extract.filter(*cloud_nonplanerorcylinder); // put into cloud_nonplanerorcylinder
  
  extract_normals.setNegative (true);
  extract_normals.setInputCloud (cloud_normals_nonplanner);
  extract_normals.setIndices (inliers_cylinder);
  extract_normals.filter (*cloud_normals_nonplannerorcylinder); //extract the norm for non-planner and non-sphere
  
  // Create the segmentation object for sphere segmentation and set all the parameters
  seg.setOptimizeCoefficients (true);
  seg.setModelType (pcl::SACMODEL_NORMAL_SPHERE);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setNormalDistanceWeight (0.1); //set the surface normals influence to a weight of 0.1
  seg.setMaxIterations (10000);
  seg.setDistanceThreshold (0.005); // imposing a distance threshold from each inlier point to the model no greater than 5mm
  seg.setRadiusLimits (0, 0.1);// limit the radius of the cylindrical model to be smaller than 10cm.
  seg.setInputCloud (cloud_nonplanerorcylinder); // input cloud is the outlier (non-planner, non_cylinder part)
  seg.setInputNormals (cloud_normals_nonplannerorcylinder);

  // Obtain the sphere inliers and coefficients
  seg.segment (*inliers_sphere, *coefficients_sphere);
  std::cerr << "coefficients_sphere: " << *coefficients_sphere << std::endl;

  // Write the sphere inliers to disk
  extract.setInputCloud (cloud_nonplanerorcylinder);
  extract.setIndices (inliers_sphere);
  extract.setNegative (false);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_sphere (new pcl::PointCloud<pcl::PointXYZ>);
  extract.filter (*cloud_sphere);

  if (cloud_sphere->points.empty ()) 
    std::cerr << "Can't find the cloud_sphere component." << std::endl;
  else
  {
    *cloud_stored += *cloud_sphere;
    // we will show the cloud_sphere in blue color
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> blue_handler (cloud_sphere, 0, 0, 250);
    viewer->addPointCloud(cloud_sphere, blue_handler, "cloud_sphere");
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud_sphere");

	  std::cerr << "PointCloud representing the cloud_sphere component: " << cloud_sphere->points.size () << " data points." << std::endl;
	  extract.setNegative (true);
    extract.filter (*filtered_part); // the rest part are the removal(abandoned part), we will show this part in red   
  }
  
  //savePointFile(savefilename, cloud_stored);
  
  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();

  return (viewer);

}


// remove all plannar part, return the desired shape
pcl::visualization::PCLVisualizer::Ptr shape_segmentation (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::SACSegmentation<pcl::PointXYZ> seg; 

  // required dataset
  pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); // final filtering result
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);
  //pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

 // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black
  pcl::visualization::PCLVisualizer::Ptr target_viewer;
  //target_viewer.reset (new pcl::visualization::PCLVisualizer ("tartget plane after segmentation"));
  //target_viewer->setBackgroundColor (0, 0, 0); // set background black


  // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_PLANE); 
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (1000);
  seg.setDistanceThreshold (DistanceThreshold); //13mm

  // apply statistical outlier removal to get rid of the noise 
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (StddevMulThresh); // defalt 1.5, set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud); // return the cloud after filtering(inlier) and store it into cloud
  // segment the largest plane
  seg.setInputCloud (cloud);
  seg.segment (*inliers_plane, *coefficients_plane);
  if (inliers_plane->indices.size () == 0)
  {
    std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
    //break;
  }

  // Extract the inliers
  extract.setInputCloud (cloud);
  extract.setIndices (inliers_plane);
  extract.setNegative (false);
  extract.filter (*cloud_filtered);
  std::cerr << "PointCloud representing the planar component: " << cloud_filtered->width * cloud_filtered->height << " data points." << std::endl;
  

  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add the largest planes points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");


  // Create the filtering object
  extract.setNegative (true);
  extract.filter (*filtered_part);//get the outlier out of the largest plane

  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (filtered_part, 255, 0, 0);
  viewer->addPointCloud(filtered_part, red_handler, "filtered part");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "filtered part");
  
  //apply normal segmentation to the filtered part, to get the desired shape
  target_viewer = normal_segmentation(filtered_part); 


  

  //target_viewer->addPointCloud<pcl::PointXYZ> (filtered_part, "segmented shape"); // add the segmented shape points into the viewer
  //target_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "segmented shape");
  //savePointFile(savefilename, cloud_stored);
  
  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();
  //target_viewer->addCoordinateSystem (0.02);
  //target_viewer->initCameraParameters ();

  return (viewer);

}

// return the largest plane
pcl::visualization::PCLVisualizer::Ptr plannar_segmentation (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::SACSegmentation<pcl::PointXYZ> seg; 

  // required dataset
  pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); // final filtering result
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black


  // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_PLANE); 
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (1000);
  seg.setDistanceThreshold (DistanceThreshold);

  //int i = 0, nr_points = (int) cloud->points.size ();
  // While 30% of the original cloud is still there
  //while (cloud->points.size () > 0.3 * nr_points)
  //{
    // Segment the largest planar component from the remaining cloud
    seg.setInputCloud (cloud);
    seg.segment (*inliers_plane, *coefficients_plane);
    if (inliers_plane->indices.size () == 0)
    {
      std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
      //break;
    }

    // Extract the inliers
    extract.setInputCloud (cloud);
    extract.setIndices (inliers_plane);
    extract.setNegative (false);
    extract.filter (*cloud_filtered);
    std::cerr << "PointCloud representing the planar component: " << cloud_filtered->width * cloud_filtered->height << " data points." << std::endl;

    // Create the filtering object
    extract.setNegative (true);
    extract.filter (*filtered_part);//outlier part
    //cloud.swap (filtered_part);
    //i++;
  //}

  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "cloud after filtering"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud after filtering");

  // extract.setNegative(true);// extrect the outlier (removal part)
  // extract.filter(*filtered_part);

  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();
  target_viewer->addCoordinateSystem (0.02);
  target_viewer->initCameraParameters ();
  return (viewer);

}


// find all the plane one by one from largest to smallest
pcl::visualization::PCLVisualizer::Ptr multi_plannar_segmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::SACSegmentation<pcl::PointXYZ> seg; 
  
  // required dataset ---------------------------------------------
  // pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices);
  // cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); 
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);
  //pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black
  target_viewer.reset (new pcl::visualization::PCLVisualizer ("tartget plane after segmentation"));
  target_viewer->setBackgroundColor (0, 0, 0); // set background black


   // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_PLANE); 
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (1000);//the maximum number of iterations the sample consensus method will run 
  seg.setDistanceThreshold (DistanceThreshold);//Distance to the model threshold (user given parameter). default: 0.001
  
  //-----process start -------------------------------------------------------------------------------------------------------
  
  //firstly,
   
  // the apply voxel grid filter to downsample the data
  // // Create the filtering object
  // pcl::VoxelGrid<pcl::PointXYZ> vox;
  // vox.setInputCloud (cloud);
  // // downsampling leaf size of 1cm - 0.01
  // vox.setLeafSize (leafsize, leafsize, leafsize);//2mm --- ideal value, lower or higher both got wrong results
  // vox.filter (*cloud);
  
  // apply statistical filter to get rid of the noise
   
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (StddevMulThresh); // defalt 1.5, set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud); // return the cloud after filtering(inlier) and store it into cloud
  



  //secondly, segment the plane in a loop
   
  int number_of_plane = 0, nr_points = (int) cloud->points.size ();
  int color_r = 255;
  int color_g = 255;
  int color_b = 255;
  // While 30% of the original cloud is still there
  //inliers->indices.size () == 0
  //while (cloud->points.size () > 0.1 * nr_points)
  while (cloud->points.size () > 0.1 * nr_points)// 10% of the original cloud is still there, will be considered as noise
  {
    // color setting -- for different plane
    if (number_of_plane == 0){ // white
      color_r = 255;
      color_g = 255;
      color_b = 255;
    }
    else if(number_of_plane == 1){//green
      color_r = 0;
      color_g = 255;
      color_b = 0;
    }
    else if(number_of_plane == 2){//blue
      color_r = 0;
      color_g = 0;
      color_b = 255;
    }
    else if(number_of_plane == 3){//purple
      color_r = 255;
      color_g = 0;
      color_b = 255;
    }
    else if(number_of_plane == 4){//yellow
      color_r = 255;
      color_g = 255;
      color_b = 0;
    }
    else if(number_of_plane == 5){//sky blue
      color_r = 0;
      color_g = 128;
      color_b = 255;
    }
    else if(number_of_plane == 6){//bright yellow
      color_r = 255;
      color_g = 255;
      color_b = 102;
    }
 
    
    //get the current segmented plane name
    std::ostringstream oss;
    oss << "segmented cloud" << number_of_plane << " " ;
    std::string cloud_name = oss.str();
    

    // define temporary coefficients_plane pointer, to store current plane coefficient, 
    // note it has to be inside this loop
    pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients);



    // Segment the largest planar component from the remaining cloud
    seg.setInputCloud (cloud);
    seg.segment (*inliers_plane, *coefficients_plane);
  
    std::cerr << "plannar coefficients of "<< cloud_name << "is: " << *coefficients_plane << std::endl;
    
    planeheight[number_of_plane] = shortest_distance(coefficients_plane->values[0],coefficients_plane->values[1], coefficients_plane->values[2], coefficients_plane->values[3]);

    if (inliers_plane->indices.size () == 0)
    {
      std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
      //break;
    }

    // define temporary point cloud pointer to store the current plane's point clouds
    // it has to be inside the while loop
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);

    // Extract the inliers
    extract.setInputCloud (cloud);
    extract.setIndices (inliers_plane);
    extract.setNegative (false);
    extract.filter (*cloud_filtered);
    std::cerr << "PointCloud representing the planar component: " << cloud_name << cloud_filtered->width * cloud_filtered->height << " data points." << std::endl;
    
    sourceClouds.push_back(cloud_filtered);// save this current cloud into a list array
    plane_coefficient_vector.push_back(coefficients_plane); // save current plane coefficent(a,b,c,d) inot the vector

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_handler (cloud_filtered, color_r, color_g, color_b);
    viewer->addPointCloud(cloud_filtered, color_handler, cloud_name);
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, cloud_name);



    // Create the filtering object
    extract.setNegative (true);
    extract.filter (*filtered_part);//outlier part
    cloud.swap (filtered_part);
    number_of_plane++;
  }


  extract.setNegative(true);// extrect the outlier (removal part): non-plannar dots, niether noise defects
  extract.filter(*filtered_part);

  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();
  

  // --------------------get the target plane from the point cloud -----------------

  //float highest_plane_value; // this is a pointer
  // get largest element from the array, go through from the first to the last element
  //float *highest_plane_value = std::max_element(planeheight[0], planeheight[i]); // find the largest value of plane height 
  //int highest_plane_index = std::distance(planeheight, std::max_element(planeheight[0], planeheight[i]));
  // highest_plane_value = std::max_element(planeheight[0], planeheight[i], // Lambda expression begins, absoute comparison
  //                                                                            [](float a, float b) {
  //                                                                           return (std::abs(a) < std::abs(b));
  //                                                                           } // end of lambda expression
  //                                                   );
  
  // float highest_plane_value = *std::max_element(planeheight, planeheight + number_of_plane + 1);
  // highest_plane_index = std::distance(planeheight, highest_plane_value);
  
  // const int N = sizeof(planeheight) / sizeof(float); // number of elements
  highest_plane_index = std::distance(planeheight, std::min_element(planeheight, planeheight+number_of_plane ));
    
  target_viewer->addPointCloud<pcl::PointXYZ> (sourceClouds[highest_plane_index], "target plane point cloud");
  target_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "target plane point cloud");
  target_viewer->addCoordinateSystem (0.02);
  target_viewer->initCameraParameters ();

  /*
  calculate distance of each point from sourceClouds[highest_plane_index], to the highest plane model with coefficient a,b,c,d
  save the output(distance) into another txt file.
  */
  //Let i be the element number which you want to access
  int i = 0;
  while (i < sourceClouds[highest_plane_index]->points.size () ) // loop to calculate the pointToPlaneDistanceSigned
  {
    // sourceClouds[highest_plane_index]->points[i] ----> the current point we are calculating
    /*
    double pcl::pointToPlaneDistanceSigned 	( const Point &	p,
		const Eigen::Vector4f & plane_coefficients ) 		
    */
    double Distance; // temporary double value to store current pointToPlaneDisntacne (signed)
    Distance = pcl::pointToPlaneDistanceSigned ( sourceClouds[highest_plane_index]->points[i], plane_coefficient_vector[highest_plane_index]->values[0]
                                                ,plane_coefficient_vector[highest_plane_index]->values[1]
                                                ,plane_coefficient_vector[highest_plane_index]->values[2]
                                                ,plane_coefficient_vector[highest_plane_index]->values[3]  );
    // savePointToPlaneDistance(PointToPlaneDistance_filename, Distance);
    point_to_plane_distance_vector.push_back(Distance);
    i++;
  }

  savePointToPlaneDistance(PointToPlaneDistance_filename, point_to_plane_distance_vector);

  // // Estimate normal vectors of the points -------------------------------------------------------------------------------------------------------------
  // // the apply voxel grid filter to downsample the data ==============================
  // // Create the filtering object
  // pcl::VoxelGrid<pcl::PointXYZ> vox;
  // vox.setInputCloud (sourceClouds[highest_plane_index]);
  // // downsampling
  // vox.setLeafSize (0.003f, 0.003f, 0.003f);//3mm --- ideal value, lower or higher both got wrong results
  // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_voxel_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  // vox.filter (*cloud_voxel_filtered);
  
  // std::cout << "PointCloud after filtering has: " << cloud->points.size ()  << " data points." << std::endl;

  // //=======================================


  // Create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  // ne.setInputCloud (cloud_voxel_filtered); // set input cloud as the highest plane after segmentation
  ne.setInputCloud (sourceClouds[highest_plane_index]);
  // Create an empty kdtree representation, and pass it to the normal estimation object.
  // Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  ne.setSearchMethod (tree);
  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
  // Use all neighbors in a sphere of radius 5mm
  ne.setRadiusSearch (0.005);
  //  Compute the features
  ne.compute (*cloud_normals);
  // compute function: for each point p in cloud P
  // 1. get the nearest neighbors of p
  // 2. compute the surface normal n of p
  // 3. check if n is consistently oriented towards the viewpoint and flip otherwise
  
  //The viewpoint is by default (0,0,0) and can be changed with:
  //setViewPoint (float vpx, float vpy, float vpz);


  // To compute a single point normal, use:
  // computePointNormal (const pcl::PointCloud<PointInT> &cloud, const std::vector<int> &indices, Eigen::Vector4f &plane_parameters, float &curvature);



  /*
  NormalEstimation estimates local surface properties (surface normals and curvatures)at each 3D point.
  If PointOutT is specified as pcl::Normal, the normal is stored in the first 3 components (0-2), and the curvature is stored in component 3.
  */
  // cloud_normals->points.size () should have the same size as the input cloud->points.size ()*
  int k = 0;
  while (k < cloud_normals->points.size () )  // while loop to get all the normal vector of the points
  {
    std::array< float, 4>  point_normal = {}; // initialize a temporory array to store the 4 component of pcl::Normal
    point_normal[0] = cloud_normals->points[k].normal_x;
    point_normal[1] = cloud_normals->points[k].normal_y;
    point_normal[2] = cloud_normals->points[k].normal_z;
    point_normal[3] = cloud_normals->points[k].curvature;
    // std::cerr << point_normal[0] << " " << point_normal[1] << "  "<< point_normal[2] << " " << point_normal[3] << std::endl;
    normal_estimation_vector.push_back (point_normal);
    k++;
  }

  saveNormalEstimation (NormalEstimation_filename, normal_estimation_vector);
  


  return (viewer);

}


// using pass though filter then using planner segemtation to get top plane
pcl::visualization::PCLVisualizer::Ptr pass_through_segmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::SACSegmentation<pcl::PointXYZ> seg; 
  
  // required dataset ---------------------------------------------
  plane_coefficient_top.reset(new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices);
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);
  bottom_plate.reset(new pcl::PointCloud<pcl::PointXYZ>);
  //pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black
  target_viewer.reset (new pcl::visualization::PCLVisualizer ("tartget plane after segmentation"));
  target_viewer->setBackgroundColor (0, 0, 0); // set background black


  // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_PLANE); 
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (1000);//the maximum number of iterations the sample consensus method will run 
  seg.setDistanceThreshold (DistanceThreshold);//Distance to the model threshold (user given parameter). default: 0.001
  


  // ----------------STEP 0: apply statistical filter to get rid of the noise---------------------------------------
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (StddevMulThresh); // defalt 1.5, set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud); // return the cloud after filtering(inlier) and store it into cloud
  // savePointFile("s_filtered.pcd", cloud);
  
  //------------------Step 1：　Voxel grid filter--------------------------------------

   // Create the filtering object
  pcl::VoxelGrid<pcl::PointXYZ> sor_voxel;
  sor_voxel.setInputCloud (cloud);
  // downsampling leaf size of 1cm
  sor_voxel.setLeafSize (leafsize, leafsize, leafsize);
  sor_voxel.filter (*cloud);
  // savePointFile("v_filtered.pcd", cloud);



  //----------------STEP 2:  apply passthough filter to get ride of the bottom plate-----------------------
  // define a cloud_filtered to store the cloud after filtering
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // Create the filtering object
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (zmin, zmax);
  // This is to get the outlier
  pass.setNegative (true);
  pass.filter (*bottom_plate);

  //pass.setFilterLimitsNegative (true);
  pass.setNegative (false);
  pass.filter (*cloud);

 
  
  // show the bottom plate
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (bottom_plate, 255, 255, 255);
  viewer->addPointCloud(bottom_plate, red_handler, "bottom plate");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "bottom plate");
  // viewer->addCoordinateSystem (0.02);
  // viewer->initCameraParameters ();
  
  
  //--------------STEP 3: Fit the plane------------------------------------------------------
  // name of the segemted plane
  std::string cloud_name = " TOP plannar surface ";

  // Segment the largest planar component from the remaining cloud
  seg.setInputCloud (cloud);
  seg.segment (*inliers_plane, *plane_coefficient_top);

  std::cerr << "plannar coefficients of "<< cloud_name << "is: " << *plane_coefficient_top << std::endl;
  
  // planeheight = shortest_distance(plane_coefficient_top->values[0], plane_coefficient_top->values[1], plane_coefficient_top->values[2], plane_coefficient_top->values[3]);

  if (inliers_plane->indices.size () == 0)
  {
    std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
    //break;
  }

  // Extract the inliers
  extract.setInputCloud (cloud);
  extract.setIndices (inliers_plane);
  extract.setNegative (false);
  extract.filter (*cloud_filtered);
  std::cerr << "PointCloud representing the planar component: " << cloud_name << cloud_filtered->width * cloud_filtered->height << " data points." << std::endl;
  

  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green_handler (cloud_filtered, 0, 255, 0); //green
  viewer->addPointCloud(cloud_filtered, green_handler, cloud_name);
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, cloud_name);
  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();

  // Create the filtering object
  extract.setNegative (true);
  extract.filter (*filtered_part);//outlier part

  
  // --------------------STEP 4: get the target plane from the point cloud -----------------

  target_viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "target plane point cloud");
  target_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "target plane point cloud");
  target_viewer->addCoordinateSystem (0.02);
  target_viewer->initCameraParameters ();


  
  /* --------------------STEP 5-------------------------------------------------------------
  calculate distance of each point from extracted plane with coefficient a,b,c,d to the origin save the output(distance) into another txt file.
  */
  //Let i be the element number which you want to access
  int i = 0;
  while (i < cloud_filtered->points.size () ) // loop to calculate the pointToPlaneDistanceSigned
  {
    double Distance; // temporary double value to store current pointToPlaneDisntacne (signed)
    Distance = pcl::pointToPlaneDistanceSigned (cloud_filtered->points[i], plane_coefficient_top->values[0]
                                                ,plane_coefficient_top->values[1]
                                                ,plane_coefficient_top->values[2]
                                                ,plane_coefficient_top->values[3]  );
    // savePointToPlaneDistance(PointToPlaneDistance_filename, Distance);
    point_to_plane_distance_vector.push_back(Distance);
    i++;
  }

  savePointToPlaneDistance(PointToPlaneDistance_filename, point_to_plane_distance_vector);
  

  // ------------------STEP 6 Estimate normal vectors of the points -----------------------------------------------------------------
  // Create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  // ne.setInputCloud (cloud_voxel_filtered); // set input cloud as the highest plane after segmentation
  ne.setInputCloud (cloud_filtered);
  // Create an empty kdtree representation, and pass it to the normal estimation object.
  // Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  ne.setSearchMethod (tree);
  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
  // Use all neighbors in a sphere of radius 5mm
  ne.setRadiusSearch (0.005);
  //  Compute the features
  ne.compute (*cloud_normals);
  

  /* --------------STEP 7: normal estimation------------------------------------------------------
  NormalEstimation estimates local surface properties (surface normals and curvatures)at each 3D point.
  If PointOutT is specified as pcl::Normal, the normal is stored in the first 3 components (0-2), and the curvature is stored in component 3.
  */
  // cloud_normals->points.size () should have the same size as the input cloud->points.size ()*
  int k = 0;
  while (k < cloud_normals->points.size () )  // while loop to get all the normal vector of the points
  {
    std::array< float, 4>  point_normal = {}; // initialize a temporory array to store the 4 component of pcl::Normal
    point_normal[0] = cloud_normals->points[k].normal_x;
    point_normal[1] = cloud_normals->points[k].normal_y;
    point_normal[2] = cloud_normals->points[k].normal_z;
    point_normal[3] = cloud_normals->points[k].curvature;
    // std::cerr << point_normal[0] << " " << point_normal[1] << "  "<< point_normal[2] << " " << point_normal[3] << std::endl;
    normal_estimation_vector.push_back (point_normal);
    k++;
  }
  saveNormalEstimation (NormalEstimation_filename, normal_estimation_vector);
  
  


  return (viewer);

}



pcl::visualization::PCLVisualizer::Ptr curve_segmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::ExtractIndices<pcl::Normal> extract_normals;
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> seg; 

  // required dataset resets
  cloud_filtered.reset (new pcl::PointCloud<pcl::PointXYZ>); // planner part result
  filtered_part.reset (new pcl::PointCloud<pcl::PointXYZ>); // the part be removed(noise)
  cloud_stored.reset (new pcl::PointCloud<pcl::PointXYZ>);
  coefficients_cylinder.reset (new pcl::ModelCoefficients);
  inliers_cylinder.reset (new pcl::PointIndices);
  cloud_normals.reset (new pcl::PointCloud<pcl::Normal>); // stores norms for all the points
  cloud_normals_nonplanner.reset (new pcl::PointCloud<pcl::Normal>); // normals for non-planner part 
  cloud_nonplanner.reset (new pcl::PointCloud<pcl::PointXYZ>);// stores the non planner part after first filterig

  // create a visualizer
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black
  target_viewer.reset (new pcl::visualization::PCLVisualizer ("tartget plane after segmentation"));
  target_viewer->setBackgroundColor (0, 0, 0); // set background black


  // apply statistical outlier removal to get rid of the noise 
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (StddevMulThresh); // defalt 1.5, set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud); // return the cloud after filtering(inlier) and store it into cloud
  

  // Estimate point normals(all points)
  ne.setSearchMethod (tree);
  ne.setInputCloud (cloud);
  ne.setKSearch (100);              // value for K, set the value here
  ne.compute (*cloud_normals); // get the norms for all the points

  //----------------------------------------------------------------------------
  //---------------------- extract all the curve shape------------------------
  //----------------------------------------------------------------------------
  // Create the segmentation object for cylinder segmentation and set all the parameters
  seg.setOptimizeCoefficients (true);
  seg.setModelType (pcl::SACMODEL_CYLINDER);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setNormalDistanceWeight (0.1); //set the surface normals influence to a weight of 0.1
  seg.setMaxIterations (10000);
  seg.setDistanceThreshold (CylinderDistanceThreshold); // imposing a distance threshold from each inlier point to the model no greater than xx
  seg.setRadiusLimits (0, CylinderRadiusLimit);// limit the radius of the cylindrical model to be smaller than the limit.
  seg.setInputCloud (cloud);
  seg.setInputNormals (cloud_normals);
  // Obtain the cylinder inliers and coefficients
  seg.segment (*inliers_cylinder, *coefficients_cylinder);
  std::cerr << "Cylinder coefficients: " << *coefficients_cylinder << std::endl;


  // Extract the planar inliers from the input cloud
  extract.setInputCloud (cloud);
  extract.setIndices (inliers_cylinder);
  extract.setNegative (false);
  // Write the planar inliers to disk
  extract.filter (*cloud_filtered);
  
  std::cerr << "PointCloud representing the cylindrical component: " << cloud_stored->points.size () << " data points." << std::endl;
  sor.setInputCloud (cloud_filtered);
  sor.setMeanK (80);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (0.2); // defalt 1.5, set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud_filtered); // return the cloud after filtering(inlier) and store it into cloud

  cloud_stored = cloud_filtered;

  extract.setNegative (true);
  extract.filter (*filtered_part);
  

  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green_handler (cloud_filtered, 0, 255, 0);
  viewer->addPointCloud(cloud_filtered, green_handler, "cylinder");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cylinder");

  




  target_viewer->addPointCloud<pcl::PointXYZ> (cloud_stored, "cylindrical part");
  target_viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cylindrical part");
  target_viewer->addCoordinateSystem (0.02);
  target_viewer->initCameraParameters ();



  return (viewer);

}







pcl::visualization::PCLVisualizer::Ptr EuclideanClusterExtraction (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
    // Create the filtering object: downsample the dataset using a leaf size of 1cm
    pcl::VoxelGrid<pcl::PointXYZ> vg;
    //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
    vg.setInputCloud (cloud);
    vg.setLeafSize (0.001f, 0.001f, 0.001f);
    vg.filter (*cloud);
    std::cout << "PointCloud after filtering has: " << cloud->points.size ()  << " data points." << std::endl; //*

    // Creating the KdTree object for the search method of the extraction
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud (cloud); // move the input cloud into the Kd Tree
    
    //cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); // final filtering result
    //filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PCDWriter writer;

    // create a visualizer
    pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor (0, 0, 0); // set background black


    std::vector<pcl::PointIndices> cluster_indices;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
    ec.setClusterTolerance (0.02); // 2cm
    ec.setMinClusterSize (100);
    ec.setMaxClusterSize (25000);
    ec.setSearchMethod (tree);
    ec.setInputCloud (cloud);
    ec.extract (cluster_indices); // get the cluster indices

    int j = 0;
    //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
    // loop over the cluster indices we got
    for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it)
    {
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
      // push back each point from the cluster into the new point cloud: cloud_cluster
      for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); ++pit)
          {
            cloud_cluster->points.push_back (cloud->points[*pit]);
          }
      cloud_cluster->width = cloud_cluster->points.size ();
      cloud_cluster->height = 1;
      cloud_cluster->is_dense = true;
     
      viewer->addPointCloud<pcl::PointXYZ> (cloud_cluster, "clusterd cloud"); // add points into the viewer
      viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "clusterd cloud");
  
      std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size () << " data points." << std::endl;
      std::stringstream ss;
      ss << "cloud_cluster_" << j << ".pcd";
      writer.write<pcl::PointXYZ> (ss.str (), *cloud_cluster, false); 
      j++;
    }

    //viewer->addPointCloud<pcl::PointXYZ> (cloud_cluster, "clusterd cloud"); // add points into the viewer
    //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "clusterd cloud");

    viewer->addCoordinateSystem (0.02);
    viewer->initCameraParameters ();

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
  bool simple(false), statistical(false), radiusOutlierRemoval(false);
  bool VoxelGrid(false), Passthrough(false),ShapeSeg(false), curveSeg(false);
  bool NormalSegmentation(false), largestPlane(false), EuclideanExtraction(false), multiPlannarSeg(false);
  bool passThroughSeg(false);

  pcl::console::parse_argument (argc, argv, "-load", loadfilename);
  pcl::console::parse_argument (argc, argv, "-save", savefilename);
  pcl::console::parse_argument (argc, argv, "-saveCoefficientPlaneName", plane_coefficient_filename);
  pcl::console::parse_argument (argc, argv, "-savePointToPlaneDistance", PointToPlaneDistance_filename);
  pcl::console::parse_argument (argc, argv, "-saveNormalEstimation", NormalEstimation_filename);
  pcl::console::parse_argument (argc, argv, "-leafsize", leafsize);
  pcl::console::parse_argument (argc, argv, "-Stddev", StddevMulThresh);
  pcl::console::parse_argument (argc, argv, "-DistanceThre", DistanceThreshold);
  pcl::console::parse_argument (argc, argv, "-CylinderRadiusLimit", CylinderRadiusLimit);
  pcl::console::parse_argument (argc, argv, "-CylinderDistanceThreshold", CylinderDistanceThreshold);
  pcl::console::parse_argument (argc, argv, "-zmin", zmin);
  pcl::console::parse_argument (argc, argv, "-zmax", zmax);




  if (pcl::console::find_argument (argc, argv, "-s") >= 0)
  {
    simple = true;
    std::cout << "Simple visualisation\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-sfilter") >= 0)
  {
    statistical = true;
    std::cout << "apply statistical(K nearest neighber method) filter\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-vfilter") >= 0)
  {
    VoxelGrid = true;
    std::cout << "apply voxel grid filter\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-rfilter") >= 0)
  {
    radiusOutlierRemoval = true;
    std::cout << "apply radius outlier removal filter\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-pfilter") >= 0)
  {
    Passthrough = true;
    std::cout << "apply pass through filter and save the results into pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-NormalSegmentation") >= 0)
  {
    NormalSegmentation = true;
    std::cout << "apply segmentation process and save the results into pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-largestPlane") >= 0)
  {
    largestPlane = true;
    std::cout << "find the largest plane and save the results into pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-multiPlannarSeg") >= 0)
  {
    multiPlannarSeg = true;
    std::cout << "find each plane with different color, get plane coefficient, save highest plane\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-passThroughSeg") >= 0)
  {
    passThroughSeg = true;
    std::cout << "apply passthrough segmentation process and save the results into pcd file\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-EuclideanExtraction") >= 0)
  {
    EuclideanExtraction = true;
    std::cout << "apply Euclidean Cluster Extraction, using Kd Tree to cluster the Point Cloud\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-ShapeSeg") >= 0)
  {
    ShapeSeg = true;
    std::cout << " remove the largest plane and return the desired shape\n";
  }
  else if (pcl::console::find_argument (argc, argv, "-curveSeg") >= 0)
  {
    curveSeg = true;
    std::cout << " find the curvature shape\n";
  }
  else
  {
    printUsage (argv[0]);
    return 0;
  }



  basic_cloud_ptr = LoadPointFile(loadfilename);


  // create a visualzer for each situation, pass the point cloud pointer to each function 
  pcl::visualization::PCLVisualizer::Ptr viewer;



  if (simple)
  {
    viewer = simpleVis(basic_cloud_ptr);
  }
  else if (statistical)
  {
    viewer = StatisticalFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (radiusOutlierRemoval)
  {
    viewer = RadiusOutlierRemovalFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (VoxelGrid)
  {
    viewer = VoxelGridFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (Passthrough)
  {
    viewer = PassThroughFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (NormalSegmentation)
  {
    viewer = normal_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_stored);
  }
   else if (largestPlane)
  {
    viewer = plannar_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
   else if (multiPlannarSeg)
  {
    viewer = multi_plannar_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, sourceClouds[highest_plane_index]);
    saveCoefficientPlane (plane_coefficient_filename, plane_coefficient_vector[highest_plane_index]);
  }
  else if (passThroughSeg)
  {
    viewer = pass_through_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
    saveCoefficientPlane (plane_coefficient_filename, plane_coefficient_top);
  }
  else if (EuclideanExtraction)
  {
    viewer = EuclideanClusterExtraction(basic_cloud_ptr);
    //savePointFile(savefilename, cloud_filtered);
  }
  else if (ShapeSeg)
  {
    viewer = shape_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_stored);
  }
   else if (curveSeg)
  {
    viewer = curve_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_stored);
  }
  

  // show the filtered part in red
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (filtered_part, 255, 0, 0);
  viewer->addPointCloud(filtered_part, red_handler, "filtered part");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "filtered part");



  //--------------------
  // -----Main loop-----
  //--------------------
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce (10);
    //std::this_thread::sleep_for(std::chrono::milliseconds(2));
    target_viewer->spinOnce (10);
  }
}



  //--------------------
  // -----reference-----
  //--------------------


// The following list describes the robust sample consensus estimators implemented:

//     SAC_RANSAC - RANdom SAmple Consensus
//     SAC_LMEDS - Least Median of Squares
//     SAC_MSAC - M-Estimator SAmple Consensus
//     SAC_RRANSAC - Randomized RANSAC
//     SAC_RMSAC - Randomized MSAC
//     SAC_MLESAC - Maximum LikeLihood Estimation SAmple Consensus
//     SAC_PROSAC - PROgressive SAmple Consensus

// As of PCL 1.0, the following models are supported:
//     SACMODEL_PLANE - used to determine plane models. The four coefficients of the plane are its Hessian Normal form: [normal_x normal_y normal_z d]
//     SACMODEL_LINE - used to determine line models. The six coefficients of the line are given by a point on the line and the direction of the line as: [point_on_line.x point_on_line.y point_on_line.z line_direction.x line_direction.y line_direction.z]
//     SACMODEL_CIRCLE2D - used to determine 2D circles in a plane. The circle's three coefficients are given by its center and radius as: [center.x center.y radius]
//     SACMODEL_SPHERE - used to determine sphere models. The four coefficients of the sphere are given by its 3D center and radius as: [center.x center.y center.z radius]
//     SACMODEL_CYLINDER - used to determine cylinder models. The seven coefficients of the cylinder are given by a point on its axis, the axis direction, and a radius, as: [point_on_axis.x point_on_axis.y point_on_axis.z axis_direction.x axis_direction.y axis_direction.z radius]
//     SACMODEL_PARALLEL_LINE - a model for determining a line parallel with a given axis, within a maximum specified angular deviation. The line coefficients are similar to SACMODEL_LINE.
//     SACMODEL_PERPENDICULAR_PLANE - a model for determining a plane perpendicular to an user-specified axis, within a maximum specified angular deviation. The plane coefficients are similar to SACMODEL_PLANE.
//     SACMODEL_NORMAL_PLANE - a model for determining plane models using an additional constraint: the surface normals at each inlier point has to be parallel to the surface normal of the output plane, within a maximum specified angular deviation. The plane coefficients are similar to SACMODEL_PLANE.
//     SACMODEL_PARALLEL_PLANE - a model for determining a plane parallel to an user-specified axis, within a maximim specified angular deviation. SACMODEL_PLANE.
//     SACMODEL_NORMAL_PARALLEL_PLANE - defines a model for 3D plane segmentation using additional surface normal constraints. The plane must lie parallel to a user-specified axis. SACMODEL_NORMAL_PARALLEL_PLANE therefore is equivallent to SACMODEL_NORMAL_PLANE + SACMODEL_PARALLEL_PLANE. The plane coefficients are similar to SACMODEL_PLANE.
