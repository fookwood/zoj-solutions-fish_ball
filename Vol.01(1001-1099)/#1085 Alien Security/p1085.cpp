// 2976651 2008-07-14 11:53:18 Accepted 1085 C++ 00:00.00 880K 呆滞的慢板 

// 有向图...

// 从一个出发点到目的点的路径当中，必经的顶点中，离目的点最近的顶点

// 先判断一个顶点是否为必经点：
//     先禁闭该顶点(标记为已访问)，然后 DFS 判断 0->ET 的可达性
//     如果不可达，那么禁闭的顶点为必经点
//     邻接矩阵单次 DFS 复杂度 V^2，那么判必经点 O(V^3)
// 然后 Floyd 一下，枚举必经点，取出最近的，总复杂度 O(V^3) 


#include <iostream>
using namespace std;

const int MAXN = 101; 

int     T,  N,  ET, x,  y;

int     V[MAXN][MAXN];
bool    Y[MAXN], P[MAXN]; 

char    WS[10]; 

bool DFS( int v ) {
    if( v == ET )   return  true; 
    P[v] = true; 
    for( int i = 0; i <= N; ++i )
        if( !P[i] && V[v][i] && DFS( i ) )
            return  true; 
    return  false; 
} 

int main() {
    
    for( scanf( "%d", &T ); T--; ) {
        
        scanf( "%d%d", &N, &ET );
        gets( WS ); 
        
        memset( V, 0, sizeof( V ) );
        
        while( cin.peek() != '\n' && cin.peek() != -1 ) {
            
            scanf( "%d%d", &x, &y );
            
            V[x][y] = 1;
            
            gets( WS );
            
        } 
        
        Y[0] = true; 
        for( int i = 1; i <= N; ++i ) {
            // 禁闭某个点，然后 DFS 判断 0 与 ET 是否还连通
            memset( P, 0, sizeof( P ) );
            P[i] = true;
            Y[i] = i != ET && !DFS( 0 ); 
        }
        
        // floyed 
        for( int i = 0; i <= N; ++i )
            for( int j = 0; j <= N; ++j )
                if( V[j][i] ) 
                for( int k = 0; k <= N; ++k )
                    if( V[i][k] && !V[j][k] ||
                        V[j][k] > V[j][i] + V[i][k] )
                        V[j][k] = V[j][i] + V[i][k];
                        
        int p = 0;
        for( int i = 0; i <= N; ++i )
            if( Y[i] && V[i][ET] && V[i][ET] < V[p][ET] )
                p = i; 
                
        printf( "Put guards in room %d.\n", p );
        
        if( T ) puts( "" ); 
                
    }
    
}
