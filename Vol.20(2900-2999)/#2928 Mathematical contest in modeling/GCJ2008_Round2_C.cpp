#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Point {
    double x, y, z;
    double p;
    void get() {scanf("%lf%lf%lf%lf", &x, &y, &z, &p);}
};

inline double sq(double x) {return x*x;}

inline double dist(const Point& a, const Point& b) {
    return (fabs(a.x-b.x) + fabs(a.y-b.y) + fabs(a.z-b.z));
}

int N;
vector<Point> P;

double eval(const Point& p) {
    double ans = 0;
    for(int i = 0; i < N; ++i)
        ans >?= dist(p, P[i]) / P[i].p;
    return ans;
}

double base(const Point& p) {
    double ans = 0;
    for(int i = 0; i < N; ++i)
        ans = max(ans, dist(p, P[i]));
    return ans;
}

int main() {
    
    freopen("C-large-practice.in", "r", stdin);
    freopen("large_out.txt", "w", stdout);
    
    int J;
    cin >> J;
    for(int u = 1; u <= J; ++u) {
        printf("Case #%d: ", u);
        cin >> N;
        P.resize(N);
        for(int i = 0; i < N; ++i)
            P[i].get();
        Point ans = P[0], it, tt;
        for(double T = 1, step; (step = base(ans) * T) > 1e-7; T *= 0.1) {
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
        printf("%.6lf\n", eval(ans));
    }
    
}
