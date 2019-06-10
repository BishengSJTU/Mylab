#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\opencv.hpp>
#include "cv.h"
#include "highgui.h"

void drawCoordinate(cv::Mat &color, cv::Mat& Pose);

int main()
{
    cv::Mat srcImage = cv::imread("0106.png");
    cv::Mat ROI;
    ROI = srcImage(cv::Rect(180,100,200,200));
    cv::imwrite("1.png", ROI);


    cv::Mat grayImage;
    cv::cvtColor(srcImage, grayImage, CV_RGB2GRAY);

    cv::imwrite("0106g.png", grayImage);
    cv::Mat srcImage1 = cv::imread("0106g.png");

    cv::Mat pose = cv::Mat::zeros(4, 4, CV_32F);
    pose.at<float>(0, 0) = 0.32490799;
    pose.at<float>(0, 1) = 0.94311500;
    pose.at<float>(0, 2) = -0.07048930;
    pose.at<float>(0, 3) = -0.05115138091;
    pose.at<float>(1, 0) = 0.68514800;
    pose.at<float>(1, 1) = -0.28610301;
    pose.at<float>(1, 2) = -0.66986400;
    pose.at<float>(1, 3) = -0.07902930777;
    pose.at<float>(2, 0) = -0.65192598;
    pose.at<float>(2, 1) = 0.16934800;
    pose.at<float>(2, 2) = -0.73913002;
    pose.at<float>(2, 3) = 0.69317821312;
    pose.at<float>(3, 0) = 0.0;
    pose.at<float>(3, 1) = 0.0;
    pose.at<float>(3, 2) = 0.0;
    pose.at<float>(3, 3) = 1.0;
    drawCoordinate(srcImage1, pose);
    cv::waitKey(0);
    return 0;
}

void drawCoordinate(cv::Mat &color, cv::Mat& Pose)
{
	if (!Pose.data) {
		return;
	}
	//Xtion internal parameters
	float f_x = 572.41140; // focal length in x axis
	float f_y = 573.57043; // focal length in y axis (usually the same?)
	float c_x = 325.26110; // camera primary point x
	float c_y = 242.04899; // camera primary point y

	//internal matrix
	cv::Mat m1 = cv::Mat::zeros(3, 4, CV_32F);
	m1.at<float>(0, 0) = f_x; // Focal length in x axis
	m1.at<float>(1, 1) = f_y; // Focal length in y axis (usually the same?)
	m1.at<float>(0, 2) = c_x; // Camera primary point x
	m1.at<float>(1, 2) = c_y; // Camera primary point y
	m1.at<float>(2, 2) = 1.0;

	cv::Mat x = cv::Mat::ones(4, 4, CV_32F);
	x.at<float>(0,0) = 0.0;
	x.at<float>(1,0) = 0.0;
	x.at<float>(2,0) = 0.0;

	x.at<float>(0,1) = 0.1;
	x.at<float>(1,1) = 0.0;
	x.at<float>(2,1) = 0.0;

	x.at<float>(0,2) = 0.0;
	x.at<float>(1,2) = 0.1;
	x.at<float>(2,2) = 0.0;

	x.at<float>(0,3) = 0.0;
	x.at<float>(1,3) = 0.0;
	x.at<float>(2,3) = 0.1;

	cv::Mat result = cv::Mat::zeros(3, 4, CV_32F);
	result = m1 * Pose * x;

	cv::Point p1 = cv::Point(result.at<float>(0,0)/result.at<float>(2,0),result.at<float>(1,0)/result.at<float>(2,0));
	cv::Point p2 = cv::Point(result.at<float>(0,1)/result.at<float>(2,1),result.at<float>(1,1)/result.at<float>(2,1));
	cv::Point p3 = cv::Point(result.at<float>(0,2)/result.at<float>(2,2),result.at<float>(1,2)/result.at<float>(2,2));
	cv::Point p4 = cv::Point(result.at<float>(0,3)/result.at<float>(2,3),result.at<float>(1,3)/result.at<float>(2,3));

	cv::line(color,p1,p2,cv::Scalar(255, 0, 0),2);
	cv::line(color,p1,p3,cv::Scalar(0, 255, 0),2);
	cv::line(color,p1,p4,cv::Scalar(0, 0, 255),2);

    color = color(cv::Rect(180,100,200,200));

	cv::imshow("color", color);
	cv::waitKey(1000);
    cv::imwrite("0241g.png", color);
}