//////////////////////////////////////////////////////////
//                      ·ÖÊýÄ£°å v1.0                   //
//////////////////////////////////////////////////////////

#ifndef FRACTION_XPER
#define FRACTION_XPER

#include <iostream>

typedef long long i64;

i64 gcd(i64 m, i64 n) { return n ? gcd(n, m%n) : m; }
i64 lcm(i64 m, i64 n) { return m / gcd(m, n) * n; }
i64 sign(i64 x) { return x > 0 ? 1 : -1; }
i64 abs(i64 x) { return x > 0 ? x : -x; }

struct Fraction {
    i64 a,  b;
    Fraction(i64 x = 0, i64 y = 1) {
        i64 m = gcd(abs(x), abs(y));
        a = x / m * sign(y);
        b = a ? abs(y / m) : 1;
    }
    operator double() const { return double(a)/double(b); }
    const Fraction operator -() {return Fraction(-a, b);}
};

Fraction abs(const Fraction& x) { return Fraction(x.a < 0 ? -x.a : x.a, x.b); }

const Fraction operator+(const Fraction& x, const Fraction& y) {
    i64 m = gcd(x.b, y.b);
    return  Fraction( y.b/m*x.a + x.b/m*y.a, x.b/m*y.b );
}

const Fraction operator-(const Fraction& x, const Fraction& y) {
    i64 m = gcd(x.b, y.b);
    return  Fraction( y.b/m*x.a - x.b/m*y.a, x.b/m*y.b );
}

const Fraction operator*(const Fraction& x, const Fraction& y) {
    i64 m1 = gcd(abs(x.a), y.b),
        m2 = gcd(abs(y.a), x.b);
    return  Fraction(x.a/m1 * y.a/m2, x.b/m2 * y.b/m1);
}

const Fraction operator/(const Fraction& x, const Fraction& y) {
    return  x * Fraction(y.b, y.a);
}

bool operator<(const Fraction& x, const Fraction& y) {
    return x.a*y.b - x.b*y.a < 0;
}    

std::ostream& operator<<(std::ostream& out, const Fraction& x) {
    if(x.a == 0)        return out << 0;
    else if(x.b == 1)   return out << x.a;
    else                return out << x.a << '/' << x.b;
}

#endif // FRACTION_XPER


#include <vector>
#include <complex> 
#include <cmath>
#include <limits>
#include <algorithm>

const double EPS = 1e-10;

// Polynomial below:
// c[0] + c[1]*x + c[2]*x^2 + ... + c[n]*x^N.
// Express as a vector<double> of indices [0..N].
typedef std::vector<Fraction> Poly;

// Polynomial evaluation.
double polyval(const Poly& c, const double x) {
    size_t n = c.size() - 1;
    double p = c[n];
    while(n > 0) p = p * x + double(c[--n]);
    return p;
}

#include <iostream>
using namespace std;

// Polynomial addition a(x) += k * b(x).
void add(Poly& a, const Poly& b, const Fraction& k) {
    if(a.size() < b.size())
        a.resize(b.size(), 0);
    for(int i = 0; i < b.size(); ++i)
        a[i] = a[i] + k * b[i];
}

// Generate from (x+1)^k to (x+1)^(k+1).
void next(Poly& B) {
    for(int i = B.size() - 1; i >= 1; --i)
        B[i] = B[i] + B[i-1];
    B.push_back(1);
}

Poly S[11];

// Generate all Sigma(i^k, 1..n) to S[1..K].
void init(int K = 10, Poly* S = S) {
    S[0].assign(2, 0);
    S[0][1] = 1;
    Poly B(2, 1);
    for(int k = 1; k <= K; ++k) {
        next(B);
        S[k].resize(k + 2, 0);
        S[k][k+1] = 1;
        for(int i = 0; i < k; ++i)
            add(S[k], S[i], -B[i]);
        for(int i = 0; i < S[k].size(); ++i)
            S[k][i] = S[k][i] / Fraction(k + 1);
    }
}

int main() {
    init();
    Poly now;
    int N;
    double left, right, ans;
    while(cin >> N) {
        now.resize(N+1);
        for(int i = N; i >= 0; --i)
            cin >> now[i].a;
        cin >> left >> right;
        ans = 0;
        for(int i = 0; i <= N; ++i) {
            if(right > 0 || i % 2 == 0)
                ans += double(now[i]) * polyval(S[i], fabs(right));
            else
                ans -= double(now[i]) * polyval(S[i], fabs(right));
            if(left > 0 || i % 2)
                ans -= double(now[i]) * polyval(S[i], fabs(left - 1.0));
            else
                ans += double(now[i]) * polyval(S[i], fabs(left - 1.0));
        }
        printf("%.6le\n", ans);
    }
}
