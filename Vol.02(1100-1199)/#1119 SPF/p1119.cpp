// 3002489 2008-07-24 18:02:09 Accepted 1119 C++ 00:00.00 872K ´ôÖÍµÄÂý°å 

// Çó¸î¶¥ 

#include <vector>
#include <iostream>
using namespace std; 

int     pre[1001], ord[1001], tre[1001],
        low[1001], prt[1001], cnt; 

vector<int> G[1001]; 

void DFS( int v ) {
    
    int w;
    
    low[v] = ord[v] = cnt++;
    
    for( int i = 0; i < G[v].size(); ++i ) {
        w = G[v][i];
        if( ord[w] == -1 ) {
            ++tre[v];
            pre[w] = v;
            DFS( w );
            if( low[v] > low[w] )
                low[v] = low[w];
            if( low[w] >= ord[v] )
                ++prt[v];
        }
        else if( w != pre[v] )
            if( low[v] > ord[w] )
                low[v] = ord[w];
    }

}

int main() {

    int x,  y,  z,  T = 0; 
    
    while( cin >> x && x ) {
        
        int mx = -1;
        
        for( int i = 1; i < 1001; ++i ) {
            G[i].clear();
            ord[i] = low[i] = pre[i] = -1;
            tre[i] = prt[i] = 0;
        }
        
        while( x ) {
            cin >> y >> z;
            if( mx < x ) mx = x;
            if( mx < y ) mx = y;
            G[x].push_back( y );
            G[y].push_back( x );
            x = z;
        }
        
        #ifndef ONLINE_JUDGE
            for( int i = 1; i <= mx; ++i ) {
                printf( "%d: ", i );
                for( int j = 0; j < G[i].size(); ++j )
                    printf( "%d ", G[i][j] );
                puts( "" );
            }
        #endif
        
        cnt = 0;
        
        DFS( y );
        
        prt[y] = tre[y] - 1;
        
        #ifndef ONLINE_JUDGE
            printf( "ord: " ); for( int i = 1; i <= mx; ++i ) printf( "%3d", ord[i] ); puts( "" );
            printf( "pre: " ); for( int i = 1; i <= mx; ++i ) printf( "%3d", pre[i] ); puts( "" );
            printf( "low: " ); for( int i = 1; i <= mx; ++i ) printf( "%3d", low[i] ); puts( "" );
            printf( "tre: " ); for( int i = 1; i <= mx; ++i ) printf( "%3d", tre[i] ); puts( "" );
            printf( "prt: " ); for( int i = 1; i <= mx; ++i ) printf( "%3d", prt[i] ); puts( "" );
        #endif
        
        if( T++ )   puts( "" );
        printf( "Network #%d\n", T );
        bool yes = false;
        for( int i = 1; i < 1001; ++i ) {
            if( prt[i] ) {
                printf( "  SPF node %d leaves %d subnets\n", i, prt[i] + 1 );
                yes = true;
            }
        }
        if( !yes )  puts( "  No SPF nodes" );
        
    }
    
} 
