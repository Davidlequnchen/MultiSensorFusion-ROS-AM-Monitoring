#include <ros/ros.h>

#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Float32.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/common.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_line.h>
#include <pcl/filters/extract_indices.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl_ros/point_cloud.h>

#include <ctime>


class NdHeight {
private:
  ros::NodeHandle nh;
  ros::Subscriber sub_cloud;
  ros::Publisher pub_height;

  float z_height;
  std_msgs::Float32 z_height_msg;

  Eigen::Matrix4f matrix;
  Eigen::Matrix4f matrix1;
  Eigen::Matrix4f matrix2;
public:
  typedef pcl::PointXYZ Point;
  typedef pcl::PointCloud<Point> PointCloud;

  NdHeight() {
    z_height = 0;

    // sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("/usb_cam/scan", 1,  &NdHeight::cbPointCloud, this);
    sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("/arm/laser_scan", 5,  &NdHeight::cbPointCloud, this);
    pub_height = nh.advertise<std_msgs::Float32>("/usb_cam/zheight", 1);

  }

  ~NdHeight() {}

  void cbPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) {
    try {
      //clock_t begin = clock();
      PointCloud::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>), cloud_p (new pcl::PointCloud<pcl::PointXYZ>);
      Eigen::VectorXf model_coefficients;
      std::vector< double > distances;
      //std::vector<int> inliers;
      pcl::fromROSMsg(*cloud_msg, *cloud);
      /*
      SampleConsensusModelLine defines a model for 3D line segmentation.

      The model coefficients are defined as:

      point_on_line.x : the X coordinate of a point on the line
      point_on_line.y : the Y coordinate of a point on the line
      point_on_line.z : the Z coordinate of a point on the line
      line_direction.x : the X coordinate of a line's direction
      line_direction.y : the Y coordinate of a line's direction
      line_direction.z : the Z coordinate of a line's direction
       */
      //using pcl::SampleConsensusModel< PointT >::Ptr = boost::shared_ptr<SampleConsensusModel<PointT> >
      pcl::SampleConsensusModelLine<pcl::PointXYZ>::Ptr model_l (new pcl::SampleConsensusModelLine<pcl::PointXYZ> (cloud));
      //RandomSampleConsensus: represents an implementation of the RANSAC (RAndom SAmple Consensus) algorithm
      pcl::RandomSampleConsensus<pcl::PointXYZ> ransac (model_l);
      ransac.setDistanceThreshold (0.0001); //Set the distance to model threshold. 
      ransac.computeModel();  //Compute the actual model and find the inliers. 
      //ransac.getInliers(inliers);

      // getModelCoefficients: Return the model coefficients of the best model found so far.
      // [output:]model_coefficients	the resultant model coefficients
      ransac.getModelCoefficients(model_coefficients); 
       
      //getDistancesToModel: Compute all distances from the cloud data to a given plane model.
      //[in]	model_coefficients	the coefficients of a plane model that we need to compute distances to 
      //[out]	distances	the resultant estimated distances   
      model_l->getDistancesToModel(model_coefficients, distances);
      double dMax = *max_element(distances.begin(), distances.end());
      //clock_t end = clock();
      //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
      //ROS_INFO_STREAM("Inliers: " << inliers.size());
      //double dMin = *min_element(distances.begin(), distances.end());
      //ROS_INFO_STREAM("MinD: " << dMin);
      z_height_msg.data = dMax;
      pub_height.publish(z_height_msg);
    } catch (...) {
      ROS_ERROR("Z height error");
    }
  }
};


int main (int argc, char** argv) {
  ros::init(argc, argv, "height");

  NdHeight nd_height;

  ros::spin();
}
