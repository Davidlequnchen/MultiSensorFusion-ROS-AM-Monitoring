/*
Created by Chen Lequn
*/
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/common/common_headers.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/sample_consensus/sac_model_plane.h>
#include <pcl/features/normal_3d.h>
// #include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/common.h>
#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_line.h>
#include <pcl/filters/extract_indices.h>
// #include <pcl_conversions/pcl_conversions.h>
#include <pcl/io/pcd_io.h>


#include <ctime>
#include <cmath>
#include <sstream>
#include <fstream>
#include <iostream> //std::cout
#include <string>  //std::string, std::to_string



typedef pcl::PointXYZ Point;
typedef pcl::PointCloud<Point> PointCloud;



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


       

int main (int argc, char** argv) {

    // load the point cloud file
    std::string reference_plate_file_name = "segmentedCloud_0.pcd";
    std::string scanning1_file = "segmentedCloud_1.pcd";
    std::string scanning2_file = "segmentedCloud_2.pcd";
    std::string scanning3_file = "segmentedCloud_3.pcd";


    pcl::PointCloud<pcl::PointXYZ>::Ptr reference_plate_point_cloud_pointer = LoadPointFile(reference_plate_file_name);
    pcl::PointCloud<pcl::PointXYZ>::Ptr scanning1_point_cloud_pointer = LoadPointFile(scanning1_file);
    pcl::PointCloud<pcl::PointXYZ>::Ptr scanning2_point_cloud_pointer = LoadPointFile(scanning2_file);
    pcl::PointCloud<pcl::PointXYZ>::Ptr scanning3_point_cloud_pointer = LoadPointFile(scanning3_file);

    double reference_plate_height = calculate_z_height(reference_plate_point_cloud_pointer);
    double scanning1_height = calculate_z_height(scanning1_point_cloud_pointer);
    double scanning2_height = calculate_z_height(scanning2_point_cloud_pointer);
    double scanning3_height = calculate_z_height(scanning3_point_cloud_pointer);

    float height_difference01 = scanning1_height - reference_plate_height;
    float height_difference02 = scanning2_height - reference_plate_height;
    float height_difference03 = scanning3_height - reference_plate_height;

    std::cout << "height_difference01: " << height_difference01 << std::endl;
    std::cout << "height_difference02: " << height_difference02 << std::endl;
    std::cout << "height_difference03: " << height_difference03 << std::endl;



}