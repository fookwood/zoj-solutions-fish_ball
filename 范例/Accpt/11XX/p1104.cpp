#include <stdio.h>
#include <math.h>

int     n;
double  x [100] , y [100];

void    init ()
{
        int     i;
        for ( i = 0; i < n; i ++ ) {
                scanf ( "%lf %lf" , &y [i] , &x [i] );
                if ( i ) x [i] += x [i - 1];
        }
}

void    Work ()
{
        double  Ta , mina;
        double  slop;
        double  t;
        
        int     i;
        mina    = 1e10;
        
        for ( i = 1; i < n; i ++ ) {
                Ta = y [i] / x [i - 1] / ( x [i - 1] - x [n - 1] );
                if ( Ta < mina ) mina = Ta;
                if ( i == n - 1 ) continue;
                Ta = y [i] / x [i] / ( x [i] - x [n - 1] );
                if ( Ta < mina ) mina = Ta;
        }
        slop = - mina * x [n - 1];

        t = sqrt ( - ( 1 + slop * slop ) * 9.8 / mina / 2 );

        printf ( "%.2lf " , atan ( slop ) * 180 / 3.1415926 );
        printf ( "%.2lf\n" , t );
}

main ()
{
        while ( scanf ( "%d" , &n ) != EOF ) {
                init ();
                Work ();
        }
}
 