// 3037317 2008-08-16 01:05:42 Accepted 2352 C++ 00:00.02 864K 呆滞的慢板 

// 重新做一次凸包，按序输出就是了 

//////////////////////////////////////////////////////
//                  计算几何类 v1.7                 //
//////////////////// Documentation ///////////////////
//                                                  //
//                  Default                         // 
//                                                  //
// 1.3 增加多边形类，带有求面积方法。               //
// 1.4 增加多边形方法，判断点是否在多边形内。       //
// 1.5 增加多边形方法，球多边形凸包。               //
// 1.6 增加多边形方法，求多边形重心。               //
// 1.7 增加了数值积分方法。                         // 
//                                                  //
//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <limits> 
#include <cmath> 
#include <algorithm> 
using namespace std; 

class Point;    // 点、矢量类（x 坐标和 y 坐标） 
class Arrow;    // 有向线段类（起点和终点） 
class Line;     // 直线类 
class Circle;   // 圆类 
class Polygon;  // 多边形 

// 常数：无穷、非数、容差、PI 
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


// 通用函数

// 弧度转角度、角度转弧度、幅角主值 [-PI,PI] 
inline double rad2deg( double x ) { return x / PI * 180.0; }
inline double deg2rad( double x ) { return x * PI / 180.0; }
inline double wrap( double x ) { x = fmod( x, 2.0 * PI );
    if(x>PI) return x-2.0*PI; if(x<-PI) return x+2.0*PI; return x; } 
inline double wrap_deg( double x ) { x = fmod( x, 360.0 );
    if(x>180.0) return x-360.0; if(x<-180.0) return x+360.0; return x; } 
 
// 最大公约数、最小公倍数
int gcd( int m, int n ) { while(n) { int r = m%n; m=n; n=r; } return m; }
int lcm( int m, int n ) { return  m * n / gcd( m, n ); }

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
inline double angle( Point a, Point b ) { return Point( a^b, a*b ).angle(); }
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


// 多边形类实现 
struct Polygon {
    vector<Point>   V;
    void clear() { V.clear(); }
    int size() const { return V.size(); } 
    void get( Point a ) { V.push_back( a ); } 
    double area() const; 
    double perimeter() const;
    bool inside( Point ) const;
    Point Polygon::center() const;
    Polygon convex() const; 
    static Point refP;  // 静态参考点 
    friend bool arg_cmp( Point a, Point b )
        { return (a-refP).angle()<(b-refP).angle(); }
}; 

Point Polygon::refP = Point();

// 返回多边形面积 
double Polygon::area() const {
    double  ans = 0; 
    for( int i = 0; i < V.size(); ++i )
        ans += V[i] * V[(i+1)%V.size()];
    return  fabs( ans ) / 2.0; 
}

// 返回多边形重心 
Point Polygon::center() const {
    Point   ans,    now;
    double  v,  w = 0.0;
    for( int i = 0; i < V.size(); ++i ) {
        now = V[i] + V[(i+1)%V.size()];
        now.x /= 3.0;
        now.y /= 3.0; 
        v = V[i] * V[(i+1)%V.size()];
        ans.x *= w; ans.y *= w;
        now.x *= v; now.y *= v;
        ans = ans + now; w += v;
        if( nz( w ) ) { ans.x /= w; ans.y /= w; } 
    }
    return  ans; 
}

// 返回多边形周长
double Polygon::perimeter() const {
    double  ans = 0; 
    for( int i = 0; i < V.size(); ++i )
        ans += dist( V[i], V[(i+1)%V.size()] );
    return  ans;
}

// 查询一个点是否在多边形内(在边上也算) 
bool Polygon::inside( Point a ) const {
    double tot = 0;
    for( int i = 0; i < V.size(); ++i ) {
        if( Arrow( V[i], V[(i+1)%V.size()] ).on_arrow( a ) )
            return  true;
        tot += angle( V[i]-a, V[(i+1)%V.size()]-a );
    }
    return  nz( tot );
}

// 求多边形的凸包
Polygon Polygon::convex() const {
    if( V.size() < 3 )  return  *this; 
    vector<Point> G = V;
    int pos = 0;
    for( int i = 1; i < G.size(); ++i )
        if( G[i].y < G[pos].y )
            pos = i;
    swap( G[0], G[pos] );
    refP = G[0];
    sort( G.begin() + 1, G.end(), arg_cmp );
    Polygon H;
    H.get( G[0] );  H.get( G[1] );
    for( int i = 2; i < G.size(); ++i ) {
        while( H.V.size() >= 2 &&
            np((H.V.back()-*(H.V.end()-2))*(G[i]-*(H.V.end()-2))) ) 
            H.V.pop_back();
        H.get( G[i] );
    }
    return  H;
} 

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////



//////////////////////////////////////////////////////
//             Online Judge 断言 v1.0               //
///////////////////Documentation//////////////////////
//                                                  //
// 根据下面不同的断言，会在 OJ 中返回不同类型的错误 // 
//                                                  //
//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////

#define Assert1( x )    { if( !(x) ) while( 1 ); }                 // TLE 
#define Assert2( x )    { if( !(x) ) while( 1 ) new int[1000]; }   // MLE 
#define Assert3( x )    { if( !(x) ) while( 1 ) *(int*)NULL = 1; } // RTE SIGSEGV 
#define Assert4( x )    { if( !(x) ) while( 1 ) puts( "OLE" ); }   // OLE 
#define Assert5( x )    { if( !(x) ) printf( "%d", 1 / 0 ); }      // RTE SIGFPE 
#define Assert6( x )    { if( !(x) ) system( "pause" ); }          // RF 

//////////////////////////////////////////////////////
//             2008 CopyRight(c) by elf             //
//////////////////////////////////////////////////////


#include <string>
using namespace std;

string  skip;

int     T,  N = 0;

Polygon G;
Point   P;

int main() {
    
    for( cin >> T; T--; N = 0 ) {
        G.clear();
        while( ++N ) {
            cin >> P;
            G.get( P );
            getline( cin, skip );
            if( !isdigit( cin.peek() ) && cin.peek() != '-' )
                break;
        }
        G = G.convex();
        
        Assert2( G.V.size() == N );
    
        int pos;
        for( pos = 0; pos < N; ++pos )
            if( zr( G.V[pos].x ) && zr( G.V[pos].y ) )
                break;
    
        for( int i = pos; i < N; ++i )
            cout << '(' << G.V[i].x
                 << ',' << G.V[i].y << ")\n";
             
        for( int i = 0; i < pos; ++i )
            cout << '(' << G.V[i].x
                 << ',' << G.V[i].y << ")\n";
             
        if( T ) puts( "" );
    
    }
    
}
