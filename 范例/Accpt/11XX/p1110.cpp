#include <stdio.h>

int     s , p , y , j;
int     a , b , c;

void    work ()
{
        int     ia , ib;

        for ( c = 0; c <= 1000; c ++ )
                for ( ib = 0; ib <= 1; ib ++ ) {
                        b = c + ib + p;
                        for ( ia = 0; ia <= 1; ia ++ ) {
                                a = b + s + ia;
                                if ( ! (a - c == y ) && ! ( a - c == y + 1 )) continue;
                                if ( a + b + c == j + 12 ) {
                                        printf ( "%d %d %d\n" , a , b , c );
                                        return;
                                }
                        }
                        
                }
}

main ()
{
        while ( scanf ( "%d %d %d %d" , &s , &p , &y , &j ) != EOF ) work ();
}
 