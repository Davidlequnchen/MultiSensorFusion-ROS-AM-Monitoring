import os
import glob
import numpy as np
# import cupy

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from camera_measures.nd_geometry.py import NdGeometry

from measures.geometry import Geometry
from measures.projection import Projection

config_file = "LaserControl.yaml"

path = '../'

