#include <stdio.h>
#include <string.h>

const   int     maxn    = 20;

int     N;
int     Left;
int     Car [21] , Part [21];
int     move = 0;
int     i , t;

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        N = 0;
        while ( scanf ( "%d" , &Car [N] ) , Car [N] < 99 )
                N ++;
        memset ( Part , 0 , sizeof ( Part ));
        while ( scanf ( "%d" , &Left ) != EOF ) {
                t = -1;
                for ( i = 0; i < N; i ++ ) {
                        if ( Part [i] ) continue;
                        if ( t == -1 || ( Left + maxn + maxn - Car [i] - move ) % maxn < ( Left + maxn + maxn - Car [t] - move ) % maxn )
                                t = i;
                }
                if ( t != -1 ) {
                        i = ( Left + maxn + maxn - Car [t] - move ) % maxn;
                        move += i;
                        move %= maxn;
                        Part [t] = Left;
                }
        }
        for ( i = 0; i < N; i ++ )
                if ( Part [i] ) printf ( "Original position %d parked in %d\n" , Car [i] , Part [i] );
                else printf ( "Original position %d did not park\n" , Car [i] );
}
