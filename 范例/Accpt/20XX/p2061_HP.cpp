#include <stdio.h>

struct   HP {
         int len , s [600];
         void  operator *= ( const int b );
         HP () { len = 1 , s [0] = 1; }
         void         print ();
};

void  HP :: operator *= ( const int b ) 
{
      int    i , j;
      for ( i = j = 0; i < len; i ++ , j /= 10 )
          j += s [i] * b , s [i] = j % 10;
      while ( j > 0 ) s [len ++] = j % 10 , j /= 10;
}

void  HP :: print ()
{
      for ( int i = len - 1; i >= 0; i -- ) printf ( "%d" , s [i] );
      printf ( "\n" );
}

main ()
{
     int     N , M , step = 0;
     while ( scanf ( "%d%d" , &N , &M ) , N || M ) {
           printf ( "Test #%d:\n" , ++step );
           if ( N < M ) {
                printf ( "0\n" );
                continue;
           }
           HP   Ans;
           for ( int i = 2; i <= N + M; i ++ ) if ( i != N + 1 ) Ans *= i;
           if ( M ) Ans *= ( N - M + 1 );
           Ans.print ();
     }
}
