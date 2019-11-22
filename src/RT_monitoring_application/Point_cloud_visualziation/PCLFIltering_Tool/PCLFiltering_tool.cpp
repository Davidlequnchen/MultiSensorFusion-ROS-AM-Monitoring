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
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/kdtree/kdtree.h>

//Boost Library
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>



using namespace std::literals::chrono_literals;


// define global values
pcl::PointXYZ min_pt, max_pt;

std::string loadfilename = "blade.pcd";
std::string savefilename = "blade_filtered.txt";




// -------------------------------------------
// -----Create global point cloud pointer-----
// -------------------------------------------
pcl::PointCloud<pcl::PointXYZ>::Ptr basic_cloud_ptr (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZRGB>::Ptr color_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
//cloud_filtered stores cloud after filtering (inliers)
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
// filtered_part stores removal parts after filtering
pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_part (new pcl::PointCloud<pcl::PointXYZ>);
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

  std::cout << "\n\nUsage: "<<progName<<" [options]\n\n"
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
            << "-EuclideanExtraction  Apply Euclidean Clustering Extraction method to segment point cloud\n"


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
  sor.setStddevMulThresh (0.5); // set standard deviation multiplier threshold, any point has property larger than this will be removed
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
  viewer->setBackgroundColor (0255, 255, 255); // set background blacks

   // Create the filtering object
  pcl::VoxelGrid<pcl::PointXYZ> sor;
  sor.setInputCloud (cloud);
  // downsampling leaf size of 1cm
  sor.setLeafSize (0.002f, 0.002f, 0.002f);
  sor.filter (*cloud_filtered);

  
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color_handler (cloud_filtered, 0, 0, 0);
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
  pass.setFilterLimits (0.0, 1.0);
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


pcl::visualization::PCLVisualizer::Ptr plannar_norm_segmentation (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
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
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  viewer->setBackgroundColor (0, 0, 0); // set background black


  // Estimate point normals(all points)
  ne.setSearchMethod (tree);
  ne.setInputCloud (cloud);
  ne.setKSearch (100);              // value for K, set the value here
  ne.compute (*cloud_normals);

  // Create the segmentation object for the planar model and set all the parameters
  seg.setOptimizeCoefficients (true);// optional
  seg.setModelType (pcl::SACMODEL_NORMAL_PLANE); // a model for determining plane models using an additional constraint: the surface normals at each inlier point
                                                  // has to be parallel to the surface normal of the output plane, within a maximum specified angular deviation
  seg.setNormalDistanceWeight (0.1);
  seg.setMethodType (pcl::SAC_RANSAC);
  seg.setMaxIterations (100);
  seg.setDistanceThreshold (0.03);
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

  viewer->addPointCloud<pcl::PointXYZ> (cloud_filtered, "planer cloud"); // add points into the viewer
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "planer cloud");// visualize the planer cloud in white
  

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
  seg.setDistanceThreshold (0.05); // imposing a distance threshold from each inlier point to the model no greater than 5cm
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
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cylinder (new pcl::PointCloud<pcl::PointXYZ> ());
  extract.filter (*cloud_cylinder);
  if (cloud_cylinder->points.empty ()) 
    std::cerr << "Can't find the cylindrical component." << std::endl;
  else
  {
    // we will show the cylinder in green color
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green_handler (cloud_cylinder, 0, 255, 0);
    viewer->addPointCloud(cloud_cylinder, green_handler, "cylinder");
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cylinder");

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
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_sphere (new pcl::PointCloud<pcl::PointXYZ> ());
  extract.filter (*cloud_sphere);
  if (cloud_sphere->points.empty ()) 
    std::cerr << "Can't find the cloud_sphere component." << std::endl;
  else
  {
    // we will show the cloud_sphere in blue color
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> blue_handler (cloud_sphere, 0, 0, 250);
    viewer->addPointCloud(cloud_sphere, blue_handler, "cloud_sphere");
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud_sphere");

	  std::cerr << "PointCloud representing the cloud_sphere component: " << cloud_sphere->points.size () << " data points." << std::endl;
	  extract.setNegative (true);
    extract.filter (*filtered_part); // the rest part are the removal(abandoned part), we will show this part in red   
  }


  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();

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
  seg.setDistanceThreshold (0.01);

  int i = 0, nr_points = (int) cloud->points.size ();
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

  extract.setNegative(true);// extrect the outlier (removal part)
  extract.filter(*filtered_part);

  viewer->addCoordinateSystem (0.02);
  viewer->initCameraParameters ();

  return (viewer);

}


pcl::visualization::PCLVisualizer::Ptr EuclideanClusterExtraction (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud)
{
    // Creating the KdTree object for the search method of the extraction
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud (cloud); // move the input cloud into the Kd Tree
    
    cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>); // final filtering result
    filtered_part.reset(new pcl::PointCloud<pcl::PointXYZ>);


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
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
    // loop over the cluster indices we got
    for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it)
    {
      //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_cluster (new pcl::PointCloud<pcl::PointXYZ>);
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
      writer.write<pcl::PointXYZ> (ss.str (), *cloud_cluster, false); //*
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
  bool VoxelGrid(false), Passthrough(false);
  bool NormalSegmentation(false), largestPlane(false), EuclideanExtraction(false);

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
  else if (pcl::console::find_argument (argc, argv, "-EuclideanExtraction") >= 0)
  {
    EuclideanExtraction = true;
    std::cout << "apply Euclidean Cluster Extraction, using Kd Tree to cluster the Point Cloud\n";
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
    viewer = plannar_norm_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
   else if (largestPlane)
  {
    viewer = plannar_segmentation(basic_cloud_ptr);
    savePointFile(savefilename, cloud_filtered);
  }
  else if (EuclideanExtraction)
  {
    viewer = EuclideanClusterExtraction(basic_cloud_ptr);
    //savePointFile(savefilename, cloud_filtered);
  }
  

  // show the filtered part in red
  pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (filtered_part, 255, 0, 0);
  viewer->addPointCloud(filtered_part, red_handler, "filtered part");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "filtered part");



  //--------------------
  // -----Main loop-----
  //--------------------
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce (10);
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
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
