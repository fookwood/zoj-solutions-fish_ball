// 1835712 2009-04-17 00:06:00 Accepted  2173 C++ 0 184 呆滞的慢板 

// 周游路线，NP 的搜索，注意搜索的起点和回溯的条件，如果有奇度点，则必从奇度点开始搜索。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E, C;
int G[10][10];
int deg[10];
int cnt, pos;

vector<int> path;
int best, now;

void dfs(int v) {
    if(path.size() == E) {
        if(cnt == 0 && path.back() == path.front()) best = min(best, now - 1);
        else best = min(best, now);
    }
    for(int w = 0; w < V; ++w) {
        if(G[v][w] != -1) {
            if(!path.empty() && G[v][w] != path.back()) now++;
            path.push_back(G[v][w]);
            G[v][w] = G[w][v] = -1;
            dfs(w);
            G[v][w] = G[w][v] = path.back();
            path.pop_back();
            if(!path.empty() && G[v][w] != path.back()) now--;
        }
    }
}

int main() {
    while(cin >> V >> C >> E && V) {
        memset(G, -1, sizeof(G));
        memset(deg, 0, sizeof(deg));
        for(int i = 0, x, y; i < E; ++i) {
            cin >> x >> y;
            cin >> G[x][y];
            G[y][x] = G[x][y];
            deg[x]++;
            deg[y]++;
        }
        cnt = 0, pos = 0;
        for(int i = 0; i < V; ++i) {
            if(deg[i] & 1) {
                ++cnt;
                pos = i;
            }
        }
        if(cnt > 2) {
            puts("No");
            continue;
        }
        path.clear();
        best = INT_MAX;
        now = 0;
        dfs(pos);
        if(best == INT_MAX) puts("No");
        else cout << best << endl;
    }
}
