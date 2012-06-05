#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-12;
    
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

bool cmp(string lhs, string rhs) {
    for(int i = 0; i < lhs.size(); ++i)
        lhs[i] = toupper(lhs[i]);
    for(int i = 0; i < rhs.size(); ++i)
        rhs[i] = toupper(rhs[i]);
    return lhs < rhs;
}

int main() {
    int M;
    double L, W, H, v, w, vx, vy;
    string name;
    vector<string> ans(0);
    while(cin >> M) {
        cin >> L >> W >> H;
        while(M--) {
            cin >> name >> v >> v;
            if(gt(H, L)) continue;
            w = sqrt(H*(2.0*L-H));
            if(gt(w, W)) continue;
            if(ng(v*v - 19.6*H)) continue;
            v = sqrt(fabs(v*v - 19.6*H));
            double vx = v * (L-H) / L;
            double vy = v * w / L;
            w += vx * vy / 4.9;
            if(lt(w, W)) continue;
            ans.push_back(name);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    }
}
