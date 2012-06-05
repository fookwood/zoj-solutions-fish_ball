#include <stdio.h>
#include <math.h>
#define Limit 100000

int     Ansx [Limit + 100] , Ansy [Limit + 100] , Ansz [Limit + 100];

bool    prime ( int a , int b )
{
        return b == 0 ? a == 1 : prime ( b , a % b ); 
}

void    Create ()
{
        int     Tot , x , y , u , v , i , j;

        for ( x = 3 , Tot = 0; Tot <= Limit; x ++ ) if ( x & 1 ) {
                 for ( i = int ( sqrt ( x )); i > 0; i -- ) if ( x % i == 0 ) {
                        j = x / i;
                        u = ( j + i ) >> 1, v = ( j - i ) >> 1;
                        y = 2 * u * v;
                        if ( x < y && prime ( y , x ) ) Ansx [Tot] = x , Ansy [Tot] = y , Ansz [Tot ++] = u * u + v * v;
                 }
        } else {
                i = x / 2;
                for ( v = int ( sqrt ( i )); v > 0; v -- ) if ( i % v == 0 ) {
                        u = i / v;
                        if ( u & 1 == v & 1 ) continue;
                        y = u * u - v * v;
                        if ( x < y && prime ( y , x ) ) Ansx [Tot] = x , Ansy [Tot] = y , Ansz [Tot ++] = u * u + v * v;
                }
        }
}

main ()
{
        Create ();
        int     N;
        while ( scanf ( "%d" , &N ) != EOF )
                N -- , printf ( "%d %d %d\n" , Ansx [N] , Ansy [N] , Ansz [N] );
}
 