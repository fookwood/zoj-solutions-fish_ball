#include <iostream>
using namespace std;

typedef long long i64;

i64 gcd(i64 m, i64 n) {
    i64 r = m % n;
    while(r) {
        m = n;
        n = r;
        r = m % n;
    }
    return n;
}

inline i64 lcm(i64 m, i64 n) {
    return m / gcd(m, n) * n;
}

int m, n;
i64 x, y;
vector<i64> g, b;

i64 cal_good(int pos, int cnt, i64 prod) {
    i64 ans = 0;
    if(cnt && pos == g.size()) {
        if(cnt & 1)
            ans += y / prod - (x - 1) / prod;
        else
            ans -= y / prod - (x - 1) / prod;
    }
    if(pos + 1 < g.size()) {
        ans += cal_good(pos + 1, cnt, prod);
        ans += cal_good(pos + 1, cnt + 1, lcm(prod, g[pos]));
    }
    return ans;
}

int main() {
    
    
    while(cin >> m >> n >> x >> y && m) {
        g.resize(m);
        b.resize(n);
    }
    
    i64 bad = 1;
    
    for(int i = 0; i < b.size(); ++i)
        bad = lcm(bad, b[i]);
    
    i64 pb = (high - 1) / bad - (low - 1) / bad;
    i64 pg = cal_good(0, 0, 1);
    
    
    
    system("pause");
}
