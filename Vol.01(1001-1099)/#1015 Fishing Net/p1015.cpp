// 3067587 2008-09-12 19:17:26 Accepted 1015 C++ 00:04.98 17996K 呆滞的慢板 

// 弦图的判定，最高势能搜索 + 完美消去序测试。 

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int V,  E;

vector<int> G[1000];
vector<pair<int, int> > P;
vector<pair<int, int> >::iterator it;

bool X[1000][1000];

int ord[1000], cdn[1000], seq[1000];

int main() {
    
    while( scanf( "%d%d", &V, &E ) && V ) {
        for( int i = 0; i < V; ++i )
            G[i].clear();
        memset(X, 0, sizeof(X));
        for( int i = 0; i < E; ++i ) {
            int x,  y;
            scanf( "%d%d", &x, &y );
            G[x-1].push_back(y-1);
            G[y-1].push_back(x-1);
            X[x-1][y-1] = X[y-1][x-1] = true;
        }
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

        bool yes = true;
        for(int i = 0; i < P.size(); ++i)
            yes &= X[P[i].first][P[i].second];

        puts(yes ? "Perfect\n" : "Imperfect\n");
        
    }
    
}
