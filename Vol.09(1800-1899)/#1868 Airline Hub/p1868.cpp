// 1763512 2009-02-15 10:14:27 Accepted  1868 C++ 10 232 呆滞的慢板 

// 蛮力枚举解决，剩下要做的就仅仅是球面距的计算了。 

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

struct Point {
    double x, y, z;
    Point() {}
    Point(double la, double lo) :
        x(cos(lo*PI/180) * cos(la*PI/180)),
        y(sin(lo*PI/180) * cos(la*PI/180)),
        z(sin(la*PI/180)) {}
};

inline double dist(const Point& a, const Point& b) {
    return sqrt((a.x-b.x)*(a.x-b.x) +
        (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int N;

Point P[1000];

double MX[1000], la[1000], lo[1000];

int main() {
    while(scanf("%d", &N) != EOF) {
        for(int i = 0; i < N; ++i) {
            scanf("%lf%lf", la + i, lo + i);
            P[i] = Point(la[i], lo[i]);
        }
        memset(MX, 0, sizeof(MX));
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1; j < N; ++j) {
                double tmp = dist(P[i], P[j]);
                MX[i] = max(MX[i], tmp);
                MX[j] = max(MX[j], tmp);
            }
        }
        int pos = 0;
        for(int i = 0; i < N; ++i)
            if(MX[i] < MX[pos])
                pos = i;
        printf("%.2lf %.2lf\n", la[pos], lo[pos]);
    }
}
