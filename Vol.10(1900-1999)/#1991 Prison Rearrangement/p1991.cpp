// 1660536 2008-10-08 11:31:24 Accepted  1991 C++ 130 456 呆滞的慢板 

// 类似于背包的 DP，但要保存所有对的信息 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> G[400];

vector<pair<int, int> > P;

int color[400];

int N, R, T, S1, S2, C1, C2;
vector<int> DP[101];

void dfs(int v, int c) {
    color[v] = c;
    if(c == 1) ++C1;
    else ++C2;
    for(int i = 0, w; i < G[v].size(); ++i) {
        w = G[v][i];
        if(!color[w]) dfs(w, 3-c);
    }
}

int main() {
    for(cin >> T; T--;) {
        cin >> N >> R;
        for(int i = 0; i < N; i++) {
            G[i].clear();
            G[i+N].clear();
        }
        while(R--) {
            int x, y;
            cin >> x >> y;
            G[x-1].push_back(N+y-1);
            G[N+y-1].push_back(x-1);
        }
        memset(color, 0, sizeof(color));
        P.clear();
        for(int i = S1 = S2 = 0; i < N; ++i) {
            if(G[N+i].empty()) {S2++; color[N+i] = -1;}
            if(G[i].empty()) {S1++; color[i] = -1;}
        }
        for(int i = 0; i < N; ++i) {
            if(color[i] == 0) {
                C1 = C2 = 0;
                dfs(i, 1);
                P.push_back(make_pair(C1, C2));
            }
        }
        for(int i = 0; i <= N/2; ++i)
            DP[i].clear();
        DP[0].push_back(0);
        for(int i = 0; i < P.size(); ++i) {
            C1 = P[i].first;
            C2 = P[i].second;
            for(int j = N/2-C1; j >= 0; --j)
                for(int k = DP[j].size()-1; k >= 0; --k)
                    DP[j+C1].push_back(DP[j][k]+C2);
            for(int j = 0; j <= N/2; ++j) {
                sort(DP[j].begin(), DP[j].end());
                DP[j].resize(unique(DP[j].begin(), DP[j].end())-DP[j].begin());
            }
        }
        int ans = 0;
        for(int i = 0; i <= N/2; ++i) {
            for(int k = 0, j; k < DP[i].size(); ++k) {
                j = DP[i][k];
                C1 = max(i, j);
                C2 = min(i+S1, j+S2);
                if(C2 >= C1 && C2 > ans) ans = C2;
            }
        }
        cout << min(ans, N/2) << endl;
    }
}
