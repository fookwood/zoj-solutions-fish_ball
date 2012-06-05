#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAXN      1200

using namespace std;

struct TPos {
       int  x , y;
       bool operator < ( const TPos & B ) const {
            int      t = x * B.y - y * B.x;
            return  t == 0 ? x * x + y * y < B.x * B.x + B.y * B.y : t > 0;
       }
       bool operator != ( const TPos & B ) const {
            return x != B.x || y != B.y;
       }
       void init () { scanf ( "%d%d" , &x , &y ); }
};

typedef vector <TPos> TConvex;

int     N;
TPos    Point [MAXN];
TConvex Convex;

void    init ();
bool    check ();
int     mul ( int , int , int , int );
bool    HaveMid ( TPos & , TPos & );

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         if ( check () ) printf ( "YES\n" );
         else printf ( "NO\n" );
     }
}

void init ()
{
     scanf ( "%d" , &N );
     for ( int i = 0; i < N; i ++ ) Point [i].init ();
     int i , j;
     for ( int i = j = 0; i < N; i ++ ) if ( Point [i].y == Point [j].y && Point [i].x < Point [j].x || Point [i].y < Point [j].y ) j = i;
     for ( int i = 0; i < N; i ++ ) if ( i != j ) Point [i].x -= Point [j].x , Point [i].y -= Point [j].y;
     Point [j].x = Point [j].y = 0;
}

bool check ()
{
     if ( N < 6 ) return false;
     Convex.clear ();
     sort ( Point , Point + N );
     Convex.push_back ( Point [0] ) , Convex.push_back ( Point [1] );
     int  len , j , k;
     for ( int i = 2; i < N; i ++ ) {
         for ( ;; ) {
             len = Convex.size ();
             if ( len == 1 ) break;
             j = len - 2 , k = len - 1;
             if ( mul ( Point [i].x - Convex [k].x , Point [i].y - Convex [k].y , 
               Convex [j].x - Convex [k].x , Convex [j].y - Convex [k].y ) > 0 ) break;
             Convex.pop_back ();
         }
         Convex.push_back ( Point [i] );
     }
     len = Convex.size (); Convex.push_back ( Convex [0] );
     if ( len <= 2 ) return false;
     for ( int i = 0; i < len; i ++ )
         if ( !HaveMid ( Convex [i] , Convex [i + 1] ) ) return false;
     return true;
}

int  mul ( int a , int b , int c , int d )
{
     return a * d - b * c;
}

bool HaveMid ( TPos & A , TPos & B )
{
     for ( int i = 0; i < N; i ++ ) if ( Point [i] != A && Point [i] != B )
         if ( mul ( A.x - Point [i].x , A.y - Point [i].y , B.x - Point [i].x , B.y - Point [i].y ) == 0 ) return true;
     return false;
}
