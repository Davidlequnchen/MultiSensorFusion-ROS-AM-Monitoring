;; Auto-generated. Do not edit!


(when (boundp 'auto_control::MsgCommand)
  (if (not (find-package "AUTO_CONTROL"))
    (make-package "AUTO_CONTROL"))
  (shadow 'MsgCommand (find-package "AUTO_CONTROL")))
(unless (find-package "AUTO_CONTROL::MSGCOMMAND")
  (make-package "AUTO_CONTROL::MSGCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude MsgCommand.msg.html


(defclass auto_control::MsgCommand
  :super ros::object
  :slots (_command ))

(defmethod auto_control::MsgCommand
  (:init
   (&key
    ((:command __command) 0.0)
    )
   (send-super :init)
   (setq _command (float __command))
   self)
  (:command
   (&optional __command)
   (if __command (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; float32 _command
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _command
       (sys::poke _command (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _command
     (setq _command (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get auto_control::MsgCommand :md5sum-) "7a381543013b116822c4c5bfba61dfce")
(setf (get auto_control::MsgCommand :datatype-) "auto_control/MsgCommand")
(setf (get auto_control::MsgCommand :definition-)
      "float32 command

")



(provide :auto_control/MsgCommand "7a381543013b116822c4c5bfba61dfce")


