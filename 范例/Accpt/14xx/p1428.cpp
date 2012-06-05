#include <stdio.h>

int     N;
int     Opt [30] [30] [30] , cost [30] [30];

void    init ()
{
        scanf ( "%d" , &N );
        int     i , j;
        for ( i = 0;i < N; i ++ )
                for ( j = i + 1; j < N; j ++ )
                        scanf ( "%d" , &cost [i] [j] );
}

int     Dp ()
{
        if ( N == 0 ) return 0;
        if ( N == 1 ) return cost [0] [1];

        int     i , j , k , t;
        
        for ( i = 0; i < N; i ++ ) 
                for ( j = 0; j <= i; j ++ )
                        for ( k = 0; k <= j; k ++ )
                                Opt [i] [j] [k] = 99999999;

        Opt [0] [0] [0] = 0;

        for ( k = 0; k + 1 < N; k ++ ) {
                for ( i = 0; i <= k; i ++ )
                        for ( j = 0; j <= i; j ++ ) {
                                t = Opt [k] [i] [j] + cost [k] [k + 1];
                                if ( t < Opt [k + 1] [i] [j] ) Opt [k + 1] [i] [j] = t;
                                t = Opt [k] [i] [j] + cost [i] [k + 1];
                                if ( t < Opt [k + 1] [k] [j] ) Opt [k + 1] [k] [j] = t;
                                t = Opt [k] [i] [j] + cost [j] [k + 1];
                                if ( t < Opt [k + 1] [k] [i] ) Opt [k + 1] [k] [i] = t;
                        }
        }

        t = 999999999;
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j <= i; j ++ )
                        if ( Opt [N - 1] [i] [j] < t )
                                t = Opt [N - 1] [i] [j];
        return t;        
}

main ()
{
        freopen ( "p.in" , "r" ,stdin );
        freopen ( "p.out" , "w" , stdout );
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                printf ( "%d\n" , Dp () );
        }
}
 