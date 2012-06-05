#include <stdio.h>
#include <string.h>

int     N , Pow [16];
int     minx [15] , miny [15] , maxx [15] , maxy [15] , color [15];
int     after [15];
int     Opt [1 << 15] [15];

int     f ( int s , int p )
{
        if ( Opt [s] [p] == 0 ) {
                Opt [s] [p] = 99999;
                
                int     i , t , s_ = s ^ Pow [p] , pre;

                for ( pre = i = 0; i < N; i ++ ) if ( s_ & Pow [i] ) {
                        pre |= after [i];
                }

                for ( i = 0; i < N; i ++ ) if ( (s_ & Pow [i]) && ( pre & Pow [i] ) == 0 ) {
                        t = f ( s_ , i );
                        if ( color [p] != color [i] ) t ++;
                        if ( t < Opt [s] [p] ) Opt [s] [p] = t;
                }
                
        }
//        printf ( "%d %d %d\n" , s , p , Opt [s] [p] );
        return  Opt [s] [p];
}

main ()
{
        int     i , j , total , min , pre;
        for ( i = 0; i < 16; i ++ ) Pow [i] = 1 << i;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                scanf ( "%d" , &N );
                for ( i = 0; i < N; i ++ ) scanf ( "%d%d%d%d%d" , &miny [i] , &minx [i] , &maxy [i] , &maxx [i] , &color [i] );
                // Input the Data

                for ( i = 0; i < N; i ++ )
                        for ( after [i] = j = 0; j < N; j ++ ) if ( i != j ) {
                                if ( maxy [j] > miny [i] || maxx [j] <= minx [i] || minx [j] >= maxx [i] ) continue;
                                after [i] |= Pow [j];
                        }
                // Work for after
                memset ( Opt , 0 , sizeof ( Opt ));
                for ( i = 0; i < N; i ++ )
                        for ( j = 0; j < N; j ++ )
                                Opt [1 << i] [j] = color [i] == color [j] ? 1 : 2;

                for ( pre = i = 0; i < N; i ++ ) pre |= after [i];
                min = 9999;
                for ( i = 0; i < N; i ++ ) if ( ( pre & Pow [i] ) == 0 ) {
                        j = f ( ( 1 << N ) - 1 , i );
                        if ( j < min ) min = j;
                }
                printf ( "%d\n" , min );
        }
}
 