#include <stdio.h>
#include <string.h>

int     degreein [26] , degreeout [26];
bool    Line [26] [26] , Save [26] , Total;

void    init ()
{
        char    s [1010] , a , b;
        int     N , i;
        scanf ( "%d" , &N );
        memset ( Line , 0 , sizeof ( Line ));
        memset ( Save , 0 , sizeof ( Save ));
        for ( i = 0; i < 26; i ++ ) degreein [i] = degreeout [i] = 0;
        for ( Total = i = 0; i < N; i ++ ) {
                scanf ( "%s" , s );
                a = s [0] - 'a'; b = s [strlen ( s ) - 1] - 'a';
                Save [a] = Save [b] = true;
                degreein [a] ++ , degreeout [b] ++;
                Line [a] [b] = true;
                Total ++;
        }
}

void    Search ( int p )
{
        Save [p] = false;
        for ( int i = 0; i < 26; i ++ ) if ( Save [i] && Line [p] [i] )
                Search ( i );
}

bool    check ()
{
        int     tot , i , j , k , Start;
        Start = -1;
        for ( i = tot = 0; i < 26; i ++ ) {
                if ( degreein [i] - degreeout [i] > 1 || degreeout [i] - degreein [i] > 1 )
                        return false;
                if ( ( degreein [i] + degreeout [i] ) % 2 ) {
                        tot ++;
                        if ( degreein [i] > degreeout [i] && Start == -1 ) Start = i;
                }
        }
        if  ( tot > 2 ) return false;

        if ( Start == -1 ) for ( i = 0; i < 26; i++ ) if ( Save [i] && Start == -1 ) Start = i;

        Search ( Start );

        for ( i = 0; i < 26; i ++ ) if ( Save [i] ) return false;
        return true;
}

main ()
{                   
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                if ( check () ) printf ( "Ordering is possible.\n" );
                        else printf ( "The door cannot be opened.\n" );
        }
}
 