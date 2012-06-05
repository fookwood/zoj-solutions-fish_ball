#include <stdio.h>
#include <string.h>

const   int     maxN = 10;
const   int     maxT = 1000;

int     N , T;
int     Opt [maxT] [maxN];

int     Len [maxN - 1] [maxN];
int     Flight [maxN - 1] [maxN] [30];

bool    init ()
{
        scanf ( "%d %d" , &N , &T );
        if ( !N ) return 0;
        
        int     i , j;
        int     k;
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < N; j ++ ) {
                        if ( i == j ) continue;
                        scanf ( "%d" , &Len [i] [j] );
                        for ( k = 0; k < Len [i] [j]; k ++ )
                                scanf ( "%d" , &Flight [i] [j] [k] ); 
                }
        return 1;
}

int     cost ( int a , int b , int time )
{
        if ( a == b ) return 0;
        if ( !Len [a] [b] ) return 0;
        return Flight [a] [b] [time % Len [a] [b]];        
}

void    Danymic ()
{
        int     i , j , t , k;
        int     notzero;

        memset ( Opt , 0 , sizeof ( Opt ));

        for ( i = 0; i < N; i ++ ) {
                t = cost ( 0 , i , 0 );
                if ( t ) Opt [0] [i] = t;
                else Opt [0] [i] = 0;
        }


        for ( k = 0; k + 1 < T; k ++ ) {
                notzero = 1;
                for ( i = 0; i < N; i ++ ) if ( Opt [k] [i] ) {
                        notzero = 0;
                        for ( j = 0; j < N; j ++ ) {
                                t = cost ( i , j , k + 1 );
                                if ( !t ) continue;
                                if ( !Opt [k + 1] [j] || Opt [k] [i] + t < Opt [k + 1] [j] )
                                        Opt [k + 1] [j] = Opt [k] [i] + t;
                        }
                }
                if ( notzero ) break;
        }
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        int     step = 0;
        while ( init ()) {
                step ++;
                printf ( "Scenario #%d\n" , step );
                Danymic ();
                if ( Opt [T - 1] [N - 1] )printf ( "The best flight costs %d.\n" , Opt [T - 1] [N - 1] );
                        else printf ( "No flight possible.\n" );
                printf ( "\n" );
        }
}
 