// 3005516 2008-07-26 00:06:20 Accepted 1655 C++ 00:00.18 916K 呆滞的慢板 

// Floyd 实现，超级 WS 的数据！！有平行边！！ 

#include <iostream>
using namespace std;

double  G[101][101];

double  val[101],   z,  tot;

int N,  M,  x,  y;

int main() {
    
    while( scanf( "%d%d", &N, &M ) != EOF ) {
    
        for( int i = 1; i < N; ++i )
            scanf( "%lf", val + i );
        
        memset( G, 0, sizeof( G ) );
        
        while( M-- ) {
            scanf( "%d%d%lf", &x, &y, &z );
            if( G[y][x] < 1.0 - z )
                G[y][x] = 1.0 - z; 
            G[x][y] = G[y][x];
        }
        
        for( int k = 1; k <= N; ++k )
            for( int i = 1; i <= N; ++i )
                for( int j = 1; j <= N; ++j )
                    if( G[i][k] * G[k][j] > G[i][j] )
                         G[i][j] = G[i][k] * G[k][j];
        
        tot = 0.0;
        for( int i = 1; i < N; ++i )
            tot += ( val[i] * G[N][i] );
            
        printf( "%.2lf\n", tot );
    
    }
    
}
