;; Auto-generated. Do not edit!


(when (boundp 'defects_identification::MsgPointDistance)
  (if (not (find-package "DEFECTS_IDENTIFICATION"))
    (make-package "DEFECTS_IDENTIFICATION"))
  (shadow 'MsgPointDistance (find-package "DEFECTS_IDENTIFICATION")))
(unless (find-package "DEFECTS_IDENTIFICATION::MSGPOINTDISTANCE")
  (make-package "DEFECTS_IDENTIFICATION::MSGPOINTDISTANCE"))

(in-package "ROS")
;;//! \htmlinclude MsgPointDistance.msg.html


(defclass defects_identification::MsgPointDistance
  :super ros::object
  :slots (_point_to_plane_distance ))

(defmethod defects_identification::MsgPointDistance
  (:init
   (&key
    ((:point_to_plane_distance __point_to_plane_distance) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _point_to_plane_distance __point_to_plane_distance)
   self)
  (:point_to_plane_distance
   (&optional __point_to_plane_distance)
   (if __point_to_plane_distance (setq _point_to_plane_distance __point_to_plane_distance)) _point_to_plane_distance)
  (:serialization-length
   ()
   (+
    ;; float32[] _point_to_plane_distance
    (* 4    (length _point_to_plane_distance)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32[] _point_to_plane_distance
     (write-long (length _point_to_plane_distance) s)
     (dotimes (i (length _point_to_plane_distance))
       (sys::poke (elt _point_to_plane_distance i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32[] _point_to_plane_distance
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _point_to_plane_distance (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _point_to_plane_distance i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get defects_identification::MsgPointDistance :md5sum-) "c24ec51a2bb9c83a98d25173a7416b03")
(setf (get defects_identification::MsgPointDistance :datatype-) "defects_identification/MsgPointDistance")
(setf (get defects_identification::MsgPointDistance :definition-)
      "float32[] point_to_plane_distance
")



(provide :defects_identification/MsgPointDistance "c24ec51a2bb9c83a98d25173a7416b03")


