#include <stdio.h>
#include <string.h>

const   int     Limit = 100000;
const   int     Hash = 88889;

int     N;
int     S;
int     Start;
int     Total;
int     pre [8];
char    data [17];
int     power2 [17];
int     Sum = 0;

int     len;
struct  node {
        int     Present , Pos , Next;
}       Data [Limit];
int     Bucket [Hash];

int     ord ( int N )
{
        int     i;
        int     ret = 0;
        for ( i = 0; i < N; i ++ ) {
                ret <<= 1;
                if ( data [i] == 'b' ) ret ++;
        }
        return ret;
}

bool    init ()
{
        if ( scanf ( "%d" , &N ) == EOF ) return false;

        int     i , t;

        scanf ( "%s" , data );
        Start = ord ( N );

        Total = 0;
        for ( i = 0; i < 8; i ++ ) {
                scanf ( "%s" , data );
                t = ord ( 3 );
                if ( data [3] == 'b' ) pre [t] = 1;
                        else pre [t] = 0;
                Total += pre [t];
        }
        scanf ( "%d" , &S );
        return true;
}

void    prepare ()
{
        int     i;
        power2 [0] = 1;
        for ( i = 1; i < 17; i ++ ) power2 [i] = power2 [i - 1] << 1;
}

void    print ( int N , int t )
{
        int     i;
        int     smallest = t;
        for ( i = 0; i < N; i ++ ) {
                if ( t & power2 [N - 1] ) t = (( t ^ power2 [N - 1] ) << 1 ) + 1;
                else t <<= 1;
                if ( t < smallest ) smallest = t;
        }

        for ( i = N - 1; i >= 0; i -- )
                if ( smallest & power2 [i] ) printf ( "b" );
                else printf ( "a" );
        printf ( "\n" );
}

int     find ( int x , int p )
{
        int     k;
        for ( k = Bucket [x % Hash]; k != -1; k = Data [k].Next )
                if ( Data [k].Present == x ) return k;
        k = x % Hash;
        Data [len].Next = Bucket [k];
        Data [len].Present = x;
        Data [len].Pos = p;
        Bucket [k] = len ++;
        return -1;
}
int     change ( int s )
{
        int     i , t;
        int     ret = 0;
        for ( i = 0; i < N; i ++ ) {
                t = 0;
                if ( s & power2 [i] ) t += 1;
                if ( s & power2 [( i + 1 ) % N] ) t += 2;
                if ( s & power2 [( i + 3 ) % N] ) t += 4;
                if ( pre [t] ) ret = ret | power2 [( i + 1 ) % N];
        }
        return ret;
}


int     Work ()
{
        Sum += S;
        if ( Total == 0 ) {
                if ( S > 1 ) return 0; else return S;
        }
        if ( Total == 8 ) {
                if ( S > 1 ) return power2 [N] - 1; else return S;
        }

        int     t = Start , b , i , j , e , f;
        int     ddd [30];
        for ( i = 0; i < 30; i ++ ) ddd [i] = i % N;

        len = 0;
        memset ( Bucket , 0xff , sizeof ( Bucket ));
        
        for ( i = 0; i < S; i ++ ) {
                f = find ( t , i );
                if ( f != -1 ) {
                        return Data [Data [f].Pos + ( S - i ) % ( i - Data [f].Pos )].Present;
                }

                e = 0;
                for ( j = 0; j < N; j ++ ) {
                        b = 0;
                        if ( t & power2 [ddd [j + 1]] ) b += 2;
                        if ( t & power2 [j] ) b += 1;
                        if ( t & power2 [ddd [j + 3]] ) b += 4;
                        if ( pre [b] ) e = e | power2 [ddd [j + 1]];
                }
                t = e;
        } 
        return t;
}

main ()
{
        freopen ( "p.in" , "r" , stdin );
        freopen ( "p.out" , "w" , stdout );

        prepare ();
        while ( init () ) print ( N , Work () );
}
 