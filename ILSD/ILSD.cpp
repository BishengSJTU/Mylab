//
// Created by bisheng on 19-5-21.
//

#include "ILSD.h"


bool SortMethod(const double &v1, const double &v2)
{
    return v1.len > v2.len;
}

double ILSD::Pointdistance(double  x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void ILSD::lineSort(vector<Vec4f> line, vector<LenOrder>&order)
{
    order.clear();
    for (int i = 0; i < line.size(); i++)
    {
        LenOrder lo;
        lo.len = Pointdistance(line.at(i)[0], line.at(i)[1], line.at(i)[2], line.at(i)[3]);
        lo.order = i;
        order.push_back(lo);
    }
    sort(order.begin(), order.end(), SortMethod);
}

