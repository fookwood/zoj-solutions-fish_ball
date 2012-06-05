#include <stdio.h>
#include <string.h>

int      Register [10] , Words [1010];

bool     init ();
void     solve ();

main ()
{
     while ( init () ) solve ();
     return 0;
     int total;
     for ( scanf( "%d\n" , &total ); total; total -- ) {
         init ();
         solve ();
         if ( total > 1 ) printf ( "\n" );
     }
}

void solve ()
{
     int   p , step , d , n , s;
     memset ( Register , 0 , sizeof ( Register ));
     for ( step = p = 0; ; step ++ , p ++ ) {
         if ( Words [p] == 100 ) break;
         s = Words [p] / 100 , d = Words [p] % 100 / 10 , n = Words [p] % 10;
         switch ( s ) {
                case 2 : Register [d] = n; break;
                case 3 : Register [d] = ( Register [d] + n ) % 1000; break;
                case 4 : Register [d] = ( Register [d] * n ) % 1000; break;
                case 5 : Register [d] =   Register [n]; break;
                case 6 : Register [d] = ( Register [d] + Register [n] ) % 1000; break;
                case 7 : Register [d] = ( Register [d] * Register [n] ) % 1000; break;
                case 8 : Register [d] = Words [Register [n]]; break;
                case 9 : Words [Register [n]] = Register [d]; break;
                case 0 : if ( Register [n] ) p = Register [d] - 1; break;
         }
//         printf ( "Order = %d %d %d %d\n" , Words [p] , s , d , n );
//         for ( int i = 0; i < 10; i ++ ) printf ( "%4d" , Register [i] ); printf ( "\n" );
     }
     printf ( "%d\n" , step + 1 );
}

bool init ()
{
     memset ( Words , 0 , sizeof ( Words ));
     char Str [100];
     int  N;
     for ( N = 0; gets ( Str ) && Str [0]; N ++ )
         sscanf ( Str , "%d" , &Words [N] );
     return N;
}

// 4392855   2006-03-08 05:29:14  Time Limit Exceeded 10.020 392 35374 C++ 10033 - Interpreter 
// 4392863   2006-03-08 05:34:16  Accepted 0.002 Minimum 35374 C++ 10033 - Interpreter 
