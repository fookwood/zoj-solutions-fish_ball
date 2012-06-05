// 1859416 2009-05-08 01:50:27 Accepted  3195 C++ 240 6260 呆滞的慢板 

// 快速求树的最短路，给出一个加权无向树，对于每次查询，
// 给出三个顶点，求连接此三个顶点的路径总和。
// 用有根树表示该树，
// 只需要预处理的时候求出每个顶点 v 到根的距离 dist[v]，
// 就可以用 dist[a] + dist[b] - 2 * dist[lca(a, b)]
// 求得 a 和 b 点的距离。
// 然后对于每次查询给出的三个顶点 a, b, c，
// 结果就是 (dist(a, b) + dist(a, c) + dist(b, c)) / 2
// 那么对于每个查询只需要做 3 次 lca，lca 的查询复杂度是 log(N) 的， 
// 另加 NlogN 的预处理复杂度。
// 因此整个复杂度降到了 O(NlogN + QlogN)。
 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void gen(
        const vector<vector<pair<int, int> > >& G,
        vector<int>& pre,
        vector<int>& height,
        vector<int>& distance,
        int v ) {
    for(int i = 0, w, l; i < G[v].size(); ++i) {
        w = G[v][i].first;
        l = G[v][i].second;
        pre[w] = v;
        height[w] = height[v] + 1;
        distance[w] = distance[v] + l;
        gen(G, pre, height, distance, w);
    }
}

int lca(
        int a,
        int b,
        int N,
        const vector<vector<int> >& LCA,
        const vector<int>& height ) {
    if(height[a] > height[b]) swap(a, b);
    int p = 0;
    while((2<<p) < N) ++p;
    while(height[b] > height[a]) {
        if(height[b] - (1<<p) >= height[a])
            b = LCA[p][b];
        p -= 1;
    }
    int q = 0;
    while((1<<q) < N) ++q;
    while(a != b) {
        if(q > 0) q -= 1;
        if(LCA[q][b] == -1) continue;
        if(q == 0 || LCA[q][a] != LCA[q][b]) {
            a = LCA[q][a];
            b = LCA[q][b];
        }
    }
    return a;
}

int main() {
    int T = 0;
    for(int N; scanf("%d", &N) != EOF;) {
        if(T++) puts("");
        vector<vector<pair<int, int> > > G(N);
        for(int i = 1, x, y, l; i < N; ++i) {
            scanf("%d%d%d", &x, &y, &l);
            G[x].push_back(make_pair(y, l));
        }
        vector<int> pre(N, -1), height(N, -1), distance(N, -1);
        height[0] = distance[0] = 0;
        gen(G, pre, height, distance, 0);
        vector<vector<int> > LCA(0);
        LCA.push_back(pre);
        for(int d = 2, p = 0; d < N; d <<= 1, p += 1) {
            LCA.push_back(vector<int>(N, -1));
            for(int i = 0; i < N; ++i)
                if(LCA[p][i] != -1)
                    LCA[p+1][i] =  LCA[p][LCA[p][i]];
        }
        int Q, a, b, c;
        for(scanf("%d", &Q); Q--;) {
            scanf("%d%d%d", &a, &b, &c);
            int x = lca(a, b, N, LCA, height); 
            int y = lca(a, c, N, LCA, height);
            int z = lca(b, c, N, LCA, height);
            int ans = distance[a] + distance[b] + distance[c]
                    - distance[x] - distance[y] - distance[z];
            printf("%d\n", ans);
        }
    }
}
