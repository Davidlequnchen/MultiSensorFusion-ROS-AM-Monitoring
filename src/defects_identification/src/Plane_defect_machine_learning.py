'''

This program identifies the defects on planar surfaces

Run in Python 2 (base)

'''

import pandas
from pandas import DataFrame

# For point cloud processing
import open3d

# For point cloud clustering using scikit-learn:
from sklearn.cluster import DBSCAN

# For data standardization (transformation of the data onto unit scale (mean=0 and variance=1), required in most machine learning)
from sklearn.preprocessing import StandardScaler

# For K Nearest Neighbours:
from sklearn import neighbors

# For support vector machine:
from sklearn import svm

# For Gaussian process:
from sklearn.gaussian_process import GaussianProcessClassifier
from sklearn.gaussian_process.kernels import RBF

# For neural network:
from sklearn import neural_network

# For decision tree:
from sklearn import tree

# For ensemble methods:
from sklearn import ensemble

# For data standardization (transform the data so that they have a near-normally distribution with zero mean and unit variance)
from sklearn import preprocessing

# Use grid search with cross validation to select ML model hyper-parameters:
from sklearn.model_selection import train_test_split  # random split the data into "training data" and "testing data"
from sklearn.model_selection import GridSearchCV  # Exhaustive grid search with cross validation (CV)
from sklearn import metrics
from sklearn.metrics import classification_report

# For plotting
import plotly.io as pio
import plotly.graph_objects as go

import numpy as np
import matplotlib.pyplot as plt

# For ML model saving
import pickle



# Lists of features to be used in machine learning:
# Each element in the following lists correspond to one scanned surface
maxRidgeDistList = []  # maximum absolute distance (positive) to the fitted plane, from "ridge" points
meanRidgeDistList = []  # average absolute distance (positive) to the fitted plane, from "ridge" points
stdRidgeDistList = []  # standard deviation of absolute distance (positive) to the fitted plane, from "ridge" points
maxDentDistList = []  # maximum absolute distance (negative) to the fitted plane, from "dent" points
meanDentDistList = []  # average absolute distance (negative) to the fitted plane, from "dent" points
stdDentDistList = []  # standard deviation of absolute distance (negative) to the fitted plane, from "dent" points
percentRidgeList = []  # percentage of "ridge" points to total points in the cloud
percentDentList = []  # percentage of "dent" points to total points in the cloud
sizeRidgeList = []  # the bounding area's size of the "ridge" points
sizeDentList = []  # the bounding area's size of the "dent" points
aspectRatioRidgeList = []  # the bounding area's aspect ratio of the "ridge" points
aspectRatioDentList = []  # the bounding area's aspect ratio of the "ridge" points

# List of class labels (targets) as training data:
# Each element in the following lists correspond to one scanned surface
classList = []   # 0: no defect. 1: "ridge" defect. 2: "dent" defect. 3: both "ridge" and "dent" defects



for i in range(1,23):  # totally 22 surfaces (index 1 to 22)

    # List of defect (ridge and dent) point clusters:
    ridgePointClusterList = []  # list of pandas dataframe
    ridgeDistanceClusterList = []
    dentPointClusterList = []
    dentDistanceClusterList = []

    print "\nSurface # " + format(i)

    PCLFile = "All_Data/" + format(i) + "/" + format(i) + "_seg.pcd"   # the point cloud file generated by PCL
    planeFile = "All_Data/" + format(i) + "/" + "coefficient_plane" + format(i) + ".txt"   # this file contains only the a, b, c, d coefficient of the plane (ax + by + cz + d = 0)
    distanceFile = "All_Data/" + format(i) + "/" + "distance_plane" + format(i) + ".txt"   # contains vertical distance FROM the plane TO all points
    normalFile = "All_Data/" + format(i) + "/" + "normalEstimation_plane" + format(i) + ".txt"   # normal vector and curvature (nx, ny, nz, c) of all points
    classFile = "All_Data/" + format(i) + "/" + "class" + format(i) + ".txt"  # the class label (targest) as training data in classification

    classFile = open(classFile, 'r')
    classList.append(int(classFile.read()))   # 0: no defect. 1: "ridge" defect. 2: "dent" defect. 3: both "ridge" and "dent" defects
    classFile.close()



    ## Read the plane coefficients from the file:
    #planeFile = open(planeFile, 'r')
    #planeCoefficients = planeFile.read()  # planeCoefficients is a string "a b c d". Plane function: ax + by + cz + d = 0
    #a = float(planeCoefficients.split(' ')[0])
    #b = float(planeCoefficients.split(' ')[1])
    #c = float(planeCoefficients.split(' ')[2])
    #d = float(planeCoefficients.split(' ')[3])
    #planeFile.close()




    #-------------------------Create pandas dataframe for point cloud------------------------------------------------------------------

    # Load data from file into pandas dataframe:
    # All points' (x,y,z), 3-column dataframe
    pointsDF = pandas.read_csv(PCLFile, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])   # skip the first 11 lines in the .pcd file

    # Distances FROM the plane to all points (1-column dataframe)
    distanceDF = pandas.read_csv(distanceFile, names=('D'))

    # Normal vector and curvature of all points (4-column dataframe):
    normalDF = pandas.read_csv(normalFile, sep=' ', names=('nx', 'ny', 'nz', 'curvature'))


    # Select the points with large positive distances FROM the plane:  "Ridge" label (defect)
    ridgeDistanceDF = distanceDF[distanceDF['D'] > 0.0005]
    ridgePointsDF = pointsDF[distanceDF['D'] > 0.0005]

    # Select the points with small negative distances FROM the plane:  "Dent" label (defect)
    dentDistanceDF = distanceDF[distanceDF['D'] < -0.0005]
    dentPointsDF = pointsDF[distanceDF['D'] < -0.0005]

    # Select the points nearly on the the plane:  "Plane" label (no defect)
    planeDistanceDF = distanceDF[ (distanceDF['D'] <= 0.0005) & (distanceDF['D'] >= -0.0005) ]
    planePointsDF = pointsDF[ (distanceDF['D'] <= 0.0005) & (distanceDF['D'] >= -0.0005) ]
    #---------------------------------------------------------------------------------------------------------------------






    #------------------Clustering of "ridge" defect points------------------------------------------------

    if not ridgePointsDF.empty:


        ## Create "Ridge" point cloud:
        #ridgePointsNP = ridgePointsDF.to_numpy()  # convert Pandas dataframe to numpy array
        #ridgePointsPCD = open3d.geometry.PointCloud()  # define a point cloud
        #ridgePointsPCD.points = open3d.utility.Vector3dVector(ridgePointsNP)  # pass numpy array to point cloud
        #open3d.visualization.draw_geometries([ridgePointsPCD])

        ## Clustering on "Ridge" point cloud: using DBSCAN method
        ## Problem: sometimes DBSCAN clustering in Open3D can be slow
        #labels = np.array(ridgePointsPCD.cluster_dbscan(eps=0.005, min_points=10, print_progress=True))
        #print("Number of clusters: " + format(labels.max()+1))

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

    #------------------------------------------------------------------------------------------------------






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

    #------------------------------------------------------------------------------------------------------







    #-----------------Feature data for each scanned surface---------------------------------------------------------
    if len(ridgeDistanceClusterList) > 0:
        #maxRidgeDistList.append(distanceDF['D'].max())
        maxRidgeDistList.append(max([dist['D'].max() for dist in ridgeDistanceClusterList]))   # "dist" is a pandas dataframe
        meanRidgeDistList.append(max([dist['D'].mean() for dist in ridgeDistanceClusterList]))
        stdRidgeDistList.append(max([dist['D'].std() for dist in ridgeDistanceClusterList]))
        #percentRidgeList.append( float(len(ridgePointsDF.index)) / len(pointsDF.index) )  # len(df.index) returns the number of rows in the dataframe (i.e. number of points in the cloud)
        percentRidgeList.append(max([float(len(p.index))/len(pointsDF.index) for p in ridgePointClusterList]))   # "p" is a pandas dataframe
        sizeRidgeList.append(max([(p['x'].max()-p['x'].min()) * (p['y'].max()-p['y'].min()) for p in ridgePointClusterList]))
        aspectRatioRidgeList.append(max([max((p['x'].max()-p['x'].min()) / (p['y'].max()-p['y'].min()),
                                             (p['y'].max()-p['y'].min()) / (p['x'].max()-p['x'].min())) for p in ridgePointClusterList]))

    else:
        maxRidgeDistList.append(0.0)
        meanRidgeDistList.append(0.0)
        stdRidgeDistList.append(0.0)
        percentRidgeList.append(0.0)
        sizeRidgeList.append(0.0)
        aspectRatioRidgeList.append(0.0)

    if len(dentDistanceClusterList) > 0:
        maxDentDistList.append(max([dist['D'].max() for dist in dentDistanceClusterList]))   # "dist" is a pandas dataframe
        meanDentDistList.append(max([dist['D'].mean() for dist in dentDistanceClusterList]))
        stdDentDistList.append(max([dist['D'].std() for dist in dentDistanceClusterList]))
        percentDentList.append(max([float(len(p.index))/len(pointsDF.index) for p in dentPointClusterList]))   # "p" is a pandas dataframe
        sizeDentList.append(max([(p['x'].max()-p['x'].min()) * (p['y'].max()-p['y'].min()) for p in dentPointClusterList]))
        aspectRatioDentList.append(max([max((p['x'].max()-p['x'].min()) / (p['y'].max()-p['y'].min()),
                                            (p['y'].max()-p['y'].min()) / (p['x'].max()-p['x'].min())) for p in dentPointClusterList]))

    else:
        maxDentDistList.append(0.0)
        meanDentDistList.append(0.0)
        stdDentDistList.append(0.0)
        percentDentList.append(0.0)
        sizeDentList.append(0.0)
        aspectRatioDentList.append(0.0)
    #---------------------------------------------------------------------------------------------------------




#------------------------Pandas dataframe for machine learning---------------------------------------

ML_df = DataFrame(list(zip(maxRidgeDistList, meanRidgeDistList, stdRidgeDistList, percentRidgeList, sizeRidgeList, aspectRatioRidgeList,
                           maxDentDistList, meanDentDistList, stdDentDistList, percentDentList, sizeDentList, aspectRatioDentList,
                           classList)),
                  columns= ["maxRidgeDist", "meanRidgeDist", "stdRidgeDist", "percentRidge", "sizeRidge", "aspectRatioRidge",
                            "maxDentDist", "meanDentDist", "stdDentDist", "percentDent", "sizeDent", "aspectRatioDent",
                            "class"])

print ML_df

# Save the dataframe to .csv file:
ML_df.to_csv("All_Data/ML_df.csv", index=None, header=True)
#---------------------------------------------------------------------------------------------







#-------------------- Correlation matrix in Heatmap ------------------------------------------

correlation_matrix = ML_df.corr(method='spearman')  # 'spearman' for monotonic correlation, 'pearson' for linear correlation
print(correlation_matrix)
# Use a Heatmap to visualize the correlation matrix:
fig = go.Figure(data=go.Heatmap(z=correlation_matrix,
                                x=["maxRidgeDist", "meanRidgeDist", "stdRidgeDist", "percentRidge", "sizeRidge", "aspectRatioRidge",
                                   "maxDentDist", "meanDentDist", "stdDentDist", "percentDent", "sizeDent", "aspectRatioDent",
                                   "class"],
                                y=["maxRidgeDist", "meanRidgeDist", "stdRidgeDist", "percentRidge", "sizeRidge", "aspectRatioRidge",
                                   "maxDentDist", "meanDentDist", "stdDentDist", "percentDent", "sizeDent", "aspectRatioDent",
                                   "class"]))
# Use the offline mode of plotly:
pio.write_html(fig, file="Figures/Correlation matrix (ML_Data).html", auto_open=False)
#---------------------------------------------------------------------------------------------








#------------------------ Machine learning (SVM classification) ------------------------

# Feature X and class (labels) Y
#X = ML_df.iloc[:,0:12].values  # or: X = ML_df[["maxRidgeDist", "meanRidgeDist", ...]]
#Y = ML_df.iloc[:,12].values    # or: Y = ML_df["class"]
X = ML_df[["percentRidge", "percentDent", "stdRidgeDist", "stdDentDist"]]
Y = ML_df["class"]

# Transform the feature data X to zero mean and unit variance:
X = StandardScaler().fit_transform(X)

# Split the data into training and testing sets:
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.1, random_state=0, shuffle=True)


## Classifier: SVM with linear kernel
#clf = svm.SVC(kernel="linear")
#clf.fit(X_train, Y_train)
#score = clf.score(X_test, Y_test)
#print("test score: %s" % score)
#Y_predict = clf.predict(X_test)
#print(Y_predict)


# Optimize the SVM Classfier's hyper-parameters:
# Ref: https://scikit-learn.org/stable/auto_examples/model_selection/plot_grid_search_digits.html
tuned_parameters = [{'kernel': ['rbf'], 'gamma': [1e-3, 1e-4], 'C': [1, 10, 100, 1000]},
                    {'kernel': ['linear'], 'C': [1, 10, 100, 1000]}]

clf = GridSearchCV(svm.SVC(), tuned_parameters, scoring="accuracy", cv=5)  # for scoring metrics: https://scikit-learn.org/0.15/modules/model_evaluation.html#the-scoring-parameter-defining-model-evaluation-rules
clf.fit(X_train, Y_train)

print("\nBest parameters set found on development set:")
print(clf.best_params_)

score = clf.score(X_test, Y_test)
print("\nTest score: %s" % score)

Y_predict = clf.predict(X_test)
print("\nY_predict (testing data) = ")
print(Y_predict)

print("\nAccuracy of SVM classifier (testing data):")
print(metrics.accuracy_score(Y_test, Y_predict))
#---------------------------------------------------------------------------------------------





#------------------------ SVM Classifier accuracy using all data (training + testing)---------------

# Save the classifier model to a file using "pickle". The model can then be read/restored (in another Python file) for new predictions
# Ref: https://scikit-learn.org/stable/modules/model_persistence.html
filename = "All_Data/SVC.pkl"
pickle.dump(clf, open(filename, "wb"))
clf_loaded = pickle.load(open(filename, 'rb'))

Y_predict = clf_loaded.predict(X)
print("\nY_predict (all data) = ")
print(Y_predict)

print("\nAccuracy of SVM classifier (all data):")
print(metrics.accuracy_score(Y, Y_predict))
#-------------------------------------------------------------------------------------------------





#------------------------ Nearest Neighbors classification ------------------------

# Feature X and class (labels) Y
#X = ML_df.iloc[:,0:12].values  # or: X = ML_df[["maxRidgeDist", "meanRidgeDist", ...]]
#Y = ML_df.iloc[:,12].values    # or: Y = ML_df["class"]
X = ML_df[["percentRidge", "percentDent", "stdRidgeDist", "stdDentDist"]]
Y = ML_df["class"]

# Transform the feature data X to zero mean and unit variance:
X = StandardScaler().fit_transform(X)

# Split the data into training and testing sets:
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.1, random_state=0, shuffle=True)


# Optimize the K-Nearest Neighbors Classfier's hyper-parameters:
# Ref: https://scikit-learn.org/stable/auto_examples/model_selection/plot_grid_search_digits.html
tuned_parameters = {'n_neighbors': [3, 4, 5, 6, 7, 8, 9],
                    'weights': ['uniform', 'distance'],
                    'algorithm': ['auto', 'ball_tree', 'kd_tree', 'brute']}    # a dict (dictionary)

clf = GridSearchCV(neighbors.KNeighborsClassifier(), tuned_parameters, scoring="accuracy", cv=5)  # for scoring metrics: https://scikit-learn.org/0.15/modules/model_evaluation.html#the-scoring-parameter-defining-model-evaluation-rules
clf.fit(X_train, Y_train)

print("\nBest parameters set found on development set:")
print(clf.best_params_)

score = clf.score(X_test, Y_test)
print("\nTest score: %s" % score)

Y_predict = clf.predict(X_test)
print("\nY_predict (testing data) = ")
print(Y_predict)

print("\nAccuracy of Nearest Neighbors classifier (testing data):")
print(metrics.accuracy_score(Y_test, Y_predict))
#---------------------------------------------------------------------------------------------





#-------------------- Nearest Neighbors Classifier accuracy using all data (training + testing)---------------

# Save the classifier model to a file using "pickle". The model can then be read/restored (in another Python file) for new predictions
# Ref: https://scikit-learn.org/stable/modules/model_persistence.html
filename = "All_Data/KNN.pkl"
pickle.dump(clf, open(filename, "wb"))
clf_loaded = pickle.load(open(filename, 'rb'))

Y_predict = clf_loaded.predict(X)
print("\nY_predict (all data) = ")
print(Y_predict)

print("\nAccuracy of Nearest Neighbors classifier (all data):")
print(metrics.accuracy_score(Y, Y_predict))
#-------------------------------------------------------------------------------------------------





#------------------------ Gaussian process classification ------------------------

# Feature X and class (labels) Y
#X = ML_df.iloc[:,0:12].values  # or: X = ML_df[["maxRidgeDist", "meanRidgeDist", ...]]
#Y = ML_df.iloc[:,12].values    # or: Y = ML_df["class"]
X = ML_df[["percentRidge", "percentDent", "stdRidgeDist", "stdDentDist"]]
Y = ML_df["class"]

# Transform the feature data X to zero mean and unit variance:
X = StandardScaler().fit_transform(X)

# Split the data into training and testing sets:
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.1, random_state=0, shuffle=True)


# Optimize the classfier's hyper-parameters:
# Ref: https://scikit-learn.org/stable/auto_examples/model_selection/plot_grid_search_digits.html
kernel = 1.0 * RBF(1.0)
tuned_parameters = {'kernel': [kernel],
                    'optimizer': [None, 'fmin_l_bfgs_b']}    # a dict (dictionary)

clf = GridSearchCV(GaussianProcessClassifier(), tuned_parameters, scoring="accuracy", cv=5)  # for scoring metrics: https://scikit-learn.org/0.15/modules/model_evaluation.html#the-scoring-parameter-defining-model-evaluation-rules
clf.fit(X_train, Y_train)

print("\nBest parameters set found on development set:")
print(clf.best_params_)

score = clf.score(X_test, Y_test)
print("\nTest score: %s" % score)

Y_predict = clf.predict(X_test)
print("\nY_predict (testing data) = ")
print(Y_predict)

print("\nAccuracy of Gaussian Process classifier (testing data):")
print(metrics.accuracy_score(Y_test, Y_predict))
#---------------------------------------------------------------------------------------------





#-------------------- Gaussian Process Classifier accuracy using all data (training + testing)---------------

# Save the classifier model to a file using "pickle". The model can then be read/restored (in another Python file) for new predictions
# Ref: https://scikit-learn.org/stable/modules/model_persistence.html
filename = "All_Data/GPC.pkl"
pickle.dump(clf, open(filename, "wb"))
clf_loaded = pickle.load(open(filename, 'rb'))

Y_predict = clf_loaded.predict(X)
print("\nY_predict (all data) = ")
print(Y_predict)

print("\nAccuracy of Gaussian Process classifier (all data):")
print(metrics.accuracy_score(Y, Y_predict))
#-------------------------------------------------------------------------------------------------




#------------------------ Decision tree classification ------------------------

# Feature X and class (labels) Y
#X = ML_df.iloc[:,0:12].values  # or: X = ML_df[["maxRidgeDist", "meanRidgeDist", ...]]
#Y = ML_df.iloc[:,12].values    # or: Y = ML_df["class"]
X = ML_df[["percentRidge", "percentDent", "stdRidgeDist", "stdDentDist"]]
Y = ML_df["class"]

# Transform the feature data X to zero mean and unit variance:
X = StandardScaler().fit_transform(X)

# Split the data into training and testing sets:
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.1, random_state=0, shuffle=True)


# Optimize the classfier's hyper-parameters:
# Ref: https://scikit-learn.org/stable/auto_examples/model_selection/plot_grid_search_digits.html
tuned_parameters = {'criterion': ['gini', 'entropy'],
                    'splitter': ['best', 'random'],
                    'max_depth': [2,3,4,5,6],
                    'min_samples_split': [2,3,4,5,6]}    # a dict (dictionary)

clf = GridSearchCV(tree.DecisionTreeClassifier(), tuned_parameters, scoring="accuracy", cv=5)  # for scoring metrics: https://scikit-learn.org/0.15/modules/model_evaluation.html#the-scoring-parameter-defining-model-evaluation-rules
clf.fit(X_train, Y_train)

print("\nBest parameters set found on development set:")
print(clf.best_params_)

score = clf.score(X_test, Y_test)
print("\nTest score: %s" % score)

Y_predict = clf.predict(X_test)
print("\nY_predict (testing data) = ")
print(Y_predict)

print("\nAccuracy of Decision Tree classifier (testing data):")
print(metrics.accuracy_score(Y_test, Y_predict))
#---------------------------------------------------------------------------------------------





#-------------------- Decision Tree Classifier accuracy using all data (training + testing)---------------

# Save the classifier model to a file using "pickle". The model can then be read/restored (in another Python file) for new predictions
# Ref: https://scikit-learn.org/stable/modules/model_persistence.html
filename = "All_Data/DTC.pkl"
pickle.dump(clf, open(filename, "wb"))
clf_loaded = pickle.load(open(filename, 'rb'))

Y_predict = clf_loaded.predict(X)
print("\nY_predict (all data) = ")
print(Y_predict)

print("\nAccuracy of Decision Tree classifier (all data):")
print(metrics.accuracy_score(Y, Y_predict))
#-------------------------------------------------------------------------------------------------