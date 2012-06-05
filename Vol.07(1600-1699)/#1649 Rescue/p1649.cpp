// 2882769 2008-05-01 17:21:00 Accepted 1649 C++ 00:00.30 476K 呆滞的慢板 
// BFS，就是 WA... 中间有逻辑错误，然后换了种不用队列的方法...
// 慢死了，不是一个量级的复杂度... 

#include <cstdio>
#include <cstring>
#include <cstdlib>

int D[4][2] = { { 0,  1 }, {  1, 0 },
                { 0, -1 }, { -1, 0 } };

int     X,  Y,  step;
bool    change, keep, finish;
char    M[200][210];
char    N[200][210];

int main() {
    
    while( scanf( "%d%d ", &X, &Y ) != EOF ) {
        
        memset( M, 0, sizeof( M ) );
        
        for( int i = 1; i <= X; ++i )
            gets( M[i] + 1 );
        
        for( step = finish = 0; true; ++step ) {
            
            change = false;
            memcpy( N, M, sizeof( M ) );
            
            for( int i = 1; i <= X; ++i ) {
                
                for( int j = 1; j <= Y; ++j ) {
                    
                    if( N[i][j] == 'r' ) {
                        change = true;
                        keep = false;
                        for( int d = 0; d < 4; ++d ) {
                            switch( N[i+D[d][0]][j+D[d][1]] ) {
                                
                                case 'x':
                                    M[i+D[d][0]][j+D[d][1]] = '.';
                                    keep = true;
                                break;
                                
                                case '.':
                                    M[i+D[d][0]][j+D[d][1]] = 'r';
                                break;
                                
                                case 'a':
                                    finish = true;
                                break;
                                
                            }
                        }
                        
                        if( !keep )   M[i][j] = '#';
                        
                        if( finish )  break;
                        
                    }
                    
                }
                
                if( finish )  break;
                
            }
            
            if( !change || finish ) break;
        }
            
        if( finish )printf( "%d\n", step + 1 );
        else        puts( "Poor ANGEL has to stay in the prison all his life." );

    }
    
}
