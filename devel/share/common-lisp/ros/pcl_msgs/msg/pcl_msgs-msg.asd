
(cl:in-package :asdf)

(defsystem "pcl_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ModelCoefficients" :depends-on ("_package_ModelCoefficients"))
    (:file "_package_ModelCoefficients" :depends-on ("_package"))
    (:file "PointIndices" :depends-on ("_package_PointIndices"))
    (:file "_package_PointIndices" :depends-on ("_package"))
    (:file "PolygonMesh" :depends-on ("_package_PolygonMesh"))
    (:file "_package_PolygonMesh" :depends-on ("_package"))
    (:file "Vertices" :depends-on ("_package_Vertices"))
    (:file "_package_Vertices" :depends-on ("_package"))
  ))