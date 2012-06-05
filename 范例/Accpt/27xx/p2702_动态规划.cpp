#include <stdio.h>
#include <map>
#include <algorithm>
#define MAXN 4100

using namespace std;

struct TState {
       int   c [4] , next , max , num;
};

typedef map <int , int>   TMap;

int    N;
TState State [MAXN];

TMap   Map;

bool   init ();
void   solve ();

main ()
{
     while ( init () ) {
           solve ();
     }
}

void solve ()
{
     TMap :: iterator Iter;
     State [N].max = 0;
     int   size , list [2] , k , l;
     for ( int i = N - 1; i >= 0; i -- ) {
         State [i].max = State [i + 1].max , State [i].next = i + 1;
         Map.clear ();
         size = 0;
         for ( int j = i; j < N; j ++ ) {
             Iter = Map.find ( State [j].num );
             if ( Iter == Map.end () ) Map [State [j].num] = 0 , Iter = Map.find ( State [j].num );
             Iter->second ++;
             if ( Iter->second == 4 ) size = 2 , list [0] = list [1] = Iter->first;
             if ( Iter->second == 2 ) list [size ++] = Iter->first;
             if ( size == 2 ) break;
         }
         if ( size < 2 ) continue;
         for ( k = i , size = 0; size < 2; k ++ )
             if ( State [k].num == list [0] ) State [i].c [size ++] = k;
         l = k;
         k = list [1] == list [0] ? k : i;
         
         for ( ; size < 4; k ++ )
             if ( State [k].num == list [1] ) State [i].c [size ++] = k;
         if ( k > l ) l = k;
         if ( State [l].max + 1 < State [i].max ) continue;
         State [i].max = State [l].max + 1;
         State [i].next = l;
         sort ( State [i].c , State [i].c + 4 );
     }
     printf ( "%d\n" , State [0].max );
     for ( int i = 0; i != N; i = State [i].next ) if ( State [i].next != i + 1 ) {
         for ( int j = 0; j < 4; j ++ ) {
              if ( j ) printf ( " " );
              printf ( "%d" , State [i].c [j] + 1 );
         }
         printf ( "\n" );
     }
     printf ( "\n" );
}

bool init ()
{
     if ( scanf ( "%d" , &N ) != 1 ) return false;
     for ( int i = 0; i < N; i ++ )
         scanf ( "%d" , &State [i].num );
     return true;
}
