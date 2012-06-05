#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

#define sqr(a) ((a)*(a))
#define eps    1e-8
#define MAXN 120

using namespace std;

struct TPoint {
       double x , y , m;
       TPoint operator * ( const TPoint & );
       double distance ( TPoint & );
       void init () { scanf ( "%lf%lf" , &x , &y ) , m = 1.0; }
};

struct TLine {
       TPoint A , B;
       TPoint operator + ( TLine & );
       void init () { A.init (), B.init (); }
};

int    N;
TLine  Line [MAXN];

bool   init ();
void   solve ();

main ()
{
     int p = 0;
     while ( init () ) {
           printf ( "Map %d\n" , ++ p );
           solve ();
     }
}

void solve ()
{
     int Tot = 0 , dSize;
     double dis [MAXN] , l1 , l2 , l;
     
     TPoint Int;
     
     for ( int i = 0; i < N; i ++ ) {
         dSize = 2 , dis [0] = 0.0 , dis [1] = l = Line [i].A.distance ( Line [i].B ) , dis [0] -= 25.0 , dis [1] += 25.0;
         
         for ( int j = 0; j < N; j ++ ) if ( i != j ){
             Int = Line [i] + Line [j];
             if ( fabs ( Int.m ) <= eps ) continue;
             
             l1 = Line [j].A.distance ( Int ) , l2 = Line [j].B.distance ( Int );
             if ( fabs ( Line [j].A.distance ( Line [j].B ) - l1 - l2 ) >= eps ) continue;
             
             l1 = Line [i].A.distance ( Int ) , l2 = Line [i].B.distance ( Int );
             if ( fabs ( l - l1 - l2 ) >= eps ) continue;
             dis [dSize ++] = l1;
         }
         sort ( dis , dis + dSize );
         for ( int j = 0; j + 1 < dSize; j ++ )
             Tot += int ( ( dis [j + 1] - dis [j] ) / 50.0 + eps );
     }
     printf ( "Trees = %d\n" , Tot );
}

bool init ()
{
     scanf ( "%d" , &N ); if ( N == 0 ) return false;
     for ( int i = 0; i < N; i ++ ) Line [i].init ();
     return true;
}

TPoint TLine :: operator + ( TLine & T )
{
       return (A * B) * (T.A * T.B);
}

TPoint TPoint :: operator * ( const TPoint & B )
{
       TPoint Ret;
       Ret.x = y * B.m - m * B.y;
       Ret.y = m * B.x - x * B.m;
       Ret.m = x * B.y - y * B.x;
       return Ret;
}


double TPoint :: distance ( TPoint & B )
{
       return sqrt ( sqr ( x / m - B.x / B.m ) + sqr ( y / m - B.y / B.m ));
}
