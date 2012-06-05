#include <stdio.h>
#include <string.h>

char    Ans [7] , Key [7];
int     A , B , N;
int     p , q , len [3] , First , step;
char    Link [3] [1000000] [7];

void    Check ()
{
        int     i , j , a , b;
        int     Num [10];

        for ( len [q] = i = 0; i < len [p]; i ++ ) {
                memset ( Num , 0 , sizeof ( Num ));
                a = b = 0;
                for ( j = 0; j < 6; j ++ ) {
                        Num [Link [p] [i] [j] - '0'] ++;
                        if ( Link [p] [i] [j] == Key [j] ) a ++;
                }
                for ( j = 0; j < 6; j ++ ) if ( Num [Key [j] - '0'] )
                        Num [Key [j] - '0'] -- , b ++;
                b -= a;
                if ( a != A || b != B ) continue;
                memcpy ( Link [q] [len [q]] , Link [p] [i] , sizeof ( Link [p] [i] ));
                len [q] ++; 
        }
        p = q; q = 1 - q;
        if ( len [p] == 1 && First == -1 ) First = step;
}

void    FirstPrepare ()
{
        memset ( Link , 0 , sizeof ( Link ));
        int     i , j;
        len [2] = 1000000;
        for ( j = 0; j < 6; j ++ ) Link [2] [0] [j] = '0';
        for ( i = 0; i < 999999; i ++ ) {
                for ( j = 5; Link [2] [i] [j] == '9'; j -- )
                        Link [2] [i + 1] [j] = '0';
                Link [2] [i + 1] [j] = Link [2] [i] [j] + 1;
                while ( --j >= 0 ) Link [2] [i + 1] [j] = Link [2] [i] [j]; 
        }
}

main ()
{
        FirstPrepare ();
        
        while ( scanf ( "%d" , &N ) , N ) {
                p = 2 , q = 0 , First = -1;
                for ( step = 0; step < N; step ++ ) {
                        scanf ( "%s %d %d" , Key , &A , &B );
                        if ( len [p] ) Check (); 
                }
                
                if ( len [p] != 1 )
                        if ( len [p] == 0 ) printf ( "No such number.\n" );
                                else printf ( "Still can't decide.\n" );
                        else if ( First == N - 1 ) printf ( "The answer %s was found after all tries.\n" , Key );
                                else printf ( "The answer %s was found after %d tries.\n" , Link [p] [0] , First + 1 );
        }
}
 