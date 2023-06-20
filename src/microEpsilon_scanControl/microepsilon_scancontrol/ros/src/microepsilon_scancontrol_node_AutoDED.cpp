#include "ros/ros.h"
#include "microepsilon_scancontrol.h"
#include <std_srvs/SetBool.h>
#include <microepsilon_scancontrol/MsgCommand.h>

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

This program is directly modified from microepsilon_scancontrol_node.cpp
This program is used for the AutoDED project.
It added the feature of ROS service commincation to turn on/off the scanning functionality during DED process

*/

// global variable
bool is_active;


namespace microepsilon_scancontrol
{
double average(double a, double b)
{

  return ( a + b ) / 100000.0 / 2.0; //version2 
}



class ScannerNode : Notifyee // version 2
{
public:

  ScannerNode ( unsigned int shutter_time, unsigned int idle_time, double lag_compensation, std::string topic,
                   std::string frame, std::string serial_number, std::string path_to_device_properties ); // version 2

 
  void publish ( ScanProfileConvertedPtr ); // version 2
  bool startScanning();
  bool stopScanning();
  bool reconnect();
  // bool disconnect();
  bool setLaserPower(bool set);
  void cbCommand (const microepsilon_scancontrol::MsgCommand::ConstPtr &msg);
  virtual void notify ( ScanProfileConvertedPtr ); // version 2

private:
  
  bool laser_on(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res);
  bool laser_off(std_srvs::Empty::Request& req, std_srvs::Empty::Response& res);
  bool scanning_switch(std_srvs::SetBoolRequest&req, std_srvs::SetBoolResponse &response);

  
  ros::NodeHandle nh_;
  ros::Subscriber sub_command;
  ros::Publisher scan_pub_;
  ros::ServiceServer scanning_switch_;
  ros::ServiceServer laser_on_, laser_off_;
  Scanner laser_;
  double lag_compensation_;
  std::string frame_;
  bool publishing_;

};

// class constructor

ScannerNode::ScannerNode ( unsigned int shutter_time, unsigned int idle_time, double lag_compensation, 
                          std::string topic, std::string frame, std::string serial_number, std::string path_to_device_properties ) 
: laser_ ( this, shutter_time, idle_time, serial_number, path_to_device_properties ) 
, lag_compensation_ ( lag_compensation )
, frame_ ( frame )
  {
    scan_pub_ = nh_.advertise < PointCloudT > (  topic, 200 );
    sub_command = nh_.subscribe("/routine_command", 5,  &ScannerNode::cbCommand, this);
    laser_off_ = nh_.advertiseService ( "laser_off", &ScannerNode::laser_off, this );
    laser_on_ = nh_.advertiseService ( "laser_on", &ScannerNode::laser_on, this );
    scanning_switch_ = nh_.advertiseService ("scanning_switch", &ScannerNode::scanning_switch, this);
    publishing_ = true;
    ROS_INFO ( "Connecting to Laser" );
  }



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

void ScannerNode::cbCommand (const microepsilon_scancontrol::MsgCommand::ConstPtr &msg)
{
  if (msg->command == 1.0){
    is_active = true;
  }

  else{
    is_active = false;
  }
}

bool ScannerNode::scanning_switch (std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &response)
{
  is_active=req.data;
  if(is_active==true){
    response.success=true;
    response.message="scanning task on";
    laser_.setLaserPower(true);
    ROS_INFO("scanning task on");
  }else{
      response.success= false;
      laser_.setLaserPower(false);
      response.message="laser scanning off";
      ROS_INFO("laser scanning off");
    }
  
  return true;
}


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
      // std::cout << "Time now is: [" << now << "], Time for cloud_msg_ is: [" << profile_time << "], Time different is: [" << ( now - profile_time ) << std::endl;
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

bool ScannerNode::setLaserPower(bool set)
{
  laser_.setLaserPower(set);
}






}  // namespace microepsilon_scancontrol



//#######################
//#### main programm ####
int main(int argc, char** argv)
{
  ros::init(argc, argv, "microepsilon_scancontrol_node_AutoDED");

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
  

  if (!nh_private.getParam("lag_compensation", lag_compensation))
  {
    lag_compensation = 0.0;
  }
  ROS_INFO("***Shutter Time: %.2fms Idle Time: %.2fms Frequency: %.2fHz", shutter_time / 100.0, idle_time / 100.0,
           100000.0 / (shutter_time + idle_time));
  //  ROS_INFO("Profiles for each Container: %d", container_size);
  ROS_INFO("Lag compensation: %.3fms", lag_compensation * 1000);


  // ---------- version scannernode constructor
  microepsilon_scancontrol::ScannerNode scanner ( shutter_time, idle_time, lag_compensation, topic,
                                                  frame, serial_number, path_to_device_properties );



  


// method 3------------------------------------------------------------------------------------
ros::Rate loop_rate(30);
while (ros::ok())
  {
    // std::cout << "is_active: " << std::to_string(scanner.is_active) << std::endl;
    if (is_active == false){
      // if the service is not active, then directly sleep without doing anything (do not turn on sensor)
      // ros::spinOnce();
      
      scanner.stopScanning();
      scanner.setLaserPower(false);
      ROS_INFO("Scanning stopped.");
      // loop_rate.sleep();
    }
    else{
      scanner.setLaserPower(true);
      bool scanning = scanner.startScanning();

      if (!scanning){
        ROS_ERROR("Couldn't start scanning. Reconnecting!");
        scanner.reconnect();
        scanner.setLaserPower(true);
        scanning = scanner.startScanning();
      }
      ROS_INFO("Started scanning.");
    }

    ros::spinOnce();
    loop_rate.sleep();
    

    // ros::spinOnce(); 
    // loop_rate.sleep();

  }

  // ros::spin();
  
  // multi threaded spining
  // ros::AsyncSpinner spinner( 6 );
  // spinner.start();
  // ros::waitForShutdown();
  // scanner.stopScanning();
  // return 0;



}
