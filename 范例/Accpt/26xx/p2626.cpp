// p2626.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

typedef __int64 int64;

#define	MAXN	51
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define	small 0x8000000000000000
#define	big	0x7fffffffffffffff

int	N;
char	Op [MAXN];
int64	OMax [MAXN] [MAXN] , OMin [MAXN] [MAXN];

bool	init ()
{
	scanf ("%d" , &N ); if ( N == 0 ) return false;
	char	Str [10];
	int	i , p;
	for ( i = 0; i < N; i ++ ) scanf ( "%s%d" , &Str , &p ) , OMax [i] [i] = p , OMin [i] [i] = p , Op [i] = Str [0];
	return true;
}

int64 Dynamic ()
{
	int	i , j , k , l , Next;
	int64	Ret = small;
	for ( l = 1; l < N; l ++ )
		for ( i = 0; i < N; i ++ ) {
			j = ( i + l ) % N;
			OMax [i] [j] = small , OMin [i] [j] = big;

			for ( k = i; k != j; k = Next ) {
				Next = k + 1 == N ? 0 : k + 1;

				if ( Op [Next] == '+' ) {
					OMax [i] [j] = max ( OMax [i] [j] , OMax [i] [k] + OMax [Next] [j] );
					OMin [i] [j] = min ( OMin [i] [j] , OMin [i] [k] + OMin [Next] [j] );
				} else {
					OMax [i] [j] = max ( OMax [i] [j] , OMax [i] [k] * OMax [Next] [j] );
					OMax [i] [j] = max ( OMax [i] [j] , OMax [i] [k] * OMin [Next] [j] );
					OMax [i] [j] = max ( OMax [i] [j] , OMin [i] [k] * OMin [Next] [j] );
					OMax [i] [j] = max ( OMax [i] [j] , OMin [i] [k] * OMax [Next] [j] );

					OMin [i] [j] = min ( OMin [i] [j] , OMax [i] [k] * OMax [Next] [j] );
					OMin [i] [j] = min ( OMin [i] [j] , OMax [i] [k] * OMin [Next] [j] );
					OMin [i] [j] = min ( OMin [i] [j] , OMin [i] [k] * OMax [Next] [j] );
					OMin [i] [j] = min ( OMin [i] [j] , OMin [i] [k] * OMin [Next] [j] );
				}
			}
		}

	for ( Ret = small , i = 0; i < N; i ++ ) {
		j = i ? i - 1 : N - 1;
		Ret = max ( Ret , OMax [i] [j] );
	}

	return Ret;
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	while ( init () ) printf ( "%I64d\n" , Dynamic () );
	return 0;
}
