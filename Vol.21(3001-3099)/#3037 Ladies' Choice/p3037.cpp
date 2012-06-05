// 3058215 2008-09-03 11:28:07 Accepted 3037 C++ 00:03.01 8680K ¥Ù÷Õµƒ¬˝∞Â 

// æ≠µ‰Œ»∂®ªÈ≈‰ 

#include <iostream>
#include <queue>
using namespace std;

const int SZ = 1000;

int N,  T;
int G[SZ][SZ],  B[SZ][SZ],  X[SZ];
int P[SZ],      GM[SZ],     BM[SZ];

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        scanf( "%d", &N );
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < N; ++j ) {
                scanf( "%d", &G[i][j] );
                G[i][j] -= 1;
            }
        }
        for( int i = 0; i < N; ++i ) {
            for( int j = 0; j < N; ++j )
                scanf( "%d", X + j );
            for( int j = 0; j < N; ++j )
                B[i][X[j]-1] = j;
        }
        queue<int>  Q;
        memset( P, 0, sizeof( P ) );
        memset( GM, -1, sizeof( GM ) );
        memset( BM, -1, sizeof( BM ) );
        for( int i = 0; i < N; ++i )
            Q.push( i );
        while( !Q.empty() ) {
            int i = Q.front();
            Q.pop();
            for( ; P[i] < N; ++P[i] ) {
                int j = G[i][P[i]];
                if( BM[j] == -1 ) {
                    GM[i] = j;
                    BM[j] = i;
                    break;
                }
                if( B[j][i] < B[j][BM[j]] ) {
                    ++P[BM[j]];
                    Q.push( BM[j] );
                    BM[j] = -1;
                    GM[i] = j;
                    BM[j] = i;
                    break;
                }
            }
        }
        for( int i = 0; i < N; ++i ) {
            if( GM[i] == -1 ) while( 1 )
                puts( "If it exist an unvalid case, OJ returns OLE here." );
            printf( "%d\n", GM[i] + 1 );
        }
    }
    
}
