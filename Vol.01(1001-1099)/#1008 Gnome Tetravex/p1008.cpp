// 搜索 + 剪枝
// 剪枝方法是合并相同的方块
// 2829491 2008-04-07 20:01:24 Accepted 1008 C++ 00:05.47 444K 呆滞的慢板  

#include <cstdio>
#include <cstring>

struct  Square {
    int     num[4];
};

bool operator == ( const Square& s1, const Square& s2 ) {
    return  s1.num[0] == s2.num[0] &&
            s1.num[1] == s2.num[1] &&
            s1.num[2] == s2.num[2] &&
            s1.num[3] == s2.num[3] ;
}

int     N,  N2, C[25];
Square  A[5][5],  B[25];
bool    success;

inline bool matchY( const Square& s1, const Square& s2 ) {
    return  s1.num[0] == s2.num[2];
}

inline bool matchX( const Square& s1, const Square& s2 ) {
    return  s1.num[3] == s2.num[1];
}

void DFS( const int& x, const int& y ) {
    if( x >= N )    success = true;
    if( success )   return;
    for( int i = 0; i < N2; i++ ) {
        bool    next = true;
        if( !C[i] ) continue;
        if( x > 0 && !matchY( B[i], A[x-1][y] ) )
            next = false;
        if( y > 0 && !matchX( B[i], A[x][y-1] ) )
            next = false;
        if( !next ) continue;
        C[i]--;
        A[x][y] = B[i];
        DFS( x + ( y + 1 ) / N, ( y + 1 ) % N );
        C[i]++;
    }
}

int main() {
    int     T = 0;
    while( scanf( "%d", &N ) && N ) {
        memset( C, 0, 25 * sizeof( int ) );
        N2 = N * N;
        int top = 0;
        for( int i = 0; i < N2; i++ ) {
            for( int j = 0; j < 4; j++ )
                scanf( "%d", &B[top].num[j] );
            int     p = -1;
            while( ++p < top ) {
                if( B[p] == B[top] )
                break;
            }
            if( p == top )
                C[top++]++;
            else
                C[p]++;
        }
        N2 = top;
        success = false;
        DFS( 0, 0 );
        if( T++ )   putchar( '\n' );
        printf( "Game %d", T );
        puts( success ? ": Possible" : ": Impossible" );
    }
}
