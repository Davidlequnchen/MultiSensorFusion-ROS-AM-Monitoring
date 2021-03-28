/*
Created by Chen Lequn
This program will analyze the point cloud produced by micro-epsilon sensor.
After each scanning, it will read the segmented point cloud file and other 
information such as plane coefficient.
The point cloud data are preprocessed by "scanning_robviz" node

Input:
- first scanning - reference substrate plane (segmentedCloud_0.pcd, coefficientPlane_0.pcd)
- from second scanning onwards: (segmentedCloud_x.pcd, coefficientPlane_x.pcd ) 

Output:
- height data file - the distance from scanned plane to the substrate reference plane
- Standard deviation of the height
- deviation from scanned plane coordinate with reference substrate frame 

Functionality:
- apply voxel grid filter to reduce the number of point for the pcd from second scanning onwards
- calculate point to reference plane (substrate) distance for each point in the cloud -- height data
- caluclate standard deiviations of the distance
- check if the difference between reference frame and scanned plane is too large
- future development: 1. check the height data with CAD model　2. ROS publisher: height -overbuild, underbuild, ok

ROS:
- publisher:

- subscribe:


*/


#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Float32MultiArray.h>

#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/common/common_headers.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/features/normal_3d.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/common.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_line.h>
#include <pcl/filters/extract_indices.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/pcd_io.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/transforms.h>

// include the created message
#include <point_cloud_analysis/MsgPointCloudScan.h>  
#include <point_cloud_analysis/MsgHeightMonitoring.h>  

#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iostream> //std::cout
#include <string>  //std::string, std::to_string




std::string path_robviz = ros::package::getPath("scanning_robviz");
std::string path_point_cloud_analysis = ros::package::getPath("point_cloud_analysis");

typedef pcl::PointXYZ Point;
typedef pcl::PointCloud<Point> PointCloud;



class NdPointCloudAnalysis {
    private:
        ros::NodeHandle nh;
        ros::Subscriber sub_point_cloud_scan_info;
        ros::Publisher pub_height_monitoring_info;
        
        // file name for each scanning, corresponds to the results from scanning_robviz
        std::string pcd_filename;
        std::string pcd_segmented_filename;
        std::string pcd_coefficient_plane_file;

        // the substrate (reference) plane file names
        std::string reference_plane_pcd_file;
        std::string reference_plane_pcd_segmented_file;
        std::string reference_plane_coefficient_file;
        
        // store the coeffecient of reference plane 0 and other scanning planes (a,b,c,d)
        std::vector< double > reference_plane_coefficient; 
        std::vector< double > scanning_plane_coefficient;

        // the file contains each points' height relative to the substrate
        std::string plane_height_file;     
        double reference_plane_z_height;
        
      
    public:
        // temp variable for extracting the point cloud from file
        pcl::PointCloud<pcl::PointXYZ>::Ptr plane_cloud_seg;
        pcl::PointCloud<pcl::PointXYZ>::Ptr reference_plane_seg;

        // class constructor
        NdPointCloudAnalysis() {
          plane_cloud_seg.reset (new pcl::PointCloud<pcl::PointXYZ>);// reset the stored cloud
          reference_plane_seg.reset (new pcl::PointCloud<pcl::PointXYZ>);// reset the stored cloud
          // subscriber and call back function
          sub_point_cloud_scan_info = nh.subscribe<point_cloud_analysis::MsgPointCloudScan>("/PointCloudScan_info", 5,  &NdPointCloudAnalysis::cbScanInfo, this);
          // ROS pubisher
          pub_height_monitoring_info = nh.advertise<point_cloud_analysis::MsgHeightMonitoring>("/height_monitoring_info", 10);
          
          }
          

        //destructor
        ~NdPointCloudAnalysis() {}
        

        //call back function
        void cbScanInfo (const point_cloud_analysis::MsgPointCloudScan::ConstPtr &msg)
        {
            if (msg->ready == true){
                // ready to process and analyze the point cloud file
                if (msg->scanning_count == 0) // first scan -- substrate (reference plane)
                {   
                    // ---------------------------------get correct name of the file produced by subprocess handler node-----------------------------
                    this->reference_plane_pcd_file = std::to_string(msg->scanning_count) + ".pcd";
                    this->reference_plane_pcd_segmented_file = "segmentedCloud_" + std::to_string(msg->scanning_count) + ".pcd";
                    this->reference_plane_coefficient_file = "coefficientPlane_" + std::to_string(msg->scanning_count) + ".txt";
                    // ----------------------------------get the full path for each full --------------------------------
                    std::string path_reference_plane_pcd_seg = path_robviz + "/pcl/" + this->reference_plane_pcd_segmented_file;
                    std::string path_reference_plane_coefficient = path_robviz + "/coefficientPlane/" + this->reference_plane_coefficient_file;

                    // ------------------------load the point cloud segmented file, store into a pointer -----------------------------
                    reference_plane_seg = NdPointCloudAnalysis::LoadPointFile(path_reference_plane_pcd_seg);
            
                    // -------------------------------- extract reference plane coefficient-----------------------------------
                    // stored the reference coefficient into an vector
                    bool result = convertFileToVector(path_reference_plane_coefficient, reference_plane_coefficient);
                    if (result){
                        std::cout << "sucessfully convert reference plane coefficient:" << std::endl;
                        std::cout << reference_plane_coefficient[0] << std::endl;
                        std::cout << reference_plane_coefficient[1] << std::endl;
                        std::cout << reference_plane_coefficient[2] << std::endl;
                        std::cout << reference_plane_coefficient[3] << std::endl;
                    }
                    else{
                        std::cout << "error! failed to extract reference plane coefficient" << std::endl;
                    }
                    //------------------------get the mean z-height of the reference plane-----------------------------------
                    this->reference_plane_z_height = calculate_z_height(reference_plane_seg);

                    // ---------------------publish height monitoring informationm-----------------------------------------------
                    point_cloud_analysis::MsgHeightMonitoring height_info;

                    height_info.plane_id = msg->scanning_count;
                    height_info.height_std = 0;
                    height_info.height_mean = 0;
                    height_info.heighest_max_min_difference = 0;
                    height_info.tilt_angle = 0;
                    
                    pub_height_monitoring_info.publish(height_info);
                 
                }
                else{
                    // in-process scanning result
                    //-----------------------------------get name of the file-------------------------------------------
                    this->pcd_filename = std::to_string(msg->scanning_count) + ".pcd";
                    this->pcd_segmented_filename = "segmentedCloud_" + std::to_string(msg->scanning_count) + ".pcd";
                    this->pcd_coefficient_plane_file = "coefficientPlane_" + std::to_string(msg->scanning_count) + ".txt";
                    this->plane_height_file = "plane_height_" + std::to_string(msg->scanning_count) + ".txt";
                    // ----------------------------------get the full path for each full --------------------------------
                    std::string path_file_pcd_seg = path_robviz + "/pcl/" + this->pcd_segmented_filename;
                    std::string path_plane_coefficient = path_robviz + "/coefficientPlane/" + this->pcd_coefficient_plane_file;
                    std::string path_height_file = path_point_cloud_analysis + "/height_data/" + this->plane_height_file;
                    
                    // ------------------------load the point cloud segmented file, store into a pointer -----------------------------
                    plane_cloud_seg = NdPointCloudAnalysis::LoadPointFile(path_file_pcd_seg);
                    // ------------------------- extract reference plane coefficient-----------------------------------
                    bool result = convertFileToVector(path_plane_coefficient, scanning_plane_coefficient);
                    if (result){
                        std::cout << "sucessfully convert the plane " << msg->scanning_count << " coefficient:" << std::endl;
                        std::cout << scanning_plane_coefficient[0] << std::endl;
                        std::cout << scanning_plane_coefficient[1] << std::endl;
                        std::cout << scanning_plane_coefficient[2] << std::endl;
                        std::cout << scanning_plane_coefficient[3] << std::endl;
                    }
                    else{
                        std::cout << "error! failed to extract plane " << msg->scanning_count << " coefficient!" << std::endl;
                    }

                
                    
                    std::vector < double > point_to_reference_height = calculate_height(plane_cloud_seg);
                    savePointToPlaneDistance(path_height_file, point_to_reference_height);
                    
                    // ----------------------extract info to publish to ROS topic ----------------------------------------------
                    double sum = std::accumulate(point_to_reference_height.begin(), point_to_reference_height.end(), 0.0);
                    double mean = sum / point_to_reference_height.size();

                    std::vector<double> diff(point_to_reference_height.size());
                    // std::transform(point_to_reference_height.begin(), point_to_reference_height.end(), diff.begin(),
                    //               std::bind2nd(std::minus<double>(), mean));
                    std::transform(point_to_reference_height.begin(), point_to_reference_height.end(), diff.begin(), 
                                     [mean](double x) { return x - mean; });
                    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
                    double stdev = std::sqrt(sq_sum / point_to_reference_height.size());
                    auto minmax = std::minmax_element(point_to_reference_height.begin(), point_to_reference_height.end());

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////-------------------better method for height calculation---------------------------/////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    double scanning_height = calculate_z_height(plane_cloud_seg);
                    float height_difference = scanning_height - this->reference_plane_z_height;
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////-------------------better method for height calculation---------------------------/////////////////
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                    // ----------------calculate the normal vector angle difference between reference plane and scanning plane 
                    double angle = calculate_angle_difference(scanning_plane_coefficient, reference_plane_coefficient);

                    // ---------------------publish height monitoring informationm-----------------------------------------------
                    point_cloud_analysis::MsgHeightMonitoring height_info;

                    height_info.plane_id = msg->scanning_count;
                    height_info.height_std = stdev;
                    height_info.height_mean = height_difference;
                    height_info.heighest_max_min_difference = *minmax.second - *minmax.first;
                    height_info.tilt_angle = angle;
                    
                    pub_height_monitoring_info.publish(height_info);

                    plane_cloud_seg.reset (new pcl::PointCloud<pcl::PointXYZ>); // reset cloud
                }
                
            }
            
        }

        // calculate the angle difference between two normal vector 
        double calculate_angle_difference (std::vector< double > & a, std::vector< double > & b)
        {

            //calculates dot product of a and b
            double dot_product = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];

            //calculates magnitude of a
            double magnitute_a =  std::sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
            //calculates magnitude of b
            double magnitute_b =  std::sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
        
            // calculate the angle between to vector
            double angle = std::acos(dot_product/( magnitute_a * magnitute_b ));

            return angle;
        }



        /*
        convertFileToVector: function read the file line by line and store it into a vector of double 
        */
        bool convertFileToVector(std::string fileName, std::vector< double > & vector)
        {
            // Open the File
            std::ifstream in(fileName.c_str());
            // Check if object is valid
            if(!in)
            {
                std::cerr << "Cannot open the File : "<<fileName<<std::endl;
                return false;
            }
            std::string str;
            // Read the next line from File untill it reaches the end.
            while (std::getline(in, str))
            {
                // Line contains string of length > 0 then save it in vector
                if(str.size() > 0){
                    std::string::size_type sz;     // alias of size_t
                    double value = std::stod (str,&sz); // convert string to double value
                    vector.push_back(value);
                }
            }
            //Close The File
            in.close();
            return true;
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


        // save the point to plane distance value into a txt file
        void savePointToPlaneDistance (std::string filename, std::vector< double > distance )
        {
            std::ofstream output_file(filename);
            std::ostream_iterator<double> output_iterator(output_file, "\n");
            std::copy(distance.begin(), distance.end(), output_iterator);
        }
        
        
        std::vector < double > calculate_height (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
        {
        /* calculate the point to reference plane height
        Input: the point cloud pointer
        Output: a vector of doubles
        */
            std::vector < double > point_to_plane_distance_vector;

            int i = 0;
            while (i < cloud->points.size () ) // loop to calculate the pointToPlaneDistanceSigned
            {
                double Distance; // temporary double value to store current pointToPlaneDisntacne (signed)
                Distance = pcl::pointToPlaneDistanceSigned (cloud->points[i], this->reference_plane_coefficient[0]
                                                            ,this->reference_plane_coefficient[1]
                                                            ,this->reference_plane_coefficient[2]
                                                            ,this->reference_plane_coefficient[3]  );
                
                point_to_plane_distance_vector.push_back(Distance);
                i++;
            }
            return point_to_plane_distance_vector;
        }


        double calculate_z_height (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
        {
            /* calculate the point to work object frame height, i.e, the average z value of the point cloud
            Input: the point cloud pointer
            Output: a vector of doubles
            */
            int i = 0;
            double sum;
            while (i < cloud->points.size () ) // loop to sum
            {
                sum = sum + cloud->points[i].z;
                i++;
            }
            double mean = sum / cloud->points.size();

            return mean;
        }

};


int main (int argc, char** argv) {
  ros::init(argc, argv, "point_cloud_analysis");

  NdPointCloudAnalysis nd_point_cloud_analysis;

  ros::spin();
}