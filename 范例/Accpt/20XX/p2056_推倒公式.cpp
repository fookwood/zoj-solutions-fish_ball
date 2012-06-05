#include <stdio.h>
#include <math.h>

int      N;
double   High;

double   Ans ()
{
         int T = int (( 1 + sqrt ( 1 + 4 * High ) ) / 2 + 1e-10 );
         if ( T + 1 >= N ) return 0;
         double Last = ( High - (double) T * ( T - 1 ) ) / T;
         return (double) ( N - T - 1 ) * ( N - T - Last );
}

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         scanf ( "%d%lf" , &N , &High );
         printf ( "%.2lf\n" , Ans () );
         if ( total > 1 ) printf ( "\n" );
     }
}
