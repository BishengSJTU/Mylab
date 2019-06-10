#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/photo.hpp>
#include <math.h>

using namespace std;
using namespace cv;
const int PI = 3.1415926;

//去除二值图像边缘的突出部
//uthreshold、vthreshold分别表示突出部的宽度阈值和高度阈值
//type代表突出部的颜色，0表示黑色，1代表白色
void delete_jut(Mat& src, Mat& dst, int uthreshold, int vthreshold, int type)
{
    int threshold;
    src.copyTo(dst);
    int height = dst.rows;
    int width = dst.cols;
    int k;  //用于循环计数传递到外部
    for (int i = 0; i < height - 1; i++)
    {
        uchar* p = dst.ptr<uchar>(i);
        for (int j = 0; j < width - 1; j++)
        {
            if (type == 0)
            {
                //行消除
                if (p[j] == 255 && p[j + 1] == 0)
                {
                    if (j + uthreshold >= width)
                    {
                        for (int k = j + 1; k < width; k++)
                            p[k] = 255;
                    }
                    else
                    {
                        for (k = j + 2; k <= j + uthreshold; k++)
                        {
                            if (p[k] == 255) break;
                        }
                        if (p[k] == 255)
                        {
                            for (int h = j + 1; h < k; h++)
                                p[h] = 255;
                        }
                    }
                }
                //列消除
                if (p[j] == 255 && p[j + width] == 0)
                {
                    if (i + vthreshold >= height)
                    {
                        for (k = j + width; k < j + (height - i)*width; k += width)
                            p[k] = 255;
                    }
                    else
                    {
                        for (k = j + 2 * width; k <= j + vthreshold*width; k += width)
                        {
                            if (p[k] == 255) break;
                        }
                        if (p[k] == 255)
                        {
                            for (int h = j + width; h < k; h += width)
                                p[h] = 255;
                        }
                    }
                }
            }
            else  //type = 1
            {
                //行消除
                if (p[j] == 0 && p[j + 1] == 255)
                {
                    if (j + uthreshold >= width)
                    {
                        for (int k = j + 1; k < width; k++)
                            p[k] = 0;
                    }
                    else
                    {
                        for (k = j + 2; k <= j + uthreshold; k++)
                        {
                            if (p[k] == 0) break;
                        }
                        if (p[k] == 0)
                        {
                            for (int h = j + 1; h < k; h++)
                                p[h] = 0;
                        }
                    }
                }
                //列消除
                if (p[j] == 0 && p[j + width] == 255)
                {
                    if (i + vthreshold >= height)
                    {
                        for (k = j + width; k < j + (height - i)*width; k += width)
                            p[k] = 0;
                    }
                    else
                    {
                        for (k = j + 2 * width; k <= j + vthreshold*width; k += width)
                        {
                            if (p[k] == 0) break;
                        }
                        if (p[k] == 0)
                        {
                            for (int h = j + width; h < k; h += width)
                                p[h] = 0;
                        }
                    }
                }
            }
        }
    }

    blur(src, dst, Size(11, 11));
    for (int i = 0; i < height; i++)
    {
        uchar* p = dst.ptr<uchar>(i);
        for (int j = 0; j < width; j++)
        {
            if (p[j] < 128)
                p[j] = 0;
            else p[j] = 255;
        }
    }
}

Mat maxArea(Mat src)
{
    vector<vector<cv::Point>> contours ;
    vector<vector<cv::Point>> maxContours;
    cv::findContours(src,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
    double maxArea = 0;
    vector<cv::Point> maxContour;
    for(size_t i = 0; i < contours.size(); i++)
    {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea)
        {
            maxArea = area;
            maxContour = contours[i];
        }
    }
    maxContours.push_back(maxContour);

    Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
    drawContours(dst, maxContours, 0, Scalar(255), CV_FILLED);

    return dst;

}
int main() {
    Mat src, lab, hsv;
    src = imread("image7.png");
    cvtColor(src, lab, COLOR_BGR2Lab);
    cvtColor(src, hsv, COLOR_BGR2HSV);

    int rows = lab.rows;
    int cols = lab.cols;

    Mat dst1(rows, cols, CV_8UC1);
    Mat dst2(rows, cols, CV_8UC1);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            float L = lab.at<Vec3b>(i, j)[0];
            L = L * 255. / 100.;

            float H = hsv.at<Vec3b>(i, j)[0];
            float S = hsv.at<Vec3b>(i, j)[1];
            float V = hsv.at<Vec3b>(i, j)[2];


//            float A = lab.at<Vec3b>(i, j)[1];
//            float B = lab.at<Vec3b>(i, j)[2];
//            float beta;
//            if(A > 0 && B > 0)
//                beta = 180./PI*atan(B / A) * 255. / 360.;
//            else if(A < 0)
//                beta = (180./PI*atan(B / A) + 180) * 255. / 360.;
//            else
//                beta = (180./PI*atan(B / A) + 360) * 255. /360.;

            dst1.at<uchar>(i, j) = L;
            dst2.at<uchar>(i, j) = V;
        }
    }

    threshold(dst1, dst1, 0, 255, CV_THRESH_OTSU);
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
    Mat out;
    dilate(dst1, dst1, element);
    erode(dst1,dst1, element);


    threshold(dst2, dst2, 0, 255, CV_THRESH_OTSU);

    dst1 = maxArea(dst1);
    dst2 = maxArea(dst2);


    Mat final1;

    delete_jut(dst1, final1, 3, 3, 1);


    imshow("dst2", dst2);

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("final1", final1);


//    Mat result;
//    illuminationChange(src, final1, result, 0.2, 0.4);
//    imshow("result", result);
    waitKey(0);
    return 0;
}