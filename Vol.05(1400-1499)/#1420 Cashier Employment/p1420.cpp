// 3048002 2008-08-23 21:57:31 Accepted 1420 C++ 00:00.03 836K 呆滞的慢板 

// 差分约束 + 参数二分 

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int v,  w,  l;
    Edge() {}
    Edge( int v, int w, int l ) :
        v( v ), w( w ), l( l ) {}
};

int     T,  N,  K;

int     A[25],  B[25];

int     dist[25];

Edge    E[24];

bool bellman_ford( int x ) {
    
    for( int i = 16; i < 24; ++i )
        E[i].l = x - A[i-15];
        
    memset( dist, 0, sizeof( dist ) );

    for( int r = 0; r < 24; ++r ) {
        bool quit = true;
        if( dist[0] > dist[24] - x ) {
            quit = false;
            dist[0] = dist[24] - x;
        }
        for( int i = 24; i > 0; --i ) {
            if( dist[i-1] > dist[i] ) {
                quit = false;
                dist[i-1] = dist[i];
            }
            if( dist[i] > dist[i-1] + B[i] ) {
                quit = false;
                dist[i] = dist[i-1] + B[i];
            }
            if( dist[E[i].w] > dist[E[i].v] + E[i].l ) {
                quit = false;
                dist[E[i].w] = dist[E[i].v] + E[i].l;
            }
        }
        if( quit )  break;
    }
    
    if( dist[0] > dist[24] - x )
        return  false;
    for( int i = 24; i > 0; --i ) {
        if( dist[i-1] > dist[i] )
            return  false;
        if( dist[i] > dist[i-1] + B[i] )
            return  false;
        if( dist[E[i].w] > dist[E[i].v] + E[i].l )
            return  false;
    }
    
    return  true;
    
}

int main() {
    
    for( cin >> T; T--; ) {
        
        for( int i = 1; i <= 24; ++i )
            cin >> A[i];
        
        memset( B, 0, sizeof( B ) );
        
        cin >> N;
        
        for( int i = 0; i < N; ++i ) {
            cin >> K;
            ++B[K + 1];
        }
        
        for( int i = 1; i <= 16; ++i )
            E[i-1] = Edge( i+8, i, -A[i+8] );
        
        for( int i = 17; i <= 24; ++i )
            E[i-1] = Edge( i-16, i, 0 );
        
        int l = 0,  m,  r = N + 1;

        while( r - l > 1 ) {
            m = ( r + l ) / 2;
            if( bellman_ford( m ) )
                    r = m;
            else    l = m;
        }
        
        if( r == N + 1 )    puts( "No Solution" );
        else                cout << r << endl;
        
    }
    
}
