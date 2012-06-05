// p1563.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int	N;
int	a [101] , p [101] , Min [101] , Sum [101];

int main(int argc, char* argv[])
{
	int	total , i , j , t;
	for ( scanf ( "%d" , &total ); total; total -- ) {
		scanf ( "%d" , &N );
		Sum [0] = 0;
		for ( i = 1; i <= N; i ++ ) scanf ( "%d%d" , &a [i] , &p [i] ) , Sum [i] = Sum [i - 1] + a [i];

		for ( Min [0] = 0 , i = 1; i <= N; i ++ ) {
			Min [i] = 0x7fffffff;
			for ( j = i - 1; j >= 0; j -- ) {
				t = Min [j] + ( Sum [i] - Sum [j] ) * p [i];
				if ( t < Min [i] ) Min [i] = t;
			}
			Min [i] += p [i] * 10;
		}
		printf ( "%d\n" , Min [N] );
	}
	return 0;
}
