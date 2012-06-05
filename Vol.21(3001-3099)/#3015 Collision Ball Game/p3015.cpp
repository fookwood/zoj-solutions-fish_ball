// 3037968 2008-08-16 19:49:59 Accepted 3015 C++ 00:00.07 844K 呆滞的慢板 

// 求出 B 的镜像，然后求与 A 的直线距 

#include <cmath>
#include <iostream>
using namespace std;

const double PI = acos( -1.0 );

struct Point {
    double  x,  y;
    Point( double x = 0, double y = 0 ) :
        x( x ), y( y ) {}
};

double dist( Point a, Point b ) {
    return  hypot( a.x - b.x, a.y - b.y );
}

struct Line {
    double  A,  B,  C;
    Line( double A, double B, double C ) :
        A( A ), B( B ), C( C ) {}
    Line( double k, double h ) {
        A = tan( k / 180.0 * PI );
        B = 1; C = -h;
    }
    Line( double k, Point p ) {
        A = k; B = -1;
        C = p.y - k * p.x;
    }
    double slope() const { return -A / B; }
};

Point intersect( Line a, Line b ) {
    return  Point (
        ( a.B * b.C - a.C * b.B ) /
        ( a.A * b.B - a.B * b.A ),
        ( a.A * b.C - a.C * b.A ) /
        ( a.B * b.A - a.A * b.B )
    );
}

Point reflect( Line l, Point p ) {
    Line v( -1.0 / l.slope(), p );
    Point q = intersect( v, l );
    q.x *= 2.0;
    q.y *= 2.0;
    q.x -= p.x;
    q.y -= p.y;
    return  q;
}

int main() {
    
    double  k, h, a, b;
    while( cin >> k >> h >> a >> b ) {
        Line    L( k, h );
        Point   A( 0, a ),  B( b, 0 );
        cout.setf( ios::fixed );
        cout.precision( 2 );
        cout << dist( A, reflect( L, B ) ) << endl;
    }
    
}
