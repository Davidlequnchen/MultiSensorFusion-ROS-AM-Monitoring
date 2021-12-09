;; Auto-generated. Do not edit!


(when (boundp 'infratec_image_processing::TemperatureFeature)
  (if (not (find-package "INFRATEC_IMAGE_PROCESSING"))
    (make-package "INFRATEC_IMAGE_PROCESSING"))
  (shadow 'TemperatureFeature (find-package "INFRATEC_IMAGE_PROCESSING")))
(unless (find-package "INFRATEC_IMAGE_PROCESSING::TEMPERATUREFEATURE")
  (make-package "INFRATEC_IMAGE_PROCESSING::TEMPERATUREFEATURE"))

(in-package "ROS")
;;//! \htmlinclude TemperatureFeature.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass infratec_image_processing::TemperatureFeature
  :super ros::object
  :slots (_header _highest _lowest _variance _kurtosis _skewness ))

(defmethod infratec_image_processing::TemperatureFeature
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:highest __highest) 0.0)
    ((:lowest __lowest) 0.0)
    ((:variance __variance) 0.0)
    ((:kurtosis __kurtosis) 0.0)
    ((:skewness __skewness) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _highest (float __highest))
   (setq _lowest (float __lowest))
   (setq _variance (float __variance))
   (setq _kurtosis (float __kurtosis))
   (setq _skewness (float __skewness))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:highest
   (&optional __highest)
   (if __highest (setq _highest __highest)) _highest)
  (:lowest
   (&optional __lowest)
   (if __lowest (setq _lowest __lowest)) _lowest)
  (:variance
   (&optional __variance)
   (if __variance (setq _variance __variance)) _variance)
  (:kurtosis
   (&optional __kurtosis)
   (if __kurtosis (setq _kurtosis __kurtosis)) _kurtosis)
  (:skewness
   (&optional __skewness)
   (if __skewness (setq _skewness __skewness)) _skewness)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _highest
    4
    ;; float32 _lowest
    4
    ;; float32 _variance
    4
    ;; float32 _kurtosis
    4
    ;; float32 _skewness
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _highest
       (sys::poke _highest (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _lowest
       (sys::poke _lowest (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _variance
       (sys::poke _variance (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _kurtosis
       (sys::poke _kurtosis (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _skewness
       (sys::poke _skewness (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _highest
     (setq _highest (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _lowest
     (setq _lowest (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _variance
     (setq _variance (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _kurtosis
     (setq _kurtosis (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _skewness
     (setq _skewness (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get infratec_image_processing::TemperatureFeature :md5sum-) "76aadf0f49fea5fc61b3a9625bed0842")
(setf (get infratec_image_processing::TemperatureFeature :datatype-) "infratec_image_processing/TemperatureFeature")
(setf (get infratec_image_processing::TemperatureFeature :definition-)
      "Header header
float32 highest
float32 lowest
float32 variance # measure of the spread of a distribution
float32 kurtosis # measure of non-guassianity
float32 skewness
# skewness = 0 : normally distributed.
# skewness > 0 : more weight in the left tail of the distribution.
# skewness < 0 : more weight in the right tail of the distribution. 


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



(provide :infratec_image_processing/TemperatureFeature "76aadf0f49fea5fc61b3a9625bed0842")


