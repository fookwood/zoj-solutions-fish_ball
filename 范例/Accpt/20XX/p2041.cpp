#include <stdio.h>
#include <math.h>
using namespace std;

const   int     maxN = 101;
const   int     maxT = 30000;

int     part;
int     N , K , T;
int     time [maxN];
int     openness [maxN];
int     stoutness [maxN];
int     MaxGet [maxN];

int     abs ( int a );

void    init ()
{
        int     i;
        int     j;
        int     t;
        scanf ( "%d %d %d" , &N , &K , &T );
        for ( i = 1; i <= N; i ++ ) scanf ( "%d" , &time [i] );
        for ( i = 1; i <= N; i ++ ) scanf ( "%d" , &openness [i] );
        for ( i = 1; i <= N; i ++ ) scanf ( "%d" , &stoutness [i] );
        for ( i = 1; i <= N; i ++ )
                for ( j = i + 1; j <= N; j ++ )
                        if ( time [i] > time [j] ) {
                        t = time [i]; time [i] = time [j]; time [j] = t;
                        t = openness [i]; openness [i] = openness [j]; openness [j] = t;
                        t = stoutness [i]; stoutness [i] = stoutness [j]; stoutness [j] = t;
                        }
}

int     MaxValue ()
{
        int     i;
        int     j;
        int     t;
        int     a;
        int     ret = 0;

        time [0] = stoutness [0] = 0;
        MaxGet [0] = 0;

        for ( i = 1; i <= N; i ++ ) {
                MaxGet [i] = -1;
                for ( j = 0; j < i; j ++ ) {
                        if ( MaxGet [j] == -1 ) continue;

                        a = stoutness [i] - stoutness [j];
                        if ( a < 0 ) a = -a;

                        if ( time [i] - time [j] < a ) continue;
                        t = MaxGet [j] + openness [i];
                        if ( t > MaxGet [i] ) MaxGet [i] = t;
                }
                if ( MaxGet [i] > ret ) ret = MaxGet [i];
        }
        return ret;
}

main ()
{
        scanf ( "%d" , &part );
        while ( part ) {
                init ();
                printf ( "%d\n" , MaxValue ());
                part --;
                if ( part ) printf ( "\n" );
        }
}
 