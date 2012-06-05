// 1705433 2008-11-19 18:00:04 Accepted  3060 C++ 20 340 ´ôÖÍµÄÂý°å 

#include <iostream>
#include <algorithm>
using namespace std;

int M, N, T;
int G[100][100], L[100][100], R[100][100], DP[100][100];

int main() {
    for(cin >> T; T--;) {
        cin >> M >> N;
        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                cin >> G[i][j];
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                L[i][j] = R[i][j] = G[i][j];
                for(int k = j-1, p = G[i][j]; k >= 0; --k) {
                    p += G[i][k] - abs(G[i][k+1]);
                    L[i][j] = max(L[i][j], p);
                }
                for(int k = j+1, p = G[i][j]; k < N; ++k) {
                    p += G[i][k] - abs(G[i][k-1]);
                    R[i][j] = max(R[i][j], p);
                }
            }
        }
        DP[0][0] = R[0][0];
        for(int j = 1, p = G[0][0]; j < N; ++j) {
            DP[0][j] = p + R[0][j];
            p += G[0][j];
        }
        for(int i = 1; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                DP[i][j] = DP[i-1][j] + max(L[i][j], R[i][j]);
                DP[i][j] = max(DP[i][j], DP[i-1][j] + L[i][j] + R[i][j] - G[i][j]);
            }
            for(int j = 0; j < N; ++j) {
                for(int k = j + 1, p = 0; k < N; ++k) {
                    DP[i][k] = max(DP[i][k], DP[i-1][j] + L[i][j] + p + R[i][k]);
                    DP[i][j] = max(DP[i][j], DP[i-1][k] + L[i][j] + p + R[i][k]);
                    p += G[i][k];
                }
            }
        }
        cout << DP[M-1][N-1] << endl;
    }
}
