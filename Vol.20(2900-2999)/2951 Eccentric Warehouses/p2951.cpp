// 1870318 2009-05-15 14:47:56 Accepted  2951 C++ 1550 184 呆滞的慢板 

// 环形物资传递：求最小的传递代价。 
// 反正在最优的策略下，必定有一条路径没有传递。
// 枚举这条路径都计算一次就行了，O(n^2) 的复杂度。
// 还可以归约成最小费用最大流来做。 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T, N;
    double A[2000], B[2000], C[2001];
    int P[2000], D[2000];
    for(cin >> T; T--;) {
        cin >> N;
        double tot = 0, den = 0;
        for(int i = 0; i < N; ++i) {
            cin >> A[i];
            tot += A[i];
        }
        for(int i = 0; i < N; ++i) {
            cin >> P[i];
            den += P[i];
        }
        for(int i = 0; i < N; ++i) cin >> D[i];
        for(int i = 0; i < N; ++i)
            B[i] =  tot * P[i] / den;
        double ans = 1e99;
        for(int i = 0; i < N; ++i) {
            double cost = 0;
            for(int j = 0; j < N; ++j) C[j] = A[j];
            int j = i;
            do {
                cost += fabs(C[j] - B[j]) * D[j];
                C[(j + 1) % N] += C[j] - B[j];
                C[j] = B[j];
                j = (j + 1) % N;
            } while(j != i);
            if(cost < ans) ans = cost;
        }
        printf("%.2lf\n", ans);
    }
}
