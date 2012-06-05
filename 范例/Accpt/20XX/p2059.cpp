#include <stdio.h>
#include <string.h>

const   int     maxn    = 2001;
const   int     half    = 1001;

int     i , n , data [maxn] , max;
int     opt [2] [half];

void    first_opt ()
{
        int     i , k , t , a , b;

        a = 0; b = 1;

        opt [a] [0] = opt [b] [0] = 0;
        for ( i = 1; i < half; i ++ ) opt [a] [i] = opt [b] [i] = -1;

        for ( max = 0 , k = 0; k < n; k ++ , a = 1 - a, b = 1 - b )
                for ( t = max , i = 0; i <= t; i ++ ) if ( opt [a] [i] >= 0 ) {
                        if ( opt [a] [i] > opt [b] [i] ) opt [b] [i] = opt [a] [i];                
                        if ( i + data [k] < half && opt [a] [i] > opt [b] [i + data [k]] ) {
                                opt [b] [i + data [k]] = opt [a] [i];
                                if ( i + data [k] > max ) max = i + data [k];
                        }
                        
                        if ( i > data [k] ) {
                                if ( opt [a] [i] + data [k] > opt [b] [i - data [k]] )
                                        opt [b] [i - data [k]] = opt [a] [i] + data [k];               
                        }
                        else {
                                if ( opt [a] [i] + i > opt [b] [data [k] - i] ) {
                                        opt [b] [data [k] - i] = opt [a] [i] + i;
                                        if ( data [k] - i > max ) max = data [k] - i;
                                }
                        }
                }

        if ( opt [a] [0] > 0 ) printf ( "%d\n" , opt [a] [0] );
                else printf ( "Sorry\n" );
        
}


main ()
{
        while ( scanf ( "%d" , &n ) , n >= 0 ) {
                for ( i = 0; i < n; i ++ ) scanf ( "%d" , &data [i] );
                first_opt ();
        }
}
       