// 2955656 2008-06-24 11:03:28 Accepted 1636 C++ 00:00.45 1372K 呆滞的慢板 

// 先作累加，然后应用容斥原理，类似于 1074 to the max 
// 整体复杂度 O( R * C + Q )，显然已达下界 

#include <cstdio>

int     A[500][500];
int     R,  C,  Q,  T; 
int     a,  b,  c,  d;

int main() {
    
    scanf( "%d", &T ); 
    
    for( int t = 1; t <= T; ++t ) {
        
        scanf( "%d%d", &R, &C );
        
        printf( "Case %d:\n", t ); 
        
        for( int i = 0; i < R; i++ ) {
            for( int j = 0; j < C; j++ ) {
                scanf( "%d", &A[i][j] );
                A[i][j] *= A[i][j]; 
            }
        }
        
        for( int i = 0; i < R; i++ ) {
            for( int j = 0; j < C; j++ ) {
                if( i )         A[i][j] += A[i - 1][j];
                if( j )         A[i][j] += A[i][j - 1];
                if( i && j )    A[i][j] -= A[i - 1][j - 1];
            }
        }
        
        for( scanf( "%d", &Q ); Q--; ) {
            
            scanf( "%d%d%d%d", &a, &b, &c, &d );
            
            int val = A[c-1][d-1];
            if( a > 1 ) 
                val -= A[a-2][d-1];
            if( b > 1 )
                val -= A[c-1][b-2];
            if( a > 1 && b > 1 )
                val += A[a-2][b-2];

            printf( "%d\n", val );
        
        }
    
    }

}
