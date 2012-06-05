#include <stdio.h>
#include <string.h>

const   int     dx [4] = { 0 , 1 , 0 , -1 };
const   int     dy [4] = { 1 , 0 , -1 , 0 };
const   char    ConstMap [4] = { 'W' , 'W' , 'B' , 'B' };


int     N;
char    Map [80] [80];
bool    State [4] [80] [80];

bool    init ()
{
        scanf ( "%d" , &N );
        if ( !N ) return false;
        int     i , j;
        char    ch;
        for ( i = 0; i < N; i++ )
                for ( j = 0; j < N; j ++ ) {
                        while ( scanf ( "%c" , &ch ) , ch != 'W' && ch != 'U' && ch != 'B' );
                        Map [i] [j] = ch;
                }
        return true;
}

void    Search ( int k , int x , int y )
{
        int     tx , ty , i;
        State [k] [x] [y] = 1;
        for ( i = 0; i < 4; i ++ ) {
                tx = x + dx [i]; ty = y + dy [i];
                if ( tx < 0 || tx == N || ty < 0 || ty == N || Map [tx] [ty] != ConstMap [k] ) continue;
                if ( !State [k] [tx] [ty] ) Search ( k , tx , ty );
        }
}

int     Prepare ()
{
        int     i , j , k , tx , ty , blackwin = 0 , numl , numr , numu , numd;
        memset ( State , 0 , sizeof ( State ));
        for ( i = 0; i < N; i ++ ) {
                if ( Map [i] [0] == 'W' && !State [0] [i] [0] ) Search ( 0 , i , 0 );
                if ( Map [i] [N - 1] == 'W' && !State [1] [i] [N - 1] ) Search ( 1 , i , N - 1 );
                if ( Map [0] [i] == 'B' && !State [2] [0] [i] ) Search ( 2 , 0 , i );
                if ( Map [N - 1] [i] == 'B' && !State [3] [N - 1] [i] ) Search ( 3 , N - 1 , i );
        }

        for ( i = 0; i < N; i ++ ) {
                if ( State [0] [i] [N - 1] ) return 1;
                if ( State [2] [N - 1] [i] ) blackwin = 1;
        }
        if ( blackwin ) return 2;
        
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < N; j ++ ) if ( Map [i] [j] == 'U' ) {
                        numl = numr = numu = numd = 0;
                        for ( k = 0; k < 4; k ++ ) {
                                tx = i + dx [k]; ty = j + dy [k];
                                if ( tx < 0 || tx == N || ty < 0 || ty == N ) continue;
                                if ( State [0] [tx] [ty] ) numl ++;
                                if ( State [1] [tx] [ty] ) numr ++;
                                if ( State [2] [tx] [ty] ) numu ++;
                                if ( State [3] [tx] [ty] ) numd ++;
                        }
                        if ( j == N - 1 && numl ) return 3;
                        if ( j == 0 && numr ) return 3;
                        if ( numl && numr ) return 3;
                        if ( i == N - 1 && numu ) blackwin = 1;
                        if ( i == 0 && numd ) blackwin = 1;
                        if ( numu && numd ) blackwin = 1;
                }
        if ( blackwin ) return 4;
        return 5;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     state;
        while ( init () ) {
                state = Prepare ();
                if ( state == 1 ) printf ( "White has a winning path.\n" ); else
                if ( state == 2 ) printf ( "Black has a winning path.\n" ); else
                if ( state == 3 ) printf ( "White can win in one move.\n" ); else
                if ( state == 4 ) printf ( "Black can win in one move.\n" ); else
                printf ( "There is no winning path.\n" );
        }
}
 