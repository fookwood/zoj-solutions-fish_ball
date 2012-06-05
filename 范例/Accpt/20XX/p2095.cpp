#include <stdio.h>
#include <math.h>

const   int     maxn    = 500001;

int     small [maxn];
int     Total [maxn];
int     part;
int     n;

void    prepare ()
{
        int     i , j;
        int     t;
        for ( i = 2; i < maxn; i ++ ) small [i] = 0;
        for ( i = 2; i < maxn; i ++ ) Total [i] = 0;

        for ( i = 2; i < maxn; i ++ ) if ( !small [i] ) {
                Total [i] = i + 1;
                for ( j = 1; j <= ( maxn - 1 ) / i; j ++ )
                        small [i * j] = i;
                }
        Total [1] = 1;
        for ( i = 2; i < maxn; i ++ ) if ( !Total [i] ) {
                t = i / small [i];
                while ( t%small [i] == 0 ) t /= small [i];
                if ( t == 1 ) Total [i] = ( i * small [i] - 1 ) / (small [i] - 1 );
                else Total [i] = Total [i / t] * Total [t];
        }
}

main ()
{
        prepare ();
        scanf ( "%d" , &part );
        for ( ; part ; part -- ) {
                scanf ( "%d" , &n );
                printf ( "%d\n" , Total [n] - n );
        }
}
 