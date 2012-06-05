// 1684090 2008-10-31 14:12:08 Accepted  2431 C++ 0 184 呆滞的慢板 

// 求多项式是否可因式分解。 
// 多项式分解因式，因式只可能是一阶或者二阶的。 
// 分别对应与单个实根和一对共轭复根。 
// 因此，用多项式求根技术，求出实根的个数为 re, 复根个数为 im
// im 必为偶数，因此若 re + im/2 > 1 则必可分解，否则不然。 

#include <vector>
#include <complex> 
#include <cmath>
#include <limits>
#include <algorithm>

const double EPS = 1e-10;

// Polynomial below:
// c[0] + c[1]*x + c[2]*x^2 + ... + c[n]*x^N.
// Express as a vector<double> of indices [0..N].
typedef std::complex<double> Complex;
typedef std::vector<double> Poly;
typedef std::vector<Complex> PolyCplx;
typedef std::vector<double> Vec;
typedef std::vector<Complex> VecCplx;

// Simplify the polynomial, eliminates the high-degree zero term.
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

// Given m+1 complex coefficients a[0..m] of a ploynomial,
// and given a complex value x by Laguerre's method until
// it converges, within the achievable roundoff limit, to
// a root of the given polynomial. the number of iterations
// is returned as its.
void laguer(PolyCplx& a, Complex& x, int& its) {
    const int MR = 8, MT = 10, MAXIT = MT * MR;
    static const double frac[MR + 1] = 
        {0.0, 0.5, 0.25, 0.75, 0.13, 0.38, 0.62, 0.88, 1.0};
    const double eps = std::numeric_limits<double>::epsilon();
    int iter, j;
    double abx, abp, abm, err;
    Complex dx, x1, b, d, f, g, h, sq, gp, gm, g2;
    int m = a.size() - 1;
    for(iter = 1; iter <= MAXIT; iter++) {
        its = iter;
        b = a[m];
        err = abs(b);
        d = f = 0.0;
        abx = abs(x);
        for(j = m - 1; j >= 0; j--) {
            f = x*f + d;
            d = x*d + b;
            b = x*b + a[j];
            err = abs(b) + abx*err;
        }
        err *= eps;
        if(abs(b) <= err) return;
        g = d / b;
        g2 = g * g;
        h = g2 - 2.0 * f / b;
        sq = sqrt(double(m-1)*(double(m)*h-g2));
        gp = g + sq;
        gm = g - sq;
        abp = abs(gp);
        abm = abs(gm);
        if(abp < abm) gp = gm;
        dx = std::max(abp, abm) > 0.0 ?
            double(m) / gp :
            std::polar(1 + abx, double(iter));
        x1 = x - dx;
        if(x == x1) return;
        if(iter % MT != 0) x = x1;
        else x -= frac[iter/MT] * dx;
    }
    // Never get here, can occur only for complex roots.
    // Try a different starting guess for the root.
    return;
}

// Given m+1 complex coefficients a[0..m] of a ploynomial,
// finds all m complex roots int roots[0..m-1].
// The boolean variable polish should be inpue as true if
// polishing is desire, false if the roots will be subse-
// quently polished by other means. 
void zroots(PolyCplx& a, VecCplx& roots, const bool& polish) {
    int i, its, j, jj;
    Complex x, b, c;
    int m = a.size() - 1;
    VecCplx ad = a;
    roots.resize(m);
    for(j = m - 1; j >= 0; j--) {
        x = 0.0;
        VecCplx ad_v(ad.begin(), ad.begin()+j+2);
        laguer(ad_v, x, its);
        if(fabs(imag(x)) <= 2.0 * EPS * fabs(real(x)))
            x = Complex(real(x), 0.0);
        roots[j] = x;
        b = ad[j+1];
        for(jj = j; jj >= 0; jj--) {
            c = ad[jj];
            ad[jj] = b;
            b = x*b + c;
        }
    }
    if(polish)
        for(j = 0; j < m; j++)
            laguer(a, roots[j], its);
    for(j = 1; j < m; j++) {
        x= roots[j];
        for(i = j-1; i >= 0; i--) {
            if(real(roots[i]) < real(x)) break;
            roots[i+1] = roots[i];
        }
        roots[i+1] = x;
    }
}




#include <iostream>
using namespace std;

int main() {
    PolyCplx a, roots;
    int T, N, X;
    for(cin >> T; T--;) {
        cin >> N;
        a.resize(N+1);
        for(int i = 0; i <= N; ++i) {
            cin >> X;
            a[N-i] = X;
        }
        zroots(a, roots, true);
        int re = 0, im;
        for(int i = 0; i < N; ++i) {
            if(fabs(imag(roots[i])) < EPS) {
                re += 1;
            }
        }
        im = (N - re) / 2;
        puts(re + im > 1 ? "NO" : "YES");
        if(T) puts("");
    }
}
