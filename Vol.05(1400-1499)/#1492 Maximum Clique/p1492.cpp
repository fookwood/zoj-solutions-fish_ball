// 2878986 2008-04-29 18:51:22 Accepted 1492 C++ 00:01.74 460K 呆滞的慢板
// 最大团，NP 完全问题，用 DFS，看别人的算法写的
// 至于榜上的 0.0x 秒过的那堆人的算法我就不得而知了
// DFS 的搜索顺序对剪枝效率有着至关重要的影响，具体见解题报告。
 
#include <cstdio>

int     B[50][50],  maxi;
int     Clique[50], top;

void DFS( int* G, const int& N  ) {
    
    if( top + N <= maxi )   return;
    
    if( top > maxi )        maxi = top;

    for( int i = 0; i < N; ++i ) {
        
        Clique[top++] = G[i];

        int P[50],  M = 0;

        for( int j = i + 1; j < N; ++j )
            if( B[G[i]][G[j]] )
                P[M++] = G[j];

        DFS( P, M );

        --top;
        
    }

}

int main() {
    
    int     G[50],  N;

    while( scanf( "%d", &N ) && N ) {

        for( int i = 0; i < N; ++i )
            for( int j = 0; j < N; ++j )
                scanf( "%d", &B[i][j] );
        
        top = 0;
        maxi = 0;
        for( int i = 0; i < N; i++ )
            G[i] = i;

        DFS( G, N );

        printf( "%d\n", maxi );

    }
}
