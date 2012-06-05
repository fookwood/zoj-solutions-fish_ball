// 3065906 2008-09-10 19:34:33 Accepted 2353 C++ 00:00.05 856K 呆滞的慢板 

// 构图，树型 DP，即 DFS 一次就行，注意，题目保证构造的图是一个森林。 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,  M,  P;

int E[200];

vector<int> V[200];

int DP[2][200];

void DFS( int v ) {
    DP[0][v] = 0;
    DP[1][v] = E[v];
    for( int i = V[v].size()-1; i >= 0; --i ) {
        int w = V[v][i];
        if( DP[0][w] == -1 ) {
            DFS( w );
            DP[0][v] += max( DP[0][w], DP[1][w] );
            DP[1][v] += DP[0][w];
        }
    }
}

int main() {
    
    while( scanf( "%d%d", &N, &M ) && N ) {
        
        for( int i = 0; i < N; ++i ) {
            scanf( "%d", E + i );
            V[i].clear();
        }
        
        for( int i = 0; i < M; ++i ) {
            scanf( "%d", &P );
            for( int j = 1; j < N; ++j ) {
                int *pos = lower_bound(E, E+j, E[j]-P);
                if(pos < E + j && *pos == E[j] - P) {
                    V[j].push_back( pos-E );
                    V[pos-E].push_back( j );
                }
            }
        }
        
        memset( DP, -1, sizeof( DP ) );
        
        int tot = 0;
        
        for( int i = 0; i < M; ++i ) {
            if( DP[0][i] == -1 ) {
                DFS( i );
                tot += max( DP[0][i], DP[1][i] );
            }
        }
        
        printf( "%d\n", tot );
        
    }
    
}
