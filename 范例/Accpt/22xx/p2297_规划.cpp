#include <stdio.h>
#include <string.h>
#define  MAXN     20

int      N , Cut [MAXN] , Add [MAXN] , Opt [1 << 19] , Pow2 [MAXN] , Boss;

main ()
{
     for ( int i = 0; i < MAXN; i ++ ) Pow2 [i] = 1 << i;
     while ( scanf ( "%d" , &N ) != EOF ) {
           N --;
           for ( int i = 0; i < N; i ++ ) scanf ( "%d%d" , &Cut [i] , &Add [i]);
           scanf ( "%d" , &Boss );
           Opt [0] = 100;
           int Tot = 1 << N , t;
           for ( int i = 1; i < Tot; i ++ ) {
               Opt [i] = -1;
               for ( int j = 0; j < N; j ++ ) if ( i & Pow2 [j] ) {
                   t = Opt [i ^ Pow2 [j]];
                   if ( t < Cut [j] ) continue;
                   t += Add [j] - Cut [j];
                   if ( t > Opt [i] ) Opt [i] = t;
               }
               if ( Opt [i] > 100 ) Opt [i] = 100;
           }
           if ( Opt [Tot - 1] >= Boss ) printf ( "clear!!!\n" );
           else printf ( "try again\n" );
     }
}
