#include <stdio.h>

int      A , B;

bool     Ans ( int a , int b )
{
 if ( a < b ) { int t = a; a = b; b = t; }
 if ( a % b == 0 || a - b >= b ) return true;
 return !Ans ( a - b , b );
}

main ()
{
     while ( scanf ( "%d%d" , &A , &B ) , A || B )
           printf ( "%s wins\n" , Ans ( A , B ) ? "Stan" : "Ollie" );
}
