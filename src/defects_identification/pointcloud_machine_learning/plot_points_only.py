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


PCLFile_seg = "V_repaired_10_6.pcd"   # the point cloud after segmentation



#-------------------------Create pandas dataframe ------------------------------------------------------------------

# Load data from file into pandas dataframe:
# All points' (x,y,z), 3-column dataframe
pointsSegDF = pandas.read_csv(PCLFile_seg, sep=' ', names=('x', 'y', 'z'), skiprows=[i for i in range(0,11)])





#----------------------Plot 4: the segmented point cloud, using the distance from plane as color scale-------------------------------
fig = go.Figure()
# Plot points, using distance FROM plane as color scale
fig.add_trace(go.Scatter3d(x = pointsSegDF['x'],
                           y = pointsSegDF['y'],
                           z = pointsSegDF['z'],
                           mode='markers',
                           marker=dict(size=1,
                                       color=pointsSegDF['z'],
                                       colorscale='Viridis',
                                       cmin = pointsSegDF['z'].min(),  # minimum color value
                                       cmax = pointsSegDF['z'].max(),  # maximum color value
                                       showscale=True)
              
                            )
            )

fig.update_layout(scene = dict(xaxis = dict(nticks=6, range=[pointsSegDF['x'].min(), pointsSegDF['x'].max()]),
                               yaxis = dict(nticks=6, range=[pointsSegDF['y'].min(), pointsSegDF['y'].max()]),
                               zaxis = dict(nticks=3, range=[pointsSegDF['z'].min(), pointsSegDF['z'].max()]),
                               aspectmode = 'data'  # preserve the proportion of actual axes data
                               )
                  )
# Use the offline mode of plotly:
pio.write_html(fig, file="10_6.html", auto_open=True)

#----------------------------------------------------------------------------------------------------------------
