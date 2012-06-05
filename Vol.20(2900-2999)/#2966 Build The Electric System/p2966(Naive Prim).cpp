// 2996846 2008-07-22 17:05:50 Accepted 2966 C++ 00:00.06 1372K 呆滞的慢板 

// 最小生成树：标准 Prim 算法

#include <cstdio>
#include <cstring>

int     W[500][500];
int     V,  E,  T,  L;
int     x,  y,  w;

bool    visited[500];
int     dist[500],  remain;

int main() {
    
    for( scanf( "%d", &T ); T--; ) {

        scanf( "%d%d", &V, &E );

        memset( W, -1, sizeof( W ) );

        while( E-- ) {
            scanf( "%d%d%d", &x, &y, &w );
            W[x][y] = W[y][x] = w;
        }

        memset( visited, 0, sizeof( visited ) );
        memset( dist, -1, sizeof( dist ) );

        visited[0] = true;
        remain = V - 1;
        L = 0;

        x = 0;
        while( remain-- ) {
            for( int i = 0; i < V; ++i )
                if( W[x][i] != -1 && !visited[i] )
                    if( dist[i] == -1 || W[x][i] < dist[i] )
                        dist[i] = W[x][i];
            int mn = 0x7FFFFFFF;
            for( int i = 0; i < V; ++i )
                if( !visited[i] && dist[i] != -1 && dist[i] < mn )
                    mn = dist[x = i];
            visited[x] = true;
            L += dist[x];
        }
        
        printf( "%d\n", L );
        
    }

} 
