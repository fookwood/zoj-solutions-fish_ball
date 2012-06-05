#include <stdio.h>

long long        Ans;
unsigned int        N , M , i;

main ()
{
 while ( scanf ( "%u%u" , &N , &M ) , N || M ) {
       N += M;
       if ( N - M < M ) M = N - M;
       
       for ( Ans = 1 , i = 1; i <= M; i ++ ) Ans = Ans * ( N - M + i ) / i;
       
       printf ( "%lld\n" , Ans );
 }
}
