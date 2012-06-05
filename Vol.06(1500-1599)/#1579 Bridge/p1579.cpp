// 1692545 2008-11-07 22:30:27 Accepted  1579 C++ 80 1748 呆滞的慢板 

// 经典过河问题，有一个 O(N) 的策略。 

#include <iostream>
#include <algorithm>
using namespace std;

long long A[100001], DP[100001], N;

int main() {
    
    while(scanf("%lld", &N) != EOF) {
        for(int i = 0; i < N; ++i)
            scanf("%lld", A + i);
        sort(A, A + N);
        DP[0] = 0;
        DP[1] = A[0];
        DP[2] = A[1];
        DP[3] = A[0] + A[1] + A[2];
        for(int i = 4; i <= N; ++i) {
            DP[i] = DP[i-2] + A[1] + A[1] + A[0] + A[i-1];
            DP[i] = min(DP[i], DP[i-1] + A[0] + A[i-1]);
        }
        printf("%lld\n", DP[N]);
    }
    
}
