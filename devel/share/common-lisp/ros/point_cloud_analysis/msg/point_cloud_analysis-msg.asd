
(cl:in-package :asdf)

(defsystem "point_cloud_analysis-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MsgHeightMonitoring" :depends-on ("_package_MsgHeightMonitoring"))
    (:file "_package_MsgHeightMonitoring" :depends-on ("_package"))
    (:file "MsgPointCloudScan" :depends-on ("_package_MsgPointCloudScan"))
    (:file "_package_MsgPointCloudScan" :depends-on ("_package"))
  ))