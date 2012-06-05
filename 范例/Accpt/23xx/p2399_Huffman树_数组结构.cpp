#include <stdio.h>
#define  MAXN     500000

int      N , Num1 [MAXN];
long long Num2 [MAXN] , Sum;

void     init ();
void     Work ();

main ()
{
     int total;
     for ( scanf ( "%d" , &total ); total; total -- ) {
         init ();
         if ( N == 1 ) printf ( "%d\n" , Num1 [0] );
         else Work () , printf ( "%lld\n" , Sum );
         if ( total > 1 ) puts ( "" );
     }
}

void Work ()
{
     Sum = 0;
     int  Start1 = 0 , Start2 = 0 , Size2 = 0;
     long long Add;
     
     for ( int i = 1; i < N; i ++ ) {
         Add = 0;
         
         if ( Start1 == N ) Add += Num2 [Start2 ++];
         else if ( Start2 == Size2 ) Add += Num1 [Start1 ++];
         else if ( Num1 [Start1] < Num2 [Start2] ) Add += Num1 [Start1 ++];
         else Add += Num2 [Start2 ++];
         
         if ( Start1 == N ) Add += Num2 [Start2 ++];
         else if ( Start2 == Size2 ) Add += Num1 [Start1 ++];
         else if ( Num1 [Start1] < Num2 [Start2] ) Add += Num1 [Start1 ++];
         else Add += Num2 [Start2 ++];
         Sum += Add; Num2 [Size2 ++] = Add;
     }
     
}

void init ()
{
     scanf ( "%d" , &N );
     for ( int i = 0; i < N; i ++ ) scanf ( "%d" , &Num1 [i] );
}
