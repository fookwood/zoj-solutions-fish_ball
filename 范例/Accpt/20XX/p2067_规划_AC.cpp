#include <stdio.h>
#include <string.h>

int      N , Ans;
int      UpSum [101] [101];
char     map [101] [101];

main ()
{
     memset ( UpSum , 0 , sizeof ( UpSum ));
     while ( scanf ( "%d\n" , &N ) != EOF ) {
           for ( int i = 0; i < N; i ++ ) gets ( map [i] );
           for ( int i = 1; i <= N; i ++ )
               for ( int j = 1; j <= N; j ++ )
                   UpSum [i] [j] = map [i - 1] [j - 1] == '#' ? 1 : 0;
           for ( int i = 1; i <= N; i ++ )
               for ( int j = 1; j <= N; j ++ )
                   UpSum [i] [j] += UpSum [i - 1] [j];
                
           Ans = 0;   
           for ( int i = 0; i < N; i ++ )
               for ( int j = i + 1; j <= N; j ++ ) {
                   int   t = 0;
                   for ( int k = 1; k <= N; k ++ ) {
                       if ( UpSum [j] [k] - UpSum [i] [k] ) t = 0;
                          else t ++;
                       Ans += t;
                   }
               }
           printf ( "%d\n" , Ans );
     }
}
