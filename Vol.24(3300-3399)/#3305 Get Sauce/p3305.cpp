// 2151524 2010-04-10 18:48:04 Accepted  3305 C++ 210 636 呆滞的慢板 

// 经典的二进制背包 DP，但是直接硬搞的话物品太多。
// 可以做一个预处理，把可能包含其他物品的物品先剔除掉，再处理就不会超时了。

#include <iostream>
#include <algorithm>
using namespace std;

int A[50000], N, M;
int DP[65536];

int main() {
    while(cin >> N >> M) {
        memset(A, 0, sizeof(A));
        for(int i = 0; i < M; ++i) {
            int k, t;
            for(scanf("%d", &k); k--;) {
                scanf("%d", &t);
                A[i] |= (1<<t-1);
            }
        }
        sort(A, A+M);
        for(int i = 0; i < M; ++i) {
            int MM = i+1;
            for(int j = i+1; j < M; ++j) {
                if((A[j] & A[i]) != A[i])
                    A[MM++] = A[j];
            }
            M = MM;
        }
        memset(DP, -1, sizeof(DP));
        int ans = 0;
        DP[0] = 0;
//cout << "M = " << M << endl;
//for(int i = 0; i < M; ++i) cout << A[i] << ' ';cout << endl;
        for(int i = 0; i < M; ++i) {
            for(int j = (1<<N) - 1 - A[i]; j >= 0; --j) {
                if(DP[j] != -1 && (j & A[i]) == 0 && (DP[j + A[i]] == -1 || DP[j + A[i]] < DP[j] + 1)) {
//                cout << "j = " << j << endl;
                    DP[j + A[i]] = DP[j] + 1;
                    ans = max(ans, DP[j + A[i]]);
                }
            }
        }
        cout << ans << endl;
    }
}
