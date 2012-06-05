#include <stdio.h>

int      N;

int      phi ( int N )
{
         int i , j;
         int Ret = N;
         for ( i = 2 , j = 4; j <= N; j += i + i + 1 , i ++ ) if ( N % i == 0 )
             for ( Ret = Ret / i * ( i - 1 ); N % i == 0; N /= i );
         if ( N > 1 ) Ret = Ret / N * ( N - 1 );
         return Ret;
}

main ()
{
     while ( scanf ( "%d" , &N ) , N )
           printf ( "%d\n" , phi ( N ));
}
