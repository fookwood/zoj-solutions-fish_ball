// 1831794 2009-04-13 00:03:10 Accepted  1449 C++ 10 184 呆滞的慢板 

// 求最大的子立方阵和，直接用求和预处理之后容斥原理，再用 n^6 的枚举即可解决。 

#include <iostream>
using namespace std;

int main() {
    int N;
    int G[21][21][21];
    while(cin >> N && N) {
        memset(G, 0, sizeof(G));
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                for(int k = 1; k <= N; ++k) {
                    cin >> G[i][j][k];
                    G[i][j][k] += G[i-1][j][k];
                    G[i][j][k] += G[i][j-1][k];
                    G[i][j][k] += G[i][j][k-1];
                    G[i][j][k] -= G[i-1][j-1][k];
                    G[i][j][k] -= G[i][j-1][k-1];
                    G[i][j][k] -= G[i-1][j][k-1];
                    G[i][j][k] += G[i-1][j-1][k-1];
                }
            }
        }
        int best = INT_MIN;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    for(int ii = i + 1; ii <= N; ++ii) {
                        for(int jj = j + 1; jj <= N; ++jj) {
                            for(int kk = k + 1; kk <= N; ++kk) {
                                int val = G[ii][jj][kk];
                                val -= G[i][jj][kk];
                                val -= G[ii][j][kk];
                                val -= G[ii][jj][k];
                                val += G[i][j][kk];
                                val += G[ii][j][k];
                                val += G[i][jj][k];
                                val -= G[i][j][k];
                                if(val > best) best = val;
                            }
                        }
                    }
                }
            }
        }
        cout << best << endl;
    }
}
