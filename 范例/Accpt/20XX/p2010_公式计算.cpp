#include <stdio.h>
#include <math.h>
#define  pi      acos ( -1 )
#include <algorithm>

using namespace std;

bool  TryPut ( int a , int b , int x , int y )
{
      double l = sqrt ( (double)x * x + y * y ) , alfa1 , alfa2 , l2;
      if ( l <= b ) alfa1 = 0; else alfa1 = acos ( b / l );
      alfa2 = atan ( (double)y / x ) + alfa1;
      if ( alfa2 > pi / 2 ) return false;
      l2 = x * sin ( alfa2 ) + y * cos ( alfa2 );
      return l2 < a + 1e-10;
}

bool  check ( int A , int B , int X , int Y )
{
      if ( A >= X && B >= Y ) return true;
      if ( A < X && B < Y ) return false;
      return  TryPut ( A , B , X , Y );
}

main ()
{
     int Total , A , B , X , Y;
     for ( scanf ( "%d" , &Total ); Total; Total -- ) {
         scanf ( "%d%d%d%d" , &A , &B , &X , &Y );
         if ( A < B ) swap ( A , B );
         if ( X < Y ) swap ( X , Y );
         if ( check ( A , B , X , Y ) ) printf ( "Escape is possible.\n" );
            else printf ( "Box cannot be dropped.\n" );
     }
}
