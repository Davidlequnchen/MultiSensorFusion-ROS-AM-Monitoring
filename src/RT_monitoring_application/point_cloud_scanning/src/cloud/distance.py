import numpy as np
import scipy
from skimage.measure import LineModelND, ransac

def z_heigh_ransac(points3d):
    """Fits points in a line model, and returns the difference in the 'z'
    dimension between the highest point and its nearest point in the model"""
    model_robust, inliers = ransac(points3d, LineModelND, min_samples=2,
                               residual_threshold=0.0001, max_trials=1000)
    outliers = inliers == False
    if len(points3d[outliers]) == 0:
        return 0

    zmax_p = points3d[outliers][np.argsort(points3d[outliers], axis=0)[-1][2]]

    k = scipy.spatial.KDTree(points3d[inliers])
    dist, index = k.query(zmax_p)
    z_nearest = points3d[inliers][index][2]

    z_heigh = zmax_p[2] - z_nearest
    return z_heigh

if __name__ == '__main__':
    pass
