#!/usr/bin/env python
import os
import rospy
import rospkg
import std_msgs.msg
from std_msgs.msg import Float32MultiArray

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2

from defects_identification.msg import MsgDefects


import pandas
from pandas import DataFrame

# For point cloud clustering using scikit-learn:
from sklearn.cluster import DBSCAN

# For data standardization (transformation of the data onto unit scale (mean=0 and variance=1), required in most machine learning)
from sklearn.preprocessing import StandardScaler

# For decision tree:
from sklearn import tree

# For data standardization (transform the data so that they have a near-normally distribution with zero mean and unit variance)
from sklearn import preprocessing

import numpy as np

# For ML model saving
import pickle


'''

This ROS node identifies the defects on planar surfaces based on training results



subscribe topic: segmentation point cloud
publish topic: message of defects identification result: 0 / 1 / 2 / 3

'''



rospack = rospkg.RosPack()
path = rospack.get_path('defects_identification')
# load the decision tree model from config folder
filename = os.path.join(path, 'config', 'DTC.pkl')


class DefectsIdentification():
    def __init__(self):

        self.clf_loaded = pickle.load(open(filename, 'rb'))
        
        self.msg_defects = MsgDefects()
        
        
        self.Y_predict = 0 # prediction result



        rospy.init_node("defects_identification")
        # subscribe the point cloud after segmentation 
        rospy.Subscriber(
            '/cloud_pcd', PointCloud2, self.cb_point_cloud, queue_size=1)


        
        # publish information of plane defects: no defects , ridge , dent ,both ridge and dent 
        self.pub_defects_info = rospy.Publisher(
            '/plane_defects_identification', MsgDefects, queue_size=10)

        
        rospy.spin()

        
    def cb_point_cloud(self, msg_cloud):
        '''
        data type of subscribed msg_cloud: PointClou2
        1. pass the point cloud value (x,y,z) to the machine learning model
        2. perform defects prediction and publish results
        '''
        # PointCloud2:  uint8[] data: [....]
        # get the actual point( x y z) information
        self.point_data = pc2.read_points(msg_cloud, skip_nans=True, field_names=("x", "y", "z"))
        
        self.msg_defects.header.stamp = msg_cloud.header.stamp
        
        # subscribe point heigt
        rospy.Subscriber(
            '/cloud_pcd/point_distance', Float32MultiArray, self.cb_distance, queue_size=1)
        





    def cb_distance(self, msg_point_distance):
        '''
        subscribe point distances message, 
        pass this point to plane distance value as a list to the machine learning model
        '''
        # point_to_plane_distance: float32[], a list of float number (msg_point_distance.data )
        # self.point_distance_data =  msg_point_distance.data 

        self.defects_prediction(self.point_data, msg_point_distance.data )
        






    def defects_prediction(self, input_cloud, point_distance):
        
        # Lists of features to be used in machine learning:
        # Each element in the following lists correspond to one scanned surface

        stdRidgeDistList = []  # standard deviation of absolute distance (positive) to the fitted plane, from "ridge" points
        stdDentDistList = []  # standard deviation of absolute distance (negative) to the fitted plane, from "dent" points
        percentRidgeList = []  # percentage of "ridge" points to total points in the cloud
        percentDentList = []  # percentage of "dent" points to total points in the cloud

        # List of class labels (targets) as training data:
        # Each element in the following lists correspond to one scanned surface
        classList = []   # 0: no defect. 1: "ridge" defect. 2: "dent" defect. 3: both "ridge" and "dent" defects

        # List of defect (ridge and dent) point clusters:
        ridgePointClusterList = []  # list of pandas dataframe
        ridgeDistanceClusterList = []
        dentPointClusterList = []
        dentDistanceClusterList = []
        

        Y_predict = 0 # prediction result: 0,1,2,3

        #-------------------------Create pandas dataframe for point cloud------------------------------------------------------------------

        # Load data from list into pandas dataframe:--------------This needs to be changed into read ros topic subscribed--------
        # All points' (x,y,z), 3-column dataframe
        pointsDF = DataFrame(input_cloud, columns=['x', 'y', 'z'] )   
        # print pointsDF
        # print pointsDF.index
        # Distances FROM the plane to all points (1-column dataframe)
        distanceDF = DataFrame(point_distance, columns=['D'])
        # print self.point_to_plane_distance
        # print distanceDF
        # print distanceDF.index
        #----------------------------------------------------------------------------------------------------------------

        
        # Select the points with large positive distances FROM the plane:  "Ridge" label (defect)
        ridgeDistanceDF = distanceDF[distanceDF['D'] > 0.0005]
        ridgePointsDF = pointsDF[distanceDF['D'] > 0.0005]

        # Select the points with small negative distances FROM the plane:  "Dent" label (defect)
        dentDistanceDF = distanceDF[distanceDF['D'] < -0.0005]
        dentPointsDF = pointsDF[distanceDF['D'] < -0.0005]

        # Select the points nearly on the the plane:  "Plane" label (no defect)
        planeDistanceDF = distanceDF[ (distanceDF['D'] <= 0.0005) & (distanceDF['D'] >= -0.0005) ]
        planePointsDF = pointsDF[ (distanceDF['D'] <= 0.0005) & (distanceDF['D'] >= -0.0005) ]


        #------------------Clustering of "ridge" defect points------------------------------------------------

        if not ridgePointsDF.empty:


            # For clustering, instead of using Open3D, we can also use scikit-learn
            # Use either DBSCAN or OPTICS method:
            ridgePointsDF_transformed = StandardScaler().fit_transform(ridgePointsDF)

            # Compute DBSCAN:
            db = DBSCAN(eps=0.5, min_samples=10).fit(ridgePointsDF_transformed)
            labels = db.labels_  # "labels" is a list of index for EACH point: -1: noise, 0: cluster 1, 1: cluster 2,.......

            # Number of clusters found, ingoring noise if present (label value = -1 for noise point)
            N_clusters = labels.max()+1   #alternatively, we can use: N_clusters = len(set(labels)) - (1 if -1 in labels else 0)
            print("Number of ridge clusters: " + format(N_clusters))

            ## Number of noise points. "-1" means the corresponding point is a noise point
            #n_noise_ = list(labels).count(-1)

            # Extract the clusters of points
            for n in range(0, N_clusters):
                ridgePointClusterList.append(ridgePointsDF[labels == n])
                ridgeDistanceClusterList.append(ridgeDistanceDF[labels == n])

        #------------------Clustering of "dent" defect points------------------------------------------------

        if not dentPointsDF.empty:

            # Use scikit-learn for clustering
            # Use either DBSCAN or OPTICS method:
            dentPointsDF_transformed = StandardScaler().fit_transform(dentPointsDF)

            # Compute DBSCAN:
            db = DBSCAN(eps=0.3, min_samples=10).fit(dentPointsDF_transformed)
            labels = db.labels_  # "labels" is a list of index for EACH point: -1: noise, 0: cluster 1, 1: cluster 2,.......

            # Number of clusters found, ingoring noise if present (label value = -1 for noise point)
            N_clusters = labels.max()+1   #alternatively, we can use: N_clusters = len(set(labels)) - (1 if -1 in labels else 0)
            print("Number of dent clusters: " + format(N_clusters))

            # Extract the clusters of points
            for n in range(0, N_clusters):
                dentPointClusterList.append(dentPointsDF[labels == n])
                dentDistanceClusterList.append(dentDistanceDF[labels == n])



        #-----------------Feature data for each scanned surface---------------------------------------------------------
        if len(ridgeDistanceClusterList) > 0:
            stdRidgeDistList.append(max([dist['D'].std() for dist in ridgeDistanceClusterList]))
            percentRidgeList.append(max([float(len(p.index))/len(pointsDF.index) for p in ridgePointClusterList]))   # "p" is a pandas dataframe
        
        else:
            stdRidgeDistList.append(0.0)
            percentRidgeList.append(0.0)
            

        if len(dentDistanceClusterList) > 0:
            stdDentDistList.append(max([dist['D'].std() for dist in dentDistanceClusterList]))
            percentDentList.append(max([float(len(p.index))/len(pointsDF.index) for p in dentPointClusterList]))   # "p" is a pandas dataframe
        

        else:
        
            stdDentDistList.append(0.0)
            percentDentList.append(0.0)
        #------------------------------------------------------------------------------


        #------------------------Prediction ------------------------
        # Feature X and class (labels) Y
        #------------------------Pandas dataframe for machine learning-----------
        X = DataFrame(list(zip(stdRidgeDistList, percentRidgeList,
                                    stdDentDistList, percentDentList,
                                classList)))[0:3]
        Y = DataFrame(list(zip(stdRidgeDistList, percentRidgeList,
                                    stdDentDistList, percentDentList,
                                classList)))[4]
       

        # Transform the feature data X to zero mean and unit variance:
        X = StandardScaler().fit_transform(X)

        #-------------------- Decision Tree Classifier accuracy using all data (training + testing)---------------

        # clf_loaded = pickle.load(open(filename, 'rb'))

        self.Y_predict = self.clf_loaded.predict(X)

        # prediction result
        self.msg_defects.defectsType = self.Y_predict 
        # publish the defects prediction result
        self.pub_defects_info.publish(self.msg_defects)
        
        
        print("\nY_predict (all data) = ")
        print(self.Y_predict)
        #-------------------------------------------------------------------------------------------------

                









if __name__ == '__main__':
    try:
        DefectsIdentification()
    except rospy.ROSInterruptException:
        pass












