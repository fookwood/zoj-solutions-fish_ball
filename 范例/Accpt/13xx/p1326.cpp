#include <stdio.h>
#include <string.h>


int     N , K;
bool    Left [50];
int     len;
int     Card [20];

bool    init ()
{
        if ( scanf ( "%d" , &N ) == EOF ) return false;
        scanf ( "%d" , & K );
        int     i;
        for ( i = 0;i < 20; i ++ ) scanf ( "%d" , &Card [i] );
        memset ( Left , 0 , sizeof ( Left ) );
        return true;
}

void    Work ()
{
        int     i , j , k , s;

        s = 0;
        for ( k = 0; k < 20; k ++ ) {
                for ( i = 0; i < N && Left [i]; i ++ );
                
                while ( i < N ) {
                        for ( j = 0; j + 1 < Card [k]; j ++ ) {
                                i ++;
                                for ( ; i < N && Left [i]; i ++ );
                                if ( i == N ) break;
                        }
                        
                        if ( i < N ) {
                                Left [i] = 1; s ++;
                                if ( s + K == N ) return;
                                for ( i ++; i < N && Left [i]; i ++ );
                        }
                }
        }
}

void    Print ()
{
        int     i , first = 1;
        for ( i = 0; i < N; i ++ ) if ( !Left [i] ) {
                if ( first ) first = 0; else printf ( " " );
                printf ( "%d" , i + 1 );
        }
        printf ( "\n\n" );
}

main ()
{
        int     step = 0;
        while ( init () ) {
                printf ( "Selection #%d\n" , ++ step );
                Work ();
                Print ();              
        }
}
 