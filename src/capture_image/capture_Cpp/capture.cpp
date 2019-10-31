#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdio>
#include <stdio.h> 


using namespace cv;



// Add cameraMatrix value collected from calibration result(out_camera_data.xml)
Mat cameraMatrix = (Mat1d(3, 3) << 1540.327686, 0, 586.968869, 0, 1481.131772, 146.133097, 0, 0, 1);

// Mat distortionCoefficients = (Mat1d(1, 4) << k1, k2, p1, p2);
Mat distCoeffs = (Mat1d(1, 5) << -0.525810, 0.155044, 0.034605, 0.003541, 0);
// Mat distortionCoefficients = (Mat1d(1, 8) << k1, k2, p1, p2, k3, k




/* 
<camera_matrix type_id="opencv-matrix">
  <rows>3</rows>
  <cols>3</cols>
  <dt>d</dt>
  <data>
    1.2215597474910767e+03 0. 640. 0. 1.2215597474910767e+03 360. 0. 0.
    1.</data></camera_matrix>
<distortion_coefficients type_id="opencv-matrix">
  <rows>5</rows>
  <cols>1</cols>
  <dt>d</dt>
  <data>
    -4.3917185340178994e-01 -4.2213574486696754e-03 0. 0.
    4.2183898046983598e-01</data></distortion_coefficients>
    */

using namespace cv;
using namespace std;

/* void loadUndistortedImage(std::string fileName, Mat & outputImage, 
    Mat & cameraMatrix, Mat & distCoeffs) {

    Mat image = imread(fileName, CV_LOAD_IMAGE_GRAYSCALE);

    // setup enlargement and offset for new image
    double y_shift = 60;
    double x_shift = 70;
    Size imageSize = image.size();
    imageSize.height += 2*y_shift;
    imageSize.width += 2*x_shift;

    // create a new camera matrix with the principal point 
    // offest according to the offset above
    Mat newCameraMatrix = cameraMatrix.clone();
    newCameraMatrix.at<double>(0, 2) += x_shift; //adjust c_x by x_shift
    newCameraMatrix.at<double>(1, 2) += y_shift; //adjust c_y by y_shift

    // create undistortion maps
    Mat map1;
    Mat map2;
    initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(), 
        newCameraMatrix, imageSize, CV_16SC2, map1, map2);

    //remap
    remap(image, outputImage, map1, map2, INTER_LINEAR);
}*/

int main(int, char* argv[])
{
    
    Size imageSize;

    VideoCapture capture(0); // open the default camera

    namedWindow( "Image View", 1 );

    for(;;)
    {
        
        Mat view, undistortedView, map1, map2; // define original view, undistorted view matrix for remap the coefficient)
        capture >> view;

        if( capture.isOpened() )
        {
            
        
            imageSize = view.size();


            initUndistortRectifyMap(cameraMatrix, distCoeffs, Mat(),
                                    getOptimalNewCameraMatrix(cameraMatrix, distCoeffs, imageSize, 1, imageSize, 0),
                                    imageSize, CV_16SC2, map1, map2); 


    
            if(view.empty())
                continue;
            //undistort( view, rview, cameraMatrix, distCoeffs, cameraMatrix );
            remap(view, undistortedView, map1, map2, INTER_LINEAR);
            imshow("Image View", undistortedView);
            
       }
                
        char c = (char)waitKey(10);
        if( c == 27 || c == 'q' || c == 'Q' )
            break;
    }
    return 0;
}
