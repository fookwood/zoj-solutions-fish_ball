#include <stdio.h>
#include <string.h>
#define  MaxN     1000001

unsigned int Num [MaxN] , Prime [MaxN] , Sum [3392929];

void     prepare ()
{
         memset ( Prime , 0 , sizeof ( Prime ));
         memset ( Sum , 0 , sizeof ( Sum ));
         Prime [1] = 1;
         for ( int i = 2; i < MaxN; i ++ ) if ( Prime [i] == 0 )
             for ( int j = i; j < MaxN; j += i ) Prime [j] = i;
         int t , q , tmp , ti;
         Num [1] = 1;
         int Max = 0;
         for ( int i = 2; i < MaxN; i ++ ) {
             for ( q = Prime [i] , tmp = 1 , ti = i , t = Prime [i]; ti % t == 0; ti /= t , q *= t )
                 tmp += q;
             Num [i] = Num [ti] * tmp;
             Sum [Num [i] - i ] ++;
         }
         Sum [0] = 1;
         for ( int i = 1; i < 3392929; i ++ ) Sum [i] += Sum [i - 1];
}

main ()
{
     prepare ();
     int     N;
     while ( scanf ( "%d" , &N ) != EOF ) {
           if ( N > 3392928 ) {
                printf ( "1000000\n" );
                continue;
           }
           printf ( "%d\n" , Sum [N] );
     }
}
