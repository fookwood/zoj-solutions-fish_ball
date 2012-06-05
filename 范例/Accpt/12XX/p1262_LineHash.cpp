#include <stdio.h>
#include <string.h>

const   int     power2 [16] = { 1 , 2 , 4 , 8 , 16 ,
                                32 , 64 , 128 , 256 , 512 ,
                                1024 , 2048 , 4096 , 8192 , 16384 , 32768 };
                                
int     N , S;
int     Start , Total;

int     pre [8];
char    data [17];

int     len = 0;
int     Pos [1 << 15];
int     Ans [1 << 15];

int     ord ( int N )
{
        int     ret = 0;
        for ( int i = 0; i < N; i ++ ) {
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

void    print ( int t )
{
        int     i;
        for ( i = N - 1; i >= 0; i -- )
                if ( t & power2 [i] ) printf ( "b" );
                else printf ( "a" );
        printf ( "\n" );
}

int     Smallest ( int t )
{
        int     i , ret = t;
        for ( i = 1; i < N; i ++ ) {
                if ( t & power2 [N - 1] ) t = (( t ^ power2 [N - 1] ) << 1 ) + 1;
                else t <<= 1;
                if ( t < ret ) ret = t;
        }
        return ret;
}

int     Work ()
{
        if ( Total == 0 ) {
                if ( S > 1 ) return 0; else return S;
        }
        if ( Total == 8 ) {
                if ( S > 1 ) return power2 [N] - 1; else return S;
        }

        int     i , Num [18];
        for ( i = 0; i < N + 3; i ++ ) Num [i] = i % N;

        int     j , Startlen = len , t = Smallest ( Start ) , Next , PreIndex;
        for ( i = 0; i < S; i ++ ) {
                if ( Pos [t] >= Startlen )
                        return Ans [( S - i ) % ( i - Pos [t] + Startlen ) + Pos [t] - Startlen];
                Ans [i] = t; Pos [t] = len ++;
                Next = 0;
                for ( j = 0; j < N; j ++ ) {
                        PreIndex = 0;
                        if ( t & power2 [Num [j]] ) PreIndex = 1;
                        if ( t & power2 [Num [j + 1]] ) PreIndex += 2;
                        if ( t & power2 [Num [j + 3]] ) PreIndex += 4;
                        if ( pre [PreIndex] ) Next = Next | power2 [Num [j + 1]];
                }
                t = Smallest ( Next );
        }
        return  t;
}

main ()
{
        memset ( Pos , 0xff , sizeof ( Pos ));
        while ( init () ) print ( Work () );
}
 