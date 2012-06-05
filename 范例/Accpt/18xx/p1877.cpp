// p1877.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
#define	min(a,b) (a<b?a:b)
using namespace std;

int	N , Speed [1000] , MinTime;

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	int	i , j , a , b;
	while ( scanf ( "%d" , &N ) != EOF ) {
		for ( i = 0; i < N; i ++ ) scanf ( "%d" , &Speed [i] );
		sort ( Speed , Speed + N );
	
		if ( N == 1 ) { printf ( "%d\n%d\n" , Speed [0] , Speed [0] ); continue; }
		if ( N == 2 ) { printf ( "%d\n%d %d\n" , Speed [1] , Speed [0] , Speed [1] ); continue; }

//		for ( i = 0; i < N;i ++ ) printf ( "%d " , Speed [i] ); printf ( "\n" );
		a = Speed [0] , b = Speed [1];

		for ( MinTime = 0 , j = N - 2; j >= 2; j -= 2 )
			MinTime += min ( a + a + Speed [j] + Speed [j + 1] , a + b + b + Speed [j + 1] );

		MinTime += j == 0 ? b : Speed [0] + Speed [1] + Speed [2];
		printf ( "%d\n" , MinTime );

		for ( j = N - 2; j >= 2; j -= 2 )
			if ( a + Speed [j] < b + b )
				printf ( "%d %d\n%d\n%d %d\n%d\n" , a , Speed [j] , a , a , Speed [j + 1] , a );
			else
				printf ( "%d %d\n%d\n%d %d\n%d\n" , a , b , a , Speed [j + 1] , Speed [j] , b );
		if ( j == 0 ) printf ( "%d %d\n" , a , b );
			else printf ( "%d %d\n%d\n%d %d\n" , a , Speed [2] , a , a , b );

	}
	return 0;
}
