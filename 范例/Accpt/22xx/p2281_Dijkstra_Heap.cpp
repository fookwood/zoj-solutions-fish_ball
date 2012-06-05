#include <stdio.h>
#include <vector>
#define  min(a,b) (a<b?a:b)
#define  Inf     0x7fffffff
#define  MAXN    100000
using    namespace std;

int      N , M , Start , Finish , Max [MAXN] , Heap [MAXN] , HeapSize , Cd [MAXN];

struct  TNode {
        int contact , value;
};

vector <TNode> Edge [MAXN];

bool   init ()
{
       if ( scanf ( "%d%d" , &N , &M ) == EOF ) return false;
       for ( int i = 0; i < N;i ++ ) Edge [i].clear ();
       int d = 0;
       int a , b , c;
       TNode T;
       for ( int i = 0; i < M; i ++ ) {
           scanf ( "%d%d%d" , &a , &b , &c ) , a -- , b --;
           T.value = c;
           T.contact = b , Edge [a].push_back ( T );
           T.contact = a , Edge [b].push_back ( T );
       }
       scanf ( "%d%d" , &Start , &Finish ) , Start -- , Finish --;
       return true;
}

void   FlyUp ( int k )
{
       int q = k , p = ( k - 1 ) / 2 , Key = Max [Heap [k]] , x = Heap [k];
       while ( q ) {
             if ( Max [Heap [p]] >= Key ) break;
             Heap [q] = Heap [p] , Cd [Heap [q]] = q;
             q = p , p = ( q - 1 ) / 2;
       }
       Heap [q] = x , Cd [x] = q;
}

void   GoDown ()
{
       int p = 0 , q = 1 , Key = Max [Heap [0]] , x = Heap [0];
       while ( q < HeapSize ) {
             if ( q + 1 < HeapSize && Max [Heap [q + 1]] > Max [Heap [q]] ) q ++;
             if ( Max [Heap [q]] <= Key ) break;
             Heap [p] = Heap [q] , Cd [Heap [p]] = p;
             p = q , q = p * 2 + 1;
       }
       Heap [p] = x , Cd [x] = p;
}


int    MinAns ()
{
       for ( int i = 0; i < N; i ++ ) Max [i] = -1;
       HeapSize = 1 , Heap [0] = Start , Cd [Start] = 0 , Max [Start] = Inf;
       int     k , d , t;
       vector <TNode> :: iterator Iter;
       while ( true ) {
             if ( HeapSize == 0 ) return 0;
             k = Heap [0] , Heap [0] = Heap [-- HeapSize] , GoDown ();
             if ( k == Finish ) return Max [k];
             for ( Iter = Edge [k].begin (); Iter != Edge [k].end (); Iter ++ ) {
                 t = min ( Max [k] , Iter->value );
                 d = Iter->contact;
                 if ( Max [d] == -1 ) Cd [d] = HeapSize , Heap [HeapSize ++] = d;
                 if ( t > Max [d] ) Max [d] = t , FlyUp ( Cd [d] );
             }
       }
}

main ()
{
     while ( init () )
           printf ( "%d\n" , MinAns () );
}
