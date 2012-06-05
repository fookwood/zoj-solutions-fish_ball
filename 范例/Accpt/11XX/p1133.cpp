#include <stdio.h>
#include <math.h>
#include <string.h>

int     Total;
int     n;
int     prime [10000];
int     sumP  [10000];

void    PrepareForPrime ()
{
        bool whether [20000];
        int     i , j;
        int     s , t;
        
        memset ( whether , 0 , sizeof ( whether ));
        for ( i = 2; i < 20000; i ++ )
                if ( !whether [i] ) {
                prime [Total] = i;

                t = i; s = 0;
                while ( t ) { s += t % 10; t /= 10; }
                sumP [Total] = s;

                Total ++;

                for ( j = 2; j <= 20000 / i; j ++ )
                        whether [i * j] = 1;
                }
}

int     Check ( int n )
{
        int     i , s;
        int     t = n , ss = 0;

        while ( t ) {
                ss += t %10;
                t /= 10;
        }

        for ( i = s = 0; prime [i] <= int ( sqrt ( n)); i ++ )
                while ( n % prime [i] == 0 ){
                        n /= prime [i];
                        s += sumP [i];
                }

        if ( s == 0 ) return 0;
                
        if ( n != 1 ) {
                t = 0; while ( n ) {
                        t += n %10;
                        n /= 10;
                }
                s += t;
        }
        return s == ss;
}


main ()
{
        PrepareForPrime ();

        while ( scanf ( "%d" , &n ) , n ) {
                n ++;
                while ( !Check ( n )) n ++;
                printf ( "%d\n" , n );
        }
}
 