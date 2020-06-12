import numpy as np
from measures.geometry import Geometry
import cv2

class Moments():
    def __init__(self, threshold=127):
        self.threshold = threshold

        self.geometry = Geometry(threshold)

    def binarize(self, frame):
        img_bin = np.zeros(frame.shape, dtype=np.uint8)
        img_bin[frame > self.threshold] = 255
        return img_bin

    def levels(self, img, min=0, max=255):
        lut = np.arange(256)
        for k in lut:
            if k <= min:
                lut[k] = 0
            elif k > min and k < max:
                lut[k] = (255. / (max - min)) * (k - min)
            else:
                lut[k] = 255
        lut_levels = np.uint8(lut)
        img = lut_levels[img]
        # self.lut_conv = (np.asarray(range(value))*(256))/value
        # img=self.lut_conv[img]
        return img

    def bounding_box(self, image):
        size = 0
        width, height = image.shape[1], image.shape[0]
        # Boundary box
        left, top = width, height
        right, bottom = 0, 0
        for y in range(height):
            for x in range(width):
                if image[y, x]:
                    size = size + 1
                    if left > x:
                        left = x
                    if top > y:
                        top = y
                    if right < x:
                        right = x
                    if bottom < y:
                        bottom = y
        if size:
            box = [left, top, right, bottom]
        else:
            box = [0, 0, 0, 0]
        return box

    def moments(self, image):
        image = image.astype(np.float32)
        # The shape of an image is accessed by img.shape. It returns a tuple of number of rows, columns, and channels (if image is color)
        width, height = image.shape[1], image.shape[0] # return rows and colums
        xx = np.arange(width).reshape((1, width))
        yy = np.arange(height).reshape((height, 1))
        m00 = np.sum(image)
        m10 = np.sum(xx * image)
        m01 = np.sum(yy * image)
        m11 = np.sum(xx * yy * image)
        m20 = np.sum(xx * xx * image)
        m02 = np.sum(yy * yy * image)
        return [m00, m01, m10, m11, m02, m20]

    def find_ellipse(self, image):
        """Calculates the ellipse approximation of the shape in the image."""
        m00, m01, m10, m11, m02, m20 = self.moments(image)
        x_cm, y_cm, angle, length, width = 0, 0, 0, 0, 0
        if m00 > 1000:
            x_cm = m10 / m00
            y_cm = m01 / m00
            # ---
            u20 = float(m20 / m00 - x_cm * x_cm)
            u02 = float(m02 / m00 - y_cm * y_cm)
            u11 = float(m11 / m00 - x_cm * y_cm)
            lmax = (u20 + u02 + np.sqrt(
                4 * u11 * u11 + (u20 - u02) * (u20 - u02))) / 2
            lmin = (u20 + u02 - np.sqrt(
                4 * u11 * u11 + (u20 - u02) * (u20 - u02))) / 2
            # ---
            angle = np.arctan((2 * u11) / (u20 - u02 + 0.0000001)) / 2
            length = 4 * np.sqrt(lmax)
            width = 4 * np.sqrt(lmin)
        return (x_cm, y_cm), (length, width), angle

    def find_geometry(self, frame):
        img_masked = self.geometry.mask(frame)
        img_bin = self.binarize(img_masked)

        # center, axis, angle = self.find_ellipse(img_bin)

        contours, _ = cv2.findContours(
            frame, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        if len(contours) > 0:
            areas = [cv2.contourArea(contour) for contour in contours]
            if np.max(areas) > 1000:
                center, axis, angle = self.find_ellipse(img_bin)

        return center, axis, angle
            
        
        #return center, axis, angle


if __name__ == '__main__':
    import cv2
    import matplotlib.pyplot as plt
    from matplotlib.patches import Ellipse

    img = cv2.imread('../../data/frame0000.jpg')
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    moments = Moments(127)
    img_bin = moments.binarize(img)
    center, axis, angle = moments.find_ellipse(img_bin)
    print center, axis, angle

    img_pix = moments.levels(img, 63, 191)
    pellipse = moments.find_ellipse(img_pix)
    print pellipse

    left, top, right, bottom = moments.bounding_box(img)
    print right - left, bottom - top

    plt.figure()
    plt.subplot(221)
    plt.imshow(img_bin, cmap='gray')
    plt.axis('off')
    plt.subplot(222)
    plt.imshow(img_pix, cmap='gray')
    plt.axis('off')
    plt.subplot(223)
    plt.imshow(img_bin, cmap='gray')
    plt.axis('off')
    plt.gca().add_patch(Ellipse(center, axis[0], axis[1],
                                angle=np.rad2deg(angle),
                                facecolor='none', edgecolor='red', lw=1.5))
    plt.subplot(224)
    plt.imshow(img_pix, cmap='gray')
    plt.axis('off')
    plt.gca().add_patch(Ellipse(pellipse[0], pellipse[1][0], pellipse[1][1],
                                angle=np.rad2deg(pellipse[2]),
                                facecolor='none', edgecolor='red', lw=1.5))
    plt.show()
