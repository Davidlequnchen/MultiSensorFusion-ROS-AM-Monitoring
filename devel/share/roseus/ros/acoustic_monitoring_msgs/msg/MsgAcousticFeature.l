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
  :slots (_header _rms_energy _amplitude_envelope _zero_crossing_rate _mel_spectrogram _mfccs _ber _spectral_centroids _spectral_rolloff _spectral_bandwidth _spectral_flatness _spectral_crest_factor _spectral_kurtosis _spectral_variance ))

(defmethod acoustic_monitoring_msgs::MsgAcousticFeature
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:rms_energy __rms_energy) 0.0)
    ((:amplitude_envelope __amplitude_envelope) 0.0)
    ((:zero_crossing_rate __zero_crossing_rate) 0.0)
    ((:mel_spectrogram __mel_spectrogram) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:mfccs __mfccs) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:ber __ber) 0.0)
    ((:spectral_centroids __spectral_centroids) 0.0)
    ((:spectral_rolloff __spectral_rolloff) 0.0)
    ((:spectral_bandwidth __spectral_bandwidth) 0.0)
    ((:spectral_flatness __spectral_flatness) 0.0)
    ((:spectral_crest_factor __spectral_crest_factor) 0.0)
    ((:spectral_kurtosis __spectral_kurtosis) 0.0)
    ((:spectral_variance __spectral_variance) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _rms_energy (float __rms_energy))
   (setq _amplitude_envelope (float __amplitude_envelope))
   (setq _zero_crossing_rate (float __zero_crossing_rate))
   (setq _mel_spectrogram __mel_spectrogram)
   (setq _mfccs __mfccs)
   (setq _ber (float __ber))
   (setq _spectral_centroids (float __spectral_centroids))
   (setq _spectral_rolloff (float __spectral_rolloff))
   (setq _spectral_bandwidth (float __spectral_bandwidth))
   (setq _spectral_flatness (float __spectral_flatness))
   (setq _spectral_crest_factor (float __spectral_crest_factor))
   (setq _spectral_kurtosis (float __spectral_kurtosis))
   (setq _spectral_variance (float __spectral_variance))
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
  (:mel_spectrogram
   (&optional __mel_spectrogram)
   (if __mel_spectrogram (setq _mel_spectrogram __mel_spectrogram)) _mel_spectrogram)
  (:mfccs
   (&optional __mfccs)
   (if __mfccs (setq _mfccs __mfccs)) _mfccs)
  (:ber
   (&optional __ber)
   (if __ber (setq _ber __ber)) _ber)
  (:spectral_centroids
   (&optional __spectral_centroids)
   (if __spectral_centroids (setq _spectral_centroids __spectral_centroids)) _spectral_centroids)
  (:spectral_rolloff
   (&optional __spectral_rolloff)
   (if __spectral_rolloff (setq _spectral_rolloff __spectral_rolloff)) _spectral_rolloff)
  (:spectral_bandwidth
   (&optional __spectral_bandwidth)
   (if __spectral_bandwidth (setq _spectral_bandwidth __spectral_bandwidth)) _spectral_bandwidth)
  (:spectral_flatness
   (&optional __spectral_flatness)
   (if __spectral_flatness (setq _spectral_flatness __spectral_flatness)) _spectral_flatness)
  (:spectral_crest_factor
   (&optional __spectral_crest_factor)
   (if __spectral_crest_factor (setq _spectral_crest_factor __spectral_crest_factor)) _spectral_crest_factor)
  (:spectral_kurtosis
   (&optional __spectral_kurtosis)
   (if __spectral_kurtosis (setq _spectral_kurtosis __spectral_kurtosis)) _spectral_kurtosis)
  (:spectral_variance
   (&optional __spectral_variance)
   (if __spectral_variance (setq _spectral_variance __spectral_variance)) _spectral_variance)
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
    ;; float32[] _mel_spectrogram
    (* 4    (length _mel_spectrogram)) 4
    ;; float32[] _mfccs
    (* 4    (length _mfccs)) 4
    ;; float32 _ber
    4
    ;; float32 _spectral_centroids
    4
    ;; float32 _spectral_rolloff
    4
    ;; float32 _spectral_bandwidth
    4
    ;; float32 _spectral_flatness
    4
    ;; float32 _spectral_crest_factor
    4
    ;; float32 _spectral_kurtosis
    4
    ;; float32 _spectral_variance
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
     ;; float32[] _mel_spectrogram
     (write-long (length _mel_spectrogram) s)
     (dotimes (i (length _mel_spectrogram))
       (sys::poke (elt _mel_spectrogram i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _mfccs
     (write-long (length _mfccs) s)
     (dotimes (i (length _mfccs))
       (sys::poke (elt _mfccs i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32 _ber
       (sys::poke _ber (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_centroids
       (sys::poke _spectral_centroids (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_rolloff
       (sys::poke _spectral_rolloff (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_bandwidth
       (sys::poke _spectral_bandwidth (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_flatness
       (sys::poke _spectral_flatness (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_crest_factor
       (sys::poke _spectral_crest_factor (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_kurtosis
       (sys::poke _spectral_kurtosis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _spectral_variance
       (sys::poke _spectral_variance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
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
   ;; float32[] _mel_spectrogram
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _mel_spectrogram (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _mel_spectrogram i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _mfccs
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _mfccs (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _mfccs i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32 _ber
     (setq _ber (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_centroids
     (setq _spectral_centroids (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_rolloff
     (setq _spectral_rolloff (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_bandwidth
     (setq _spectral_bandwidth (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_flatness
     (setq _spectral_flatness (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_crest_factor
     (setq _spectral_crest_factor (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_kurtosis
     (setq _spectral_kurtosis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _spectral_variance
     (setq _spectral_variance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get acoustic_monitoring_msgs::MsgAcousticFeature :md5sum-) "57131d07b28013debc0969e0928b0739")
(setf (get acoustic_monitoring_msgs::MsgAcousticFeature :datatype-) "acoustic_monitoring_msgs/MsgAcousticFeature")
(setf (get acoustic_monitoring_msgs::MsgAcousticFeature :definition-)
      "Header header
# time-domain features
float32 rms_energy
float32 amplitude_envelope
float32 zero_crossing_rate
# freqeuncy domain features
float32[] mel_spectrogram
float32[] mfccs
float32 ber
float32 spectral_centroids
float32 spectral_rolloff
float32 spectral_bandwidth
float32 spectral_flatness
float32 spectral_crest_factor
float32 spectral_kurtosis
float32 spectral_variance


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



(provide :acoustic_monitoring_msgs/MsgAcousticFeature "57131d07b28013debc0969e0928b0739")


