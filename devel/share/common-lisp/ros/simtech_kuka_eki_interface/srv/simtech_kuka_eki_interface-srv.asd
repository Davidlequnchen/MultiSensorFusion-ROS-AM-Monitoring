
(cl:in-package :asdf)

(defsystem "simtech_kuka_eki_interface-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SrvRobotCommand" :depends-on ("_package_SrvRobotCommand"))
    (:file "_package_SrvRobotCommand" :depends-on ("_package"))
  ))