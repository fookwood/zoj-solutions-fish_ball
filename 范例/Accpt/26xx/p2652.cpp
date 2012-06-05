#include <stdio.h>
#include <string.h>
#define  Inf       0x7fffffff


bool     Positive [100] [100];
int      N , M , len [100] , edge [100] [100] , map [100] [100] , Min , Change [100];

bool     init ()
{
         if ( scanf ( "%d%d" , &N , &M ) == EOF ) return false;
         for ( int i = 0; i < N; i ++ )
             for ( int j = 0; j < M; j ++ ) scanf ( "%d" , &map [i] [j] );
         Min = Inf;
/*         if ( N > M ) {
              int t;
              for ( int i = 0; i + i < N; i ++ )
                  for ( int j = 0; j + j < M; j ++ )
                      t = map [i] [j] , map [i] [j] = map [j] [i] , map [j] [i] = t;
              t = N , N = M , M = t;
         }
*/

         for ( int i = 0; i < N; i ++ ) {
             len [i] = 0;
             for ( int j = 0; j < M; j ++ ) {
                 Positive [i] [j] = ( map [i] [j] > 0 );
                 if ( map [i] [j] ) edge [i] [len [i] ++] = j;
             }
         }
         
         memset ( Change , 0xff , sizeof ( Change ));
         return true;
}

void     Search ( int depth , int ctime )
{
         if ( ctime >= Min || Min == 0 ) return;
         if ( depth == N ) { Min = ctime; return; }

         int  Save [100] , j , i , t , S;
         memcpy ( Save , Change , sizeof ( Change ) );
         for ( i = S = 0; i < len [depth]; i ++ ) {
             j = edge [depth] [i];
             t = Positive [depth] [j] ? 0 : 1;
             if ( Change [j] == -1 ) {
                  Change [j] = t;
                  if ( t ) S ++;
             }
             else if ( Change [j] != t ) break;
         }
         if ( i == len [depth] ) Search ( depth + 1 , ctime + S );
         
         memcpy ( Change , Save , sizeof ( Change ) );
         for ( i = S = 0; i < len [depth]; i ++ ) {
             j = edge [depth] [i];
             t = Positive [depth] [j] ? 1 : 0;
             if ( Change [j] == -1 ) {
                Change [j] = t;
                if ( t ) S ++;
             }
             else if ( Change [j] != t ) break;
         }
         if ( i == len [depth] ) Search ( depth + 1 , ctime + 1 + S );
         memcpy ( Change , Save , sizeof ( Change) );
}

main ()
{
     while ( init () ) {
           Search ( 0 , 0 );
           if ( Min == Inf ) printf ( "-1\n" );
           else printf ( "%d\n" , Min );
     }
}
