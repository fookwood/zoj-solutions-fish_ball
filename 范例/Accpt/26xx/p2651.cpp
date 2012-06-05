#include <stdio.h>
#include <set>
#define  MAXN     20001
#define  Inf      0x0fffffff

using namespace std;

int      N , A , B , Ord [MAXN] , Num [MAXN] , Deg [MAXN];

set <int> Deglist [3];

bool     check ();

main ()
{
     while ( scanf ( "%d%d%d", &N , &A , &B ) != EOF ) {
           if ( !check () ) printf ( "No\n" );
     }
}

bool check ()
{
     if ( A == B && A < N ) return false;
     set <int> :: iterator Iter , Iter2;
     int S;
     for ( int i = 0; i < 3; i ++ ) Deglist [i].clear ();
     for ( int i = 0; i <= N; i ++ ) Deg [i] = ( i - B >= 0 ) + ( i + A <= N ) , Deglist [Deg [i]].insert ( i );
     
     for ( int i = 0; i <= N; i ++ ) {
         if ( Deglist [0].empty () ) return false;
         Iter = Deglist [0].begin ();
         S = *Iter , Deglist [0].erase ( Iter );
         Ord [i] = S , Num [S] = i;
         if ( S - A >= 0 ) Iter2 = Deglist [Deg [S - A]].find ( S - A ) , Deglist [Deg [S - A]].erase ( Iter2 ) , Deglist [-- Deg [S - A]].insert ( S - A );
         if ( S + B <= N ) Iter2 = Deglist [Deg [S + B]].find ( S + B ) , Deglist [Deg [S + B]].erase ( Iter2 ) , Deglist [-- Deg [S + B]].insert ( S + B );
     }
     printf ( "Yes\n" );
     for ( int i = 1; i <= N; i ++ )
         if ( Num [i] > Num [i - 1] ) printf ( "Right %d\n" , Num [i] - Num [i - 1] );
         else printf ( "Left %d\n" , Num [i - 1] - Num [i] );
     return true;
}
