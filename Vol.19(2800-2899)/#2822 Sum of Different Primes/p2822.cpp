// 1686260 2008-11-02 14:30:22 Accepted  2822 C++ 340 12600 呆滞的慢板 

// 类似背包的 DP，DP[i][j][k] 表示共 i 个数编号小于 j 总和为 k 的方案数。

#include <iostream>
using namespace std;

bool B[1121] = {};
int T = 0, P[187];

int DP[15][189][1121];
int N, K;

int main() {
    for(int i = 2; i * i <= 1120; ++i)
        if(!B[i])
            for(int j = i * i; j <= 1120; j += i)
                B[j] = true;
    for(int i = 2; i <= 1120; ++i)
        if(!B[i]) P[T++] = i;
    DP[0][0][0] = 1;
    for(int i = 0; i < 14; ++i) {
        for(int j = 0; j < T; ++j) {
            for(int p = j; p < T; ++p) {
                for(int k = 0; k + P[p] < 1121; ++k) {
                    DP[i+1][p+1][k+P[p]] += DP[i][j][k];
                }
            }
        } 
    }
    while(cin >> N >> K && N) {
        int ans = 0;
        for(int i = 0; i < 188; ++i)
            ans += DP[K][i][N];
        cout << ans << endl;
    }
}
