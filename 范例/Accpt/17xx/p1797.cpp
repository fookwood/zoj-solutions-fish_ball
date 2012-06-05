#include <stdio.h>

int   gcd ( int a , int b )
{
 if ( b == 0 ) return a; else return gcd ( b , a % b );      
}

int main(int argc, char *argv[])
{
    int      total , n , i;
    unsigned int   Ans , Tmp , g;
    for ( scanf ( "%d" , &total ); total; total -- ) {
        scanf ( "%d" , &n );
        Ans = 1;
        for ( i = 0; i < n; i ++ ) {
            scanf ( "%d" , &Tmp );
            g = Tmp > Ans ? gcd ( Tmp , Ans ) : gcd ( Ans , Tmp );
            Ans = Ans / g * Tmp;
        }
        printf ( "%u\n" , Ans );
    }
}
