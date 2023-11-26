# MFDT Workspace: 
ROS-based Multisensor fusion digital twin (MFDT) platform for location-dependant real-time monitoring and defect detection of laser-directed energy deposition (L-DED) Additive Manufacturing (AM) process.


## 1. Installation
### 1.1. Install ROS-noetic and dependencies
- install ROS-noetic on Ubuntu 20.04: http://wiki.ros.org/noetic/Installation/Ubuntu

- install developer essentials:
  ```
  sudo apt-get install build-essential g++ python3-dev autotools-dev libicu-dev libbz2-dev libboost-all-dev intltool libglib2.0-dev
  ```
- install OpenCV
  ```
  sudo apt install libopencv-dev python3-opencv
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

### 1.2. Install Pylon Camera-related packages
- For Pylon camera ROS packages (Basler USB Camera Driver): https://github.com/basler/pylon-ros-camera
  - Installation: Clone the official repository workspace (right now it is already inside the __camera_utils__ folder): `git clone https://github.com/basler/pylon-ros-camera`
   * Clone drag&bot public common messages: `git clone https://github.com/dragandbot/dragandbot_common.git`
   * Install ROS dependencies (In the downloaded folder): `sudo sh -c 'echo "yaml https://raw.githubusercontent.com/basler/pylon-ros-camera/master/pylon_camera/rosdep/pylon_sdk.yaml" > /etc/ros/rosdep/sources.list.d/30-pylon_camera.list' && sudo rosdep update && sudo rosdep install --from-paths . --ignore-src --rosdistro=$ROS_DISTRO -y`


### 1.3. Install MicroEpsilon scanControl Packages
- Download and install Micro-Epsilon scanControl SDK:
[./src/microEpsilon_scanControl/microepsilon_scancontrol/scanCONTROLLinuxSDK0.2.3] 
- Install prerequisite aravis: download the __aravis-0.6.1.tar.xz__ package
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


### 1.4. Install Audio signal processing packages
- install essential (C++ compile from souce): https://essentia.upf.edu/installing.html
  <!-- - download Essentia 2.1 beta5: https://github.com/MTG/essentia/releases/tag/v2.1_beta5 -->
  - Download the master branch (download it via Github Desktop): https://github.com/MTG/essentia
  - Complie follow the instruction:
  ```
  pip install essentia
  ```
  Install depandencies
  ```
  sudo apt-get install build-essential libeigen3-dev libyaml-dev libfftw3-dev libavcodec-dev libavformat-dev libavutil-dev libswresample-dev libsamplerate0-dev libtag1-dev libchromaprint-dev
  ```
  ```
  sudo apt-get install python3-dev python3-numpy-dev python3-numpy python3-yaml python3-six
  ```
  Compile
  ```
  python3 waf configure --build-static --with-python --with-cpptests --with-examples --with-vamp
  ```
  ```
  python3 waf
  ```
  To install the C++ library, Python bindings, extractors and Vamp plugin 
  ```
  sudo python3 waf install
  ```

### 1.5. Install other packages and complie the entire workspace
- Install LightGBM (ML model): https://lightgbm.readthedocs.io/en/stable/Installation-Guide.html#linux

- install Required Python Packages: 
  ```
  pip install -r requirements.txt
  ```

- Go to the ROS workspace, then complile:
  ```
  catkin_make
  ```

- Remember to source the package:
go to the folder under home directory:
  ```
  cd
  gedit .bashrc
  ```
  Then add the following line into the .bashrc file
  ```
  source ~/SIMTech_ws/devel/setup.bash
  source .bashrc
  ```

<!-- - install BOOST library (download at: https://www.boost.org/users/download/)
```
sudo ./bootstrap.sh
sudo ./b2
``` -->


<!-- :exclamation: Important instructions;
:question: Remain unsolved issues, will be developed in the future;
:red_circle: code finished but have not been tested;
:x: code under heavy development;
:negative_squared_cross_mark: dead end and archived;
:heavy_check_mark: Tested sucessfully; -->

## 2. Configurations and Settings
### 2.1. Hardware configuration
<!-- #### Ethernet connections (pictures) -->
#### 2.1.1. Connections (Ubuntu Linux settings)
- Xiris 1800V thermal camera (melt pool monitoring): Ethernet Connection port
  - (suggested configuration on monitoring PC - )
- Xiris WeldMIC acoustic monitoring: USB port 
  - Use the command `arecord -l` to check the microphone device number (card, subdevice index)
- KUKA RSI interface: Ethernet Connection port. 
  - suggested configuration on monitoring PC - __IP: 192.168.1.3__
  - suggested configuration on the KUKA controller (add additional RSI network): __IP: 192.168.1.20__
  - try to ping the robot from the PC using:
    ```
    ping 192.168.1.20
    ```
  - Network setting for KUKA windows (for communication with workvisual): __192.168.250.20__, PC side: __IP: 192.168.250.1__
  - Try to ping the KUKA robot from the workvisual PC:
    ```
    ping 192.168.1.20
    ```
- ABB (require multi-tasking & PC interface): Ethernet port. 
  - suggested configuration on monitoring PC - __IP: 192.168.125.3__ 
- Coaxial CCD melt pool camera: USB port
  - use the command `ls ~/dev/video*` to check the USB camera index
- Infratec Vario thermal camera (NTU): PCI Ethernet port. 
  - suggested ethernet configuration on monitoring PC - __IP: 169.254.87.1__ 

#### 2.1.2. Sensor Configurations:
- For microphone sensor:
  - __Xiris WeldMIC__:
    - Sampling rate: 44100
    - Channel Number: 1
    - Sample format: "S16LE"
    - Bit Depth: 16
  - __miniDSP__:
    - Sampling rate: 48000 (must be)
    - Channel Number: 2
    - Sample format: "S24LE"
    - Bit Depth: 24
  - device: `arecord -l` will show available input devices, use the car number as
  the first number and the subdevice number as the second in a string
  like `hw:1,0``
    ```
    <arg name="device" default="hw:2,0" />
    ```


- MicroEpsilon Laser Line Scaner:
  - check "path_to_device_properties" variable in the folder `src/microEpsilon_scanControl/microepsilon_scancontrol/launch/scanner_driver.launch`
  - check the serial number
  - change __SCANNER_RESOLUTION__ in the `microepsilon_scancontrol.h` (640 for 2900-50 scanner (SIMTech side), 2048 for 3010)

- For Coaxial Camera:
  - pixel_format: either yuyv or mjpeg (depands on the connector)

### 2.2. Experiments Instructions
#### 2.2.1 Software instruction 
- launch the entire program with Qt GUI :heavy_check_mark:
   ```
   cd ~/SIMTech_ws/src/multisense_gui/launch 
   roslaunch qt_multisense_gui.launch
   ```
- launch the monitoring program (without experiments) :heavy_check_mark:
  ```
  roslaunch multimodal_monitoring multimodal_monitoring.launch
  ```

- launch the monitoring for experiments (with rosbag recording) :heavy_check_mark:
  ```
  roslaunch multimodal_monitoring multimodal_monitoring_experiments.launch
  ```

#### 2.2.2 Launch file configurations
- The configurations can be set in the launch file
- To launch the acoustic monitoring, set parameter `<arg name="acoustic" default="true"/>`, Similarly, for Coaxial Monitoring, KUKA, ABB robot, etc.
- For recording data, remember to change the path of recorded audio signal (wav): ` <arg name="dst" default="~/SIMTech_ws/src/acoustic_monitoring/data/KUKA_printing_SS_recording_6.wav"/>`
-  __Record__ the data into ___rosbag___: (change path if necessary). This is located in the `multimodal_monitoring_experiments.launch` file
    ```
    <node pkg="rosbag" type="record" name="rosbag_record" 
    args="-O **location-to-the-folder*_recorded_name.bag 
    /audio /audioStamped /acoustic_feature" />
    ```
#### 2.2.3 Important instructions for conducting experiments
- Before experiments, the thermal camera's focus needs to be fine-tuned. Make sure it is focused to the laser spot.
- After calibrating the focus, the temperature range of the camera needs to be configured to the correct range. (500-2000 degrees) -- __(only for Infratec VarioCAM camera, Xiris no need)__
- :exclamation: Conduct a dry run to test the microphone sensor. Make sure it is capturing the acoustic signal rather than using the PC built-in microphone. 

- ping kuka LDED robot RSI interface:
  ```
  ping 192.168.1.20
  ```

- ping MicroEpsilon ScanController
  ```
  ping 169.254.87.67
  ```
- ping ABB driver
  ```
  ping 192.168.125.1
  ```

#### 2.2.4 Data recordings
- General format (without robot)
  ```
  rosbag record -O /media/chenlequn/Lequn_HD/Research_Projects/multimodal_monitoring/data/experiment.bag /audio /audioStamped /acoustic_feature /infratec/image_raw /infratec/image_converted_mono8 /infratec/temperature_feature /general_contours/max_contour_area /convex_hull/hull_area
  ```
- record all the informtion
  ```
  rosbag record -O /media/chenlequn/Lequn_HD/Research_Projects/multimodal_monitoring/data/experiment.bag /audio /audioStamped /acoustic_feature /infratec/image_raw /infratec/image_converted_mono8 /infratec/temperature_feature /general_contours/max_contour_area /convex_hull/hull_area /cartesian_position /cartesian_velocity
  ```
- List out the topic to select: `rostopic list` 
- Change the name of the bag file and its locations :exclamation:


## 3. Single modal monitoring 


### 3.1. Thermal monitoring (Infratec VarioCAM)
#### 3.1.1 configuration and specifications
- set parameters for the thermal images (__max, min temp, croppings__): `~/SIMTech_ws/src/Infratec_thermal_camera/thermal_monitoring/config/thermal_camera_parameter.yaml` :exclamation::exclamation::exclamation:
Note that chaneg the parameter in this yaml file will __overwrite__ the default settings. Hence, this is the only file you need to modify during the experiments.
- remember to set python with network access: :heavy_check_mark:
  ```
  setcap cap_net_raw+eip /usr/bin/python3.6
  ```

#### 3.1.2 launch instructions
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

### 3.2. Laser line scanning (MicroEpsilon)
#### 3.2.1 configuration and specifications
```
ping 192.168.1.20 ## KUKA RSI
ping 169.254.87.67 ## MicroEpsilon
```
#### 3.2.2 Launch instructions
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