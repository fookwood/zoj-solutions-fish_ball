#include <stdio.h>

int     Ans ( int n , int m )
{
        int     x = 1 << 30 , half , equal;

        while ( m && n > m ) {
                while ( x >= m && x - ( x - m + 1 ) / 2 >= n ) x >>= 1;
                if ( m > x ) { n -= x; m -= x; continue; }
                if ( n - m >= x / 2 ) { n -= x / 2; continue; }
                return 0;
        }
        if ( m == 0 || n < m ) return 0;
        return 1;
}

main ()
{
        int     total , n , m;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                scanf ( "%d%d" , &n , &m );
                printf ( "%d\n" , Ans ( n , m ));
        } 
}
 