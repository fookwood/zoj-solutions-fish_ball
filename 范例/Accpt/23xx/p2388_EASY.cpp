#include <stdio.h>

int      A , B;

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         scanf ( "%d%d" , &A , &B );
         if ( (A & 1) != (B & 1) || A < B ) {
              printf ( "impossible\n" );
              continue;
         }
         printf ( "%d %d\n" , ( A + B ) / 2 , ( A - B ) / 2 );
     }
}
