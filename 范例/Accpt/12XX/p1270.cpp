#include <stdio.h>

int     N;
float   Pos [6];
int     A [6] , B [6];
bool    Ans [31];

bool    Check ( int s )
{
        int     i , k;
        float   t;
        for ( i = 0; i < N; i ++ ) {
                t = Pos [i] * 60 * 60 / s;
                t = t - int ( t /  ( A [i] + B [i] ) )* ( A [i] + B [i] );
                if ( t > A [i] ) return false;
        }
        return true;
}

void    PrintAnswer ()
{
        int     i;
        int     last = 0;
        int     len = 0;
        int     Ansa [30] , Ansb [30];
        
        for ( i = 0; i < 31; i ++ ) if ( Ans [i] ) {
                if ( !last ) Ansa [len ++] = i;
                Ansb [len - 1] = i;
                last ++;
        } else  last = 0;

        if ( !len ) printf ( "No acceptable speeds." );
        for ( i = 0; i < len; i ++ ) {
                if ( i ) printf ( ", " );
                printf ( "%d" , Ansa [i] + 30 );
                if ( Ansa [i] != Ansb [i] ) printf ( "-%d" , Ansb [i] + 30 );
        }
        printf ( "\n" );
}

main ()
{
        int     step = 0;
        int     a , b , c , i;
        while ( scanf ( "%d\n" , &N ) , N > 0 ) {
                step ++;
                printf ( "Case %d: " , step );
                
                for ( i = 0; i < N; i ++ ) {
                        scanf ( "%f %d %d %d\n" , &Pos [i] , &a , &b , &c );
                        A [i] = a + b; B [i] = c;
                }
                for ( i = 0; i < 31; i ++ )
                        Ans [i] = Check ( i + 30 );

                PrintAnswer ();
        }
}
