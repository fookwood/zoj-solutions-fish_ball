#include <iostream>
#include <algorithm>
using namespace std;

bool tmp[18], now[18];

long long DP[33][1<<9][1<<9];

int m, n;

void from(int b, bool* B) {
    for(int i = 0; i < m; ++i)
        B[i] = b & (1<<i) != 0;
}

int to(bool* B) {
    int ans = 0;
    for(int i = 0; i < m; ++i)
        if(B[i])
            ans |= (1<<i);
    return ans;
}

int main() {
    while(cin >> m >> n && m) {
        memset(DP, 0, sizeof(DP));
        DP[0][0][0] = 1;
        for(int h = 0; h <= 30; ++h) {
            DP[h+3][0] += DP[h][0];
            for(int c = 1; c < (1<<m)-1; ++c) {
                for(int p = 0; p < (1<<m); ++p) {
                    if(p )
                    from(c, tmp);
                    from(p, now);
                    DP[h+1][]
                }
            }
        }
    }
}
