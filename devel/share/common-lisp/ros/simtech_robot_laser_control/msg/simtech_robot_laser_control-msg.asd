
(cl:in-package :asdf)

(defsystem "simtech_robot_laser_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgControl" :depends-on ("_package_MsgControl"))
    (:file "_package_MsgControl" :depends-on ("_package"))
    (:file "MsgEmission" :depends-on ("_package_MsgEmission"))
    (:file "_package_MsgEmission" :depends-on ("_package"))
    (:file "MsgInfo" :depends-on ("_package_MsgInfo"))
    (:file "_package_MsgInfo" :depends-on ("_package"))
    (:file "MsgPower" :depends-on ("_package_MsgPower"))
    (:file "_package_MsgPower" :depends-on ("_package"))
    (:file "MsgSetpoint" :depends-on ("_package_MsgSetpoint"))
    (:file "_package_MsgSetpoint" :depends-on ("_package"))
    (:file "MsgStart" :depends-on ("_package_MsgStart"))
    (:file "_package_MsgStart" :depends-on ("_package"))
  ))