#include <stdio.h>
#include <math.h>

int      N;
double   Ans , Tmp , T;

main ()
{
     while ( scanf ( "%d" , &N ) != EOF ) {
           scanf ( "%lf" , &T );
           Ans = 0;
           for ( int i = 0; i < N; i ++ ) {
               scanf ( "%lf" , &Tmp );
               if (  pow ( Tmp , T ) > 0 ) Ans += pow ( Tmp , T );
           }
           printf ( "%.lf\n" , Ans + 1e-8 );
     }
}
