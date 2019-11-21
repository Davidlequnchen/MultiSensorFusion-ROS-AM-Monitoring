#include "../include/pclviewer.h"
#include "../include/ui_pclviewer.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>


#include <string>
#include <sstream>
#include <iostream>
#include <thread>
//#include "pcl_visualizer_demo.cpp"

using namespace std::literals::chrono_literals;



// class constructor
PCLViewer::PCLViewer(QWidget *parent) :
  QMainWindow (parent), ui (new Ui::PCLViewer), cloud_topic_("/filtered_cloud")
{
  ui->setupUi (this);
  this->setWindowTitle ("PCLViewer");
  // Setup the cloud pointer
  cloud.reset (new PointCloudTA);
  // The number of points in the cloud
  cloud->points.resize (200);

  // The default color
  red   = 128;
  green = 128;
  blue  = 128;

  //initalize the publisher

  cloud_pub_ = nh_.advertise<sensor_msgs::PointCloud2> (cloud_topic_, 30);
    // sensor_msgs::PointCloud2 data structure: 
    // std_msgs/Header header
    // uint32 height
    // uint32 width
    // sensor_msgs/PointField[] fields
    // bool is_bigendian
    // uint32 point_step
    // uint32 row_step
    // uint8[] data
    // bool is_dense

    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud
    //    pcl::PCLHeader 	header
    // std::vector< PointT, Eigen::aligned_allocator< PointT > > 	points
    // std::uint32_t 	width = 0
    // std::uint32_t 	height = 0
    // bool 	is_dense = true
    // Eigen::Vector4f 	sensor_origin_ = Eigen::Vector4f::Zero ()
    // Eigen::Quaternionf 	sensor_orientation_ = Eigen::Quaternionf::Identity ()
    //print some info about the node
  std::string r_ct = nh_.resolveName (cloud_topic_);
  ROS_INFO_STREAM("Publishing cloud on topic " << r_ct );


  // Fill the cloud with some points
  for (size_t i = 0; i < cloud->points.size (); ++i)
  {
    cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);

    cloud->points[i].r = red;
    cloud->points[i].g = green;
    cloud->points[i].b = blue;
  }

  
  pcl::toROSMsg(*cloud, cloud_out); // convert to ros message(cloud_out)
  cloud_pub_.publish (cloud_out); //  publish the point cloud 
  


// --------------------------conversion from pcl to ros message PointCloud2
// template<typename T>
// 00538   void toROSMsg(const pcl::PointCloud<T> &pcl_cloud, sensor_msgs::PointCloud2 &cloud)
// 00539   {
// 00540     pcl::PCLPointCloud2 pcl_pc2;
// 00541     pcl::toPCLPointCloud2(pcl_cloud, pcl_pc2);
// 00542     pcl_conversions::moveFromPCL(pcl_pc2, cloud);
// 00543   }




 
  // set up the point cloud visualization viewer
  /* 
  viewer.reset (new pcl::visualization::PCLVisualizer ("Point cloud Visualizer", true));
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addPointCloud (cloud, "cloud");
  viewer->resetCamera ();
  viewer->addCoordinateSystem (1.0);
  cb_args_class.viewerPtr = pcl::visualization::PCLVisualizer::Ptr(viewer);
  cb_args_class.pointProcessPtr = &pointProcess;
  viewer->registerPointPickingCallback (pp_callback, (void*)&cb_args_class);
  

  viewer->spinOnce(0.1); // update the screen
  //std::this_thread::sleep_for(std::chrono::milliseconds(2));
  */


  /* 
  while (!viewer->wasStopped ())
  {
    viewer->spinOnce (100);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  */
}


PCLViewer::~PCLViewer ()
{
  delete ui;
}


void settings_from_gui() {
  // TODO: Load parameters from gui and save it to file.
}

void settings_to_gui() {
  // TODO: Load parameters from settings member a show it.
}

//cloud visualization function, which will set up the point cloud visualization viewer, and return the point cloud visualizer pointer 'view'
// void PCLViewer::cloud_Vis ()
// {   try 
//     {
//         //create a viewer object
//         viewer.reset (new pcl::visualization::PCLVisualizer ("3D Point cloud Visualizer", true));
//         //pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Point cloud Visualizer"));
//         viewer->setBackgroundColor (0, 0, 0);
//         viewer->addPointCloud (cloud, "cloud");
//         viewer->resetCamera ();
//         viewer->addCoordinateSystem (1.0);
//         cb_args_class.viewerPtr = pcl::visualization::PCLVisualizer::Ptr(viewer);
//         cb_args_class.pointProcessPtr = &pointProcess;
//         viewer->registerPointPickingCallback (pp_callback, (void*)&cb_args_class);
        
//         // -----Main loop-----
        
//         while (!viewer->wasStopped ())
//         {
//         viewer->spinOnce(0.1);
//         std::this_thread::sleep_for(std::chrono::milliseconds(1));
//         }
        
//     }
//     catch(char const* error)
//     {
//         std::cout << "PCL visualization error: " << error << std::endl;
//     }
//     catch(...)
//     {
//         std::cout << "Unknown visualization exception.";
//     }

// }


//load PCD
void PCLViewer::on_pushButton_load_clicked()
{
    try
    {
        std::vector<pcl::visualization::Camera> cam;
        std::string archive_name;
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open cloud of points"), "",
                            tr("Point cloud files (*.pcd);;Point Cloud (*.pcd *.ply)"));
        archive_name = fileName.toUtf8().constData();
        pointProcess.LoadPointFile(archive_name); // load the pcd file, and stores the point cloud into pointer cloud_xyz

        /* 
        viewer->removePointCloud("distance_clicked_points");
        viewer->removePointCloud("cloud");
        viewer->removePointCloud("cloud_mod");
        viewer->removeCoordinateSystem();
        viewer->removeAllShapes();

        viewer->resetCamera ();
        //ui->qvtkWidget->update ();
        viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(2));   // added


        viewer->addCoordinateSystem(0.15);//"workobject"
        */

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;// define a new cloud


        
        cloud = nullptr;
        cloud_pub_.publish (cloud_out); //  publish the None point cloud to clear and remove everything


        pointProcess.getPointCloud(cloud); // stores the data from cloud_xyz into cloud
        pcl::PointXYZ min_pt, max_pt;
        pcl::getMinMax3D(*cloud, min_pt, max_pt);

        //viewer->getCameras(cam);
        cam[0].pos[0] = (max_pt.x + min_pt.x) / 2;
        cam[0].pos[1] = (max_pt.y + min_pt.y) / 2;
        cam[0].focal[0] = (max_pt.x + min_pt.x) / 2;
        cam[0].focal[1] = (max_pt.y + min_pt.y) / 2;
        cam[0].focal[2] = max_pt.z;
        /* 
        viewer->setCameraParameters(cam[0]);
        viewer->addPointCloud (cloud, "cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_cloud_size->value(), "cloud");
        */
        //ui->qvtkWidget->update ();
        //viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));   // added

        
        pcl::toROSMsg(*cloud, cloud_out); // convert to ros message
        cloud_pub_.publish (cloud_out);   // publish the loaded cloud

        std::cout << "Camara:" << std::endl << " - pos: (" << cam[0].pos[0] << ", "    << cam[0].pos[1] << ", "    << cam[0].pos[2] << ")" << endl
                  << " - view: ("    << cam[0].view[0] << ", "   << cam[0].view[1] << ", "   << cam[0].view[2] << ")"    << endl
                  << " - focal: ("   << cam[0].focal[0] << ", "  << cam[0].focal[1] << ", "  << cam[0].focal[2] << ")"   << endl;
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

//save PCD
void PCLViewer::on_pushButton_save_clicked()
{
    try
    {
    std::string archive_name;
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"),"",
                        tr("Point Cloud (*.pcd);;Point Cloud (*.pcd *.ply)"));
    archive_name = fileName.toUtf8().constData();
    pointProcess.SavePointFile(archive_name);
    }
    catch(char const* error)
    {
        std::cout << "Save error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown save exception.";
    }
}


void PCLViewer::on_pushButton_center_clicked()
{
    try
    {
        Eigen::Affine3f sel_frame;
        Eigen::VectorXf plane;
        pointProcess.getPlaneCoeffs(plane);
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        pointProcess.getSelPoints(cloud);
        std::vector<pcl::visualization::Camera> cam;
        //viewer->getCameras(cam);
        float fZ;
        cam[0].pos[0] = cloud->points.back().x;
        cam[0].pos[1] = cloud->points.back().y;
        fZ = cloud->points.back().z;
        cam[0].focal[0] = cam[0].pos[0];
        cam[0].focal[1] = cam[0].pos[1];
        cam[0].focal[2] = fZ;
        pointProcess.PlaceFrameZPlane(plane, cloud->points.at(cloud->points.size()-2), cloud->points.back(), sel_frame);
        /*
        viewer->setCameraParameters(cam[0]);
        viewer->addCoordinateSystem(0.01, sel_frame);//"base_frame"
         */
        std::cout << "Frame: " << std::endl << sel_frame.linear() << std::endl;
        std::cout << "Pos: " << std::endl << sel_frame.translation() << std::endl;
        //ui->qvtkWidget->update ();
        //viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(2));

        
        pcl::toROSMsg(*cloud, cloud_out); // convert to ros message
        cloud_pub_.publish (cloud_out);
    }
    catch(char const* error)
    {
        std::cout << "Focus point error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown focus point exception.";
    }
}

//apply filter
void PCLViewer::on_pushButton_apply_filtering_clicked()
{
    try
    {
    std::string str;
    std::stringstream ss;
    //Voxel Grid
    if (ui->stackedWidget_filter->currentIndex() == 0)
    {
        pointProcess.VoxelFilter(ui->doubleSpinBox_voxel_x->value(), ui->doubleSpinBox_voxel_y->value(), ui->doubleSpinBox_voxel_z->value());
    }
    //Statistical filter
    else if (ui->stackedWidget_filter->currentIndex() == 1)
    {
        pointProcess.StatisticalFilter((int)ui->doubleSpinBox_filter1_kn->value(),ui->doubleSpinBox_filter1_desv->value());
    }
    //Radius filter
    else if (ui->stackedWidget_filter->currentIndex() == 2)
    {
        pointProcess.RadiusFilter((int)ui->doubleSpinBox_radio_k->value(),ui->doubleSpinBox_radio->value());
    }
    //Resampling
    else if (ui->stackedWidget_filter->currentIndex() == 3)
    {
        pointProcess.ResamplingPoints(ui->doubleSpinBox_smooth->value());
    }
    //Pass through
    else if (ui->stackedWidget_filter->currentIndex() == 4)
    {
        pointProcess.PassthroughFilter(ui->doubleSpinBox_min_pass->value(),ui->doubleSpinBox_max_pass->value(),ui->comboBox_pass->currentIndex());
    }

    // we do not need to remove the cloud here, since we are publishing the filtered cloud in red.
    // we will remain the original data in white 


    pcl::PointCloud<pcl::PointXYZRGB>::Ptr mod_cloud;
    // cloud_out.header = mod_cloud->header;
    // cloud = nullptr;
    // cloud_pub_.publish (cloud_out); // publish a None point cloud to clear the point cloud data



    pointProcess.getModPointCloud(mod_cloud);   // Get 'new_cloud_xyz', which is the filtered result
                                                // and assign it to mod_cloud

    /* 
    //viewer->removePointCloud("cloud_mod");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (mod_cloud, 255, 0, 0);
    //viewer->addPointCloud(mod_cloud, red_handler, "cloud_mod");
    //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "cloud_mod");
    //ui->qvtkWidget->update ();
    */
    mod_cloud->r = 250;
    mod_cloud->g = 0;
    mod_cloud->b = 0;
    
    pcl::toROSMsg(mod_cloud, cloud_out); // convert to ros message
    cloud_pub_.publish (cloud_out);    // publish the mod_cloud in red color, which are the filtered part

    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_data->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Filter error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown filter exception.";
    }
}

//Auto filter
void PCLViewer::on_pushButton_filter_clicked()
{
    try
    {
        std::string str;
        std::stringstream ss;
        pcl::PointXYZ min_pt, max_pt;
        int original_size, modified_size, n_iter = 0;
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr mod_cloud, cloud;
        pointProcess.getPointCloud(mod_cloud);
        original_size = mod_cloud->points.size();
        pcl::getMinMax3D(*mod_cloud, min_pt, max_pt);
        pointProcess.PassthroughFilter(-0.002,max_pt.z*2,2);
        pointProcess.ModifyPointCloud();
        while (n_iter < 1)
        {
            n_iter++;
            pointProcess.RadiusFilter(7,-1);
            pointProcess.ModifyPointCloud();
            pointProcess.getPointCloud(cloud);
            modified_size = cloud->points.size();
            ss << "Removed by radius: " << original_size-modified_size << std::endl;
        }
        
        
        /* 
        viewer->removePointCloud("cloud");
        viewer->removePointCloud("cloud_mod");
        viewer->addPointCloud (cloud, "cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_cloud_size->value(), "cloud");
        //ui->qvtkWidget->update ();
        viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(2));
        */
        
        pcl::toROSMsg(*cloud, cloud_out); // convert to ros message
        cloud_pub_.publish (cloud_out);  //publish the point cloud after the autofilter.

        str = ss.str();
        QString qstr = QString::fromStdString(str);
        ui->textBrowser_data->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Filter error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown filter exception.";
    }
}

//Undo filter
void PCLViewer::on_pushButton_undo_filter_clicked()
{
    /* 
    viewer->removePointCloud("cloud_mod");
    //ui->qvtkWidget->update ();
    viewer->spinOnce(0.1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(2)); 
    */
    
    //cloud_out = nullptr;
    cloud_pub_.publish (cloud_out);


}

//accept modification filter
void PCLViewer::on_pushButton_accept_filter_clicked()
{
    try
    {
    
    cloud = nullptr;
    
    cloud_pub_.publish (cloud_out);  //remove everything first

    pointProcess.ModifyPointCloud();
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pointProcess.getPointCloud(cloud);//Get 'cloud_xyz': stores the cloud_xyz into cloud
                                     // cloud_xyz is the cloud result after filtering process, after applying each function.
    
    
    
    pcl::toROSMsg(*cloud, cloud_out); // convert to ros message
    cloud_pub_.publish (cloud_out);  //publish the point cloud after the filtering has done.

    /* 
    viewer->removePointCloud("cloud");
    viewer->removePointCloud("cloud_mod");
    viewer->addPointCloud (cloud, "cloud");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_cloud_size->value(), "cloud");
    //ui->qvtkWidget->update ();
    viewer->spinOnce(0.1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(2));
    */


    }
    catch(char const* error)
    {
        std::cout << "Filter accept error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown filter accept exception.";
    }
}

//Data cloud, output the cloud data information
void PCLViewer::on_pushButton_clicked()
{
    try
    {
    std::vector<pcl::visualization::Camera> cam;
    pcl::PointXYZ min_pt, max_pt;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pointProcess.getPointCloud(cloud);
    pcl::getMinMax3D(*cloud, min_pt, max_pt);
    std::string str;
    std::stringstream ss;
    float filter_r = (max_pt.x - min_pt.x + max_pt.y - min_pt.y + max_pt.z - min_pt.z) / (3 * sqrt(cloud->width * cloud->height)) * ui->doubleSpinBox_radio_k->value() / 2;
    ui->doubleSpinBox_radio->setValue(filter_r);
    if (ui->comboBox_pass->currentIndex() == 0)
    {
        ui->doubleSpinBox_min_pass->setValue(min_pt.x);
        ui->doubleSpinBox_max_pass->setValue(max_pt.x);
    }
    else if (ui->comboBox_pass->currentIndex() == 1)
    {
        ui->doubleSpinBox_min_pass->setValue(min_pt.y);
        ui->doubleSpinBox_max_pass->setValue(max_pt.y);
    }
    else if (ui->comboBox_pass->currentIndex() == 2)
    {
        ui->doubleSpinBox_min_pass->setValue(min_pt.z);
        ui->doubleSpinBox_max_pass->setValue(max_pt.z);
    }
    ss << "filter R: " << std::endl << filter_r << std::endl;
    ss << "points: " << std::endl << cloud->width * cloud->height << std::endl;
    ss << "Dimensions: " << std::endl << max_pt.x - min_pt.x << ", " << max_pt.y - min_pt.y << ", " << max_pt.z - min_pt.z << std::endl;
    ss << "Maximo: " << std::endl << max_pt.x << ", " << max_pt.y << ", " << max_pt.z << std::endl;
    ss << "Minimo: " << std::endl << min_pt.x << ", " << min_pt.y << ", " << min_pt.z << std::endl;
    //viewer->getCameras(cam);
    ss << "Camara:" << std::endl << " - pos: (" << cam[0].pos[0] << ", "    << cam[0].pos[1] << ", "    << cam[0].pos[2] << ")" << std::endl
                          << " - view: ("    << cam[0].view[0] << ", "   << cam[0].view[1] << ", "   << cam[0].view[2] << ")"    << std::endl
                          << " - focal: ("   << cam[0].focal[0] << ", "  << cam[0].focal[1] << ", "  << cam[0].focal[2] << ")"   << std::endl;
    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_data->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Filter accept error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown filter accept exception.";
    }
}

void PCLViewer::on_doubleSpinBox_cloud_size_valueChanged(double arg1)
{   /* 
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_cloud_size->value(), "cloud");
    //ui->qvtkWidget->update ();
    viewer->spinOnce(0.1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(2));
    */
}

void PCLViewer::on_doubleSpinBox_mod_size_valueChanged(double arg1)
{   /*
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "cloud_mod");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "source_cloud");
    //ui->qvtkWidget->update ();
    viewer->spinOnce(0.1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(2));
     */
}

void PCLViewer::on_doubleSpinBox_sel_size_valueChanged(double arg1)
{   /*
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_sel_size->value(), "distance_clicked_points");
    viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_sel_size->value(), "clicked_points");
    //ui->qvtkWidget->update ();
    viewer->spinOnce(0.1);
    //std::this_thread::sleep_for(std::chrono::milliseconds(2));
    */
}

void PCLViewer::on_spinBox_cluster_valueChanged(int argv)
{ /*
  try {
    pcl::PointCloud<pcl::PointXYZ>::Ptr seg_cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    seg_cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    pointProcess.Extract(argv);
    viewer->removePointCloud ("cloud");
    pointProcess.getModPointCloud(seg_cloud);
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
    pointProcess.getPointCloud(cloud);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (cloud, 255, 0, 0);
    viewer->removePointCloud ("cloud_mod");
    viewer->addPointCloud (cloud, "cloud");
    viewer->addPointCloud(seg_cloud, red_handler, "cloud_mod");
    }
    catch(char const* error)
    {
        std::cout << "Region selection error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown region selection exception." << std::endl;
    }
    */
}

//Adjust plane
void PCLViewer::on_pushButton_function_plane_fit_clicked()
{
    try
    {
    std::string str;
    std::stringstream ss;
    ground_coeffs.resize(4);
    pcl::PointXYZ min_pt, max_pt;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;

    pointProcess.FitPlane(ui->doubleSpinBox_ransac_dist->value());
    pointProcess.getPlaneCoeffs(ground_coeffs);
    pointProcess.getModPointCloud(cloud);
    pcl::getMinMax3D(*cloud, min_pt, max_pt);

    ss << "plane selected: " << std::endl << ground_coeffs(0) << std::endl << ground_coeffs(1) << std::endl << ground_coeffs(2) << std::endl << ground_coeffs(3) << std::endl;
    pcl::ModelCoefficients::Ptr coefficients_plane_manual (new pcl::ModelCoefficients);
    coefficients_plane_manual->values.resize (4);
    coefficients_plane_manual->values[0] = ground_coeffs.x ();
    coefficients_plane_manual->values[1] = ground_coeffs.y ();
    coefficients_plane_manual->values[2] = ground_coeffs.z ();
    coefficients_plane_manual->values[3] = ground_coeffs.w ();

    // viewer->removePointCloud("cloud_mod");
    // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (cloud, 255, 0, 0);
    // viewer->addPointCloud(cloud, red_handler, "cloud_mod");
    // viewer->removeShape("plane selected");
    // viewer->addPlane(*coefficients_plane_manual, min_pt.x, min_pt.y, min_pt.z, "plane selected");

    pointProcess.TransformatioMatrix(ground_coeffs);
    pointProcess.getTransformationMatrix(t_matrix);

    ss << "Affine3f: " << std::endl << t_matrix.matrix() << std::endl;
    //viewer->addCoordinateSystem(0.01 ,t_matrix);//"plane_frame"
    pointProcess.SaveMatrix();

    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_data_2->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Plane fitting error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown plane fitting exception." << std::endl;
    }
}

//record a cloud of points to plane
void PCLViewer::on_pushButton_record_plane_clicked()
{
    try
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        pointProcess.CutPlane(ui->checkBox_points_sup->checkState(), ui->doubleSpinBox_ransac_dist->value());
        pointProcess.getModPointCloud(cloud);

        //viewer->removePointCloud("cloud_mod");
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (cloud, 255, 0, 0);
        //viewer->addPointCloud(cloud, red_handler, "cloud_mod");
        //ui->qvtkWidget->update ();
        //viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    catch(char const* error)
    {
        std::cout << "Plane cutting error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown plane cutting exception." << std::endl;
    }
}

//Delete selected planes and points
void PCLViewer::on_pushButton_undo_plane_clicked()
{
    pointProcess.resetSelPoints();
    // viewer->removePointCloud("clicked_points");
    // viewer->removePointCloud("distance_clicked_points");
    // viewer->removeShape("plane selected");
    // viewer->removePointCloud("cloud_mod");
    // viewer->removeCoordinateSystem();
}


//Calculates the average distance of the points selected to the Adjust plane
void PCLViewer::on_pushButton_distances_clicked()
{
    //TODO: implement this function in class PointCloudProcess
    try
    {
        std::string str;
        std::stringstream ss;
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        pointProcess.getSelPoints(cloud);
        float d, d_avg, d_max, d_min;
        if (cloud->points.size() > 0){
            for (int i=0; i < cloud->points.size(); i++)
            {
               ss << "point " << i << ": " << std::endl << cloud->points[i] << std::endl;
               if (i == 0)
               {
                   d_avg = cloud->points[i].z;
                   d_max = cloud->points[i].z;
                   d_min = cloud->points[i].z;
               }
               else
               {
                   if (cloud->points[i].z < d_min) d_min = cloud->points[i].z;
                   if (cloud->points[i].z > d_max) d_max = cloud->points[i].z;
                   d_avg += cloud->points[i].z;
               }
           }
           d_avg = d_avg / cloud->points.size();
           ss << "Z media:" << std::endl << d_avg << std::endl;
           ss << "Z max:" << std::endl << d_max << std::endl;
           ss << "Z min:" << std::endl << d_min << std::endl;
       }
       else{
           ss << "Non se seleccionaron points" << std::endl;
       }
        str = ss.str();
        QString qstr = QString::fromStdString(str);
        ui->textBrowser_data_2->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Distances error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown distances exception." << std::endl;
    }
}

//reorient cloud with respect to plane
void PCLViewer::on_pushButton_reorient_clicked()
{
    try
    {
        std::string str;
        std::stringstream ss;
        pointProcess.ReorientPointCloud();
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        pointProcess.getModPointCloud(cloud);
        ss << "Translation:" << std::endl << t_matrix.translation() << std::endl;
        ss << "Rotation:" << std::endl << t_matrix.linear() << std::endl;
        //viewer->removePointCloud("cloud_mod");
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (cloud, 255, 0, 0);
        //viewer->addPointCloud(cloud, red_handler, "cloud_mod");
        //viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "cloud_mod");
        //ui->qvtkWidget->update ();
        //viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(2));


        str = ss.str();
        QString qstr = QString::fromStdString(str);
        ui->textBrowser_data_2->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Plane cutting error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown plane cutting exception." << std::endl;
    }
}

//accept modification fitting
void PCLViewer::on_pushButton_accept_fitting_clicked()
{
    try
    {
        pointProcess.ModifyPointCloud();
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        pointProcess.getPointCloud(cloud);
        // viewer->removePointCloud("cloud");
        // viewer->removePointCloud("cloud_mod");
        // viewer->addPointCloud (cloud, "cloud");
        // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_cloud_size->value(), "cloud");
        //ui->qvtkWidget->update ();
        //viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(1));   // added
    }
    catch(char const* error)
    {
        std::cout << "Fitting acept error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown fitting acept exception." << std::endl;
    }
}

//Project points
void PCLViewer::on_pushButton_proj_points_clicked()
{
    try
    {
        std::string str;
        std::stringstream ss;
        int border_pixels = 40;
        float resolution = 0.0001;
        pointProcess.setProjection(resolution, border_pixels);
        pointProcess.ProjectPointCloud();
        str = ss.str();
        QString qstr = QString::fromStdString(str);
        ui->textBrowser_projection->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Projection error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown projection exception." << std::endl;
    }
}

void PCLViewer::on_pushButton_2d_place_clicked()
{
    try
    {
        std::string str;
        std::stringstream ss;
        Eigen::Affine3f foundPointT = Eigen::Affine3f::Identity();

        //viewer->removeCoordinateSystem("found_point");
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
        pointProcess.PlaceFrame2D(ui->doubleSpinBox_2dx->value(), ui->doubleSpinBox_2dy->value(), foundPointT);
        //viewer->addCoordinateSystem(0.01 ,foundPointT);//"found_point"

        pointProcess.getModPointCloud(cloud);
        // viewer->removePointCloud("cloud_mod");
        // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red_handler (cloud, 255, 0, 0);
        // viewer->addPointCloud(cloud, red_handler, "cloud_mod");
        // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "cloud_mod");
        // //ui->qvtkWidget->update ();
        // viewer->spinOnce(0.1);
        //std::this_thread::sleep_for(std::chrono::milliseconds(2));


        str = ss.str();
        QString qstr = QString::fromStdString(str);
        ui->textBrowser_data_2->append(qstr);
    }
    catch(char const* error)
    {
        std::cout << "Place error: " << error << std::endl;
    }
    catch(...)
    {
        std::cout << "Unknown place exception." << std::endl;
    }
}

void PCLViewer::on_pushButton_load_model_clicked()
{
  try {
    std::string str;
    std::stringstream ss;
    std::string archive_name;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir nube de points"), "",
                                                    tr("Point cloud files (*.pcd);;Point Cloud (*.pcd *.ply)"));
    archive_name = fileName.toUtf8().constData();
    pointProcess.LoadSourceCloud(archive_name);

    // viewer->removePointCloud("source_cloud");
    // //ui->qvtkWidget->update ();
    // viewer->spinOnce(0.1);
    // //std::this_thread::sleep_for(std::chrono::milliseconds(2));


    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pointProcess.getSourcePointCloud(cloud);

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_handler (cloud, 0, 255, 255);
    // viewer->addPointCloud(cloud, source_handler, "source_cloud");
    // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "source_cloud");
    // //ui->qvtkWidget->update ();
    // viewer->spinOnce(0.1);
    // //std::this_thread::sleep_for(std::chrono::milliseconds(2));


    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_align->append(qstr);
  }
  catch(char const* error) {
    std::cout << "Load model error: " << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown load model exception." << std::endl;
  }
}

void PCLViewer::on_pushButton_delete_model_clicked()
{
  try {
    std::string str;
    std::stringstream ss;
    //TODO: Code
    // viewer->removePointCloud("source_cloud");
    // //ui->qvtkWidget->update ();
    // viewer->spinOnce(0.1);
    // std::this_thread::sleep_for(std::chrono::milliseconds(1));   // added

    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_align->append(qstr);
  }
  catch(char const* error) {
    std::cout << "Delete model error: " << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown delete model exception." << std::endl;
  }
}

void PCLViewer::on_pushButton_init_align_clicked()
{
  try {
    std::string str;
    std::stringstream ss;
    pointProcess.InitialAlign(ui->doubleSpinBox_radio->value());
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pointProcess.getSourcePointCloud(cloud);

    // viewer->removePointCloud("source_cloud");
    // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_handler (cloud, 0, 255, 255);
    // viewer->addPointCloud(cloud, source_handler, "source_cloud");
    // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "source_cloud");
    // //ui->qvtkWidget->update ();
    // viewer->spinOnce(0.1);
    // std::this_thread::sleep_for(std::chrono::milliseconds(1));   // added


    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_align->append(qstr);
  }
  catch(char const* error) {
    std::cout << "Initial aligning error: " << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown initial aligning exception." << std::endl;
  }
}

void PCLViewer::on_pushButton_fine_alignment_clicked()
{
  try {
    std::string str;
    std::stringstream ss;
    pointProcess.FineAlign();
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pointProcess.getSourcePointCloud(cloud);

    // viewer->removePointCloud("source_cloud");
    // pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> source_handler (cloud, 0, 255, 255);
    // viewer->addPointCloud(cloud, source_handler, "source_cloud");
    // viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, ui->doubleSpinBox_mod_size->value(), "source_cloud");
    // //ui->qvtkWidget->update ();
    // viewer->spinOnce(0.1);
    // std::this_thread::sleep_for(std::chrono::milliseconds(1));   // added

    str = ss.str();
    QString qstr = QString::fromStdString(str);
    ui->textBrowser_align->append(qstr);
  }
  catch(char const* error) {
    std::cout << "Fine aligning error:" << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown fine aligning exception." << std::endl;
  }
}

void PCLViewer::on_pushButton_test_clicked()
{
  try {
    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud;
    colored_cloud.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    pointProcess.Segment(colored_cloud);
    // viewer->removePointCloud ("cloud_mod");
    // viewer->removePointCloud ("cloud");
    // viewer->addPointCloud (colored_cloud, "cloud");
  }
  catch(char const* error) {
    std::cout << "Test error:" << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown test exception." << std::endl;
  }
}

void PCLViewer::on_actionLoad_triggered()
{
  try {
    std::string archive_name;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Cargar parámetros de procesado"), "",
                                                        tr("Json format (*.json);;"));
    archive_name = fileName.toUtf8().constData();
    if (archive_name != "") {
        pointProcess.settings.load(archive_name);
    }
  }
  catch(char const* error) {
    std::cout << "Load parameters error:" << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown load parameters exception." << std::endl;
  }
}

void PCLViewer::on_actionSave_triggered()
{
  try {
    std::string archive_name;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Guardar parámetros de procesado"), "",
                                                    tr("Json format (*.json);;"));
    archive_name = fileName.toUtf8().constData();
    if (archive_name != "") {
      pointProcess.settings.save(archive_name);
    }
  }
  catch(char const* error) {
    std::cout << "Save parameters error:" << error << std::endl;
  }
  catch(...) {
    std::cout << "Unknown save parameters exception." << std::endl;
  }
}


