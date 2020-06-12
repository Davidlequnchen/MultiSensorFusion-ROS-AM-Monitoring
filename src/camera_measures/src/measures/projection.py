import cv2
import numpy as np

from homography import Homography


class Projection():
    def __init__(self, config=None, SIZE=500):
        self.hom = Homography()
        self.vis = np.eye(3)
        self.SIZE = SIZE
        if config is not None:
            self.load_configuration(config)

    def load_configuration(self, filename):
        hom = self.hom.load(filename)
        points = np.float32(
            [[-2.5, -2.5], [2.5, -2.5], [-2.5, 2.5], [2.5, 2.5]])
        pixels = np.float32(
            [[0, 0], [0, self.SIZE], [self.SIZE, 0], [self.SIZE, self.SIZE]])
        vis = Homography()
        vis.calculate(points, pixels)
        self.vis = np.dot(vis.inv, hom)

    def transform_ellipse(self, center, axis, angle):
        # TODO: Add box point calculation from ellipse and inverse transform.
        print '-----'
        _center, _axis, _angle = center, axis, angle
        _angle = np.rad2deg(_angle)
        print _center, _axis, _angle
        box = np.float32(cv2.cv.BoxPoints((_center, _axis, _angle)))
        _center, _axis, _angle = cv2.minAreaRect(self.hom.transform(box))
        _angle = np.deg2rad(_angle)
        print _center, _axis, _angle
        #center, axis, angle = _center, _axis, _angle
        print '-----'
        major_u = axis[0] / 2 * np.cos(angle) + center[0]
        major_v = axis[0] / 2 * np.sin(angle) + center[1]
        minor_u = axis[1] / 2 * np.cos(angle) + center[0]
        minor_v = axis[1] / 2 * np.sin(angle) + center[1]
        center = self.hom.transform([center])[0]
        axis = self.hom.transform(np.float32([[major_u, major_v],
                                              [minor_u, minor_v]]))
        axis = axis - center
        length = 2 * np.sqrt(np.sum(axis[0] * axis[0]))
        width = 2 * np.sqrt(np.sum(axis[1] * axis[1]))
        angle = np.arctan2(axis[0][1], axis[0][0])
        axis = (length, width)
        print center, axis, angle
        return center, axis, angle

    def project_image(self, image):
        im_measures = cv2.warpPerspective(
            image, self.vis, (self.SIZE, self.SIZE), flags=cv2.INTER_CUBIC)  #cv2.INTER_LINEAR)
        return im_measures


if __name__ == '__main__':
    import matplotlib.pyplot as plt

    p_NIT = Projection()
    p_NIT.load_configuration('../../config/tachyon.yaml')

    plt.figure()
    plt.subplot(121)
    im_NIT = cv2.imread('../../data/nir_focus.jpg')
    print im_NIT.shape
    plt.imshow(cv2.cvtColor(im_NIT, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.axis('off')
    plt.subplot(122)
    im_NIT = p_NIT.project_image(im_NIT)
    plt.imshow(cv2.cvtColor(im_NIT, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.axis('off')
    plt.show()

    center, axis, angle = (12, 10), (7, 3), 0
    center, axis, angle = p_NIT.transform_ellipse(center, axis, angle)
    print center, axis, angle

    points = np.float32([[-2.5, -2.5], [2.5, -2.5], [-2.5, 2.5], [2.5, 2.5]])
    pixels = np.float32([[8, 7], [25, 6], [9, 24], [25, 23]])
    p_NIT.hom.calculate(points, pixels)
    print np.around(p_NIT.hom.transform(pixels), decimals=4)
    print np.around(p_NIT.hom.project(points), decimals=4)
