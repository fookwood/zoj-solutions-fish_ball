// 1651929 2008-09-30 00:38:42 Accepted  2928 C++ 660 268 呆滞的慢板 

// 神奇的模拟退火算法.... 

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Point {
    double x, y, z;
    double p;
    void get() {scanf("%lf%lf%lf", &x, &y, &z);}
    void put() {printf("%.3lf %.3lf %.3lf\n", x, y, z);}
};

inline double sq(double x) {return x*x;}

inline double dist(const Point& a, const Point& b) {
    return sqrt(sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z));
}

int N;
vector<Point> P;

double eval(const Point& p) {
    double ans = 0;
    for(int i = 0; i < N; ++i)
        ans += dist(p, P[i]);
    return ans;
}

double base(const Point& p) {
    double ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, dist(p, P[i]));
    return ans;
}

int main() {
    
    while(cin >> N) {
        P.resize(N);
        for(int i = 0; i < N; ++i) P[i].get();
        Point ans = P[0], tt;
        double bb = base(ans);
        for(double T = 1, step; (step = bb * T) > 1e-7; T *= 0.5) {
            for(int L = 0; L < 20; ++L) {
                for(int dx = -1; dx <= 1; ++dx) {
                    for(int dy = -1; dy <= 1; ++dy) {
                        for(int dz = -1; dz <= 1; ++dz) {
                            tt.x = ans.x + step*dx;
                            tt.y = ans.y + step*dy;
                            tt.z = ans.z + step*dz;
                            if(eval(tt) - eval(ans) < 0)
                                ans = tt;
                        }
                    }
                }
            }
        }
        ans.put();
    }
    
}
