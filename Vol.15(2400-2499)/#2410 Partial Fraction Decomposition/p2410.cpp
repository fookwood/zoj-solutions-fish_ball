// 1683222 2008-10-30 18:11:09 Accepted  2410 C++ 0 184 呆滞的慢板 

// 数值算法，有理分式分解：求三次方程根，然后分母多项式除 (x-r[i])，再求有理函数值。 

#include <vector>
#include <cmath>

const double EPS = 1e-5;

// Polynomial below:
// c[0] + c[1]*x + c[2]*x^2 + ... + c[n]*x^N.
// Express as a vector<double> of indices [0..N].
typedef std::vector<double> Poly;
typedef std::vector<double> Vec;

// Simplify the polynomial, reduce the high-degree zero term.
void tidy(Poly& c) {
    while(c.size() > 1 && fabs(c.back()) < EPS)
        c.pop_back();
}

// Polynomial evaluation.
double polyval(const Poly& c, const double x) {
    size_t n = c.size() - 1;
    double p = c[n];
    while(n > 0) p = p * x + c[--n];
    return p;
}

// Evaluate all degree derivation of a polynomial.
const Vec ddpoly(const Poly& c, const double x) {
    int nc = c.size() - 1;
    Vec pd(nc+1, 0.0);
    pd[0] = c[nc];
    for(int i = nc-1; i >= 0; i--) {
        for(int j = nc-i; j > 0; j--)
            pd[j] = pd[j]*x + pd[j-1];
        pd[0] = pd[0] * x + c[i];
    }
    double cnst = 1.0;
    for(int i = 2; i < nc+1; i++) {
        cnst *= i;
        pd[i] *= cnst;
    }
    return pd;
}

// Slow convolution, multiplying two polynomials.
// Complexity: O(nu * nv).
void conv(const Poly& u, const Poly& v, Poly& w) {
    int nu = u.size(), nv = v.size();
    w.assign(nu + nv - 1, 0.0);
    for(int i = 0; i < nu; i++)
        for(int j = 0; j < nv; j++)
            w[i+j] += u[i] * v[j];
}

// Slow deconvolution, polynomial dividing.
// q returns the quotient, r returns the remainder.
void deconv(const Poly& u, const Poly& v, Poly& q, Poly& r) {
    int n = u.size() - 1;
    int nv = v.size() - 1;
    q.assign(n+1, 0.0);
    r = u;
    for(int k = n-nv; k >= 0; k--) {
        q[k] = r[nv+k] / v[nv];
        for(int j = nv+k-1; j >= k; j--)
            r[j] -= q[k] * v[j-k];
    }
    r.resize(nv);
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

double a0, a1, a2;
double b0, b1, b2;
double r1, r2, r3;
double A1, A2, A3;

const double PI = acos(-1.0);

bool zr(double x) {
    return fabs(x) < EPS;
}

int main() {

    while(cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2) {

        if(zr(a0) && zr(a1) && zr(a2)) break;

        double Q = (b2*b2 - 3.0*b1) / 9.0;
        double R = (2.0*b2*b2*b2 - 9.0*b2*b1 + 27.0*b0) / 54.0;
        double theta = acos(R/sqrt(Q*Q*Q));

        r1 = -2.0 * sqrt(Q) * cos(theta/3.0) - b2/3.0;
        r2 = -2.0 * sqrt(Q) * cos((theta+2.0*PI)/3.0) - b2/3.0;
        r3 = -2.0 * sqrt(Q) * cos((theta-2.0*PI)/3.0) - b2/3.0;
        
        r1 = round(r1);
        r2 = round(r2);
        r3 = round(r3);
        
        if(r2 > r3) swap(r2, r3);
        if(r1 > r2) swap(r1, r2);
        if(r2 > r3) swap(r2, r3);
        
        Poly b(4), a(3), w(2), q, r;
        b[0] = b0;  b[1] = b1;  b[2] = b2;  b[3] = 1;
        a[0] = a0;  a[1] = a1;  a[2] = a2;
        
        w[0] = -r1; w[1] = 1;
        deconv(b, w, q, r);
        A1 = polyval(a, r1) / polyval(q, r1);
        
        w[0] = -r2; w[1] = 1;
        deconv(b, w, q, r);
        A2 = polyval(a, r2) / polyval(q, r2);
        
        w[0] = -r3; w[1] = 1;
        deconv(b, w, q, r);
        A3 = polyval(a, r3) / polyval(q, r3);
        
        if(zr(A1)) A1 = 0.0;
        if(zr(A2)) A2 = 0.0;
        if(zr(A3)) A3 = 0.0;
        if(zr(r1)) r1 = 0.0;
        if(zr(r2)) r2 = 0.0;
        if(zr(r3)) r3 = 0.0;

        cout << r1 << ' ' << r2 << ' ' << r3 << ' ';
        printf("%.2lf %.2lf %.2lf\n", A1, A2, A3);
    }
}
