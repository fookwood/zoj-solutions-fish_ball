#include <stdio.h>
#include <algorithm>

using namespace std;

struct  Tdata   {
        int     W , S;
        int     ords;
        } data [1000];

int     n;
int     last;

int     get [1000];
int     pred [1000];


bool    comp ( const Tdata &a , const Tdata &b )
{
        return a.W > b.W;
}

int     maxget ()
{
        int     i , j;
        int     ret = 0;

        for ( i = 0; i < n; i ++ ) pred [i] = -1;
        
        for ( i = 0; i < n; i ++ ) {
                get [i] = 0;
                for ( j = 0; j < i; j ++ ) if ( data [j].S < data [i].S && data [j].W > data [i].W && get [j] > get [i] ) {
                        get [i] = get [j];
                        pred [i] = j;
                }
                get [i] ++;
        }
        for ( i = 0; i < n; i ++ ) if ( get [i] > get [ret] ) ret = i;
        return ret;
}

void    print ( int last )
{
        printf ( "%d\n" , get [last] );

        for ( ; last != -1; last = pred [last] ){
        printf ( "%d\n" , data [last].ords );
        }
}

main ()
{
        for ( n = 0; scanf ( "%d %d" , &data [n].W , &data [n].S ) != EOF ; n ++ ) data [n].ords = n + 1;
        sort ( data , data + n , comp );
        last = maxget ();
        print ( last );
}
