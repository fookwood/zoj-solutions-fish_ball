#include <stdio.h>
#include <algorithm>
using namespace std;

const   int     maxn    = 100;
        int     dx [5] = { 0 , 0 , 1 , -1 , 0};
        int     dy [5] = { 1 , -1 , 0 , 0 , 0};

int     N , M , T;
int     Opt [maxn] [maxn] [maxn + 1] , Back [maxn] [maxn] [maxn + 1];

struct  node {
        int     Time , minx , miny , maxx , maxy;
}       data [maxn];

int     n;

bool    comp ( const node & a , const node & b )
{
        return ( a.Time < b.Time );
}

bool    range ( int x , int y )
{
        return x >= 0 && x < N && y >= 0 && y < M;
}

bool    init ()
{
        int     i;
        if ( N == 0 ) return false;
        scanf ( "%d" , &n );
        for ( i = 0; i < n; i ++ )
                scanf ( "%d %d %d %d %d" , &data [i].Time , &data [i].minx , &data [i].miny , &data [i].maxx , &data [i].maxy );
        sort ( data , data + n , comp );
        return true;
}

void    Work ()
{
        int     i , j , k , c , r;
        int     x , y;
        int     ret;
        int     finalx , finaly;

        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < M; j ++ )
                        Opt [i] [j] [0] = 1;
                        
        for ( r = 0 , k = 1; k <= T; k ++ ) {

                for ( i = 0; i < N; i ++ )
                        for ( j = 0; j < N; j ++ )
                                Opt [i] [j] [k] = 0;

                for ( i = 0; i < N; i ++ )
                        for ( j = 0; j < M; j ++ ) {
                                if ( ! Opt [i] [j] [k - 1] ) continue;
                                for ( c = 0; c < 5; c ++ ) {
                                        x = i + dx [c];
                                        y = j + dy [c];
                                        if ( !range ( x , y )) continue;
                                        Opt [x] [y] [k] ++;
                                }
                        }

                while ( r < n && data [r].Time == k ) {
                        for ( i = data [r].minx - 1; i < data [r].maxx; i ++ )
                                for ( j = data [r].miny - 1; j < data [r].maxy; j ++ )
                                        Opt [i] [j] [k] = 0;
                        r ++;
                }
        }

        ret = 0;
        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < M; j ++ )
                        ret += Opt [i] [j] [T];
                        
        if ( !ret ) {
                printf ( "The robber has escaped.\n" );
                return;
        }

        for ( i = 0; i < N; i ++ )
                for ( j = 0; j < M; j ++ )
                        if ( Opt [i] [j] [T] > 0 ) Back [i] [j] [T] = 1;
                                else Back [i] [j] [T] = 0;

        r = n - 1;
        while ( r >= 0 && data [r].Time == T ) r --;

        for ( k = T - 1; k >= 0; k -- ) {

                for ( i = 0; i < N; i ++ )
                        for ( j = 0; j < M; j ++ )
                                Back [i] [j] [k] = 0;

                for ( i = 0; i < N; i ++ )
                        for ( j = 0; j < M; j ++ ) {
                                if ( !Back [i] [j] [k + 1] ) continue;
                                for ( c = 0; c < 5; c ++ ) {
                                        x = i + dx [c];
                                        y = j + dy [c];
                                        if ( !range ( x , y )) continue;
                                        Back [x] [y] [k] ++;
                                }
                        }

                while ( r >= 0 && data [r].Time == k ) {
                        for ( i = data [r].minx - 1; i < data [r].maxx; i ++ )
                                for ( j = data [r].miny - 1; j < data [r].maxy; j ++ )
                                        Back [i] [j] [k] = 0;
                        r --;
                }
        }

        ret = 0;
        for ( k = 1; k <= T; k ++ ) {
                r = 0; c = 0;

                for ( i = 0; i < N; i ++ )
                        for ( j = 0; j < M; j ++ ) {
                                if ( !Opt [i] [j] [k] || !Back [i] [j] [k] ) continue;

                                finalx = i; finaly = j;
                                c ++;
                        }
                if ( c == 1 ) {
                        printf ( "Time step %d: The robber has been at %d,%d.\n" , k , finalx + 1 , finaly + 1 );
                        ret ++;
                }
        }
        if ( !ret ) printf ( "Nothing known.\n" );
}

main ()
{
        int     step = 0;

        while ( 1 ) {
                scanf ( "%d %d %d" , &N , &M , &T );
                if ( !init () ) break;
                step ++;
                printf ( "Robbery #%d:\n" , step );
                Work ();
                printf ( "\n" );
        }
}
 