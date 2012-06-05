// 1685338 2008-11-01 15:36:12 Accepted  2707 C++ 0 180 呆滞的慢板 

// 高等代数的内容，二进制多项式的运算
// 可以抽象出多项式的 乘、除、模、减 运算，然后就变成解模线性方程组
// 可以应用数论的扩展欧几里德算法实现。 

#include <vector>
#include <complex> 
#include <cmath>
#include <limits>
#include <algorithm>

// Polynomial below:
// c[0] + c[1]*x + c[2]*x^2 + ... + c[n]*x^N.
// Express as a vector<double> of indices [0..N].
typedef std::vector<int> Poly;

// Simplify the polynomial, eliminates the high-degree zero term.
void tidy(Poly& c) {
    while(!c.empty() && c.back() == 0)
        c.pop_back();
}

// Slow convolution, multiplying two polynomials.
// Complexity: O(nu * nv).
void conv(const Poly& u, const Poly& v, Poly& w) {
    if(u.empty() || v.empty()) {w.clear(); return;}
    int nu = u.size(), nv = v.size();
    w.assign(nu + nv - 1, 0);
    for(int i = 0; i < nu; i++)
        for(int j = 0; j < nv; j++)
            w[i+j] ^= (u[i] & v[j]);
    tidy(w);
}

// Slow deconvolution, polynomial dividing.
// q returns the quotient, r returns the remainder.
void deconv(const Poly& u, const Poly& v, Poly& q, Poly& r) {
    int n = u.size() - 1;
    int nv = v.size() - 1;
    q.assign(n + 1, 0);
    r = u;
    for(int k = n-nv; k >= 0; k--) {
        q[k] = r[nv+k];
        for(int j = nv+k-1; j >= k; j--)
            r[j] ^= (q[k] & v[j-k]);
    }
    r.resize(nv);
    tidy(q);
    tidy(r);
}

// Add b to a or Subs b from a.
void sub(Poly& a, const Poly& b) {
    if(a.size() < b.size())
        a.resize(b.size(), 0);
    for(int i = 0; i < b.size(); ++i)
        a[i] ^= b[i];
    tidy(a);
}

// GCD
void gcd(const Poly& m, const Poly& n, Poly& w) {
    if(n.empty()) {
        w = m;
        return;
    }
    Poly q, r;
    deconv(m, n, q, r);
    gcd(n, r, w);
}

// Extend GCD
void extendEuclid(const Poly& , const Poly& b, Poly& d, Poly& x, Poly& y) {
    if(b.size() == 0) {
        d = a;
        x.assign(1, 1);
        y.clear();
        return;
    }
    Poly q, r;
    deconv(a, b, q, r);
    extendEuclid(b, r, d, x, y);
    conv(q, y, r);
    sub(x, r);
    std::swap(x, y);
}

#include <iostream>
using namespace std;

bool get(Poly& p) {
    int N;
    if(!(cin >> N)) return false;
    p.resize(N + 1);
    for(int i = 0; i <= N; ++i)
        cin >> p[N - i];
    return true;
}

void put(const Poly& p) {
    int N = p.size() - 1;    
    cout << N;
    for(int i = N; i >= 0; --i)
        cout << ' ' << p[i];
    puts("");
}

int main() {

    Poly a1, b1, c1, a2, b2, c2, w, q, r, x, y, d;
    
    while(get(a1), get(b1), get(c1),
        get(a2), get(b2), get(c2)) {
        if(a1.empty()) {
            swap(a1, a2);
            swap(b1, b2);
            swap(c1, c2);
        }
        if(!a2.empty()) {
            conv(a2, b1, w); b1 = w;
            conv(a2, c1, w); c1 = w;
            conv(a1, b2, w); b2 = w;
            conv(a1, c2, w); c2 = w;
            conv(a1, a2, w); a1 = a2 = w;
            sub(a2, a1);
            sub(b2, b1);
            sub(c2, c1);
        }
        if(b2.empty()) {
            /// y 不限，扩展欧几里德 ///
            if(c2.empty()) {
                if(a1.empty()) {
                    //////////// 全解任意 ////////////
                    if(c1.empty()) {
                        put(c1);
                        put(c2);
                        puts(""); 
                    }
                    ////////// x 导出矛盾 ////////////
                    else {
                        puts("No solution\n");
                    }
                }
                else {
                    extendEuclid(a1, b1, d, x, y);
                    deconv(c1, d, q, r);
                    ///////////// 存在整解 ///////////
                    if(r.empty()) {
                        conv(x, q, w);
                        x = w;
                        conv(y, q, w); 
                        y = w;
                        put(x);
                        put(y);
                        puts("");
                    }
                    //////////// 全没有整解 //////////
                    else {
                        puts("No solution\n");
                    }
                }
            }
            //////// y 导出矛盾 //////// 
            else {
                puts("No solution\n");
            }
        }
        else {
            deconv(c2, b2, q, r);
            if(r.empty()) {
                c2 = q;
                b2.assign(1, 1);
                conv(b1, c2, w);
                sub(c1, w);
                b1.clear();
                if(a1.empty()) {
                    //////////// x 解任意 ////////////
                    if(c1.empty()) {
                        put(c1);
                        put(c2);
                        puts("");
                    }
                    //////////// x 导出矛盾 //////////
                    else {
                        puts("No solution\n");
                    }
                }
                else {
                    deconv(c1, a1, q, r);
                    //////////// 最终唯一解 //////////
                    if(r.empty()) {
                        c1 = q;
                        a1.assign(1, 1);
                        put(c1);
                        put(c2);
                        puts("");
                    }
                    //////////// x 没有整解 //////////
                    else {
                        puts("No solution\n");
                    }
                } 
            }
            //////// y 没有整解 ////////
            else {
                puts("No solution\n");
            }
        }
    }

}
