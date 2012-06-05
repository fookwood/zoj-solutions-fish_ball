#include <stdio.h>

main ()
{
        int     n , u , d;
        while ( scanf ( "%d%d%d" , &n , &u , &d ) , n || u || d ) {
                if ( n <= u ) printf ( "1\n" );
                        else printf ( "%d\n" , ( n - u - 1 ) / ( u - d ) * 2 + 3 );
        }
}
 