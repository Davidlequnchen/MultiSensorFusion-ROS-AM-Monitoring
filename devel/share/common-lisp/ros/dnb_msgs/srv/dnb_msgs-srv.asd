
(cl:in-package :asdf)

(defsystem "dnb_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "SetString" :depends-on ("_package_SetString"))
    (:file "_package_SetString" :depends-on ("_package"))
  ))