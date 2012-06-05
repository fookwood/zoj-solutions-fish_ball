#include <stdio.h>
#include <math.h>
#include <string.h>

#define  min(a,b) (a<b?a:b)
#define  max(a,b) (a>b?a:b)

int      N;

int   Money [1000] , Tot , Avg;
int   Sum1 , Sum2;


main ()
{
     int i , j;
     int Ans;
     double  Tmp;

     
     while ( scanf ( "%d\n" , &N ) , N ) {
           for ( Tot = i = 0; i < N; i ++ ) {
               scanf ( "%lf" , &Tmp ); Tmp *= 100;
               Money [i] = int ( Tmp + 0.3 );
               Tot += Money [i];
           }      
           Avg = Tot / N;
           for ( Sum1 = i = 0; i < N; i ++ ) if ( Money [i] < Avg ) Sum1 += Avg - Money [i];
           for ( Sum2 = i = 0; i < N; i ++ ) if ( Money [i] > Avg  + 1 ) Sum2 += Money [i] - Avg - 1;

           Ans = max ( Sum1 , Sum2 );

           printf ( "$%d.%02d\n" , Ans / 100 , Ans % 100 );

     }
}
