#include <stdio.h>
#include <string.h>

int      N , Ans , Sum [101] [101];
char     map [100] [110];

main ()
{
     memset ( Sum , 0 , sizeof ( Sum ));
     
     while ( scanf ( "%d\n" , &N ) != EOF ) {
           for ( int i = 0; i < N; i ++ ) gets ( map [i] );
           for ( int i = 1; i <= N; i ++ )
               for ( int j = 1; j <= N; j ++ )
                   Sum [i] [j] = map [i - 1] [j - 1] == '#' ? 1 : 0;
           for ( int i = 1; i <= N; i ++ )
               for ( int j = 1; j <= N; j ++ )
                   Sum [i] [j] += Sum [i - 1] [j] + Sum [i] [j - 1] - Sum [i - 1] [j - 1];
           Ans = 0;
           for ( int i = 1; i <= N; i ++ )
               for ( int j = 1; j <= N; j ++ )
                   for ( int p = i; p <= N && map [p - 1] [j - 1] == '.'; p ++ )
                       for ( int q = j; q <= N; q ++ ) {
                           if ( Sum [p] [q] - Sum [i - 1] [q] - Sum [p] [j - 1] + Sum [i - 1] [j - 1] ) break;
                           Ans ++;
                       }
           printf ( "%d\n" , Ans );
     }
}
