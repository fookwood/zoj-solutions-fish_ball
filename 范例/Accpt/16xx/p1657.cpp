#include <stdio.h>
#include <string.h>

bool    IsPrime [1 << 15];
int     NumberPrime , Prime [3600];

void    CreatePrime ()
{
        memset ( IsPrime , 1 , sizeof ( IsPrime ));
        Prime [0] = Prime [1] = false;
        int     i , j;
        NumberPrime = 0;
        for ( i = 2; i < 1 << 15; i ++ ) if ( IsPrime [i] ) {
                Prime [NumberPrime ++] = i;
                for ( j = i + i; j < 1 << 15; j += i ) IsPrime [j] = false;
        }
}

int     NumberPair ( int N )
{
        int     Ret , i , tmp = N >> 1;
        for ( Ret = 0 , i = 0; Prime [i] <= tmp; i ++ )
                if ( IsPrime [N - Prime [i]] ) Ret ++;
        return  Ret;
}


main ()
{
        int     N;
        CreatePrime ();
        while ( scanf ( "%d" , &N ) , N )
                printf ( "%d\n" , NumberPair ( N ));
}
 