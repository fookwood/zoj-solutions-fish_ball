#include <stdio.h>
#include <algorithm>

#define MAXN   300
#define MAXM   30000

using namespace std;

struct TNode {
       TNode * LeftChild , * RightBrother , * Father;
};

struct TElement {
       TNode * Which;
       int   Step;
       bool operator < ( const TElement & B ) const {
            return Step < B.Step;
       }
};

int          N , M , dis [MAXN] [MAXN] , QSize;
TNode        Node [MAXM];
TElement     Queue [MAXN];

bool   init ();
void   print ();
bool   Refresh ( int );
void   push ( TNode * , TNode * );

main ()
{
     int    i;
     while ( init () ) {
           for ( i = 1; i < N; i ++ ) if ( !Refresh ( i ) ) break;
           if ( i >= N ) print ();
           else printf ( "-1\n" );
           printf ( "\n" );
     }
}

void push ( TNode * a , TNode * b )
{
     a->Father = b ,
     a->RightBrother = b->LeftChild ,
     b->LeftChild = a ,
     a->LeftChild = NULL;
}

bool Refresh ( int p )
{
     int     a , b , c , d , i , j;
     TNode   * r;
     QSize = 1 , Queue [0].Which = Node , Queue [0].Step = dis [0] [p];
     for ( i = 1; i < p; i ++ ) {
         a = dis [0] [i] , b = dis [i] [p] , c = dis [0] [p];
         if ( a > b + c || b > a + c || c > a + b || ( a + b + c ) % 2 ) return false;
         d = ( a + b - c ) / 2;
         if ( d == 0 ) return false;
         for ( r = Node + i , j = 0; j < d; j ++ ) r = r->Father;
         Queue [QSize].Which = r , Queue [QSize ++].Step = b - d;
     }
     
     sort ( Queue , Queue + QSize );
     if ( Queue [0].Step == 0 ) return false;
     
     for ( j = 1 , r = Queue [0].Which; j < Queue [0].Step; j ++ , r = r->LeftChild )
         push ( Node + M ++ , r );
     push ( Node + p , r );
     for ( r = Node + p , d = i = 0; i < QSize; i ++ ) {
         for ( ; d < Queue [i].Step; d ++ ) r = r->Father;
         if ( r != Queue [i].Which ) return false;
     }
     for ( r = Node->LeftChild , d = 0; r != NULL; r = r->RightBrother ) d ++;
     return d <= 1;
}

void print ()
{
     printf ( "%d\n" , M );
     TNode * HaveOutPut = Node->LeftChild;
     printf ( "%d %d\n" , 1 , Node->LeftChild - Node + 1 );
     for ( int i = 1; i < M; i ++ )
         if ( Node + i != HaveOutPut ) printf ( "%d %d\n" , i + 1 , Node [i].Father - Node + 1 );
}

bool init ()
{
     if ( scanf ( "%d" , &N ) != 1 ) return false;
     for ( int i = 0; i < N; i ++ )
         for ( int j = 0; j < N; j ++ )
             scanf ( "%d" , &dis [i] [j] );
     memset ( Node , 0 , sizeof ( Node ));
     M = N;
     return true;
}
