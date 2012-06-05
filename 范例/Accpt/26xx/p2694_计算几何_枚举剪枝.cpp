#include <stdio.h>
#include <math.h>
#include <algorithm>

#define MAXN 40010
#define eps  1e-8
#define sqr(a) ((a)*(a))

using namespace std;

struct TPoint {
       double  x , y;
       double  distance ( TPoint & );
};

struct TCircle {
       TPoint  Mid;
       double  r;
       bool    visible;
       void    init () { scanf ( "%lf%lf%lf" , &r , &Mid.x , &Mid.y ); }
};

int            N , Rad [MAXN] , Pos [MAXN] , Sum;
TCircle        Circle [MAXN];

bool   init ();
void   solve ();
bool   cmp_rad ( const int & , const int & );
bool   cmp_pos ( const int & , const int & );
void   print ();

main ()
{
     while ( init () ) {
           solve ();
           print ();
     }
}

void print ()
{
     bool  first = true;
     printf ( "%d\n" , Sum );
     for ( int i = 0; i < N; i ++ ) if ( Circle [i].visible ) {
         if ( first ) first = false; else printf ( " " );
         printf ( "%d" , i + 1 );
     }
     printf ( "\n" );
}

bool cmp_pos ( const int & a , const int & b )
{
     return Circle [a].Mid.x < Circle [b].Mid.x;
}

bool cmp_rad ( const int & a , const int & b )
{
     return Circle [a].r > Circle [b].r;
}

void solve ()
{
     for ( int i = 0; i < N; i ++ ) Rad [i] = Pos [i] = i , Circle [i].visible = true;
     sort ( Rad , Rad + N , cmp_rad );
     sort ( Pos , Pos + N , cmp_pos );
     
     int low , high , mid , l1 , l2;
     double Key;
     
     for ( int i = Sum = 0; i < N; i ++ ) if ( Circle [Rad [i]].visible ) {
         Key = Circle [Rad [i]].Mid.x - Circle [Rad [i]].r;
         
         for ( low = -1 , high = N - 1; low + 1 < high; ) {
             mid = ( low + high ) >> 1;
             if ( Circle [Pos [mid]].Mid.x <= Key - eps ) low = mid;
             else high = mid;
         }
         l1 = high;
         
         Key = Circle [Rad [i]].Mid.x + Circle [Rad [i]].r;
         for ( low = 0 , high = N; low + 1 < high; ) {
             mid = ( low + high ) >> 1;
             if ( Circle [Pos [mid]].Mid.x <= Key + eps ) low = mid;
             else high = mid;
         }
         l2 = low;
         
         for ( int j = l1; j <= l2; j ++ )
             if ( Pos [j] != Rad [i] && Circle [Pos [j]].Mid.distance ( Circle [Rad [i]].Mid ) <= Circle [Rad [i]].r + eps )
                Circle [Pos [j]].visible = false;
         
         Sum ++;
     }
}

double TPoint :: distance ( TPoint & B )
{
       return sqrt ( sqr ( x - B.x ) + sqr ( y - B.y ));
}

bool   init ()
{
       scanf ( "%d" , &N ); if ( N == 0 ) return false;
       for ( int i = 0; i < N; i ++ )
           Circle [i].init ();
       return true;
}
