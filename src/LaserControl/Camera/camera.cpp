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
   

    VideoCapture capture(1); // open the default camera

    namedWindow( "Image View", 1 );

    for(;;)
    {
        
        Mat view;
        capture >> view;

        if( capture.isOpened() )
        {
           
            if(view.empty())
                continue;

           
            imshow("Image View", view);
            
       }
                
        char c = (char)waitKey(10);
        if( c == 27 || c == 'q' || c == 'Q' )
            break;
    }
    return 0;
}

