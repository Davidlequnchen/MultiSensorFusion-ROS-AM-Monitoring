
(cl:in-package :asdf)

(defsystem "infratec_image_processing-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MsgHistogram" :depends-on ("_package_MsgHistogram"))
    (:file "_package_MsgHistogram" :depends-on ("_package"))
    (:file "MsgMeltpool" :depends-on ("_package_MsgMeltpool"))
    (:file "_package_MsgMeltpool" :depends-on ("_package"))
    (:file "MsgMeltpoolWidth" :depends-on ("_package_MsgMeltpoolWidth"))
    (:file "_package_MsgMeltpoolWidth" :depends-on ("_package"))
    (:file "MsgROISize" :depends-on ("_package_MsgROISize"))
    (:file "_package_MsgROISize" :depends-on ("_package"))
    (:file "MsgThreshold" :depends-on ("_package_MsgThreshold"))
    (:file "_package_MsgThreshold" :depends-on ("_package"))
    (:file "TemperatureFeature" :depends-on ("_package_TemperatureFeature"))
    (:file "_package_TemperatureFeature" :depends-on ("_package"))
  ))