// 1665502 2008-10-13 20:22:25 Accepted  1550 C++ 0 184 呆滞的慢板 

// 判别一个长方形能否放到另一个长方形中。
// 如果能正放，直接 YES，如果完全不可能，直接 NO。
// 否则，斜放，用一条边距离的平行线卡住长方形，求两端的宽是否小于另一边长。
 

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-12;

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

bool check(double X, double Y, double A, double B) {
    if(X > Y) swap(X, Y);
    if(A > B) swap(A, B);
    double R = hypot(X, Y), W;
    double theta = asin(X/R);
    if(le(X, A) && le(Y, B)) return true;
    if(ge(X, A) && ge(Y, B)) return false;
        if(Y > B && X < B) {
            W = R * sin(PI/2 - asin(B/R) + 2 * theta);
            if(W <= A) return true;
        }
        swap(A, B);
        if(Y > B && X < B) {
            W = R * sin(PI/2 - asin(B/R) + 2 * theta);
            if(W <= A) return true;
        }
    return false;
}

int main() {
    double A, B, C, D, E;
    while(cin >> A >> B >> C >> D >> E) {
        if(check(A, B, D, E) ||
            check(A, C, D, E) ||
            check(B, C, D, E)) puts("YES");
        else puts("NO");
    }
}
