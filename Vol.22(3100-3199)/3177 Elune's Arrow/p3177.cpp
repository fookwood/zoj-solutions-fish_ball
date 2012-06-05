#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-8;

int main() {
    int T;
    for(cin >> T; T--;) {
        double x0, y0, x1, y1, dx, dy, r0, r1, v;
        double A, B, C, R;
        cin >> x0 >> y0 >> x1 >> y1 >> dx >> dy >> r0 >> r1 >> v;
        R = r0 + r1;
        A = dx*dx + dy*dy - v*v;
        B = 2 * ((x0 - x1) * dx + (y0 - y1) * dy - R * v);
        C = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0) - R * R;
        //*/
        double tmp, a1, a2;
        if(fabs(A) < 1e-8) {
            if(fabs(B) < 1e-8) puts("Impossible");
            else {
                if(B > 0 && C < 0 || B < 0 && C > 0)
                    printf("%.4lf\n", -C/B);
                else puts("Impossible");
            }
            continue;
        }
        if(A>0)
        {
            if(B*B+4*A*C<0)
            {
                puts("Impossible");
                continue;
            }
            a1=(-B+sqrt(B*B-4*A*C))/2.0/A;
            a2=(-B-sqrt(B*B-4*A*C))/2.0/A;
            //>0的最小跟
            tmp=2000000000;
            if(a1>0&&a1<tmp)tmp=a1;
            if(a2>0&&a2<tmp)tmp=a2;
            if(tmp==2000000000)
                puts("Impossible");
            else
                printf("%.4lf\n",tmp);
            continue;
        }
        else
        {
                a1=(-B+sqrt(B*B-4*A*C))/2.0/A;
                a2=(-B-sqrt(B*B-4*A*C))/2.0/A;
                //>0的最小跟
                tmp=2000000000;
                if(a1>0&&a1<tmp)tmp=a1;
                if(a2>0&&a2<tmp)tmp=a2;
                if(tmp==2000000000)
                    puts("Impossible");
                else
                    printf("%.4lf\n",tmp);
                continue;                
        }

        /*/
        if(fabs(A) < 1e-8) {
            if(fabs(B) < 1e-8) puts("Impossible");
            else {
                if(B > 0 && C < 0 || B < 0 && C > 0)
                    printf("%.4lf\n", -C/B);
                else puts("Impossible");
            }
        }
        else if(A > 0) {
            if(B*B - 4*A*C < 0) puts("Impossible");
            double delta = sqrt(B*B - 4*A*C);
            double a1 = (-B-delta) / 2 / A, a2 = (-B+delta) / 2 / A;
            double ans = 1e99;
            if(a1 > 0 && a1 < ans) ans = a1;
            if(a2 > 0 && a2 < ans) ans = a2;
            if(ans == 1e99) puts("Impossible");
            else printf("%.4lf\n", fabs(ans));
        }
        else {
            double delta = sqrt(B*B - 4*A*C);
            double a1 = (-B-delta) / 2 / A, a2 = (-B+delta) / 2 / A;
            double ans = 1e99;
            if(a1 > 0 && a1 < ans) ans = a1;
            if(a2 > 0 && a2 < ans) ans = a2;
            if(ans == 1e99) puts("Impossible");
            else printf("%.4lf\n", fabs(ans));
        }
        //*/
    }
}
