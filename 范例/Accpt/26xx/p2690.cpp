#include <stdio.h>
#include <algorithm>
#define MAXN      100010

using namespace std;

int   N , M , X [MAXN] , Y [MAXN] , c , C , Min , Max;

bool  init ();
bool  check ();

main ()
{
     while ( init () ) {
           if ( !check ()) printf ( "Impossible\n" );
     }
}

bool check ()
{
     if ( X [N - 1] != Y [M - 1] ) return false;
     int  i , j , ti , tj , sum;
     
     for ( i = j = Max = sum = 0; i < N; i ++ ) {
         for ( ; j < M && Y [j] < X [i]; j ++ ) sum += Y [j];
         Max += ( M - j ) * X [i] + sum;
     }
     Max *= C;
     
     Min = 0;
     for ( i = N - 1 , j = M - 1; i >= 0; i -- ) {
         for ( ; j >= 0 && Y [j] > X [i]; j -- ) Min += Y [j];
         if ( X [i] == Y [j] ) j --;
         Min += X [i];
     }
     for ( ; j >= 0; j -- ) Min += Y [j];
     Min *= c;
     
     printf ( "Minimum: %d, maximum: %d\n" , Min , Max );
     return true;
}

bool init ()
{
     scanf ( "%d%d" , &N , &M );
     if ( N == 0 && M == 0 ) return false;
     scanf ( "%d%d" , &c , &C );
     for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &X [i] );
     for ( int j = 0; j < M; j ++ ) scanf ( "%d" , &Y [j] );
     sort ( X , X + N );
     sort ( Y , Y + M );
     return true;
}

