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
#include <limits> 
#include <cmath> 
#include <set>
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
const double EPS = 1e-8;
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
inline double square( double x, double y ) { return x*x + y*y; }
inline double hypot( double x, double y ) { return sqrt( x*x+y*y ); }

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
void get( Point& p ) { scanf( "%lf%lf", &p.x, &p.y ); }

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
inline double dist2( Point a, Point b ) { return square(a.x-b.x, a.y-b.y ); }
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
    // 返回斜率 
    double slope() const
        { return  zr( B ) ? zr( A ) ? NaN : INF : -A / B; }
}; 

// 直线重合、相交、平行、直线交点、线段交点、三直线围面积 
inline bool superp( Line p, Line q )
    { return eq( p.A*q.B, p.B*q.A ) && eq( p.A*q.C, p.C*q.A ); }
inline bool cross( Line p, Line q )
    { return ne( p.A*q.B, p.B*q.A ); }
inline bool parallel( Line p, Line q ) 
    { return eq( p.A*q.B, p.B*q.A ) && ne( p.A*q.C, p.C*q.A ); }
inline Point intersect( Line p, Line q ) {
    if( superp( p, q ) )    return Point( NaN, NaN ); 
    if( parallel( p, q ) )  return Point( INF, INF );
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
    
// 垂足，反射点，点线距，线线距，点角式 
const Point pedal( Line l, Point p ) {
    if( zr( l.slope() ) ) return intersect( Line( 1.0, 0.0, -p.x ), l );
    return intersect( Line( p, -1.0 / l.slope() ), l );
}
const Point pedal( Point p, Line l ) { return pedal( l, p ); }
const Point reflect( Line l, Point p ) { return pedal( l, p ) * 2.0 - p; }
const Point reflect( Point p, Line l ) { return pedal( l, p ) * 2.0 - p; }
double dist( Point p, Line l ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Line l, Point p ) { return fabs(l.A*p.x+l.B*p.y+l.C)/hypot(l.A,l.B); }
double dist( Arrow a, Point p ) {
    double  ans = min( dist( p, a.a ), dist( p, a.b ) );
    if( a.on_arrow( pedal( p, Line( a ) ) ) )
        ans = min( ans, dist( p, Line( a ) ) );
    return  ans;
}
double dist( Point p, Arrow a ) { return dist( a, p ); }
double dist( Arrow a, Arrow b ) {
    if( intersect( a, b ) ) return  0.0;
    return  min( min( dist( a.a, b ), dist( a.b, b ) ),
                 min( dist( a, b.a ), dist( a, b.b ) ) );
}
double dist( Line l, Line m ) {
    if( !parallel( l, m ) ) return 0.0;
    if( zr( l.A ) ) return  fabs(m.C/m.B*l.B-l.C)/hypot(l.A,l.B);
    else            return  fabs(m.C/m.A*l.A-l.C)/hypot(l.A,l.B);
}
const Line pBisector( Point a, Point b ) {
    Point c = (a+b)/2.0, d( c.x+a.y-b.y, c.y-a.x+b.x );
    return  Line( c, d ); 
} 
const Line paLine( Point a, double agl ) {
    if( eq( fmod( fabs( agl ), PI ), PI / 2.0 ) )
            return  Line( 1.0, 0.0, -a.x ); 
    else    return  Line( a, tan( agl ) );
}
const Line paLine( double agl, Point a ) { return paLine( a, agl ); }


//////////////////////////////////////////////////////////
//               2008 CopyRight(c) by elf               //
//////////////////////////////////////////////////////////


// 圆类实现 
struct Circle {
    Point   c;
    double  r;
    Circle( Point c = Point(), double r = 1.0 ) :
        c( c ), r( r ) {}
    Circle( double x, double y, double r ) :
        c( x, y ), r( r ) {} 
}; 

pair<Line, Line> tangent( Point p, Circle c ) {
    double  d = dist( p, c.c );
    Line    nil = Line( NaN, NaN, NaN );
    if( lt( d, c.r ) )  return  make_pair( nil, nil );
    double  alpha = ( c.c - p ).angle();
    double  theta = eq( d, c.r ) ? PI / 2.0 : asin( c.r / d );
    return  make_pair( paLine( p, alpha + theta ),
                       paLine( p, alpha - theta ) );
}


// 多边形类实现 
class Polygon {
    
    vector<Point>   V;

public:

    // 基本操作 
    void clear() { V.clear(); }
    int size() const { return V.size(); } 
    void insert( Point a ) { V.push_back( a ); } 
     
    template<class Iter>
    void get( Iter bg, Iter ed ) { V.assign( bg, ed ); }
    void get( const vector<Point>& H ) { V = H; }
    
    // 功能类 
    double area() const;
    double perimeter() const;
    bool inside( Point ) const;
    const Point Polygon::center() const;

}; 

// 返回多边形面积 
double Polygon::area() const {
    double  ans = 0; 
    for( int i = 0; i < V.size(); ++i )
        ans += V[i] * V[(i+1)%V.size()];
    return  fabs( ans ) / 2.0; 
}

// 返回多边形重心 
const Point Polygon::center() const {
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

//////////////////////////////////////////////////////
//               凸包子模块 from v1.12              //
//////////////////////////////////////////////////////

class ConvexHull {
    
    vector<Point>   P;
    
    static Point refP,  ctrP;
    
    static double xmult( Point lhs, Point rhs, Point ref )
        { return  ( lhs - ref ) * ( rhs - ref ); }
    
    static bool acmp( const Point& lhs, const Point& rhs ) {
        return  ng( xmult( lhs, rhs, refP ) ) ||
                zr( xmult( lhs, rhs, refP ) ) &&
                ng( xmult( lhs, rhs, ctrP ) );
    }

public:
    
    template<class Iter>
    void get( Iter bg, Iter ed ) { P.assign( bg, ed ); }
    
    size_t size() const { return P.size(); }

    void clear() { P.clear(); }

    void insert( const Point& p ) { P.push_back( p ); }

    vector<Point> run() {
        int i,  k = 0;
        for( refP = ctrP = P[0], i = 1; i < P.size(); ++i ) {
            ctrP = ctrP + P[i];
            if( gt( refP.y, P[i].y ) || eq( refP.y, P[i].y ) &&
                gt( refP.x, P[i].x ) )  refP = P[k=i];
        }
        ctrP = ctrP / P.size();
        swap( P[k], P[0] );
        sort( P.begin() + 1, P.end(), acmp );
        if( P.size() < 3 )  return  P;
        vector<Point>   ans( P.begin(), P.begin() + 3 );
        for( i = k = 3; i < P.size(); ++i, ++k ) {
            while( k > 2 && ng( xmult( ans[k-2], P[i], ans[k-1] ) ) )
                { ans.pop_back(); k--; }
            ans.push_back( P[i] );
        }
        return  ans;
    }
    
    static vector<Point> tidy( vector<Point> V ) {
        int N = V.size();
        vector<Point>   ans( 0 );
        for( int i = 0; i < N; ++i ) {
            double  crs = (V[i]-V[(i+N-1)%N])*(V[i]-V[(i+1)%N]);
            double  inr = (V[i]-V[(i+N-1)%N])^(V[i]-V[(i+1)%N]);
            if( !( zr( crs ) && np( inr ) ) )
                ans.push_back( V[i] );
        }
        return  ans;
    }
    
}; 

Point ConvexHull::refP = Point();
Point ConvexHull::ctrP = Point();

//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////

/*
//////////////////////////////////////////////////////
//            线段集相交子模块 from v1.10           //
//////////////////////////////////////////////////////

// 判断一组线段是否存在交点
class AnyIntersect {
    
    static  double  x;
    
    class Op {
    public:
        bool operator () ( const Arrow& a, const Arrow& b ) {
            double  h1, h2;
            if( eq( a.a.x, a.b.x ) ) 
                    h1 = a.a.y;
            else    h1 = intersect( Line( a ), Line( -1, 0, x ) ).y;
            if( eq( b.a.x, b.b.x ) ) 
                    h2 = b.a.y;
            else    h2 = intersect( Line( b ), Line( -1, 0, x ) ).y;
            return  h1 < h2;
        }
    };
    
    vector<Arrow>   V; 
    set<Arrow, Op>  S;
    vector<pair<Point, int> >   P; 
    
public:
    
    void clear() { V.clear(); }
    
    void insert( Arrow a ) {
        if( ! ( a.a < a.b ) ) swap( a.a, a.b );
        P.push_back( make_pair( a.a, V.size() ) );
        P.push_back( make_pair( a.b, V.size() ) );
        V.push_back( a );
    }
    
    void insert( Point a, Point b ) { insert( Arrow( a, b ) ); }
    
    bool run() {
        sort( P.begin(), P.end() );
        S.clear();
        set<Arrow, Op>::iterator    it1,    it2; 
        for( int i = 0; i < P.size(); ++i ) {
            Arrow   now = V[P[i].second];
            x = P[i].first.x;
            if( P[i].first == now.a ) {
                it1 = S.insert( now ).first;
                if( it1 != S.begin() ) {
                    it2 = it1;
                    --it2;
                    if( cross( *it2, *it1 ) )
                        return  true;
                }
                it2 = it1;
                if( ++it2 != S.end() && cross( *it2, *it1 ) )
                    return  true;
            }
            else {
                it2 = it1 = S.find( now );
                if( it1 != S.begin() && ++it2 != S.end() ) {
                    --it1;
                    if( cross( *it1, *it2 ) )
                        return  true;
                }
                S.erase( now );
            } 
        } 
        return  false;
    } 
    
};

double AnyIntersect::x = 0;

//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////
*/

//////////////////////////////////////////////////////
//              最近点对子模块 from v1.11           //
//////////////////////////////////////////////////////

template<int SZ> 
class Nearest {

    Point   P[SZ];
    Point   *X[SZ], *Y[SZ], *T[SZ];
    int     size;

    static bool xcmp( Point* lhs, Point* rhs )
        { return  lhs->x < rhs->x || lhs->x == rhs->x && lhs->y < rhs->y; }

    static bool ycmp( Point* lhs, Point* rhs )
        { return  lhs->y < rhs->y || lhs->y == rhs->y && lhs->x < rhs->x; }

    double nearest( int l, int r ) {
        if( r - l <= 2 ) return dist( *X[l], *X[l+1] );
        int m = l + r >> 1;
        for( int k = l, i = l, j = m; k < r; ++k )
            if( xcmp( Y[k], X[m] ) )    T[i++] = Y[k];
            else                        T[j++] = Y[k];
        copy( T + l, T + r, Y + l );
        double ans = min( nearest( l, m ), nearest( m, r ) );
        merge( Y + l, Y + m, Y + m, Y + r, T + l, ycmp );
        copy( T + l, T + r, Y + l );
        int top = 0;
        for( int i = l; i < r; ++i )
            if( gt( Y[i]->x, X[m]->x - ans ) &&
                lt( Y[i]->x, X[m]->x + ans ) )
                T[top++] = Y[i];
        for( int i = 0; i < top; ++i )
            for( int j = i + 1; j <= i + 6 && j < top; ++j )
                ans = min( ans, dist( *T[i], *T[j] ) );
        return  ans;
    }
    
public:
    
    void clear() { size = 0; }
        
    template<class Iter>
    void get( Iter bg, Iter ed ) { size = copy( bg, ed, P ) - P; }

    void insert( const Point& p ) { P[size++] = p; } 
    
    double run() {
        for( int i = 0; i < size; ++i )
            X[i] = Y[i] = P + i;
        sort( X, X + size, xcmp );
        sort( Y, Y + size, ycmp );
        for( int i = 1; i < size; ++i )
            if( *X[i] == *X[i-1] )
                return  0;
        return  nearest( 0, size ); 
    }
    
};

//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////
//              最远点对子模块 from v1.11           //
//////////////////////////////////////////////////////

class Farthest {
public:
    vector<Point>   P;
    
    int nx( int p ) { return (p+1) % P.size(); }

    double area( int p1, int p2, int p3 ) 
        { return  fabs( (P[p1]-P[p2])*(P[p1]-P[p3]) ); }

public:
    
    template<class Iter>
    void get( Iter bg, Iter ed ) { P.assign( bg, ed ); }
    
    size_t size() const { return P.size(); }

    void clear() { P.clear(); }

    void insert( const Point& p ) { P.push_back( p ); }

    double run() {
        ConvexHull  ch;
        ch.get( P.begin(), P.end() );
        P = ch.run();
        if( P.size() == 2 ) return  dist( P[0], P[1] );
for( int i = 0; i < P.size(); ++i )
cout << P[i] << endl;puts("");
        P = ConvexHull::tidy( P );
for( int i = 0; i < P.size(); ++i )
cout << P[i] << endl;puts("");
//*
double  rt = 0;
for( int i = 0; i < P.size(); ++i ){//cout<<P[i]<<endl;
for( int j=i+1; j < P.size(); ++j )
rt = max(rt, dist(P[i],P[j]));
}
return  rt;
//*/
        if( P.size() == 2 ) return  dist( P[0], P[1] );
        int p,  q,  p0, q0;
        p = 0;  q = 1;
        while( gt( area( p, nx(p), nx(q) ), area( p, nx(p), q ) ) )
            q = nx( q );
        p0 = p; q0 = q;
        double  ans = dist2( P[p0], P[q0] );
        while( q != p0 ) {
            p = nx( p );
            while( gt( area( p, nx(p), nx(q) ), area( p, nx(p), q ) ) ) {
                q = nx( q );
                if( p == q0 && q == p0 )
                        return  sqrt( ans );
                else    ans = max( ans, dist2( P[p], P[q] ) );
            }
            //*
            if( eq( area( p, nx(p), nx(q) ), area( p, nx(p), q ) ) )
                if( p == q0 && q == p0 )
                        ans = max( ans, dist2( P[nx(p)], P[q] ) );
                else    ans = max( ans, dist2( P[p], P[nx(q)] ) );
            //*/
        }
        return  sqrt( ans );
    }
     
    
}; 

//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////



//////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf              //
//////////////////////////////////////////////////////

/*
10
5 0
0 0
2 0
6 0
9 0
8 0
1 0
7 0
4 0
3 0
*/
int main() {
    
//    freopen( "a.in", "r", stdin );
//    freopen( "a.out", "w", stdout );

Line C = pBisector( Point( 0, 1 ), Point(1, 0) ) ;
cout << C.A <<' ' C.B <<' '<< C.C << endl; 
    
    int         N;
    Farthest    far;
    Point       P;
    
    while( scanf( "%d", &N ) != EOF && N ) {
        
        far.clear();
        
        for( int i = 0; i < N; ++i ) {
            get( P );
            far.insert( P );
        }
        
        double  ans = far.run();
        
        printf( "%d\n", int( ans*ans + .1 ) );
        
    }   
    
}
