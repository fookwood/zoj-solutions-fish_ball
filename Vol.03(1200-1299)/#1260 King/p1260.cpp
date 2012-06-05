// 3047430 2008-08-23 17:17:00 Accepted 1260 C++ 00:00.00 840K 呆滞的慢板 

// 差分约束系统，先构图，bellman_ford 判负环 

#include <iostream>
using namespace std;

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge( int v, int w, int l ) :
        v( v ), w( w ), l( l ) {}
};

Edge    E[110];
int     N,  M,  x,  n,  len;
char    op[3];
int     dist[110];

bool bellman_ford() {
    memset( dist, 0, sizeof( dist ) );
    for( int t = 0; t < N; ++t ) {
        bool quit = true;
        for( int i = 0; i < M; ++i ) {
            if( dist[E[i].w] > dist[E[i].v] + E[i].l ) {
                dist[E[i].w] = dist[E[i].v] + E[i].l;
                quit = false;
            }
        }
        if( quit )  break;
    }
    for( int i = 0; i < M; ++i )
        if( dist[E[i].w] > dist[E[i].v] + E[i].l )
            return  false;
    return  true;
}

int main() {
    
    while( cin >> N && N ) {
        cin >> M;
        for( int i = 0; i < M; ++i ) {
            scanf( "%d%d%s%d", &E[i].v, &E[i].w, op, &E[i].l );
            E[i].w += E[i].v;
            E[i].v -= 1;
            if( op[0] == 'g' ) {
                swap( E[i].w, E[i].v );
                E[i].l = -E[i].l;
            }
            E[i].l -= 1;
        }

        puts( bellman_ford() ?
            "lamentable kingdom" :
            "successful conspiracy" );
    }
    
}
