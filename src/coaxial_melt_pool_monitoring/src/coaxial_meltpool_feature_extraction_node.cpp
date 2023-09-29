#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "coaxial_melt_pool_monitoring/MsgCoaxialMeltPoolFeatures.h" // Replace with actual package name

class FeatureExtractionNode {
private:
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber image_sub_;
    image_transport::Publisher image_general_contour_pub_;
    image_transport::Publisher image_convex_hull_pub_;
    image_transport::Publisher image_moment_pub_;
    ros::Publisher feature_pub_;

    std::string image_topic_;
    int threshold_;


public:
    FeatureExtractionNode() : it_(nh_) {
        // Initialize parameters
        nh_.param<std::string>("image", image_topic_, "/pylon_camera_node/image_raw");
        nh_.param<int>("threshold", threshold_, 235);

        // Initialize publishers
        feature_pub_ = nh_.advertise<coaxial_melt_pool_monitoring::MsgCoaxialMeltPoolFeatures>("coaxial_melt_pool_features", 10);
        image_general_contour_pub_ = it_.advertise("image_general_contour", 5);
        image_convex_hull_pub_ = it_.advertise("image_convex_hull", 5);
        image_moment_pub_ = it_.advertise("image_moment_extract", 5);

        // Initialize subscriber
        image_sub_ = it_.subscribe(image_topic_, 10, &FeatureExtractionNode::imageCallback, this);
    }

    std::vector<double> generalContourFeatures(const sensor_msgs::ImageConstPtr& msg, const std::string& input_frame_from_msg)
    {
        std::vector<double> features;
        try{
            // Convert the image into something opencv can handle.
            cv::Mat frame = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8)->image;

            cv::Mat gray, threshold_output;

            if (frame.channels() > 1) {
                cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            } else {
                gray = frame;
            }
            cv::blur(gray, gray, cv::Size(3, 3));
            
            cv::threshold(gray, threshold_output, threshold_, 255, cv::THRESH_BINARY);

            int max_thresh = 255;
            std::vector<std::vector<cv::Point> > contours;
            std::vector<cv::Vec4i> hierarchy;
            cv::RNG rng(12345);
                    
             /// Find contours, note the ouput "contours" is a vector of points
            cv::findContours(threshold_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
            // ------------empty drawing----------------------------------
            cv::Mat drawing = cv::Mat::zeros(threshold_output.size(), CV_8UC3);

            //------ do the following only if the contour exists
            if (!contours.empty())
            {
                /// Find the rotated rectangles and ellipses for each contour
                std::vector<cv::RotatedRect> min_rect(contours.size());
                std::vector<cv::RotatedRect> min_ellipse(contours.size());
                std::vector<double> contour_area(contours.size());

                for (size_t i = 0; i < contours.size(); i++)
                {
                min_rect[i] = cv::minAreaRect(cv::Mat(contours[i]));
                contour_area[i] = cv::contourArea	(cv::Mat(contours[i]));
                
                if (contours[i].size() > 5)
                {
                    min_ellipse[i] = cv::fitEllipse(cv::Mat(contours[i]));
                } 
                
                }

                /// Get the max contour area, and its corresponding ellipse and rectangle
                int max_contour_area_index = std::max_element(contour_area.begin(),contour_area.end()) - contour_area.begin();
                float max_contour_area = *std::max_element(contour_area.begin(), contour_area.end());
                features.push_back(max_contour_area);
                features.push_back(min_rect[max_contour_area_index].angle);
                // features.push_back(min_rect[max_contour_area_index].center.x);
                // features.push_back(min_rect[max_contour_area_index].center.y);
                features.push_back(min_rect[max_contour_area_index].size.width);
                features.push_back(min_rect[max_contour_area_index].size.height);
                features.push_back(min_ellipse[max_contour_area_index].angle);
                // features.push_back(min_ellipse[max_contour_area_index].center.x);
                // features.push_back(min_ellipse[max_contour_area_index].center.y);
                features.push_back(min_ellipse[max_contour_area_index].size.width);
                features.push_back(min_ellipse[max_contour_area_index].size.height);

                cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
                // contour
                // ellipse
                cv::ellipse(drawing, min_ellipse[max_contour_area_index], color, 2, 8);
                // rotated rectangle
                cv::Point2f rect_points[4];
                min_rect[max_contour_area_index].points(rect_points);
                for (int j = 0; j < 4; j++)
                cv::line(drawing, rect_points[j], rect_points[(j + 1) % 4], color, 1, 8);
            }
            else{
                // ---------------------publish zero or NaN---------------------
                features.push_back(0);
                features.push_back(0);
                // features.push_back(min_rect[max_contour_area_index].center.x);
                // features.push_back(min_rect[max_contour_area_index].center.y);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                // features.push_back(min_ellipse[max_contour_area_index].center.x);
                // features.push_back(min_ellipse[max_contour_area_index].center.y);
                features.push_back(0);
                features.push_back(0);
            }

            // Publish the image
            sensor_msgs::ImagePtr out_img = 
                cv_bridge::CvImage(msg->header, sensor_msgs::image_encodings::BGR8, drawing).toImageMsg();
            image_general_contour_pub_.publish(out_img);

        }catch (cv_bridge::Exception& e)
        {
            ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
        }

        return features;
    }


    std::vector<double> convexHullFeatures(const sensor_msgs::ImageConstPtr& msg, const std::string& input_frame_from_msg)
    {
        std::vector<double> features;
        try{
            // Convert the image into something opencv can handle.
            cv::Mat frame = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8)->image;

            cv::Mat gray, threshold_output;
            if (frame.channels() > 1) {
                cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            } else {
                gray = frame;
            }

            cv::blur(gray, gray, cv::Size(3, 3));
            cv::threshold(gray, threshold_output, threshold_, 255, cv::THRESH_BINARY);

            std::vector<std::vector<cv::Point>> contours;
            std::vector<cv::Vec4i> hierarchy;
            cv::RNG rng(12345);
            int max_thresh = 255;

            cv::findContours(threshold_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

            //-------------empty drawing---------------------
            cv::Mat drawing = cv::Mat::zeros(threshold_output.size(), CV_8UC3);

            /// --------- do the following only if there is a contour --------------
            if (!contours.empty()) {
                /// Find the convex hull object for each contour
                std::vector<std::vector<cv::Point> > hull(contours.size());
                // Find the bounding convex hull area for each contour
                std::vector<double> hull_area(contours.size());

                for (size_t i = 0; i < contours.size(); i++) {
                    cv::convexHull(cv::Mat(contours[i]), hull[i], false);
                    hull_area[i] = cv::contourArea(cv::Mat(hull[i]));
                }

                // Get the max hull area
                /// Get the max contour area, and its corresponding ellipse and rectangle
                int max_contour_area_index = std::max_element(hull_area.begin(),hull_area.end()) - hull_area.begin();
                features.push_back(hull_area[max_contour_area_index]);
                cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
                // cv::drawContours(drawing, contours, (int)max_contour_area_index, color, 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
                cv::drawContours(drawing, hull, (int)max_contour_area_index, color, 4, 8, std::vector<cv::Vec4i>(), 0, cv::Point());

                
            } else {
                // If no contours are found, push 0 as max_hull_area
                features.push_back(0);
            }

            // Publish the image.
            sensor_msgs::ImagePtr out_img = 
                cv_bridge::CvImage(msg->header, sensor_msgs::image_encodings::BGR8, drawing).toImageMsg();
            image_convex_hull_pub_.publish(out_img);


        }
        catch (cv_bridge::Exception& e)
        {
            ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
        }

        return features;
    }

    
    // comparison function object
    static bool compareContourAreas(const std::vector<cv::Point>& contour1, const std::vector<cv::Point>& contour2)
    {
        // https://stackoverflow.com/questions/13495207/opencv-c-sorting-contours-by-their-contourarea
        double i = fabs(contourArea(cv::Mat(contour1)));
        double j = fabs(contourArea(cv::Mat(contour2)));
        return (i > j);
    }


    std::vector<double> momentFeatures(const sensor_msgs::ImageConstPtr& msg, const std::string& input_frame_from_msg)
    {
        std::vector<double> features;
        try {
            // Convert the image into something opencv can handle.
            cv::Mat frame = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8)->image;

            cv::Mat gray, threshold_output;
            if (frame.channels() > 1) {
                cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            } else {
                gray = frame;
            }

            cv::blur(gray, gray, cv::Size(3, 3));
            cv::threshold(gray, threshold_output, threshold_, 255, cv::THRESH_BINARY);

            std::vector<std::vector<cv::Point>> contours;
            std::vector<cv::Vec4i> hierarchy;
            cv::RNG rng(12345);

            cv::findContours(threshold_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

            cv::Mat drawing;
        
            // drawing = cv::Mat::zeros(canny_output.size(), CV_8UC3);
            drawing = cv::Mat::zeros(threshold_output.size(), CV_8UC3);
            



            if (!contours.empty()) {

                // https://stackoverflow.com/questions/13495207/opencv-c-sorting-contours-by-their-contourarea
                std::sort(contours.begin(), contours.end(), compareContourAreas);

                std::vector<cv::Moments> mu(contours.size());
                std::vector<cv::Point2f> mc(contours.size());
                
                /// Get the moments
                for (size_t i = 0; i < contours.size(); i++)
                {
                    mu[i] = moments(contours[i], false);
                }

                ///  Get the mass centers:
                for (size_t i = 0; i < contours.size(); i++)
                {
                    mc[i] = cv::Point2f(static_cast<float>(mu[i].m10 / mu[i].m00), static_cast<float>(mu[i].m01 / mu[i].m00));
                }
                
                int index = 0; // the area has already been sorted, 0-largest, contours.size()-1: smallest area
                features.push_back(mu[index].m00);
                features.push_back(mu[index].m10);
                features.push_back(mu[index].m01);
                features.push_back(mu[index].m20);
                features.push_back(mu[index].m11);
                features.push_back(mu[index].m02);
                features.push_back(mu[index].m30);
                features.push_back(mu[index].m21);
                features.push_back(mu[index].m12);
                features.push_back(mu[index].m03);
                features.push_back(mu[index].mu20);
                features.push_back(mu[index].mu11);
                features.push_back(mu[index].mu02);
                features.push_back(mu[index].mu30);
                features.push_back(mu[index].mu21);
                features.push_back(mu[index].mu12);
                features.push_back(mu[index].mu03);
                features.push_back(mu[index].nu20);
                features.push_back(mu[index].nu11);
                features.push_back(mu[index].nu02);
                features.push_back(mu[index].nu30);
                features.push_back(mu[index].nu21);
                features.push_back(mu[index].nu12);
                features.push_back(mu[index].nu03);
                features.push_back(mc[index].x);
                features.push_back(mc[index].y);
                features.push_back(cv::arcLength(contours[index], true));
                features.push_back(cv::contourArea(contours[index]));
            
                cv::Scalar color = cv::Scalar(rng.uniform(0, 150), rng.uniform(0, 255), rng.uniform(0, 255));
                cv::drawContours(drawing, contours, (int)index, color, 2, 6, hierarchy, 0, cv::Point());
                cv::circle(drawing, mc[index], 4, color, -1, 8, 0);
        
            } else {
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
                features.push_back(0);
            }

            // Publish the image.
            sensor_msgs::ImagePtr out_img = 
                cv_bridge::CvImage(msg->header, sensor_msgs::image_encodings::BGR8, drawing).toImageMsg();
            image_moment_pub_.publish(out_img);
        }
        catch (cv_bridge::Exception& e){
            ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
        }
        return features;
    }

    void imageCallback(const sensor_msgs::ImageConstPtr& msg) {
        try{
            coaxial_melt_pool_monitoring::MsgCoaxialMeltPoolFeatures feature_msg;
            // Extract features from general contours
            std::vector<double> max_contour_feature = generalContourFeatures(msg, msg->header.frame_id);
            std::vector<double> convex_hull_features = convexHullFeatures(msg, msg->header.frame_id);
            std::vector<double> moment_features = momentFeatures(msg, msg->header.frame_id);

            // Populate feature_msg based on max_contour_feature
           
            feature_msg.max_contour_area = max_contour_feature[0];
            feature_msg.rectangle_angle = max_contour_feature[1];
            feature_msg.rectangle_width = max_contour_feature[2];
            feature_msg.rectangle_height = max_contour_feature[3];
            feature_msg.ellipse_angle = max_contour_feature[4];
            feature_msg.ellipse_width = max_contour_feature[5];
            feature_msg.ellipse_height = max_contour_feature[6];

            feature_msg.max_hull_area = convex_hull_features[0];

            feature_msg.max_hull_area = moment_features[0];

            feature_msg.m00 = moment_features[0];
            feature_msg.m10 = moment_features[1];
            feature_msg.m01 = moment_features[2];
            feature_msg.m20 = moment_features[3];
            feature_msg.m11 = moment_features[4];
            feature_msg.m02 = moment_features[5];
            feature_msg.m30 = moment_features[6];
            feature_msg.m21 = moment_features[7];
            feature_msg.m12 = moment_features[8];
            feature_msg.m03 = moment_features[9];
            feature_msg.mu20 = moment_features[10];
            feature_msg.mu11 = moment_features[11];
            feature_msg.mu02 = moment_features[12];
            feature_msg.mu30 = moment_features[13];
            feature_msg.mu21 = moment_features[14];
            feature_msg.mu12 = moment_features[15];
            feature_msg.mu03 = moment_features[16];
            feature_msg.nu20 = moment_features[17];
            feature_msg.nu11 = moment_features[18];
            feature_msg.nu02 = moment_features[19];
            feature_msg.nu30 = moment_features[20];
            feature_msg.nu21 = moment_features[21];
            feature_msg.nu12 = moment_features[22];
            feature_msg.nu03 = moment_features[23];
            feature_msg.center_x = moment_features[24];
            feature_msg.center_y = moment_features[25];
            feature_msg.length = moment_features[26];
            feature_msg.area = moment_features[27];
            
            // Publish features
            feature_pub_.publish(feature_msg);

        }catch (const std::exception& e) {
            ROS_ERROR("Exception caught: %s", e.what());
        } catch (...) {
            ROS_ERROR("Unknown exception caught");
        }

    }

};

int main(int argc, char** argv) {
    ros::init(argc, argv, "coaxial_feature_extraction_node");
    
    FeatureExtractionNode coaxial_feature_extraction_node;
    ros::spin();
    return 0;
}
