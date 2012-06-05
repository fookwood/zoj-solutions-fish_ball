// p1524.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int	N , M;
int	Card [101];
double	Min [101];

int main(int argc, char* argv[])
{
	int	i , Max , j , a;
	double	tmp;
	while ( scanf ( "%d%d" , &N , &M ) , N || M ) {
		for ( i = 1; i <= N; i ++ ) scanf ( "%d" , &Card [i] );
		Min [0] = 0; Max = 0;
		for ( j = 0; j < M; j ++ ) {
			scanf ( "%d%lf" , &a , &tmp );
			if ( Max < N ) Min [Max + 1] = 1e10;
			for ( i = Max; i >= 0; i -- ) if ( i < N && Card [i + 1] == a && Min [i] + tmp < Min [i + 1] )
				Min [i + 1] = Min [i] + tmp;
			if ( Max < N && Card [Max + 1] == a ) Max ++;
		}
		if ( Max == N ) printf ( "%.2lf\n" , Min [N] );
			else printf ( "Impossible\n" );
	}
	return 0;
}
