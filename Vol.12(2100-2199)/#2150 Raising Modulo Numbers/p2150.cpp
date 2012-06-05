// 2903488 2008-05-10 12:52:56 Accepted 2150 C++ 00:00.14 440K 呆滞的慢板 

// 直接搞就是了，整数的 pow 要写成 O(logn)的

#include <cstdio>

int     M;

int Pow( const int& x, const int& y ) {
    if( y == 0 )    return  1;
    if( y == 1 )    return  x;
    int     p2 = Pow( x, y / 2 );
    if( y % 2 )     return  ( x * ( ( p2 * p2 ) % M ) ) % M;
    else            return  ( p2 * p2 ) % M;
}


int main() {

    int Z,  N,  x,  y,  ans;
    
    for( scanf( "%d", &Z ); Z--; ) {
        
        ans = 0;
        for( scanf( "%d%d", &M, &N ); N--; ) {
            scanf( "%d%d", &x, &y );
            ans += Pow( x % M, y );
            ans %= M;
        }
        
        printf( "%d\n", ans );
        
    } 
    
}
