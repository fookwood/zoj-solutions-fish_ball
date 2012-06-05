#include <stdio.h>
#include <math>
#include <algorithm>

using namespace std;

struct  TNode {
        double  a , b;
};

int     N , K;
int     state;
TNode   Line [1000];
bool    final [1000];

bool    init ()
{
        scanf( "%d%d" , & N , & K );
        if ( N == 0 && K == 0 ) return false;
        int     i , x , y;
        state = 0;
        for ( i = 0; i < N; i ++ ) {
                scanf ( "%d%d" , &x , &y );
                if ( abs ( y ) > K ) state = 1;
                else {
                        Line [i].a = x - sqrt ( K * K - y * y );
                        Line [i].b = x + sqrt ( K * K - y * y );
                }
        }
        return true;
}

bool    comp ( const TNode &a , const TNode &b )
{
        return a.b < b.b;
}

int     Ans ()
{
        if ( state ) return -1;
        sort ( Line , Line + N , comp );

        int     ret = 0;
        int     i , j;
        memset ( final , 0 , sizeof ( final ));
        for ( i = 0;i < N;i ++ ) if ( !final [i] ) {
                ret ++;
                final [i] = 1;
                for ( j = i; j < N; j ++ ) if ( Line [j].a <= Line [i].b && Line [i].b <= Line [j].b )
                        final [j] = 1; 
        }
        return ret;
}

main ()
{
        int     step = 0;
        while ( init () )
                printf ( "Case %d: %d\n" , ++ step , Ans () );         
}
