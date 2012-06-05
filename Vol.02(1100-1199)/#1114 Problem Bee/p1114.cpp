// 2149178 2010-04-09 13:42:46 Accepted  1114 C++ 0 184 呆滞的慢板 

// 蜂窝距离，坐标转换。
// 将坐标作出变换，以六边形中心为网格，宽为 1.5s，高为 sqrt(3)/2s，s为边长。
// 然后找到离起点和终点最近的六边形中心，求出第一步距离。
// 然后根据选定的两个中心可以将坐标转化为整数。
// 由于坐标的对称性，相减取绝对值即为坐标距离(tx和ty)。
// 两个六边形中心相距 sqrt(3)s，实际的间隔应该为max(tx, ty)*sqrt(3)s。
// 另外注意 tx = ty = 0 的情况下，距离为直接的两点间距离。 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double YU = 0.5 * sqrt(3.0);
        
inline double dist(double x1, double y1, double x2, double y2) {
    return hypot(x1-x2, y1-y2);
}

int calc(double x, double y, int& tx, int& ty) {    
    int xd = (int)(x / 1.5);
    int xu = xd + 1;
    int yd = (int)(y / YU);
    int yu = yd + 1;
    if((xd + yd) % 2) {
        double d1 = dist(x, y, xd * 1.5, yu * YU);
        double d2 = dist(x, y, xu * 1.5, yd * YU);
        if(d1 < d2) {
            tx = xd;
            ty = yu;
        }
        else {
            tx = xu;
            ty = yd;
        }
    }
    else {
        double d1 = dist(x, y, xd * 1.5, yd * YU);
        double d2 = dist(x, y, xu * 1.5, yu * YU);
        if(d1 < d2) {
            tx = xd;
            ty = yd;
        }
        else {
            tx = xu;
            ty = yu;
        }
    }
}

int main() {
    double s, x1, y1, x2, y2;
    while(cin >> s >> x1 >> y1 >> x2 >> y2 && s) {
        x1 /= s;
        y1 /= s;
        x2 /= s;
        y2 /= s;
        int tx1, tx2, ty1, ty2;
        calc(x1, y1, tx1, ty1);
        calc(x2, y2, tx2, ty2);
        int tx = abs(tx2 - tx1), ty = abs(ty2 - ty1);
        double ans;
        if(tx || ty) {
            ans = max(tx, ty) * YU * 2 + dist(x1, y1, tx1*1.5, ty1*YU) + dist(x2, y2, tx2*1.5, ty2*YU);
        }
        else {
            ans = dist(x1, x2, y1, y2); 
        }
        printf("%.03f\n", ans * s);
    }
}
