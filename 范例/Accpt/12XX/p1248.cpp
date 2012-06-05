#include <stdio.h>
#define MAX 100
int     n;

int     Inf = 999999999;
int     x [MAX], y [MAX];

int     Check ()
{
        int     cross;
        int     MaxX = Inf, MaxY = Inf, MinX = -Inf, MinY = -Inf;
        int     a , b , c;
        for ( a = 0; a < n; a ++ ) {
                b = ( a + 1 ) % n;
                c = ( b + 1 ) % n;
                cross = ( x [a] - x [b] ) * ( y [c] - y [b] ) - ( y [a] - y [b] ) * ( x [c] - x [b] );

                if ( cross >= 0 ) {
                        if ( y [a] == y [b] ) {
                                if ( y [b] > y [c] ) {
                                        if ( x [b] < MaxX ) MaxX = x [b];
                                        if ( y [b] < MaxY ) MaxY = y [b];
                                } else {
                                        if ( x [b] > MinX ) MinX = x [b];
                                        if ( y [b] > MinY ) MinY = y [b];
                                }
                        } else {
                                if ( x [b] > x [c] ) {
                                        if ( x [b] < MaxX ) MaxX = x [b];
                                        if ( y [b] > MinY ) MinY = y [b];
                                } else {
                                        if ( x [b] > MinX ) MinX = x [b];
                                        if ( y [b] < MaxY ) MaxY = y [b];
                                };
                        }
                } else {
                        if ( y [a] == y [b] ) {
                                if ( y [b] > y [c] ) {
                                        if ( x [b] < MaxX ) MaxX = x [b];
                                        if ( y [b] > MinY ) MinY = y [b];
                                } else {
                                        if ( x [b] > MinX ) MinX = x [b];
                                        if ( y [b] < MaxY ) MaxY = y [b];
                                }
                        } else {
                                if ( x [b] > x [c] ) {
                                        if ( x [b] > MinX ) MinX = x [b];
                                        if ( y [b] > MinY ) MinY = y [b];        
                                } else {
                                        if ( x [b] < MaxX ) MaxX = x [b];
                                        if ( y [b] < MaxY ) MaxY = y [b];
                                }
                        }
                }
                if ( MinX > MaxX || MinY > MaxY ) return 0;
        }
        return 1;
}

main ()
{
        int     i , step = 0;
        
        while ( scanf ( "%d" , &n ) , n ) {
                step ++;
                printf ( "Floor #%d\n" , step );
                for ( i = 0; i < n; i ++ )
                        scanf ( "%d%d" , &x [i] , &y [i] );
                if ( Check () ) printf ( "Surveillance is possible.\n" );
                        else printf ( "Surveillance is impossible.\n" );
                printf ( "\n" );
        }
}
 