'''

This program identifies the defects on planar surfaces

Run in Python 2 (base)

'''

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

import sys, getopt





def main():
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

    PCLFile = str(sys.argv[1])
    distanceFile = str(sys.argv[2])
    filename =  str(sys.argv[3])



    #-------------------------Create pandas dataframe for point cloud------------------------------------------------------------------

    # Load data from list into pandas dataframe:--------------This needs to be changed into read ros topic subscribed--------
    pointsDF = pandas.read_csv(PCLFile, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])   # skip the first 11 lines in the .pcd file

    # Distances FROM the plane to all points (1-column dataframe)
    distanceDF = pandas.read_csv(distanceFile, names=('D'))
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
        # print("Number of ridge clusters: " + format(N_clusters))

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
        # print("Number of dent clusters: " + format(N_clusters))

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
    # X = DataFrame(list(zip(stdRidgeDistList, percentRidgeList, stdDentDistList, percentDentList)),
    #               columns= ["stdRidgeDist", "percentRidge", "stdDentDist", "percentDent"])

    X = DataFrame(list(zip([0], [0], [0], [0])),
                columns= ["stdRidgeDist", "percentRidge", "stdDentDist", "percentDent"])

    # print (X)
    # Y = DataFrame(list(zip(stdRidgeDistList, percentRidgeList,
    #                             stdDentDistList, percentDentList,
    #                         classList)))[4]


    # Transform the feature data X to zero mean and unit variance:
    X = StandardScaler().fit_transform(X)

    #-------------------- Decision Tree Classifier accuracy using all data (training + testing)---------------




    clf_loaded = pickle.load(open(filename, 'rb'))



    Y_predict = clf_loaded.predict(X)


    # print("\nY_predict (all data) = ")
    print(Y_predict[0])

    return float(Y_predict[0])

                


if __name__ == "__main__":
    main()
