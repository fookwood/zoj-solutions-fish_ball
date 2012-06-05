#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-12;
const double PI = acos( -1.0 );

// 浮点函数积分公式 
double integral( double a, double b, double (*f)( double ) ) {
    int     n,  i;
    double  h = b - a, temp, ret, T, C, x;
    for( T = f( a ) + f( b ), n = 1; ; ) {
        for( x = a + 0.5 * h, C = 0.0, i = 0; i < n; x += h, ++i )
            C += f( x );
        ret = ( T + 4.0 * C ) * h / 6.0;
        if( fabs( ret - temp ) < EPS )
            return  ret;
        temp = ret, T += 2.0 * C, h *= 0.5, n <<= 1;
    }
}

double n, z;

inline double fun(double x) {
    return cos(z * sin(x) - n * x);
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(6);
    while(cin >> n >> z) {
        double ans = integral(0, PI, fun) / PI;
        if(fabs(ans) < EPS) ans = 0.0;
        cout << ans << endl;
    }
}
