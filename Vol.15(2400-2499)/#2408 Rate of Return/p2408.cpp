// 1682662 2008-10-30 12:07:39 Accepted  2408 C++ 0 184 呆滞的慢板 

// 明显到目标月的结余按照净利率是单增的，则二分利率即可。 

#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, double> Rec;

int N, T = 0;

vector<Rec> V;
Rec X;

bool eval(double x) {
    double tot = 0;
    for(int i = 0; i < N; ++i) {
        double now = V[i].second;
        for(int j = V[i].first; j <= X.first; ++j)
            now *= 1 + x;
        tot += now;
    }
    return tot < X.second;
}

int main() {
    
    while(cin >> N && N != -1) {
        V.clear();
        for(int i = 0; i < N; ++i) {
            cin >> X.first >> X.second;
            V.push_back(X);
        }
        cin >> X.first >> X.second;
        double l = 0, r = 1, m;
        while(r - l > 1e-8) {
            m = (l + r) / 2;
            if(eval(m)) l = m;
            else r = m;
        }
        if(T++) puts("");
        printf("Case %d: %.5lf\n", T, m);
    }
    
}
