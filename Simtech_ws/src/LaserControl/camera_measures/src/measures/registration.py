import cv2
import numpy as np

from projection import Projection
from homography import Homography

from tachyon.tachyon import LUT_IRON

RED = (0, 0, 255)
GREEN = (0, 255, 0)
BLUE = (255, 0, 0)
ORANGE = (0, 128, 255)
YELLOW = (0, 255, 255)
MAGENTA = (255, 0, 255)
MAROON = (0, 0, 128)
BLACK = (0, 0, 0)
GRAY = (128, 128, 128)
WHITE = (255, 255, 255)

SIZE = 500


class Registration():
    def __init__(self):
        self.speed = 0
        self.velocity = (0, 0, 0)
        self.ellipse = (0, 0), (0, 0), 0

        self.p_camera = Projection()
        self.p_tachyon = Projection()

        self.img_camera = None
        self.img_tachyon = None

        self.hom = Homography()
        points = np.float32([[-2.5, -2.5], [2.5, -2.5], [-2.5, 2.5], [2.5, 2.5]])
        pixels = np.float32([[0, 0], [0, SIZE], [SIZE, 0], [SIZE, SIZE]])
        self.hom.calculate(points, pixels)

    def draw_points(self, image, pnts):
        pixels = self.hom.project(pnts)
        for pnt in pixels:
            cv2.circle(image, (int(pnt[0]), int(pnt[1])), 3, BLUE, -1)
        return image

    def draw_circle(self, image, color=GRAY):
        cr, cc = self.hom.project([[0, 0]])[0]
        r = self.hom.project([[0, 2.5]])[0][1]
        cv2.circle(image, (cc, cr), r, color, thickness=5, lineType=8)
        return image

    def draw_axis(self, image):
        points = self.hom.project(np.float32([[0, 0], [1, 0], [0, 1]]))
        pnt0, pnt1, pnt2 = points[0], points[1], points[2]
        cv2.line(image, (pnt0[0], pnt0[1]), (pnt1[0], pnt1[1]), RED, 2)
        cv2.line(image, (pnt0[0], pnt0[1]), (pnt2[0], pnt2[1]), GREEN, 2)
        cv2.circle(image, (int(pnt0[0]), int(pnt0[1])), 3, BLUE, -1)
        return image

    def draw_ellipse(self, image, ellipse, color=MAROON):
        center, axis, angle = ellipse
        angle = np.rad2deg(angle)
        box = np.float32(cv2.boxPoints((center, axis, angle)))
        center, axis, angle = cv2.minAreaRect(self.hom.project(box))
        center = (int(round(center[0])), int(round(center[1])))
        axis = (int(round(axis[0]/2)), int(round(axis[1]/2)))
        cv2.ellipse(image, center, axis, angle, 0, 360, color, 2)
        cv2.circle(image, center, 3, color, -1)
        return image

    def draw_arrow(self, image, speed, vel, color=YELLOW):
        if speed > 0:
            if speed <= 10:
                scale = 0.1
            else:
                scale = 0.01
            points = np.float32([[0, 0], [scale * vel[0], scale * vel[1]]])
            points = self.hom.project(points)
            p = (int(points[0][0]), int(points[0][1]))
            q = (int(points[1][0]), int(points[1][1]))
            arrow_magnitude = 10 * scale * speed
            angle = np.arctan2(p[1]-q[1], p[0]-q[0])
            p1 = (int(q[0] + arrow_magnitude * np.cos(angle + np.pi/6)),
                  int(q[1] + arrow_magnitude * np.sin(angle + np.pi/6)))
            p2 = (int(q[0] + arrow_magnitude * np.cos(angle - np.pi/6)),
                  int(q[1] + arrow_magnitude * np.sin(angle - np.pi/6)))
            cv2.line(image, p, q, color, 2)
            cv2.line(image, p1, q, color, 2)
            cv2.line(image, p2, q, color, 2)
        return image

    def paint_images(self):
        image = np.zeros((SIZE, SIZE, 3), dtype=np.uint8)
        if self.img_camera is not None:
            img_camera = cv2.cvtColor(self.img_camera, cv2.COLOR_GRAY2BGR)
            img_camera = self.p_camera.project_image(img_camera)
            image = cv2.addWeighted(image, 1, img_camera, 0.4, 0)
        if self.img_tachyon is not None:
            if len(self.img_tachyon.shape) == 2:
                self.img_tachyon = LUT_IRON[self.img_tachyon]
            img_tachyon = cv2.cvtColor(self.img_tachyon, cv2.COLOR_RGB2BGR)
            img_tachyon = self.p_tachyon.project_image(img_tachyon)
            image = cv2.addWeighted(image, 1, img_tachyon, 0.6, 0)
        image = self.draw_circle(image)
        image = self.draw_axis(image)
        image = self.draw_ellipse(image, self.ellipse)
        image = self.draw_arrow(image, self.speed, self.velocity)
        return image


if __name__ == '__main__':
    import matplotlib.pyplot as plt

    registration = Registration()
    registration.p_camera.load_configuration('../../config/camera.yaml')
    registration.p_tachyon.load_configuration('../../config/tachyon.yaml')
    #registration.img_tachyon = cv2.imread('../../data/frame0000.jpg')
    im_final = registration.paint_images()
    im_final = registration.draw_axis(im_final)

    im_NIT = cv2.imread('../../data/nit_pattern.png')
    im_uEye = cv2.imread('../../data/nir_pattern.png')

    # center, axis, angle = (12, 12), (7, 3), 0
    # center, axis, angle = p_NIT.transform_ellipse(center, axis, angle)
    # im_final = registration.draw_ellipse(im_final, (center, axis, angle))

    plt.figure()
    plt.subplot(121)
    plt.imshow(cv2.cvtColor(im_NIT, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.axis('off')
    plt.subplot(122)
    plt.imshow(cv2.cvtColor(im_uEye, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.axis('off')
    plt.show()

    im_pNIT = registration.p_tachyon.project_image(im_NIT)
    im_pNIT = registration.draw_ellipse(im_pNIT, ((0, 0), (5, 5), np.pi/2))
    im_puEye = registration.p_camera.project_image(im_uEye)
    im_puEye = registration.draw_ellipse(im_puEye, ((0, 0), (5, 5), np.pi/2))

    plt.figure()
    plt.subplot(121)
    plt.imshow(cv2.cvtColor(im_pNIT, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.axis('off')
    plt.subplot(122)
    plt.imshow(cv2.cvtColor(im_puEye, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.axis('off')
    plt.show()

    registration.img_tachyon = cv2.cvtColor(im_NIT, cv2.COLOR_BGR2RGB)
    registration.img_camera = cv2.cvtColor(im_uEye, cv2.COLOR_BGR2GRAY)
    registration.speed = 10
    registration.velocity = (10, -10, 0)
    registration.ellipse = (0, 0), (3, 1), np.pi/4
    im_final = registration.paint_images()

    plt.figure()
    plt.imshow(cv2.cvtColor(im_final, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.show()
