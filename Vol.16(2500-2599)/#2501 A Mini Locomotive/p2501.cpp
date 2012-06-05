// 1653747 2008-10-02 12:46:16 Accepted  2501 C++ 10 1168 ´ôÖÍµÄÂý°å 

// ¼òµ¥ DP 

#include <iostream>
using namespace std;

int main() {
    int T, N, K;
    int A[50001];
    int DP[4][50001];
    for(cin >> T; T-- && cin >> N;) {
        A[0] = 0;
        for(int i = 1; i <= N; ++i) {
            cin >> A[i];
            A[i] += A[i-1];
        }
        cin >> K;
        for(int i = 0; i <= N; ++i) {
            DP[0][i] = 0;
            DP[1][i] = DP[2][i] = DP[3][i] = -1;
        }
        for(int i = 0; i+K <= N; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(i) DP[j][i] = max(DP[j][i], DP[j][i-1]);
                if(DP[j][i] != -1) {
                    DP[j+1][i+K] =
                        max(DP[j+1][i+K],
                        DP[j][i] + A[i+K] - A[i]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= N; ++i)
            ans = max(ans, DP[3][i]);
        cout << ans << endl;
    }
}
