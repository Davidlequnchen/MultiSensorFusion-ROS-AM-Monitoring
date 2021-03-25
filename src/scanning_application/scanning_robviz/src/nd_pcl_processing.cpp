#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/common.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_line.h>
#include <pcl/filters/extract_indices.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/pcd_io.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>

#include <scanning_robviz/MsgCommand.h>    // added
#include <scanning_robviz/MsgPointCloudScan.h>

#include <ctime>
#include <sstream>
#include <fstream>
#include <iostream> //std::cout
#include <string>  //std::string, std::to_string
#include <boost/filesystem.hpp>
#include "subprocess.hpp"

namespace sp = subprocess;
namespace fs =boost::filesystem;

// global variable
bool is_active;


std::string path = ros::package::getPath("scanning_robviz");

typedef pcl::PointXYZ Point;
typedef pcl::PointCloud<Point> PointCloud;


class NdSubprocessHandler {
    private:
        ros::NodeHandle nh;
        ros::Subscriber sub_cloud;
        ros::Subscriber sub_command;
        ros::Publisher pub_point_cloud_scan;
        std_msgs::Float32MultiArray msg_point_distance;
        
        //ros::Time stamp; //get the current time when initialization
        double stamp =ros::Time::now().toSec(); //get the current time when initialization
        double interval = 5.0;  // duration between each subprocess
        std::string pcd_filename;
        std::string pcd_segmented_filename;
        std::string pcd_plane_distance_file;
        std::string pcd_coefficient_plane_file;

        int scanning_count = 0; //number of scanning
      
      
    public:
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_stored;

        // constructor
        NdSubprocessHandler() {
          cloud_stored.reset (new pcl::PointCloud<pcl::PointXYZ>);// reset the stored cloud
          // subscriber and call back function
          sub_cloud = nh.subscribe<sensor_msgs::PointCloud2>("/microepsilon/cloud_transformed", 5,  &NdSubprocessHandler::cbPointCloud, this);
          sub_command = nh.subscribe<scanning_robviz::MsgCommand>("/routine_command", 5,  &NdSubprocessHandler::cbCommand, this);

          // ROS publisher
          pub_point_cloud_scan = nh.advertise<scanning_robviz::MsgPointCloudScan>("/PointCloudScan_info", 10);
          }

        //destructor
        ~NdSubprocessHandler() {}
        

        //call back function
        void cbCommand (const scanning_robviz::MsgCommand::ConstPtr &msg)
        {
            if (msg->command == 1.0){
                is_active = true;

            }else{
                is_active = false;
            }
        }


        void cbPointCloud(const sensor_msgs::PointCloud2ConstPtr& cloud_msg) 
        {
            PointCloud cloud; //temporary cloud
            double current_stamp = ros::Time::now().toSec(); // local variable for the current time when receiving current message
            // this->pcd_filename = std::to_string(this->stamp) + ".pcd";
            // this->pcd_segmented_filename = std::to_string(this->stamp) + "segmented.pcd";
            // this->pcd_plane_distance_file = std::to_string(this->stamp) + "distance.txt";
            


            if (is_active) // when microepsilon sensor is open
            {   
                pcl::fromROSMsg(*cloud_msg, cloud); // convert pointcloud2 message to point cloud object
                *cloud_stored += cloud; // store(append) the temporary cloud into the cloud_stored pointer

                //--------------point cloud analysis not ready--------------------
                // read routine command send from EKI server
                scanning_robviz::MsgPointCloudScan point_cloud_scan;
                point_cloud_scan.ready = false;
                point_cloud_scan.scanning_count = this->scanning_count;
                pub_point_cloud_scan.publish(point_cloud_scan);
            }
            else 
            {
                if (!cloud_stored->empty()) // because we only want to do pcl processing once for each scanning result
                // if cloud_stored is not empty, then can we proceed to do pcl post-processings
                {
                    // fs::path dir (path);
                    // fs::path file(this->pcd_filename);
                    // fs::path full_path = dir / file;

                    this->pcd_filename = std::to_string(this->scanning_count) + ".pcd";
                    this->pcd_segmented_filename = "segmentedCloud_" + std::to_string(this->scanning_count) + ".pcd";
                    this->pcd_plane_distance_file = "localDistance_" + std::to_string(this->scanning_count) + ".txt";
                    this->pcd_coefficient_plane_file = "coefficientPlane_" + std::to_string(this->scanning_count) + ".txt";

                    std::string full_path = path + "/pcl/" + this->pcd_filename;
                    std::cout << "saved to path: " << full_path << std::endl;
                    // save cloud_stored into a pcd file
                    NdSubprocessHandler::savePointFile(full_path, cloud_stored);

                    if (this->scanning_count == 0){
                        // -------------------subprocess start(segmentation process)----------------------
                        //define the executable program and set all the parameters here
                        //Usage: ./PCL_segmentation [options] [-load filename] [-save filename] [-leafsize /float] [-DistanceThre /float] [-Stddev /float]
                        // fs::path dir (path + "/PCL_segmentation/build");
                        // fs::path file("PCL_segmentation");
                        // fs::path full_path = dir / file;
                        // EXAMPLE ------------------------------------------------------------------------------------
                        // ./PCL_segmentation -passThroughSeg -load Q1.pcd -save Q1_seg.pcd -saveCoefficientPlaneName coefficient_Q1.txt 
                        // -savePointToPlaneDistance distance_Q1.txt -saveNormalEstimation normalEstimation_Q1.txt -DistanceThre 0.003 
                        // -Stddev 1.2 -leafsize 0.00018 -zmin -0.236 -zmax 0
                        // However, normalEstimation and saveCoefficientPlaneName can be ommited
                        //--------------------------------------------------------------------------------------------
                        std::string executable = path + "/PCL_segmentation/build/PCL_segmentation";
                        std::string option = " -passThroughSeg"; //other options: -multiPlannarSeg, -NormalSegmentation, -largestPlane, -ShapeSeg, ,-multiPlannarSeg, -sfilter, curveSeg
                        std::string loadfile = " -load " + path + "/pcl/" + this->pcd_filename;
                        std::string savefile = " -save " + path + "/pcl/" + this->pcd_segmented_filename;
                        // std::string savePointDistance = " -savePointToPlaneDistance ~/SIMTech_ws/src/scanning_application/scanning_robviz/distance/distance.txt";
                        std::string savePointDistance = " -savePointToPlaneDistance " + path + "/distance/" + this->pcd_plane_distance_file;
                        std::string saveCoefficientPlane = " -saveCoefficientPlaneName " + path + "/coefficientPlane/" + this->pcd_coefficient_plane_file;
                        std::string parameters = " -DistanceThre 0.003 -Stddev 1.2 -leafsize 0.0003 -zmin 0.318 -zmax 10";
                        // std::string parameters = " ";
                        // Initialize String Array
                        std::string command_line = executable + option + loadfile + savefile + saveCoefficientPlane + savePointDistance + parameters;

                        auto p = sp::call({command_line});
                        //--------------------subprocess end------------------------

                    }

                    else{
                        // -------------------subprocess start(segmentation process)----------------------
                        //define the executable program and set all the parameters here
                        //Usage: ./PCL_segmentation [options] [-load filename] [-save filename] [-leafsize /float] [-DistanceThre /float] [-Stddev /float]
                        // fs::path dir (path + "/PCL_segmentation/build");
                        // fs::path file("PCL_segmentation");
                        // fs::path full_path = dir / file;
                        // EXAMPLE ------------------------------------------------------------------------------------
                        // ./PCL_segmentation -passThroughSeg -load Q1.pcd -save Q1_seg.pcd -saveCoefficientPlaneName coefficient_Q1.txt 
                        // -savePointToPlaneDistance distance_Q1.txt -saveNormalEstimation normalEstimation_Q1.txt -DistanceThre 0.003 
                        // -Stddev 1.2 -leafsize 0.00018 -zmin -0.236 -zmax 0
                        // However, normalEstimation and saveCoefficientPlaneName can be ommited
                        //--------------------------------------------------------------------------------------------
                        std::string executable = path + "/PCL_segmentation/build/PCL_segmentation";
                        std::string option = " -passThroughSeg"; //other options: -multiPlannarSeg, -NormalSegmentation, -largestPlane, -ShapeSeg, ,-multiPlannarSeg, -sfilter, curveSeg
                        std::string loadfile = " -load " + path + "/pcl/" + this->pcd_filename;
                        std::string savefile = " -save " + path + "/pcl/" + this->pcd_segmented_filename;
                        // std::string savePointDistance = " -savePointToPlaneDistance ~/SIMTech_ws/src/scanning_application/scanning_robviz/distance/distance.txt";
                        std::string savePointDistance = " -savePointToPlaneDistance " + path + "/distance/" + this->pcd_plane_distance_file;
                        std::string saveCoefficientPlane = " -saveCoefficientPlaneName " + path + "/coefficientPlane/" + this->pcd_coefficient_plane_file;
                        std::string parameters = " -DistanceThre 0.003 -Stddev 1.2 -leafsize 0.0003 -zmin 0.322 -zmax 10";
                        // std::string parameters = " ";
                        // Initialize String Array
                        std::string command_line = executable + option + loadfile + savefile + saveCoefficientPlane + savePointDistance + parameters;

                        auto p = sp::call({command_line});
                        //--------------------subprocess end------------------------

                    }
                    


                    try{
                        std::string pcdFile = path + "/pcl/" + this->pcd_segmented_filename;
                        std::string distanceFile = path+ "/distance/" + this->pcd_plane_distance_file;

                        // pcl::PointCloud<pcl::PointXYZ>::Ptr seg_cloud = NdSubprocessHandler::LoadPointFile(pcdFile);

                        //--------subprocess for visualizing the segmented cloud in Rviz--------------------------------------
                        std::string interval = " 0.1 "; //publish 10 times a second, If <interval> is zero or not specified the message is published once. 
                        std::string frame = "_frame_id:=/workobject";
                        // command line call the pcd_to_pointcloud node: $ rosrun pcl_ros pcd_to_pointcloud <file.pcd> [ <interval> ]
                        // Initialize String Array
                        std::string command_line = "rosrun pcl_ros pcd_to_pointcloud " + pcdFile  + interval + frame; 
                        auto s = sp::Popen({command_line});
                        // auto s = sp::Popen({command_line});
                        //------------subprocess end---------------------------------------------------
                        
                        //--------------publish the point cloud scan info to let analysis begin--------------------
                        // read routine command send from EKI server
                        scanning_robviz::MsgPointCloudScan point_cloud_scan;
                        point_cloud_scan.ready = true;
                        point_cloud_scan.scanning_count = this->scanning_count;
                        pub_point_cloud_scan.publish(point_cloud_scan);

                        // --------------subprocess for defects prediction---------------------------------
                        std::string prediction_python_exe = path + "/defects_prediction/Plane_defect_machine_learning.py";
                        std::string DecisionTree_Model_file = path + "/config/KNN.pkl";

                        std::string prediction_exe = "python " + prediction_python_exe + " " + pcdFile + " " + distanceFile + " " + DecisionTree_Model_file;
                        // auto predict = sp::Popen({prediction_exe}, output{PIPE});
                        // auto obuf = predict.communicate().first;
                        // std::cout << "Data : " << obuf.buf.data() << std::endl;
                        // std::cout << "Data len: " << obuf.length << std::endl;
                        // auto p = Popen({"ls", "-l"}, output{PIPE});
                        // auto obuf = p.communicate().first;
                        // std::cout << "Data : " << obuf.buf.data() << std::endl;
                        // std::cout << "Data len: " << obuf.length << std::endl;
                        // --------------------------------------------------------------------------------
                        
                        this->scanning_count = this->scanning_count + 1;
                    
                        cloud_stored.reset (new pcl::PointCloud<pcl::PointXYZ>);// reset the stored cloud
                        this->stamp = ros::Time::now().toSec();  // update the stamp

                    }catch (...) { // caught by reference to base
                        std::string pcdFile = path + "/empty/empty_cloud.pcd" ;
                        std::string distanceFile = path+ "/distance/" + this->pcd_plane_distance_file;

                        // pcl::PointCloud<pcl::PointXYZ>::Ptr seg_cloud = NdSubprocessHandler::LoadPointFile(pcdFile);

                        std::string interval = " 0.1 "; //publish 10 times a second, If <interval> is zero or not specified the message is published once. 
                        std::string frame = "_frame_id:=/workobject";

                        //--------subprocess for visualizing the segmented cloud--------------------------------------
                        //command line call the pcd_to_pointcloud node: $ rosrun pcl_ros pcd_to_pointcloud <file.pcd> [ <interval> ]
                        // Initialize String Array
                        std::string command_line = "rosrun pcl_ros pcd_to_pointcloud " + pcdFile + interval + frame;  
                        
                        auto s = sp::Popen({command_line});
                        //------------subprocess end---------------------------------------------------

                        //--------------point cloud analysis not ready--------------------
                        // read routine command send from EKI server
                        scanning_robviz::MsgPointCloudScan point_cloud_scan;
                        point_cloud_scan.ready = false;
                        point_cloud_scan.scanning_count = this->scanning_count;
                        pub_point_cloud_scan.publish(point_cloud_scan);


                        // --------------subprocess for defects prediction---------------------------------
                        std::string prediction_python_exe = path + "/defects_prediction/Plane_defect_machine_learning.py";
                        std::string DecisionTree_Model_file = path + "/config/DTC.pkl";

                        std::string prediction_exe = "python " + prediction_python_exe + " " + pcdFile + " " + distanceFile + " " + DecisionTree_Model_file;
                        auto predict = sp::Popen({prediction_exe});
                        // --------------------------------------------------------------------------------

                        this->scanning_count = this->scanning_count + 1;

                        cloud_stored.reset (new pcl::PointCloud<pcl::PointXYZ>);// reset the stored cloud
                        this->stamp = ros::Time::now().toSec();  // update the stamp
                    }
                }
                else{
                    // read routine command send from EKI server
                    scanning_robviz::MsgPointCloudScan point_cloud_scan;
                    point_cloud_scan.ready = false;
                    point_cloud_scan.scanning_count = this->scanning_count;
                    pub_point_cloud_scan.publish(point_cloud_scan);
                }
            }
      }

        void savePointFile (std::string fileName, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) 
        {
          try
          {   
              if ((cloud->width * cloud->height) > 0) {
                    // save the point cloud(cloud) into the file
                    pcl::io::savePCDFileASCII(fileName, *cloud);
                    //std::cerr << "Saved " << *cloud.points.size () << " data points to pcd file." << std::endl;
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


};


int main (int argc, char** argv) {
  ros::init(argc, argv, "subprocess_handler");

  NdSubprocessHandler nd_subprocess_handler;

  ros::spin();
}