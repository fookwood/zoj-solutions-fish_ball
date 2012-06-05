// 1869100 2009-05-14 17:56:11 Accepted  2949 C++ 40 8012 呆滞的慢板 

// 求期望的决策次数，非常短小的 DP，
// DP[M][N] 是两种面剩余碗数时的期望。
// 初值是 DP[0][j] = DP[i][0] = 0。
// 递推条件是 DP[i][j] = 1 + DP[i-1][j] + DP[i][j-1]。 

#include <iostream>
using namespace std;

double DP[1001][1001] = {};

int main() {
    for(int i = 1; i <= 1000; ++i)
        for(int j = 1; j <= 1000; ++j)
            DP[i][j] = 1.0 + (DP[i-1][j] + DP[i][j-1]) / 2;
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        printf("%.2lf\n", DP[N][N]);
    }
}
