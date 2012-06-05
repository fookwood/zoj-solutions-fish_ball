// 最小生成树 Kruscal
// 并查集的压缩路径省去了，因此比较慢
// 2845225 2008-04-15 15:37:04 Accepted 1372 C++ 00:00.35 884K 呆滞的慢板  

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int x,  y,  l;
    Edge() {}
    Edge( int ) { cin >> x >> y >> l; }
};

bool operator < ( const Edge& e1, const Edge& e2 ) {
    return  e1.l < e2.l;
}

int main() {
    int     V[51],  v,  e;
    vector<Edge>    E;
    while( ( cin >> v ) && v ) {
        cin >> e;
        E.clear();
        for( int i = 1; i <= v; i++  )
            V[i] = i;
        for( int i = 0; i < e; i++ )
            E.push_back( Edge( 1 ) );
        sort( E.begin(), E.end() );
        int     N = v - 1;
        int     sum = 0;
        for( int i = 0; i < E.size(); i++ ) {
            int     p = E[i].x,  q = E[i].y;
            while( p != V[p] )  p = V[p];
            while( q != V[q] )  q = V[q];
            if( p == q )    continue;
            V[p] = q;
            sum += E[i].l;
            if( !N-- )   break;
        }
        cout << sum << endl;
    }
}
