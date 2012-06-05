#include <stdio.h>
#include <algorithm>
#include <utility>
#include <set>
#define MAXN   300
#define MAXM   30000

using namespace std;

typedef  pair <int,int> TQueue;
typedef  set < TQueue > TEdge;

int      N , M , dis [MAXN] [MAXN] , QSize , Father [MAXM] , RootSon;
TQueue   Queue [MAXN] , Edge [MAXM];
TEdge    EdgeSet;

bool   init ();
void   print ();
bool   Refresh ( int );

main ()
{
     int    i;
     while ( init () ) {
           for ( RootSon = 0 , i = 1; i < N; i ++ ) if ( !Refresh ( i ) ) break;
           if ( i >= N ) print ();
           else printf ( "-1\n" );
           printf ( "\n" );
     }
}

bool Refresh ( int p )
{
     
     int     a , b , c , d , i , j , r;
     
     QSize = 1 , Queue [0].first = dis [0] [p] , Queue [0].second = 0;
     
     for ( i = 1; i < p; i ++ ) {
         a = dis [0] [i] , b = dis [i] [p] , c = dis [0] [p];
         if ( a >= b + c || b >= a + c || c >= a + b || ( a + b + c ) % 2 ) return false;
         d = ( a + b - c ) / 2;
         for ( r = i , j = 0; j < d; j ++ ) r = Father [r];
         Queue [QSize].first = b - d , Queue [QSize ++].second = r;
     }
     
     sort ( Queue , Queue + QSize );
     if ( Queue [0].first == 0 ) return false;
     if ( Queue [0].second == 0 ) RootSon ++;
     
     for ( j = 1 , r = p; j < Queue [0].first; j ++ , r = Father [r] )
         Father [r] = M ++;
     Father [r] = Queue [0].second;
     
     for ( r = p , d = i = 0; i < QSize; i ++ ) {
         for ( ; d < Queue [i].first; d ++ ) r = Father [r];
         if ( r != Queue [i].second ) return false;
     }
     return RootSon <= 1;
}

void print ()
{
     TQueue            Tmp;
     TEdge :: iterator Iter;
     printf ( "%d\n" , M );
     EdgeSet.clear ();
     for ( int i = 1; i < M; i ++ ) {
         Tmp.first = i + 1 , Tmp.second = Father [i] + 1;
         if ( Tmp.first > Tmp.second ) swap ( Tmp.first , Tmp.second );
         EdgeSet.insert ( Tmp );
     }
     for ( Iter = EdgeSet.begin (); Iter != EdgeSet.end (); Iter ++ )
         printf ( "%d %d\n" , Iter->first , Iter->second );
}

bool init ()
{
     if ( scanf ( "%d" , &N ) != 1 ) return false;
     for ( int i = 0; i < N; i ++ )
         for ( int j = 0; j < N; j ++ )
             scanf ( "%d" , &dis [i] [j] );
     M = N;
     return true;
}
