import numpy as np
import cv2
import glob


# Define the chess board rows and columns
rows = 9
cols = 6

# dist = np.zeros(4)
# mtx = np.zeros((rows * cols))








def error():
    try :
        error = 0

        for i in range(len(objectPointsArray)):
            imgPoints, _ = cv2.projectPoints(objectPointsArray[i], rvecs[i], tvecs[i], mtx, dist)
            error += cv2.norm(imgPointsArray[i], imgPoints, cv2.NORM_L2) / len(imgPoints)

        print("Total error: ", error / len(objectPointsArray))

    except ZeroDivisionError:
        print("Zero division error")



if __name__ == '__main__':

    # Set the termination criteria for the corner sub-pixel algorithm
    criteria = (cv2.TERM_CRITERIA_MAX_ITER + cv2.TERM_CRITERIA_EPS, 30, 0.001)

    # Prepare the object points: (0,0,0), (1,0,0), (2,0,0), ..., (6,5,0). They are the same for all images
    objectPoints = np.zeros((rows * cols, 3), np.float32)
    objectPoints[:, :2] = np.mgrid[0:rows, 0:cols].T.reshape(-1, 2)

    # Create the arrays to store the object points and the image points
    objectPointsArray = []
    imgPointsArray = []

    # ret, mtx, dist, rvecs, tvecs = calibrate()
    
    # Loop over the image files
    for path in glob.glob('img2/*.jpg'):
        # Load the image and convert it to gray scale
        img = cv2.imread(path)
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # Find the chess board corners
        ret, corners = cv2.findChessboardCorners(gray, (rows, cols), None)

        # Make sure the chess board pattern was found in the image
        if ret:
            # Refine the corner position
            corners = cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)
            
            # Add the object points and the image points to the arrays
            objectPointsArray.append(objectPoints)
            imgPointsArray.append(corners)

            # Draw the corners on the image
            cv2.drawChessboardCorners(img, (rows, cols), corners, ret)

            # Display the image
            cv2.imshow('chessboard', img)
            cv2.waitKey(300)
        
            #Calibrate the camera and save the results
            ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objectPointsArray, imgPointsArray, gray.shape[::-1], None, None)
            np.savez('/data/calib.npz', mtx=mtx, dist=dist, rvecs=rvecs, tvecs=tvecs)


            # Print the camera calibration error
            error()
    
            # Load one of the test images
            # img = cv2.imread('calib_img/1.jpg')
            h, w = img.shape[:2]

            # Obtain the new camera matrix and undistort the image
            newCameraMtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, (w, h), 1, (w, h))


            # method 1: use undistort function
            undistortedImg = cv2.undistort(img, mtx, dist, None, newCameraMtx)


            # method 2: remapping
            # undistort
            # mapx,mapy = cv2.initUndistortRectifyMap(mtx,dist,None,newCameraMtx,(w,h),5)
            # undistortedImg = cv2.remap(img,mapx,mapy,cv2.INTER_LINEAR)

            # crop the image
            x,y,w,h = roi
            undistortedImg = undistortedImg[y:y+h, x:x+w]


        # Display the final result
        # cv2.namedWindow('result')
        cv2.imwrite('result.png',undistortedImg)
        cv2.imshow('chessboard',undistortedImg)
        cv2.waitKey(500)

    cv2.destroyAllWindows()


