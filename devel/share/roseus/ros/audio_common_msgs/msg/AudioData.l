;; Auto-generated. Do not edit!


(when (boundp 'audio_common_msgs::AudioData)
  (if (not (find-package "AUDIO_COMMON_MSGS"))
    (make-package "AUDIO_COMMON_MSGS"))
  (shadow 'AudioData (find-package "AUDIO_COMMON_MSGS")))
(unless (find-package "AUDIO_COMMON_MSGS::AUDIODATA")
  (make-package "AUDIO_COMMON_MSGS::AUDIODATA"))

(in-package "ROS")
;;//! \htmlinclude AudioData.msg.html


(defclass audio_common_msgs::AudioData
  :super ros::object
  :slots (_data ))

(defmethod audio_common_msgs::AudioData
  (:init
   (&key
    ((:data __data) (make-array 0 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _data __data)
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; uint8[] _data
    (* 1    (length _data)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8[] _data
     (write-long (length _data) s)
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8[] _data
   (let ((n (sys::peek buf ptr- :integer))) (incf ptr- 4)
     (setq _data (make-array n :element-type :char))
     (replace _data buf :start2 ptr-) (incf ptr- n))
   ;;
   self)
  )

(setf (get audio_common_msgs::AudioData :md5sum-) "f43a8e1b362b75baa741461b46adc7e0")
(setf (get audio_common_msgs::AudioData :datatype-) "audio_common_msgs/AudioData")
(setf (get audio_common_msgs::AudioData :definition-)
      "uint8[] data

")



(provide :audio_common_msgs/AudioData "f43a8e1b362b75baa741461b46adc7e0")


