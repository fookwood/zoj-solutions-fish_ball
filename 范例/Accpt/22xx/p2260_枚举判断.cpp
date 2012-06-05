#include <stdio.h>
#include <algorithm>

bool     Change;
int      A , B , C , x , y , z;

void     Work ( int a , int b , int c )
{
         x = 0x0fffffff , y = 0x0fffffff;
         int  p1 = a - b , tx , ty , t , p2 = a + b , p3;
         bool find = false;
         for ( t = 0; !find ; t ++ ) {
             if ( ( c + t * a ) % p2 == 0 ) {
                  ty = ( c + t * a ) / ( a + b );
                  tx = t - ty;
                  if ( tx >= 0 )
                     x = tx , y = ty , find = true;
             }
             
             if ( p3 = a * t - c , p3 < 0 ) continue;
             
             if ( p3 % p1 == 0 ) {
                  ty = p3 / p1 , tx = t - ty;
                  if ( tx >= 0 )
                       if ( tx + ty < x + y || tx + ty == x + y && tx * A + ty * B < x * A + y * B )
                          x = tx , y = ty , find = true;
             }
             if ( p3 % p2 == 0 ) {
                  ty = p3 / p2 , tx = t - ty;
                  if ( tx >= 0 )
                       if ( tx + ty < x + y || tx + ty == x + y && tx * A + ty * B < x * A + y * B )
                          x = tx , y = ty , find = true;
             }
         }
}

main ()
{
     while ( scanf ( "%d%d%d" , &A , &B , &C ) , A || B || C ) {
           Change = ( A < B );
           if ( A < B ) std::swap ( A , B );
           Work ( A , B , C );
           if ( !Change ) printf ( "%d %d\n" , abs ( x ) , abs ( y ));
           else printf ( "%d %d\n" , abs ( y ) , abs ( x ));
     }
}
