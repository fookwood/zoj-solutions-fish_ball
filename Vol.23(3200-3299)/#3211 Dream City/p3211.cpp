// 1882468 2009-05-24 01:32:15 Accepted  3211 C++ 50 184 呆滞的慢板 

// DP，由于最后按天排序的砍树序列必有 b[i] <= b[j]，当 i < j。
// 因此，先对 b[1..N] 排序，然后再用 DP 解决，复杂度 O(N*K)。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
    int T, N, K;

    vector<pair<int, int> > V;
    
    // DP[i][j] 表示取到第 i 棵树时，录取 j 棵的最大值。 
    int DP[251][251];

    for(cin >> T; T--;) {
        cin >> N >> K;
        V.resize(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &V[i].second);
        for(int i = 0; i < N; ++i)
            scanf("%d", &V[i].first);
        sort(V.begin(), V.end());
        memset(DP, -1, sizeof(DP));
        DP[0][0] = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < K; ++j) {
                if(DP[i][j] != -1) {
                    DP[i+1][j] = max(DP[i+1][j], DP[i][j]);
                    DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] + V[i].second + j * V[i].first);
                }
            }
        }
        printf("%d\n", DP[N][K]);
    }
}
