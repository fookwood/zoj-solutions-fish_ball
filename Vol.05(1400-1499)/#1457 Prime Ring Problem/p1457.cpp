// 这是一道标准的 DFS 题
// 偷懒用了 STL, 不用的话可能更爽
// AC in 0.72s, 840k 
#include <cstdio>
#include <vector>
using namespace std;

const bool prime[] = {  0, 1, 1, 1, 0, 1, 0, 1, 0, 0,
                        0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                        0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                        0, 1, 0, 0, 0, 0, 0, 1, 0  };
bool    adj[20][20],   status[20];
int     N,  T = 1;
vector<int>	stk;

void DFS( const int& v ) {
    if( stk.size() == N ) {
        if( adj[stk.front()][stk.back()] ) {
            putchar( '1' );
            for( int i = 1; i < N; i++ )
                printf( " %d", stk[i] );
            putchar( '\n' );
        }
        return;
    }
    for( int i = 2; i <= N; i++ ) {
        if( !status[i] && adj[v][i] ) {
            status[i] = true;
            stk.push_back( i );
            DFS( i );
            stk.pop_back();
            status[i] = false;
        }
    }
}

int main() {
    for( int i = 1; i < 20; i++ )
        for( int j = 1; j < 20; j++ )
            adj[i][j] = prime[i + j];
    while( scanf( "%d", &N ) != EOF ) {
        printf( "Case %d:\n", T++ );
        stk.resize( 0 );
        stk.push_back( 1 );
        status[1] = true;
        for( int i = 2; i <= N; i++ )
            status[i] = false;
        if( N % 2 == 0 ) DFS( 1 );
        putchar( '\n' );
    }
}
