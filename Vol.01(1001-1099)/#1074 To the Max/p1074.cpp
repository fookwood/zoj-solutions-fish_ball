// 先求和，再枚举上下界的 x,y
// O(n^4)
#include <cstdio>

int main() {
    
    int     N,  A[100][100],    temp,   max;
    
    while( scanf( "%d", &N ) != EOF ) {
    
        for( int i = 0; i < N; i++ )
            for( int j = 0; j < N; j++ )
                scanf( "%d", &A[i][j] );
        
        for( int i = 0; i < N; i++ ) {
            for( int j = 0; j < N; j++ ) {
                if( i )         A[i][j] += A[i - 1][j];
                if( j )         A[i][j] += A[i][j - 1];
                if( i && j )    A[i][j] -= A[i - 1][j - 1];
            }
        }
        
        max = -0x7FFFFFFF;
        
        for( int i1 = -1; i1 < N - 1; i1++ )
            for( int i2 = i1 + 1; i2 < N; i2++ )
                for( int j1 = -1; j1 < N - 1; j1++ )
                    for( int j2 = j1 + 1; j2 < N; j2++ ) {
                        temp = A[i2][j2];
                            if( i1 > -1 )
                                temp -= A[i1][j2];
                            if( j1 > -1 )
                                temp -= A[i2][j1];
                            if( i1 > -1 && j1 > -1 )
                                temp += A[i1][j1];
                            if( temp > max )
                                max = temp;
        }
        
        printf( "%d\n", max );
    
    }

}
