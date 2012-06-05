#include <stdio.h>
#include <string.h>

int     N;
char    Answer [100] [61];
int     len [100];
char    data [100] [61] , temp [61];

void    sort ()
{
        int     i , j , wide , many , t;
        int     maxlen;

        for ( maxlen = 0 , i = 0; i < N; i ++ ) {
                len [i] = strlen ( data [i] );
                if ( len [i] > maxlen ) maxlen = len [i];
        }
        
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < N; j ++ )
                        if ( strncmp ( data [i] , data [j] , 60 ) < 0 ) {
                                strncpy ( temp , data [i] , 60 );
                                strncpy ( data [i] , data [j] , 60 );
                                strncpy ( data [j] , temp , 60 );
                                t = len [i]; len [i] = len [j]; len [j] = t;
                        }

        maxlen += 2; wide = 62 / maxlen; many = ( N - 1 ) / wide + 1;

        memset ( Answer , ' ' , sizeof ( Answer ) );

        t = 0;
        for ( j = 0; j < wide; j ++ ) {
                for ( i = 0; i < many; i ++ ) if ( t < N ) {
                        memcpy ( Answer [i] + j * maxlen , data [t] , len [t] );
                        t ++;
                }
        }
        printf ( "------------------------------------------------------------\n" );

        for ( i = 0; i < many; i ++ ) {
                for ( j = 59; Answer [i] [j] == ' '; j -- );
                Answer [i] [j + 1] = 0;
                printf ( "%s\n" , Answer [i] );
        }
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     i;
        while ( scanf ( "%d" , &N ) != EOF ) {
                for ( i = 0; i < N; i ++ ) scanf ( "%s" , data [i] );
                sort ();
        }
}
 