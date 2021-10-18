
(cl:in-package :asdf)

(defsystem "dnb_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ComponentStatus" :depends-on ("_package_ComponentStatus"))
    (:file "_package_ComponentStatus" :depends-on ("_package"))
    (:file "StringMultiArray" :depends-on ("_package_StringMultiArray"))
    (:file "_package_StringMultiArray" :depends-on ("_package"))
  ))