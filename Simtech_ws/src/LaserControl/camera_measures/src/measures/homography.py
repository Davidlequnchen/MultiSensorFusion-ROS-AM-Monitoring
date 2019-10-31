import cv2
import yaml
import numpy as np


class Homography():
    def __init__(self):
        self.hom = np.eye(3)
        self.inv = np.eye(3)

    def load(self, filename):
        with open(filename, 'r') as f:
            data = yaml.load(f)
        self.hom = np.array(data['hom'])
        self.inv = np.linalg.inv(self.hom)
        return self.hom

    def save(self, filename):
        data = {'hom': self.hom.tolist()}
        with open(filename, 'w') as f:
            yaml.dump(data, f)
        return self.hom

    def calculate(self, points, pixels):
        """Calculates the transformation from pixels to real coordinates."""
        self.hom, status = cv2.findHomography(pixels, points)
        self.inv = np.linalg.inv(self.hom)
        return self.hom

    def scale(self, hom):
        return np.mean([hom[0, 0], hom[1, 1]])

    def transform(self, pixels):
        """Transforms pixels to points."""
        pnts = np.float32([
            np.dot(self.hom, np.array([pnt[0], pnt[1], 1])) for pnt in pixels])
        points = np.float32([pnt[:2] / pnt[2] for pnt in pnts])
        return points

    def project(self, points):
        """Projects points as pixels."""
        pnts = np.float32([
            np.dot(self.inv, np.array([pnt[0], pnt[1], 1])) for pnt in points])
        pixels = np.float32([pnt[:2] / pnt[2] for pnt in pnts])
        return pixels


if __name__ == '__main__':
    points = np.float32([[-2.5, -2.5], [2.5, -2.5], [-2.5, 2.5], [2.5, 2.5]])
    pixels = np.float32([[8, 7], [25, 6], [9, 24], [25, 23]])

    pattern_points = np.float32([[0, 0], [6, 0], [0, 6], [6, 6]])
    image_points = np.float32([[8, 7], [25, 6], [9, 24], [25, 23]])

    h = Homography()
    hom = h.calculate(pattern_points, image_points)

    print hom, h.scale(hom)
    print np.around(h.transform(image_points), decimals=4)
    print np.around(h.project(pattern_points), decimals=4)
