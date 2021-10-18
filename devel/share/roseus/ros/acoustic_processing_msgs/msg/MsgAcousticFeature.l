;; Auto-generated. Do not edit!


(when (boundp 'acoustic_processing_msgs::MsgAcousticFeature)
  (if (not (find-package "ACOUSTIC_PROCESSING_MSGS"))
    (make-package "ACOUSTIC_PROCESSING_MSGS"))
  (shadow 'MsgAcousticFeature (find-package "ACOUSTIC_PROCESSING_MSGS")))
(unless (find-package "ACOUSTIC_PROCESSING_MSGS::MSGACOUSTICFEATURE")
  (make-package "ACOUSTIC_PROCESSING_MSGS::MSGACOUSTICFEATURE"))

(in-package "ROS")
;;//! \htmlinclude MsgAcousticFeature.msg.html


(defclass acoustic_processing_msgs::MsgAcousticFeature
  :super ros::object
  :slots (_spectral_centroids _fft ))

(defmethod acoustic_processing_msgs::MsgAcousticFeature
  (:init
   (&key
    ((:spectral_centroids __spectral_centroids) 0.0)
    ((:fft __fft) 0.0)
    )
   (send-super :init)
   (setq _spectral_centroids (float __spectral_centroids))
   (setq _fft (float __fft))
   self)
  (:spectral_centroids
   (&optional __spectral_centroids)
   (if __spectral_centroids (setq _spectral_centroids __spectral_centroids)) _spectral_centroids)
  (:fft
   (&optional __fft)
   (if __fft (setq _fft __fft)) _fft)
  (:serialization-length
   ()
   (+
    ;; float32 _spectral_centroids
    4
    ;; float32 _fft
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _spectral_centroids
       (sys::poke _spectral_centroids (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _fft
       (sys::poke _fft (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _spectral_centroids
     (setq _spectral_centroids (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _fft
     (setq _fft (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get acoustic_processing_msgs::MsgAcousticFeature :md5sum-) "dceaefa1e58f133ccf0968427c39fdf1")
(setf (get acoustic_processing_msgs::MsgAcousticFeature :datatype-) "acoustic_processing_msgs/MsgAcousticFeature")
(setf (get acoustic_processing_msgs::MsgAcousticFeature :definition-)
      "float32 spectral_centroids
float32 fft



")



(provide :acoustic_processing_msgs/MsgAcousticFeature "dceaefa1e58f133ccf0968427c39fdf1")


