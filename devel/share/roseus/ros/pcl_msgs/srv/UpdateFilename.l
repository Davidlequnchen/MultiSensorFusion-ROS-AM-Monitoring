;; Auto-generated. Do not edit!


(when (boundp 'pcl_msgs::UpdateFilename)
  (if (not (find-package "PCL_MSGS"))
    (make-package "PCL_MSGS"))
  (shadow 'UpdateFilename (find-package "PCL_MSGS")))
(unless (find-package "PCL_MSGS::UPDATEFILENAME")
  (make-package "PCL_MSGS::UPDATEFILENAME"))
(unless (find-package "PCL_MSGS::UPDATEFILENAMEREQUEST")
  (make-package "PCL_MSGS::UPDATEFILENAMEREQUEST"))
(unless (find-package "PCL_MSGS::UPDATEFILENAMERESPONSE")
  (make-package "PCL_MSGS::UPDATEFILENAMERESPONSE"))

(in-package "ROS")





(defclass pcl_msgs::UpdateFilenameRequest
  :super ros::object
  :slots (_filename ))

(defmethod pcl_msgs::UpdateFilenameRequest
  (:init
   (&key
    ((:filename __filename) "")
    )
   (send-super :init)
   (setq _filename (string __filename))
   self)
  (:filename
   (&optional __filename)
   (if __filename (setq _filename __filename)) _filename)
  (:serialization-length
   ()
   (+
    ;; string _filename
    4 (length _filename)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _filename
       (write-long (length _filename) s) (princ _filename s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _filename
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _filename (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass pcl_msgs::UpdateFilenameResponse
  :super ros::object
  :slots (_success ))

(defmethod pcl_msgs::UpdateFilenameResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass pcl_msgs::UpdateFilename
  :super ros::object
  :slots ())

(setf (get pcl_msgs::UpdateFilename :md5sum-) "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(setf (get pcl_msgs::UpdateFilename :datatype-) "pcl_msgs/UpdateFilename")
(setf (get pcl_msgs::UpdateFilename :request) pcl_msgs::UpdateFilenameRequest)
(setf (get pcl_msgs::UpdateFilename :response) pcl_msgs::UpdateFilenameResponse)

(defmethod pcl_msgs::UpdateFilenameRequest
  (:response () (instance pcl_msgs::UpdateFilenameResponse :init)))

(setf (get pcl_msgs::UpdateFilenameRequest :md5sum-) "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(setf (get pcl_msgs::UpdateFilenameRequest :datatype-) "pcl_msgs/UpdateFilenameRequest")
(setf (get pcl_msgs::UpdateFilenameRequest :definition-)
      "string filename
---
bool success

")

(setf (get pcl_msgs::UpdateFilenameResponse :md5sum-) "93a4bc4c60dc17e2a69e3fcaaa25d69d")
(setf (get pcl_msgs::UpdateFilenameResponse :datatype-) "pcl_msgs/UpdateFilenameResponse")
(setf (get pcl_msgs::UpdateFilenameResponse :definition-)
      "string filename
---
bool success

")



(provide :pcl_msgs/UpdateFilename "93a4bc4c60dc17e2a69e3fcaaa25d69d")


