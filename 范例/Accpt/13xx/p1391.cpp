#include <stdio.h>
#include <algorithm>

#define MAXN    8001
#define Limit   500000

using namespace std;

int     N , Answer;
struct  TData {
        int     y1 , y2 , x;
}       Data [MAXN];

bool    Reach [MAXN];
int     Segment [MAXN] , Point [MAXN];
int     Total , *Bucket [MAXN] , Present [Limit] , Last [MAXN];

bool    cmp ( const TData & a , const TData & b )
{
        return a.x < b.x;
}

void init ()
{
        Total = 0; Answer = 0;
        memset ( Segment , 0xff , sizeof ( Segment ));
        memset ( Bucket , 0 , sizeof ( Bucket ));
        memset ( Point , 0xff , sizeof ( Point ));

        scanf ( "%d" , &N );
        for ( int i = 0; i < N; i ++ ) scanf ( "%d %d %d" , &Data [i].y1 , &Data [i].y2 , &Data [i].x );
        sort ( Data , Data + N , cmp );
}

void    Work ()
{
        int     i , j , k , a , b;

        for ( k = 0; k < N; k ++ ) {
                memset ( Reach , 0 , k );
                a = Data [k].y1 , b = Data [k].y2;
                for ( i = a; i < b; i ++ ) {
                        if ( Segment [i] != -1 ) Reach [Segment [i]] = 1;
                        if ( Point [i] != -1 ) Reach [Point [i]] = 1;
                        Segment [i] = k; Point [i] = k;
                } if ( Point [b] != -1 ) Reach [Point [b]] = 1; Point [b] = k;

                Bucket [k] = &Present [Total];
                for ( i = 0; i < k; i ++ ) if ( Reach [i] ) Present [Total ++] = i;
                Last [k] = & Present [Total] - Bucket [k];

                for ( i = 0; i < Last [k]; i ++ ) {
                        a = *( Bucket [k] + i );
                        for ( j = 0; j < Last [a]; j ++ )
                                if ( Reach [*( Bucket [a] + j )] ) Answer ++;
                }
        }
}

main ()
{
        int NumberCase;
        for ( scanf ( "%d" , &NumberCase ); NumberCase; NumberCase -- ) {
                init ();
                Work ();
                printf ( "%d\n" , Answer );
        }
}
