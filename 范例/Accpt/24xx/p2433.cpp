#include <stdio.h>
#define MAXN      50010
int      N , Num [MAXN];

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         scanf ( "%d" , &N );
         Num [0] = 0;
         for ( int i = 1; i < N; i ++ ) scanf ( "%d" , &Num [i] );
         if ( N <= 3 ) {
              printf ( "0\n" );
              if ( total > 1 ) printf ( "\n" );
              continue;
         }
         int k;
         for ( int i = k = 2; i + 1 < N; i ++ ) 
             if ( Num [i] - Num [i - 1] < Num [k] - Num [k - 1] ) k = i;
         printf ( "%d\n" , Num [N - 1] + Num [k] - Num [k - 1] );
         printf ( "%d %d %d %d\n" , k + 1 , 1 , N , k );
         if ( total > 1 ) printf ( "\n" );
     }
}
