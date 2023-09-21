# MFDT Workspace: 
ROS-based Multisensor fusion digital twin (MFDT) platform for real-time monitoring and defect detection of laser-directed energy deposition (L-DED) Additive Manufacturing (AM) process.


## Installation
- install ROS-noetic on Ubuntu 20.04: http://wiki.ros.org/noetic/Installation/Ubuntu

- install developer essentials:
  ```
  sudo apt-get install build-essential g++ python3-dev autotools-dev libicu-dev libbz2-dev libboost-all-dev intltool libglib2.0-dev
  ```
<!-- - install glibc:
  ```
  sudo apt install glibc-source -y
  ``` -->
- install gstreamer-1.0
  ```
  sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
  ```
- install ROS industrial and packages
  ```
  sudo apt-get install ros-noetic-roscpp, ros-noetic-std-msgs
  sudo apt-get install ros-noetic-industrial-core
  sudo apt-get install ros-noetic-moveit-visual-tools
  ```
- Install ROS controller
  ```
  sudo apt-get install ros-noetic-ros-control ros-noetic-ros-controllers
  ```
- install vtk
  ```
  sudo apt install python3-pip
  python -m pip install vtk
  ```

- install plotjuggler
  ```
  sudo apt install ros-noetic-plotjuggler-ros
  ```

- install Python Packages: 
  ```
  pip install -r requirements.txt
  ```


- For Pylon camera ROS packages (Basler USB Camera Driver): https://github.com/basler/pylon-ros-camera
  - Installation: Clone the official repository workspace (right now it is already inside the __camera_utils__ folder): `git clone https://github.com/basler/pylon-ros-camera`
   * Clone drag&bot public common messages: `git clone https://github.com/dragandbot/dragandbot_common.git`
   * Install ROS dependencies: `sudo sh -c 'echo "yaml https://raw.githubusercontent.com/basler/pylon-ros-camera/master/pylon_camera/rosdep/pylon_sdk.yaml" > /etc/ros/rosdep/sources.list.d/30-pylon_camera.list' && sudo rosdep update && sudo rosdep install --from-paths . --ignore-src --rosdistro=$ROS_DISTRO -y`

- install Micro-Epsilon scanControl SDK:
[./src/microEpsilon_scanControl/microepsilon_scancontrol/scanCONTROLLinuxSDK0.2.3] 
- install aravis: download the aravis-0.6.1.tar.xz package
(version 0.7 is not stable, do not download) http://ftp.acc.umu.se/pub/GNOME/sources/aravis/0.6/
  ````
  ./configure
  sudo make
  sudo make install
  sudo ldconfig
  ````
  If encounter problem like: "Error Message: checking for GTK... configure: error: Package requirements (gtk+-2.0 ¿= 2.10.0)
were not met: No package ’gtk+-2.0’ found":
  ````bash
  sudo apt-get update && upgrade
  sudo apt-get install intltool
  sudo apt-get install libgtk2.0-dev
  ````


- install essential (C++ compile from souce): https://essentia.upf.edu/installing.html
  - download Essentia 2.1 beta5: https://github.com/MTG/essentia/releases/tag/v2.1_beta5
  - Complie follow the instruction
<!-- - install BOOST library (download at: https://www.boost.org/users/download/)
```
sudo ./bootstrap.sh
sudo ./b2
``` -->




:exclamation: Important instructions;
:question: Remain unsolved issues, will be developed in the future;
:red_circle: code finished but have not been tested;
:x: code under heavy development;
:negative_squared_cross_mark: dead end and archived;
:heavy_check_mark: Tested sucessfully;

## Eperiment instructions
### Hardware configuration (multisensor)
<!-- #### Ethernet connections (pictures) -->

#### Connections (Ubuntu Linux settings)

- Xiris 1800V thermal camera (melt pool monitoring): Ethernet Connection port
  - (suggested configuration on monitoring PC - )
- Xiris WeldMIC acoustic monitoring: USB port
- KUKA RSI interface: Ethernet Connection port. 
  - suggested configuration on monitoring PC - __IP: 192.168.1.3__
- Coaxial CCD melt pool camera: USB port
- Infratec thermal camera: PCI Ethernet port. 
  - suggested configuration on monitoring PC - __IP: 169.254.87.1__ 
- ABB: Ethernet port. 
  - suggested configuration on monitoring PC - __IP: 192.168.125.3__ 


### 1. Multimodal monitoring 
#### 1.1 Software instruction 
- launch the monitoring (without experiments) :heavy_check_mark:
  ```
  roslaunch multimodal_monitoring multimodal_monitoring.launch
  ```

- launch the monitoring for experiments (with rosbag recording) :heavy_check_mark:
  
  ```
  roslaunch multimodal_monitoring multimodal_monitoring_experiments.launch
  ```
#### 1.2 configurations
- to launch the thermal monitoring, set parameter `<arg name="thermal" default="true"/>`
-  to launch the acoustic monitoring, set parameter `<arg name="acoustic" default="true"/>`
-  Change the path of recorded audio signal (wav): ` <arg name="dst" default="~/SIMTech_ws/src/acoustic_monitoring/data/KUKA_printing_SS_recording_6.wav"/>`
-  __Record__ the data into ___rosbag___: (change path if necessary). This is located in the ___multimodal_monitoring_experiments.launch___ file
    ```
    <node pkg="rosbag" type="record" name="rosbag_record_multimodal monitoring_experiment" 
    args="-O ~/SIMTech_ws/src/acoustic_monitoring/data/KUKA_printing_SS_recording_6.bag 
    /audio /audioStamped /acoustic_feature " />
    ```
#### 1.3 Important instructions for conducting experiments
- Before experiments, the thermal camera's focus needs to be fine-tuned. Make sure it is focused to the laser spot.
- After calibrating the focus, the temperature range of the camera needs to be configured to the correct range. (500-2000 degrees) -- __only for Infratec VarioCAM camera, Xiris no need__
- :exclamation: Conduct a dry run to test the microphone sensor. Make sure it is capturing the acoustic signal rather than using the PC built-in microphone. 
- For KUKA program, need to add RSI communications in the code


- ping kuka LDED robot RSI interface:
  ```
  ping 192.168.1.3
  ```

- ping MicroEpsilon ScanController
  ```
  ping 169.254.87.67
  ```
- ping ABB driver
  ```
  ping 192.168.125.1
  ```

#### 1.4 Data recordings
- General format (without robot)
  ```
  rosbag record -O /media/chenlequn/Lequn_HD/Research_Projects/multimodal_monitoring/data/experiment.bag /audio /audioStamped /acoustic_feature /infratec/image_raw /infratec/image_converted_mono8 /infratec/temperature_feature /general_contours/max_contour_area /convex_hull/hull_area
  ```
- record all the informtion
  ```
  rosbag record -O /media/chenlequn/Lequn_HD/Research_Projects/multimodal_monitoring/data/experiment.bag /audio /audioStamped /acoustic_feature /infratec/image_raw /infratec/image_converted_mono8 /infratec/temperature_feature /general_contours/max_contour_area /convex_hull/hull_area /cartesian_position /cartesian_velocity
  ```
- List out the topic to select: `rostopic list` 
  ```
  /acoustic_feature
  /audio
  /audioStamped
  /audio_info
  /camera/cloud
  /cartesian_position
  /cartesian_velocity
  /convex_hull/hull_area
  /convex_hull/hulls
  ...
  /general_contours/contour_area
  /general_contours/ellipses
  /general_contours/image
  ...
  /general_contours/rectangles
  ...
  /infratec/image_converted_mono8
  /infratec/image_raw
  /infratec/temperature_feature
  /joint_states
  /position_trajectory_controller/command
  /position_trajectory_controller/follow_joint_trajectory/cancel
  /position_trajectory_controller/follow_joint_trajectory/feedback
  /position_trajectory_controller/follow_joint_trajectory/goal
  /position_trajectory_controller/follow_joint_trajectory/result
  /position_trajectory_controller/follow_joint_trajectory/status
  /position_trajectory_controller/state
  ```
- Change the name of the bag file and its locations :exclamation:



## 2. Single modal monitoring 

### 2.1. Acoustic monitoring
### 2.1.1 parameters and setup
- device: `arecord -l` will show available input devices, use the car number as
  the first number and the subdevice number as the second in a string
  like hw:1,0
  ```
  <arg name="device" default="hw:2,0" />
  ```
- sampling rate: 
  ```
  <arg name="sample_rate" default="44100"/>
  ```

### 2.1.2 launch instructions
- standalone acoustic monitoring: :heavy_check_mark:
  ```
  roslaunch acoustic_feature_extraction acoustic_monitoring.launch
  ```
-  acoustic monitoring with rosbag recording: :heavy_check_mark:
  ```
  roslaunch acoustic_feature_extraction acoustic_monitoring_experiment.launch
  ```


### 2.2. Thermal monitoring (Infratec VarioCAM)
#### 2.2.1 configuration and specifications
- set parameters for the thermal images (__max, min temp, croppings__): `~/SIMTech_ws/src/Infratec_thermal_camera/thermal_monitoring/config/thermal_camera_parameter.yaml` :exclamation::exclamation::exclamation:
Note that chaneg the parameter in this yaml file will __overwrite__ the default settings. Hence, this is the only file you need to modify during the experiments.
- remember to set python with network access: :heavy_check_mark:
  ```
  setcap cap_net_raw+eip /usr/bin/python3.6
  ```

#### 2.2.2 launch instructions
- launch the basic thermal camera driver GUI(for testing the Infratec camera)  :heavy_check_mark:
  ```
  roslaunch infratec_ros_driver infratec_vario_ros_driver_basic.launch
  ```

- launch the basic thermal camera driver GUI with thermal image conversions (to mono format) :heavy_check_mark:
  ```
  roslaunch infratec_ros_driver infratec_driver_image_convert.launch
  ```

- [__thermal camera monitoring basic__]: launch the thermal camera and connet to KUKA robot (set robot_launch to true) :ok_hand:
  ```
  roslaunch thermal_monitoring thermal_monitoring_basic.launch
  ```
- [__thermal camera monitoring__]: camera + robot + in-situ image processing  :heavy_check_mark:
    - open the launch file and set corresponding nodes to __false__ if you don't want to launch it.
  ```
  roslaunch thermal_monitoring thermal_monitoring.launch
  ```

- [__thermal camera monitoring with multimodal GUI__]: camera + robot + in-situ image processing  :x:
   - under heavy development
  ```
  roslaunch infratec_ros_driver qt_infratec_insitu_monitoring.launch
  ```

### 2.3. Laser line scanning (MicroEpsilon)
#### 2.3.1 configuration and specifications
```
ping 192.168.1.3 ## KUKA RSI
ping 169.254.87.67 ## MicroEpsilon
```
#### 2.3.2 Launch instructions
```
cd ~/SIMTech_ws/src/scanning_application/scanning_robviz/launch
roslaunch scanning_robviz robviz_abb_microepsilon.launch ## for ABB hybrid laser-arc
roslaunch scanning_robviz robviz_kuka_microepsilon.launch ## for KUKA system
```


## 3. Post-experiment offline data processing
- navigate to `experiment_data` folder
- execute feature extraction for thermal monitoring modal:
  ```
  roslaunch experiment_data feature_extraction.launch
  ```