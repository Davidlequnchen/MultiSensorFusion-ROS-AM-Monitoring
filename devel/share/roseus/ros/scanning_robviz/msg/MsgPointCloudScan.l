;; Auto-generated. Do not edit!


(when (boundp 'scanning_robviz::MsgPointCloudScan)
  (if (not (find-package "SCANNING_ROBVIZ"))
    (make-package "SCANNING_ROBVIZ"))
  (shadow 'MsgPointCloudScan (find-package "SCANNING_ROBVIZ")))
(unless (find-package "SCANNING_ROBVIZ::MSGPOINTCLOUDSCAN")
  (make-package "SCANNING_ROBVIZ::MSGPOINTCLOUDSCAN"))

(in-package "ROS")
;;//! \htmlinclude MsgPointCloudScan.msg.html


(defclass scanning_robviz::MsgPointCloudScan
  :super ros::object
  :slots (_ready _scanning_count ))

(defmethod scanning_robviz::MsgPointCloudScan
  (:init
   (&key
    ((:ready __ready) nil)
    ((:scanning_count __scanning_count) 0)
    )
   (send-super :init)
   (setq _ready __ready)
   (setq _scanning_count (round __scanning_count))
   self)
  (:ready
   (&optional __ready)
   (if __ready (setq _ready __ready)) _ready)
  (:scanning_count
   (&optional __scanning_count)
   (if __scanning_count (setq _scanning_count __scanning_count)) _scanning_count)
  (:serialization-length
   ()
   (+
    ;; bool _ready
    1
    ;; int32 _scanning_count
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ready
       (if _ready (write-byte -1 s) (write-byte 0 s))
     ;; int32 _scanning_count
       (write-long _scanning_count s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ready
     (setq _ready (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _scanning_count
     (setq _scanning_count (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get scanning_robviz::MsgPointCloudScan :md5sum-) "e17f7c935aac21da9daa560a5aff6392")
(setf (get scanning_robviz::MsgPointCloudScan :datatype-) "scanning_robviz/MsgPointCloudScan")
(setf (get scanning_robviz::MsgPointCloudScan :definition-)
      "bool ready # to tell the analysis node ready or not
int32 scanning_count # No. of scan

")



(provide :scanning_robviz/MsgPointCloudScan "e17f7c935aac21da9daa560a5aff6392")


