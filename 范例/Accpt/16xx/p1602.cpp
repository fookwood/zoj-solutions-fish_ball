#include <stdio.h>

int     N , Num [100] , Opt [100] [100];


int     Answer ()
{
        int     i , j , k , l , t;
        for ( i = 0; i + 1 < N; i ++ ) Opt [i] [i + 1] = 0;
                
        for ( l = 2; l < N; l ++ ) {
                for ( i = 0; i + l < N; i ++ ) {
                        j = i + l;
                        Opt [i] [j] = 99999999;
                        for ( k = i + 1; k < j; k ++ ) {
                                t = Opt [i] [k] + Opt [k] [j] + Num [i] * Num [j] * Num [k];
                                if ( t < Opt [i] [j] ) Opt [i] [j] = t;
                        }
                }
        }
        return  Opt [0] [N - 1];
}

main ()
{
        int     i;
        while ( scanf ( "%d" , &N ) != EOF ) {
                for ( i = 0; i < N; i ++ ) scanf ( "%d" , &Num [i] );
                printf ( "%d\n" , Answer () );
        }
}
 