#include <stdio.h>
#include <math.h>

int     w , d;
double  Ans;

int     Answer ( double a , double b )
{
        double  t , d;
        t = a / b;
        d = t - int ( t );
        t = int ( t );
        if ( d > 0.5 ) t ++;
        return int ( t * b );
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        int     step = 0;
        while ( 1 ) {
                scanf ( "%d %d" , &w , &d );
                if ( w == 0 && d == 0 ) break;
                step ++;
                printf ( "Sample #%d\n" , step );
                Ans = 5730 * log ( double ( d ) / w / 810 ) / log ( 0.5 );
                if ( Ans > 10000 ) {
                        printf ( "The approximate age is %d years.\n" , Answer ( Ans , 1000 ));

                } else {

                        printf ( "The approximate age is %d years.\n" , Answer ( Ans , 100 ) );

                }
                printf ( "\n" );
        }
}
 