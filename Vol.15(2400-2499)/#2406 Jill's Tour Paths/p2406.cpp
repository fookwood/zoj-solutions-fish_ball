// 1683445 2008-10-30 20:24:50 Accepted  2406 C++ 0 184 呆滞的慢板 

// 直接蛮力回溯所有路径即可。 

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, int> > G[21];

vector<pair<int, vector<int> > > P;

int V, E, S, T, D, C = 0;

vector<int> path;
bool B[21];

void dfs(int v, int l) {
    if(l > D) return;
    if(v == T) {
        P.push_back(make_pair(l, path));
        return;
    }
    for(int i = 0, w, s; i < G[v].size(); ++i) {
        w = G[v][i].first;
        s = G[v][i].second;
        if(!B[w]) {
            B[w] = true;
            path.push_back(w);
            dfs(w, l + s);
            path.pop_back();
            B[w] = false;
        }
    }
}

int main() {
    
    while(cin >> V && V != -1) {
        for(int i = 1; i <= V; ++i)
            G[i].clear();
        P.clear();
        for(cin >> E; E--;) {
            int x, y, l;
            cin >> x >> y >> l;
            G[x].push_back(make_pair(y, l));
            G[y].push_back(make_pair(x, l));
        }
        cin >> S >> T >> D;
        memset(B, 0, sizeof(B));
        B[S] = true;
        path.assign(1, S);
        dfs(S, 0);
        sort(P.begin(), P.end());
        if(C++) puts("");
        printf("Case %d:\n", C);
        for(int i = 0; i < P.size(); ++i) {
            printf(" %d:", P[i].first);
            for(int j = 0; j < P[i].second.size(); ++j)
                printf(" %d", P[i].second[j]);
            puts("");
        }
    }
    
}
