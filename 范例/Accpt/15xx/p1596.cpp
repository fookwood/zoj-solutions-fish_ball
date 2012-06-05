// p1596.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

int	N;
double	p [3];
double Num [1000000];
int	Reach [3];

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );
	int	i , j;
	double	min;

	while ( scanf ( "%lf%lf%lf%d" , &p [0] , &p [1] , &p [2] , &N ) != EOF ) {
		Reach [0] = Reach [1] = Reach [2] = 0;
		Num [0] = 1;

		for ( i = 0; i < N; i ++ ) {
			min = 1e20;
			for ( j = 0; j < 3; j ++ ) {
				while ( p [j] * Num[Reach [j]] <= Num [i] ) Reach [j] ++;
				if ( p [j] * Num [Reach [j]] < min ) min = p [j] * Num [Reach [j]];
			}
			Num [i + 1] = min;
		}
		printf ( "%.f\n" , Num [N] );
	}
	return 0;
}
