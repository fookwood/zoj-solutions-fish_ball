#include <stdio.h>
#include <algorithm>
#define MaxChild        20
using   namespace std;

int     N;
int     Len [201] , Child [201] [MaxChild];

void    init ()
{
        int     i , j , p;
        scanf ( "%d" , &N );
        for ( i = 1; i <= N; i ++ ) {
                scanf ( "%d" , &p );
                scanf ( "%d" , &Len [p] );
                for ( j = 0; j < Len [i]; j ++ )
                        scanf ( "%d" , &Child [p] [j] );
        }
}

int     Max ( int p )
{
        int     i , Min , t;
        for ( i = 0; i < Len [p]; i ++ )
                Child [p] [i] = Max ( Child [p] [i] );
        sort ( Child [p] , Child [p] + Len [p] );
        for ( Min = 1 , i = 0; i < Len [p]; i ++ ) {
                t = Child [p] [i] + Len [p] - i - 1;
                if ( t > Min ) Min = t;
        }
        return  Min;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );
        
        int     total;
        for ( scanf ( "%d" , &total ); total; total -- ) {
                init ();
                printf ( "%d\n" , Max ( 1 ) );
        }
}
 