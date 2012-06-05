#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const   int     Pow [10] = { 1 , 10 , 100 , 1000 , 10000 , 100000 , 1000000 , 10000000 , 100000000 , 1000000000 };

int     N , Long;
int     len , Ans [100];

void    Work ()
{
        len = 0;
        for ( Long = 0; Long < 10 && Pow [Long] <= N; Long ++ );
        Long --;
        int     i , k , tmp , A , B;
        for ( i = 0; i <= Long; i ++ ) {
                tmp = N / Pow [i];
                A = tmp / 11;
                k = tmp % 11;
                tmp = N % Pow [i];
                if ( tmp % 2 || A + k == 0 ) continue;
                B = tmp / 2;
                if ( k < 10 )
                Ans [len ++] = A * Pow [i] * 10 + k * Pow [i] + B;
                if ( k == 0 || i == 0 ) continue;
                k --; B += Pow [i] >> 1;
                if ( A + k == 0 ) continue;
                Ans [len ++] = A * Pow [i] * 10 + k * Pow [i] + B;
        }
        sort ( Ans , Ans + len );

        k = 0; if ( len )
        for ( k = i = 1; i < len; i ++ ) if ( Ans [i] != Ans [i - 1] )
                Ans [k ++] = Ans [i];
        len = k;
}

main ()
{
//        freopen ( "p.in" , "r" , stdin );
//        freopen ( "p.out" , "w" , stdout );

        int     total , i , j , len1 , len2;
        for ( scanf( "%d" , &total ); total; total -- ) {
                scanf ( "%d" , &N );
                Work ();
                printf ( "%d\n" , len );
                for ( i = 0; i < len; i ++ ) {
                        printf ( "%d + " , Ans [i] );
                        len1 = Ans [i] ? log10 ( Ans [i] ) + 1: 1;
                        len2 = N - Ans [i] ? log10 ( N - Ans [i] ) + 1 : 1;
                        for ( j = len2 + 1; j < len1; j ++ ) printf ( "0" );
                        printf ( "%d = %d\n" , N - Ans [i] , N );
                }
                if ( total > 1 ) printf ( "\n" );
        }
}
 