#!/usr/bin/env python

'''

This ROS node identifies the defects on planar surfaces based on training results



subscribe topic: segmentation point cloud
publish topic: message of defects identification result: 0 / 1 / 2 / 3

'''
# required ROS libraries
import os
import rospy
import rospkg
import std_msgs.msg

import sensor_msgs.point_cloud2 as pc2
from sensor_msgs.msg import PointCloud2

from defects_identification.msg import MsgDefects
from defects_identification.msg import MsgPointHeight

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

rospack = rospkg.RosPack()
path = rospack.get_path('defects_identification')



class DefectsIdentification():
    def __init__(self):
        rospy.init_node("surface defects indentification")
        # subscribe the point cloud after segmentation 
        rospy.Subscriber(
            '/cloud_pcd', PointCloud2, self.cb_point_cloud, queue_size=1)

        # subscribe point heigt
        rospy.Subscriber(
            '/cloud_pcd/point_height', MsgPointHeight, self.cb_point_height, queue_size=10)
        
        
        # publish information of plane defects: no defects , ridge , dent ,both ridge and dent 
        self.pub_defects_info = rospy.Publisher(
            '/plane_defects_identification', MsgDefects, queue_size=10)

        self.msg_defects = MsgDefects()

        self.defects_classifier = PlaneDefectsML()

        # load the decision tree model from config folder
        filename = os.path.join(path, 'config', 'DTC.pkl')
        self.defects_classifier.load_classification_model(filename)

        
    def cb_point_cloud(self, msg_cloud):
        '''
        data type of subscribed msg_cloud: PointClou2
        1. pass the point cloud value (x,y,z) to the machine learning model
        2. perform classification and publish results
        '''



    def cb_point_height(self, msg_point_height):
        '''
        subscribe point heights message, 
        pass this point to plane distance value as a list to the machine learning model
        '''




class PlaneDefectsML():
    def __init__(self):
        
        # Lists of features to be used in machine learning:
        # Each element in the following lists correspond to one scanned surface

        self.stdRidgeDistList = []  # standard deviation of absolute distance (positive) to the fitted plane, from "ridge" points
        self.stdDentDistList = []  # standard deviation of absolute distance (negative) to the fitted plane, from "dent" points
        self.percentRidgeList = []  # percentage of "ridge" points to total points in the cloud
        self.percentDentList = []  # percentage of "dent" points to total points in the cloud

        # List of class labels (targets) as training data:
        # Each element in the following lists correspond to one scanned surface
        self.classList = []   # 0: no defect. 1: "ridge" defect. 2: "dent" defect. 3: both "ridge" and "dent" defects

        # List of defect (ridge and dent) point clusters:
        self.ridgePointClusterList = []  # list of pandas dataframe
        self.ridgeDistanceClusterList = []
        self.dentPointClusterList = []
        self.dentDistanceClusterList = []
        
        self.point_to_plane_distance = []
        self.point_cloud = [] #[[x,y,z], [x,y,z],...]

        


    def get_cloud(self, pointcloud):
        self.point_cloud = pointcloud

    def get_point_to_plane_distance(self, distance):
        self.point_to_plane_distance = distance



    def panda_DF_create(self):
        #-------------------------Create pandas dataframe for point cloud------------------------------------------------------------------

        # Load data from file into pandas dataframe:--------------This needs to be changed into read ros topic subscribed--------
        # All points' (x,y,z), 3-column dataframe
        self.pointsDF = pandas.read_csv(self.point_cloud, sep=',', names=('x', 'y', 'z'))   # skip the first 11 lines in the .pcd file

        # Distances FROM the plane to all points (1-column dataframe)
        self.distanceDF = pandas.read_csv(self.point_to_plane_distance, names=('D'))
        #----------------------------------------------------------------------------------------------------------------

        
        # Select the points with large positive distances FROM the plane:  "Ridge" label (defect)
        self.ridgeDistanceDF = self.distanceDF[self.distanceDF['D'] > 0.0005]
        self.ridgePointsDF = self.pointsDF[self.distanceDF['D'] > 0.0005]

        # Select the points with small negative distances FROM the plane:  "Dent" label (defect)
        self.dentDistanceDF = self.distanceDF[self.distanceDF['D'] < -0.0005]
        self.dentPointsDF = self.pointsDF[self.distanceDF['D'] < -0.0005]

        # Select the points nearly on the the plane:  "Plane" label (no defect)
        self.planeDistanceDF = self.distanceDF[ (self.distanceDF['D'] <= 0.0005) & (self.distanceDF['D'] >= -0.0005) ]
        self.planePointsDF = self.pointsDF[ (self.distanceDF['D'] <= 0.0005) & (self.distanceDF['D'] >= -0.0005) ]



    def clustering_defects(self):
            
        #------------------Clustering of "ridge" defect points------------------------------------------------

        if not self.ridgePointsDF.empty:


            # For clustering, instead of using Open3D, we can also use scikit-learn
            # Use either DBSCAN or OPTICS method:
            ridgePointsDF_transformed = StandardScaler().fit_transform(self.ridgePointsDF)

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
                self.ridgePointClusterList.append(self.ridgePointsDF[labels == n])
                self.ridgeDistanceClusterList.append(self.ridgeDistanceDF[labels == n])

        #------------------Clustering of "dent" defect points------------------------------------------------

        if not self.dentPointsDF.empty:

            # Use scikit-learn for clustering
            # Use either DBSCAN or OPTICS method:
            dentPointsDF_transformed = StandardScaler().fit_transform(self.dentPointsDF)

            # Compute DBSCAN:
            db = DBSCAN(eps=0.3, min_samples=10).fit(dentPointsDF_transformed)
            labels = db.labels_  # "labels" is a list of index for EACH point: -1: noise, 0: cluster 1, 1: cluster 2,.......

            # Number of clusters found, ingoring noise if present (label value = -1 for noise point)
            N_clusters = labels.max()+1   #alternatively, we can use: N_clusters = len(set(labels)) - (1 if -1 in labels else 0)
            print("Number of dent clusters: " + format(N_clusters))

            # Extract the clusters of points
            for n in range(0, N_clusters):
                self.dentPointClusterList.append(self.dentPointsDF[labels == n])
                self.dentDistanceClusterList.append(self.dentDistanceDF[labels == n])






    
    def data_featuring (self):   
        #-----------------Feature data for each scanned surface---------------------------------------------------------
        if len(self.ridgeDistanceClusterList) > 0:
            self.stdRidgeDistList.append(max([dist['D'].std() for dist in self.ridgeDistanceClusterList]))
            #percentRidgeList.append( float(len(ridgePointsDF.index)) / len(pointsDF.index) )  # len(df.index) returns the number of rows in the dataframe (i.e. number of points in the cloud)
            self.percentRidgeList.append(max([float(len(p.index))/len(self.pointsDF.index) for p in self.ridgePointClusterList]))   # "p" is a pandas dataframe
        
        else:
            self.stdRidgeDistList.append(0.0)
            self.percentRidgeList.append(0.0)
            

        if len(self.dentDistanceClusterList) > 0:
            self.stdDentDistList.append(max([dist['D'].std() for dist in self.dentDistanceClusterList]))
            self.percentDentList.append(max([float(len(p.index))/len(self.pointsDF.index) for p in self.dentPointClusterList]))   # "p" is a pandas dataframe
        

        else:
        
            self.stdDentDistList.append(0.0)
            self.percentDentList.append(0.0)
            




    def load_classification_model(self, filename):
        # load the decision tree model from config folder
        self.clf_loaded = pickle.load(open(filename, 'rb'))



    def decision_tree_prediction (self):
        #------------------------Prediction based on Decision tree classification ------------------------
        # Feature X and class (labels) Y
        #------------------------Pandas dataframe for machine learning-----------
        self.X = DataFrame(list(zip(self.stdRidgeDistList, self.percentRidgeList,
                                    self.stdDentDistList, self.percentDentList,
                                self.classList)))[0:3]
        self.Y = DataFrame(list(zip(self.stdRidgeDistList, self.percentRidgeList,
                                    self.stdDentDistList, self.percentDentList,
                                self.classList)))[4]
       

        # Transform the feature data X to zero mean and unit variance:
        X = StandardScaler().fit_transform(self.X)

        #-------------------- Decision Tree Classifier accuracy using all data (training + testing)---------------

        # clf_loaded = pickle.load(open(filename, 'rb'))

        Y_predict = self.clf_loaded.predict(X)
        print("\nY_predict (all data) = ")
        print(Y_predict)
        #-------------------------------------------------------------------------------------------------

                









if __name__ == '__main__':
    try:
        DefectsIdentification()
    except rospy.ROSInterruptException:
        pass












