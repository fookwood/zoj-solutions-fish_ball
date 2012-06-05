// 1760625 2009-02-08 00:28:18 Accepted  1503 C++ 0 184 呆滞的慢板 

// 估价游戏，一个决策为背景的 DP，当前剩下 i 次机会和 j 条命，
// 最优的策略可以覆盖 DP[i][j] 范围内的所有情况，
// 那么，要求 DP[i][j]，当 i = 0 时，结果为 0，j = 0 时，结果为 i，
// 然后，求 DP[i][j]，选择一个位置 k，
// 如果猜大了，那么剩下 i-1 机会和 j-1 命，那么 DP[i-1][j-1] 必须刚好覆盖 k-1， 
// 如果猜小了，那么剩下 i-1 机会和 j 命，那么还可以覆盖到 k + DP[i-1][j] 的范围。 
// 因此 DP[i][j] = DP[i-1][j-1] + 1 + DP[i-1][j]

#include <iostream>
using namespace std;

int main() {
    int M, N;
    int DP[31][31] = {};
    for(int i = 1; i < 31; ++i) {
        DP[i][0] = i;
        for(int j = 1; j < 31; ++j)
            DP[i][j] = DP[i-1][j-1] + 1 + DP[i-1][j];
    }
    int T = 1;
    while(cin >> M >> N && (M || N))
        cout << "Case " << T++ << ": " << DP[M][N] << endl;
}
