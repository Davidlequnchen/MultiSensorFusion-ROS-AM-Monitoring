;; Auto-generated. Do not edit!


(when (boundp 'dnb_msgs::StringMultiArray)
  (if (not (find-package "DNB_MSGS"))
    (make-package "DNB_MSGS"))
  (shadow 'StringMultiArray (find-package "DNB_MSGS")))
(unless (find-package "DNB_MSGS::STRINGMULTIARRAY")
  (make-package "DNB_MSGS::STRINGMULTIARRAY"))

(in-package "ROS")
;;//! \htmlinclude StringMultiArray.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass dnb_msgs::StringMultiArray
  :super ros::object
  :slots (_layout _data ))

(defmethod dnb_msgs::StringMultiArray
  (:init
   (&key
    ((:layout __layout) (instance std_msgs::MultiArrayLayout :init))
    ((:data __data) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _layout __layout)
   (setq _data __data)
   self)
  (:layout
   (&rest __layout)
   (if (keywordp (car __layout))
       (send* _layout __layout)
     (progn
       (if __layout (setq _layout (car __layout)))
       _layout)))
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; std_msgs/MultiArrayLayout _layout
    (send _layout :serialization-length)
    ;; string[] _data
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/MultiArrayLayout _layout
       (send _layout :serialize s)
     ;; string[] _data
     (write-long (length _data) s)
     (dolist (elem _data)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/MultiArrayLayout _layout
     (send _layout :deserialize buf ptr-) (incf ptr- (send _layout :serialization-length))
   ;; string[] _data
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _data (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _data i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(setf (get dnb_msgs::StringMultiArray :md5sum-) "77f374096c7ec9d15c35d6d0e5287e6b")
(setf (get dnb_msgs::StringMultiArray :datatype-) "dnb_msgs/StringMultiArray")
(setf (get dnb_msgs::StringMultiArray :definition-)
      "std_msgs/MultiArrayLayout layout
string[] data
================================================================================
MSG: std_msgs/MultiArrayLayout
# The multiarray declares a generic multi-dimensional array of a
# particular data type.  Dimensions are ordered from outer most
# to inner most.

MultiArrayDimension[] dim # Array of dimension properties
uint32 data_offset        # padding elements at front of data

# Accessors should ALWAYS be written in terms of dimension stride
# and specified outer-most dimension first.
# 
# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]
#
# A standard, 3-channel 640x480 image with interleaved color channels
# would be specified as:
#
# dim[0].label  = \"height\"
# dim[0].size   = 480
# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)
# dim[1].label  = \"width\"
# dim[1].size   = 640
# dim[1].stride = 3*640 = 1920
# dim[2].label  = \"channel\"
# dim[2].size   = 3
# dim[2].stride = 3
#
# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.

================================================================================
MSG: std_msgs/MultiArrayDimension
string label   # label of given dimension
uint32 size    # size of given dimension (in type units)
uint32 stride  # stride of given dimension
")



(provide :dnb_msgs/StringMultiArray "77f374096c7ec9d15c35d6d0e5287e6b")


