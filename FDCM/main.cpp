#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <highgui.h>
#include "fstream"

#include "IprovedFDCM.h"
using namespace std;
using namespace cv;

double OnlyThreshold = 0.9;

int main(int argc, char* argv[]) {
#if 0
    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_STD);
#else

    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_NONE, 0.8, 0.6, 0.5, 16, 0, 0.9, 1024);
#endif
    //灰度图
    Mat Template = imread("1.jpg", 0);
    vector<Vec4f> ScrLines, Qlines;
    ls->detect(Template, Qlines);
    VideoCapture cap("5.mp4");
    IprovedFDCM fastmodel;
    int len_th = 15;
    double rst[4];
    //将line过短（<len_th的删除）按线长排序
    fastmodel.lineSortCut(Qlines, fastmodel.Qorder, len_th);
    double lenSum = 0;
    for (int i = 0; i < Qlines.size(); i++) {
        lenSum += fastmodel.Pointdistance(Qlines.at(i)[0], Qlines.at(i)[1], Qlines.at(i)[2], Qlines.at(i)[3]);
    }
    fastmodel.Gloable_th = lenSum * OnlyThreshold;
    DWORD start, stop;
    for (;;) {
        Mat Src;
        start = GetTickCount();
        cap >> Src;
        if (Src.cols == 0) {
            break;
        }
        //灰度图
        Mat gray;
        cvtColor(Src, gray, CV_RGB2GRAY);
        ls->detect(gray, ScrLines);

        fastmodel.lineSortCut(ScrLines, fastmodel.order, len_th);
        //Src:原图
        //Qorder:模板直线按长度排序
        //Qlines:直线本身
        //order:场景直线按长度排序
        //SrcLines:直线本身
        fastmodel.ondistTrans(Src, fastmodel.Qorder, Qlines, fastmodel.order, ScrLines, true, rst);
        if (rst[0] > 0)  //if the macthing is sucesses
        {
            Point2f Cen;
            double cita = rst[1];
            double tx = rst[2];
            double ty = rst[3];
            Cen.x = Template.cols / 2 * cos(cita) + sin(cita) * Template.rows / 2 + rst[2];
            Cen.y = Template.rows / 2 * cos(cita) - sin(cita) * Template.cols / 2 + rst[3];
            RotatedRect RotRec(Cen, Size(Template.cols, Template.rows), -cita * 180 / CV_PI);
            Point2f vertices[4];
            RotRec.points(vertices);
            for (int i = 0; i < 4; i++)
                line(Src, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0));
        }
        imshow("Src", Src);
        stop = GetTickCount();
        cout << "time:" << stop - start << endl;

        waitKey(0);
    }

    return 0;
}