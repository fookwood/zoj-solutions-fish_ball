#include <stdio.h>
#include <math.h>
#include <list>

using namespace std;

typedef long long int64;

struct TNode {
       int64 current;
       int   many;
};

typedef list<TNode> TList;
typedef TList :: iterator TIter;

TList   List;

int     N , M;
int64   Sum;

bool    init ();
void    solve ();
void    print ();
TIter   find ( int );
int64   lowdiv ( int64 , int64 );
int64   highdiv ( int64 , int64 );

main()
{
      while ( init () ) {
            solve ();
            print ();
            printf ( "\n" );
      }
}

TIter find ( int k )
{
      int  p = 0;
      TIter Iter;
      
      for ( Iter = List.begin (); ; Iter ++ ) {
          p += Iter->many;
          if ( p >= k ) break;
      }
      if ( Iter->many == 1 ) return Iter;
      TNode  Ins;
      if ( p - Iter->many + 1 != k ) {
         Ins.current = Iter->current , Ins.many = Iter->many + k - p - 1 , Iter->many -= Ins.many;
         List.insert ( Iter , Ins );
      }
      
      if ( Iter->many == 1 ) return Iter;
      Ins.current = Iter->current , Ins.many = 1 , Iter->many --;
      Iter = List.insert ( Iter , Ins );
      return Iter;
}

void  print ()
{
      bool  first = true;
      TList :: iterator Iter;
      for ( Iter = List.begin (); Iter != List.end (); Iter ++ )
          for ( int i = 0; i < Iter->many; i ++ ) {
              if ( first ) first = false; else printf ( " " );
              printf ( "%lld" , Iter->current );
          }
      printf ( "\n" );
}

void  solve ()
{
      int   a , b;
      int64 CurrentSum = Sum , S , avg;
      
      TNode P;
      TList :: iterator Iter1 , Iter2 , Iter;
      
      for ( int i = 0; i < M; i ++ ) {
          scanf ( "%d %d" , &a , &b );
          Iter1 = find ( a ) , Iter2 = find ( b ) , Iter2 ++;
          
          for ( Iter = Iter1 , S = 0; Iter != Iter2; Iter ++ )
              S += Iter->many * Iter->current;
          
          avg = CurrentSum <= Sum ? highdiv ( S , b - a + 1 ) : lowdiv ( S , b - a + 1 );
          
          CurrentSum += avg * ( b - a + 1 ) - S;
          
          Iter1->current = avg , Iter1->many = b - a + 1 , Iter1 ++;
          
          for ( Iter = Iter1; Iter != Iter2; Iter = Iter1 )
              Iter1 = Iter , Iter1 ++ , List.erase ( Iter );
      }
}

int64 lowdiv ( int64 a , int64 b )
{
      if ( a >= 0 ) return a / b;
      else return ( a - b + 1 ) / b;
}

int64 highdiv ( int64 a , int64 b )
{
      if ( a >= 0 ) return ( a + b - 1 ) / b;
      else return a / b;
}

bool  init ()
{
      if ( scanf ( "%d%d" , &N , &M ) != 2 ) return false;
      TNode P;
      P.many = 1 , Sum = 0;
      List.clear ();
      for ( int i = 0; i < N; i ++ )
          scanf ( "%lld" , &P.current ) , List.push_back ( P ) , Sum += P.current;
      return true;
}
