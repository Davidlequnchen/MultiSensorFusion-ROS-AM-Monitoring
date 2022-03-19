# SIMTech_ws



<!-- emojy can be used: 
:heavy_multiplication_x:
:exclamation:
:question:
:negative_squared_cross_mark:
:heavy_check_mark:
:x: 
:red_circle: -->

:exclamation: Important instructions;
:question: Remain unsolved issues, will be developed in the future;
:red_circle: code finished but have not been tested;
:x: code under heavy development;
:negative_squared_cross_mark: dead end and archived;
:heavy_check_mark: Tested sucessfully;

## Eperiment instructions
### Hardware configuration
#### Ethernet connections (pictures)
<!-- ![](./src/doc/Adaptive_PID_VRFT.png?raw=true) -->
#### Ethernet connections (Ubuntu Linux settings)

- PCI Ethernet port (normal ethernet): Infratec thermal camera
- Ethernet Connection port (USB-C): RSI (KUKA)
<!-- ![](./src/doc/Adaptive_PID_VRFT.png?raw=true) -->



### 1. Multimodal monitoring 
#### 1.1 software instruction 
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
#### 1.3 Important instructions for conducting the experiment
- Before experiments, the thermal camera's focus needs to be fine-tuned. Make sure it is focused to the laser spot.
- After calibrating the focus, the temperature range of the camera needs to be configured to the correct range. (500-2000 degrees)
- Do a dry run to test the microphone sensor. Make sure it is capturing the acoustic signal rather than using the PC built-in microphone. :exclamation:
- For KUKA program, need to add RSI communications in the code:
```

```
- ping kuka:
```
ping 192.168.1.3
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
### 2.1. Thermal monitoring
#### 2.1.1 configuration and specifications
- set parameters for the thermal images (__max, min temp, croppings__): `~/SIMTech_ws/src/Infratec_thermal_camera/thermal_monitoring/config/thermal_camera_parameter.yaml` :exclamation::exclamation::exclamation:
Note that chaneg the parameter in this yaml file will __overwrite__ the default settings. Hence, this is the only file you need to modify during the experiments.
- remember to set python with network access: :heavy_check_mark:
```
setcap cap_net_raw+eip /usr/bin/python3.6
```

#### 2.1.2 launch instructions
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


## 3. Post-experiment offline data processing
- navigate to `experiment_data` folder
- execute feature extraction for thermal monitoring modal:
```
roslaunch experiment_data feature_extraction.launch
```