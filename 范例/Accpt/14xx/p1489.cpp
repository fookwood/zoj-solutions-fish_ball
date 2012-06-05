#include <stdio.h>

main ()
{
        int     N , X , i , T;
        while ( scanf ( "%d" , &N ) != EOF )
                if ( !(N % 2) || N == 1 ) printf ( "2^? mod %d = 1\n" , N );
                        else {
                        for ( X = 1 , T = 2; T != 1; T = ( T << 1 ) % N ) X ++;
                        printf ( "2^%d mod %d = 1\n" , X , N );
                        }
}
 