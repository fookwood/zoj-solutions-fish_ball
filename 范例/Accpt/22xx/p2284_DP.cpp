#include <stdio.h>

long long  Opt [20] [201];

main ()
{
     for ( int i = 0; i < 20; i ++ ) Opt [i] [0] = 1;
     for ( int i = 1; i < 20; i ++ )
         for ( int j = 1; j < 201; j ++ ) {
             Opt [i] [j] = 0;
             for ( int k = 0; k <= j && k <= i; k ++ ) Opt [i] [j] += Opt [i - 1] [j - k];
         }
     int     N , K;
     while ( scanf ( "%d%d" , &N , &K ) , N || K  ) 
           printf ( "%lld\n" , Opt [N - 1] [K] );
}
