
(cl:in-package :asdf)

(defsystem "acoustic_monitoring_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "AudioDataStamped" :depends-on ("_package_AudioDataStamped"))
    (:file "_package_AudioDataStamped" :depends-on ("_package"))
    (:file "MsgAcousticFeature" :depends-on ("_package_MsgAcousticFeature"))
    (:file "_package_MsgAcousticFeature" :depends-on ("_package"))
  ))