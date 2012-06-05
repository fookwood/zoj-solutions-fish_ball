// DP, Floyd's Algorithm
// 0.05 400K AC

#include <cstring>
#include <cstdio> 

int main() {
    
    int    V,    E,    T = 1;
    
    char    A[30][100],    s1[100],    s2[100];
    
    float    x,    loop,    D[30][30];
    
    int    top,    stk[30];
    
    while( scanf( "%d", &V ) && V ) {
        
        for( int i = 0; i < V; i++ ) {
            
            scanf( "%s", A[i] );
            
            for( int j = 0; j < V; j++ )
                D[i][j] = 0.; 
                
        }
        
        scanf( "%d", &E );
        
        for( int i = 0; i < E; i++ ) {
            
            scanf( "%s%f%s", s1, &x, s2 );
            
            int    j = -1,    k = -1;
            
            while( 1 ) if( !strcmp( A[++j], s1 ) ) break;
            while( 1 ) if( !strcmp( A[++k], s2 ) ) break;
            
            D[j][k] = x; 
        }
        
        for( int k = 0; k < V; k++ )
            for( int i = 0; i < V; i++ )
                for( int j = 0; j < V; j++ )
                    if( D[i][k] * D[k][j] > D[i][j] )
                        D[i][j] = D[i][k] * D[k][j];
                        
        bool    yes = 0;
        
        for( int k = 0; k < V; k++ ) {
            
            if( D[k][k] > 1. ) {
            
                yes = 1;
                break;
            
            }
        }
        
        printf( "Case %d", T++ ); 
        
        puts( yes ? ": Yes" : ": No" ); 
    }
} 

