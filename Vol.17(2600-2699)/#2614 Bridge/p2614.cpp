// 1655021 2008-10-03 19:18:22 Accepted  2614 C++ 0 184 呆滞的慢板 

// 微积分题！！ 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-5;

double fun(double L, double D, double x) {
    return sqrt(D*D+x*x)+D*D*asinh(x/D)/x-2.0*L;
}

double sol(double L, double D) {
    double l = 0, r = 2.0 * L, m;
    while(r - l > EPS) {
        m = (l + r) / 2.0;
        if(fun(L, D, m) < 0.0) l = m;
        else r = m;
    }
    return m / 4.0;
}

int main() {
    double D, H, B, L, N;
    int T; cin >> T;
    for(int t = 0; t < T;) {
        if(t++) puts("");
        printf("Case %d:\n", t);
        cin >> D >> H >> B >> L;
        double h1 = sol(L, B);
//cout << "h1 = " << h1 << endl;
        N = ceil(max(B/D, h1/H));
//cout << "N = " << (N) << endl;
        printf("%.2lf\n", H-h1/N);
    }
}
