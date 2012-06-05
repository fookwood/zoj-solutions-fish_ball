// 2932866 2008-05-25 22:03:15 Accepted 1628 C++ 00:00.00 392K 呆滞的慢板 

// 规模太小，霸王硬上弓...
// 这个时候，代码快是首要的 

#include <cstdio>

char    A[9][10];
int     X1, Y1, X2, Y2;

int main() {
    
    while( scanf( "%s", A[1] + 1 ) != EOF ) {

        for( int i = 2; i <= 8; ++i )
            scanf( "%s", A[i] + 1 );

        scanf( "%d%d%d%d", &X1, &Y1, &X2, &Y2 );
        
        char    c = A[X1][Y1];
        A[X1][Y1] == A[X2][Y2];
        A[X2][Y2] = c;

        bool    yes = false;
        
        for( int i = 1; i <= 6; ++i ) {
            for( int j = 1; j <= 8; ++j ) {
                if( A[i][j] == A[i+1][j] &&
                    A[i][j] == A[i+2][j] )
                    yes = true;
            }
        }
        
        for( int j = 1; j <= 6; ++j ) {
            for( int i = 1; i <= 8; ++i ) {
                if( A[i][j] == A[i][j+1] &&
                    A[i][j] == A[i][j+2] )
                    yes = true;
            }
        }
        
        if( ( X1 - X2 ) * ( X1 - X2 ) +
            ( Y1 - Y2 ) * ( Y1 - Y2 ) != 1 )
            yes = false;
        
        puts( yes ? "Ok!" : "Illegal move!" );

    }
    
}
