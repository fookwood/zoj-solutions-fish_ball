#include <stdio.h>

int     num [6];

bool    init ()
{
        int     i , s;
        for ( s = i = 0; i < 6; i ++ ) {
                scanf ( "%d" , &num [i] );
                s += num [i];
        }
        return ( s > 0 );
}

int     Ans ()
{
        int     ret = 0 , t;
        ret += num [5];                                 // Long == 6
        ret += num [4]; num [0] -= num [4] * 11;        // Long == 5
        ret += num [3]; num [1] -= num [3] * 5;         // Long == 4

        if ( num [2] > 0 ) {
                ret += ( num [2] - 1 ) / 4 + 1; t = num [2] % 4;
                        if ( t == 1 ) { num [1] -= 5; num [0] -= 7; } else
                        if ( t == 2 ) { num [1] -= 3; num [0] -= 6; } else
                        if ( t == 3 ) { num [1] -= 1; num [0] -= 5; };
        }                                               // Long == 3
        
        if ( num [1] > 0 ) { ret += ( num [1] - 1 ) / 9 + 1; num [0] -= ( 9 - num [1] % 9 ) % 9  * 4; }
        if ( num [1] < 0 ) { num [0] += num [1] * 4; };
                                                        // Long == 2
        if ( num [0] > 0 ) ret += ( num [0] - 1 ) / 36 + 1;
                                                        // Long == 1
        return ret;
}

main ()
{
      
        while ( init () ) {
                printf ( "%d\n" , Ans () );
        }
}
 