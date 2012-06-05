#include <iostream>

using namespace std;

long long f [11] [320] [6] , Ans [320];

void prepare ();

main ()
{
     int     N;
     prepare ();
     while ( cin >> N ) cout << Ans [N] << endl;
}

void prepare ()
{
     int     i , j , k , s , a , b , S1 , S2 , NextScore , NextState;
     memset ( f , 0 , sizeof ( f ));
     f [0] [0] [0] = 1;
     
     for ( i = 0; i < 10; i ++ )
         for ( j = 0; j < 300; j ++ )
             for ( s = 0; s < 6; s ++ ) if ( f [i] [j] [s] ) {
                 S1 = s / 3 , S2 = s % 3;
                 for ( a = 0; a <= 10; a ++ )
                     for ( b = 0; a + b <= 10; b ++ ) {
                         if ( a == 10 ) {
                              NextScore = j + a;
                              if ( S1 ) NextScore += a;
                              if ( S2 ) NextScore += a;
                              NextState = ( S2 > 1 ) * 3 + 2;
                              f [i + 1] [NextScore] [NextState] += f [i] [j] [s];
                         } else {
                              NextScore = j + a + b;
                              if ( S1 ) NextScore += a;
                              if ( S2 ) NextScore += a;
                              if ( S2 > 1 ) NextScore += b;
                              NextState = ( a + b == 10 );
                              f [i + 1] [NextScore] [NextState] += f [i] [j] [s];
                         }
                     }
             }
     for ( i = 0; i <= 300; i ++ ) Ans [i] = f [10] [i] [0];
     
     for ( i = 0; i <= 300; i ++ )
         for ( s = 1; s < 6; s ++ ) if ( f [10] [i] [s] ) {
             S1 = s / 3 , S2 = s % 3;
             for ( a = 0; a <= 10; a ++ )
                 for ( b = 0; b <= 10; b ++ ) {
                     if ( a != 10 && a + b > 10 ) continue;
                     if ( S2 < 2 && b ) continue;
                     NextScore = i;
                     if ( S1 ) NextScore += a;
                     if ( S2 ) NextScore += a;
                     if ( S2 > 1 ) NextScore += b;
                     Ans [NextScore] += f [10] [i] [s];
                 }
         }
}
