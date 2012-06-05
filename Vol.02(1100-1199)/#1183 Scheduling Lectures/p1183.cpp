// 3020014 2008-08-03 21:47:05 Accepted 1183 C++ 00:01.91 4760K 呆滞的慢板 

// 经典 DP，DP 到用第 i 个课时讲完 第 j 个题目时最小的不满度 

#include <iostream>
#include <algorithm>
using namespace std;

int     T,  N,  L,  C;
int     DP[1001][1001];
int     V[1001];

inline int getVal( int len ) {
    if( len == L )      return  0;
    if( L - len <= 10 ) return  -C;
    return  ( L - len - 10 ) * ( L - len - 10 );
}

int main() {
    
    for( cin >> T; T--; ) {

        int cs = 0;

        while( cin >> N && N ) {
            
            if( cs++ )  puts( "" );
    
            cin >> L >> C;
            for( int i = 1; i <= N; ++i )
                cin >> V[i];

            for( int i = 0; i <= N; ++i )
                for( int j = 0; j <= N + 1; ++j )
                    DP[i][j] = INT_MAX;
    
            DP[0][0] = 0;

            int x,  y,  z,  t;
            for( x = 0; x <= N && DP[x][N] == INT_MAX; ++x )
                for( y = x; DP[x][y] != INT_MAX; ++y )
                    for( t=V[z=y+1]; z<=N && t<=L; t+=V[++z] )
                        DP[x+1][z] <?= ( DP[x][y] + getVal( t ) );

            #ifndef ONLINE_JUDGE
            for( int i = 1; i <= N; ++i ){
                for( int j = 1; j <= N; ++j ) {
                    if( DP[i][j] == INT_MAX ) cout << "  NULL";
                        else    printf( "%6d", DP[i][j] );
                }
                puts( "" );
            }
            #endif

            printf( "Case %d:\n\n", cs );
            printf( "Minimum number of lectures: %d\n", x );
            printf( "Total dissatisfaction index: %d\n", DP[x][N] );

        }

        if( T ) puts( "" );

    }

}
