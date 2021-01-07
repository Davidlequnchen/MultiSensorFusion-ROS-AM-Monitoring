;; Auto-generated. Do not edit!


(when (boundp 'camera_measures::MsgVelocityStatus)
  (if (not (find-package "CAMERA_MEASURES"))
    (make-package "CAMERA_MEASURES"))
  (shadow 'MsgVelocityStatus (find-package "CAMERA_MEASURES")))
(unless (find-package "CAMERA_MEASURES::MSGVELOCITYSTATUS")
  (make-package "CAMERA_MEASURES::MSGVELOCITYSTATUS"))

(in-package "ROS")
;;//! \htmlinclude MsgVelocityStatus.msg.html


(defclass camera_measures::MsgVelocityStatus
  :super ros::object
  :slots (_running _speed ))

(defmethod camera_measures::MsgVelocityStatus
  (:init
   (&key
    ((:running __running) nil)
    ((:speed __speed) 0.0)
    )
   (send-super :init)
   (setq _running __running)
   (setq _speed (float __speed))
   self)
  (:running
   (&optional __running)
   (if __running (setq _running __running)) _running)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:serialization-length
   ()
   (+
    ;; bool _running
    1
    ;; float32 _speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _running
       (if _running (write-byte -1 s) (write-byte 0 s))
     ;; float32 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _running
     (setq _running (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; float32 _speed
     (setq _speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get camera_measures::MsgVelocityStatus :md5sum-) "f12f52908a2201f7da503aef7f554966")
(setf (get camera_measures::MsgVelocityStatus :datatype-) "camera_measures/MsgVelocityStatus")
(setf (get camera_measures::MsgVelocityStatus :definition-)
      "bool running
float32 speed

")



(provide :camera_measures/MsgVelocityStatus "f12f52908a2201f7da503aef7f554966")


