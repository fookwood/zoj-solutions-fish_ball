#include <stdio.h>
#include <string.h>

unsigned int    f [232] [232];

void    Prepare ()
{
       /* f [i] [j] = 1    { j > i / 2 && j <= i }
                    f [i] [j + 1] + f [i - j * 2] [j] { j <= i / 2 && j > 0 }
       */

        int     i , j;
        memset ( f , 0 , sizeof ( f ) );

        for ( i = 0; i < 232; i ++ )
                for ( j = i / 2 + 1; j <= i; j ++ ) f [i] [j] = 1;
        for ( i = 0; i < 232; i ++ ) f [0] [i] = 1;

        for ( i = 1; i < 232; i ++ )
                for ( j = i / 2; j > 0; j -- )
                        f [i] [j] = f [i] [j + 1] + f [i - j * 2] [j];                        
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        Prepare ();
        int     N;
        while ( scanf ( "%d" , &N ) , N )
                printf ( "%u %u\n" , N , f [N] [1] );
}
 