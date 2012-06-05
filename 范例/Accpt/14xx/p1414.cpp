#include <stdio.h>

main ()
{
        int     total , N , M;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                scanf ( "%d%d" , &N , &M );
                if ( N == M || N == M + 2 )
                        printf ( "%d\n" , N + M - ( N % 2 == 1 ) );
                        else printf ( "No Number\n" );
        }
}
 