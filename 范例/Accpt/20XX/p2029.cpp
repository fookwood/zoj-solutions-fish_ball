#include <stdio.h>
#include <algorithm>

using namespace std;

int      num [1000] , N , M , *p , Tmp;

main ()
{
     while ( scanf ( "%d%d" , &N , &M ) != EOF ) {
           for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &num [i] );
           sort ( num , num + N );
           for ( int i = 0; i < M; i ++ ) {
               scanf ( "%d" , &Tmp );
               if ( Tmp < num [0] || Tmp >= num [N - 1] ) {
                    printf ( "no such interval\n" );
                    continue;
               }
               p = upper_bound ( num , num + N , Tmp );
               printf ( "[%d,%d)\n" , *(p - 1) , *p );
           }
           printf ( "\n" );
     }
}
