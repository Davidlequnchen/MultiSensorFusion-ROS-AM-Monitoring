
(cl:in-package :asdf)

(defsystem "acoustic_processing_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MsgAcousticFeature" :depends-on ("_package_MsgAcousticFeature"))
    (:file "_package_MsgAcousticFeature" :depends-on ("_package"))
  ))