// zju 1464
#include <stdio.h>
#define MAX 10000

int     N , K;
double  Long [MAX] , TotalLong;

void    init ()
{
        int     i;
        scanf ( "%d%d" , &N , &K );
        for ( TotalLong = i = 0; i < N; i ++ ) {
                scanf ( "%lf" , &Long [i] );
                TotalLong += Long [i];
        }
}

double  Answer ()
{
        int     i , get; 
        double  low = 0 , high = TotalLong / K + 1, mid;

        while ( low + 0.01 < high ) {
                mid = ( low + high ) / 2;
                for ( get = i = 0; i < N; i ++ )
                        get += int ( Long [i] / mid );
                if ( get >= K ) low = mid;
                        else high = mid;
        }

        return low;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                printf ( "%.2lf\n" , Answer () );
                if ( total ) printf ( "\n" );                
        }
}
 