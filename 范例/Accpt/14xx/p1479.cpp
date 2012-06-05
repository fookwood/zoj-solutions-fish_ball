#include <stdio.h>
#include <string.h>

const   int     max     = 20;
const   int     dx [8]  = { -1 , 0 , 1 , 0 , 1 , 1 , -1 , -1 };
const   int     dy [8]  = { 0 , 1 , 0 , -1 , -1 , 1 , -1 , 1 };

int     N , M , map [max] [max] , min [max] [max];

int     Startx , Starty , Goalx , Goaly;
int     tot , x [max * max] , y [max * max];
char    s [max * max];

bool    range ( int x, int y )
{
        return x >= 0 && x < N && y >= 0 && y < M;
}

bool    init ()
{
        if ( scanf ( "%d%d" , &N , &M ) == EOF ) return false;
        scanf ( "%d%d%d%d" , &Startx , &Starty , &Goalx , &Goaly );
        Startx --; Starty --; Goalx --; Goaly --;

        int     i , face;
        memset ( map , 0 , sizeof ( map ));
        
        scanf ( "%d" , &tot );
        for ( i = 0; i < tot; i ++ )
                scanf ( "%d %d %c" , &x [i] , &y [i] , &s [i] ) , map [-- x [i]] [-- y [i]] = 1;
        for ( i = 0; i < tot; i ++ ) {
                if ( s [i] == 'B' ) continue;
                if ( s [i] == 'u' ) face = 0; else
                if ( s [i] == 'r' ) face = 1; else
                if ( s [i] == 'd' ) face = 2; else
                if ( s [i] == 'l' ) face = 3;
                for ( x [i] += dx [face] , y [i] += dy [face]; range ( x [i] , y [i] ) && map [x [i]] [y [i]] != 1; x [i] += dx [face] , y [i] += dy [face] )
                        map [x [i]] [y [i]] = 2;        
        }
        return  true;
}

void    Search ( int x, int y , int cost )
{
        if ( min [x] [y] != -1 && cost >= min [x] [y] ) return;
        min [x] [y] = cost;
        int     face , px , py , face2 , ppx , ppy;
        for ( face = 0; face < 8; face ++ ) {
                px = x + dx [face]; py = y + dy [face];
                if ( !range ( px , py ) ) continue;
                if ( map [px] [py] == 0 ) { Search ( px , py , cost ); continue; }
                if ( map [px] [py] == 1 ) continue;

                for ( face2 = 0; face2 < 8; face2 ++ ) {
                        ppx = px + dx [face2]; ppy = py + dy [face2];
                        if ( !range ( ppx , ppy ) ) continue;
                        if ( map [ppx] [ppy] == 0 ) Search ( ppx , ppy , cost + 1 );
                }
        }
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        while ( init () ) {
                memset ( min , 0xff , sizeof ( min ));
                Search ( Startx , Starty , 0 );
/*                        for ( int i = 0; i < N; i ++ ) {
                                for ( int j = 0; j < M; j ++ ) printf( "%d " , min [i] [j] );
                                printf ( "\n" );
                        }
*/
                printf ( "%d\n" , min [Goalx] [Goaly] );
        }
}
