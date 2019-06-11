#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string.h>
#include <set>
#include "/usr/local/include/yaml-cpp/yaml.h"

using namespace std;
using namespace cv;

struct idxAngle
{
    int idx;
    double angle;
};

struct idxLen
{
    int idx;
    double len;
};

struct idxPoint
{
    int idx;
    double x;
};

double Pointdistance(double  x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

bool mysort(idxLen il1, idxLen il2)
{
    return il1.len > il2.len;
}

bool mysort2(idxPoint p1, idxPoint p2)
{
    return p1.x < p2.x;
}

bool mysort3(idxPoint p1, idxPoint p2)
{
    return p1.x > p2.x;
}

double LineAngle(double x1, double y1, double x2, double y2) {

    if (x1 == x2)
        return 90;
    else {
        if((y2 - y1) / (x2 - x1) > 0)
            return atan((y2 - y1) / (x2 - x1)) * 180 / CV_PI;
        else
            return atan((y2 - y1) / (x2 - x1)) * 180 / CV_PI + 180;
    }
}

int main()
{
    YAML::Node config;
    ofstream fout("line.yaml",ios::app);


    int MAX_LENS = 3;
    bool useRefine = true;
    bool useCanny = true;
    int N =  2562;
    for(int image_th = 0; image_th < N; image_th++) {

        config.reset();

        Mat image = imread("./ico_template_m2_400/r400num" + to_string(image_th) + "gamma0.bmp");

        if (image.empty()) {
            cout << "Unable to load Image" << endl;
            waitKey(0);
            return 1;
        }
        Mat resImage;
        cvtColor(image, resImage, CV_RGB2GRAY);

        threshold(resImage, resImage, 0, 255, CV_THRESH_BINARY);

        Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_STD);

        vector<Vec4f> line;
        vector<Vec4f> cut_line;

        vector<Vec4f> max_line;
        double max_len = 0;
        double max_idx = 0;

        vector<double> len;
        double total_len(0);
        double average_len;

        ls->detect(resImage, line);

        vector<idxLen> idxLens;
        vector<vector<idxAngle> > angleLine;
        angleLine.resize(18);

        for (int i = 0; i < line.size(); i++) {
            double l = Pointdistance(line.at(i)[0], line.at(i)[1], line.at(i)[2], line.at(i)[3]);
            idxLen iL;
            iL.idx = i;
            iL.len = l;
            idxLens.push_back(iL);
            len.push_back(l);

            double line_angle = LineAngle(line.at(i)[0], line.at(i)[1], line.at(i)[2], line.at(i)[3]);
            int discreteAngle = line_angle / 10;
            if (discreteAngle > 17)
                discreteAngle = 17;

            idxAngle iA;
            iA.idx = i;
            iA.angle = line_angle;
            angleLine[discreteAngle].push_back(iA);

            total_len += l;

            if (l > max_len) {
                max_len = l;
                max_idx = i;
            }
        }
        sort(idxLens.begin(), idxLens.end(), mysort);

        //对角度进行离散化，取与长度前MAX_LENS的组
        vector<Vec4f> L;
        MAX_LENS = min(MAX_LENS, (int) line.size());
        set<int> s;
        for (int ith = 0; ith < MAX_LENS; ith++) {
            int index = idxLens[ith].idx;

            double x1 = line.at(index)[0];
            double y1 = line.at(index)[1];
            double x2 = line.at(index)[2];
            double y2 = line.at(index)[3];
//        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

            double angle = LineAngle(x1, y1, x2, y2);

            double k = tan(angle * CV_PI / 180);

            int discreteAngle = angle / 10;
            if(discreteAngle > 17)
                discreteAngle = 17;

            double x0 = (x1 + x2) / 2;

            vector<vector<idxPoint> > p;
            p.resize(2);
            idxPoint p1 = {index, x1};
            idxPoint p2 = {index, x2};

            if (x1 > x0) {
                p[0].push_back(p1);
                p[1].push_back(p2);
            } else {
                p[0].push_back(p1);
                p[1].push_back(p2);
            }


            for (int i = 0; i < angleLine[discreteAngle].size(); i++)
            {
                if (angleLine[discreteAngle][i].idx == index)
                    continue;
                double a1 = line[angleLine[discreteAngle][i].idx][0];
                double b1 = line[angleLine[discreteAngle][i].idx][1];
                double a2 = line[angleLine[discreteAngle][i].idx][2];
                double b2 = line[angleLine[discreteAngle][i].idx][3];
                double d1 = abs(k * a1 - b1 - k * x1 + y1) / sqrt(k * k + 1);
                double d2 = abs(k * a2 - b2 - k * x1 + y1) / sqrt(k * k + 1);

                if (d1 < 10 && d2 < 10) {
                    double x;
                    x = (a1 / k + b1 + k * x1 - y1) / (k + 1 / k);
                    idxPoint tem = {angleLine[discreteAngle][i].idx, x};
                    if (x > x0)
                        p[0].push_back(tem);
                    else
                        p[1].push_back(tem);

                    x = (a2 / k + b2 + k * x1 - y1) / (k + 1 / k);
                    tem = {angleLine[discreteAngle][i].idx, x};
                    if (x > x0)
                        p[0].push_back(tem);
                    else
                        p[1].push_back(tem);
                }
            }


            sort(p[0].begin(), p[0].end(), mysort2);
            sort(p[1].begin(), p[1].end(), mysort3);

            //找到右端点
            int i = 0;
            double endx1;
            while (p[0][i].idx != index) {
                s.insert(p[0][i].idx);
                i++;
            }
            s.insert(p[0][i].idx);
            i++;
            while (i < p[0].size() && (p[0][i].x - p[0][i - 1].x) * sqrt(k * k + 1) < 16) {
                s.insert(p[0][i].idx);
                i++;
            }
            endx1 = p[0][i - 1].x;
            double endy1 = k * (endx1 - x1) + y1;


            //找到左端点
            i = 0;
            double endx2;
            while (p[1][i].idx != index) {
                s.insert(p[1][i].idx);
                i++;
            }
            s.insert(p[1][i].idx);
            i++;
            while (i < p[1].size() && (p[1][i].x - p[1][i - 1].x) > -16) {
                s.insert(i);
                i++;
            }
            endx2 = p[1][i - 1].x;
            double endy2 = k * (endx2 - x1) + y1;

            Vec4f l(endx1, endy1, endx2, endy2);
            line.push_back(l);


            for (int i = 0; i < angleLine[discreteAngle].size(); i++)
                L.push_back(line[angleLine[discreteAngle][i].idx]);

        }

        //合并过短直线
        vector<Vec4f>::iterator l = line.begin();
        for (set<int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
            line.erase(l + *it);
        }




        // 求平均直线长度，将小于平均长度的直线删除
        idxLens.clear();
        len.clear();
        max_len = 0;
        max_idx = 0;

        for (int i = 0; i < line.size(); i++) {
            double l = Pointdistance(line.at(i)[0], line.at(i)[1], line.at(i)[2], line.at(i)[3]);
            idxLen iL;
            iL.idx = i;
            iL.len = l;
            idxLens.push_back(iL);
            len.push_back(l);


            if (l > max_len) {
                max_len = l;
                max_idx = i;
            }
        }

        max_line.push_back(line[max_idx]);
        average_len = total_len / line.size();
        for (int i = 0; i < len.size(); i++) {
            if (len[i] > max_len * 0.2)
                cut_line.push_back(line[i]);
        }



        // Show found lines
        Mat lineImage = Mat::zeros(image.rows, image.cols, CV_8UC1);

        ls->drawSegments(lineImage, cut_line);

        cvtColor(lineImage, lineImage, CV_BGR2GRAY);
        threshold(lineImage, lineImage, 0, 255, THRESH_OTSU);

        vector<vector<float> > writelines;
        for(int i = 0; i < cut_line.size(); i++) {
            vector<float> writeline;
            writeline.push_back(cut_line.at(i)[0]);
            writeline.push_back(cut_line.at(i)[1]);
            writeline.push_back(cut_line.at(i)[2]);
            writeline.push_back(cut_line.at(i)[3]);
            writelines.push_back(writeline);
        }

        config[to_string(image_th)] = writelines;

        fout << config;
        fout << endl;
        cout << "image" << image_th << "has been processed" << endl;
    }
    fout.close();
    return 0;
}

