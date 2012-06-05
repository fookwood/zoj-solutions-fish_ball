#include <stdio.h>
#include <math.h>
#include <set>
#define eps   1e-8
//#define MAXN  50010
using namespace std;

int  N;
double sumx , sumy;

struct TPos {
       double  x , y;
       bool operator < ( const TPos & B ) const {
            return fabs ( x - B.x ) < eps ? y < B.y : x < B.x;
       }
       bool operator == ( const TPos & B ) const {
            return fabs ( x - B.x ) < eps && fabs ( y - B.y ) < eps;
       }
};

typedef set <TPos> TSet;

TSet Set;
bool init ();
bool check ();

main ()
{
     while ( init () )
           if ( !check () ) printf ( "This is a dangerous situation!\n" );
}

bool check ()
{
     if ( Set.size () != N ) for ( ;1; );
     TSet :: iterator Iter , Iter2;
     TPos Pos;
/*     if ( N & 1 ) {
          for ( Iter = Set.begin (); Iter != Set.end (); Iter ++ ) {
              Iter2 = Iter; Iter2 ++; if ( Iter2 == Set.end ()) break;
              if (!( (*Iter) == (*Iter2 ))) return false;
          }
          return true;
     }
*/
     for ( Iter = Set.begin (); Iter != Set.end (); Iter ++ ) {
         Pos.x = sumx - Iter->x , Pos.y = sumy - Iter->y;
         if ( Set.find ( Pos ) == Set.end () ) return false;
     }     
     printf ( "V.I.P. should stay at (%.1lf,%.1lf).\n" , sumx / 2.0 , sumy / 2.0 );
     return true;
}

bool init ()
{
     scanf ( "%d" , &N );
     if ( N == 0 ) return false;
     TPos  Pos;
     double sx = 0 , sy = 0 , x , y;
     Set.clear ();
     for ( int i = 0; i < N; i ++ ) {
         scanf ( "%lf%lf" , &Pos.x , &Pos.y ) , 
         sx += Pos.x , sy += Pos.y;
         Set.insert ( Pos );
     }
     sumx = sx / N * 2;
     sumy = sy / N * 2;
     return true;
}
