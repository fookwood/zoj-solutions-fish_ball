#include <stdio.h>
#include <string.h>

const   int     dx [4] = { 1 , 0 , 0 , -1 };
const   int     dy [4] = { 0 , 1 , -1 , 0 };

int     map [7] [7];
int     x [33] , y [33] , Stive [33];

void    prepare ()
{
        memset ( map , 0xff , sizeof ( map ) );
        int     i , j , t = 0;
        for ( i = 0; i < 2; i ++ )
                for ( j = 2; j < 5; j ++ ) {
                        x [t] = i; y [t] = j; map [i] [j] = t ++;
                }
        for ( i = 2; i < 5; i ++ )
                for ( j = 0; j < 7; j ++ ) {
                        x [t] = i; y [t] = j; map [i] [j] = t ++;
                }
        for ( i = 5; i < 7; i ++ )
                for ( j = 2; j < 5; j ++ ) {
                        x [t] = i; y [t] = j; map [i] [j] = t ++;
                }
}

void    init ()
{
        int     t;
        memset ( Stive , 0 , sizeof ( Stive ));
        while ( scanf ( "%d" , &t ) , t )
                Stive [t - 1] = 1;
}

int     range ( int x , int y )
{
        return x >= 0 && x < 7 && y >= 0 && y < 7 && map [x] [y] != -1;
}

int     Change ()
{
        int     k , i , s = 0 , tx , ty;
        for ( i = 32; i >= 0; i -- ) if ( Stive [i] ) s += i + 1;
        else {
                for ( k = 0; k < 4; k ++ ) {
                        tx = x [i] + dx [k];
                        ty = y [i] + dy [k];
                        if ( !range ( tx , ty ) || !Stive [map [tx] [ty]] ) continue;
                        tx += dx [k]; ty += dy [k];
                        if ( !range ( tx , ty ) || !Stive [map [tx] [ty]] ) continue;
                        
                        Stive [map [tx] [ty]] = 0; tx -= dx [k]; ty -= dy [k];
                        Stive [map [tx] [ty]] = 0; tx -= dx [k]; ty -= dy [k];
                        Stive [map [tx] [ty]] = 1;
                        return -1;
                }
        }
        return s;
}

void    print ()
{
        int     i , j;
        for ( i = 0; i < 7; i ++ ) {
                for ( j = 0; j < 7; j ++ ) {
                        if ( map [i] [j] == -1 ) {
                                printf ( "    " );
                                continue;
                        }
                        printf ( "   %d" , Stive [map [i] [j]] );
                }
                printf ( "\n" );
        }
}

main ()
{
        printf ( "HI Q OUTPUT\n" );

        int     total , t;
        prepare ();
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                while ( t = Change () , t == -1 );
                printf ( "%d\n" , t );
        }
        
        printf ( "END OF OUTPUT\n" );
}
 