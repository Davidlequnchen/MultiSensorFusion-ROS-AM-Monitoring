;; Auto-generated. Do not edit!


(when (boundp 'microepsilon_scancontrol::MsgCommand)
  (if (not (find-package "MICROEPSILON_SCANCONTROL"))
    (make-package "MICROEPSILON_SCANCONTROL"))
  (shadow 'MsgCommand (find-package "MICROEPSILON_SCANCONTROL")))
(unless (find-package "MICROEPSILON_SCANCONTROL::MSGCOMMAND")
  (make-package "MICROEPSILON_SCANCONTROL::MSGCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude MsgCommand.msg.html


(defclass microepsilon_scancontrol::MsgCommand
  :super ros::object
  :slots (_command ))

(defmethod microepsilon_scancontrol::MsgCommand
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

(setf (get microepsilon_scancontrol::MsgCommand :md5sum-) "7a381543013b116822c4c5bfba61dfce")
(setf (get microepsilon_scancontrol::MsgCommand :datatype-) "microepsilon_scancontrol/MsgCommand")
(setf (get microepsilon_scancontrol::MsgCommand :definition-)
      "float32 command

")



(provide :microepsilon_scancontrol/MsgCommand "7a381543013b116822c4c5bfba61dfce")


