#include <stdio.h>
#define  Inf      0x7fffffff
#define  Ord(a,b,c) ((((a)*M+(b))<<2)+(c))

const    int      dx [4] = { 0 , -1 , 0 , 1 };
const    int      dy [4] = { -1 , 0 , 1 , 0 };

struct TNode {
       int   x , y , face , Min;
}      Points [40000];

int    HeapSize , Heap [40000] , Cd [40000] , Cost [2] , N , M , Len , Finish;

char   map [100] [100];

bool   init ()
{
       if ( scanf ( "%d%d%d%d\n" , &M , &N , &Cost [0] , &Cost [1] ) == EOF ) return false;
       for ( int i = N - 1; i >= 0; i -- ) scanf ( "%s" , map [i] );
       for ( int i = Len = 0; i < N; i ++ )
           for ( int j = 0; j < M; j ++ )
               for ( int f = 0; f < 4; f ++ )
                   Points [Len].x = i , Points [Len].y = j , Points [Len].face = f , Points [Len ++].Min = Inf;
       Finish = Ord ( N - 1 , M - 1 , 2 );
//       for ( int i = 0; i < N; i ++ ) printf ( "%s\n" , map [i] );
       return true;
}

void   GoDown ()
{
       int p = 0 , q = 1 , Key = Points [Heap [0]].Min , x = Heap [0];
       while ( q < HeapSize ) {
             if ( q + 1 < HeapSize && Points [Heap [q + 1]].Min < Points [Heap [q]].Min ) q ++;
             if ( Points [Heap [q]].Min >= Key ) break;
             Heap [p] = Heap [q] , Cd [Heap [p]] = p;
             p = q , q = p * 2 + 1;
       }
       Heap [p] = x , Cd [x] = p;
}

void   FlyUp ( int k )
{
       int q = k , p = ( k - 1 ) / 2 , Key = Points [Heap [k]].Min , x = Heap [k];
       while ( q ) {
             if ( Points [Heap [p]].Min <= Key ) break;
             Heap [q] = Heap [p] , Cd [Heap [q]] = q;
             q = p , p = ( q - 1 ) / 2;
       }
       Heap [q] = x , Cd [x] = q;
}

bool   range ( int x , int y )
{
       return x >= 0 && x < N && y >= 0 && y < M;
}

int    Dij ()
{
       if ( map [0] [0] == 'b' ) return -1;
       
       HeapSize = 1 , Heap [0] = 1 , Cd [1] = 0 , Points [1].Min = Cost [1];
       Cd [2] = HeapSize , Heap [HeapSize ++] = 2 , Points [2].Min = Cost [0] , FlyUp ( 1 );
       Cd [3] = HeapSize , Heap [HeapSize ++] = 3 , Points [3].Min = Cost [1] , FlyUp ( 2 );
       
       int      k , x , y , f , tx , ty , tf , Order , d;
//       printf ( "%d\n" , Finish );

       while ( HeapSize ) {
             k = Heap [0] , Heap [0] = Heap [-- HeapSize] , GoDown ();
             
             f = k & 3 , x = ( k >> 2 ) / M , y = ( k >> 2 ) % M;


             if ( k == Finish ) return Points [Finish].Min;
             
//             if ( f == 3 ) printf ( "%d %d %d %d\n" , x , y , f , Points [k].Min );

             tx = x + dx [f] , ty = y + dy [f];
             if ( !range ( tx , ty ) || map [tx] [ty] == 'b' ) continue;
             for ( d = -1; d < 2; d ++ ) {
                 tf = ( f + d + 4 ) & 3;
//             printf ( "T %d %d %d\n" , tx , ty , tf );
                 Order = Ord ( tx , ty , tf );
                 if ( Points [Order].Min == Inf ) Cd [Order] = HeapSize , Heap [HeapSize ++] = Order;
                 if ( Points [k].Min + Cost [d & 1] < Points [Order].Min )
                    Points [Order].Min = Points [k].Min + Cost [d & 1] , FlyUp ( Cd [Order] );
             }
             
       }
       return -1;
}

main ()
{
     while ( init () ) {
           int    Ans = Dij ();
           if ( Ans != -1 ) printf ( "%d\n" , Ans );
           else printf ( "impossible\n" );
     }
}
