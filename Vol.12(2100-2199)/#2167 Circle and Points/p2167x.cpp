// 1839615 2009-04-20 22:22:45 Accepted  2167 C++ 1080 184 呆滞的慢板 

// 平面上有若干点，求固定大小的圆在能包含最多几个点。
// 用 O(n^3) 的算法可以通过，枚举两个点，得到边界落在这两个点上的圆，
// 然后看一下所有的点落在这个圆中的有几个，用此更新最大值。 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double x[300], y[300];
    int N;
    
    while(scanf("%d", &N) && N) {
        for(int i = 0; i < N; ++i)
            scanf("%lf%lf", x + i, y + i);
        int best = 1;
        for(int i = 0; i < N; ++i) {
            for(int j = i + 1, now; j < N; ++j) {
                if((x[i]-x[j])*(x[i]-x[j])+
                    (y[i]-y[j])*(y[i]-y[j]) > 4.0) continue;
                double xo = (x[i] + x[j]) / 2.0;
                double yo = (y[i] + y[j]) / 2.0;
                double xv = yo - y[i], yv = x[i] - xo;
                double h = (xv * xv) + (yv * yv);
                double d = sqrt(1.0 - h);
                xv = xv / sqrt(h) * d;
                yv = yv / sqrt(h) * d;
                now = 0;
                for(int k = 0; k < N; ++k) {
                    if((x[k] - xo - xv) * (x[k] - xo - xv) +
                        (y[k] - yo - yv) * (y[k] - yo - yv) < 1.0001) {
                        now += 1;
                    }
                }
                if(now > best) best = now;
                now = 0;
                for(int k = 0; k < N; ++k) {
                    if((x[k] - xo + xv) * (x[k] - xo + xv) +
                        (y[k] - yo + yv) * (y[k] - yo + yv) < 1.0001) {
                        now += 1;
                    }
                }
                if(now > best) best = now;
            }
        }
        
        printf("%d\n", best);
        
    }
    
}
