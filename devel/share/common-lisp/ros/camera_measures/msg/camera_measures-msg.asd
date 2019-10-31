
(cl:in-package :asdf)

(defsystem "camera_measures-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgGeometry" :depends-on ("_package_MsgGeometry"))
    (:file "_package_MsgGeometry" :depends-on ("_package"))
    (:file "MsgStatus" :depends-on ("_package_MsgStatus"))
    (:file "_package_MsgStatus" :depends-on ("_package"))
    (:file "MsgVelocity" :depends-on ("_package_MsgVelocity"))
    (:file "_package_MsgVelocity" :depends-on ("_package"))
  ))