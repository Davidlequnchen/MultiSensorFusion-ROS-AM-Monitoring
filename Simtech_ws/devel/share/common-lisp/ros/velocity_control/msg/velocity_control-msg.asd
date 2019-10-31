
(cl:in-package :asdf)

(defsystem "velocity_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgSpeedOverride" :depends-on ("_package_MsgSpeedOverride"))
    (:file "_package_MsgSpeedOverride" :depends-on ("_package"))
  ))