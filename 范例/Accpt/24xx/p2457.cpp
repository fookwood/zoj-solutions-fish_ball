#include <stdio.h>
#include <string.h>

const   int     maxm    = 1000;

int     opt [maxm];
int     len , data [maxm] , pred [maxm] , last [maxm] , ans [maxm];
int     n , m , a , max , i , t , j;

main ()
{
        while ( scanf ( "%d %d" , &n , &m) != EOF ) {

                memset ( opt , 0 , sizeof ( opt ));
                len = 0;
                opt [0] = 1; opt [1] = 1; data [0] = 1; last [1] = 1;
                max = 1;

                for ( j = 1; j <= n; j ++ ) {
                        scanf ( "%d" , &a );
                        if ( opt [a] ) opt [a] ++;
                        if ( opt [a] != m && a && max != m - 1 ) for ( i = len; i >= 0; i -- ) {
                                t = ( data [i] * a ) % m;
                                if ( !opt [t] ) {
                                        opt [t] = 1; data [++ len] = t;
                                        pred [t] = j; last [t] = data [i];
                                        if ( t > max ) max = t;
                                }
                        }
                }


                printf ( "%d\n" , max );
                
                for ( len = 0 , i = max; i != 1; i = last [i] ) ans [len++] = pred [i];

                for ( i = len - 1; i >= 0; i -- ) {
                        if ( i != len - 1 ) printf ( " " );
                        printf ( "%d" , ans [i] );
                        }
                if ( i ) printf ( "\n" );
        }
}
 