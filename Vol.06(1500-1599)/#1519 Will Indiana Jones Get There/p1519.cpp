// 3064522 2008-09-09 12:59:59 Accepted 1519 C++ 00:02.56 904K 呆滞的慢板 

// Prim，变相最小生成树，每个原来的线段代表一个顶点，边权为两条直线的距离。 

//////////////////////////////////////////////////////////
//       映射二分堆(Mapped_Binary_Heap)类模板 v1.3      //
//////////////////////////////////////////////////////////
//                                                      //
//                   模板参数                           //
// 1. SZ:     映射二分堆的最大索引号;                   //
// 2. T:      映射二分堆蕴含值类型，缺省为 int;         //
// 3. Op:     比较准则 functor，缺省为小于;             // 
//                                                      //
//                     接口                             //
// 1. clear:  清空堆;                                   //
// 2. empty:  判空;                                     // 
// 3. size:   返回堆大小(元素个数);                     //
// 4. top:    返回堆顶元素(索引和值结对);               //
// 5. push:   按索引插入元素，自动识别更新为最小值;     //
// 6. pop:    删除最小值;                               //
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <functional>
#include <algorithm>
using namespace std;

template <int SZ, class T = int, class Op = less<T> >
class MBH {

    pair<int, T> heap[SZ + 1];
    int key[SZ + 1], sz;

public:

    void clear() { sz = 0; memset( key, 0, sizeof( key ) ); }
    
    int size() const { return sz; }
    
    bool empty() const { return sz == 0; } 
    
    pair<int, T> top() const { return heap[1]; }
    
    void push( int idx, T val ) {
        if( !key[idx] ) {
            key[idx] = ++sz;
            heap[sz] = make_pair( idx, val );
        }
        else if( Op()( val, heap[key[idx]].second ) )
            heap[key[idx]].second = val;
        for( int pos = key[idx], c;
            ( c = pos >> 1 ) && Op()( val, heap[c].second ); pos = c ) {
            swap( heap[pos], heap[c] );
            key[idx] = c;
            key[heap[pos].first] = pos;
        }
    }
    
    void pop() {
        key[heap[1].first] = 0;
        heap[1] = heap[sz--];
        if( sz == 0 )   return;
        key[heap[1].first] = 1;
        for( int pos = 1, c; ( c = pos<<1 ) <= sz; pos = c ) {
            if( c < sz && Op()( heap[c+1].second, heap[c].second ) ) ++c;
            if( Op()( heap[c].second, heap[pos].second ) ) {
                swap( heap[c], heap[pos] );
                key[heap[c].first] = c;
                key[heap[pos].first] = pos;
            }
            else break;
        }
    }

};

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//                    计算几何类 v1.12                  //
////////////////////// Documentation /////////////////////
//                                                      //
//                    Default                           // 
//                                                      //
// 1.3  增加多边形类，带有求面积方法。                  //
// 1.4  增加多边形方法，判断点是否在多边形内。          //
// 1.5  增加多边形方法，球多边形凸包。                  //
// 1.6  增加多边形方法，求多边形重心。                  //
// 1.7  增加了数值积分方法。                            // 
// 1.8  增加了点类标量运算、点与线的关系运算。          // 
// 1.9  增加了圆类，点到圆的切线。(有待测试)            //
// 1.10 增加了判断一组线段是否有交点的类。              //
// 1.11 增加了最近点对算法模块。                        // 
// 1.12 升级了凸包模块，提升了效率并分离了接口。        // 
//                                                      //
//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm> 
using namespace std; 

class Point;    // 点、矢量类（x 坐标和 y 坐标） 
class Arrow;    // 有向线段类（起点和终点） 
class Line;     // 直线类 
class Circle;   // 圆类 
class Polygon;  // 多边形 

const double INF = 1e30;
const double EPS = 1e-8;
const double PI = acos( -1.0 );

inline bool eq( double x, double y ) { return x-y < EPS && y-x < EPS; }
inline bool ne( double x, double y ) { return x-y > EPS || y-x > EPS; }
inline bool gt( double x, double y ) { return x-y > EPS; }
inline bool ge( double x, double y ) { return y-x < EPS; }
inline bool lt( double x, double y ) { return y-x > EPS; }
inline bool le( double x, double y ) { return x-y < EPS; }

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
const Point operator*( Point a, double k ) { return Point( a.x*k, a.y*k ); }
const Point operator*( double k, Point a ) { return Point( a.x*k, a.y*k ); }
const Point operator+( Point a, double k ) { return Point( a.x+k, a.y+k ); }
const Point operator+( double k, Point a ) { return Point( a.x+k, a.y+k ); }
const Point operator-( Point a, double k ) { return Point( a.x-k, a.y-k ); }
const Point operator-( double k, Point a ) { return Point( k-a.x, k-a.y ); }
const Point operator-( Point a ) { return Point( -a.x, -a.y ); }
const Point operator/( Point a, double k ) { return Point( a.x/k, a.y/k ); }
inline double dist( Point a, Point b ) { return hypot(a.x-b.x, a.y-b.y ); }
inline double area( Point a, Point b, Point p3 ) { return fabs((a-b)*(a-p3))/2.0; }
inline double Point::angle()
    { if( zr(x)&&ps(y) ) return PI / 2.0;
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
    inline bool on_arrow( Point p ) { return zr((a-p)*(p-b))&&nn((a-p)^(p-b)); } 
}; 

// 线段是否相交(存在重合点)，重合(所有点重合)，平行，重叠(有不止一点重合) 
inline bool cross( Arrow v, Arrow w ) {
    if( v.on_arrow( w.a ) || v.on_arrow( w.b ) ||
        w.on_arrow( v.a ) || w.on_arrow( v.b ) ) return true;
    return ( ps((v.a-w.a)*(w.b-w.a)) ^ ps((v.b-w.a)*(w.b-w.a)) )
        && ( ps((w.a-v.a)*(v.b-v.a)) ^ ps((w.b-v.a)*(v.b-v.a)) );
}
inline bool superp( Arrow v, Arrow w )
    { return v.a==w.a && v.b==w.b || v.b==w.a && v.a==w.b; }
inline bool parallel( Arrow v, Arrow w )
    { return parallel(v.a-v.b, w.a-w.b) || parallel(v.a-v.b, w.b-w.a); }
inline bool overlap( Arrow v, Arrow w ) {
    if( !parallel(v, w) || zr(v.length()) || zr(w.length()) ) return false;
    if( superp( v, w ) ) return true;
    if( v.b < v.a ) swap( v.a, v.b );
    if( w.b < w.a ) swap( w.a, w.b );
    if( w.a < v.a ) swap( v, w );
    return v.b!=w.a && parallel( v.a-v.b, w.a-v.b );
}


// 直线类，给的是一般式的三个系数 
struct Line {
    double  A,  B,  C;
    // 一般式 
    Line( double A = 0, double B = 0, double C = 0 ) :
        A( A ), B( B ), C( C ) {} 
    // 两点式 
    Line( Point a, Point b ) : A( b.y-a.y ), B( a.x-b.x ),
        C( a.x*(a.y-b.y) + a.y*(b.x-a.x) ) {}
    // 点斜式
    Line( double k, Point p ) : A( k ), B( -1 ),
        C( p.y - k * p.x ) {}
    Line( Point p, double k ) : A( k ), B( -1 ),
        C( p.y - k * p.x ) {}
    // 线段生成直线 
    explicit Line( Arrow v ) { *this = Line( v.a, v.b ); }
}; 

// 直线重合、相交、平行、直线交点、线段交点、三直线围面积 
inline bool superp( Line p, Line q )
    { return eq( p.A*q.B, p.B*q.A ) && eq( p.A*q.C, p.C*q.A ); }
inline bool cross( Line p, Line q )
    { return ne( p.A*q.B, p.B*q.A ); }
inline bool parallel( Line p, Line q ) 
    { return eq( p.A*q.B, p.B*q.A ) && ne( p.A*q.C, p.C*q.A ); }
    
// 垂足，反射点，点线距，线线距 
double dist( Point p, Line l ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Line l, Point p ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Arrow a, Point p ) {
    if( le( fabs( angle(a.a-p, a.a-a.b) ), PI/2.0 ) &&
        le( fabs( angle(a.b-p, a.b-a.a) ), PI/2.0 ) )
        return  dist( p, Line( a ) );
    return  min( dist( p, a.a ), dist( p, a.b ) );
}
double dist( Point p, Arrow a ) { return dist( a, p ); }
double dist( Arrow a, Arrow b ) {
    if( cross( a, b ) ) return  0.0;
    return  min( min( dist( a.a, b ), dist( a.b, b ) ),
                 min( dist( a, b.a ), dist( a, b.b ) ) );
}

//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////

#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

Arrow   S[1000];

Arrow getSeg( double x, double y, double d ) {
    Arrow   ans;
    ans.a.x = ans.b.x = x;
    ans.a.y = ans.b.y = y;
    if( ps(d) ) ans.b.x += d;
    else        ans.b.y -= d;
    return  ans;
}

double disX( int i, int j ) { return  dist( S[i], S[j] ); }

int main() {

    int     N;

    MBH<1000, double>   hp;
    
    bool    B[1000];
    
    double  ans;
    
    while( scanf( "%d", &N ) && N ) {
        hp.clear();
        memset( B, 0, sizeof( B ) );
        for( int i = 0; i < N; ++i ) {
            double x,  y,  d;
            cin >> x >> y >> d;
            S[i] = getSeg( x, y, d );
        }
        hp.push( 0, ans = 0.0 );
        while( !hp.empty() ) {
            int v = hp.top().first;
            ans >?= hp.top().second;
            hp.pop();
            B[v] = true;
            if( v == 1 ) break;
            for( int w = 0; w < N; ++w )
                if( !B[w] )
                    hp.push( w, disX( v, w ) );
        }
        if( zr( ans ) ) ans = EPS;
        cout.setf( ios::fixed );
        cout.precision( 2 );
        cout << ans << endl;
    }
    
}
