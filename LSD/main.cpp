#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
//#include "ILSD.h"
#include <iostream>
using namespace std;
using namespace cv;

double Pointdistance(double  x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
//struct Line
//{
//    int
//};
int main()
{
    bool useRefine = true;
    bool useCanny = true;
    Mat image = imread("image3.png");
    if( image.empty() )
    {
        cout << "Unable to load Image" << endl; return 1;
    }
    imshow("Source Image", image);

    Mat imageBf;
    bilateralFilter(image, imageBf, 5, 10, 10);
//    imshow("bi", imageBf);
    //双边滤波
    Mat imageEnhance;
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
    filter2D(imageBf, imageEnhance, CV_8UC3, kernel);
    imshow("iE", imageEnhance);

    Mat resImage;
    cvtColor(image, resImage, CV_RGB2GRAY);



    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_STD);

    vector<Vec4f> line;
    vector<Vec4f> cut_line;
    vector<double> len;
    double total_len(0);
    double average_len;

    ls->detect(resImage, line);
    for(int i = 0; i < line.size(); i++)
    {
        double l = Pointdistance(line.at(i)[0], line.at(i)[1], line.at(i)[2], line.at(i)[3]);
        len.push_back(l);
        total_len += l;
    }

    average_len = total_len/line.size();

    for(int i = 0; i < len.size(); i++)
    {
        if(len[i] > average_len)
            cut_line.push_back(line[i]);
    }



    // Show found lines

    ls->drawSegments(image, line);
    imshow("result", image);

    waitKey();
    return 0;
}

