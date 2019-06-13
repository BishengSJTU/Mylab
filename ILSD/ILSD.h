//
// Created by bisheng on 19-5-21.
//

#ifndef LSD_ILSD_H
#define LSD_ILSD_H

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;

struct LenOrder
{
    int order;
    double len;
};

class ILSD {
public:
    vector<Vec4f> lines_std;
    vector<LenOrder> order;

public:
    ILSD()
    {

    }

    double Pointdistance(double  x1, double y1, double x2, double y2);
    void lineSort(vector<Vec4f> line, vector<LenOrder>&order);
};


#endif //LSD_ILSD_H
