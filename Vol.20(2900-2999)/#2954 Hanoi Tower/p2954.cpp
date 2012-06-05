// iostream »á TLE
// 2812454 2008-03-30 21:51:34 Accepted 2954 C++ 00:00.09 840K ´ôÖÍµÄÂý°å  

#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int     T,  m,  n,  x,  y,  p;
    vector<int>     peg[3];
    peg[0].reserve( 10 );
    peg[1].reserve( 10 );
    peg[2].reserve( 10 );
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d%d", &m, &n );
        peg[0].resize( m );
        for( int i = 0; i < m; i++ )
            peg[0][i] = m - i;
        peg[1].resize( 0 );
        peg[2].resize( 0 );
        p = 0x7FFFFFFF;
        for( int i = 1; i <= n; i++ ) {
            scanf( "%d%d", &x, &y );
            if( p != 0x7FFFFFFF || x == y )
                continue;
            if( peg[x-1].size() && ( !peg[y-1].size() || peg[x-1].back() < peg[y-1].back() ) ) {
                peg[y-1].push_back( peg[x-1].back() );
                peg[x-1].pop_back();
            }
            else    p = -i;
            if( peg[2].size() == m )
                p = i;
        }
        if( p == 0x7FFFFFFF )
            puts( "0" );
        else
            printf( "%d\n", p );
    }

}
