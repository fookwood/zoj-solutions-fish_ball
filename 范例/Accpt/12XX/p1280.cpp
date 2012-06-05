#include <stdio.h>

int     total;
int     x1 , x2 , x3 , x4 , y1 , y2 , y3 , y4;
int     c1 , c2 , c3;    

int     cross ( int x1 , int y1 , int x2 , int y2 )
{
        return  x1 * y2 - x2 * y1;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        printf ( "INTERSECTING LINES OUTPUT\n" );
        scanf ( "%d" , &total );
        while ( total ) {
                scanf ( "%d %d %d %d %d %d %d %d" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3 , &x4 , &y4 );
                c1 = cross ( y1 - y2 , x2 - x1 , y3 - y4 , x4 - x3 );
                c2 = cross ( cross ( x2 , y2 , x1 , y1 ) , x2 - x1 , cross ( x4 , y4 , x3 , y3 ) , x4 - x3 );
                c3 = cross ( y1 - y2 , cross ( x2 , y2 , x1 , y1 ) , y3 - y4 , cross ( x4 , y4 , x3 , y3 ));

                if ( c1 == 0 )
                        if ( c2 == 0 && c3 == 0 ) printf ( "LINE\n" );
                        else printf ( "NONE\n" );
                else  printf ( "POINT %.2lf %.2lf\n" , double ( c2 ) / c1 , double ( c3 ) / c1 );
                total --;
        }
        printf ( "END OF OUTPUT\n" );
}
 