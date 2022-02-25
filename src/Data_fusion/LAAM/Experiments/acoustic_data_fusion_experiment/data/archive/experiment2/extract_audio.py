from ros import rosbag

def extract_audio(bag_path, topic_name, mp3_path):
    print ('Opening bag')
    bag = rosbag.Bag(bag_path)
    mp3_file = open(mp3_path, 'w')
    print ('Reading audio messages and saving to mp3 file')
    msg_count = 0
    for topic, msg, stamp in bag.read_messages(topics=[topic_name]):
        if msg._type == 'audio_common_msgs/AudioData':
            msg_count += 1
            mp3_file.write(''.join(msg.data))
    bag.close()
    mp3_file.close()
    print ('Done. %d audio messages written to %s'%(msg_count, mp3_path))

bag_path = '/home/chenlequn/SIMTech_ws/src/Data_fusion/LAAM/Experiments/acoustic_data_fusion_experiment/data/experiment2/recording2.bag'
topic_name = '/audio/audio'
mp3_path = '/home/chenlequn/SIMTech_ws/src/Data_fusion/LAAM/Experiments/acoustic_data_fusion_experiment/data/experiment2/recording_audio.mp3'

extract_audio(bag_path, topic_name, mp3_path)

