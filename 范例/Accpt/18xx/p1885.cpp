#include <stdio.h>
#include <math.h>

#define  Base     10000

struct   HP {
         int len , s [30];
         void operator += ( int a );
         void operator *= ( int a );
         void print ();
         HP ( int t = 0 ) { len = 1, s [0] = t; }
};

void     HP::print ()
{
 printf ( "%d" , s [len - 1] );
 for ( int i = len - 2; i >= 0; i -- ) printf ( "%04d" , s [i] );
 printf ( "\n" );         
}

void     HP::operator += ( int a )
{
     int i , j;
     for ( j = a , i = 0; j && i < len; i ++ )
         j += s [i] , s [i] = j % Base , j /= Base;
     while ( j ) s [len ++] = j % Base , j /= Base;
}

void HP::operator *= ( int a )
{
     int i , j;
     for ( j = 0 , i = 0; i < len; i ++ )
         j += s [i] * a , s [i] = j % Base , j /= Base;
     while ( j ) s [len ++] = j % Base , j /= Base;
}

int   T , A , B;

int main(int argc, char *argv[])
{
    while ( scanf ( "%d%d%d" , &T , &A , &B ) != EOF ) {
   	      printf ( "(%d^%d-1)/(%d^%d-1) " , T , A , T , B );
          if ( A == 0 || B == 0 || T == 1 || A % B || ( A - B ) * log10 ( T ) > 100 ) {
               puts("is not an integer with less than 100 digits.");continue;
          }
          HP Ans;
          int    Pb;
          for ( Pb = A - B; Pb >= 0; Pb -- ) {
              Ans *= T;
              if ( Pb % B == 0 ) Ans += 1;
          }
          Ans.print ();
    }
}
