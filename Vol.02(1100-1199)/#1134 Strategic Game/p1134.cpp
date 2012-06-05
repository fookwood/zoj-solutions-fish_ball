// 3047595 2008-08-23 19:20:40 Accepted 1134 C++ 00:00.57 944K 呆滞的慢板 

// 简单 DFS，如果一个节点他有一个儿子没被标记，标记该节点并基数加一
// 否则不标记，这是个贪心的结论 

#include <iostream>
#include <vector>
using namespace std;

vector<int> V[1500];

int     N,  x,  y,  k,  cnt;

bool    B[1500];

bool DFS( int v ) {
    B[v] = true;
    bool cover = false;
    for( int i = 0; i < V[v].size(); ++i ) {
        if( B[V[v][i]] ) continue;
        cover |= DFS( V[v][i] );
    }
    cnt += cover;
    return  !cover;
}

int main() {
    
    while( scanf( "%d", &N ) != EOF ) {
        
        for( int i = 0; i < N; ++i )
            V[i].clear();

        for( int i = 0; i < N; ++i ) {
            for( scanf( "%d:(%d)", &x, &k ); k--; ) {
                scanf( "%d", &y );
                V[x].push_back( y );
                V[y].push_back( x );
            }
        }
        
        memset( B, 0, sizeof( B ) );
        
        DFS( cnt = 0 );
        
        printf( "%d\n", cnt );
    
    }
    
}
