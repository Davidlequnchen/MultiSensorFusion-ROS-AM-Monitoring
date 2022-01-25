# SIMTech_ws

#### System requirement
- ROS Noetic
- Ubuntu 20.04
- Python3

#### Installation instructions
- Install `gstreamer-1.0`(Guide: https://gstreamer.freedesktop.org/documentation/installing/on-linux.html?gi-language=c)
```
sudo apt-get -y install libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-good
```

- build the whole pacakges
```
catkin_make
```