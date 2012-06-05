// 1665599 2008-10-13 21:34:37 Accepted  1563 C++ 0 184 呆滞的慢板 

// 珠宝采购，类似背包，n^3 的 DP，DP[k] 为买完第 k 种珠宝之后的最小花费。
// 然后，对于每个 k，可以考虑用它代替前面的 j..k 种珠宝，
// 然后选择不同的 j 以更新最小值，即可完成 DP。 

#include <iostream>
using namespace std;

int DP[101], P[101], A[101], N, T;

int main() {
    
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 1; i <= N; ++i) {
            cin >> A[i] >> P[i];
            DP[i] = INT_MAX;
        }
        DP[0] = 0;
        for(int i = 1; i <= N; ++i) {
            for(int j = 0; j < i; ++j) {
                int sum = 0;
                for(int k = j+1; k <= i; ++k)
                    sum += A[k];
                DP[i] = min(DP[i], DP[j] + (10 + sum) * P[i]);
            }
        }
        cout << DP[N] << endl;
    }
    
}
