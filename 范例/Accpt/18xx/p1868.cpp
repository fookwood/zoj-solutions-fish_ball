#include <stdio.h>
#include <math.h>
#define  pi      acos ( -1 )

int      N;
double   J [1000] , W [1000] , Dis [1000] , X [1000] , Y [1000] , Z [1000];

main ()
{
 int i , j;
 double  t;
 
 while ( scanf ( "%d" , &N ) != EOF ) {
       for ( i = 0; i < N; i ++ ) scanf ( "%lf%lf" , &W [i] , &J [i] );
       
       for ( i = 0; i < N; i ++ ) Dis [i] = 0 , 
           Z [i] = sin ( W [i] * pi / 180 ) , 
           X [i] = cos ( W [i] * pi / 180 ) * sin ( J [i] * pi / 180 ) , 
           Y [i] = cos ( W [i] * pi / 180 ) * cos ( J [i] * pi / 180 );
       
       for ( i = 0; i < N; i ++ )
           for ( j = i + 1; j < N; j ++ ) {
               t = acos ( X [i] * X [j] + Y [i] * Y [j] + Z [i] * Z [j] );
               if ( t > Dis [i] ) Dis [i] = t;
               if ( t > Dis [j] ) Dis [j] = t;
               }
               
       for ( i = 0 , j = 0; i < N; i ++ ) if ( Dis [i] < Dis [j] ) j = i;
       printf ( "%.2lf %.2lf\n" , W [j] , J [j] );
       }     
}
