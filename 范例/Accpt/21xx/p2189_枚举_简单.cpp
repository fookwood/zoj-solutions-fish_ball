#include <stdio.h>
#define  min(a,b) (a<b?a:b)
int      A , B , C , D , Money;

bool  find ()
{
      int  T , j , k , l;
      for ( int i = A; i >= 0; i -- ) {
          T = Money - i * 25;
          if ( T < 0 ) continue;
          j = min ( T / 10 , B ) , T -= j * 10;
          k = min ( T / 5 , C ) , T -= k * 5;
          l = min ( T , D ) , T -= l;
          if ( T ) continue;
          printf ( "%d %d %d %d\n" , i , j , k , l );
          return true;
      }
      return false;
}

main ()
{
     double  T;
     while ( scanf ( "%lf%d%d%d%d" , &T , &A , &B , &C , &D ) != EOF ) {
           Money = int ( T * 100 + 0.1 );
           if ( !find () ) printf ( "NO EXACT CHANGE\n" );
     }
}
