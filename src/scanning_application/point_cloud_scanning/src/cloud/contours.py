import os
import cv2
import numpy as np
import matplotlib.pyplot as plt #matplotlib.pyplot is a state-based interface to matplotlib. It provides a MATLAB-like way of plotting.
import matplotlib.gridspec as gridspec

from matplotlib.widgets import SpanSelector
from matplotlib.patches import Rectangle


def pcd_to_xyz(filename):
    points = np.loadtxt(filename, skiprows=11)
    nfilename = '%s.xyz' % filename[:-4]
    with open(nfilename, 'w') as f:
        np.savetxt(f, points[:, :3], fmt='%.6f')


def xyz_to_pcd(filename):
    points3d = np.loadtxt(filename)
    nfilename = '%s.pcd' % filename[:-4]
    with open(nfilename, 'w') as f:
        f.write('# .PCD v.7 - Point Cloud Data file format\n')
        f.write('VERSION .7\n')
        f.write('FIELDS x y z\n')
        f.write('SIZE 4 4 4\n')
        f.write('TYPE F F F\n')
        f.write('COUNT 1 1 1\n')
        f.write('WIDTH %i\n' % len(points3d))
        f.write('HEIGHT 1\n')
        f.write('VIEWPOINT 0 0 0 1 0 0 0\n')
        f.write('POINTS %i\n' % len(points3d))
        f.write('DATA ascii\n')
        np.savetxt(f, points3d, fmt='%.6f')


def read_cloud(filename):
    cloud = np.loadtxt(filename)
    return cloud


def zmap_from_cloud(cloud):
    # numpy.all(a, axis=None, out=None, keepdims=<no value>)[source]
    #Test whether all array elements along a given axis evaluate to True.
    #a: Input array or object that can be converted to an array.
    '''
    #axis : None or int or tuple of ints, optional
     Axis or axes along which a logical AND reduction is performed. 
     The default (axis = None) is to perform a logical AND over all the dimensions of the input array. 
     axis may be negative, in which case it counts from the last to the first axis.
    '''
    cloud = cloud[np.all(cloud > 0, axis=1)]
    points = (np.round(cloud, 4) * 10000).astype(np.int32)
    x_max = np.max(points[:, 0]) #extract all the x value -- the first elements in each row form the array
    y_max = np.max(points[:, 1]) #extract all the y value -- second elements in each row of the array.
    zmap = np.zeros((x_max + 1, y_max + 1))
    zmap[points[:, 0], points[:, 1]] = points[:, 2] # mapping all the z point into the y axis -- z-map, get the height of the part
    return zmap


def read_zmap(filename):
    img = cv2.imread(filename, cv2.IMREAD_UNCHANGED)
    if len(img.shape) > 2:
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    return img


def save_zmap(filename, zmap):
    zmap = zmap.astype(np.uint16)
    cv2.imwrite(filename, zmap)


def show_zmap(zmap):
    plt.figure()
    plt.imshow(zmap, cmap='jet')
    plt.colorbar()
    plt.show()


def fill_zmap(zmap, size=5):
    kernel = np.ones((size, size), np.uint8)
    '''
    Erosion and Dilation:
    erosion removes white noises, but it also shrinks our object. So we dilate it. Since noise is gone, 
    Closing is reverse of Opening, Dilation followed by Erosion. 
    It is useful in closing small holes inside the foreground objects, or small black points on the object.
    '''
    closing = cv2.morphologyEx(zmap, cv2.MORPH_CLOSE, kernel) #remove the noise
    return closing.astype(np.uint16)


def erode_zmap(zmap, size=10, iterations=1):
    kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (size, size))
    erosion = cv2.erode(zmap, kernel, iterations=iterations)
    return erosion


def contours_zmap(zmap, thr=100):
    img_thr = np.zeros(zmap.shape, np.uint8)
    if type(thr) is tuple:
        thrs = np.logical_and(zmap > thr[0], zmap < thr[1])
    else:
        thrs = zmap > thr
    img_thr[thrs] = 255
    contours, hierarchy = cv2.findContours(
        img_thr.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    return contours


def approx_contours(contours, epsilon=1):
    return [cv2.approxPolyDP(contour, epsilon, True) for contour in contours]


def draw_contours(zmap, contours, color=(255, 0, 0), size=None):
    if zmap.dtype == np.uint16:
        img = (zmap / 256).astype(np.uint8)
    else:
        img = zmap.copy()
    if size is None:
        size = int(np.round(float(img.shape[0]) / 512))
    if len(img.shape) < 3 and type(color) != int:
        img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
    cv2.drawContours(img, contours, -1, color, size)
    return img


def hull_contour(contours, area=1000):
    contour = np.vstack(contours)
    if cv2.contourArea(contour) > area:
        contour = cv2.convexHull(contour)
        contour = cv2.approxPolyDP(contour, 1.0, True)
    return contour


class Segmentation:
    def __init__(self):
        self.contours = []
        self.zmap = None

    def on_select(self, xmin, xmax):
        print(xmin, xmax)
        xmin = int(round(xmin))
        xmax = int(round(xmax))
        self.rect.set_xy((xmin, 0))
        self.rect.set_width(xmax-xmin)
        if xmin == xmax:
            self.ax1.imshow(self.zmap)
        else:
            self.contours = contours_zmap(self.zmap, thr=(xmin, xmax))
            img = draw_contours(self.zmap, self.contours, color=(255, 0, 0), size=2)
            self.ax1.imshow(img)
        self.fig.canvas.draw()

    def plot_zmap(self, zmap):
        self.zmap = zmap
        '''
        Bases: matplotlib.gridspec.GridSpecBase
        Specifies the geometry of the grid that a subplot can be placed in.
        The location of grid is determined by similar way as the SubplotParams.
        The number of rows and number of columns of the grid need to be set. 
        Optionally, the subplot layout parameters (e.g., left, right, etc.) can be tuned.
        '''
        gs = gridspec.GridSpec(5, 1)
        self.fig = plt.figure(figsize=(8, 6))
        self.ax1 = self.fig.add_subplot(gs[:4, :])
        self.ax1.imshow(zmap)
        self.ax1.axes.get_xaxis().set_visible(False)
        self.ax1.axes.get_yaxis().set_visible(False)
        self.ax2 = self.fig.add_subplot(gs[4, :])
        #generate histogram
        
        self.ax2.hist(
            zmap.flatten(), 100, range=(0, zmap.max()), fc='k', ec='k')
        '''
        self.ax2.hist(
            zmap.flatten(), 100, range=(0, zmap.max()), fc='k', ec='k')
        '''
        self.ax2.axes.get_yaxis().set_visible(False)
        self.rect = Rectangle(
            (0, 0), 0, self.ax2.get_ylim()[1], alpha=.2, color=(1, 0, 0))
        self.ax2.add_patch(self.rect)
        self.span = SpanSelector(
            self.ax2, self.on_select, 'horizontal', useblit=True,
            rectprops=dict(alpha=0.5, facecolor='red'))
        plt.show()


def slice_of_contours(zmap, contours, scale=10):
    slice = []
    for contour in contours:
        points = contour.reshape((-1, 2))
        points = [[y, x, zmap[y, x]] for x, y in points]
        points.append(points[0])
        points = np.array(points, np.float)
        slice.append((1. / scale) * points)
    return slice


def lines_of_surface(zmap, lines, scale=10, step=5):
    zlines = []
    for line in lines:
        zline = []
        line = np.round(line * scale)
        dist = line[1, 1] - line[0, 1]
        steps = np.abs(np.round(dist / (step * scale))) + 1
        ypoints = np.linspace(line[0, 1], line[1, 1], steps)
        for ypoint in ypoints:
            x = int(line[0, 0])
            y = int(ypoint)
            z = zmap[x, y]
            zline.append(np.array([x, y, z]))
        zline = (1. / scale) * np.array(zline)
        zlines.append(zline)
    return np.array(zlines)


def show_path_from_slice(slice):
    import time
    from planning.planning import Planning
    from planning.mlabplot import MPlot3D
    from planning.polyline import filter_polyline

    t0 = time.time()
    planning = Planning()
    slice = [filter_polyline(polyline, dist=0.3) for polyline in slice]
    path = planning.get_path_from_slices([slice], 0.8)
    t1 = time.time()
    print('Time for path:', t1 - t0)

    # # Get path with frames
    # _path = []
    # for position, orientation, process in path:
    #    frame, t = calc.quatpose_to_pose(position, orientation)
    #    _path.append([position, frame, process])

    mplot3d = MPlot3D()
    mplot3d.draw_slice(slice)
    mplot3d.draw_path(path)
    mplot3d.show()


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('-d', '--data', type=str,
                        default='../../data/cylinder1.xyz',
                        help='path to input xyz cloud file')
    parser.add_argument('-t', '--threshold', type=int,
                        default=100, help='threshold value for contours')
    args = parser.parse_args()
    filename = args.data
    threshold = args.threshold

    name, extension = os.path.splitext(filename)
    if extension == '.pcd':
        pcd_to_xyz(filename)
    if extension == '.xyz':
        xyz_to_pcd(filename)

    cloud = read_cloud(filename)
    zmap = zmap_from_cloud(cloud)
    zmap = fill_zmap(zmap, size=7)

    filename = '%s.png' % name
    save_zmap(filename, zmap)
    show_zmap(zmap)

    #zmap = read_zmap(filename)
    zmap = fill_zmap(zmap, size=7)

    segmentation = Segmentation()
    segmentation.plot_zmap(zmap)
    #contours = approx_contours(segmentation.contours, epsilon=2)
    #contours = [hull_contour(segmentation.contours, area=1000)]
    slice = slice_of_contours(zmap, segmentation.contours)
    print('Slice', slice)
    #show_path_from_slice(slice)

    contours = approx_contours(segmentation.contours, epsilon=3)
    img = draw_contours(zmap, contours, color=(255, 0, 0), size=2)
    #contour = hull_contour(contours, area=1500)
    #img = draw_contours(zmap, [contour], color=(255, 0, 0), size=2)

    plt.figure()
    plt.subplot(121)
    plt.imshow(zmap)
    plt.subplot(122)
    plt.imshow(img)
    plt.show()

    from planning.planning import Planning

    planning = Planning()
    path = planning.get_path_from_slices([slice], track_distance=1.3, focus=0)
    lines = planning.get_grated(slice, 1.3)
    surf_lines = lines_of_surface(zmap, lines)
    print(surf_lines)
    # TODO: Merge function for translate lines (polyline) to path
    #path = planning.get_path_from_fill_lines(surf_lines)
    path = []
    for line in surf_lines:
        for point in line[:-1]:
            path.append([point, planning.orientation, True])
        path.append([line[-1], planning.orientation, False])
    print(path)

    from planning.mlabplot import MPlot3D

    mplot3d = MPlot3D()
    mplot3d.draw_slice(slice)
    mplot3d.draw_path(path)
    mplot3d.show()
