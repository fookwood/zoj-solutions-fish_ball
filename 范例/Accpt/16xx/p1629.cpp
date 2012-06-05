#include <stdio.h>

int     N;

int     f ( int N )
{
        int     Ret = 0 , i;
        for ( i = 1; i <= N; i ++ ) Ret += ( 1 + i ) * i / 2;
        for ( i = 1; i + i <= N; i ++ ) Ret += ( N - i - i + 2 ) * ( N - i - i + 1 ) / 2;
        return  Ret;
}

main ()
{
        while ( scanf ( "%d" , &N ) != EOF )
                printf ( "%d\n" , f ( N ));
}
 