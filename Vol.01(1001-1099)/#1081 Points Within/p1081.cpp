// 3010116 2008-07-28 11:39:53 Accepted 1081 C++ 00:00.00 852K 呆滞的慢板 

////////////////////////////////////////////////////
//                 计算几何类 v1.0                //
///////////////////Documentation////////////////////
//                                                //
//                  Default                       // 
//                                                //
////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

#include <iostream>
#include <limits> 
#include <cmath> 
#include <algorithm> 
using namespace std; 

class Point;    // 点、矢量类（x 坐标和 y 坐标） 
class Arrow;    // 有向线段类（起点和终点） 
class Line;     // 直线类 
class Circle;   // 圆类 

const double INF = numeric_limits<double>::infinity();
const double NaN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-6;
const double PI = acos( -1.0 );

// 附带容差浮点比较 
inline bool eq( double x, double y ) { return x-y < EPS && y-x < EPS; }
inline bool ne( double x, double y ) { return x-y > EPS || y-x > EPS; }
inline bool gt( double x, double y ) { return x-y > EPS; }
inline bool ge( double x, double y ) { return y-x < EPS; }
inline bool lt( double x, double y ) { return y-x > EPS; }
inline bool le( double x, double y ) { return x-y < EPS; }

// 等于零、正数、负数、非负、非正、非零 
inline bool zr( double x ) { return x < EPS && x > -EPS; }
inline bool ps( double x ) { return x > EPS; }
inline bool ng( double x ) { return x < -EPS; }
inline bool nn( double x ) { return x > -EPS; }
inline bool np( double x ) { return x < EPS; }
inline bool nz( double x ) { return x > EPS || x < -EPS; }

// 弧度转角度、角度转弧度、幅角主值 [-PI,PI] 
inline double rad2deg( double x ) { return x / PI * 180.0; }
inline double deg2rad( double x ) { return x * PI / 180.0; }
inline double wrap( double x ) { x = fmod( x, 2.0 * PI );
    if(x>PI) return x-2.0*PI; if(x<-PI) return x+2.0*PI; return x; } 
inline double wrap_deg( double x ) { x = fmod( x, 360.0 );
    if(x>180.0) return x-360.0; if(x<-180.0) return x+360.0; return x; } 


// 点类实现 
struct Point {
    double  x,  y;
    Point( double x = 0, double y = 0 ) : x( x ), y( y ) {}
    inline double angle();
    inline double length() { return hypot( x, y ); } 
    inline bool origin() { return zr( x ) && zr( y ); }
    inline bool nan() { return x!=x || y!=y; }
    inline bool inf() { return fabs(x)==INF || fabs(y)==INF; } 
};

istream& operator >> ( istream& is, Point& p ) { return is >> p.x >> p.y; }
ostream& operator << ( ostream& os, Point p ) { return os << "(" << p.x << ", " << p.y << ")"; }

// 等价、不等、加、减、叉乘、内积、两点距离、三点面积、幅角、夹角
inline bool operator==( Point a, Point b ) { return eq(a.x, b.x) && eq(a.y, b.y); }
inline bool operator!=( Point a, Point b ) { return ne(a.x, b.x) || ne(a.y, b.y); }
inline bool operator<( Point a, Point b )  { return lt(a.x,b.x) || eq(a.x,b.x) && lt(a.y,b.y); }
inline Point operator+( Point a, Point b ) { return Point( a.x+b.x, a.y+b.y ); }
inline Point operator-( Point a, Point b ) { return Point( a.x-b.x, a.y-b.y ); }
inline double operator*( Point a, Point b ) { return a.x*b.y - a.y*b.x; }
inline double operator^( Point a, Point b ) { return a.x*b.x + a.y*b.y; }
inline double dist( Point a, Point b ) { return hypot(a.x-b.x, a.y-b.y ); }
inline double area( Point a, Point b, Point p3 ) { return fabs((a-b)*(a-p3))/2.0; }
inline double Point::angle()
    { if( zr(x)&&zr(y) ) return NaN;
      if( zr(x)&&ps(y) ) return PI / 2.0;
      if( zr(x)&&ng(y) ) return -PI / 2.0;
      if( ps(x)&&zr(y) ) return 0.0;
      if( ps(x) ) return atan( y / x );
      if( ng(x) ) return wrap( PI + atan( y / x ) );
    }
inline double angle( Point a, Point b ) { return wrap( b.angle() - a.angle() ); }
inline double angle2( Point a, Point b ) { return Point( a^b, a*b ).angle(); }
inline bool parallel( Point a, Point b ) 
    { return a.origin() || b.origin() || eq( a.angle(), b.angle() ); }

// 三角形公式： 

// 有向线段类实现 a 指向 b 
struct Arrow {
    Point   a,  b;
    Arrow() {}
    Arrow( Point a, Point b ) : a( a ), b( b ) {}
    inline double angle() { return ( b - a ).angle(); }
    inline double length() { return ( b - a ).length(); }
    inline bool on_arrow( Point p ) { return parallel( p-a, b-p ); } 
}; 

// 线段是否相交(存在重合点)，重合(所有点重合)，平行，重叠(有不止一点重合) 
inline bool cross( Arrow v, Arrow w ) {
    if( v.on_arrow( w.a ) || v.on_arrow( w.b ) ||
        w.on_arrow( v.a ) || w.on_arrow( v.b ) ) return true;
    return ( ps((v.a-w.a)*(w.a-w.b)) ^ ps((v.b-w.a)*(w.a-w.b)) )
        && ( ps((v.a-w.b)*(w.a-w.b)) ^ ps((v.b-w.b)*(w.a-w.b)) );
}
inline bool operator == ( Arrow v, Arrow w )
    { return v.a==w.a && v.b==w.b || v.b==w.a && v.a==w.b; }
inline bool parallel( Arrow v, Arrow w )
    { return parallel(v.a-v.b, w.a-w.b) || parallel(v.a-v.b, w.b-w.a); }
inline bool overlap( Arrow v, Arrow w ) {
    if( !parallel(v, w) || zr(v.length()) || zr(w.length()) ) return false;
    if( v==w ) return true;
    if( v.b < v.a ) swap( v.a, v.b );
    if( w.b < w.a ) swap( w.a, w.b );
    if( w.a < v.a ) swap( v, w );
    return v.b!=w.a && parallel( v.a-v.b, w.a-v.b );
}


// 直线类，给的是一般式的三个系数 
struct Line {
    double  A,  B,  C;
    Line( int A = 0, int B = 0, int C = 0 ) :
        A( A ), B( B ), C( C ) {} 
    Line( Point a, Point b ) : A( b.y-a.y ), B( a.x-b.x ),
        C( a.x*(a.y-b.y) + a.y*(b.x-a.x) ) {}
    Line( Arrow v ) { *this = Line( v.a, v.b ); }
}; 

// 直线重合(==)、相交(!=)、平行、直线交点、线段交点、三直线围面积 
inline bool operator == ( Line p, Line q )
    { return p.A*q.B == p.B*q.A && p.A*q.C == p.C*q.A; }
inline bool operator != ( Line p, Line q )
    { return p.A*q.B != p.B*q.A; }
inline bool parallel( Line p, Line q ) 
    { return p.A*q.B == p.B*q.A && p.A*q.C != p.C*q.A; }
inline Point intersect( Line p, Line q ) {
    if( p == q ) return Point( NaN, NaN ); 
    if( parallel( p, q ) ) return Point( INF, INF );
    return Point( (p.B*q.C-q.B*p.C)/(q.B*p.A-p.B*q.A),
                  (p.A*q.C-q.A*p.C)/(q.A*p.B-p.A*q.B) );
}
inline Point intersect( Arrow v, Arrow w ) {
    if( !cross(v, w) || overlap(v, w) ) return Point( NaN, NaN ); 
    if( !parallel(v, w) ) return intersect( Line(v), Line(w) );
    if( w.on_arrow(v.a) ) return v.a;
    if( w.on_arrow(v.b) ) return v.b;
    if( v.on_arrow(w.a) ) return w.a;
    if( v.on_arrow(w.b) ) return w.b;
}
inline double area( Line p, Line q, Line r )
    { return area( intersect(p, q), intersect(q, r), intersect(r, p) ); }

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

#include <vector>
using namespace std;

int M,  N,  T = 0;
vector<Point>   V;
Point   P;

int main() {
    
    while( cin >> M >> N ) {
        
        if( T++ )   puts( "" );
        printf( "Problem %d:\n", T );
        
        V.resize( M );
        
        for( int i = 0; i < M; ++i )    cin >> V[i];
        V.push_back( V.front() );
        
        for( int i = 0; i < N; ++i ) {
            cin >> P;
            double  tot = 0;
            for( int i = 0; i < M; ++i ) {
                if( Arrow( V[i+1], V[i] ).on_arrow( P ) ) {
                    tot = 1.0;
                    break;
                }
                tot += angle( V[i+1]-P, V[i]-P );
            }
            puts( zr( tot ) ? "Outside" : "Within" );
        }
        
    }
    
    
}
