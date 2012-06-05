#include <stdio.h>

int     N , M;
int     x [100] , y [100] , Opt [100] [100];

int     Dp ()
{
        int     i , j , k1 , k2 , tmp;
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < M; j ++ ) {
                        Opt [i] [j] = 0;

                        if ( i && Opt [i - 1] [j] > Opt [i] [j] ) Opt [i] [j] = Opt [i - 1] [j];
                        if ( j && Opt [i] [j - 1] > Opt [i] [j] ) Opt [i] [j] = Opt [i ] [j - 1];

                        if ( x [i] == y [j] ) continue;
                        for ( k1 = i - 1; k1 >= 0 && x [k1] != y [j]; k1 -- );
                        for ( k2 = j - 1; k2 >= 0 && y [k2] != x [i]; k2 -- );
                        if ( k1 > 0 && k2 > 0 ) tmp = Opt [k1 - 1] [k2 - 1]; else tmp = 0;
                        if ( k1 >= 0 && k2 >= 0 && tmp + 2 > Opt [i] [j] )
                                Opt [i] [j] = tmp + 2;
                }
        int     ret = 0;
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < M; j ++ )
                        if ( Opt [i] [j] > ret )
                                ret = Opt [i] [j];
        return ret;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total , p;
        int     i;
        for ( scanf ( "%d" , &total ) , p = 0; p < total; p ++ ) {
                scanf ( "%d%d" , &N , &M );
                for ( i = 0; i < N; i ++ ) scanf ( "%d" , &x [i] );
                for ( i = 0; i < M; i ++ ) scanf ( "%d" , &y [i] );

                printf ( "%d\n" , Dp () );                
        }
}
 