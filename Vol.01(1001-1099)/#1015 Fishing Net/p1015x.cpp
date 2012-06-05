// 3067626 2008-09-12 19:39:25 Accepted 1015 C++ 00:02.03 10348K 呆滞的慢板 

// 弦图的判定，最高势能搜索 + 完美消去序测试。 

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template<int SZ>
class Graph {

    int V,  E;
    vector<int> G[SZ];
    vector<pair<int, int> > P;

    bool X[SZ][SZ];

    int ord[SZ], cdn[SZ], seq[SZ];
    
public:
    
    void init(int N) {
        V = N;
        for( int i = 0; i < V; ++i )
            G[i].clear();
        memset(X, 0, sizeof(X));
    }
    
    void insert(int v, int w) {
        G[v].push_back(w);
        G[w].push_back(v);
        X[v][w] = X[w][v] = true;
    }
    
    bool chordal() {
        memset(ord, -1, sizeof(ord));
        memset(cdn, 0, sizeof(cdn));
        for(int rem = 0; rem < V; ++rem) {
            int mx = -1, pos;
            for(int i = 0; i < V; ++i)
                if(ord[i] == -1 && cdn[i] > mx)
                    mx = cdn[pos = i];
            ord[pos] = rem;
            seq[rem] = pos;
            for(int i = 0; i < G[pos].size(); ++i)
                ++cdn[G[pos][i]];
        }
        P.clear();
        for(int i = 1; i < V; ++i) {
            int v = seq[i], u, w, p = -1;
            vector<int> temp(0);
            for(int j = 0; j < G[v].size(); ++j) {
                u = G[v][j];
                if(ord[u] < i) {
                    temp.push_back(u);
                    if(ord[u] > p)
                        p = ord[w = u];
                }
            }
            for(int k = 0; k < temp.size(); ++k)
                if(temp[k] != w)
                    P.push_back(make_pair(temp[k], w));
        }
        for(int i = 0; i < P.size(); ++i)
            if(!X[P[i].first][P[i].second])
                return  false;
        return  true;
    }
    
};

Graph<1000> G;
int V,  E;

int main() {

    while( scanf( "%d%d", &V, &E ) && V ) {
        G.init(V);
        for( int i = 0; i < E; ++i ) {
            int x,  y;
            scanf( "%d%d", &x, &y );
            G.insert(x-1, y-1);
        }
        puts(G.chordal() ? "Perfect\n" : "Imperfect\n");
    }
    
}
