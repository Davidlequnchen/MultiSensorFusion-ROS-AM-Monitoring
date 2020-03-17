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



// define global values
pcl::PointXYZ min_pt, max_pt;

std::string loadfilename = "flatslow.pcd";
std::string savefilename = "test_filtered.txt";
std::string PointToPlaneDistance_filename = "PointToPlaneDistance_filename.txt";
std::string plane_coefficient_filename = "plane_coefficient_filename.txt";

float leafsize = 0.002f; // 2mm
float StddevMulThresh = 1.5; // this parameter is for statistical filter 
float DistanceThreshold = 0.0013; // this parameter is for plannar segmentation
float CylinderDistanceThreshold = 0.2;
float CylinderRadiusLimit = 0.1; // 1m
int highest_plane_index = 0;

float planeheight[MAX_PLANE_NUMBER] = {}; // define an array with maximum 10 members to store the value of the plane height for each plane found
//pcl::ModelCoefficients::Ptr coefficients_plane_list[MAX_PLANE_NUMBER] = {}; // define an Array of Pointers, stores the coefficent of the plane that been segmented
//pcl::PointIndices::Ptr inliers_plane_list[MAX_PLANE_NUMBER] = {}; // define a pointer array to stores the inliers indices of the segmented plane
//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_lst[MAX_PLANE_NUMBER] (new pcl::PointCloud<pcl::PointXYZ>); // store the segmented cloud
std::vector < pcl::PointCloud<pcl::PointXYZ>::Ptr, Eigen::aligned_allocator <pcl::PointCloud<pcl::PointXYZ>::Ptr > > sourceClouds;
// vector toe store the coefficient plane pointer
std::vector < pcl::ModelCoefficients::Ptr, Eigen::aligned_allocator <pcl::ModelCoefficients::Ptr> > plane_coefficient_vector;

std::vector < double > point_to_plane_distance_vector;






// -------------------------------------------
// -----Create global point cloud pointer-----
// -------------------------------------------
pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr color_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
//cloud_filtered stores cloud after filtering (inliers)
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
// filtered_part stores removal parts after filtering
pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_part (new pcl::PointCloud<pcl::PointXYZ>);
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

  std::cout << "\n\nUsage: "<<progName<<" [options] [-load filename] [-save filename] \n"
            << "[-savePointToPlaneDistance PointToPlaneDistance_filename] [-leafsize /float] [-DistanceThre /float]"
            << "[-Stddev /float]\n\n"
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
void savePointFile (std::string fileName, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) 
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



// save the point to plane distance value into a txt file
void savePointToPlaneDistance (std::string filename, std::vector< double > distance )
{
  std::ofstream output_file(filename);
  std::ostream_iterator<double> output_iterator(output_file, "\n");
  std::copy(distance.begin(), distance.end(), output_iterator);
}





// Function to find distance between point and a plane (here we calculate distance between origin 0,0,0 and plane ax+by+cz+d=0) 
float shortest_distance(float a, float b, float c, float d) // pass in 4 plane coefficient
{ //Distance = (| a*x1 + b*y1 + c*z1 + d |) / (sqrt( a*a + b*b + c*c))
  // d = fabs((d)); 
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
void  StatisticalFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // initialize the point cloud filter for future usage
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);

  
  // Create the filtering object
  pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  sor.setMeanK (100);            // set K mean value: he number of neighbors to analyze for each point 
  sor.setStddevMulThresh (1.5); // set standard deviation multiplier threshold, any point has property larger than this will be removed
  sor.filter (*cloud_filtered); // return the cloud after filtering(inlier) and store it into cloud_filtered

  

  // This is to get the outlier(the filtered part)
  sor.setNegative (true);
  sor.filter (*filtered_part);
  
}


void  RadiusOutlierRemovalFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  //---The user specifies a number of neighbors which every index -----------------
  //---must have within a specified radius to remain in the PointCloud. ----------


  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

 

  //create a filter object
  pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
  // build the filter
  outrem.setInputCloud(cloud);
  outrem.setRadiusSearch(0.9);
  outrem.setMinNeighborsInRadius (2);
  // apply filter
  outrem.filter (*cloud_filtered);


  // This is to get the outlier(the filtered part)
  outrem.setNegative (true);
  outrem.filter (*filtered_part);


  
}

void  VoxelGridFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);


   // Create the filtering object
  pcl::VoxelGrid<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  // downsampling leaf size of 1cm
  sor.setLeafSize (leafsize, leafsize, leafsize);
  sor.filter (*cloud_filtered);

  
  
  // This is to get the outlier(the filtered part)
  //sor.setNegative (true);
  //sor.filter (*filtered_part);


}


void  PassThroughFilter (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
  // define a cloud_filtered to store the cloud after filtering
  //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>);

  // Create the filtering object
  pcl::PassThrough<pcl::PointXYZ> pass;
  pass.setInputCloud (cloud);
  pass.setFilterFieldName ("z");
  pass.setFilterLimits (0.0, 1.0);
  //pass.setFilterLimitsNegative (true);
  pass.filter (*cloud_filtered);

}


// ----------------------------------------
// ----------Segmentation functions--------
// ----------------------------------------


void normal_segmentation (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
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
  cloud_stored = cloud_filtered;

  //----------------------------------------------------------------------------
  //---------------------- extract cylinder from non-planer --------------------
  //----------------------------------------------------------------------------

  extract.setNegative(true);// extract the outlier (removal part)
  extract.filter(*cloud_nonplanner); // now cloud_nonplanner  is the non-planer part
  //filtered_part = cloud_nonplanner;
  extract.setNegative(true);// extract the outlier (removal part)
  extract.filter(*filtered_part); 

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
	  std::cerr << "PointCloud representing the cylindrical component: " << cloud_cylinder->points.size () << " data points." << std::endl;
	  extract.setNegative (true);
    extract.filter (*filtered_part); // the rest part are the removal(abandoned part), we will show this part in red   
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
	  std::cerr << "PointCloud representing the cloud_sphere component: " << cloud_sphere->points.size () << " data points." << std::endl;
	  extract.setNegative (true);
    extract.filter (*filtered_part); // the rest part are the removal(abandoned part), we will show this part in red   
  }
  
  //savePointFile(savefilename, cloud_stored);


}


// remove all plannar part, return the desired shape
void shape_segmentation (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::SACSegmentation<pcl::PointXYZ> seg; 

  // required dataset
  pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices);
  cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); // final filtering result
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);
  cloud_nonplanner.reset(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ> segmented_cloud;


 
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
  
  //---------------------------segment the largest plane---------------------------------------------------------------------------------
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
  extract.filter (*filtered_part);//get the outlier out of the largest plane
  
  //------apply normal segmentation to the non-planner, to get the desired shape-----------------------------
  normal_segmentation(filtered_part); 
  

}

// return the largest plane
void plannar_segmentation (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
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


  // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_PLANE); 
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (1000);
  seg.setDistanceThreshold (DistanceThreshold);

  
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

  
  // extract.setNegative(true);// extrect the outlier (removal part)
  // extract.filter(*filtered_part);

}


// find all the plane one by one from largest to smallest
void multi_plannar_segmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
  //define objects needed
  pcl::ExtractIndices<pcl::PointXYZ> extract;
  pcl::SACSegmentation<pcl::PointXYZ> seg; 
  
   // required dataset
  // pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients);
  pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices);
  // cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); 
  filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);


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
  while (cloud->points.size () > 0.1 * nr_points)// 10% of the original cloud is still there, will be considered as noise
  {
    // color setting -- for different plane
    if (number_of_plane == 0){ // white
      color_r = 255;
      color_g = 255;
      color_b = 255;
    }
    else if(number_of_plane == 1){//blue
      color_r = 0;
      color_g = 0;
      color_b = 255;
    }
    else if(number_of_plane == 2){//green
      color_r = 0;
      color_g = 255;
      color_b = 0;
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


    // Create the filtering object
    extract.setNegative (true);
    extract.filter (*filtered_part);//outlier part
    cloud.swap (filtered_part);
    number_of_plane++;
  }


  extract.setNegative(true);// extrect the outlier (removal part): non-plannar dots, niether noise defects
  extract.filter(*filtered_part);


  // --------------------get the target plane from the point cloud -----------------

  // const int N = sizeof(planeheight) / sizeof(float); // number of elements
  // highest_plane_index = std::distance(planeheight, std::max_element(planeheight, planeheight + N));
  highest_plane_index = std::distance(planeheight, std::min_element(planeheight, planeheight+number_of_plane ));
  
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

}

void curve_segmentation(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
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
  cloud_stored = cloud_filtered;
  std::cerr << "PointCloud representing the cylindrical component: " << cloud_stored->points.size () << " data points." << std::endl;



}




void EuclideanClusterExtraction (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
    // Creating the KdTree object for the search method of the extraction
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud (cloud); // move the input cloud into the Kd Tree
    
    //cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); // final filtering result
    //filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);


    // create a visualizer
    pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
    viewer->setBackgroundColor (0, 0, 0); // set background black


    
    std::vector<pcl::PointIndices> cluster_indices;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
    ec.setClusterTolerance (0.02); // 2cm
    ec.setMinClusterSize (1000);
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
      // std::stringstream ss;
      // ss << "cloud_cluster_" << j << ".pcd";
      // writer.write<pcl::PointXYZ> (ss.str (), *cloud_cluster, false); 
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
  
  pcl::console::parse_argument (argc, argv, "-load", loadfilename);
  pcl::console::parse_argument (argc, argv, "-save", savefilename);
  pcl::console::parse_argument (argc, argv, "-leafsize", leafsize);
  pcl::console::parse_argument (argc, argv, "-Stddev", StddevMulThresh);
  pcl::console::parse_argument (argc, argv, "-savePointToPlaneDistance", PointToPlaneDistance_filename);
  pcl::console::parse_argument (argc, argv, "-DistanceThre", DistanceThreshold);
  pcl::console::parse_argument (argc, argv, "-CylinderRadiusLimit", CylinderRadiusLimit);
  pcl::console::parse_argument (argc, argv, "-CylinderDistanceThreshold", CylinderDistanceThreshold);



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
    std::cout << "find each plane with different color, get plane coefficient\n";
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
    StatisticalFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (radiusOutlierRemoval)
  {
    RadiusOutlierRemovalFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (VoxelGrid)
  {
    VoxelGridFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (Passthrough)
  {
    PassThroughFilter(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (NormalSegmentation)
  {
    normal_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_stored);
  }
   else if (largestPlane)
  {
    plannar_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
   else if (multiPlannarSeg)
  {
    multi_plannar_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, sourceClouds[highest_plane_index]);
  }
  else if (EuclideanExtraction)
  {
    EuclideanClusterExtraction(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (ShapeSeg)
  {
    shape_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_stored);
  }
  else if (curveSeg)
  {
    curve_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_stored);
  }
  
  //----------------------------------
  // -----Main visualization loop-----
  //----------------------------------
  // while (!viewer->wasStopped ())
  // {
  //   viewer->spinOnce (10);
  //   std::this_thread::sleep_for(std::chrono::milliseconds(2));
  // }

 
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
