// 3048160 2008-08-24 01:33:29 Accepted 2770 C++ 00:00.08 960K 呆滞的慢板 

// 典型差分约束系统 

#include <iostream>
using namespace std;

struct Edge { int v, w, l; };

int     C[1001],    N,  M;

Edge    E[10001];

int     D[1001];

bool bellman_ford() {
    
    memset( D, 0, sizeof( D ) );
    
    for( int t = 0; t < N; ++t ) {
        bool quit = true;
        for( int i = 0; i < M; ++i ) {
            if( D[E[i].w] > D[E[i].v] + E[i].l ) {
                D[E[i].w] = D[E[i].v] + E[i].l;
                quit = false;
            }
        }
        for( int i = 1; i <= N; ++i ) {
            if( D[i-1] > D[i] ) {
                D[i-1] = D[i];
                quit = false;
            }
            if( D[i] > D[i-1] + C[i] ) {
                D[i] = D[i-1] + C[i];
                quit = false;
            }
        }
        if( quit )  break;
    }
    
    for( int i = 0; i < M; ++i )
        if( D[E[i].w] > D[E[i].v] + E[i].l )
            return  false;
    for( int i = 1; i <= N; ++i ) {
        if( D[i-1] > D[i] )
            return  false;
        if( D[i] > D[i-1] + C[i] )
            return  false;
    }
    
    return  true;
    
}

int main() {
    
    while( cin >> N >> M ) {
        
        for( int i = 1; i <= N; ++i )
            scanf( "%d", C + i );
        
        for( int i = 0; i < M; ++i ) {
            int x,  y;
            scanf( "%d%d%d", &x, &y, &E[i].l );
            E[i].v = y;
            E[i].w = x - 1;
            E[i].l *= -1;
        }
        
        if( !bellman_ford() )   puts( "Bad Estimations" );
        
        else    cout << D[N] - D[0] << endl;
        
    }
    
}
