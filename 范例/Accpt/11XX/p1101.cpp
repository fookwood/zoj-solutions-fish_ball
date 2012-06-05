#include <stdio.h>
#include <algorithm>

using namespace std;

int     n;
int     data [1000];

int     BinSearch ( int i , int j , int k , int p )
{
        int     l = 0, r = n;
        int     mid;
        while ( l + 1 < r ) {
                mid = ( l + r ) >> 1;
                if ( data [mid] > p ) r = mid;
                else l = mid;
        }
        
        if ( l != i && l != j && l != k && data [i] == data [j] + data [k] + data [l] )
                return 1;
        else return 0;
        
}

void    Search ()
{
        int     i;
        int     j , k;
        int     goal;

        for ( i = n - 1; i >= 0; i -- )
                for ( j = n - 1; j >= 1; j -- ) if ( i != j )
                        for ( k = j - 1; k >= 0; k -- ) if ( k != j && k != i ) {
                                goal = data [i] - data [j] - data [k];
                                if ( goal > data [k] ) break;
                                if (BinSearch ( i , j , k , goal )) {
                                        printf ( "%d\n" , data [i] );
                                        return;
                                }
                        }

        printf ( "no solution\n" );
}

main ()
{
        while ( scanf ( "%d" , &n ) , n ) {
                for ( int i = 0; i < n; i ++ ) scanf ( "%d" , &data [i] );
                sort ( data , data + n );
                Search ();
        }
}
 