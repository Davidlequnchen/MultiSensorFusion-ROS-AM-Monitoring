# Defects Identification

This node subscribe the point cloud after filtering and segmentation, then perform defects predition. It will publish the defects identification results, and decide whether to stop the robot and stop the laser.

## Launch file 
1. defects_prediction.launch
   * this is the actual defects prediction launch file used.
   * Nodes: 
     * scanning_robviz/launch/_**robviz_microepsilon.launch**_:
         * microepsilon_workcell/launch/__workcell.launch__
         * nd_cloud, Package: "point_cloud_scanning"
         * rob_scanning_visualization.py, Package: "scanning_robviz"
         * nd_subprocess_handler. Package: "scanning_robviz"
         * camera_measures/launch/velocity_measures.launch"
     * nd_defects_identification
  




2. defects_prediction_test.launch
   * this one is for simulation in Rviz, no need to connect to robot, only for testing. Just connect to the sensor is enough
   * Nodes
     * scanning_robviz/launch/_**robviz_microepsilon_simulation.launch**_:
         * microepsilon_workcell/launch/__workcell_test.launch__
         * nd_cloud, Package: "point_cloud_scanning"
         * rob_scanning_visualization.py, Package: "scanning_robviz"
         * nd_subprocess_handler. Package: "scanning_robviz"
         * camera_measures/launch/velocity_measures.launch"
     * nd_defects_identification


## ROS Node

### nd_defects_identification
This ROS node identifies the defects on planar surfaces based on training results.

* Subscribed ROS Topoic
   - __"/cloud_pcd"__: the in-situ surface monitoring feedback provied by subprocess handler node, by running the "rosrun pcl_ros pcd_to_pointcloud "

* Publish ROS Topic:
  -  __"/plane_defects_identification"__ : MsgDefects


### nd_laser_robot_stop
This node receives defects identification result, then issues command to robot controller to stop the robot and laser if any defects found.

* Subscribed ROS Topoic
   - __"/plane_defects_identification"__: (MsgDefects) -- the defects identification result:  0 / 1 / 2 / 3

* Publish ROS Topic:
  -  None
  -  Instead of publishing ROS Topic, it will issue the stop command directly to the laser server and robot motion server socket.

