#include "LmdFuncs.h"

namespace OpenLmd {
  
  //read and load the json file contains all the prarameters needed for pcl processing
  void cloud_s::load(const std::string &filename) {
      boost::property_tree::ptree tree;
      if (filename != "") {
        boost::property_tree::read_json(filename, tree);
      }

      align.leaf_size = tree.get<float>("align.leaf_size", 0.001);
      align.radius_normals = tree.get<float>("align.radius_normals", 0.005);
      align.radius_features = tree.get<float>("align.radius_features", 0.01);
      align.max_iterations = tree.get<int>("align.max_iterations", 10000);
      align.n_samples = tree.get<int>("align.n_samples", 3);
      align.correspondence_randomness = tree.get<float>("align.correspondence_randomness", 5);
      align.similarity_threshold = tree.get<float>("align.similarity_threshold", 0.9);
      align.max_correspondence_d = tree.get<float>("align.max_correspondence_d", 0.0025);
      align.inlier_fraction = tree.get<float>("align.inlier_fraction", 0.25);

      segmentation.region.max_cluster = tree.get<int>("segmentation.region.max_cluster", 1000000);
      segmentation.region.min_cluster = tree.get<int>("segmentation.region.min_cluster", 50);
      segmentation.region.n_neighbors = tree.get<int>("segmentation.region.n_neighbors", 30);
      segmentation.region.k_neighbors = tree.get<int>("segmentation.region.k_neighbors", 50);
      segmentation.region.smooth_thr = tree.get<float>("segmentation.region.smooth_thr", 0.0523599);
      segmentation.region.curvature = tree.get<float>("segmentation.region.curvature", 1.0);

      filters.voxel_grid.leaf_size_x = tree.get<float>("filters.voxel_grid.leaf_size_x", 0.001);
      filters.voxel_grid.leaf_size_y = tree.get<float>("filters.voxel_grid.leaf_size_y", 0.001);
      filters.voxel_grid.leaf_size_z = tree.get<float>("filters.voxel_grid.leaf_size_z", 0.001);
      filters.statistical.k_neighbors = tree.get<int>("filters.statistical.k_neighbors", 5);
      filters.statistical.deviation = tree.get<float>("filters.statistical.deviation", 0.01);
      filters.radius_search.k_neighbors = tree.get<int>("filters.radius_search.k_neighbors", 7);
      filters.radius_search.radius = tree.get<float>("filters.radius_search.radius", 0.01);
      filters.passthrough.x.min = tree.get<float>("filters.passthrough.x.min", 0.0);
      filters.passthrough.x.max = tree.get<float>("filters.passthrough.x.max", 0.0);
      filters.passthrough.y.min = tree.get<float>("filters.passthrough.y.min", 0.0);
      filters.passthrough.y.max = tree.get<float>("filters.passthrough.y.max", 0.0);
      filters.passthrough.z.min = tree.get<float>("filters.passthrough.z.min", 0.0);
      filters.passthrough.z.max = tree.get<float>("filters.passthrough.z.max", 0.0);
      filters.resampling.search_radius = tree.get<float>("filters.resampling.search_radius", 0.001);

      fitting.distance_threshold = tree.get<float>("fitting.distance_threshold", 0.001);
  }
  // read the json file contains the pcl processing prameters
  void cloud_s::save(const std::string &filename) {
      boost::property_tree::ptree tree;

      tree.put<float>("align.leaf_size", align.leaf_size);
      tree.put<float>("align.radius_normals", align.radius_normals);
      tree.put<float>("align.radius_features", align.radius_features);
      tree.put<int>("align.max_iterations", align.max_iterations);
      tree.put<int>("align.n_samples", align.n_samples);
      tree.put<float>("align.correspondence_randomness", align.correspondence_randomness);
      tree.put<float>("align.similarity_threshold", align.similarity_threshold);
      tree.put<float>("align.max_correspondence_d", align.max_correspondence_d);
      tree.put<float>("align.inlier_fraction", align.inlier_fraction);

      tree.put<int>("segmentation.region.max_cluster", segmentation.region.max_cluster);
      tree.put<int>("segmentation.region.min_cluster", segmentation.region.min_cluster);
      tree.put<int>("segmentation.region.n_neighbors", segmentation.region.n_neighbors);
      tree.put<int>("segmentation.region.k_neighbors", segmentation.region.k_neighbors);
      tree.put<float>("segmentation.region.smooth_thr", segmentation.region.smooth_thr);
      tree.put<float>("segmentation.region.curvature", segmentation.region.curvature);

      tree.put<float>("filters.voxel_grid.leaf_size_x", filters.voxel_grid.leaf_size_x);
      tree.put<float>("filters.voxel_grid.leaf_size_y", filters.voxel_grid.leaf_size_y);
      tree.put<float>("filters.voxel_grid.leaf_size_z", filters.voxel_grid.leaf_size_z);
      tree.put<int>("filters.statistical.k_neighbors",filters.statistical.k_neighbors);
      tree.put<float>("filters.statistical.deviation",filters.statistical.deviation);
      tree.put<int>("filters.radius_search.k_neighbors",filters.radius_search.k_neighbors);
      tree.put<float>("filters.radius_search.radius",filters.radius_search.radius);
      tree.put<float>("filters.passthrough.x.min", filters.passthrough.x.min);
      tree.put<float>("filters.passthrough.x.max", filters.passthrough.x.max);
      tree.put<float>("filters.passthrough.y.min", filters.passthrough.y.min);
      tree.put<float>("filters.passthrough.y.max", filters.passthrough.y.max);
      tree.put<float>("filters.passthrough.z.min", filters.passthrough.z.min);
      tree.put<float>("filters.passthrough.z.max", filters.passthrough.z.max);
      tree.put<float>("filters.resampling.search_radius", filters.resampling.search_radius);

      tree.put<float>("fitting.distance_threshold", fitting.distance_threshold);

      if (filename != "") {
        boost::property_tree::write_json(filename, tree);
      }
  }
  
  /*Class consturctor: 
    initialize the cloud_xyz, source_cloud, new_cloud_xyz, selected_points
    for storing collections of 3D points.
   */
  PointCloudProcess::PointCloudProcess() {
      cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
      source_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
      new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
      selected_points.reset(new pcl::PointCloud<pcl::PointXYZ>);
      t_matrix = Eigen::Affine3f::Identity(); //t_matrix: 3D affine transformation matrix
      paralel_mat = Eigen::Affine3f::Identity(); ////paralel_mat: 3D affine transformation matrix
      border_pixels = 40;
      resolution = 0.0001;
      ground_coeffs.resize(4); // initialize the vector with 4 elements
      ground_coeffs(0) = 0;
      ground_coeffs(1) = 0;
      ground_coeffs(2) = 1;
      ground_coeffs(3) = 0;
      settings.load(""); // settings is defined as an object of cloud_s.
                        // load None parameters will make the processing parameters set as defult stated above.
  }
  
  // Load a point cloud to 'cloud_xyz' member from a '.pcd' file
  void PointCloudProcess::LoadPointFile(std::string fileName) {
      if (fileName != "") {
          new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
          selected_points.reset(new pcl::PointCloud<pcl::PointXYZ>);
          cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
          //Load a PCD v.6 file into a templated PointCloud type. 
          if (pcl::io::loadPCDFile<pcl::PointXYZ> (fileName, *cloud_xyz) == -1) {
              PCL_ERROR("Couldn't read file *.pcd \n");
              throw "Couldn't read file *.pcd";
          }
      } else {
          PCL_ERROR("Invalid file name \n");
          throw "Invalid file name";
      }
      /*pcl::getMinMax3D:
        Get the minimum and maximum values on each of the 3 (x-y-z) dimensions in a given pointcloud.
        Parameters
        cloud	the point cloud data message(input)
        min_pt	the resultant minimum bounds(output)
        max_pt	the resultant maximum bounds(output)  */
      pcl::getMinMax3D(*cloud_xyz, min_pt, max_pt);
      return;
  }

   // Load a point cloud to 'source_cloud' member from a '.pcd' file
  void PointCloudProcess::LoadSourceCloud(std::string fileName) {
      if (fileName != "") {
          source_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
          if (pcl::io::loadPCDFile<pcl::PointXYZ> (fileName, *source_cloud) == -1) {
              PCL_ERROR("Couldn't read file *.pcd \n");
              throw "Couldn't read file *.pcd";
          }
      } else {
          PCL_ERROR("Invalid file name \n");
          throw "Invalid file name";
      }
      return;
  }

  // Save 'cloud_xyz' in a file
  void PointCloudProcess::SavePointFile(std::string fileName) {
      if (fileName != "") {
          if ((cloud_xyz->width * cloud_xyz->height) > 0) {
              if (fileName.compare(fileName.size()-4, 4, ".pcd") != 0) {
                  fileName += ".pcd";
              }
              pcl::io::savePCDFileASCII(fileName, *cloud_xyz);
          } else {
              PCL_ERROR("Point cloud empty \n");
              throw "Point cloud empty";
          }
      } else {
          PCL_ERROR("Invalid file name \n");
          throw "Invalid file name";
      }
      return;
  }
  
  // Get 'cloud_xyz': stores the cloud_xyz into a designated cloud(defined from function parameter)
  void PointCloudProcess::getPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud) {
      int nPoints = cloud_xyz->points.size();
      if (nPoints <= 0) {
          throw "Point cloud empty";
      }
      cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
      *cloud = *cloud_xyz;
      return;
  }

  //get the source cloud, store it in a new cloud
  void PointCloudProcess::getSourcePointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud) {
      /*
      get the points from the source cloud
       */
      int nPoints = source_cloud->points.size();
      if (nPoints <= 0) {
          throw "Point cloud empty";
      }
      cloud.reset(new pcl::PointCloud<pcl::PointXYZ>); // reset the cloud before it new data come in
      *cloud = *source_cloud;
      return;
  }
  
  // Get 'new_cloud_xyz'
  void PointCloudProcess::getModPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud) {
      int nPoints = new_cloud_xyz->points.size();
      if (nPoints <= 0) {
          throw "New point cloud empty";
      }
      cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
      *cloud = *new_cloud_xyz;
      return;
  }

  // Get 'selected points'
  void PointCloudProcess::getSelPoints(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud) {
      int nPoints = selected_points->points.size();
      if (nPoints <= 0) {
          throw "No selected points";
      }
      cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
      *cloud = *selected_points;
      return;
  }

  // Clear cloud of 'selected points'
  void PointCloudProcess::resetSelPoints() {
      selected_points.reset(new pcl::PointCloud<pcl::PointXYZ>);
  }

  // Reset 'cloud_xyz' to 'new_cloud_xyz'
  void PointCloudProcess::ModifyPointCloud() {
      if (new_cloud_xyz->width * new_cloud_xyz->height >= 1) {
          cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
          *cloud_xyz = *new_cloud_xyz;
          pcl::getMinMax3D(*cloud_xyz, min_pt, max_pt);
      } else {
          PCL_ERROR("Empty mod cloud \n");
          throw "Empty mod point cloud";
      }
      return;
  }

  //define a voxel filter (a 3D box with height with and length), with parameters defined.
  void PointCloudProcess::VoxelFilter(double leafX, double leafY, double leafZ) {
      // if leafX or Y or Z defined as -1, will take the average value from point data and cloud data
      if (leafX == -1) {
          leafX = (max_pt.x - min_pt.x) / (cloud_xyz->width * cloud_xyz->height);
      }
      if (leafY == -1) {
          leafY = (max_pt.y - min_pt.y) / (cloud_xyz->width * cloud_xyz->height);
      }
      if (leafZ == -1) {
          leafZ = (max_pt.z - min_pt.z) / (cloud_xyz->width * cloud_xyz->height);
      }
      if (leafX > 0 && leafY > 0 && leafZ > 0) {
          new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>); // clear new cloud
          pcl::VoxelGrid<pcl::PointXYZ> sor; //define an voxel grid object
          sor.setInputCloud(cloud_xyz); // set the in put cloud as 'cloud_xyz', which is for further processing
          sor.setLeafSize(leafX, leafY, leafZ);
          sor.filter(*new_cloud_xyz); // store the filtered cloud into the 'new_cloud_xyz'
      } else {
          PCL_ERROR("Invalid voxel dimensions \n");
          throw "Invalid voxel dimensions";
      }
      return;
  }

  // get the leaf size parameters from the setting list
  void PointCloudProcess::VoxelFilter() {
    VoxelFilter(settings.filters.voxel_grid.leaf_size_x,
                settings.filters.voxel_grid.leaf_size_y,
                settings.filters.voxel_grid.leaf_size_z);
  }

  
  //Statistical Filter uses the standard deviation method to remove the noise
  void PointCloudProcess::StatisticalFilter(int kNearest, double multiplier) {
      // kNearest is k_neighbors, defined as number of neighbors one point have
      // multiplier is defined as standard deviation multiplier from the setting list
      if (kNearest == -1) {
          kNearest = 10;
      }
      if (multiplier == -1) {
          multiplier = 1;
      }
      if (kNearest > 0 && multiplier >= 0) {
          new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);// clean the new_cloud_xyz
          pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;  // Create the filtering object for statistical noise removal
          sor.setInputCloud(cloud_xyz); // use the cloud_xyz as the input cloud
          sor.setMeanK(kNearest);  //The number of neighbors to analyze for each point is set to be KNearest
          sor.setStddevMulThresh(multiplier); //standard deviation multiplier to 1
          //  means is that all points who have a distance larger than 1 standard deviation 
          // of the mean distance to the query point will be marked as outliers and removed
          sor.filter(*new_cloud_xyz); // output the filtered cloud into the new_cloud_xyz
      } else {
          PCL_ERROR("Invalid statistical parameters \n");
          throw "Invalid statistical parameters";
      }
      return;
  }
  
  // set the parameters k_neighbors and deviation from the setting list
  void PointCloudProcess::StatisticalFilter() {
    StatisticalFilter(settings.filters.statistical.k_neighbors,
                      settings.filters.statistical.deviation);
  }

  void PointCloudProcess::RadiusFilter(int kNearest, double radius) {
      // set defult value for KNearest and radius
      if (kNearest == -1) {
          kNearest = 7;
      }
      if (radius == -1) {
          radius = (max_pt.x - min_pt.x + max_pt.y - min_pt.y + max_pt.z - min_pt.z) / (3 * sqrt(cloud_xyz->width * cloud_xyz->height)) * kNearest / 2;
      }
      /*
      RadiusOutlierRemoval filters points in a cloud based on the number of neighbors they have.
      Iterates through the entire input once, and for each point, retrieves the number of neighbors
      within a certain radius. The point will be considered an outlier if it has too few neighbors, 
      as determined by setMinNeighborsInRadius(). The radius can be changed using setRadiusSearch(). 
       */
      if (kNearest >= 1 && radius > 0) {
          new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
          pcl::RadiusOutlierRemoval<pcl::PointXYZ> sor;  // Create the filtering object
          sor.setInputCloud(cloud_xyz);
          sor.setMinNeighborsInRadius(kNearest);// define number of neighbors
          sor.setRadiusSearch(radius);
          sor.filter(*new_cloud_xyz);
      } else {
          PCL_ERROR("Invalid radius search parameters \n");
          throw "Invalid radius search parameters";
      }
      return;
  }

  // set the k_neighbors and radius from the setting list
  void PointCloudProcess::RadiusFilter() {
    RadiusFilter(settings.filters.radius_search.k_neighbors,
                 settings.filters.radius_search.radius);
  }

  void PointCloudProcess::PassthroughFilter(double min, double max, int axis) {
      /*
      class PassThrough passes points in a cloud based on constraints for one particular field of the point type.
      Iterates through the entire input once, automatically filtering non-finite points and the points 
      outside the interval specified by setFilterLimits(), which applies only to the field specified by 
      setFilterFieldName(). 
       */
      if (axis >= 0 && axis <= 2) {
          pcl::PassThrough<pcl::PointXYZ> pass;
          pass.setInputCloud(cloud_xyz); // set input cloud
          if (axis == 0)
              pass.setFilterFieldName("x");
          if (axis == 1)
              pass.setFilterFieldName("y");
          if (axis == 2)
              pass.setFilterFieldName("z");
          // The indices x/y/z array indexes all points of cloud_in that have x/y/z between min and max
          pass.setFilterLimits(min, max);
          pass.setFilterLimitsNegative(false); //Set to true if we want to return the data outside
                                               //the interval specified by setFilterLimits (min, max) Default: false. 
          pass.filter(*new_cloud_xyz);
      } else {
          PCL_ERROR("Invalid passtrough filter parameters \n");
          throw "Invalid passtrough filter parameters";
      }
      return;
  }
  
  // set the passthrough parameters read from the parameter setting list
  void PointCloudProcess::PassthroughFilter() {
    PassthroughFilter(settings.filters.passthrough.x.min,
                      settings.filters.passthrough.x.max, 0);
    PassthroughFilter(settings.filters.passthrough.y.min,
                      settings.filters.passthrough.y.max, 1);
    PassthroughFilter(settings.filters.passthrough.z.min,
                      settings.filters.passthrough.z.max,2);
  }

  void PointCloudProcess::ResamplingPoints(double radius) {
      if (radius == -1) {
          radius = (max_pt.x - min_pt.x + max_pt.y - min_pt.y + max_pt.z - min_pt.z) / (3 * sqrt(cloud_xyz->width * cloud_xyz->height)) * radius / 2;
      }
      if (radius>0) {
          new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
          //KdTree is a generic type of 3D spatial locator using kD-tree structures. 
          // kd tree: a data structure,  a binary search tree with other constraints imposed on it

          //The class is making use of the FLANN (Fast Library for Approximate Nearest Neighbor) 
          //define the nearest neighbor search (NSS)problem in the following way: given a set of points
          //P=p1, p2, . . . , pn in a metric spaceX, these points must be preprocessed in such a way that
          //given a new query point q∈X, finding the point in P that is nearest to q can be done quickly.
          pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ>);
          /*
          MovingLeastSquares represent an implementation of the MLS (Moving Least Squares)
          algorithm for data smoothing and improved normal estimation. 
           */
          pcl::MovingLeastSquares<pcl::PointXYZ, pcl::PointXYZ> mls;// create an object
          mls.setInputCloud(cloud_xyz); // set input cloud 

          //Sets whether the surface and normal are approximated using a polynomial,
          //or only via tangent estimation. 
          mls.setPolynomialFit(true);
          //Provide a pointer to the search object. a pointer to the spatial search object. 
          mls.setSearchMethod(tree);
          //Set the sphere radius that is to be used for determining the k-nearest neighbors used for fitting. 
          mls.setSearchRadius(radius);
          //process: Base method for surface reconstruction for all points, output	the resultant reconstructed surface model 
          mls.process(*new_cloud_xyz);
      } else {
          PCL_ERROR("Invalid resampling parameters \n");
          throw "Invalid resampling parameters";
      }
      return;
  }

  // set the search_radius parameter from the setting list
  void PointCloudProcess::ResamplingPoints() {
    ResamplingPoints(settings.filters.resampling.search_radius);
  }

  void PointCloudProcess::AddPoint(pcl::PointCloud<pcl::PointXYZ>::Ptr &add_cloud, pcl::PointXYZ sel_point) {
      // sel_point is the point need to be added to the cloud
      int nPoints = add_cloud->points.size();
      if (nPoints > 0) {
          if (add_cloud->points[nPoints -1].x == sel_point.x && add_cloud->points[nPoints -1].y == sel_point.y && add_cloud->points[nPoints -1].z == sel_point.z) {
              // add_cloud->points.pop_back(); //Removes the last element in the vector, effectively reducing the container size by one.
              throw "Repeated point";
          }
      }
      add_cloud->points.push_back(sel_point); // add one element at the end
      return;
  }


  // add the point to the point cloud 'selected_points'
  void PointCloudProcess::AddPoint(pcl::PointXYZ sel_point) {
    AddPoint(selected_points, sel_point);
  }

  // Fit a plane to a cloud, set 'ground_coeffs', and get inliers in 'new_cloud_xyz'
  // input plane_cloud_xyz(point cloud), distThreshold
  void PointCloudProcess::FitPlane(const pcl::PointCloud<pcl::PointXYZ>::Ptr &plane_cloud_xyz, double distThreshold) {
      if (distThreshold == 0) {
          throw "Threslhold can't be 0.0";
      }
      if (plane_cloud_xyz->points.size() < 3) {
          throw "Empty point cloud";
      }
      ground_coeffs.resize(4);
    /*
    SampleConsensusModelPlane: defines a model for 3D plane segmentation. 
    model coefficient: 
    a : the X coordinate of the plane's normal (normalized)
    b : the Y coordinate of the plane's normal (normalized)
    c : the Z coordinate of the plane's normal (normalized)
    d : the fourth Hessian component of the plane's equation
	the input point cloud dataset here is set to be the plane_cloud_xyz
     */
    pcl::SampleConsensusModelPlane<pcl::PointXYZ>::Ptr model_plane_ptr(new pcl::SampleConsensusModelPlane<pcl::PointXYZ> (plane_cloud_xyz));
    /*
    RandomSampleConsensus represents an implementation of the RANSAC (RAndom SAmple Consensus) algorithm,
    [in] model: a Sample Consensus model 
     */
    pcl::RandomSampleConsensus<pcl::PointXYZ> ransac_manual(model_plane_ptr);
    //Set the distance to model threshold. 
    ransac_manual.setDistanceThreshold(distThreshold);
    //Compute the actual model and find the inliers. 
    ransac_manual.computeModel();
    //Return the model coefficients of the best model found so far. store the coefficients into ground_coeffs vector
    ransac_manual.getModelCoefficients(ground_coeffs);
    std::vector<int> inliers;
    // get the inlier and store it into a vector
    ransac_manual.getInliers(inliers);
    new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);// clear value from new_cloud_xyz
    //this will copy all the value from plane_cloud_xyz into new_cloud_xyz, with constraint of inlier
    pcl::copyPointCloud<pcl::PointXYZ>(*plane_cloud_xyz, inliers, *new_cloud_xyz); 
  }


  // Fit to 'selected_points' if n>3, else to 'cloud_xyz'
  void PointCloudProcess::FitPlane(double distThreshold) {
      if (selected_points->points.size() > 3) {
          FitPlane(selected_points, distThreshold);
    } else if (cloud_xyz->points.size() > 3) {
          FitPlane(cloud_xyz, distThreshold);
    } else {
        throw "No valid point cloud";
    }
  }

  // get the best fitting model plane coefficient after finding the plane by ransac method
  void PointCloudProcess::getPlaneCoeffs(Eigen::VectorXf &coeffs) {
    coeffs = ground_coeffs;
  }

  // transform matrix calculation
  // input: Eigen::VectorXf coeffs
  // output: Eigen::Affine3f &tMatrix
  void PointCloudProcess::TransformatioMatrix(Eigen::VectorXf coeffs, Eigen::Affine3f &tMatrix) {
      Eigen::Matrix4f transform_1 = Eigen::Matrix4f::Identity();
      // Take w as a fixed vector
      Eigen::Vector3f w(coeffs.x(), coeffs.y(), coeffs.z());
      if (w[2] < 0)
          w *= -1;
      Eigen::Vector3f v(0, 1, 0);
      // Set u the normal plane to k
      Eigen::Vector3f u(v.cross(w));
      v = w.cross(u);
      u = v.cross(w);
      u.normalize();
      v.normalize();
      w.normalize();
      for (int i=0; i < 3; i++) {
          transform_1(i, 0) = u[i];
      }
      for (int i=0; i < 3; i++) {
          transform_1(i, 1) = v[i];
      }
      for (int i=0; i < 3; i++) {
          transform_1(i, 2) = w[i];
      }
      pcl::getMinMax3D(*cloud_xyz, min_pt, max_pt);
      transform_1(0, 3) = min_pt.x;
      transform_1(1, 3) = min_pt.y;
      transform_1(2, 3) = min_pt.z;
      tMatrix = Eigen::Affine3f::Identity();
      tMatrix = transform_1;
  }

  void PointCloudProcess::TransformatioMatrix(Eigen::VectorXf coeffs) {
      TransformatioMatrix(coeffs, t_matrix);
  }

  void PointCloudProcess::PlaceFrameZPlane(Eigen::VectorXf a, pcl::PointXYZ orig, pcl::PointXYZ dirX, Eigen::Affine3f &frame) {
      Eigen::Vector3f w(a(0), a(1), a(2));
      Eigen::Matrix4f transform_1 = Eigen::Matrix4f::Identity();
      w.normalize();
      if (w[2] < 0)
          w *= -1;
      Eigen::Vector3f b(dirX.x-orig.x, dirX.y-orig.y, dirX.z-orig.z);
      Eigen::Vector3f v(w.cross(b));
      v.normalize();
      Eigen::Vector3f u(v.cross(w));
      u.normalize();
      for (int i=0; i < 3; i++) {
          transform_1(i, 0) = u[i];
      }
      for (int i=0; i < 3; i++) {
          transform_1(i, 1) = v[i];
      }
      for (int i=0; i < 3; i++) {
          transform_1 (i, 2) = w[i];
      }
      frame = Eigen::Affine3f::Identity();
      frame = transform_1;
      frame(0,3) = orig.x;
      frame(1,3) = orig.y;
      frame(2,3) = orig.z;

      Eigen::Quaternionf cuat;
      cuat = Eigen::Quaternionf(frame.linear());

      SaveMatrix("base_frame.json", frame);
  }

  void PointCloudProcess::CutPlane(bool updown, double offset) {
      float normal;
      std::vector<int> inliers;
      for (int i = 0; i < cloud_xyz->size(); i++) {
          normal = ground_coeffs.x () * cloud_xyz->points[i].x + ground_coeffs.y () * cloud_xyz->points[i].y + ground_coeffs.z () * cloud_xyz->points[i].z + ground_coeffs.w ();
          if (updown) {
              if (normal >= (0-offset)) {
                  inliers.push_back(i);
              }
          } else {
              if (normal <= (0+offset)) {
                  inliers.push_back(i);
              }
          }
      }
      new_cloud_xyz.reset(new pcl::PointCloud<pcl::PointXYZ>);
      pcl::copyPointCloud<pcl::PointXYZ>(*cloud_xyz, inliers, *new_cloud_xyz);
  }

  void PointCloudProcess::getTransformationMatrix(Eigen::Affine3f &tMatrix) {
      tMatrix = t_matrix;
  }

  void PointCloudProcess::SaveMatrix(const std::string fileName, Eigen::Affine3f matrix) {
      Eigen::Quaternionf cuat;
      cuat = Eigen::Quaternionf(matrix.linear());
      ofstream myfile;
      myfile.open(fileName.c_str(), ios::out | ios::trunc);
      myfile << "{\"frame\": {" << std::endl;
      myfile << "\t" << "\"u\": [" << matrix(0, 0) << ", " << matrix(0, 1)
              << ", " << matrix(0, 2) << "]," << std::endl;
      myfile << "\t" << "\"v\": [" << matrix(1, 0) << ", " << matrix(1, 1)
              << ", " << matrix(1, 2) << "]," << std::endl;
      myfile << "\t" << "\"w\": [" << matrix(2, 0) << ", " << matrix(2, 1)
              << ", " << matrix(2, 2) << "]," << std::endl;
      myfile << "\t" << "\"t\": [" << matrix(0, 3)*1000 << ", " << matrix(1, 3)*1000
              << ", " << matrix(2, 3)*1000 << "]," << std::endl;
      myfile << "\t" << "\"quat\": [" << cuat.x() << ", " << cuat.y()
              << ", " << cuat.z() << ", " << cuat.w() << "]" << std::endl;
      myfile << "}}";
      myfile.close();
  }

  void PointCloudProcess::SaveMatrix(const std::string fileName) {
    SaveMatrix(fileName, t_matrix);
  }

  void PointCloudProcess::ReorientPointCloud(Eigen::Affine3f tMatrix) {
      paralel_mat = tMatrix;
      pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud;
      temp_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
      Eigen::Affine3f transformada = Eigen::Affine3f::Identity();
      transformada.translation() = -1 * tMatrix.translation();
      pcl::transformPointCloud(*cloud_xyz, *new_cloud_xyz, transformada);

      transformada = Eigen::Affine3f::Identity();
      transformada.linear() = tMatrix.linear().transpose();
      pcl::transformPointCloud(*new_cloud_xyz, *temp_cloud, transformada);

      transformada = Eigen::Affine3f::Identity();
      transformada.translation() = tMatrix.translation();
      pcl::transformPointCloud(*temp_cloud, *new_cloud_xyz, transformada);
  }

  void PointCloudProcess::ReorientPointCloud() {
      ReorientPointCloud(t_matrix);
  }

  void PointCloudProcess::setProjection(float res, int border) {
      resolution = res;
      border_pixels = border;
  }

  void PointCloudProcess::ProjectPointCloud(const std::string fileName) {
      float res = resolution;
      int over_pixel = border_pixels;
      pcl::PointCloud<pcl::PointXYZ>::Ptr proj_cloud(new pcl::PointCloud<pcl::PointXYZ> (*cloud_xyz));
      pcl::getMinMax3D(*cloud_xyz, min_pt, max_pt);
      float x_size, y_size, z_size;
      x_size = max_pt.x - min_pt.x;
      y_size = max_pt.y - min_pt.y;
      z_size = max_pt.z - min_pt.z;
      int imageX, imageY;
      imageX = x_size/res+over_pixel;
      imageY = y_size/res+over_pixel;
      cv::Mat oProjection(imageY, imageX,  CV_16U);
      oProjection = cv::Scalar(0);
      std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > data_points;
      data_points =  proj_cloud->points; // boost::get<pcl::PointXYZ>(proj_cloud->points);
      while (!data_points.empty()) {
          float x, y , z;
          pcl::PointXYZ point = data_points.back();
          x = (point.x - min_pt.x) / res;
          y = (point.y - min_pt.y) / res;
          z = (point.z - min_pt.z) / z_size * 65535;
          x = x+over_pixel/2;
          y = y+over_pixel/2;
          if (oProjection.at<ushort>(static_cast<int>(y), static_cast<int>(x)) == 0)
            oProjection.at<ushort>(static_cast<int>(y), static_cast<int>(x)) = cv::saturate_cast<ushort>(z);
          else {
            if (oProjection.at<ushort>(static_cast<int>(y), static_cast<int>(x)) < cv::saturate_cast<ushort>(z))
              oProjection.at<ushort>(static_cast<int>(y),static_cast<int>(x)) = cv::saturate_cast<ushort>(z);
          }
          data_points.pop_back();
      }
      std::vector<int> compression_params;
      compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
      compression_params.push_back(3);
      cv::imwrite(fileName, oProjection, compression_params);
  }

  void PointCloudProcess::PlaceFrame2D(int xVal, int yVal, Eigen::Affine3f &foundPointT) {
      int over_pixel = border_pixels;
      float res = resolution;
      pcl::PointXYZ min_pt, max_pt, f_pt;
      pcl::getMinMax3D(*cloud_xyz, min_pt, max_pt);
      float x_size, y_size;
      x_size = max_pt.x - min_pt.x;
      y_size = max_pt.y - min_pt.y;
      f_pt.x = (xVal - over_pixel/2) * res + min_pt.x;
      f_pt.y = (yVal - over_pixel/2) * res + min_pt.y;
      f_pt.z = 0;

      //Transformación
      pcl::PointCloud<pcl::PointXYZ>::Ptr temp_cloud;
      temp_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
      Eigen::Affine3f transformada = Eigen::Affine3f::Identity();
      transformada.translation() = -1 * paralel_mat.translation();
      cloud_xyz->points.push_back(f_pt);
      pcl::transformPointCloud(*cloud_xyz, *new_cloud_xyz, transformada);

      f_pt = new_cloud_xyz->points.back();
      new_cloud_xyz->points.pop_back();
      f_pt.z = 0;
      new_cloud_xyz->points.push_back(f_pt);

      transformada = Eigen::Affine3f::Identity();
      transformada.linear() = paralel_mat.linear();
      pcl::transformPointCloud(*new_cloud_xyz, *temp_cloud, transformada);

      transformada = Eigen::Affine3f::Identity();
      transformada.translation() = paralel_mat.translation();
      pcl::transformPointCloud(*temp_cloud, *new_cloud_xyz, transformada);
      f_pt = new_cloud_xyz->points.back();
      new_cloud_xyz->points.pop_back();
      cloud_xyz->points.pop_back();

      foundPointT = Eigen::Affine3f::Identity();
      foundPointT.linear() = t_matrix.linear();
      foundPointT(0, 3) = f_pt.x;
      foundPointT(1, 3) = f_pt.y;
      foundPointT(2, 3) = f_pt.z;
      foundPointT.rotate(Eigen::AngleAxisf(0, Eigen::Vector3f::UnitZ()));

      SaveMatrix("found_point.json", foundPointT);
  }

  void PointCloudProcess::InitialAlign(float radius) {
        PointCloudT::Ptr object (new PointCloudT);
        PointCloudT::Ptr object_aligned (new PointCloudT);
        PointCloudT::Ptr scene (new PointCloudT);
        FeatureCloudT::Ptr object_features (new FeatureCloudT);
        FeatureCloudT::Ptr scene_features (new FeatureCloudT);
        const float leaf = 0.001f;

        pcl::copyPointCloud(*cloud_xyz, *scene);
        pcl::copyPointCloud(*source_cloud, *object);

        // Estimate normals for scene
        pcl::console::print_highlight("Estimating scene normals...\n");
        pcl::NormalEstimationOMP<PointNT, PointNT> nest;
        nest.setRadiusSearch(radius);
        nest.setInputCloud(scene);
        nest.compute(*scene);

        // Estimate features
        pcl::console::print_highlight("Estimating features...\n");
        FeatureEstimationT fest;
        fest.setRadiusSearch(radius * 1.5f);
        fest.setInputCloud(object);
        fest.setInputNormals(object);
        fest.compute(*object_features);
        fest.setInputCloud(scene);
        fest.setInputNormals(scene);
        fest.compute(*scene_features);

        // Perform alignment
        pcl::console::print_highlight("Starting alignment...\n");
        pcl::SampleConsensusPrerejective<PointNT, PointNT, FeatureT> align;
        align.setInputSource(object);
        align.setSourceFeatures(object_features);
        align.setInputTarget(scene);
        align.setTargetFeatures(scene_features);
        align.setMaximumIterations(10000); // Number of RANSAC iterations
        align.setNumberOfSamples(3); // Number of points to sample for generating/prerejecting a pose
        align.setCorrespondenceRandomness(5); // Number of nearest features to use
        align.setSimilarityThreshold(0.9f); // Polygonal edge length similarity threshold
        align.setMaxCorrespondenceDistance(2.5f * leaf); // Inlier threshold
        align.setInlierFraction(0.25f); // Required inlier fraction for accepting a pose hypothesis
        {
          pcl::ScopeTime t("Alignment");
          align.align(*object_aligned);
        }

        if (align.hasConverged()) {
          // Print results
          printf("\n");
          Eigen::Matrix4f transformation = align.getFinalTransformation();
          pcl::console::print_info("    | %6.3f %6.3f %6.3f | \n", transformation (0,0), transformation (0,1), transformation (0,2));
          pcl::console::print_info("R = | %6.3f %6.3f %6.3f | \n", transformation (1,0), transformation (1,1), transformation (1,2));
          pcl::console::print_info("    | %6.3f %6.3f %6.3f | \n", transformation (2,0), transformation (2,1), transformation (2,2));
          pcl::console::print_info("\n");
          pcl::console::print_info("t = < %0.3f, %0.3f, %0.3f >\n", transformation (0,3), transformation (1,3), transformation (2,3));
          pcl::console::print_info("\n");
          pcl::console::print_info("Inliers: %i/%i\n", align.getInliers ().size (), object->size ());
          source_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
          pcl::copyPointCloud(*object_aligned, *source_cloud);
        } else {
          pcl::console::print_error("Alignment failed!\n");
      }
  }

  void PointCloudProcess::FineAlign() {
      pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
      icp.setInputSource(source_cloud);
      icp.setInputTarget(cloud_xyz);
      // icp.setMaxCorrespondenceDistance (0.01);
      // icp.setTransformationEpsilon (1e-8);
      // icp.setEuclideanFitnessEpsilon (1);
      icp.setMaximumIterations(1);
      icp.align(*source_cloud);
      std::cout << "has converged:" << icp.hasConverged() << " score: " <<
          icp.getFitnessScore() << std::endl;
      std::cout << icp.getFinalTransformation() << std::endl;
  }

  void PointCloudProcess::Segment(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &colored_cloud) {
    if (cloud_xyz->points.size() == 0) {
      throw "Point process 'cloud_xyz' empty";
    }
    pcl::search::Search<pcl::PointXYZ>::Ptr tree = boost::shared_ptr<pcl::search::Search<pcl::PointXYZ> > (new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;

    normal_estimator.setSearchMethod (tree);
    normal_estimator.setInputCloud (cloud_xyz);
    normal_estimator.setKSearch (settings.segmentation.region.k_neighbors);
    normal_estimator.compute (*normals);

    pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;
    reg.setMinClusterSize (settings.segmentation.region.min_cluster);
    reg.setMaxClusterSize (settings.segmentation.region.max_cluster);
    reg.setSearchMethod (tree);
    reg.setNumberOfNeighbours (settings.segmentation.region.n_neighbors);
    reg.setInputCloud (cloud_xyz);
    reg.setInputNormals (normals);
    reg.setSmoothnessThreshold (settings.segmentation.region.smooth_thr);
    reg.setCurvatureThreshold (settings.segmentation.region.curvature);

    clusters.clear();
    reg.extract (clusters);

    int max_cluster = 0, n_max_cluster = -1;
    for (int i = 0; i < clusters.size(); i++) {
      std::cout << "Cluster n: " << i << " poits: "
                << clusters[i].indices.size() << std::endl;
      if (clusters[i].indices.size() > max_cluster) {
        max_cluster = clusters[i].indices.size();
        n_max_cluster = i;
      }
    }
    std::cout << "Number of clusters is equal to "
              << clusters.size() << std::endl;
    std::cout << "Big cluster has " << max_cluster << " points." << endl;
    std::cout << "This is the n = " << n_max_cluster << std::endl;

    colored_cloud = reg.getColoredCloud ();
    return;
  }

  void PointCloudProcess::Extract(int index, pcl::PointCloud<pcl::PointXYZ>::Ptr &segment_cloud) {
    if (clusters.size() == 0) {
      throw "No clusters detected";
    }
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
    if (clusters.size() >= index) {
      *inliers = clusters[index];
      // Extract the planar inliers from the input cloud
      pcl::ExtractIndices<pcl::PointXYZ> extract;
      extract.setInputCloud (cloud_xyz);
      extract.setIndices (inliers);
      extract.setNegative (false);
      extract.filter (*segment_cloud);
    }
  }

  void PointCloudProcess::Extract(int index) {
    Extract(index, new_cloud_xyz);
  }


}  // namespace OpenLmd
