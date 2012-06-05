#include <stdio.h>

char     Str [100];

const    int w [5] = { 9 , 4 , 4 , 4 , 7 };

main()
{
      double Ans , Total , p , q , T;
      int    a [5];
      char   c [5];
      while ( gets ( Str ) && Str [0] != '-' ) {
            Ans = Total = 0;
            
            do {
               sscanf ( Str , "%d%c%d%c%d%c%d%c%d%c" , &a [0] , &c [0] , &a [1] , &c [1] , &a [2] , &c [2] , &a [3] , &c [3] , &a [4] , &c [4] );
               p = q = 0;
               for ( int i = 0; i < 5; i ++ ) {
                   if ( c [i] == 'g' ) c [i] = 'C' , a [i] *= w [i];
                   if ( c [i] == 'C' ) p += a [i];
                      else q += a [i];
               }
               T = p / ( 1 - q / 100 );
               Total += T;
               if ( c [0] == 'C' ) Ans += a [0];
                  else Ans += a [0] * T / 100;
            } while ( gets ( Str ) && Str [0] != '-' );
            
            printf ( "%.lf%c\n" , 100 * Ans / Total , '%' );
      }
}
