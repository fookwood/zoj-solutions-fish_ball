#include <stdio.h>
#include <algorithm>
#define MAXN      1020
#define eps       1e-8

int     N;
double  W [MAXN] , Max;

main ()
{
     int total , i;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         scanf ( "%d" , &N );
         Max = 0;
         for ( i = 0; i < N; i ++ ) scanf ( "%lf" , & W [i] );
         std :: sort ( W , W + N );
         for ( i = 0; i < N; i ++ )
             if ( W [i] * ( N - i ) > Max ) Max = W [i] * ( N - i );
         printf ( "%.lf\n" , Max + eps );
     }
}
// 1668311 2006-03-08 20:58:26 Accepted 2488 C++ 00:00.00 444K AndyZhau 
