#include <stdio.h>

int     N , InCome , GoOut , Pay , max;
int     Month [13];
int     Opt [13] [1001];

int     Dp ()
{
        int     i , j , k , t;
        for ( i = 1; i <= max; i ++ ) Opt [0] [i] = 99999;
        Opt [0] [0] = 0;

        for ( i = 1; i <= N; i ++ ) {
                for ( j = 0; j <= max; j ++ ) {
                        Opt [i] [j] = 9999999;
                        if ( j < Month [i] ) continue;
                        for ( k = 0; k <=j; k ++ ) {
                                t = Opt [i - 1] [k] + InCome * ( j - k );
                                if ( t < Opt [i] [j] ) Opt [i] [j] = t;
                        }
                        for ( k = j + 1; k <= max; k ++ ) {
                                t = Opt [i - 1] [k] + GoOut * ( k - j );
                                if ( t < Opt [i] [j] ) Opt [i] [j] = t;
                        }
                        Opt [i] [j] += j * Pay;
                }
        }
        int ret = 9999999;
        for ( i = 0; i <= max; i ++ )
                if ( Opt [N] [i] < ret )
                        ret = Opt [N] [i];
        return ret;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     i;
        while ( scanf ( "%d" , &N ) , N ) {
                scanf ( "%d %d%d" , &InCome , &Pay , &GoOut );
                for ( max = 0 , i = 1; i <= N; i ++ ) {
                        scanf ( "%d" , &Month [i] );
                        if ( Month [i] > max ) max = Month [i];
                }
                printf ( "%d\n" , Dp () );
        }
}
 