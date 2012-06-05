#include <stdio.h>
#include <string.h>

const    int      dx [4] = { -1 , 0 , 1 , 0 };
const    int      dy [4] = { 0 , -1 , 0 , 1 };

int      N , M , map [102] [102];
bool     Fill [102] [102];

bool     range ( int x , int y )
{
         return x >= 0 && x <= N + 1 && y >= 0 && y <= M + 1;
}

bool     check ( int x1 , int y1 , int x2 , int y2 )
{
         if ( x1 == x2 && y1 == y2 ) return false;
         if ( map [x1] [y1] == 0 || map [x1] [y1] != map [x2] [y2] ) return false;
         
         memset ( Fill , 0 , sizeof ( Fill ));
         int    x , y , px , py , face;
         
         Fill [x1] [y1] = true;
         for ( int i = 0; i < 4; i ++ ) {
             for ( x = x1 + dx [i] , y = y1 + dy [i]; range ( x , y ) && map [x] [y] == 0; x += dx [i] , y += dy [i] )
                 Fill [x] [y] = true;
             if ( x == x2 && y == y2 ) return true;
         }

         for ( int i = 0; i < 4; i ++ )
             for ( x = x2 + dx [i] , y = y2 + dy [i]; range ( x , y ) && map [x] [y] == 0; x += dx [i] , y += dy [i] ) {
                 if ( Fill [x] [y] ) return true;
                 for ( face = ( i + 1 ) % 4 , px = x + dx [face] , py = y + dy [face]; range ( px , py ); px += dx [face] , py += dy [face] ) {
                     if ( Fill [px] [py] ) return true;
                     if ( map [px] [py] ) break;
                 }
                 for ( face = ( i + 3 ) % 4 , px = x + dx [face] , py = y + dy [face]; range ( px , py ); px += dx [face] , py += dy [face] ) {
                     if ( Fill [px] [py] ) return true;
                     if ( map [px] [py] ) break;
                 }
             }
         return false;
}

main ()
{
     while ( scanf ( "%d%d" , &N , &M ) , N || M ) {
           memset ( map , 0 , sizeof ( map ));
           for ( int i = 1; i <= N; i ++ )
               for ( int j = 1; j <= M; j ++ ) 
                   scanf ( "%d" , &map [i] [j] );
                   
           int     Q , x1 , y1 , x2 , y2 , Ans = 0;
           for ( scanf ( "%d" , &Q ); Q ; Q -- ) {
               scanf ( "%d%d%d%d" , &x1 , &y1 , &x2 , &y2 );
               if ( check ( x1 , y1 , x2 , y2 ) ) Ans ++ , map [x1] [y1] = map [x2] [y2] = 0;
           }
           printf ( "%d\n" , Ans * 2 );
     }
}
