#include <stdio.h>
#include <string.h>

int     NumX [2000] , NumY [2000];
int     N , M , MaxUp [200] [200] , MaxRight [200] [200];

int     lenData , a [200] , b [200] , c [200] , d [200];

int     max ( int a , int b )
{       return  a > b ? a : b; }
int     min ( int a , int b )
{       return  a < b ? a : b; }

void    swap ( int &a , int &b )
{       int     t = a; a = b; b = t; }

void    init ()
{
        int     i , j;
        memset ( NumX , 0xff , sizeof ( NumX ));
        memset ( NumY , 0xff , sizeof ( NumY ));
        
        scanf ( "%d" , &lenData );

        for ( i = 0; i < lenData; i ++ ) {
                scanf ( "%d%d%d%d" , &a [i] , &b [i] , &c [i] , &d [i] ) ,
                NumX [a [i]] = NumX [c [i]] = NumY [b [i]] = NumY [d [i]] = 0;
                if ( a [i] > c [i] ) swap ( a [i] , c [i] );
                if ( b [i] > d [i] ) swap ( b [i] , d [i] );
        }
        N = M = 0;
        for ( i = 0; i < 1001; i ++ ) {
                if ( NumX [i] == 0 ) NumX [i] = N ++;
                if ( NumY [i] == 0 ) NumY [i] = M ++;
        }
//        printf ( "%d %d\n" , N , M );

        memset ( MaxUp , 0 , sizeof ( MaxUp ));
        memset ( MaxRight , 0 , sizeof ( MaxRight ));

        for ( i = 0; i < lenData; i ++ ) {
                if ( a [i] == c [i] )
                        for ( j = NumY [b [i]]; j < NumY [d [i]]; j ++ )
                                MaxUp [NumX [a [i]]] [j] = 1;
                else
                        for ( j = NumX [a [i]]; j < NumX [c [i]]; j ++ )
                                MaxRight [j] [NumY [b [i]]] = 1;
        }
        
        for ( i = 0; i < N; i ++ )
                for ( j = M - 1; j >= 0; j -- )
                        if ( MaxUp [i] [j] ) MaxUp [i] [j] += MaxUp [i] [j + 1];
        for ( j = 0; j < M; j ++ )
                for ( i = N - 1; i >= 0; i -- )
                        if ( MaxRight [i] [j] ) MaxRight [i] [j] += MaxRight [i + 1] [j];
}

int     Ans ()
{
        int     ret = 0;
        int     i , j , p , q;

        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < M; j ++ ) if ( MaxUp [i] [j] && MaxRight [i] [j] ) {
                        for ( p = i + 1; p <= i + MaxRight [i] [j]; p ++ )
                                for ( q = j + 1; q <= j + MaxUp [i] [j]; q ++ )
                                        if ( MaxUp [p] [j] + j >= q && MaxRight [i] [q] + i >= p )
                                                ret ++;
                }
        
        return ret;
}

main ()
{
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                printf ( "%d\n" , Ans () );
        }
}
 