// 1737035 2009-01-01 01:03:26 Accepted  3080 C++ 1110 1132 呆滞的慢板  
// 找出连通分量，每个连通分量求一个最短路，然后取所有分量最短路的最大值。 

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, dist[1000], p[1000];
int block[1000];
vector<pair<int, int> > G[1000];
vector<vector<int> > comp;

void dfs(int v, int b) {
    block[v] = b;
    comp[b].push_back(v);
    for(int i = 0, w; i < G[v].size(); ++i) {
        w = G[v][i].first;
        if(block[w] == -1)
            dfs(w, b);
    }
}

int main() {
    while(cin >> N) {
        for(int i = 0, t; i < N; ++i) {
            G[i].clear();
            for(int j = 0; j < N; ++j) {
                scanf("%d", &t);
                if(i != j && t >= 0)
                    G[i].push_back(make_pair(j, t));
            }
        }
        memset(block, -1, sizeof(block));
        int b = 0;
        comp.clear();
        for(int i = 0; i < N; ++i) {
            if(block[i] == -1) {
                comp.push_back(vector<int>());
                dfs(i, b++);
            }
        }
        for(int i = 0; i < N; ++i)
            scanf("%d", p + i);
        int ans = 0;
        for(int blk = 0; blk < b; ++blk) {
            int mn = -1;
            for(int t = 0, u; t < comp[blk].size(); ++t) {
                u = comp[blk][t];
                queue<int> Q;
                memset(dist, -1, sizeof(dist));
                Q.push(u);
                dist[u] = p[u];
                while(!Q.empty()) {
                    int v = Q.front();
                    Q.pop();
                    for(int i = 0, w, d; i < G[v].size(); ++i) {
                        w = G[v][i].first;
                        d = G[v][i].second;
                        if(dist[w] == -1 || dist[w] > dist[v] + d) {
                            dist[w] = dist[v] + d;
                            Q.push(w);
                        }
                    }
                }
                int now = comp[blk][0];
                for(int k = 0; k < comp[blk].size(); ++k)
                    now = max(now, dist[comp[blk][k]]);
                if(mn == -1 || mn > now) mn = now;
            }
            ans = max(ans, mn);
        }
        cout << ans << endl;
    }
}
