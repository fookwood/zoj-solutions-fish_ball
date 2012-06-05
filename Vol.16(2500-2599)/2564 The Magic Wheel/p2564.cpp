#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = acos(-1.0);

int N;
double r, h, d;

vector<double> a, b, c;

void proc(vector<double>& x) {
    for(int i = 0; i < x.size(); ++i)
        x[i] = fmod(x[i]+4*PI, 2*PI);
    sort(x.begin(), x.end());
}

inline double diff(double x, double y) {
    double z = fabs(x-y);
    return z < PI ? z : 2 * PI - z;
}

double dist(const vector<double>& x, const vector<double>& y, int k) {
    double ans = 0.0;
    for(int i = 0; i < N; ++i)
        ans += hypot(diff(x[i], y[(i+k)%N]) * r, h/2.0);
    return ans;
}

int main() {
    while(cin >> N >> r >> h) {
        a.resize(N);
        b.resize(N);
        c.resize(N);
        for(int i = 0; i < N; ++i) cin >> a[i];
        for(int i = 0; i < N; ++i) cin >> b[i];
        for(int i = 0; i < N; ++i) cin >> c[i];
        proc(a);
        proc(b);
        proc(c);
        int k1, k2;
        double v1, v2, tmp;
        v1 = dist(a, b, 0); k1 = 0;
        for(int i = 1; i < N; ++i) {
            tmp = dist(a, b, i);
            if(tmp < v1) {
                k1 = i;
                v1 = tmp;
            }
        }
        v2 = dist(b, c, 0); k2 = 0;
        for(int i = 1; i < N; ++i) {
            tmp = dist(b, c, i);
            if(tmp < v2) {
                k2 = i;
                v2 = tmp;
            }
        }
        printf("%.4lf\n", v1 + v2);
        for(int i = 0; i < N; ++i) {
            cout << i+1 << ' '
                << (i+k1)%N + 1 << ' '
                << (i+k1+k2)%N + 1 << endl;
        }
    }
}
