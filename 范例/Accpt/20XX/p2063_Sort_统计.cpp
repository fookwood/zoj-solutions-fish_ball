#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>

using    namespace  std;

map <string , int> Dic;
map <string , int> :: iterator Iter;

int N , Limit , len;
struct TNode {
       bool  Start;
       int   Time , W;
}      Data [50000];

int    Wast [50000] , MaxTime;

void  init_dic ()
{
      int      N , i , Cost;
      char     Str [100] , t;
      Dic.clear ();
      for ( scanf ( "%d\n" , &N ) , i = 0; i < N; i ++ )
          scanf ( "%[^]]%c%d\n" , Str , &t , &Cost ) , Dic [(string) Str] = Cost;
}

bool  init ()
{
      if ( scanf ( "%d%d\n" , &N , &Limit ) == EOF ) return false;
      char Str [100] , Tmp;
      int  StartTime , FinishTime;
      memset ( Wast , 0 , sizeof ( Wast )); MaxTime = 0;
      for ( int i = len = 0; i < N; i ++ ) {
          scanf ( "%[^]]%c%d%d\n" , Str , &Tmp , &StartTime , &FinishTime );
          Iter = Dic.find ( (string) Str );
          Data [len].Start = true , Data [len].Time = StartTime , Data [len ++].W = Iter->second;
          Data [len].Start = false , Data [len].Time = FinishTime , Data [len ++].W = Iter->second;
          Wast [StartTime] += Iter->second;
          Wast [FinishTime] -= Iter->second;
          if ( FinishTime > MaxTime ) MaxTime = FinishTime;
      }
      return true;
}

bool  cmp ( const TNode & a , const TNode & b )
{
      return a.Time == b.Time ? !a.Start && b.Start : a.Time < b.Time;
}

void  Work2 ()
{
      int   i , Max = 0;
      for ( i = 1; i <= MaxTime; i ++ ) Wast [i] += Wast [i - 1];
      for ( i = 0; i <= MaxTime; i ++ ) if ( Wast [i] > Limit ) {
          printf ( "The power will be out at time %d because the power is %d Watts and overloaded.\n" , i , Wast [i] );
          return;
      } else
      if ( Wast [i] > Max ) Max = Wast [i];
      printf ( "The maximum power needed is %d Watts.\n" , Max );
}

void  Work1 ()
{
      sort ( Data , Data + len , cmp );
      int  Max = 0;
      int  i , j , Ag = 0;
      for ( i = 0; i < len; i = j ) {
          for ( j = i; j < len && Data [i].Time == Data [j].Time; j ++ )
              if ( Data [j].Start ) Ag += Data [j].W;
              else Ag -= Data [j].W;
          if ( Ag > Limit ) {
               printf ( "The power will be out at time %d because the power is %d Watts and overloaded.\n" , Data [i].Time , Ag );
               return;
          }
          if ( Ag > Max ) Max = Ag;
      }
      printf ( "The maximum power needed is %d Watts.\n" , Max );
}

main ()
{
     init_dic ();
     while ( init () ) Work1 (); // Work2 ();
}
