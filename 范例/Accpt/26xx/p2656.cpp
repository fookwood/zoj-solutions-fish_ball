#include <stdio.h>
#include <string.h>
#define  min(a,b) ((a)<(b)?(a):(b))

int      x [20000] , N , N2 , First , Small;

main ()
{
     while ( scanf ( "%d" , &N ) != EOF ) {
           for ( int i = 0; i < N; i ++ ) scanf ( "%d%d" , &x [i] , &N2 ) , x [i] -= N2;
           for ( int i = 0; i < N; i ++ ) x [i + N] = x [i]; N2 = N + N;
           First = N2 , Small = 0;
           for ( int i = N2 - 1; i >= 0; i -- ) {
               Small = min ( Small , 0 ) + x [i];
               if ( Small >= 0 ) First = i;
           }
           if ( First < N ) printf ( "%d\n" , First );
           else printf ( "impossible\n" );
     }
}
