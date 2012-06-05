// 1773788 2009-03-01 15:39:16 Accepted  3172 C++ 290 184 呆滞的慢板 

// 求一个森林的最长路径，直接蛮 DFS 即可。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<vector<int> > G;
vector<int> B;
int ans;

void dfs(int v, int level) {
    B[v] = true;
    ans = max(ans, level);
    for(int i = 0, w; i < G[v].size(); ++i) {
        w = G[v][i];
        if(B[w] == false)
            dfs(w, level + 1);
    }
}

int main() {
    while(cin >> V >> E) {
        G.assign(V, vector<int>());
        while(E--) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        ans = 0;
        for(int i = 0; i < V; ++i) {
            B.assign(V, false);
            dfs(i, 1);
        }
        if(ans > 7) cout << ans << endl;
        else puts("Impossible");
    }
}
