// 2915973 2008-05-15 15:32:14 Accepted 1862 C++ 00:00.00 392K ´ôÖÍµÄÂý°å 

// ¼òµ¥Ä£Äâ 

#include <cstdio>
#include <cstring>

char    A[12][12],  B[12][12],  C[12][12];
int     N,  T = 0;

int main() {

    while( scanf( "%d", &N ) != EOF ) {
        
        if( T++ )   puts( "" );

        memset( A, 0, sizeof( A ) );
        memset( B, 0, sizeof( B ) );
        memset( C, 0, sizeof( C ) );
        
        for( int i = 1; i <= N; ++i )    
            scanf( "%s", A[i] + 1 );
        
        for( int i = 1; i <= N; ++i )    
            scanf( "%s", B[i] + 1 );
            
        bool    touched = false;
        for( int i = 1; i <= N; ++i ) {
            for( int j = 1; j <= N; ++j ) {
                if( B[i][j] == 'x' ) {
                    C[i][j] = '0';
                    if( A[i][j] == '*' )
                        touched = true;
                    else for( int x = i - 1; x <= i + 1; ++x ) {
                        for( int y = j - 1; y <= j + 1; ++y )
                            C[i][j] += ( A[x][y] == '*' );
                    }
                }
                else    C[i][j] = '.';
            }
        }
        
        if( touched )
            for( int i = 1; i <= N; ++i )
                for( int j = 1; j <= N; ++j )
                    if( A[i][j] == '*' )
                        C[i][j] = '*';

        for( int i = 1; i <= N; ++i )
            puts( C[i] + 1 );
    
    }

}
