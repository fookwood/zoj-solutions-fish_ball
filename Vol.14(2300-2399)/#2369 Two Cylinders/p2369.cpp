// 数值积分... 不过积分函数是抄来的

// 积分可以这样搞：从两个圆柱的轴平面平行的方向切片
// 切出来的都是矩形，最后推出来的公式：
// 8∫sqrt(r1^2-x^2)*sqrt(r2^2-x^2)dx 

// 至于怎么高精度积分，可以用龙贝格公式之类的，反正我抄来的
// 这个函数就特别的好，短小精悍... 

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double  R,  r;
int     T;

inline double f( const double& x ) {
    return  sqrt( ( R*R - x*x ) * ( r*r - x*x ) );
}

double simpson(double a, double b, double eps) {
    int n,i;
    double h = b - a, temp, ret, T, C, x;
    for (T = f(a) + f(b), n = 1; ; ) {
        for (x = a + 0.5 * h, C = 0.0, i = 0; i < n; x += h, ++i)
            C += f(x);
        ret = (T + 4 * C) * h / 6;
        if (fabs(ret - temp) < eps)
            return ret;
        temp = ret, T += 2 * C, h *= 0.5, n <<= 1;
    }
}

int main() {
    
    cin >> T;
        
    while( T-- ) {
        
        cin >> R >> r;
        
        if( R < r )
            swap( R, r );

        double ans = simpson( 0.0, r, 1e-5 );
        
        printf( "%.4lf\n", ans * 8.0 );
        
        if( T ) cout << endl;

    }
    
}
