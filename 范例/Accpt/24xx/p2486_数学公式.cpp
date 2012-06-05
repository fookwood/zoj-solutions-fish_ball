#include <stdio.h>
#include <math.h>

int      N;
double   p;

main ()
{
     while ( scanf ( "%d%lf" , &N , &p ) != EOF ) {
           printf ( "%.lf\n" , exp ( log ( p ) / N ) + 1e-8 );
     }
}
