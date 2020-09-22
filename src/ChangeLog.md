# New changes and updates 

## New ROS programs and nodes


1. **nd_adaptive_pid_calculation.py** (the ros node for pid parameter calcualtion based on speed changes) inside "simtech_robot_laser_control->script"
2. __nd_pid_vrft.py__ (the ros node for vrft pid parameter calculation)
3. __qt_control_v2.py__ (add vrft features in qt based on original version)
4. __control_v2.ui__ (add vrft feature) inside "simtech_robot_laser_control->resources"
5. add __adaptive_calculation.yaml__ inside "simtech_robot_laser_control->config", this file specifies calculation coefficient as rosparm
6. __"control_pro.py"__ in "simtech_robot_laser_control->src->control": contains modified pid algorithm with anti-windup
7. __"nd_control_pro.py"__ in "simtech_robot_laser_control->script": contains modified pid algorithm with anti-windup



## Modified ROS program and nodes
1. moved 'calibraiton_c++', 'calibration_python', 'calibration_img' into folder: __camera_utils__
2. Changed the name of __'RT_monitoring_applications'__ into __'scanning_applications'__
3. Move "camera" from __LaserControl__ folder to __camera_utils__ folder
4. Move the __camera_measures__ folder outside the __"LaserControl"__
5. Rename __"LaserControl"__ to __"laserControl_CNC"__
6. Rename __"Monitoring"__ to __"laser_profiler_scanning"__


## Side notes
1. __nd_supervisor__: 
   - supervise laser power(on/off and value) and velocity (on/off and speed)
   - msg: MsgStatus
   - note that inside the program, we assume the laser power is always on (could be a small bug here)
2. __nd_velocity_supervisor__: 
   - only supervise velocity (on/off and speed)
   - msg: MsgVelocityStatus
  
3. __camera_measueres.launch__



## 2020 Sep 22
Changed the SERVER_motion.md, while loop wait time from 0.01 to 0.1s (0.1 is used in OpenLMD)