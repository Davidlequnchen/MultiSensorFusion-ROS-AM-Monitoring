
(cl:in-package :asdf)

(defsystem "microepsilon_scancontrol-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MsgCommand" :depends-on ("_package_MsgCommand"))
    (:file "_package_MsgCommand" :depends-on ("_package"))
  ))