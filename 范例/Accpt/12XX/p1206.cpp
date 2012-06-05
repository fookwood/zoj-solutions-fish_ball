#include <stdio.h>
#include <string.h>

int     N , M;
int     Lasta , Lastb;
int     Money [1000];
int     Opt [10000] [10] [10];
int     Pre [10000] [10] [10];

bool    init ()
{
        if ( scanf ( "%d %d" , &N , &M ) == EOF ) return false;

        int     c , m;
        memset ( Money , 0 , sizeof ( Money ));
        
        for ( ; N ; N -- ) {
                scanf ( "%d %d" , &c , &m );
                Money [c] = m;
        }
        return true;
}

void Dynamic ()
{
        int     k , i , j , t , q , p;
        for ( k = M - 2; k < M; k ++ )
                for ( i = 0; i < 10; i ++ )
                        for ( j = 0; j < 10; j ++ ) {
                                Opt [k] [i] [j] = 0;
                                Pre [k] [i] [j] = -1;
                        }

        for ( k = M - 3; k >= 0; k -- ) {
                for ( i = 0; i < 10; i ++ )
                        for ( j = 0; j < 10; j ++ ) {
                                Opt [k] [i] [j] = -99999999;

                                t = i * 100 + j * 10;
                                for ( p = 0; p < 10; p ++ ) {
                                        q = t + p;
                                        q = Opt [k + 1] [j] [p] + Money [q];

                                        if ( q > Opt [k] [i] [j] ) {
                                                Opt [k] [i] [j] = q;
                                                Pre [k] [i] [j] = p;
                                        }
                                }
                        }
        }

        q = -99999999;
        for ( i = 0; i < 10; i ++ )
                for ( j = 0; j < 10; j ++ )
                        if ( Opt [0] [i] [j] > q ) {
                                q = Opt [0] [i] [j];
                                Lasta = i;
                                Lastb = j;
                        }
}

void    print ()
{
        int     a = Lasta , b = Lastb , t;
        int     i;
        for ( i = 0; i < M - 2; i ++ ) {
                printf ( "%d" , a );
                t = b; b = Pre [i] [a] [b]; a = t;
        }
        printf ( "%d%d" , a , b );
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        while ( init ()) {
                if ( M == 1 ) printf ( "0" );
                else if ( M == 2 ) printf ( "00" );
                else {
                        Dynamic ();
                        print ();
                }
                printf ( "\n" );
        }
}
 