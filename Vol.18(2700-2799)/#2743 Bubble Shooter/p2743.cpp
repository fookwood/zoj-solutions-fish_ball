// 2956897 2008-06-26 21:04:41 Accepted 2743 C++ 00:00.01 904K 呆滞的慢板 

// 泡泡龙，分类上写的是模拟，本质是 DFS

// 先在新增点上 DFS 一次，这次是同色才连通，DFS 过的 ++cnt，并标记为 'E'
// 这时，如果 cnt < 3，那么输出 0
// 否则，对第 0 行(顶部)所有点做 DFS1，这次只要有泡泡就连通
//     不用计数，访问过的标记为 'E'
// 然后，遍历所有点，如果还有泡泡(由于他们不与顶层连通，必然掉下来)，++cnt 

#include <cstdio>
#include <cctype>

char    A[100][101];
int     H,  W,  X,  Y,  cnt;

inline bool isValid( int x, int y ) {
    return  x >= 0 && y >= 0 && x < H && y < W;
}    

void DFS( int x, int y ) {
    
    char p = A[x][y];
    
    A[x][y] = 'E';
    
    ++cnt;
    
    if( x % 2 ) {
        if( isValid( x-1, y )   && A[x-1][y]   == p )   DFS( x-1, y );
        if( isValid( x-1, y+1 ) && A[x-1][y+1] == p )   DFS( x-1, y+1 );
        if( isValid( x+1, y )   && A[x+1][y]   == p )   DFS( x+1, y );
        if( isValid( x+1, y+1 ) && A[x+1][y+1] == p )   DFS( x+1, y+1 );
        if( isValid( x, y-1 )   && A[x][y-1]   == p )   DFS( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   == p )   DFS( x, y+1 );
    }
    
    else {
        if( isValid( x-1, y )   && A[x-1][y]   == p )   DFS( x-1, y );
        if( isValid( x-1, y-1 ) && A[x-1][y-1] == p )   DFS( x-1, y-1 );
        if( isValid( x+1, y )   && A[x+1][y]   == p )   DFS( x+1, y );
        if( isValid( x+1, y-1 ) && A[x+1][y-1] == p )   DFS( x+1, y-1 );
        if( isValid( x, y-1 )   && A[x][y-1]   == p )   DFS( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   == p )   DFS( x, y+1 );
    }
    
}

void DFS1( int x, int y ) {
    
    A[x][y] = 'E';
    
    if( x % 2 ) {
        if( isValid( x-1, y )   && A[x-1][y]   > 'E' )   DFS1( x-1, y );
        if( isValid( x-1, y+1 ) && A[x-1][y+1] > 'E' )   DFS1( x-1, y+1 );
        if( isValid( x+1, y )   && A[x+1][y]   > 'E' )   DFS1( x+1, y );
        if( isValid( x+1, y+1 ) && A[x+1][y+1] > 'E' )   DFS1( x+1, y+1 );
        if( isValid( x, y-1 )   && A[x][y-1]   > 'E' )   DFS1( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   > 'E' )   DFS1( x, y+1 );
    }
    
    else {
        if( isValid( x-1, y )   && A[x-1][y]   > 'E' )   DFS1( x-1, y );
        if( isValid( x-1, y-1 ) && A[x-1][y-1] > 'E' )   DFS1( x-1, y-1 );
        if( isValid( x+1, y )   && A[x+1][y]   > 'E' )   DFS1( x+1, y );
        if( isValid( x+1, y-1 ) && A[x+1][y-1] > 'E' )   DFS1( x+1, y-1 );
        if( isValid( x, y-1 )   && A[x][y-1]   > 'E' )   DFS1( x, y-1 );
        if( isValid( x, y+1 )   && A[x][y+1]   > 'E' )   DFS1( x, y+1 );
    }
    
}

int main() {
    
    while( scanf( "%d%d%d%d", &H, &W, &X, &Y ) != EOF ) {
    
        gets( A[0] );
    
        for( int i = 0; i < H; ++i )
            gets( A[i] );
            
        cnt = 0;
        
        DFS( X - 1, Y - 1 );
        
        if( cnt < 3 ) {
            puts( "0" );
            continue;
        }
        
        for( int i = 0; i < W; ++i ) {
            if( A[0][i] != 'E' )
                DFS1( 0, i );
        }
        
        for( int i = 0; i < H; ++i )
            for( int j = 0; j < W; ++j )
                if( A[i][j] && A[i][j] != 'E' )
                    ++cnt;
        
        printf( "%d\n", cnt );
    
    }
    
}
