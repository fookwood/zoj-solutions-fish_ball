#include <stdio.h>
#include <algorithm>

#define  MAXN       120

using namespace std;

int   N , K , Father [MAXN] , Son [MAXN] , Cut , Prepare [MAXN] , PreSize , Dep [MAXN];
bool  mark [MAXN];

bool  init ();
void  solve ();
bool  cmp ( const int & , const int & );
int   Search ( int );

main ()
{
     while ( init () )
           solve ();
}

int Search ( int p )
{
    if ( Dep [p] != -1 ) return Dep [p];
    if ( Father [p] ) Dep [p] = Search ( Father [p] ) + 1;
    else Dep [p] = 1;
    return Dep [p];
}

bool cmp ( const int & a , const int &b )
{
     return Dep [a] > Dep [b];
}

void solve ()
{
     for ( int i = 1; i <= N; i ++ ) if ( Dep [i] == -1 ) Search ( i );
     
     memset ( mark , 0 , sizeof ( mark ));
     for ( Cut = 0 ;; Cut ++ ) {
         PreSize = 0;
         for ( int i = 1; i <= N; i ++ ) if ( !mark [i] && Son [i] == 0 )
             Prepare [PreSize ++] = i;
         if ( PreSize == 0 ) break;
         sort ( Prepare , Prepare + PreSize , cmp );
         for ( int i = 0; i < K && i < PreSize; i ++ )
             mark [Prepare [i]] = true , Son [Father [Prepare [i]]] --;
     }
     printf ( "%d\n" , Cut );
}

bool init ()
{
     scanf ( "%d%d" , &N , &K );
     if ( N == 0 && K == 0 ) return false;
     memset ( Son , 0 , sizeof ( Son ));
     memset ( Father , 0 , sizeof ( Father ));
     memset ( Dep , 0xff , sizeof ( Dep ));
     int    a , b;
     for ( int i = 1; i < N; i ++ ) {
         scanf ( "%d%d" , &a , &b );
         Father [a] = b;
         Son [b] ++;
     }
     return true;
}
