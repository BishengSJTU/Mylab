#include <ctime>
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
#include "/usr/local/include/yaml-cpp/yaml.h"

#include "IprovedFDCM.h"
#include "ILSD.h"
using namespace std;
using namespace cv;

double OnlyThreshold = 0.9;
const int MAXCOST = 65535;

int main(int argc, char* argv[]) {
#if 1
    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_STD);
#else

    Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_NONE, 0.8, 0.6, 0.5, 16, 0, 0.9, 1024);
#endif
    //灰度图
    int N = 1;
    YAML::Node config = YAML::LoadFile("line.yaml");

    //对带匹配的源图片进行循环
    for (int image_th = 4; image_th < 5; image_th++) {

        double mincost = MAXCOST;
        int minidx = 0;


        //对模板循环
        for(int template_th = 0; template_th < 2562; template_th++) { //max 2562
//        Mat Template = imread("1.jpg", 0);

            //从yaml文件中读入直线数据
            vector<Vec4f> ScrLines, Qlines;

            vector<vector<float> > myline;
            myline = config[to_string(template_th)].as<vector<vector<float>>>();//527
            for (int i = 0; i < myline.size(); i++) {
                Vec4f line;
                for (int j = 0; j < myline[i].size(); j++)
                    line[j] = myline[i][j];
                Qlines.push_back(line);
            }


//        ls->detect(Template, Qlines);


            IprovedFDCM fastmodel;
            int len_th = 8;
            double rst[4];
            //将line过短（<len_th的删除）按线长排序
            fastmodel.lineSortCut(Qlines, fastmodel.Qorder, len_th);
            double lenSum = 0;
            for (int i = 0; i < Qlines.size(); i++) {
                lenSum += fastmodel.Pointdistance(Qlines.at(i)[0], Qlines.at(i)[1], Qlines.at(i)[2], Qlines.at(i)[3]);
            }
            fastmodel.Gloable_th = lenSum * OnlyThreshold;


            Mat Src;
            Src = imread("r400num527gamma0.jpg");
//            imshow("srcimage", Src);
//            waitKey(0);
            if (Src.cols == 0) {
                cout << "The image is empty !" << endl;
                exit(0);
            }
            //灰度图
            ScrLines = getLine(Src);


            fastmodel.lineSortCut(ScrLines, fastmodel.order, len_th);
            //Src:原图
            //Qorder:模板直线按长度排序
            //Qlines:直线本身
            //order:场景直线按长度排序
            //SrcLines:直线本身
            double cost = fastmodel.ondistTrans(Src, fastmodel.Qorder, Qlines, fastmodel.order, ScrLines, true, rst);
            if(cost > 1e-5)
                cout << template_th << ":" << cost << endl;

            if (rst[0] > 0)  //if the macthing is sucesses
            {
                Point2f Cen;
                double cita = rst[1];
                double tx = rst[2];
                double ty = rst[3];
                Cen.x = config["col"].as<int>() / 2 * cos(cita) + sin(cita) * config["row"].as<int>() / 2 + rst[2];
                Cen.y = config["row"].as<int>() / 2 * cos(cita) - sin(cita) * config["col"].as<int>() / 2 + rst[3];
                RotatedRect RotRec(Cen, Size(config["col"].as<int>(), config["row"].as<int>()), -cita * 180 / CV_PI);
//            Cen.x = Template.cols / 2 * cos(cita) + sin(cita) * Template.rows / 2 + rst[2];
//            Cen.y = Template.rows / 2 * cos(cita) - sin(cita) * Template.cols / 2 + rst[3];
//            RotatedRect RotRec(Cen, Size(Template.cols, Template.rows), -cita * 180 / CV_PI);
                Point2f vertices[4];
                RotRec.points(vertices);
                for (int i = 0; i < 4; i++)
                    line(Src, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0));
            }

            if(cost < mincost) {
                mincost = cost;
                minidx = template_th;
            }
//            cout << cost << endl;

//            imshow("Src", Src);

            waitKey(0);
        }
        cout << "minidx" << minidx << endl;
    }

    return 0;
}