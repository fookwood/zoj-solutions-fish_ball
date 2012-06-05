#include <stdio.h>
#include <algorithm>
using namespace std;

const   int     maxn = 1000;

int     n;
int     Total;
int     Ans;
int     num [maxn];
int     d [maxn] [maxn];
bool    Use [maxn] [maxn];

void    init ()
{
        int     i;
        int     j;
        int     last;
        for ( i = 0; i < n; i ++ ) scanf ( "%d" , &num [i] );
        sort ( num , num + n );
        Total = Ans = 0;
        last = 1;

        num [Total ++] = num [0];
        for ( i = 1; i < n; i ++ ) if ( num [i] != num [i - 1] ) {
                num [Total ++] = num [i];
                if ( last > Ans ) Ans = last;
                last = 1;
        } else last ++;

        if ( last > Ans ) Ans = last;

        for ( i = 0; i < Total; i ++ )
                for ( j = 0; j < Total - i; j ++ )
                        d [i] [j] = num [i + j + 1] - num [i];

}

int     BinFind ( int w , int D )
{
        int     l = 0 , r = Total - w;
        int     mid;
        while ( l + 1 < r ) {
                mid = ( l + r ) / 2;
                if ( d [w] [mid] <= D ) l = mid;
                        else r = mid;
        }
        if ( l >= Total - w || d [w] [l] != D ) return -1;
        return l;
}

void    Work ()
{
        int     i , j;
        int     last;
        int     w , k;
        int     Nw , Nk;
        
        for ( i = 0; i < Total; i ++ )
                for ( j = 0; j < Total - i; j ++ )
                        Use [i] [j] = 1;

        for ( i = 0; i < Total; i ++ )
                for ( j = 0; j < Total - i; j ++ )
                        if ( Use [i] [j] ) {
                                w = i;
                                k = j;
                                last = 1;
                                do {
                                        Use [w] [k] = 0;
                                        last ++;
                                        Nw = w + k + 1;
                                        Nk = BinFind ( Nw , d [w] [k] );
                                        if ( Nk < 0 ) break;
                                        w = Nw; k = Nk;
                                } while (1);
                                if ( last > Ans ) Ans = last;
                        }
        printf ( "%d\n" , Ans );
}

main ()
{
        while ( scanf ( "%d" , &n ) != EOF ) {
                init ();
                Work ();
        }
}
 