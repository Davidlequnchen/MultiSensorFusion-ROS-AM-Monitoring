;; Auto-generated. Do not edit!


(when (boundp 'audio_common_msgs::AudioInfo)
  (if (not (find-package "AUDIO_COMMON_MSGS"))
    (make-package "AUDIO_COMMON_MSGS"))
  (shadow 'AudioInfo (find-package "AUDIO_COMMON_MSGS")))
(unless (find-package "AUDIO_COMMON_MSGS::AUDIOINFO")
  (make-package "AUDIO_COMMON_MSGS::AUDIOINFO"))

(in-package "ROS")
;;//! \htmlinclude AudioInfo.msg.html


(defclass audio_common_msgs::AudioInfo
  :super ros::object
  :slots (_channels _sample_rate _sample_format _bitrate _coding_format ))

(defmethod audio_common_msgs::AudioInfo
  (:init
   (&key
    ((:channels __channels) 0)
    ((:sample_rate __sample_rate) 0)
    ((:sample_format __sample_format) "")
    ((:bitrate __bitrate) 0)
    ((:coding_format __coding_format) "")
    )
   (send-super :init)
   (setq _channels (round __channels))
   (setq _sample_rate (round __sample_rate))
   (setq _sample_format (string __sample_format))
   (setq _bitrate (round __bitrate))
   (setq _coding_format (string __coding_format))
   self)
  (:channels
   (&optional __channels)
   (if __channels (setq _channels __channels)) _channels)
  (:sample_rate
   (&optional __sample_rate)
   (if __sample_rate (setq _sample_rate __sample_rate)) _sample_rate)
  (:sample_format
   (&optional __sample_format)
   (if __sample_format (setq _sample_format __sample_format)) _sample_format)
  (:bitrate
   (&optional __bitrate)
   (if __bitrate (setq _bitrate __bitrate)) _bitrate)
  (:coding_format
   (&optional __coding_format)
   (if __coding_format (setq _coding_format __coding_format)) _coding_format)
  (:serialization-length
   ()
   (+
    ;; uint8 _channels
    1
    ;; uint32 _sample_rate
    4
    ;; string _sample_format
    4 (length _sample_format)
    ;; uint32 _bitrate
    4
    ;; string _coding_format
    4 (length _coding_format)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _channels
       (write-byte _channels s)
     ;; uint32 _sample_rate
       (write-long _sample_rate s)
     ;; string _sample_format
       (write-long (length _sample_format) s) (princ _sample_format s)
     ;; uint32 _bitrate
       (write-long _bitrate s)
     ;; string _coding_format
       (write-long (length _coding_format) s) (princ _coding_format s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _channels
     (setq _channels (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint32 _sample_rate
     (setq _sample_rate (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _sample_format
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _sample_format (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint32 _bitrate
     (setq _bitrate (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _coding_format
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _coding_format (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get audio_common_msgs::AudioInfo :md5sum-) "9413d9b7029680d3b1db6ed0ae535f88")
(setf (get audio_common_msgs::AudioInfo :datatype-) "audio_common_msgs/AudioInfo")
(setf (get audio_common_msgs::AudioInfo :definition-)
      "# This message contains the audio meta data

# Number of channels
uint8 channels
# Sampling rate [Hz]
uint32 sample_rate
# Audio format (e.g. S16LE)
string sample_format
# Amount of audio data per second [bits/s]
uint32 bitrate
# Audio coding format (e.g. WAVE, MP3)
string coding_format

")



(provide :audio_common_msgs/AudioInfo "9413d9b7029680d3b1db6ed0ae535f88")


