#include <stdio.h>
#include <string.h>

int     N , Smallest;
int     len [100];
bool    Kuo [100];
char    data [100] [101];

void    init ()
{
        int     i;
        
        Smallest = 0;
        scanf ( "%d" , &N );
        for ( i = 0; i < N; i ++ ) {
                scanf ( "%s" , data [i] );
                len [i] = strlen ( data [i] );
                if ( len [i] < len [Smallest] ) Smallest = i;
        }
}

int     Ans ()
{
        char    temp [100] , temp2 [100];

        bool    Have;
        int     i , j , k , Limit = len [Smallest] , t , pass;
        for ( i = 0; i < Limit; i ++ ) Kuo [i] = 1;

        for ( k = 0; k < Limit; k ++ ) {
                Have = 0;
                
                for ( i = 0 , j = k; j < Limit; i ++ , j = i + k ) if ( Kuo [i] ) {
                        strcpy ( temp , data [Smallest] + i ); temp [k + 1] = 0;
                        for ( t = 0; t < k + 1; t ++ ) temp2 [t] = temp [k - t]; temp2 [k + 1] = 0;

                        pass = 1;
                        for ( t = 0; t < N; t ++ ) if ( t != Smallest ) {
                                if ( strstr ( data [t] , temp ) != NULL ) continue;
                                if ( strstr ( data [t] , temp2 ) != NULL ) continue;
                                pass = 0; break;
                        }
                        if ( !pass ) Kuo [i] = 0; else Have = 1;
                }
                if ( !Have ) break;
        }
        return k;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total;
        for ( scanf ( "%d" , &total ) ; total; total -- ) {
                init ();
                printf ( "%d\n" , Ans () );
        }
}
 