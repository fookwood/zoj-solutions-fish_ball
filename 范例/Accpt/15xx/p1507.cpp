#include <stdio.h>
#include <algorithm>
#define Limit   16000000
using   namespace std;


int     N , NC;
char    s [Limit];

struct  word
{
        char    *p;
        bool    operator < ( const word &b ) const {
                return strncmp ( p , b.p , N ) < 0;
        }
}       Data [1000000];

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total , i , len , ans;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                scanf ( "%d%d" , &N , &NC );
                scanf ( "%s" , s ); len = strlen ( s ); len -= N - 1;
                for ( i = 0; i < len; i ++ ) Data [i].p = s + i;
                sort ( Data , Data + len );
                for ( ans = i = 1; i < len; i ++ ) if ( Data [i - 1] < Data [i] )
                        ans ++;
                printf ( "%d\n" , ans );
                if ( total > 1 ) printf ( "\n" );
        }
}
 