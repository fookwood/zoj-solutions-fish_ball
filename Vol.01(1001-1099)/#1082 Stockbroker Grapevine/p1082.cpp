// Dynamic Programming and
// Floyed's Algorithm 
// See Anany Levitin << Introduction to the Design and Analysis of Algorithms >>
// Chapter 8.2
#include <cstdio>

int main() {
    
    int    N,    D[51][51];
    
    while( scanf( "%d", &N ) && N ) {
    
        for( int i = 1; i <= N; i++ )
            for( int j = 1; j <= N; j++ )
                if( i == j )    D[i][j] = 0;
                else        D[i][j] = -1;
                
        for( int i = 1; i <= N; i++ ) {
            
            int    T;
            
            for( scanf( "%d", &T ); T--; ) {
                int    p;
                scanf( "%d", &p );
                scanf( "%d", &D[i][p] );
            }
            
        }
        
        for( int k = 1; k <= N; k++ )
            for( int i = 1; i <= N; i++ )
                for( int j = 1; j <= N; j++ )
                    if( D[i][k] != -1 && D[k][j] != -1 )
                    if( D[i][j] == -1 || D[i][k] + D[k][j] < D[i][j] )
                        D[i][j] = D[i][k] + D[k][j];

        int    min = 0x7fffffff,    mini = 0;
        
        for( int i = 1; i <= N; i++ ) {
        
            int    max = 0;
        
            for( int j = 1; j <= N; j++ ) {
        
                if( D[i][j] == -1 ) {
                    max = 0;
                    break;
                }
        
                if( D[i][j] > max )
                    max = D[i][j];
        
            }
        
            if( max && max < min ) {
                min = max;
                mini = i;
            }
        
        }
        
        if( mini )     printf( "%d %d\n", mini, min );
        else        printf( "disjoint\n" );
    
    }
} 
