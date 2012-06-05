#include <stdio.h>
#include <string.h>
#define MAXN 3010
#define Inf  10000
#define Prime  24971
#define HashSize ( 1 << 16 )
using namespace std;

typedef short int  Integer;


int     N , Num [MAXN] , Ans [MAXN] , Len , Left [MAXN];
Integer MaxLong [MAXN] [MAXN];

struct  TNode {
        int   Key , Next;
        Integer Pos;
};

int     Hash [HashSize];
TNode   Node [MAXN];

bool    init ();
void    solve ();
void    print ();
Integer *   find ( int );
Integer *   Insert ( int );

main ()
{
     bool    first = true;
     while ( init () ) {
           if ( first ) first = false; else printf ( "\n" );
           solve ();
           print ();
     }
}

Integer * Insert ( int K )
{
        int p = K & ( HashSize - 1 ) , q;
        for ( q = Hash [p]; q != -1; q = Node [q].Next ) if ( Node [q].Key == K ) return & Node [q].Pos;
        Node [Len].Key = K , Node [Len].Next = Hash [p] , Hash [p] = Len ++;
        return & Node [Len - 1].Pos;
}

Integer * find ( int K )
{
        int p = K & ( HashSize - 1 ) , q;
        for ( q = Hash [p]; q != -1; q = Node [q].Next ) if ( Node [q].Key == K ) return & Node [q].Pos;
        return NULL;
}

void solve ()
{
     if ( N < 3 ) return;
     
     int  i , j;
     Integer * p;
     Len = 0;
     memset ( Hash , 0xff , sizeof ( Hash ));
     
     /*for ( i = 0; i < N; i ++ ) {
         for ( j = i - 1; j >= 0; j -- ) if ( Num [i] == Num [j] ) break;
         Left [i] = j;
     }*/
     for ( i = 0; i < N; i ++ ) for ( j = i + 1; j < N; j ++ ) MaxLong [i] [j] = 2;
     
     for ( i = 0; i + 1 < N; i ++ ) {
         if ( i ) *Insert ( Num [i - 1] ) = i - 1;
         
         for ( j = i + 1; j < N; j ++ ) {
//             if ( Num [i] && Left [j] > i ) continue;
             p = find ( Num [j] - Num [i] );
             MaxLong [i] [j] = ( p == NULL ? 2 : MaxLong [*p] [i] + 1 );
         }
     }
     
/*     for ( int i = 0; i < N; i ++ ) {
         for ( int j = 0; j < N; j ++ ) printf ( "%d " , MaxLong [i] [j] ); printf ( "\n" );
     }
*/
}

bool init ()
{
     if ( scanf ( "%d" , &N ) == EOF ) return false;
     for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &Num [i] );
     return true;
}

void print ()
{
     if ( N < 3 ) {
          printf ( "%d\n" , N );
          for ( int i = 0; i < N; i ++ ) {
              if ( i ) printf ( " " );
              printf ( "%d" , Num [i] );
          }
          return;
     }
     int  a = 0 , b = 1 , l;
     for ( int i = 0; i < N; i ++ )
         for ( int j = i + 1; j < N; j ++ ) if ( MaxLong [i] [j] > MaxLong [a] [b] ) a = i , b = j;
         
     l = MaxLong [a] [b];
     
     printf ( "%d\n" , l );
     Ans [l - 1] = Num [b] , Ans [l - 2] = Num [a];
     for ( int i = l - 3; i >= 0; i -- ) Ans [i] = Ans [i + 2] - Ans [i + 1];
     for ( int i = 0; i < l; i ++ ) {
         if ( i ) printf ( " " );
         printf ( "%d" , Ans [i] );
     }
     printf ( "\n" );
}
