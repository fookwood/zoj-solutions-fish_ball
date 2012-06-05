#include <stdio.h>
#include <math.h>

main ()
{
     int N;
     while ( scanf ( "%d" , &N ) != EOF ) {
           double t = N * log10 ( N );
           t = t - int ( t );
           t = exp ( t * log ( 10 ));
           printf ( "%d\n" , int ( t ));
     }
}
