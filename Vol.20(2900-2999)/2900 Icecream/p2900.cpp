#include <iostream>
using namespace std;

int N, A[2000];
int K, P, M;

int DP[2000][2000];

int main() {
    while(cin >> N >> K >> P >> M) {
        for(int i = 0; i < N; ++i)
            scanf("%d", A + i);
        memset(DP, 0, sizeof(DP));
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            DP[i][0] = 1;
            if(K == 1) {
                ans += 1;
                ans %= M;
            }
            for(int j = i + 1; j < N; ++j) {
                if(A[j] - A[i] <= P && A[i] - A[j] <= P) {
                    for(int k = 0; k <= i; ++k) {
                        if(DP[i][k]) {
                            DP[j][k + 1] += DP[i][k];
                            DP[j][k + 1] %= M;
                            if(k + 2 >= K) {
                                ans += DP[i][k];
                                ans %= M;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
