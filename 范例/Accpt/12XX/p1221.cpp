#include <stdio.h>
#include <string.h>

const   int     n = 20;

int     graph [20] [20];

int     Long [20] [20];

bool    init ()
{
        int     i , j;
        int     total , b;
        memset ( graph , 0 , sizeof ( graph ));
        memset ( Long , 0xff , sizeof ( Long ));
        for ( i = 0; i < n - 1; i ++ ) {
                if ( scanf ( "%d" , &total ) == EOF ) return false;
                for ( j = 0; j < total; j ++ ) {
                        scanf ( "%d" , &b );
                        graph [i] [b - 1] = graph [b - 1] [i] = 1;
                }
        }
        return true;
}

void    Floyd ()
{
        int     i , j , k , t;
        for ( i = 0; i < n; i ++ ) Long [i] [i] = 0;
        for ( i = 0; i < n; i ++ )
                for ( j = i + 1; j < n; j ++ ) if ( graph [i] [j] )
                        Long [i] [j] = Long [j] [i] = 1;
        for ( k = 0; k < n; k ++ )
                for ( i = 0; i < n; i ++ )
                        for ( j = 0; j < n; j ++ ) {
                                if ( Long [i] [k] == -1 || Long [k] [j] == -1 )
                                        continue;
                                t = Long [i] [k] + Long [k] [j];
                                if ( Long [i] [j] == -1 || Long [i] [j] > t )
                                        Long [i] [j] = t;
                        }
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     step = 0;
        int     totalask , a , b;
        while ( init ()) {
                step ++;
                Floyd ();
                printf ( "Test Set #%d\n" , step );
                scanf ( "%d" , &totalask );
                while ( totalask ) {
                        scanf ( "%d %d" , &a , &b );
                        printf ( "%d to %d: %d\n" , a , b , Long [a - 1] [b - 1] );
                        totalask --;
                }
                printf ( "\n" );
        }
}
 