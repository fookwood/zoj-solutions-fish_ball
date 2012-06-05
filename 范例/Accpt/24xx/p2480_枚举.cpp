#include <stdio.h>
#define MAXN      20

struct TPoint {
       int    x , y;
};

struct TWindow {
       TPoint  LeftUp , RightDown;
       bool    PointIn ( const TPoint & B ) {
               return B.x >= LeftUp.x && B.x <= RightDown.x && B.y >= LeftUp.y && B.y <= RightDown.y;
       }
};

int    N , M;
TWindow Windows [MAXN];

int     check ( TPoint & );
bool    init ();
void    solve ();

main ()
{
     while ( init () ) {
           solve ();
     }
}

void solve ()
{
     TPoint  Point;
     scanf ( "%d" , &M );
     for ( int i = 0; i < M; i ++ ) {
         scanf ( "%d%d" , &Point.x , &Point.y );
         printf ( "%d\n" , check ( Point ) );
     }
}

bool init ()
{
     scanf ( "%d" , &N );
     if ( N == 0 ) return false;
     for ( int i = 0; i < N; i ++ )
         scanf ( "%d%d%d%d" , &Windows [i].LeftUp.x , &Windows [i].LeftUp.y , &Windows [i].RightDown.x , &Windows [i].RightDown.y );
     return true;
}

int  check ( TPoint &B )
{
     for ( int i = N - 1; i >= 0; i -- )
         if ( Windows [i].PointIn ( B ) ) return i;
     return -1;
}
// 1668049 2006-03-08 19:37:26 Accepted 2480 C++ 00:00.00 436K AndyZhau 
