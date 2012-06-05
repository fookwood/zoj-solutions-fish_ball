#include <stdio.h>
#include <math.h>
#include <algorithm>

int      N , M , map [50] [50] , Limit , Len;

struct   TNode {
         int   x , y;
}        Data [2500];

bool     cmp ( const TNode &a , const TNode &b )
{
         return map [a.x] [a.y] > map [b.x] [b.y];
}

void     init ()
{
         scanf ( "%d%d%d" , &N , &M , &Limit );
         for ( int i = Len = 0; i < N; i ++ )
             for( int j = 0; j < M; j ++ ) {
                  scanf ( "%d" , &map [i] [j] );
                  if ( map [i] [j] ) Data [Len].x = i , Data [Len ++].y = j;
             }
         std::sort ( Data , Data + Len , cmp );
}

int      Ans ()
{
         if ( Len == 0 || Data [0].x * 2 + 3 > Limit ) return 0;
         
         int Ret = map [Data [0].x] [Data [0].y] , Time = Data [0].x + 2 , Next;
         
         for ( int i = 1; i < Len; i ++ ) {
             Next = Time + abs ( Data [i].x - Data [i - 1].x ) + abs ( Data [i].y - Data [i - 1].y ) + 1;
             if ( Next + Data [i].x + 1 > Limit ) return Ret;
             Ret += map [Data [i].x] [Data [i].y];
             Time = Next;
         }
         return Ret;
}

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         printf ( "%d\n" , Ans ());
     }
}
