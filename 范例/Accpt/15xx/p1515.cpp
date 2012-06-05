#include <stdio.h>

int     N , P;

main ()
{
        int     kind , i;
        while ( scanf ( "%d%d" , &N , &P ) , N || P ) {
                for ( kind = 0 , i = 2; i <= N; i ++ ) kind += ( i - 1 ) * ( N - i + 1 ) * ( N - i + 1 );
                N *= N , printf ( "%.2lf\n" , double ( N ) * ( N - 1 ) * ( N - 2 ) * ( N - 3 ) * P / 2400 / kind );
        }
}
 