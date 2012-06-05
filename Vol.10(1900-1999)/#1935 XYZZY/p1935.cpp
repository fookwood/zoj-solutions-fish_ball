// 3013993 2008-07-30 15:55:48 Accepted 1935 C++ 00:01.07 940K 呆滞的慢板 

// 带负环的最短路，SPFA
// 注意可达性 

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> V[101], W[101]; 

int     N,  M,  x,  y;

int     val[101], wgt[101];

bool    rch[101]; 

deque<pair<int, int> > Q; 

void DFS( int w ) {
    rch[w] = true;
    for( int i = 0; i < W[w].size(); ++i )
        if( !rch[W[w][i]] )
            DFS( W[w][i] );
}

int main() {
    
    while( cin >> N && N != -1 ) {
        
        for( int i = 1; i <= N; ++i )
            W[i].clear();
        
        for( int i = 1; i <= N; ++i ) {
            cin >> wgt[i] >> M;
            V[i].resize( M );
            for( int j = 0; j < M; ++j ) {
                cin >> V[i][j];
                W[V[i][j]].push_back( i );
            }
        }
        
        memset( rch, 0, sizeof( rch ) );
        
        DFS( N );
        
        memset( val, 0, sizeof( val ) );
        
        Q.clear(); 
        
        val[1] = 100;
        
        for( int i = 0; i < V[1].size(); ++i )
            Q.push_back( make_pair( 1, V[1][i] ) );
        
        while( !Q.empty() ) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop_front();
            if( val[x] + wgt[y] > val[y] && rch[y] ) {
                val[y] = val[x] + wgt[y];
                for( int i = 0; i < V[y].size(); ++i )
                    Q.push_back( make_pair( y, V[y][i] ) );
            }
            if( val[N] > 0 )   break;
        }
        
        puts( val[N] > 0 ? "winnable" : "hopeless" );
        
    } 
    
}
