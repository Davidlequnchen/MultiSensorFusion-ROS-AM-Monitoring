#include "ros/ros.h"
#include "microepsilon_scancontrol.h"

#include "sensor_msgs/PointCloud2.h"
#include <sensor_msgs/point_cloud2_iterator.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_srvs/Empty.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud< PointT > PointCloudT;

/*

version 1: container mode, meseaurement field, time synchronize
version 2: profile mode only
version 3 : container mode. delete measurement field, but has same method of publishing as version 1

*/

namespace microepsilon_scancontrol
{
double average(double a, double b)
{
  // return (a + b) / 2.0;
  return ( a + b ) / 100000.0 / 2.0; //version2 
}

// class ScannerNode : public TimeSync, Notifyee
class ScannerNode : Notifyee // version 2
{
public:
  // ScannerNode(unsigned int shutter_time, unsigned int idle_time, unsigned int container_size, MeasurementField field,
  //             double lag_compensation, std::string topic, std::string frame, std::string serial_number,
  // //             std::string path_to_device_properties); //version 1
  // ScannerNode ( unsigned int shutter_time, unsigned int idle_time, unsigned int container_size, double lag_compensation, std::string topic,
  //                 std::string frame, std::string serial_number, std::string path_to_device_properties ); // version 3
  ScannerNode ( unsigned int shutter_time, unsigned int idle_time, double lag_compensation, std::string topic,
                   std::string frame, std::string serial_number, std::string path_to_device_properties ); // version 2

  // void publish();
  void publish ( ScanProfileConvertedPtr ); // version 2
  bool startScanning();
  bool stopScanning();
  bool reconnect();
  // virtual void sync_time(unsigned int profile_counter, double shutter_open, double shutter_close);
  // virtual void notify();
  virtual void notify ( ScanProfileConvertedPtr ); // version 2

private:
  // void initialiseMessage();
  bool laser_on(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res);
  bool laser_off(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res);
  
  //-------------------------------version 1
  // ros::Publisher scan_pub_;
  // ros::Publisher meassured_z_pub_;
  // ros::ServiceServer laser_on_, laser_off_;
  // ros::NodeHandle nh_;
  // // laser data
  // Scanner laser_;
  // int last_second_;
  // double lag_compensation_;
  // // published data
  // sensor_msgs::PointCloud2 cloud_msg_;
  // // parameters
  // ros::Duration shutter_close_sync_;
  // std::string frame_;
  // bool publishing_;
  //---------------------------------version 2
    ros::NodeHandle nh_;
    ros::Publisher scan_pub_;
    ros::ServiceServer laser_on_, laser_off_;
    Scanner laser_;
    double lag_compensation_;
    std::string frame_;
    bool publishing_;
};

// class constructor
//---------original-----------------------------------
// ScannerNode::ScannerNode(unsigned int shutter_time, unsigned int idle_time, unsigned int container_size,
//                          MeasurementField field, double lag_compensation, std::string topic, std::string frame,
//                          std::string serial_number, std::string path_to_device_properties)
//   : laser_(this, this, shutter_time, idle_time, container_size, field, serial_number, path_to_device_properties)
//   , lag_compensation_(lag_compensation)
//   , frame_(frame)
// {
//   scan_pub_ = nh_.advertise<sensor_msgs::PointCloud2>(topic, 500);
//   meassured_z_pub_ = nh_.advertise<std_msgs::Float32MultiArray>("meassured_z", 50);
//   laser_off_ = nh_.advertiseService("laser_off", &ScannerNode::laser_off, this);
//   laser_on_ = nh_.advertiseService("laser_on", &ScannerNode::laser_on, this);
//   publishing_ = true;
//   initialiseMessage();
//   ROS_INFO("Connecting to Laser");
// }
//-------------------second version -- 
ScannerNode::ScannerNode ( unsigned int shutter_time, unsigned int idle_time, double lag_compensation, 
                          std::string topic, std::string frame, std::string serial_number, std::string path_to_device_properties ) 
: laser_ ( this, shutter_time, idle_time, serial_number, path_to_device_properties ) 
, lag_compensation_ ( lag_compensation )
, frame_ ( frame )
  {
    scan_pub_ = nh_.advertise < PointCloudT > (  topic, 200 );
    laser_off_ = nh_.advertiseService ( "laser_off", &ScannerNode::laser_off, this );
    laser_on_ = nh_.advertiseService ( "laser_on", &ScannerNode::laser_on, this );
    publishing_ = true;
    ROS_INFO ( "Connecting to Laser" );
  }
// -----------------third version------------
// ScannerNode::ScannerNode(unsigned int shutter_time, unsigned int idle_time, unsigned int container_size,
//                         double lag_compensation, std::string topic, std::string frame,
//                          std::string serial_number, std::string path_to_device_properties)
//   : laser_(this, this, shutter_time, idle_time, container_size, serial_number, path_to_device_properties)
//   , lag_compensation_(lag_compensation)
//   , frame_(frame)
// {
//   scan_pub_ = nh_.advertise<sensor_msgs::PointCloud2>(topic, 500);
//   meassured_z_pub_ = nh_.advertise<std_msgs::Float32MultiArray>("meassured_z", 50);
//   laser_off_ = nh_.advertiseService("laser_off", &ScannerNode::laser_off, this);
//   laser_on_ = nh_.advertiseService("laser_on", &ScannerNode::laser_on, this);
//   publishing_ = true;
//   initialiseMessage();
//   ROS_INFO("Connecting to Laser");
// }
//---------------------------------------------------------------------------------------------------


// void ScannerNode::sync_time(unsigned int profile_counter, double shutter_open, double shutter_close)
// {
//   ROS_DEBUG("New Timestamp: %d %9f", profile_counter, average(shutter_open, shutter_close));
//   shutter_close_sync_ =
//       ros::Time::now() - ros::Time(average(shutter_open, shutter_close)) - ros::Duration(lag_compensation_);
//   last_second_ = 0;
// }

// void ScannerNode::notify()
// {
//   publish();
// }
// -------------------------version 2
 void ScannerNode::notify ( ScanProfileConvertedPtr data )
  {
    publish ( data );
  }

bool ScannerNode::laser_off(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res)
{
  publishing_ = false;
  // return true;
  return laser_.setLaserPower(false);
}
bool ScannerNode::laser_on(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res)
{
  publishing_ = true;
  // return true;
  return laser_.setLaserPower(true);
}

// void ScannerNode::initialiseMessage()// used for version 1 and 3
// {
//   cloud_msg_.header.frame_id = frame_;
//   cloud_msg_.is_bigendian = false;
//   cloud_msg_.is_dense = true;
//   cloud_msg_.height = 1;
//   cloud_msg_.width = 640;
//   sensor_msgs::PointCloud2Modifier modifier(cloud_msg_);
//   modifier.setPointCloud2Fields(3, "x", 1, sensor_msgs::PointField::FLOAT32, "y", 1, sensor_msgs::PointField::FLOAT32,
//                                 "z", 1, sensor_msgs::PointField::FLOAT32);
//   modifier.reserve(640);
// }

// void ScannerNode::publish()
// {
//   while (laser_.hasNewData())
//   {
//     sensor_msgs::PointCloud2Iterator<float> iter_x(cloud_msg_, "x");
//     sensor_msgs::PointCloud2Iterator<float> iter_z(cloud_msg_, "z");
//     sensor_msgs::PointCloud2Iterator<float> iter_y(cloud_msg_, "y");
//     ScanProfileConvertedPtr data = laser_.getData();
//     ros::Time profile_time(average(data->shutter_open, data->shutter_close));
//     if (profile_time.toSec() - last_second_ < 0)
//     {
//       shutter_close_sync_ += ros::Duration(128);
//     }
//     last_second_ = profile_time.toSec();
//     if (publishing_)
//     {
//       cloud_msg_.header.stamp = profile_time + shutter_close_sync_;
//       ++cloud_msg_.header.seq;
//       ROS_DEBUG_STREAM(profile_time << " " << cloud_msg_.header.stamp);
//       sensor_msgs::PointCloud2Modifier modifier(cloud_msg_);
//       modifier.resize(data->x.size());
//       static bool firstrun = true;
//       if (firstrun)
//       {
//         ROS_INFO_STREAM("Points per profile: " << data->z.size());
//         firstrun = false;
//       }
//       for (int i = 0; i < data->x.size(); ++i, ++iter_x, ++iter_z, ++iter_y)
//       {
//         *iter_x = data->x[i];
//         *iter_z = data->z[i];
//         *iter_y = 0.0;
//       }
//       scan_pub_.publish(cloud_msg_);
//       std_msgs::Float32MultiArray meassured_z;
//       if (data->z.size() > 0)
//       {
//         meassured_z.data.push_back((float)data->z[0]);
//         meassured_z.data.push_back((float)data->z[data->z.size() / 2]);
//         meassured_z.data.push_back((float)data->z[data->z.size() - 1]);
//         meassured_z_pub_.publish(meassured_z);
//       }
//     }
//   }
// }
// ---------------------------------------------second version of publish
void ScannerNode::publish ( ScanProfileConvertedPtr data )
  {
    if ( publishing_ )
    {
      PointCloudT cloud_msg_;
      cloud_msg_.header.frame_id = frame_;
      cloud_msg_.height = 1;
      ros::Time now = ros::Time::now();
      ros::Time profile_time = now - ros::Duration ( average ( data->shutter_open, data->shutter_close ) + lag_compensation_ );
      pcl_conversions::toPCL ( profile_time, cloud_msg_.header.stamp );
      std::cout << "Time now is: [" << now << "], Time for cloud_msg_ is: [" << profile_time << "], Time different is: [" << ( now - profile_time ) << std::endl;
      ++cloud_msg_.header.seq;
      PointT temp_point;
      int point_counter = 0;
      // double min_z = 140;
      for ( int i = 0; i < data->x.size(); ++i )
      {
        if ( data->z[i] > 30 )
        {
          // if ( data->z[i] < min_z )
          // {
          //   min_z = data->z[i];
          // }
          temp_point.x = - data->x[i] / 1000.0;
    			temp_point.y = data->z[i] / 1000.0;
    			temp_point.z = 0.0;
    			cloud_msg_.points.push_back ( temp_point );
          point_counter++;
        }
      }
      cloud_msg_.width = point_counter;
      // std::cout << "min_z = " << min_z << std::endl;
      scan_pub_.publish ( cloud_msg_ );
    }
  }



bool ScannerNode::startScanning()
{
  return laser_.startScanning();
}

bool ScannerNode::stopScanning()
{
  return laser_.stopScanning();
}

bool ScannerNode::reconnect()
{
  laser_.reconnect();
}

}  // namespace microepsilon_scancontrol



//#######################
//#### main programm ####
int main(int argc, char** argv)
{
  ros::init(argc, argv, "microepsilon_scancontrol_node");

  ros::NodeHandle nh_private("~");

  int shutter_time;
  int idle_time;
  // int container_size;
  double lag_compensation;
  std::string topic, frame, serial_number, path_to_device_properties;
  // double field_left, field_right, field_far, field_near;
  if (!nh_private.getParam("shutter_time", shutter_time))
  {
    ROS_ERROR("You have to specify parameter shutter_time!");
    return -1;
  }
  if (!nh_private.getParam("idle_time", idle_time))
  {
    ROS_ERROR("You have to specify parameter idle_time!");
    return -1;
  }
  // if (!nh_private.getParam("container_size", container_size))
  // {
  //   ROS_ERROR("You have to specify parameter container_size!");
  //   return -1;
  // }
  if (!nh_private.getParam("frame", frame))
  {
    ROS_ERROR("You have to specify parameter frame!");
    return -1;
  }
  if (!nh_private.getParam("path_to_device_properties", path_to_device_properties))
  {
    ROS_ERROR("You have to specify parameter path_to_device_properties!");
    return -1;
  }
  if (!nh_private.getParam("topic", topic))
  {
    topic = "laser_scan";
  }
  if (!nh_private.getParam("serial_number", serial_number))
  {
    serial_number = "";
  }
  // if (!nh_private.getParam("field_left", field_left))
  // {
  //   field_left = 0.0;
  // }
  // if (!nh_private.getParam("field_right", field_right))
  // {
  //   field_right = 0.0;
  // }
  // if (!nh_private.getParam("field_far", field_far))
  // {
  //   field_far = 0.0;
  // }
  // if (!nh_private.getParam("field_near", field_near))
  // {
  //   field_near = 0.0;
  // }
  if (!nh_private.getParam("lag_compensation", lag_compensation))
  {
    lag_compensation = 0.0;
  }
  ROS_INFO("***Shutter Time: %.2fms Idle Time: %.2fms Frequency: %.2fHz", shutter_time / 100.0, idle_time / 100.0,
           100000.0 / (shutter_time + idle_time));
  //  ROS_INFO("Profiles for each Container: %d", container_size);
  ROS_INFO("Lag compensation: %.3fms", lag_compensation * 1000);

  // field_left = fmin(fmax(field_left, 0.0), 1.0);
  // field_right = fmin(fmax(field_right, 0.0), 1.0);
  // field_far = fmin(fmax(field_far, 0.0), 1.0);
  // field_near = fmin(fmax(field_near, 0.0), 1.0);
  // microepsilon_scancontrol::MeasurementField field(field_left, field_right, field_far, field_near);
  // ---------- version 2 scannernode constructor
  microepsilon_scancontrol::ScannerNode scanner ( shutter_time, idle_time, lag_compensation, topic,
                                                  frame, serial_number, path_to_device_properties );
  //----------- version 1 scannerNode constructor
  // microepsilon_scancontrol::ScannerNode scanner(shutter_time, idle_time, container_size, field, lag_compensation, topic,
  //                                               frame, serial_number, path_to_device_properties);
  //-----------version 3 scannerNode construtor
  // microepsilon_scancontrol::ScannerNode scanner(shutter_time, idle_time, container_size, lag_compensation, topic,
  //                                                frame, serial_number, path_to_device_properties);
                                                 
  bool scanning = scanner.startScanning();
  while (!scanning && !ros::isShuttingDown())
  {
    ROS_ERROR("Couldn't start scanning. Reconnecting!");
    scanner.reconnect();
    scanning = scanner.startScanning();
  }
  ROS_INFO("Started scanning.");

  // ros::spin();
  ros::AsyncSpinner spinner( 6 );
  spinner.start();
  ros::waitForShutdown();
  scanner.stopScanning();
  return 0;
}
