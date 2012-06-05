#include <stdio.h>
#include <math.h>
#define  Inf      1e20

int      L , N , D;
double   A;

double f ( int N , int D );

main ()
{
     int       i , j;
     double    min;
     while ( scanf ( "%lf%d" , &A , &L ) != EOF ) {
           min = Inf;
           for ( i = 1; i <= L; i ++ ) {
               j = int ( i / A );
               if ( j == 0 ) j = 1;
               if ( j > L ) j = L;
               if ( f ( i , j ) < min )
                  min = f ( i , j ) , N = i , D = j;
               if ( f ( i , j + 1 ) < min )
                  min = f ( i , j + 1 ) , N = i , D = j + 1;
           }
           printf ( "%d %d\n" , N , D );
     }
}

double f ( int N , int D )
{
       if ( N > L || D > L ) return Inf;
       if ( D == 0 ) return Inf;
       return fabs ( A - (double) N / D );
}
