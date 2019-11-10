#include "industrial_robot_client/joint_trajectory_action.h"
#include <industrial_robot_client/utils.h>
#include <industrial_utils/param_utils.h>
#include <industrial_utils/utils.h>


using industrial_robot_client::joint_trajectory_action::JointTrajectoryAction;

int main(int argc, char** argv)
{
  // initialize node
  ros::init(argc, argv, "joint_trajectory_action");

  JointTrajectoryAction action;
  action.run();

  return 0;
}
