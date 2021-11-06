/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2014 Norwegian University of Science and Technology
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Norwegian University of Science and
 *     Technology, nor the names of its contributors may be used to
 *     endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/*
 * Original Author: Lars Tingelstad <lars.tingelstad@ntnu.no>
   Updated for SIMTech: Chen Lequn　－　chen1470@e.ntu.edu.sg
 */

#include <simtech_kuka_rsi_hw_interface/simtech_kuka_rsi_hw_interface.h>
// message
#include <simtech_kuka_rsi_hw_interface/MsgCartPosition.h>
#include <simtech_kuka_rsi_hw_interface/MsgCartVelocity.h>

int main(int argc, char** argv)
{
  ROS_INFO_STREAM_NAMED("hardware_interface", "Starting hardware interface...");

  ros::init(argc, argv, "simtech_kuka_rsi_hw_interface");

  ros::AsyncSpinner spinner(2);
  spinner.start();

  ros::NodeHandle nh;

  // ROS publisher
  ros::Publisher pub_cartesian_position = nh.advertise<simtech_kuka_rsi_hw_interface::MsgCartPosition>("/cartesian_position", 10);
  ros::Publisher pub_cartesian_velocity = nh.advertise<simtech_kuka_rsi_hw_interface::MsgCartVelocity>("/cartesian_velocity", 10);

  simtech_kuka_rsi_hw_interface::KukaHardwareInterface simtech_kuka_rsi_hw_interface;
  simtech_kuka_rsi_hw_interface.configure();

  // Set up timers
  ros::Time timestamp;
  ros::Duration period;
  auto stopwatch_last = std::chrono::steady_clock::now();
  auto stopwatch_now = stopwatch_last;

  controller_manager::ControllerManager controller_manager(&simtech_kuka_rsi_hw_interface, nh);

  simtech_kuka_rsi_hw_interface.start();

  // Get current time and elapsed time since last read
  timestamp = ros::Time::now();
  stopwatch_now = std::chrono::steady_clock::now();
  period.fromSec(std::chrono::duration_cast<std::chrono::duration<double>>(stopwatch_now - stopwatch_last).count());
  stopwatch_last = stopwatch_now;

  // Run as fast as possible
  while (ros::ok())
  //while (!g_quit)
  {
    // Receive current state from robot
    if (!simtech_kuka_rsi_hw_interface.read(timestamp, period))
    {
      ROS_FATAL_NAMED("kuka_hardware_interface", "Failed to read state from robot. Shutting down!");
      ros::shutdown();
    }
    // publish cartesian position read directly from the rsi interface
    simtech_kuka_rsi_hw_interface::MsgCartPosition cartesian_position_msg;
    cartesian_position_msg.X = simtech_kuka_rsi_hw_interface.cart_position_[0];
    cartesian_position_msg.Y = simtech_kuka_rsi_hw_interface.cart_position_[1];
    cartesian_position_msg.Z = simtech_kuka_rsi_hw_interface.cart_position_[2];
    cartesian_position_msg.A = simtech_kuka_rsi_hw_interface.cart_position_[3];
    cartesian_position_msg.B = simtech_kuka_rsi_hw_interface.cart_position_[4];
    cartesian_position_msg.C = simtech_kuka_rsi_hw_interface.cart_position_[5];
    pub_cartesian_position.publish(cartesian_position_msg);

    /* Python reference code, adopted from the nd_velocity node in camera measures package
    speed, velocity = self.velocity.instantaneous(
        stamp.to_sec(), np.array(position))
    self.msg_velocity.header.stamp = stamp
    self.msg_velocity.speed = speed
    self.msg_velocity.vx = velocity[0]
    self.msg_velocity.vy = velocity[1]
    self.msg_velocity.vz = velocity[2]
    self.velocity_pub.publish(self.msg_velocity)
    */
    // calculate and publish the cartesian velocity based on the cartesian position
    simtech_kuka_rsi_hw_interface::MsgCartVelocity cartesian_velocity_msg;
    simtech_kuka_rsi_hw_interface.calculate_cart_velocity(timestamp.toSec(), simtech_kuka_rsi_hw_interface.cart_position_);
    cartesian_velocity_msg.Vx = simtech_kuka_rsi_hw_interface.cart_velocity_[0];
    cartesian_velocity_msg.Vy = simtech_kuka_rsi_hw_interface.cart_velocity_[1];
    cartesian_velocity_msg.Vz = simtech_kuka_rsi_hw_interface.cart_velocity_[2];
    cartesian_velocity_msg.Speed = simtech_kuka_rsi_hw_interface.cart_velocity_[3];
    pub_cartesian_velocity.publish(cartesian_velocity_msg);


    // Get current time and elapsed time since last read
    timestamp = ros::Time::now();
    stopwatch_now = std::chrono::steady_clock::now();
    period.fromSec(std::chrono::duration_cast<std::chrono::duration<double>>(stopwatch_now - stopwatch_last).count());
    stopwatch_last = stopwatch_now;

    // Update the controllers
    controller_manager.update(timestamp, period);

    // Send new setpoint to robot
    simtech_kuka_rsi_hw_interface.write(timestamp, period);
  }

  spinner.stop();
  ROS_INFO_STREAM_NAMED("hardware_interface", "Shutting down.");

  return 0;

}
