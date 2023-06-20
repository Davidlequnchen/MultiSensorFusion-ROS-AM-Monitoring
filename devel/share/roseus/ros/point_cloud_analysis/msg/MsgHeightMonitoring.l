;; Auto-generated. Do not edit!


(when (boundp 'point_cloud_analysis::MsgHeightMonitoring)
  (if (not (find-package "POINT_CLOUD_ANALYSIS"))
    (make-package "POINT_CLOUD_ANALYSIS"))
  (shadow 'MsgHeightMonitoring (find-package "POINT_CLOUD_ANALYSIS")))
(unless (find-package "POINT_CLOUD_ANALYSIS::MSGHEIGHTMONITORING")
  (make-package "POINT_CLOUD_ANALYSIS::MSGHEIGHTMONITORING"))

(in-package "ROS")
;;//! \htmlinclude MsgHeightMonitoring.msg.html


(defclass point_cloud_analysis::MsgHeightMonitoring
  :super ros::object
  :slots (_plane_id _height_std _height_mean _heighest_max_min_difference _tilt_angle ))

(defmethod point_cloud_analysis::MsgHeightMonitoring
  (:init
   (&key
    ((:plane_id __plane_id) 0)
    ((:height_std __height_std) 0.0)
    ((:height_mean __height_mean) 0.0)
    ((:heighest_max_min_difference __heighest_max_min_difference) 0.0)
    ((:tilt_angle __tilt_angle) 0.0)
    )
   (send-super :init)
   (setq _plane_id (round __plane_id))
   (setq _height_std (float __height_std))
   (setq _height_mean (float __height_mean))
   (setq _heighest_max_min_difference (float __heighest_max_min_difference))
   (setq _tilt_angle (float __tilt_angle))
   self)
  (:plane_id
   (&optional __plane_id)
   (if __plane_id (setq _plane_id __plane_id)) _plane_id)
  (:height_std
   (&optional __height_std)
   (if __height_std (setq _height_std __height_std)) _height_std)
  (:height_mean
   (&optional __height_mean)
   (if __height_mean (setq _height_mean __height_mean)) _height_mean)
  (:heighest_max_min_difference
   (&optional __heighest_max_min_difference)
   (if __heighest_max_min_difference (setq _heighest_max_min_difference __heighest_max_min_difference)) _heighest_max_min_difference)
  (:tilt_angle
   (&optional __tilt_angle)
   (if __tilt_angle (setq _tilt_angle __tilt_angle)) _tilt_angle)
  (:serialization-length
   ()
   (+
    ;; int32 _plane_id
    4
    ;; float32 _height_std
    4
    ;; float32 _height_mean
    4
    ;; float32 _heighest_max_min_difference
    4
    ;; float32 _tilt_angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _plane_id
       (write-long _plane_id s)
     ;; float32 _height_std
       (sys::poke _height_std (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _height_mean
       (sys::poke _height_mean (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _heighest_max_min_difference
       (sys::poke _heighest_max_min_difference (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _tilt_angle
       (sys::poke _tilt_angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _plane_id
     (setq _plane_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _height_std
     (setq _height_std (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _height_mean
     (setq _height_mean (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _heighest_max_min_difference
     (setq _heighest_max_min_difference (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _tilt_angle
     (setq _tilt_angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get point_cloud_analysis::MsgHeightMonitoring :md5sum-) "d5dba450528743fdd28379753715b42a")
(setf (get point_cloud_analysis::MsgHeightMonitoring :datatype-) "point_cloud_analysis/MsgHeightMonitoring")
(setf (get point_cloud_analysis::MsgHeightMonitoring :definition-)
      "int32 plane_id         # the id for the scanning
float32 height_std
float32 height_mean
float32 heighest_max_min_difference
float32 tilt_angle

")



(provide :point_cloud_analysis/MsgHeightMonitoring "d5dba450528743fdd28379753715b42a")


