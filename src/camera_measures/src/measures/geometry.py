import cv2
import numpy as np


class Geometry():
    def __init__(self, threshold=127):
        self.threshold = threshold # set the defult threshold value when initialzing the Geometry

    def binarize(self, frame):
        img_bin = np.zeros(frame.shape, dtype=np.uint8)
        img_bin[frame > self.threshold] = 255
        return img_bin

    def find_contour(self, frame):
        # _, contours, _ = cv2.findContours(
        #     frame, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        contours, _ = cv2.findContours(
            frame, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        cnt = None
        if len(contours) > 0:
            areas = [cv2.contourArea(contour) for contour in contours]
            if np.max(areas) > 5:
                cnt = contours[np.argmax(areas)]
                # np.argmax Returns the indices of the maximum values along an axis.
                #areas = np.delete(areas, np.argmax(areas))
                #if np.max(areas) > 5:
                #  cnt = contours[np.argmax(areas)]
        return cnt

    def mask(self,frame):
        # Create the basic black image 
        mask = np.zeros(shape = frame.shape, dtype = "uint8")

        # Draw a white, filled circle on the mask image
        # cv2.circle(image, center_coordinates, radius, color, thickness)
        cv2.circle(mask, (382,228), 55, (255, 255, 255),110)
        # for camera 0
        #cv2.circle(mask, (640,360), 100, (255, 255, 255),200)

        # Apply the mask and display the result
        maskedImg = cv2.bitwise_and(src1 = frame, src2 = mask)

        return maskedImg
	        

    def find_ellipse(self, frame):
        cnt = self.find_contour(frame)
        axis, angle, center = (0, 0), 0, (0, 0)
        if cnt is not None:
            if len(cnt) > 4:
                ellipse = cv2.fitEllipse(cnt)
                (x, y), (h, v), angle = ellipse
                center = (x, y)
                if h >= v:
                    axis = (h, v)
                    angle = np.deg2rad(angle)
                else:
                    axis = (v, h)
                    angle = np.deg2rad(angle-90)
        return center, axis, angle
    
    
    
    def find_maxcircle (self, frame):                                     # added 20200610
        # y = 220; h = 80; x = 350; w = 80
        # crop_frame = frame[y:y+h, x:x+w]
        cnt = self.find_contour(frame)
        center, radius = (0, 0), 0
        if cnt is not None:
            if len(cnt) > 4:
                # Calculate the distances to the contour
                # define an array, to store the distance for each point to the countour
                raw_dist = np.empty(frame.shape, dtype=np.float32)
                # loop every point, calculate dist to the countour
                
                for i in range(frame.shape[0]):
                    for j in range(frame.shape[1]):
                        raw_dist[i,j] = cv2.pointPolygonTest(cnt, (j,i), True)
         
                
                # for i in range(350,430):
                #     for j in range(220,300):
                #         raw_dist[i,j] = cv2.pointPolygonTest(cnt, (j,i), True)
                
                # raw_dist = np.nan_to_num(raw_dist)
                
            
                
                # get the radius and center of the circle
                _, maxVal, _, maxDistPt = cv2.minMaxLoc(raw_dist)
                
                # rospy.loginfo(maxDistPt)


                maxVal = abs(maxVal)
                
                result = cv2.cvtColor(frame,cv2.COLOR_GRAY2BGR)
                
                # the maximum distance to the countour is the center point of the circle
                center = maxDistPt
                radius = maxVal
                
                # cv2.circle(result,center, radius,(0,255,0), 2, cv2.LINE_8, 0)
                
        return center, radius



    def find_geometry(self, frame):
        # first, mask the frame into a circle
        img_masked = self.mask(frame)

        # second, binarize the frame (1,0)
        img_bin = self.binarize(img_masked)

        # second find the contour of the image
        #third, fit the ellipse into the contour.
        # center, axis, angle = self.find_ellipse(img_masked)
        center, axis, angle = self.find_ellipse(img_bin)
        return center, axis, angle
    
    
    
    def find_circular_geometry (self, frame):                            # added 20200610
        img_masked = self.mask(frame)

        # second, binarize the frame (1,0)
        img_bin = self.binarize(img_masked)
        
        # crop the frame  
        # y = 220; h = 80; x = 350; w = 80
        y = 190; h = 120; x = 300; w = 120
        crop_frame = img_bin[y:y+h, x:x+w]

        center, radius = self.find_maxcircle(crop_frame)
        
        diameter = 2 * radius
        circle_center = [0,0]
        circle_center[0] = center[0] + x
        circle_center[1] = center[1] + y
        center = tuple(circle_center)
            
        return center, diameter, radius
        

    def draw_geometry(self, frame, ellipse):
        center, axis, angle = ellipse
        center = (int(round(center[0])), int(round(center[1])))
        axis = (int(round(axis[0]/2)), int(round(axis[1]/2)))
        # cv2.ellipse(img, center, axes, angle, startAngle, endAngle, color[, thickness[, lineType[, shift]]]) 
        cv2.ellipse(
            frame, center, axis, np.rad2deg(angle), 0, 360, (255, 0, 0), 4)
        
        #center, axis, angle = np.float32(cv2.cv.BoxPoints((center, axis, np.rad2deg(angle)))
        #center, axis, angle = cv2.minAreaRect(box)
        # calculate the minor axis length and major axis length
        Max = axis[0]  * np.cos(angle)
        May = axis[0]  * np.sin(angle)
        max = axis[1]  * np.sin(angle)
        may = axis[1]  * np.cos(angle)
        
        # calculate the four vertices for the ellipse
        
        M1x = int(center[0] + Max)
        M1y = int(center[1] + May)
        M2x = int(center[0] - Max)
        M2y = int(center[1] - May)
        m1x = int(center[0] - max)
        m1y = int(center[1] + may)
        m2x = int(center[0] + max)
        m2y = int(center[1] - may)
        

                                              
        # Draw a diagonal blue line with thickness of 5 px
        cv2.line(frame, (M1x,M1y), (M2x,M2y), (0,0,255), 5)
        cv2.line(frame, (m1x,m1y), (m2x,m2y), (0,0,255), 5)
        return frame
    
    
    def draw_circlular_geometry(self, frame, circle):
        center, diameter, radius = circle
        center = (int(round(center[0])), int(round(center[1])))
        radius = (int(round(radius)))
        
        
        cv2.circle(frame, center, radius, (0,0,0), 2, cv2.LINE_8, 0)
        
        return frame




if __name__ == '__main__':
    import matplotlib.pyplot as plt

    img = cv2.imread('../../data/frame0000.jpg')
    frame = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    geometry = Geometry(127)
    ellipse = geometry.find_geometry(frame)
    print ellipse

    img = cv2.resize(img, (frame.shape[0] * 10, frame.shape[1] * 10))
    center = (ellipse[0][0] * 10, ellipse[0][1] * 10)
    axis = (ellipse[1][0] * 10, ellipse[1][1] * 10)
    angle = ellipse[2]

    frame1 = geometry.draw_geometry(img, (center, axis, angle))

    img = cv2.imread('../../data/frame0001.jpg')
    frame = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ellipse = geometry.find_geometry(frame)
    print ellipse

    frame2 = geometry.draw_geometry(img, ellipse)

    plt.figure()
    plt.subplot(121)
    plt.imshow(cv2.cvtColor(frame1, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.subplot(122)
    plt.imshow(cv2.cvtColor(frame2, cv2.COLOR_BGR2RGB), interpolation='none')
    plt.show()
