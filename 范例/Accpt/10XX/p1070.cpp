#include <stdio.h>
#include <math.h>

double  Vs , R , c , w;
int     n;
int     i;

main ()
{
        scanf ( "%lf %lf %lf %d" , &Vs , &R , &c , &n );
        for ( i = 0; i < n; i ++ ) {
                scanf ( "%lf" , &w );
                printf ( "%.3lf\n" , Vs * R / sqrt (R * R + 1 / c / c / w / w ));
        }
        
}
 