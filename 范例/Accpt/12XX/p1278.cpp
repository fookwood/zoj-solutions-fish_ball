#include <stdio.h>

const   int     max     = 10000;

int     Z , I , M , L;
int     Pos [max];

bool    init ()
{
        scanf ( "%d %d %d %d" , &Z , &I , &M , &L );
        return Z || I || M || L;
}

int     Work ()
{
        int     i;
        for ( i = 0; i < max; i ++ ) Pos [i] = -1;
        i = 0;
        while ( Pos [L] == -1 ) {
                Pos [L] = i;
                i ++;
                L = ( Z * L + I ) % M;
        }
        return i - Pos [L];
}

main ()
{
        int     step = 0;
        while ( 1 ) {
                if ( !init() ) break;
                step ++;
                printf ( "Case %d: %d\n" , step , Work () );
        }
}
 