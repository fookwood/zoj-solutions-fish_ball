#include <stdio.h>
#include <string.h>
#include <algorithm>

#define MAXN      300010
#define MAXAll    20000100

using namespace std;
                  
int N , Son [MAXN] , Left [MAXAll] , In [MAXAll] , Out [MAXAll] , Stack [MAXN] , Reach [MAXN];

bool  init ();
void  ConstructTree ();
void  solve ();
void  DFS ();

main ()
{
     int total , p = 0;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         if ( p ) printf ( "\n" );
         printf ( "Case %d:\n" , ++ p );
         init ();
         ConstructTree ();
         DFS ();
         solve ();
     }
}

void DFS ()
{
     
     int depth = 0 , T = 0;
     Stack [0] = 0 , Reach [0] = Left [0] , In [0] = T ++;
     for ( depth = 0; depth >= 0; ) {
         if ( Stack [depth] >= N ) { Out [Stack [depth]] = T ++; depth --; continue; }
         if ( Reach [depth] == Left [Stack [depth]] + Son [Stack [depth]] ) { Out [Stack [depth]] = T ++; depth --; continue; }
         Stack [depth + 1] = Reach [depth] ++;
         Reach [++ depth] = Left [Stack [depth]] , In [Stack [depth]] = T ++;
     }
//     for ( int i = 0; i < 10; i++ ) printf ( "%d %d\n" , In [i] , Out [i] );
}

void ConstructTree ()
{
     memset ( Left , 0 , sizeof ( Left ));
     Left [0] = 1;
     for ( int i = 1; i < N; i ++ ) Left [i] = Left [i - 1] + Son [i - 1];
//     for ( int i = 0; i < N;i ++ ) printf ( "%d " , Left [i] ); printf ( "\n" );
}

bool init ()
{
     scanf ( "%d" , &N );
     memset ( Son , 0 , sizeof ( Son ));
     for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &Son [i] );
}

bool check ( int A , int B )
{
}

void solve ()
{
     int   Q , A , B;
     scanf ( "%d" , &Q );
     for ( int i = 0; i < Q; i ++ ) {
         scanf ( "%d%d" , &A , &B );
         if ( In [A] < In [B] && Out [B] < Out [A] ) printf ( "Yes\n" );
         else printf ( "No\n" );
     }
}

// 1684664	2006-03-15 19:45:35	Accepted	2615	C++	00:03.84	238324K	AndyZhau
