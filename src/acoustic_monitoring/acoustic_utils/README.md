

## Reference
### [ROS Audio Convert](https://github.com/sbrodeur/ros-audio-convert)
audio conversion based on the audio_common stack
- Convert a single bag file to wav
```
rosrun audio_convert bag2wav --input=audio.bag --output=audio.wav --input-audio-topic=/audio
```

### [ROS utils for audio streams](https://github.com/introlab/audio_utils)
- resampling ros bag audio signa
- other utility functionalities might be useful during development
