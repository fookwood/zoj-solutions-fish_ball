// zju 1403 Search

#include <stdio.h>
#include <string.h>

int     Target;
bool    Have [27];
int     Num [27] [5];
char    Data [30];
int     Ans [5] , Stack [5];


void    Prepare ()
{
        int     i , j;
        for ( i = 1; i < 27; i ++ ) Num [i] [0] = i;
        for ( i = 1; i < 5; i ++ )
                for ( j = 1; j < 27; j ++ )
                        Num [j] [i] = Num [j] [i - 1] * j;
}

bool    Search ( int depth , int get )
{
        int     i , Next;

        if ( depth == 5 ) {
                if ( get == Target ) {
                        for ( i = 0; i < 5; i ++ )
                                Ans [i] = Stack [i];
                        return true;
                }
                return false;
        }

        for ( i = 26; i; i -- ) if ( Have [i] ) {
                Have [i] = 0;
                Stack [depth] = i;
                if ( depth % 2 ) Next = get - Num [i] [depth];
                        else Next = get + Num [i] [depth];
                if ( Search ( depth + 1 , Next ) ) return true;
                Have [i] = 1;
        }
        return false;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     i , len;
        Prepare ();
        while ( scanf ( "%d" , & Target ) , Target ) {
                scanf ( "%s" , Data );
                len = strlen ( Data );
                memset ( Have , 0 , sizeof ( Have ) );
                for ( i = 0; i < len; i ++ ) Have [Data [i] - 'A' + 1] = 1;
                if ( Search ( 0 , 0 ) )
                        for ( i = 0; i < 5; i ++ ) printf ( "%c" , Ans [i] + 'A' - 1 );
                                else printf ( "no solution" );
                        printf ( "\n" );
        }
}
 