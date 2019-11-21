#ifndef PCLVIEWER_H
#define PCLVIEWER_H
//#ifndef Q_MOC_RUN
//define Q_MOC_RUN
// basic file operations
#include <fstream>
#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Qt
#include <QMainWindow>
#include <QFileDialog>

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
#include <pcl/common/common_headers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/io/pcd_io.h>
#include <pcl/console/parse.h>



// Visualization Toolkit (VTK)
//#include <vtkRenderWindow.h>

//Boost Library
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

//LMD projects functions
#include "LmdFuncs.h"

//ros include files
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/PointCloud2.h>
//conversions from PCL custom types
#include <pcl_conversions/pcl_conversions.h>


#include <string>

#include <sstream>




using namespace cv;

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

typedef pcl::PointXYZRGBA PointTA;
typedef pcl::PointCloud<PointTA> PointCloudTA;

namespace Ui
{
  class PCLViewer;
}

class PCLViewer : public QMainWindow
{
  Q_OBJECT
  
public:
    explicit PCLViewer (QWidget *parent = 0);
    ~PCLViewer ();
    void cloud_Vis();
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
    //void cloud_visualization();
    
protected:
  // initalize the pcl visualizer shared pointer
  //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("3D Point cloud Visualizer"));
  //boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  PointCloudTA::Ptr cloud;

  unsigned int red;
  unsigned int green;
  unsigned int blue;

  OpenLmd::PointCloudProcess pointProcess;

  Eigen::VectorXf ground_coeffs;
  Eigen::Affine3f t_matrix;

  //struct callback_args cb_args;
  struct callback_args_class cb_args_class;

private slots:
  pcl::visualization::PCLVisualizer::Ptr on_pushButton_load_clicked();

  void on_pushButton_save_clicked();

  void on_pushButton_apply_filtering_clicked();

  void on_pushButton_undo_filter_clicked();

  void on_pushButton_clicked();

  void on_pushButton_function_plane_fit_clicked();

  void on_pushButton_undo_plane_clicked();

  void on_pushButton_distances_clicked();

  void on_doubleSpinBox_cloud_size_valueChanged(double arg1);

  void on_doubleSpinBox_mod_size_valueChanged(double arg1);

  void on_doubleSpinBox_sel_size_valueChanged(double arg1);

  void on_spinBox_cluster_valueChanged(int argv);

  void on_pushButton_accept_filter_clicked();

  void on_pushButton_reorient_clicked();

  void on_pushButton_record_plane_clicked();

  void on_pushButton_accept_fitting_clicked();

  void on_pushButton_center_clicked();

  void on_pushButton_proj_points_clicked();

  void on_pushButton_2d_place_clicked();

  void on_pushButton_filter_clicked();

  void on_pushButton_load_model_clicked();

  void on_pushButton_delete_model_clicked();

  void on_pushButton_init_align_clicked();

  void on_pushButton_fine_alignment_clicked();

  void on_pushButton_test_clicked();

  void on_actionLoad_triggered();

  void on_actionSave_triggered();

private:
  Ui::PCLViewer *ui;

  void settings_from_gui();

  void settings_to_gui();

  //bool save(false), apply(false), undo(false), loadfile(false);

  //bool accept(false), center(false), 

  // ros::NodeHandle nh_; // create a node handler
  // sensor_msgs::PointCloud2 cloud_out; //cache the cloud message
  // std::string cloud_topic_; //default output
  // ros::Publisher cloud_pub_; //cloud message publisher

};

#endif // PCLVIEWER_H
//#endif // Q_MOC_RUN
