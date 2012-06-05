#include <stdio.h>
#include <string.h>

const   int     dx [4] = { 1 , 0 , -1 , 0 };
const   int     dy [4] = { 0 , 1 , 0 , -1 };

const   int     fx [4] = { 0 , 0 , -1 , -1 };
const   int     fy [4] = { -1 , 0 , 0 , -1 };

char    BitMap [32] [32];

int     Check ( char p )
{
        if ( p == 'E' ) return 0;
        if ( p == 'N' ) return 1;
        if ( p == 'W' ) return 2;
        if ( p == 'S' ) return 3;
        return -1;
}

void    PrintMap ()
{
        int     i , j;
        for ( j = 31; j >= 0; j -- ) {
                for ( i = 0; i < 32; i ++ )
                        printf ( "%c" , BitMap [i] [j] );
                printf ( "\n" );
        }
}

void    Work ()
{
        memset ( BitMap , '.' , sizeof ( BitMap ));
        int     x , y;
        char    ch;
        int     face;
        scanf ( "%d%d\n" , &x , &y );
        while ( scanf ( "%c" , &ch ) , ch != '.' ) {
                face = Check ( ch );
                BitMap [x + fx [face]] [y + fy [face]] = 'X';
                x += dx [face]; y += dy [face];
        }
        PrintMap ();
}

main ()
{
        int     total , step;
        for ( step = 1 , scanf ( "%d" , &total ) ; step <= total; step ++ ) {
                printf ( "Bitmap #%d\n" , step );
                Work ();
                printf ( "\n" );
        }
}
 