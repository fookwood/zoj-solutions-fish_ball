#include <stdio.h>

double   Ans , V , T;

main ()
{
     int N;
     while ( scanf ( "%d" , &N ) , N ) {
           Ans = 1e30;
           for ( int i = 0; i < N; i ++ ) {
               scanf ( "%lf%lf" , &V , &T );
               if ( T < 0 ) continue;
               if ( 4.5 * 3600 / V + T < Ans )
                  Ans = 4.5 * 3600 / V + T;
           }
           printf ( "%d\n" , int ( Ans + 0.999 ));
     }
}
