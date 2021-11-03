/*
   Updated for SIMTech: Chen Lequn　－　chen1470@e.ntu.edu.sg
 */

#include <camera_measures/MsgPosition.h>
#include <camera_measures/MsgVelocity.h>
#include <camera_measures/MsgTwist.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>



int main(int argc, char** argv)
{
  ROS_INFO_STREAM_NAMED("kuka_velocity", "Starting kuka_velocity...");

  ros::init(argc, argv, "kuka_velocity measures");

  // ros::AsyncSpinner spinner(2);
  // spinner.start();

  ros::NodeHandle nh;

  // ROS publisher
  ros::Publisher pub_position = nh.advertise<camera_measures::MsgPosition>("/kuka_kr90/position", 10);
  ros::Publisher pub_vel = nh.advertise<geometry_msgs::Twist>("/kuka_kr90/twist", 10);


  tf::TransformListener listener;

  //Sets the loop to publish at a rate of 90Hz
  ros::Rate rate(125);
  // Run as fast as possible

  while (ros::ok())
  //while (!g_quit)
  {
    tf::StampedTransform transform;
    
    geometry_msgs::Twist msg_twist;
    try {
            listener.waitForTransform("/tcp_link", "/base_link", ros::Time(0), ros::Duration(10.0) );
            listener.lookupTransform("/tcp_link", "/base_link", ros::Time(0), transform);
            listener.lookupTwist("/tcp_link", "/base_link", ros::Time(0), ros::Duration(0.008), msg_twist);
        } catch (tf::TransformException ex) {
            ROS_ERROR("%s",ex.what());
        }
    
    pub_vel.publish(msg_twist);
    // cart_position_ = simtech_kuka_rsi_hw_interface.cart_position_;
    camera_measures::MsgPosition position_msg;
    position_msg.x = transform.getOrigin().x();
    position_msg.y = transform.getOrigin().y();
    position_msg.z =  transform.getOrigin().z();
    // position_msg.Y = transform.getRotation().yaw();
    // position_msg.P = transform.getRotation().pitch();
    // position_msg.R = transform.getRotation().roll();

    pub_position.publish(position_msg);


    // camera_measures::MsgVelocity vel_msg;
    // vel_msg.speed =  sqrt(pow(transform.getOrigin().x(), 2) +
    //                             pow(transform.getOrigin().y(), 2) +
    //                             pow(transform.getOrigin().z(), 2));
    // pub_vel.publish(vel_msg);



    ros::spinOnce();
    rate.sleep();

  }

  // spinner.stop();
  ROS_INFO_STREAM_NAMED("kuka_velocity", "Shutting down.");

  return 0;

}
