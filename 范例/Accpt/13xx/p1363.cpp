#include <stdio.h>
#include <math.h>

int     C , N , M;
float   Opt [2] [102];

float   Ans ()
{
        if ( ( N - M ) % 2 == 1 || M > C ) return 0;

        int     a = 0 , b = 1 , k , i , change;
        float   t;

        for ( i = 1; i <= C + 1; i ++ ) { Opt [a] [i] = Opt [b] [i] = 0; }
        Opt [a] [0] = 1; Opt [b] [C + 1] = Opt [b] [0] = Opt [b] [C + 1] = 0;

        for ( k = 0; k < N; k ++ , a = 1 - a , b = 1 - b ) {  change = 0;
                Opt [b] [0] = Opt [a] [1] / C;
                for ( i = 1; i <= C; i ++ ) {
                        t = ( ( C - i + 1 ) * Opt [a] [i - 1] + ( i + 1 ) * Opt [a] [i + 1] ) / C;
                        if ( fabs ( t - Opt [b] [i] ) > 0.00005 ) change = 1;
                        Opt [b] [i] = t;
                }
                if ( k % 2 == M % 2 && !change ) break;
        }
        
        return Opt [a] [M];
}

main ()
{
        while ( scanf ( "%d" , &C ) , C ) {
                scanf ( "%d%d" , &N , &M );
                printf ( "%.3f\n" , Ans () ); 
        }
}
 