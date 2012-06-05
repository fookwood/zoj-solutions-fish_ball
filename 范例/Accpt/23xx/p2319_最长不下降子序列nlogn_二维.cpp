#include <stdio.h>
#include <algorithm>

using namespace std;

#define  MAXN     100001

struct   TNode {
         int      x , y , Order;
}        Data [MAXN];

int      N , Min [MAXN] , Max [MAXN] , Long [MAXN] , Pre [MAXN] , Pos [MAXN] , Ans , AnsP;

void     init ();
void     work ();

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         work ();
     }
}

void print ( int k )
{
     if ( Pre [k] != -1 ) print ( Pre [k] ), printf ( " " );
     printf ( "%d" , Data [k].Order + 1 );
}

void work ()
{
     Ans = 0;
     fill ( Max , Max + N , -1 );
     memset ( Max , 0xff , sizeof ( Max ));
     fill ( Long + 1 , Long + N + 1 , 0x7fffffff );
     Long [0] = -1; Pos [0] = -1;
     int  low , high , mid;
     for ( int i = 0; i < N; i ++ ) {
         
         if ( i && Data [i].x != Data [i - 1].x )
              for ( int j = i - 1; j >= 0 && Data[j].x == Data [i - 1].x; j -- )
                  if ( Data [j].y < Long [Max [j]] )
                     Long [Max [j]] = Data [j].y , Pos [Max [j]] = j;
                     
         low = 0 , high = Ans + 1;
         while ( low + 1 < high ) {
               mid = ( low + high ) >> 1;
               if ( Long [mid] < Data [i].y ) low = mid;
               else high = mid;
         }
         Max [i] = low + 1;
         Pre [i] = Pos [low];
         if ( Max [i] > Ans ) Ans = Max [i] , AnsP = i;
     }
     printf ( "%d\n" , Ans );
     print ( AnsP );
     printf ( "\n" );
}

bool cmp ( const TNode &a , const TNode &b )
{
     return a.x == b.x ? a.y < b.y : a.x < b.x;
}

void init ()
{
     scanf ( "%d" , &N );
     for ( int i = 0; i < N; i ++ ) scanf ( "%d%d" , &Data [i].x , &Data [i].y ) , Data [i].Order = i;
     sort ( Data , Data + N , cmp );
}
