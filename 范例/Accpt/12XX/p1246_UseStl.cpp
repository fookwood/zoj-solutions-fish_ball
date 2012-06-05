#include <stdio.h>
#include <string.h>

char    data [255];
char    seps [] = " \n";
int     Num [11];

char    *Word ( char *d )
{
        char    *p;
        p = strtok ( d , seps );
        if ( p == NULL ) {
                scanf ( "%s" , data );
                p = Word ( data );
        }
        return p;
}

int     ChangeToInt ( char *p )
{
        int     i , len = strlen ( p );
        int     ret = 0;
        for ( i = 0; i < len; i ++ )
                ret = ret * 10 + *( p + i ) - '0';
        return ret;
}

void    Search ( int dep , int St , int Pow )
{
        char    *p;
        int     t;
        
        for ( p = Word ( NULL ); strcmp ( p , "END" ) != 0; p = Word ( NULL ) ) {
                if ( strcmp ( p , "LOOP" ) == 0 ) {
                        p = Word ( NULL );
                        if ( strcmp ( p , "n" ) == 0 ) {
                                Search ( dep + 1 , St + 1 , Pow );
                        } else {
                                Search ( dep + 1 , St , Pow * ChangeToInt ( p ));
                        }
                } else {
                        p = Word ( NULL );
                        t = ChangeToInt ( p );
                        Num [St] += Pow * t;
                }
        }
}

void    Work ()
{
        data [0] = 0;
        memset ( Num , 0 , sizeof ( Num ));

        Word ( data );
        Search ( 0 , 0 , 1 );

        int     i , j , first = 1;
        printf ( "Runtime = " );
        for ( i = 15; i && ! Num [i] ; i -- );
        for ( j = i; j >= 1; j -- ) if ( Num [j] ) {
                if ( !first ) printf ( "+" );
                if ( Num [j] != 1 ) printf ( "%d*n" , Num [j] ); else printf ( "n" );
                if ( j > 1 ) printf ( "^%d" , j );
                first = false;
        }
        if ( first ) printf ( "%d" , Num [0] ); else
        if ( Num [0] ) printf ( "+%d" , Num [0] ); 
        printf ( "\n" );
}

main ()
{
        int     step , total;
        scanf ( "%d" , &total );
        for ( step = 1; step <= total; step ++ ) {
                printf ( "Program #%d\n" , step );
                Work ();
                printf ( "\n" );
        }
}
