#include <stdio.h>

double   A , B , C , D;

void     PrintAns ( double a , double b , double c )
{
         printf ( "%.1lf g of ice and %.1lf g of water at %.1lf C\n"  , a , b , c );
}

main ()
{
     double  J , T;
     while ( scanf ( "%lf%lf%lf%lf" , &A , &B , &C , &D ) , A != 0 || B != 0 || C != 0 || D != 0 ) {
           J = 4.19 * A * C + 335 * A + 2.09 * B * D;
           T = A + B;
           if ( J < 0 ) {
                PrintAns ( T , 0 , J / T / 2.09 );
                continue;
           }
           if ( J > 335 * T ) {
                PrintAns ( 0 , T , ( J - 335 * T ) / T / 4.19 );
                continue;
           }
           PrintAns ( T - J / 335 , J / 335 , 0 );
     }
}
