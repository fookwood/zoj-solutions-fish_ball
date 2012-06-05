#include <stdio.h>
#include <math.h>
#include <algorithm>

#define MAXN 210
#define sqr(a) ((a)*(a))
#define eps    1e-8

using namespace std;

struct TPoint {
       double x , y;
       void   init () { scanf ( "%lf%lf" , &x , &y ); }
       double distance ( TPoint & );
};

struct TLine {
       TPoint A , B;
       double distance ( TPoint & );
       void init () { A.init () , B.init (); }
};

struct TInfo {
       TPoint Point;
       double cost [2] , value;
       void   init ();
};

int    N , C , Pre [MAXN] [MAXN];
TLine  L , R;
TInfo  Info [MAXN];
double f [MAXN] [MAXN];

bool   init ();
void   solve ();

main ()
{
     while ( init () ) {
           solve ();
     }
}

void solve ()
{
     memset ( f , 0 , sizeof ( f ));
     
     for ( int i = N - 1; i >= 0; i -- )
         for ( int j = 0; j <= N - i; j ++ )
             if ( j == 0 ) f [i] [j] = f [i + 1] [j] + Info [i].cost [1] , Pre [i] [j] = 2;
             else if ( j == N - i ) f [i] [j] = f [i + 1] [j - 1] + Info [i].cost [0] , Pre [i] [j] = 1;
             else if ( f [i + 1] [j] + Info [i].cost [1] < f [i + 1] [j - 1] + Info [i].cost [0] )
                  f [i] [j] = f [i + 1] [j] + Info [i].cost [1] , Pre [i] [j] = 2;
                  else f [i] [j] = f [i + 1] [j - 1] + Info [i].cost [0] , Pre [i] [j] = 1;
     
     double Min = 1e20;
     int    p;
     for ( int i = 0; i <= N; i ++ )
         if ( abs ( N - i - i ) <= C )
            if ( f [0] [i] < Min ) Min = f [0] [i] , p = i;
     
     for ( int i = 0; i < N; i ++ ) {
         if ( i ) printf ( " " );
         if ( Pre [i] [p] == 1 ) printf ( "1" ) , p --;
         else printf ( "2" );
     }
     if ( p ) for (;; );
     printf ( "\n\n" );
}

bool init ()
{
     if ( scanf ( "%d%d" , &N , &C ) != 2 ) return false;
     L.init () , R.init ();
     for ( int i = 0; i < N; i ++ )
         Info [i].init ();
     return true;
}

double TLine :: distance ( TPoint & P )
{
       double Min , l;
       l = A.distance ( B );
       Min = fabs ( ( A.x - P.x ) * ( B.y - P.y ) - ( A.y - P.y ) * ( B.x - P.x ) );
       return Min / l;
}

double TPoint :: distance ( TPoint & P )
{
       return sqrt ( sqr ( x - P.x ) + sqr ( y - P.y ) );
}

void TInfo :: init ()
{
     Point.init ();
     scanf ( "%lf" , &value );
     cost [0] = L.distance ( Point ) * value;
     cost [1] = R.distance ( Point ) * value;
}
