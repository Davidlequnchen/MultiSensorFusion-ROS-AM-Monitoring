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


double min_max_z_value (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
/* get the min and max z height value from the point cloud
Input: the point cloud pointer
Output: min and max z value (double)
*/
    int i = 0;
    std::vector< double >  vector_z_value;

    while (i < cloud->points.size () ) // loop to sum
    {
        vector_z_value.push_back (cloud->points[i].z);
        i++;
    }

    auto minmax = minmax_element(std::begin(vector_z_value), std::end(vector_z_value));

    std::cout << "minimum height value: " << *minmax.first << std::endl;
    std::cout << "maximum height value: " << *minmax.second << std::endl;
    double difference = *minmax.second - *minmax.first;

}


// double min_max_z_value (std::vector< double > & local_distance_vector)
// {
//     /* get the min and max z height value from the point cloud
//     Input: the point cloud local distance to reference plane (vector)
//     Output: min and max z value (double)
//     */
//     int i = 0;

//     auto minmax = minmax_element(std::begin(local_distance_vector), std::end(local_distance_vector));

//     std::cout << "minimum height value: " << *minmax.first << std::endl;
//     std::cout << "maximum height value: " << *minmax.second << std::endl;
//     double difference = *minmax.second - *minmax.first;

// }

       

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

    // std::string path_localDistance_file0 = "localDistance_0.txt";
    // std::string path_localDistance_file1 = "localDistance_1.txt";
    // std::string path_localDistance_file2 = "localDistance_2.txt";
    // std::vector< double > local_distance_vector_0;
    // std::vector< double > local_distance_vector_1;
    // std::vector< double > local_distance_vector_2;
    

    // convertFileToVector(path_localDistance_file0, local_distance_vector_0);
    // convertFileToVector(path_localDistance_file1, local_distance_vector_1);
    // convertFileToVector(path_localDistance_file2, local_distance_vector_2);


    // double min_max_difference0 = min_max_z_value (local_distance_vector_0);
    // double min_max_difference1 = min_max_z_value (local_distance_vector_1);
    // double min_max_difference2 = min_max_z_value (local_distance_vector_2);
    // std::cout << "min_max_difference_0: " << min_max_difference0 * 1000 << std::endl;
    // std::cout << "min_max_difference_1: " << min_max_difference1 * 1000 << std::endl;
    // std::cout << "min_max_difference_2: " << min_max_difference2 * 1000 << std::endl;

    // double sq_sum = std::inner_product(local_distance_vector_2.begin(), local_distance_vector_2.end(), 
    //                                     local_distance_vector_2.begin(), 0.0);
    // double stdev = std::sqrt(sq_sum / local_distance_vector_2.size());

    // std::cout << "stddev_2: " << stdev * 1000 << std::endl;



    double min_max_difference1 = min_max_z_value (scanning1_point_cloud_pointer);
    double min_max_difference2 = min_max_z_value (scanning2_point_cloud_pointer);
    double min_max_difference3 = min_max_z_value (scanning3_point_cloud_pointer);
    std::cout << "min_max_difference_1: " << min_max_difference1 * 1000 << std::endl;
    std::cout << "min_max_difference_2: " << min_max_difference2 * 1000 << std::endl;
    std::cout << "min_max_difference_3: " << min_max_difference3 * 1000 << std::endl;

    // double sq_sum = std::inner_product(local_distance_vector_2.begin(), local_distance_vector_2.end(), 
    //                                     local_distance_vector_2.begin(), 0.0);
    // double stdev = std::sqrt(sq_sum / local_distance_vector_2.size());

    // std::cout << "stddev_2: " << stdev * 1000 << std::endl;


    float height_difference01 = (scanning1_height - reference_plate_height) * 1000;
    float height_difference02 = (scanning2_height - reference_plate_height) * 1000;
    float height_difference03 = (scanning3_height - reference_plate_height) * 1000;

    std::cout << "height_difference01: " << height_difference01 << std::endl;
    std::cout << "height_difference02: " << height_difference02 << std::endl;
    std::cout << "height_difference03: " << height_difference03 << std::endl;



}