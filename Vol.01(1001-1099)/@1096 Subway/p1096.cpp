#include <iostream>
#include <cmath>
using namespace std;

int	main() {
    
    freopen("B.1.dat", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    double sx, vx, ax, jx, ans;
    while(cin >> sx >> vx >> ax >> jx) {
        double vp = 0.5 * ax * ax / jx;
        if(2 * vp > vx) {
            ax = exp(log(vx * jx) / 2);
            vp = vx / 2;
        }
        double t1 = ax / jx;
        double dt = (vx - 2 * vp) / ax;
        double sy = (t1 + 0.5 * dt) * vx;
        double sz = t1 * vp * 2;
        if(sx > 2 * sy) {
            ans = 4 * t1 + 2 * dt + (sx - 2 * sy) / vx;
        }
        else if(sx > sz) {
            double a = ax;
            double b = 2 * (vp + ax * t1);
            double c = 4 * vp * t1 - sx;
            ans = 4 * t1 
                + (-b + sqrt(b * b - 4 * a * c)) / a;
        }
        else {
            ans = exp(log(sx / 2 / jx) / 3.0) * 4;
        }
        printf("%.1lf\n", ans);
    } 
} 

