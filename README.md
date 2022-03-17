# SIMTech_ws



<!-- emojy can be used: 
:heavy_multiplication_x:
:exclamation:
:question:
:negative_squared_cross_mark:
:heavy_check_mark:
:x: 
:red_circle: -->


## Eperiment instructions
### 1. Multimodal monitoring 
#### 1.1 software instruction 
- launch the monitoring (without experiments) 
```
roslaunch multimodal_monitoring multimodal_monitoring.launch
```

- launch the monitoring for experiments
  
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
#### Important instructions for conducting the experiment
- Before experiments, the thermal camera's focus needs to be fine-tuned. Make sure it is focused to the laser spot.
- After calibrating the focus, the temperature range of the camera needs to be configured to the correct range. (500-2000 degrees)
- Do a dry run to test the microphone sensor. Make sure it is capturing the acoustic signal rather than using the PC built-in microphone. :exclamation:




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

### 2.1.2 launch instructions




## 3. Post-experiment offline data processing
- navigate to `experiment_data` folder
- execute feature extraction for thermal monitoring modal:
```
roslaunch experiment_data feature_extraction,launch
```