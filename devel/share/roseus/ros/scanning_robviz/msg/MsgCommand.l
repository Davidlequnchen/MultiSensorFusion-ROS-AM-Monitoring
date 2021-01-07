;; Auto-generated. Do not edit!


(when (boundp 'scanning_robviz::MsgCommand)
  (if (not (find-package "SCANNING_ROBVIZ"))
    (make-package "SCANNING_ROBVIZ"))
  (shadow 'MsgCommand (find-package "SCANNING_ROBVIZ")))
(unless (find-package "SCANNING_ROBVIZ::MSGCOMMAND")
  (make-package "SCANNING_ROBVIZ::MSGCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude MsgCommand.msg.html


(defclass scanning_robviz::MsgCommand
  :super ros::object
  :slots (_command ))

(defmethod scanning_robviz::MsgCommand
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

(setf (get scanning_robviz::MsgCommand :md5sum-) "7a381543013b116822c4c5bfba61dfce")
(setf (get scanning_robviz::MsgCommand :datatype-) "scanning_robviz/MsgCommand")
(setf (get scanning_robviz::MsgCommand :definition-)
      "float32 command

")



(provide :scanning_robviz/MsgCommand "7a381543013b116822c4c5bfba61dfce")


