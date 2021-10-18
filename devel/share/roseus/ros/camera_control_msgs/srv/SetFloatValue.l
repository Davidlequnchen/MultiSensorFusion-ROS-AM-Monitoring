;; Auto-generated. Do not edit!


(when (boundp 'camera_control_msgs::SetFloatValue)
  (if (not (find-package "CAMERA_CONTROL_MSGS"))
    (make-package "CAMERA_CONTROL_MSGS"))
  (shadow 'SetFloatValue (find-package "CAMERA_CONTROL_MSGS")))
(unless (find-package "CAMERA_CONTROL_MSGS::SETFLOATVALUE")
  (make-package "CAMERA_CONTROL_MSGS::SETFLOATVALUE"))
(unless (find-package "CAMERA_CONTROL_MSGS::SETFLOATVALUEREQUEST")
  (make-package "CAMERA_CONTROL_MSGS::SETFLOATVALUEREQUEST"))
(unless (find-package "CAMERA_CONTROL_MSGS::SETFLOATVALUERESPONSE")
  (make-package "CAMERA_CONTROL_MSGS::SETFLOATVALUERESPONSE"))

(in-package "ROS")





(defclass camera_control_msgs::SetFloatValueRequest
  :super ros::object
  :slots (_value ))

(defmethod camera_control_msgs::SetFloatValueRequest
  (:init
   (&key
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _value (float __value))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; float32 _value
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _value
       (sys::poke _value (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _value
     (setq _value (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass camera_control_msgs::SetFloatValueResponse
  :super ros::object
  :slots (_success _message ))

(defmethod camera_control_msgs::SetFloatValueResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _message (string __message))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass camera_control_msgs::SetFloatValue
  :super ros::object
  :slots ())

(setf (get camera_control_msgs::SetFloatValue :md5sum-) "345a3274594e7cc629d8cd38d3b1fe73")
(setf (get camera_control_msgs::SetFloatValue :datatype-) "camera_control_msgs/SetFloatValue")
(setf (get camera_control_msgs::SetFloatValue :request) camera_control_msgs::SetFloatValueRequest)
(setf (get camera_control_msgs::SetFloatValue :response) camera_control_msgs::SetFloatValueResponse)

(defmethod camera_control_msgs::SetFloatValueRequest
  (:response () (instance camera_control_msgs::SetFloatValueResponse :init)))

(setf (get camera_control_msgs::SetFloatValueRequest :md5sum-) "345a3274594e7cc629d8cd38d3b1fe73")
(setf (get camera_control_msgs::SetFloatValueRequest :datatype-) "camera_control_msgs/SetFloatValueRequest")
(setf (get camera_control_msgs::SetFloatValueRequest :definition-)
      "# Used by :
# - set_trigger_delay ROS service. (value = delay in micro sec.).
# - set_line_debouncer_time ROS service. (value = delay in micro sec.).
# - set_noise_reduction ROS service. (value = reduction value). 
# - set_sharpness_enhancement ROS service (value = sharpness value). 

float32 value 		# value to be setted
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
")

(setf (get camera_control_msgs::SetFloatValueResponse :md5sum-) "345a3274594e7cc629d8cd38d3b1fe73")
(setf (get camera_control_msgs::SetFloatValueResponse :datatype-) "camera_control_msgs/SetFloatValueResponse")
(setf (get camera_control_msgs::SetFloatValueResponse :definition-)
      "# Used by :
# - set_trigger_delay ROS service. (value = delay in micro sec.).
# - set_line_debouncer_time ROS service. (value = delay in micro sec.).
# - set_noise_reduction ROS service. (value = reduction value). 
# - set_sharpness_enhancement ROS service (value = sharpness value). 

float32 value 		# value to be setted
---
bool success   # indicate successful run of triggered service
string message # informational, e.g. for error messages
")



(provide :camera_control_msgs/SetFloatValue "345a3274594e7cc629d8cd38d3b1fe73")


