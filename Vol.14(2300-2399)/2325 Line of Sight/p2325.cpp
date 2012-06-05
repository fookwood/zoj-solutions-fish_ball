//////////////////////////////////////////////////////////////////////////
//                     Geometric class, Version 2.0                     //
//////////////////////////////////////////////////////////////////////////
//                                                                      //                                                                      //
//  V2.0(2008-9-16):                                                    // 
//      -Rewrite all basic component from V1.12;                        //
//                                                                      //
//////////////////////////////////////////////////////////////////////////
//                   Powered by ELF, Copyright(c) 2008                  //
//////////////////////////////////////////////////////////////////////////

#ifndef GEOMETRIC20_XPER
#define GEOMETRIC20_XPER

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//             Constants and precision comaprision operator.            //
//////////////////////////////////////////////////////////////////////////

const double PI = acos(-1.0);
const double EPS = 1e-10;

struct Point;
struct Segment;
struct Line;
struct Circle;
struct Polygon;
typedef Point Vector;
typedef Segment Rectangle;

double hypot(double lhs, double rhs)
    { return sqrt(lhs*lhs+rhs*rhs); }

inline bool lt(double lhs, double rhs) { return rhs - lhs >= EPS; }
inline bool le(double lhs, double rhs) { return rhs - lhs >= -EPS; }
inline bool gt(double lhs, double rhs) { return lhs - rhs >= EPS; }
inline bool ge(double lhs, double rhs) { return lhs - rhs >= -EPS; }
inline bool eq(double lhs, double rhs) { return fabs(rhs-lhs) < EPS; }
inline bool ne(double lhs, double rhs) { return fabs(rhs-lhs) >= EPS; }

inline bool zr(double lhs) { return fabs(lhs) < EPS; }
inline bool nz(double lhs) { return fabs(lhs) >= EPS; }
inline bool ps(double lhs) { return lhs >= EPS; }
inline bool nn(double lhs) { return lhs >= -EPS; }
inline bool ng(double lhs) { return lhs < -EPS; }
inline bool np(double lhs) { return lhs < EPS; }

//////////////////////////////////////////////////////////////////////////
//                        Point struct definition.                      //
//////////////////////////////////////////////////////////////////////////

struct Point {
    double x, y;
    Point(double x=0, double y=0) : x(x), y(y) {}
    void get() { scanf("%lf%lf", &x, &y); }
    void put() const { printf("(%lf, %lf)", x, y); }
    operator bool() const { return nz(x) && nz(y); }
    double length() const { return sqrt(x*x+y*y); }
};

// Point struct stream operator.
istream& operator>>(istream& is, Point& p) 
    { return is >> p.x >> p.y;}
ostream& operator<<(ostream& os, const Point& p) 
    { return os << "(" << p.x << ", " << p.y << ")"; }

// Point struct comparision operator.
bool operator==(const Point& lhs, const Point& rhs)
    { return eq(lhs.x, rhs.x) && eq(lhs.y, rhs.y); }
bool operator!=(const Point& lhs, const Point& rhs)
    { return ne(lhs.x, rhs.x) && ne(lhs.y, rhs.y); }
bool operator<(const Point& lhs, const Point& rhs)
    { return lt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && lt(lhs.y, rhs.y); }
bool operator<=(const Point& lhs, const Point& rhs)
    { return lt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && le(lhs.y, rhs.y); }
bool operator>(const Point& lhs, const Point& rhs)
    { return gt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && gt(lhs.y, rhs.y); }
bool operator>=(const Point& lhs, const Point& rhs)
    { return gt(lhs.x, rhs.x) || eq(lhs.x, rhs.x) && ge(lhs.y, rhs.y); }

// Point struct scalar operator.
const Point operator+(const Point& lhs, double rhs)
    { return Point(lhs.x+rhs, lhs.y+rhs); }
const Point operator+(double lhs, const Point& rhs)
    { return Point(lhs+rhs.x, lhs+rhs.y); }
const Point operator-(const Point& lhs, double rhs)
    { return Point(lhs.x-rhs, lhs.y-rhs); }
const Point operator-(double lhs, const Point& rhs)
    { return Point(lhs-rhs.x, lhs-rhs.y); }
const Point operator*(double lhs, const Point& rhs)
    { return Point(lhs*rhs.x, lhs*rhs.y); }
const Point operator*(const Point& lhs, double rhs)
    { return Point(lhs.x*rhs, lhs.y*rhs); }
const Point operator/(const Point& lhs, double rhs)
    { return Point(lhs.x/rhs, lhs.y/rhs); }
Point& operator+=(Point& lhs, double rhs)
    { lhs.x += rhs; lhs.y += rhs; return lhs; }
Point& operator-=(Point& lhs, double rhs)
    { lhs.x -= rhs; lhs.y -= rhs; return lhs; }
Point& operator*=(Point& lhs, double rhs)
    { lhs.x *= rhs; lhs.y *= rhs; return lhs; }
Point& operator/=(Point& lhs, double rhs)
    { lhs.x /= rhs; lhs.y /= rhs; return lhs; }

// Point struct vector operator.
const Point operator+(const Point& lhs, const Point& rhs)
    { return Point(lhs.x+rhs.x, lhs.y+rhs.y); }
const Point operator-(const Point& lhs, const Point& rhs)
    { return Point(lhs.x-rhs.x, lhs.y-rhs.y); }
const Point operator~(const Point& lhs) 
    { return Point(-lhs.y, lhs.x); }
double operator^(const Point& lhs, const Point& rhs)
    { return lhs.x*rhs.y - lhs.y*rhs.x; }
double operator*(const Point& lhs, const Point& rhs)
    { return lhs.x*rhs.x + lhs.y*rhs.y; }
Point& operator+=(Point& lhs, const Point& rhs)
    { lhs.x += rhs.x; lhs.y += rhs.y; return lhs; }
Point& operator-=(Point& lhs, const Point& rhs)
    { lhs.x -= rhs.x; lhs.y -= rhs.y; return lhs; }

//////////////////////////////////////////////////////////////////////////
//                       Segment struct definition.                     //
//////////////////////////////////////////////////////////////////////////

struct Segment {
    Point a, b;
    Segment() : a(), b() {}
    Segment(Point a, Point b) : a(a), b(b) {}
};

//////////////////////////////////////////////////////////////////////////
//                         Line struct definition.                      //
//////////////////////////////////////////////////////////////////////////

struct Line {
    double A, B, C;
    Line() : A(0), B(0), C(0) {}
    Line(double A, double B, double C) : A(A), B(B), C(C) {}
    Line(const Point& lhs, const Point& rhs) :
        A(rhs.y - lhs.y), B(lhs.x - rhs.x), C(-(lhs.x*A+lhs.y*B)) {}
    Line(double slope, const Point& p) :
        A(slope), B(-1.0), C(p.y-slope*p.x ) {}
    Line(const Point& p, double slope) :
        A(slope), B(-1.0), C(p.y-slope*p.x ) {}
    Line(const Segment& s) { *this = Line(s.a, s.b); }
    double eval(const Point& p) const { return A*p.x+B*p.y+C; }
};

//////////////////////////////////////////////////////////////////////////
//                        Circle struct definition.                     //
//////////////////////////////////////////////////////////////////////////

struct Circle {
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r) : c(c), r(r) {}
    Circle(double r, Point c) : c(c), r(r) {}
}; 

//////////////////////////////////////////////////////////////////////////
//                       Polygon struct definition.                     //
//////////////////////////////////////////////////////////////////////////

struct Polygon : public vector<Point> {
    Polygon() : vector<Point>(0) {}
    Polygon(const Polygon& P) : vector<Point>(P) {}
    Polygon(const vector<Point>& V) : vector<Point>(V) {}
    template<class Iter> Polygon(Iter begin, Iter end) :
        vector<Point>(begin, end) {}
    double area() const;
    const Point center() const;
    int within(const Point& p) const;
};

double Polygon::area() const {
    double ans = 0.0;
    for(int i=0; i<size(); ++i)
        ans += (at(i) ^ at((i+1)%size()));
    return fabs(ans)*0.5;
}

const Point Polygon::center() const {
    Point ans(0, 0), p;
    double W = 0.0, w;
    for(int i=0; i<size(); ++i) {
        W += (w = (at(i) ^ at((i+1)%size())));
        p = (at(i) + at((i+1)%size())) / 3.0 * w;
        ans += p;
    }
    return ans / W;
}

int quadrant(const Point& p) {
    if(zr(p.x) && zr(p.y))  return -1;
    if(p.x > 0 && p.y >= 0) return 0;
    if(p.x <= 0 && p.y > 0) return 1;
    if(p.x < 0 && p.y <= 0) return 2;
    if(p.x >= 0 && p.y < 0) return 3;
}

// onside returns -1, while within returns 1, outside returns 0
int Polygon::within(const Point& p) const {
    int n = 0, qa, qb;
    Point a, b = back() - p;
    for(int i=0; i<size(); ++i) {
        qa = quadrant(a=b);
        qb = quadrant(b=at(i)-p);
        if(qa==-1 || qb==-1) return -1;
        else if(qa==qb) continue;
        else if(qa==(qb+3)%4) ++n;
        else if(qa==(qb+1)%4) --n;
        else if(zr(a^b)) return -1;
        else n += ps(a^b) ? 2 : -2;
    }
    return n ? 1 : 0;
}

//////////////////////////////////////////////////////////////////////////
//                       Relations between objects.                     //
//////////////////////////////////////////////////////////////////////////

bool cross(const Line& l, const Segment& s) {
    double a = l.eval(s.a), b = l.eval(s.b);
    return zr(a) || zr(b) || ps(a)^ps(b);
}
bool cross(const Segment& s, const Line& l)
    { return cross(l, s); }
bool onSegment(const Point& p, const Segment& s)
    { return zr((p-s.a)^(p-s.b)) && np((p-s.a)*(p-s.b)); }
bool cross(const Segment& v, const Segment& w) {
    if(onSegment(v.a, w) ||
        onSegment(v.b, w) ||
        onSegment(w.a, v) ||
        onSegment(w.b, v))
        return true;
    return ( ps((v.a-w.a)^(w.b-w.a)) ^ ps((v.b-w.a)^(w.b-w.a)) )
        && ( ps((w.a-v.a)^(v.b-v.a)) ^ ps((w.b-v.a)^(v.b-v.a)) );
}
const Point intersect(Line a, Line b) {
    return Point( (a.B*b.C-b.B*a.C)/(b.B*a.A-a.B*b.A),
                  (a.A*b.C-b.A*a.C)/(b.A*a.B-a.A*b.B) );
}
const Point pedal(const Line& l, const Point& p ) {
    double k = l.eval(p)/(l.A*l.A+l.B*l.B);
    return Point(p.x-l.A*k, p.y-l.B*k);
}
const Point pedal(const Point& p, const Line& l)
    { return pedal(l, p); }
const Point mirror(const Line& l, const Point& p)
    { return pedal(l, p) * 2.0 - p; }
const Point mirror(const Point& p, const Line& l)
    { return pedal(l, p) * 2.0 - p; }
const Line bisector(const Point& a, const Point& b)
    { return Line((a+b)/2.0, (a+b)/2.0+~(a-b)); }
//const Circle circumcircle(const Point& a, const Point& b, const Point& c) {
//    Point p = intersect(Line(a, b), Line(b, c));
//    return Circle(p, dist(a, p));
//}

//////////////////////////////////////////////////////////////////////////
//                       Distances between objects.                     //
//////////////////////////////////////////////////////////////////////////

double dist(const Point& lhs, const Point& rhs)
    { return (lhs-rhs).length(); }
double dist(const Point& p, const Line& l)
    { return fabs(l.eval(p))/hypot(l.A, l.B); }
double dist(const Line& l, const Point& p)
    { return fabs(l.eval(p))/hypot(l.A, l.B); }
double dist(const Segment& s, const Point& p) {
    if(ps((s.a-p)*(s.a-s.b))^ps((s.b-p)*(s.b-s.a))) 
        return min(dist(s.a, p), dist(s.b, p));
    return dist(p, Line(s.a, s.b));
}
double dist(const Point& p, const Segment& s)
    { return dist(s, p); } 
double dist(const Line& l, const Segment& s) {
    if(cross(l, s)) return 0.0;
    return min(dist(s.a, l), dist(s.b, l));
}
double dist(const Segment& s, const Line& l)
    { return dist(l, s); }

//////////////////////////////////////////////////////////////////////////
//                       Basic triangle operation.                      //
//////////////////////////////////////////////////////////////////////////

//   We assume that the three vertex of the triangle is pA-pB-pC,
// while the angle assign to them are A-B-C, and the opposite side
// of them are a-b-c, the funtions below follows this rule of signs.

// Area of triagles calculation functions.
double areaSSA(double a, double b, double C)
    { return 0.5*a*b*sin(C); }
double areaSSS(double a, double b, double c)
    { double s=(a+b+c)*0.5; return sqrt(s*(s-a)*(s-b)*(s-c)); }
double areaSAA(double a, double B, double C)
    { return a*a*0.5/(1.0/tan(B)+1.0/tan(C)); }
double area(const Point& pA, const Point& pB, const Point& pC)
    { return fabs((pB-pA)^(pC-pA))*0.5; }
double area(const Vector& v, const Vector& w)
    { return fabs(v^w)*0.5; }
double side_c(double a, double b, double C = PI/2.0) {
    double ans = a*a + b*b - 2.0*a*b*cos(C);
    return nn(ans) ? sqrt(fabs(ans)) : -1.0;
}

//////////////////////////////////////////////////////////////////////////
//                      Polygon Method: Convex Hull                     //
//////////////////////////////////////////////////////////////////////////

Point refP, ctrP;
double xmult(Point lhs, Point rhs, Point ref) {
    return (lhs - ref) ^ (rhs - ref);
}
    
bool acmp(const Point& lhs, const Point& rhs) {
    return  ng(xmult(lhs, rhs, refP)) ||
            zr(xmult(lhs, rhs, refP)) &&
            ng(xmult(lhs, rhs, ctrP));
}
const Polygon ConvexHull(Polygon P) {
    int i, k = 0;
    for(refP = ctrP = P[0], i = 1; i < P.size(); ++i ) {
        ctrP = ctrP + P[i];
        if(gt(refP.y, P[i].y) || eq(refP.y, P[i].y) &&
            gt(refP.x, P[i].x))  refP = P[k=i];
    }
    ctrP.x /= P.size();
    ctrP.y /= P.size();
    swap(P[k], P[0]);
    sort(P.begin() + 1, P.end(), acmp);
    if( P.size() < 3 )  return  P;
    Polygon CH(P.begin(), P.begin() + 3);
    for(i = k = 3; i < P.size(); ++i, ++k) {
        while(k > 2 && np(xmult(CH[k-2], P[i], CH[k-1])))
            {CH.pop_back(); k--;}
        CH.push_back( P[i] );
    }
    return CH;
}

#endif // GEOMETRIC20_XPER

//////////////////////////////////////////////////////////////////////////
//                     Geometric class, Version 2.0                     //
//                   Powered by ELF, Copyright(c) 2008                  //
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Obj {
    double x1, x2, y;
    bool get() {
        cin >> x1 >> x2 >> y;
        return x1 || x2 || y;
    }
};

Obj result, house, temp;
double Y;
vector<Obj> V;

Line ground(0, 1, 0);

int N;

const double anchor = 1e300;
class SegCut {
    deque<Point> Q;
public:
    void clear() {Q.clear(); Q.push_back(Point(anchor, anchor));}
    void push(Point p) {Q.push_front(p);}
    void insert(Point p) {
        while(Q.front().x != anchor) {
            Point q = Q.front();
            Q.pop_front();
            if(ge(p.x, q.y) || le(p.y, q.x)) continue;
            if(ge(p.x, q.x)) Q.push_back(Point(q.x, p.x));
            if(le(p.y, q.y)) Q.push_back(Point(p.y, q.y));
        }
        Q.push_back(Q.front());
        Q.pop_front();
    }
    double maxLen() {
        double len = 0;
        for(int i = 0; i + 1 < Q.size(); ++i)
            len = max(len, Q[i].y - Q[i].x);
        return len;
    }
} sc;

int main() {
    
//    freopen("test1.in", "r", stdin);
//    freopen("test.out", "w", stdout);
    
    while(house.get()) {

        result.get();
        Y = result.y;
        result.y -= Y;
        house.y -= Y;
        cin >> N;
        V.clear();
        for(int i = 0; i < N; ++i) {
            temp.get();
            temp.y -= Y;
            if(temp.y >= house.y ||
                temp.y <= result.y)
                continue;
            V.push_back(temp);
        }
        N = V.size();
        
        double px1, px2;
        
        sc.clear();
        sc.push(Point(result.x1, result.x2));
        
        for(int i = 0; i < N; ++i) {
            px1 = intersect(
                Line(
                    Point(house.x1, house.y),
                    Point(V[i].x2, V[i].y)
                ),
                ground
            ).x;
            px2 = intersect(
                Line(
                    Point(house.x2, house.y),
                    Point(V[i].x1, V[i].y)
                ),
                ground
            ).x;
            sc.insert(Point(px2, px1));
        }
        
        double ans = sc.maxLen();
        if(zr(ans)) puts("No View");
        else printf("%.2lf\n", ans + EPS);
        
    }
    
}
