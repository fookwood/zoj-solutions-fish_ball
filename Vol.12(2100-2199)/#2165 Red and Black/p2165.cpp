// 2925805 2008-05-20 23:17:09 Accepted 2165 C++ 00:00.00 456K 呆滞的慢板 

// 入门级 DFS

#include <cstdio>
#include <cstring>

char    A[20][21];
int     W,  H,  tot;

void DFS( const int& x, const int& y ) {
    if( x < 0 || x >= H ||
        y < 0 || y >= W ||
        A[x][y] == '#' ) {
        return;
    }
    ++tot;
    A[x][y] = '#';
    DFS( x + 1, y );
    DFS( x, y - 1 );
    DFS( x, y + 1 );
    DFS( x - 1, y );
    
}

int main() {

    while( scanf( "%d%d", &W, &H ) && W ) {
    
        int xx, yy;
        
        gets( A[0] );
        
        for( int i = 0; i < H; ++i ) {
            gets( A[i] );
            for( int j = 0; A[i][j]; ++j ) {
                if( A[i][j] == '@' ) {
                    xx = i;
                    yy = j;
                }
            }
        }
        
        tot = 0;
        DFS( xx, yy );
        printf( "%d\n", tot );
    
    }

}
