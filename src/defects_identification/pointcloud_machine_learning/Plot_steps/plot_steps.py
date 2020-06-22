'''

This program identifies the defects on planar surfaces

Run in Python 2 (base)

'''

import pandas
from pandas import DataFrame


# For plotting
import plotly.io as pio
import plotly.graph_objects as go

import numpy as np

PCLFile = "Q1.pcd" # the original scanning Point cloud 
PCL_sfiltered = "Q1_sfiltered.pcd" # Point Cloud after statistical filtering (noise cancelling)
PCL_vfiltered = "Q1_vfiltered.pcd" # point cloud after apply the voxel grid filter (downsampling)
PCLFile_seg = "Q1_seg.pcd"   # the point cloud after segmentation
planeFile = "coefficient_Q1.txt"   # this file contains only the a, b, c, d coefficient of the plane (ax + by + cz + d = 0)
distanceFile = "distance_Q1.txt"   # contains vertical distance FROM the plane TO all points
normalFile = "normalEstimation_Q1.txt"   # normal vector and curvature (nx, ny, nz, c) of all points

# Read the plane coefficients from the file:
planeFile = open(planeFile, 'r')
planeCoefficients = planeFile.read()  # planeCoefficients is a string "a b c d". Plane function: ax + by + cz + d = 0
a = float(planeCoefficients.split(' ')[0])
b = float(planeCoefficients.split(' ')[1])
c = float(planeCoefficients.split(' ')[2])
d = float(planeCoefficients.split(' ')[3])




#-------------------------Create pandas dataframe ------------------------------------------------------------------

# Load data from file into pandas dataframe:
# All points' (x,y,z), 3-column dataframe
pointsDF = pandas.read_csv(PCLFile, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])   # skip the first 11 lines in the .pcd file
pointssFilteredDF = pandas.read_csv(PCL_sfiltered, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])
pointsvFilteredDF = pandas.read_csv(PCL_vfiltered, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])
pointsSegDF = pandas.read_csv(PCLFile_seg, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])


# Distances FROM the plane to all points (1-column dataframe)
distanceDF = pandas.read_csv(distanceFile, names=('D'))

# Normal vector and curvature of all points (4-column dataframe):
normalDF = pandas.read_csv(normalFile, sep=' ', names=('nx', 'ny', 'nz', 'curvature'))

#---------------------------------------------------------------------------------------------------------------------



#----------------------Plot 1: the original point cloud, using the z (height) as color scale-------------------------------
fig = go.Figure()
# Plot points, using distance FROM plane as color scale
fig.add_trace(go.Scatter3d(x = pointsDF['x'],
                           y = pointsDF['y'],
                           z = pointsDF['z'],
                           mode='markers',
                           marker=dict(size=1,
                                       color=pointsDF['z'],
                                       colorscale='Viridis',
                                       cmin = pointsDF['z'].min(),  # minimum color value
                                       cmax = pointsDF['z'].max(),  # maximum color value
                                       showscale=True)
                           )
              )

fig.update_layout(scene = dict(xaxis = dict(nticks=6, range=[pointsDF['x'].min(), pointsDF['x'].max()]),
                               yaxis = dict(nticks=6, range=[pointsDF['y'].min(), pointsDF['y'].max()]),
                               zaxis = dict(nticks=3, range=[pointsDF['z'].min(), pointsDF['z'].max()]),
                               aspectmode = 'data'  # preserve the proportion of actual axes data
                               )
                  )
# Use the offline mode of plotly:
pio.write_html(fig, file="Q1.html", auto_open=True)

#----------------------------------------------------------------------------------------------------------------


#----------------------Plot 2: the point cloud after noise cancelling, using the z (height) as color scale-------------------------------
fig = go.Figure()
# Plot points, using distance FROM plane as color scale
fig.add_trace(go.Scatter3d(x = pointssFilteredDF['x'],
                           y = pointssFilteredDF['y'],
                           z = pointssFilteredDF['z'],
                           mode='markers',
                           marker=dict(size=1,
                                       color=pointssFilteredDF['z'],
                                       colorscale='Viridis',
                                       cmin = pointssFilteredDF['z'].min(),  # minimum color value
                                       cmax = pointssFilteredDF['z'].max(),  # maximum color value
                                       showscale=True)
                           )
              )

fig.update_layout(scene = dict(xaxis = dict(nticks=6, range=[pointssFilteredDF['x'].min(), pointssFilteredDF['x'].max()]),
                               yaxis = dict(nticks=6, range=[pointssFilteredDF['y'].min(), pointssFilteredDF['y'].max()]),
                               zaxis = dict(nticks=3, range=[pointssFilteredDF['z'].min(), pointssFilteredDF['z'].max()]),
                               aspectmode = 'data'  # preserve the proportion of actual axes data
                               )
                  )
# Use the offline mode of plotly:
pio.write_html(fig, file="Q1_noise_canclled.html", auto_open=True)

#----------------------------------------------------------------------------------------------------------------



#----------------------Plot 3: the original point cloud, using the z (height) as color scale-------------------------------
fig = go.Figure()
# Plot points, using distance FROM plane as color scale
fig.add_trace(go.Scatter3d(x = pointsvFilteredDF['x'],
                           y = pointsvFilteredDF['y'],
                           z = pointsvFilteredDF['z'],
                           mode='markers',
                           marker=dict(size=1,
                                       color=pointsvFilteredDF['z'],
                                       colorscale='Viridis',
                                       cmin = pointsvFilteredDF['z'].min(),  # minimum color value
                                       cmax = pointsvFilteredDF['z'].max(),  # maximum color value
                                       showscale=True)
                           )
              )

fig.update_layout(scene = dict(xaxis = dict(nticks=6, range=[pointsvFilteredDF['x'].min(), pointsvFilteredDF['x'].max()]),
                               yaxis = dict(nticks=6, range=[pointsvFilteredDF['y'].min(), pointsvFilteredDF['y'].max()]),
                               zaxis = dict(nticks=3, range=[pointsvFilteredDF['z'].min(), pointsvFilteredDF['z'].max()]),
                               aspectmode = 'data'  # preserve the proportion of actual axes data
                               )
                  )
# Use the offline mode of plotly:
pio.write_html(fig, file="Q1_downsampled.html", auto_open=True)

#----------------------------------------------------------------------------------------------------------------




#----------------------Plot 4: the segmented point cloud, using the distance from plane as color scale-------------------------------
fig = go.Figure()
# Plot points, using distance FROM plane as color scale
fig.add_trace(go.Scatter3d(x = pointsSegDF['x'],
                           y = pointsSegDF['y'],
                           z = pointsSegDF['z'],
                           mode='markers',
                           marker=dict(size=1,
                                       color=distanceDF['D'],
                                       colorscale='Viridis',
                                       cmin = distanceDF['D'].min(),  # minimum color value
                                       cmax = distanceDF['D'].max(),  # maximum color value
                                       showscale=True)
                           )
              )

# Plot the plane fitted from the point cloud, using the plane coefficients a, b, c, d. Plane function: ax + by + cz + d = 0
X = np.linspace(pointsSegDF['x'].min(), pointsSegDF['x'].max(), 3)
Y = np.linspace(pointsSegDF['y'].min(), pointsSegDF['y'].max(), 3)
X,Y = np.meshgrid(X,Y)
Z = (a*X + b*Y + d) / (-c)
fig.add_trace(go.Surface(x = X,
                         y = Y,
                         z = Z,
                         opacity = 0.5,
                         surfacecolor = (0,0,0)
                         )
              )
fig.update_layout(scene = dict(xaxis = dict(nticks=6, range=[pointsSegDF['x'].min(), pointsSegDF['x'].max()]),
                               yaxis = dict(nticks=6, range=[pointsSegDF['y'].min(), pointsSegDF['y'].max()]),
                               zaxis = dict(nticks=3, range=[pointsSegDF['z'].min(), pointsSegDF['z'].max()]),
                               aspectmode = 'data'  # preserve the proportion of actual axes data
                               )
                  )
# Use the offline mode of plotly:
pio.write_html(fig, file="Q1_Seg.html", auto_open=True)

#----------------------------------------------------------------------------------------------------------------
