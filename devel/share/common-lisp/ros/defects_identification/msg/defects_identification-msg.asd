
(cl:in-package :asdf)

(defsystem "defects_identification-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgDefects" :depends-on ("_package_MsgDefects"))
    (:file "_package_MsgDefects" :depends-on ("_package"))
  ))