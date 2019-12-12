
(cl:in-package :asdf)

(defsystem "camera_measures-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgGeometry" :depends-on ("_package_MsgGeometry"))
    (:file "_package_MsgGeometry" :depends-on ("_package"))
    (:file "MsgPosition" :depends-on ("_package_MsgPosition"))
    (:file "_package_MsgPosition" :depends-on ("_package"))
    (:file "MsgStatus" :depends-on ("_package_MsgStatus"))
    (:file "_package_MsgStatus" :depends-on ("_package"))
    (:file "MsgTwist" :depends-on ("_package_MsgTwist"))
    (:file "_package_MsgTwist" :depends-on ("_package"))
    (:file "MsgVelocity" :depends-on ("_package_MsgVelocity"))
    (:file "_package_MsgVelocity" :depends-on ("_package"))
    (:file "MsgVelocityStatus" :depends-on ("_package_MsgVelocityStatus"))
    (:file "_package_MsgVelocityStatus" :depends-on ("_package"))
  ))