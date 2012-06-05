// 105 2008-11-09 12:32:30 Accepted  C C++ 0 184 呆滞的慢板 

// 求圆形和圆环的面积交，容斥原理即可，圆跟环外圆交 - 圆跟环内圆交。 

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 2.0 * asin( 1.0 );

double region(double x1, double y1, double r1,
            double x2, double y2, double r2) {
    
    double  d = hypot( x1 - x2, y1 - y2 );

    if( d - r1 - r2 > -1e-5 )
        return 0;
    
    if( r1 < r2 )   swap( r1, r2 );
        
    if( d - r1 + r2 < 1e-5 )
        return PI * r2 * r2;
        
    else {
        double  area = 0.0;
        double  theta = acos( ( r2*r2 + d*d - r1*r1 )
                                / d / r2 / 2.0 );
        area += theta * r2 * r2;
        area -= r2 * r2 * cos( theta ) * sin( theta );
        double  alpha = acos( ( r1*r1 + d*d - r2*r2 )
                                / d / r1 / 2.0 );
        area += alpha * r1 * r1;
        area -= r1 * r1 * cos( alpha ) * sin( alpha );
            return area;
    }
    
}

int main() {
    double x1, y1, r1, x2, y2, r, R;
    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r >> R) {
        double ans = region(x1, y1, r1, x2, y2, R) -
            region(x1, y1, r1, x2, y2, r);
        if(fabs(ans) < 1e-5) ans = 0;
        printf("%.3lf\n", ans);
    }
} 
