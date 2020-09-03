# AutoDED: Automatic surface scanning and process control for DED

<!-- <span style="background-color: #FFFF00">Marked text</span>
<code> <i>This text will be italic</i> <b>this text will be bold</b> </code> -->


This ROS project combines <code>"microEpsilon_scanControl"</code> and <code>"simtech_robot_laser_control"</code>, makes the DED proces monitoring and control fully automated without the need of human intervention. 

## Key Features

### 1. Robot Controller RAPID programs (Server)

#### 1.1 __TRobt1 (Main task)__    

Example:  <code> a20x40_wo_profile.mod</code>
  - Global variable (Persistant variable in COMMON.sys): <span style="background-color: #FFFF00">routine_command</span> -- 0: idle mode, 1: scanning, 2: control
  - __mode 0__: (idle mode) the process is not doing scanning task or process control. (When we do not want to control, or when robot is on the way going to the scanning position) 
  - __mode 1__: (Surface scanning) Interrupt routines occurs inside the robot path. E.g., the robot stops moving and laser off after finishing xx layers of printing, an interrupt invokes and robot goes to the trapped routine to execute the tool path for surface scanning to check surface defects -- __microEpsilon_scanControl__ will be enabled to do the scanning job.
  - __mode 2__: (Process control) Contains robot __moveL__ and laser on/off command.(Normal printing routine), while the __simtech_robot_laser_control__ nodes are enabled to do the adaptive contol functionalities.
  - The global variable ***routine_command** is set accordingly when interrupt occurs.
  
#### 1.2  __Socket_routine.mod__ (semi-staitc)
   - a tcp socket server communicate with the ROS
   - It keeps publishing the global variable <code>routine_command</code> to tell ros which mode (0/1/2) the process is currently doing.
   - Runs continously without intermittence



#### 1.3  __Laser control__ (semi-static)
  - tcp socket listening to the laser voltage signal send from　PC ROS program
  - Runs continously without intermittence

#### 1.4 __state refresher__(semi-static)
  - Tcp socket send the robot state to ROS.
  - Runs continiously without intermittence
  
### 2. PC ROS programs 

#### 2.1 __Main program__ 
- a tcp socket client communicating with __Socket_routine__ server in ABB robot controller.
- Read data of which task (0 or 1 or 2 the program currently handles, then it will enable/disable the corresponding ROS service.
- __mode 0__ Idle mode, __mode 1__ -- Laser control, __mode 2__-- surface scanning
- Use ROS service On/off switch to switch between the modes
#### 2.2 __microEpsilon_scanControl__

- Add a separate C++ ROS node program ___microepsilon_scancontrol_node_AutoDED.cpp___ in the <code>microepsilon_scancontrol</code> folder 

#### 2.3 __simtech_robot_laser_control__