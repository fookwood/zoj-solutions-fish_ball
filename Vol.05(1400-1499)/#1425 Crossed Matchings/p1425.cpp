// 1717114 2008-12-03 00:17:50 Accepted  1425 C++ 0 224 呆滞的慢板 

// 交叉线匹配，经典 DP，n^3。 

#include <iostream>
#include <algorithm>
using namespace std;

int T, A[100], B[100], M, N, DP[101][101];

int main() {
    for(cin >> T; T--;) {
        cin >> M >> N;
        for(int i = 0; i < M; ++i) cin >> A[i];
        for(int i = 0; i < N; ++i) cin >> B[i];
        memset(DP, 0, sizeof(DP));
        int mx = 0;
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                DP[i][j+1] = max(DP[i][j+1], DP[i][j]);
                DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
                DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j]);
                if(A[i] == B[j]) continue;
                int p = i + 1, q = j + 1;
                while(p < M && A[p] != B[j]) p++;
                while(q < N && A[i] != B[q]) q++;
                if(p == M || q == N) continue;
                DP[p+1][q+1] = max(DP[i][j] + 2, DP[p+1][q+1]);
                mx = max(mx, DP[p+1][q+1]);
            }
        }
        cout << mx << endl;
    }
}
