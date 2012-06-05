// p1638_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>

using namespace std;

#define	MAXS	110
#define	MAXN	100100

int	N , A , B , C , Total;
int	a [MAXN] , b [MAXN] , c [MAXN] , s [MAXN];
int	Opt [MAXS] [MAXS] [MAXS] , Sum [MAXS] [MAXS] [MAXS];
int	Num [MAXN];
bool	Used [MAXN];

bool	cmp_a ( const int &i , const int &j )
{
	return a [i] == a [j] ? s [i] > s [j] : a [i] > a [j];
}

bool	cmp_b ( const int &i , const int &j )
{
	return b [i] == b [j] ? s [i] > s [j] : b [i] > b [j];
}

bool	cmp_c ( const int &i , const int &j )
{
	return c [i] == c [j] ? s [i] > s [j] : c [i] > c [j];
}

void	Work ()
{
	int	i , j , k , t , e , TmpSum;
	memset ( Opt , 0xff , sizeof ( Opt )); 
	Opt [0] [0] [0] = 0 , Sum [0] [0] [0] = 0;

	for ( t = 0; t < N; t ++ ) if ( Used [t] ) {
		for ( i = Total; i >= 0; i -- ) {
			if ( i > A ) i = A;
			for ( j = Total - i; j >= 0; j -- ) {
				if ( j > B ) j = B;
				for ( k = Total - i - j; k >= 0; k -- ) {
					if ( k > C ) k = C;
					if ( Opt [i] [j] [k] == -1 ) continue;

					TmpSum = Sum [i] [j] [k] + a [t] + b [t] + c [t];
					e = Opt [i] [j] [k] + a [t];
					if ( e > Opt [i + 1] [j] [k] || e == Opt [i + 1] [j] [k] && TmpSum > Sum [i + 1] [j] [k] )
						Opt [i + 1] [j] [k] = e , Sum [i + 1] [j] [k] = TmpSum;
					e = Opt [i] [j] [k] + b [t];
					if ( e > Opt [i] [j + 1] [k] || e == Opt [i] [j + 1] [k] && TmpSum > Sum [i] [j + 1] [k] )
						Opt [i] [j + 1] [k] = e , Sum [i] [j + 1] [k] = TmpSum;
					e = Opt [i] [j] [k] + c [t];
					if ( e > Opt [i] [j] [k + 1] || e == Opt [i] [j] [k + 1] && TmpSum > Sum [i] [j] [k + 1] )
						Opt [i] [j] [k + 1] = e , Sum [i] [j] [k + 1] = TmpSum;

				}
			}
		}
	}
	printf ( "%d %d\n" , Opt [A] [B] [C] , Sum [A] [B] [C] );
}

void	init ()
{
	int	i , Limit;
	scanf ( "%d%d%d%d" , &N , &A , &B , &C );
	for ( i = 0; i < N; i ++ )
		scanf ( "%d%d%d" , &a [i] , &b [i] , &c [i] ) , s [i] = a [i] + b [i] + c [i];
	Total = A + B + C;
	for ( i = 0; i < N; i ++ ) Num [i] = i;

	Limit = Total + Total > N ? N : Total + Total;

	memset ( Used , 0 , sizeof ( Used ));
	sort ( Num , Num + N , cmp_a );
	for ( i = 0; i < Limit; i ++ ) Used [Num [i]] = true;
	sort ( Num , Num + N , cmp_b );
	for ( i = 0; i < Limit; i ++ ) Used [Num [i]] = true;
	sort ( Num , Num + N , cmp_c );
	for ( i = 0; i < Limit; i ++ ) Used [Num [i]] = true;
}


int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	int	part;
	for ( scanf ( "%d" , &part ); part; part -- ) {
		init ();
		Work ();
	}
	return 0;
}
