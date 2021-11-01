
(cl:in-package :asdf)

(defsystem "simtech_kuka_rsi_hw_interface-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgCartPosition" :depends-on ("_package_MsgCartPosition"))
    (:file "_package_MsgCartPosition" :depends-on ("_package"))
  ))