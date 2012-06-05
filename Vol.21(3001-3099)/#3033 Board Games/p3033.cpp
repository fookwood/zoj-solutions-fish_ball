// 3058630 2008-09-03 19:39:44 Accepted 3033 C++ 00:00.96 960K 呆滞的慢板 

// 最短路，Bellman-ford，很无耻的，路径长度居然要用 long long  

#include <vector>
#include <iostream>
using namespace std;

typedef long long i64;
const i64 INT64_MAX = 0x7FFFFFFFFFFFFFFFll; 

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge(int v, int w, int l) :
        v(v), w(w), l(l) {}
};

int T,  N,  M,  s,  t;
vector<Edge>    E;

i64 D[300];

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        scanf( "%d%d%d%d", &N, &s, &t, &M );
        E.resize( M );
        for( int i = 0; i < M; ++i )
            scanf( "%d%d%d", &E[i].v, &E[i].w, &E[i].l );
        for( int i = 0; i < N; ++i )
            D[i] = INT64_MAX;
        D[s] = 0;
        bool loop;
        for( int i = 0; i < N; ++i ) {
            loop = false;
            for( int j = 0; j < M; ++j ) {
                if( D[E[j].v] != INT64_MAX &&
                    D[E[j].w] > D[E[j].v] + E[j].l ) {
                    loop = true;
                    D[E[j].w] = D[E[j].v] + E[j].l;
                }
            }
            if( !loop ) break;
        }
        if( loop || D[t] == INT64_MAX )
                puts( "infinity" );
        else    printf( "%lld\n", D[t] );
    }
    
}
