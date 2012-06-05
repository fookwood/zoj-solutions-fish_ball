// zju 1439 
#include <stdio.h>
#include <math.h>

int     x1 , x2 , x3 , y11 , y2 , y3 , z1 , z2 , z3;
double  a , b , c , p , s , q;

double  dis ( int x1 , int y1 , int z1 , int x2 , int y2 , int z2 )
{
        return sqrt ( double( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) + ( z1 - z2 ) * ( z1 - z2 ));
}

main ()
{
        while ( scanf ( "%d%d%d%d%d%d%d%d%d" , &x1 , &y11 , &z1 , &x2 , &y2 , &z2 , &x3 , &y3 , &z3 ) != EOF ) {
                a = dis ( x1 , y11 , z1 , x2 , y2 , z2 );
                b = dis ( x2 , y2 , z2 , x3 , y3 , z3 );
                c = dis ( x3 , y3 , z3 , x1 , y11 , z1 );
                p = ( a + b + c ) / 2;
                s = sqrt ( p * ( p - a ) * ( p - b ) * ( p - c ));
                q = 4 * s * s / p / a / b /c;
                printf ( "%.3f\n" , q * q );
        }
}
 