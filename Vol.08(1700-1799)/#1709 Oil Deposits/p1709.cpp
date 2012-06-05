// ¼òµ¥ DFS 
// 2822106 2008-04-04 01:44:11 Accepted 1709 C++ 00:00.00 452K ´ôÖÍµÄÂý°å 

#include <cstdio>
#include <cstring>

char A[100][101],    M,  N;

void DFS( const int& x, const int& y ) {
    if( x >= 0 && y >= 0 &&
        x < M  && y < N  &&
        A[x][y] == '@'  ) {
        A[x][y] = '*';
        DFS( x - 1, y );
        DFS( x + 1, y );
        DFS( x, y - 1 );
        DFS( x, y + 1 );
        DFS( x + 1, y + 1 );
        DFS( x - 1, y + 1 );
        DFS( x + 1, y - 1 );
        DFS( x - 1, y - 1 );
    }
}

int main() {
    while( scanf( "%d%d", &M, &N ) && M ) {
        for( int i = 0; i < M; i++ )
            scanf( "%s", A[i] );
        int     count = 0;
        for( int i = 0; i < M; i++ ) {
            for( int j = 0; j < N; j++ ) {
                if( A[i][j] == '@' ) {
                    DFS( i, j );
                    count++;
                }
            }
        }
        printf( "%d\n", count );
    }
}
