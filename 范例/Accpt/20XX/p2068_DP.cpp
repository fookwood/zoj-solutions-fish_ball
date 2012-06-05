#include <stdio.h>
#include <algorithm>
#define min(a,b) (a<b?a:b)
using    namespace  std;

int      Long [2] [500] , N [2] , Opt [501] [501];

int      Ans ( int a , int b )
{
         memset ( Opt , 0 , sizeof ( Opt ));
         for ( int i = 1; i <= N [a]; i ++ )
             Opt [i] [i] = Opt [i - 1] [i - 1] + ( Long [a] [i - 1] - Long [b] [i - 1] ) * ( Long [a] [i - 1] - Long [b] [i - 1] );
             
         for ( int i = 1; i <= N [a]; i ++ )
             for ( int j = i + 1; j <= N [b] - N [a] + i; j ++ )
                 Opt [i] [j] = min ( Opt [i] [j - 1] , Opt [i - 1] [j - 1] + ( Long [a] [i - 1] - Long [b] [j - 1] ) * ( Long [a] [i - 1] - Long [b] [j - 1] ));
                 
         return  Opt [N [a]] [N [b]];
}

main ()
{
     char        Str [100];
     int Total , T;
     for ( scanf ( "%d\n" , &Total ); Total; Total -- ) {
         for ( int i = 0; i < 2; i ++ ) {
             scanf ( "%d" , &N [i] );
             for ( int j = 0; j < N [i]; j ++ ) scanf ( "%d" , &Long [i] [j] );
             gets ( Str );
             sort ( Long [i] , Long [i] + N [i] );
         }
         T = N [0] <= N [1] ? Ans ( 0 , 1 ) : Ans ( 1 , 0 );
         printf ( "%d\n" , T );
     }
}
