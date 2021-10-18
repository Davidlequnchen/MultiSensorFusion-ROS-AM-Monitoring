;; Auto-generated. Do not edit!


(when (boundp 'acoustic_monitoring_msgs::MsgAcousticFeature)
  (if (not (find-package "ACOUSTIC_MONITORING_MSGS"))
    (make-package "ACOUSTIC_MONITORING_MSGS"))
  (shadow 'MsgAcousticFeature (find-package "ACOUSTIC_MONITORING_MSGS")))
(unless (find-package "ACOUSTIC_MONITORING_MSGS::MSGACOUSTICFEATURE")
  (make-package "ACOUSTIC_MONITORING_MSGS::MSGACOUSTICFEATURE"))

(in-package "ROS")
;;//! \htmlinclude MsgAcousticFeature.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass acoustic_monitoring_msgs::MsgAcousticFeature
  :super ros::object
  :slots (_header _rms_energy _amplitude_envelope _zero_crossing_rate _mfccs_mean _mfccs_variance _spectral_centroids _spectral_rolloff ))

(defmethod acoustic_monitoring_msgs::MsgAcousticFeature
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:rms_energy __rms_energy) 0.0)
    ((:amplitude_envelope __amplitude_envelope) 0.0)
    ((:zero_crossing_rate __zero_crossing_rate) 0.0)
    ((:mfccs_mean __mfccs_mean) 0.0)
    ((:mfccs_variance __mfccs_variance) 0.0)
    ((:spectral_centroids __spectral_centroids) 0.0)
    ((:spectral_rolloff __spectral_rolloff) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _rms_energy (float __rms_energy))
   (setq _amplitude_envelope (float __amplitude_envelope))
   (setq _zero_crossing_rate (float __zero_crossing_rate))
   (setq _mfccs_mean (float __mfccs_mean))
   (setq _mfccs_variance (float __mfccs_variance))
   (setq _spectral_centroids (float __spectral_centroids))
   (setq _spectral_rolloff (float __spectral_rolloff))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:rms_energy
   (&optional __rms_energy)
   (if __rms_energy (setq _rms_energy __rms_energy)) _rms_energy)
  (:amplitude_envelope
   (&optional __amplitude_envelope)
   (if __amplitude_envelope (setq _amplitude_envelope __amplitude_envelope)) _amplitude_envelope)
  (:zero_crossing_rate
   (&optional __zero_crossing_rate)
   (if __zero_crossing_rate (setq _zero_crossing_rate __zero_crossing_rate)) _zero_crossing_rate)
  (:mfccs_mean
   (&optional __mfccs_mean)
   (if __mfccs_mean (setq _mfccs_mean __mfccs_mean)) _mfccs_mean)
  (:mfccs_variance
   (&optional __mfccs_variance)
   (if __mfccs_variance (setq _mfccs_variance __mfccs_variance)) _mfccs_variance)
  (:spectral_centroids
   (&optional __spectral_centroids)
   (if __spectral_centroids (setq _spectral_centroids __spectral_centroids)) _spectral_centroids)
  (:spectral_rolloff
   (&optional __spectral_rolloff)
   (if __spectral_rolloff (setq _spectral_rolloff __spectral_rolloff)) _spectral_rolloff)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _rms_energy
    4
    ;; float32 _amplitude_envelope
    4
    ;; float32 _zero_crossing_rate
    4
    ;; float32 _mfccs_mean
    4
    ;; float32 _mfccs_variance
    4
    ;; float32 _spectral_centroids
    4
    ;; float32 _spectral_rolloff
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _rms_energy
       (sys::poke _rms_energy (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _amplitude_envelope
       (sys::poke _amplitude_envelope (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _zero_crossing_rate
       (sys::poke _zero_crossing_rate (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _mfccs_mean
       (sys::poke _mfccs_mean (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _mfccs_variance
       (sys::poke _mfccs_variance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_centroids
       (sys::poke _spectral_centroids (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_rolloff
       (sys::poke _spectral_rolloff (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _rms_energy
     (setq _rms_energy (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _amplitude_envelope
     (setq _amplitude_envelope (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _zero_crossing_rate
     (setq _zero_crossing_rate (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _mfccs_mean
     (setq _mfccs_mean (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _mfccs_variance
     (setq _mfccs_variance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_centroids
     (setq _spectral_centroids (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_rolloff
     (setq _spectral_rolloff (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get acoustic_monitoring_msgs::MsgAcousticFeature :md5sum-) "c14a16b80445b9cad4c6f29ce8f94aa6")
(setf (get acoustic_monitoring_msgs::MsgAcousticFeature :datatype-) "acoustic_monitoring_msgs/MsgAcousticFeature")
(setf (get acoustic_monitoring_msgs::MsgAcousticFeature :definition-)
      "Header header
# time-domain features
float32 rms_energy
float32 amplitude_envelope
float32 zero_crossing_rate
# frequency-domain features
# float32 mfccs
float32 mfccs_mean
float32 mfccs_variance
float32 spectral_centroids
float32 spectral_rolloff


# spectral_centroid computes the \"average\" frequency at each frame, where frequencies are weighted relatively by their energy.
# spectral_bandwidth similar to centroid, but for variance (or other moments).
# spectral_rolloff essentially the maximum: finds the frequency f such that almost all of the energy (by default, 85%)


================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :acoustic_monitoring_msgs/MsgAcousticFeature "c14a16b80445b9cad4c6f29ce8f94aa6")


