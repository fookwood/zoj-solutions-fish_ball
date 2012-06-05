// 简单几何
// 对精度问题要有发神经般的敏感！！
// 2840234 2008-04-12 16:43:00 Accepted 1280 C++ 00:00.00 388K 呆滞的慢板 

#include <cstdio>
#include <cmath>

const double EPS = 1e-5;

int main() {
    int     T;
    double  x1, y1, x2, y2, x3, y3, x4, y4;
    double  a1, b1, c1, a2, b2, c2;
    scanf( "%d", &T );
    puts( "INTERSECTING LINES OUTPUT" );
    while( T-- ) {
        scanf( "%lf%lf%lf%lf%lf%lf%lf%lf",
            &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );
        a1 = y2 - y1;
        b1 = x1 - x2;
        c1 = y1 * x2 - y2 * x1;
        a2 = y4 - y3;
        b2 = x3 - x4;
        c2 = y3 * x4 - y4 * x3;
        if( fabs( a1 * b2 - a2 * b1 ) < EPS ) {
            if( fabs( a1 * c2 - a2 * c1 ) < EPS &&
                fabs( b1 * c2 - b2 * c1 ) < EPS )
                puts( "LINE" );
            else
                puts( "NONE" );
        }
        else {
            double y = ( a1 * c2 - a2 * c1 ) /
                    ( a2 * b1 - a1 * b2 );
            double x = ( b1 * c2 - b2 * c1 ) /
                    ( b2 * a1 - b1 * a2 );
            y = round( y * 100. ) / 100. + EPS;
            x = round( x * 100. ) / 100. + EPS;
            printf( "POINT %.2lf %.2lf\n", x, y );
        }
    }
    puts( "END OF OUTPUT" );
}
