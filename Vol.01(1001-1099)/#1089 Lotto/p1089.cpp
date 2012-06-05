// 2927984 2008-05-21 21:30:27 Accepted 1089 C++ 00:00.00 388K 呆滞的慢板 

// 直接枚举 
// Rewritten on 2008-5-21

#include <cstdio>

int main() {
    
    int     K,  T = 0,  A[13];
    int     a,  b,  c,  d,  e,  f;
    
    while( scanf( "%d", &K ) && K ) {
    
        if( T++ )   putchar( '\n' );
    
        for( a = 0; a < K; ++a )
            scanf( "%d", A + a );
            
        for( a = 0;     a < K; ++a )
        for( b = a + 1; b < K; ++b )
        for( c = b + 1; c < K; ++c )
        for( d = c + 1; d < K; ++d )
        for( e = d + 1; e < K; ++e )
        for( f = e + 1; f < K; ++f )
            printf( "%d %d %d %d %d %d\n",
                A[a], A[b], A[c], A[d], A[e], A[f] );
    
    }
    
}
