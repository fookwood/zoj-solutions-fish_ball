// 2164775 2010-04-16 11:53:09 Accepted  3310 C++ 300 11904 呆滞的慢板 

// 环形相邻互斥0-1背包问题，只需分第一个是否选定来DP即可。 

#include <iostream>
#include <algorithm>
using namespace std;

int A[1000000], DP[2][1000000], N;

int main() {
    while(cin >> N) {
        for(int i = 0; i < N; ++i) scanf("%d", A + i);
        int ans = 0;
        // 第一遍，强制第一个选定
        memset(DP, 0, sizeof(DP));
        DP[1][0] = A[0];
        for(int i = 1; i < N; ++i) {
            DP[0][i] = max(DP[0][i-1], DP[1][i-1]);
            DP[1][i] = max(DP[1][i-1], DP[0][i-1]+A[i]);
        }
        ans = DP[0][N-1];
        // 第二遍，强制第一个不选
        memset(DP, 0, sizeof(DP));
        for(int i = 1; i < N; ++i) {
            DP[0][i] = max(DP[0][i-1], DP[1][i-1]);
            DP[1][i] = max(DP[1][i-1], DP[0][i-1]+A[i]);
        }
        ans = max(ans, max(DP[0][N-1], DP[1][N-1]));
        cout << ans << endl; 
    }
}
