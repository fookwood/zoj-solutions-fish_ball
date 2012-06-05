// 1867983 2009-05-14 02:00:21 Accepted  3141 C++ 430 340 呆滞的慢板 

// 掰巧克力，经典，问掰多少下能把 M * N 的巧克力掰成全部是正方型的。
// 用 DP，DP[M][N] 表示 M * N 需要的次数。
// 那么初始条件就是 DP[i][i] = 0。
// 递推条件就是 DP[M][N] = min(DP[i][N] + DP[M-i][N] + 1, DP[M][j] + DP[M][N-j] + 1)。
// 其中 0<i<M，0<j<N。用递归做这个 DP 比较方便。 

#include <iostream>
#include <algorithm>
using namespace std;

int DP[201][201];

int eval(int M, int N) {
    if(DP[M][N] != INT_MAX) return DP[M][N];
    for(int i = 1; i < M; ++i)
        DP[M][N] = min(DP[M][N], eval(i, N) + eval(M - i, N) + 1);
    for(int i = 1; i < N; ++i)
        DP[M][N] = min(DP[M][N], eval(M, i) + eval(M, N - i) + 1);
    return DP[M][N];
}

int main() {
    for(int i = 0; i <= 200; ++i)
        for(int j = 0; j <= 200; ++j)
            if(i == j) DP[i][j] = 0;
            else DP[i][j] = INT_MAX;
    int T, M, N;
    for(cin >> T; T--;) {
        cin >> M >> N;
        cout << eval(M, N) << endl;
    }
}
