// zju 1435
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const   int     dx [16] = { 0 , 0 , -1 , 1 , -1 , 1 , -1 , 1 , -1 , -1 , 1 , 1 , -2 , -2 , 2 , 2 };
const   int     dy [16] = { -1 , 1 , 0 , 0 , -1 , -1 , 1 , 1 , -2 , 2 , -2 , 2 , -1 , 1 , -1 , 1 };

int     N , W , H , Pow [20];
bool    map [10] [10] , found;
int     graph [20] , x [20] , y [20] , c [20];
char    state [20];

int     Max;

bool    init ()
{
        char    Str [100];
        if ( scanf ( "%s" , Str ) == EOF ) return false;
        int     i , j;
        char    ch;
        scanf ( "%d%d" , &W , &H );
        for ( N = i = 0; i < H; i ++ )
                for ( j = 0; j < W; j ++ ) {
                        while ( scanf ( "%c" , &ch ) , !isupper ( ch ));
                        if ( ch != 'E' ) x [N] = i , y [N] = j , state [N ++] = ch;
                }
        scanf ( "%s" , Str );
        return true;
}

bool    range ( int x , int y ) { return x >= 0 && x < H && y >= 0 && y < W; }

void    WorkForGraph ()
{
        int     i , tx , ty , k;
        for ( i = 0; i < N; i ++ ) graph [i] = Pow [N] - 1 - Pow [i];
        for ( i = 0; i < N; i ++ ) {
                memset ( map , 0 , sizeof ( map ));
                switch ( state [i] ) {
                        case 'K' :      for ( k = 0; k < 8; k ++ ) {
                                                tx = x [i] + dx [k] , ty = y [i] + dy [k];
                                                if ( range ( tx , ty ) ) map [tx] [ty] = true;
                                        }
                                        break;
                        case 'Q' :      for ( k = 0; k < 8; k ++ )
                                                for ( tx = x [i] + dx [k] , ty = y [i] + dy [k]; range ( tx , ty ); tx += dx [k] , ty += dy [k] )
                                                        map [tx] [ty] = true;
                                        break;
                        case 'B' :      for ( k = 4; k < 8; k ++ )
                                                for ( tx = x [i] + dx [k] , ty = y [i] + dy [k]; range ( tx , ty ); tx += dx [k] , ty += dy [k] )
                                                        map [tx] [ty] = true;
                                        break;
                        case 'R' :      for ( k = 0; k < 4; k ++ )
                                                for ( tx = x [i] + dx [k] , ty = y [i] + dy [k]; range ( tx , ty ); tx += dx [k] , ty += dy [k] )
                                                        map [tx] [ty] = true;
                                        break;
                        case 'N' :      for ( k = 8; k < 16; k ++ ) {
                                                tx = x [i] + dx [k] , ty = y [i] + dy [k];
                                                if ( range ( tx , ty )) map [tx] [ty] = true;
                                        }
                                        break;
                }
                for ( k = 0; k < N; k ++ ) if ( map [x [k]] [y [k]] ) graph [i] &= (~Pow [k]) , graph [k] &= (~Pow [i]);
        }
}


void    Search ( int U , int size )
{
        if ( U == 0 ) {
                if ( size > Max ) Max = size , found = true;
                return;
        }
        
        int     len , i;
        for ( len = i = 0; i < N; i ++ ) if ( U & Pow [i] ) len ++;
        if ( len + size <= Max ) return;
        for ( i = 0; U; i ++ ) if ( U & Pow [i] ) {
                if ( size + c [i] <= Max ) return;
                U -= Pow [i];
                Search ( U & graph [i] , size + 1 );
                if ( found ) return;
        }
}

main ()
{
        int     i , j;
        for ( i = 0; i < 20; i ++ ) Pow [i] = 1 << i;
        
        while ( init () ) {
                WorkForGraph ();

                Max = 0;
                for ( i = N - 1 , j = 0; i >= 0; j |= Pow [i --] ) {
                        found = false;
                        Search ( j & graph [i] , 1 );
                        c [i] = Max;
                }
                printf ( "Minimum Number of Pieces to be removed: %d\n" , N - Max );
        }
}
