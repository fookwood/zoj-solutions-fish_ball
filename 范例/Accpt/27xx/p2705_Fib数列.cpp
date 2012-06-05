#include <iostream>
#define  Limit     1000000001 
#define  MAXN      100000
using namespace std;

typedef long long int64;

int     N;
int64   f [MAXN] , a , b;

void    first ();
int64   check ();

main ()
{
     first ();
     while ( cin >> a >> b )
           cout << check () << endl << endl;
}

int64 check ()
{
      int64 Ret = 0 , t , Tot = a * b;
      for ( int i = 0; i < N; i ++ ) {
          if ( a % ( f [i] + f [i + 1] ) == 0 ) {
               t = Tot - b * a / ( f [i] + f [i + 1] );
               if ( t > Ret ) Ret = t;
          }
          if ( b % ( f [i] + f [i + 1] ) == 0 ) {
               t = Tot - a * b / ( f [i] + f [i + 1] );
               if ( t > Ret ) Ret = t;
          }
      }
      return Ret;
}

void first ()
{
     int   i;
     f [0] = f [1] = 1;
     for ( i = 2; ; i ++ ) {
         f [i] = f [i - 2] + f [i - 1];
         if ( f [i] > Limit ) break;
     }
     N = i;
}
