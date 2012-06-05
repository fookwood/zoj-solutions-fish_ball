#include <stdio.h>
#include <algorithm>

#define MaxLen    15
#define Base      10000000

using namespace std;

struct HP {
       int len , s [MaxLen];
       HP () { len = 1 , s [0] = 0; }
       void operator += ( const HP & );
       void print ();
};

int    N;
HP     f [64] [64] [64] , Ans [61];

void   solve ();

main ()
{
     for ( ; scanf ( "%d" , &N ) == 1; ) {
         if ( N == 0 ) {
              printf ( "0\n\n" );
              continue;
         }
         solve ();
         printf ( "\n" );
     }
}

void solve ()
{
     int   i , j , k;
     for ( i = 0; i <= N; i ++ )
         for ( j = 0; j <= N; j ++ )
             for ( k = 0; k <= N; k ++ ) f [i] [j] [k].len = 1 , f [i] [j] [k].s [0] = 0;
     
     f [0] [0] [0].len = 1 , f [0] [0] [0].s [0] = 1;

     for ( int p = 0; p < N + N + N; p ++ ) {
         for ( i = min ( p , N ); i >= 0; i -- )
             for ( j = i; j >= 0; j -- ) {
                 k = p - i - j;
                 if ( k <= j && k >= 0 )
                    if ( f [i] [j] [k].len > 1 || f [i] [j] [k].s [0] ) {
                         f [i + 1] [j] [k] += f [i] [j] [k];
                         if ( i >= j + 1 ) f [i] [j + 1] [k] += f [i] [j] [k];
                         if ( j >= k + 1 ) f [i] [j] [k + 1] += f [i] [j] [k];
                    }
             }
     }
//     Ans [N] = f [N] [N] [N];
     f [N] [N] [N].print ();
}

void HP :: operator += ( const HP & B )
{
      int i , j;
      for ( i = j = 0; i < len || i < B.len; i ++ ) {
          if ( i < len ) j += s [i];
          if ( i < B.len ) j += B.s [i];
          s [i] = j % Base , j /= Base;
      }
      for ( ; j; j /= Base ) s [i ++] = j % Base;
      for ( len = i; len > 1 && s [len - 1] == 0; len -- );
}

void HP :: print ()
{
     printf ( "%d" , s [len - 1] );
     for ( int i = len - 2; i >= 0; i -- ) printf ( "%07d" , s [i] );
     printf ( "\n" );
}
