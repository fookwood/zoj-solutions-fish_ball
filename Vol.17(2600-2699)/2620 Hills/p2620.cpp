////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////

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
inline Point intersect( Line p, Line q ) {
    if( eq( p.A*q.B, p.B*q.A ) ) return Point( INF, INF );
    return Point( (p.B*q.C-q.B*p.C)/(q.B*p.A-p.B*q.A),
                  (p.A*q.C-q.A*p.C)/(q.A*p.B-p.A*q.B) );
}
inline Point intersect( Arrow v, Arrow w ) {
    return intersect( Line(v), Line(w) );
}

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
double dist( Line l, Line m ) {
    if( !parallel( l, m ) ) return 0.0;
    if( zr( l.A ) ) return  fabs(m.C/m.B*l.B-l.C)/hypot(l.A,l.B);
    else            return  fabs(m.C/m.A*l.A-l.C)/hypot(l.A,l.B);
}

////////////////////////////////////////////////////
//            2008 CopyRight(c) by elf            //
////////////////////////////////////////////////////


#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 交点坐标，所属的两条直线，在两条直线中的序号 
struct Intersect {
    Point   p;
    int     v1, v2;
    int     k1, k2;
    int other(int v) const { return v == v1 ? v2 : v1; }
    int otherk(int v) const { return v == v1 ? k2 : k1; }
};

struct Triangle {
    int p[3];
    Triangle(int x, int y, int z) {
        p[0] = x; p[1] = y; p[2] = z;
        sort(p, p+3);
    }
};

bool operator<(const Triangle& a, const Triangle& b) {
    return  a.p[0] < b.p[0] || a.p[0] == b.p[0] && (
            a.p[1] < b.p[1] || a.p[1] == b.p[1] &&
            a.p[2] < b.p[2] );
}

set<Triangle>   S;

bool cmp( Intersect* lhs, Intersect* rhs ) {
    return  lhs->p < rhs->p;
}

int     N,  M,  T;

Arrow       V[500];
Intersect   P[125000];

Intersect*  L[500][500];
vector<Intersect*>  G[500];

bool pInTriangle(const Point& p, const Point& a,
                 const Point& b, const Point& c ) {
    double  agl = angle( a-p, b-p ) +
                  angle( b-p, c-p ) +
                  angle( c-p, a-p );
    return  -PI < agl && agl < PI;
}

void next(int v, int& i, int& j) {
    if( j + 1 < G[v].size() &&
        G[v][j]->p == G[v][j+1]->p ) {
        ++j; return;
    }
    if( G[v][i] == G[v][i+1] ) {
        while( G[v][j-1] == G[v][j] ) --j;
        ++i; return;
    }
    ++i; ++j;
}

int main() {
    
    scanf( "%d", &T );
    for( int t = 1; t <= T; ++t ) {
        scanf( "%d", &N );
        for( int i = 0; i < N; ++i ) {
            scanf( "%lf%lf%lf%lf", &V[i].a.x,
                &V[i].a.y, &V[i].b.x, &V[i].b.y );
            G[i].clear();
        }
        
        
        
        
for(int i = 0; i < N; ++i)
    cout << V[i].a << " "<<V[i].b <<endl;
        
        
        
        
        memset( L, 0, sizeof( L ) );
        M = 0;
        for( int i = 0; i < N; ++i ) {
            for( int j = i + 1; j < N; ++j ) {
                if( !cross( V[i], V[j] ) ) continue;
                P[M].p = intersect( V[i], V[j] );
                P[M].v1 = i;
                P[M].v2 = j;
                L[i][j] = L[j][i] = P + M;
                G[i].push_back( P + M );
                G[j].push_back( P + M );
                ++M;
            }
        }
        
for(int i=0;i<M;++i)
cout<<"* "<<P[i].p<<endl;
puts("");

        for( int i = 0; i < N; ++i ) {
            sort( G[i].begin(), G[i].end(), cmp );
            for( int j = 0; j < G[i].size(); ++j ) {
                if( G[i][j]->v1 == i )
                        G[i][j]->k1 = j;
                else    G[i][j]->k2 = j;
            }
        }
        
for(int i=0;i<N;++i){
cout<<i<<": ";
for(int j=0;j<G[i].size();++j)cout<<G[i][j]->p<<' ';
puts("");
}
puts("");

for(int i=0;i<M;++i)
cout<<"* "<<P[i].p<<' '<<P[i].v1<<' '<<P[i].v2<<' '<<P[i].k1<<' '<<P[i].k2<<endl;
puts("");

        
        S.clear();
        
        for( int v = 0; v < N; ++v ) {
            int i = 0,  j = 0,  n = G[v].size();
cout << v<<": ";
            while( G[v][j]->p == G[v][i]->p && j < n ) ++j;
            for(; i<n && j<n; next(v, i, j)) {
cout<<"  i="<<i<<"  j="<<j<<endl;
                int x = G[v][i]->other(v), xk = G[v][i]->otherk(v),
                    y = G[v][j]->other(v), yk = G[v][j]->otherk(v);
cout<<"  x="<<x<<"  xk="<<xk<<endl;
cout<<"  y="<<y<<"  yk="<<yk<<endl;
                if( !L[x][y] )  continue;
                if( x > y ) { swap(x, y); swap(xk, yk); }
                int xv = L[x][y]->otherk(x),
                    yv = L[x][y]->otherk(y);
                if(xk > xv) swap(xk, xv);
                if(yk > yv) swap(yk, yv);
                while( xk + 1 < G[x].size() &&
                    G[x][xk]->p == G[x][xk+1]->p ) ++xk;
                while( xv - 1 >= 0 &&
                    G[x][xv]->p == G[x][xv-1]->p ) --xv;
                if( xk != xv - 1 )  continue;
                while( yk + 1 < G[y].size() &&
                    G[y][yk]->p == G[y][yk+1]->p ) ++yk;
                while( yv - 1 >= 0 &&
                    G[y][yv]->p == G[y][yv-1]->p ) --yv;
                if( yk != yv - 1 )  continue;
system("pause");
                bool yes = true;
                for( int m = 0; m < N; ++m ) {
                    if( pInTriangle( V[m].a, L[v][x]->p, L[v][y]->p, L[x][y]->p ) ||
                        pInTriangle( V[m].b, L[v][x]->p, L[v][y]->p, L[x][y]->p ) ) {
                        yes = false;
                        break;
                    }
                }
                if( yes ) S.insert( Triangle( x, y, v ) );
            }
        }
        
        printf( "Case %d:\n%d\n", t, S.size() );
        if( t != T ) puts( "" );
        
    }
    
}
