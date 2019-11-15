#ifndef LMD_FUNCS
#define LMD_FUNCS
#ifndef Q_MOC_RUN

#include <iostream>
#include <vector>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/voxel_grid_occlusion_estimation.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/common.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
#include <pcl/filters/passthrough.h>
#include <pcl/common/transforms.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/features/fpfh_omp.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/sample_consensus_prerejective.h>
#include <pcl/common/time.h>
#include <pcl/segmentation/region_growing.h>

//Boost Library
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

// Types
typedef pcl::PointNormal PointNT;
typedef pcl::PointCloud<PointNT> PointCloudT;
typedef pcl::FPFHSignature33 FeatureT;
typedef pcl::FPFHEstimationOMP<PointNT,PointNT,FeatureT> FeatureEstimationT;
typedef pcl::PointCloud<FeatureT> FeatureCloudT;
typedef pcl::visualization::PointCloudColorHandlerCustom<PointNT> ColorHandlerT;// Types


//declaracions
namespace OpenLmd
{
    // declare the parameters for point cloud processing
    struct align_s {
        float leaf_size;
        float radius_normals;
        float radius_features;
        int max_iterations;
        int n_samples;
        float correspondence_randomness;
        float similarity_threshold;
        float max_correspondence_d;
        float inlier_fraction;
    };

    struct voxel_grid_s {
        float leaf_size_x;
        float leaf_size_y;
        float leaf_size_z;
    };

    struct statistical_s {
        int k_neighbors;
        float deviation;
    };

    struct radius_search_s    {
        int k_neighbors;
        float radius;
    };

    struct limits   {
        float max;
        float min;
    };

    struct passthrough_s  {
        limits x;
        limits y;
        limits z;
    };

    struct resampling_s   {
        float search_radius;
    };

    struct filters_s {
        voxel_grid_s voxel_grid;
        statistical_s statistical;
        radius_search_s radius_search;
        passthrough_s passthrough;
        resampling_s resampling;
    };

    struct fitting_s    {
        float distance_threshold;
    };

    struct region_s    {
      int k_neighbors;
      int max_cluster;
      int min_cluster;
      int n_neighbors;
      float smooth_thr;
      float curvature;
    };

    struct segmentation_s    {
      region_s region;
    };

    //cloud setting struct
    struct cloud_s {
        align_s align;
        filters_s filters;
        fitting_s fitting;
        segmentation_s segmentation;
        void load(const std::string &filename);
        void save(const std::string &filename);
    };

class PointCloudProcess {
 public:
    PointCloudProcess();
    // Load a point cloud to 'cloud_xyz' member from a '.pcd' file
    void LoadPointFile(std::string fileName);
    // Load a point cloud to 'source_cloud' member from a '.pcd' file
    void LoadSourceCloud(std::string fileName);
    // Save 'cloud_xyz' in a file
    void SavePointFile(std::string fileName);
    // Get 'cloud_xyz'
    void getPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    void getSourcePointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    // Get 'new_cloud_xyz'
    void getModPointCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    // Get selected points
    void getSelPoints(pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud);
    // Clear cloud of selected points
    void resetSelPoints();
    // Reset 'cloud_xyz' to 'new_cloud_xyz'
    void ModifyPointCloud();
    void VoxelFilter(double leafX, double leafY, double leafZ);
    void VoxelFilter();
    void StatisticalFilter(int kNearest, double multiplier);
    void StatisticalFilter();
    void RadiusFilter(int kNearest, double radius);
    void RadiusFilter();
    void PassthroughFilter(double min, double max, int axis);
    void PassthroughFilter();
    void ResamplingPoints(double radius);
    void ResamplingPoints();
    // Add a point to a cloud
    void AddPoint(pcl::PointCloud<pcl::PointXYZ>::Ptr &add_cloud, pcl::PointXYZ sel_point);
    // Add a point to 'selected_points'
    void AddPoint(pcl::PointXYZ sel_point);
    // Fit a plane to a cloud, set 'ground_coeffs', and get inliers in 'new_cloud_xyz'
    void FitPlane(const pcl::PointCloud<pcl::PointXYZ>::Ptr &plane_cloud_xyz, double distThreshold = 0.01);
    // Fit to 'selected_points' if n>3, else to 'cloud_xyz'
    void FitPlane(double distThreshold = 0.01);
    void getPlaneCoeffs(Eigen::VectorXf &coeffs);
    void TransformatioMatrix(Eigen::VectorXf coeffs, Eigen::Affine3f &tMatrix);
    void TransformatioMatrix(Eigen::VectorXf coeffs);//TODO: Default coeffs? to catch ground_coeffs
    void PlaceFrameZPlane(Eigen::VectorXf a, pcl::PointXYZ orig, pcl::PointXYZ dirX, Eigen::Affine3f &frame);
    void CutPlane(bool updown, double offset);
    void getTransformationMatrix(Eigen::Affine3f &tMatrix);
    void SaveMatrix(const std::string fileName, Eigen::Affine3f matrix);
    void SaveMatrix(const std::string fileName = "plane.json");
    void ReorientPointCloud(Eigen::Affine3f tMatrix);
    void ReorientPointCloud();
    void setProjection(float res, int border);
    void ProjectPointCloud(const std::string fileName = "ocvImage.png");
    void PlaceFrame2D(int xVal, int yVal, Eigen::Affine3f &foundPointT);
    void InitialAlign(float radius = 0.001f);
    void FineAlign();
    void Segment(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &colored_cloud);
    void Extract(int index, pcl::PointCloud<pcl::PointXYZ>::Ptr &segment_cloud);
    void Extract(int index);

    cloud_s settings;
    
    //~PointCloudProcess();

 private:
    //represents the base class in PCL for storing collections of 3D points. 
    // it contains folloing attributes:
    /*
    1. pcl::PCLHeader 	header
 	The point cloud header. 

    2. std::vector< PointT, Eigen::aligned_allocator< PointT > > 	points
 	The point data. --> stored in a dynamically aligned matrix
    class Eigen::aligned_allocator< T >
    STL compatible allocator
    to use with types requiring a non standrad alignment.
    The memory is aligned as for dynamically aligned
     matrix/array types such as MatrixXd. 
 
    3. std::uint32_t 	width = 0
 	 The point cloud width (if organized as an image-structure). 
 
    4. std::uint32_t 	height = 0
 	 The point cloud height (if organized as an image-structure).
 
    5. bool    is_dense = true
 	 True if no points are invalid (e.g., have NaN or Inf values 
    in any of their floating point fields). 
 
    6. Eigen::Vector4f 	sensor_origin_ = Eigen::Vector4f::Zero ()
 	Sensor acquisition pose (origin/translation). 
 
    7. Eigen::Quaternionf 	sensor_orientation_ = Eigen::Quaternionf::Identity ()
 	Sensor acquisition pose (rotation). 
     */
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz;
    pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr new_cloud_xyz;
    pcl::PointCloud<pcl::PointXYZ>::Ptr selected_points;
    
    // stores information about a 3-D affine geometric transformation 
    // and enables forward and inverse transformations.
    //an affine transformation is a composition of rotations, translations, dilations, and shears. 
    Eigen::Affine3f t_matrix, paralel_mat;
    std::vector <pcl::PointIndices> clusters;
    pcl::PointXYZ min_pt, max_pt;
    Eigen::VectorXf ground_coeffs;
    int border_pixels;
    float resolution;
};
}  // namespace OpenLmd


#endif  // LMD_FUNCS
#endif
