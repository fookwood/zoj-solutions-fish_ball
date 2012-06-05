// p1882.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int	N , M;
bool	graph [100] [100];
double X [200] , Y [200];
double	Limit;

int	Link [100];
bool	mk [100];

bool	init ()
{
	int	S , V , i , j;
	double	d;
	if ( scanf ( "%d%d%d%d" , &N , &M , &S , &V ) == EOF ) return false;
	Limit = double ( S ) * V , Limit *= Limit;
	for ( i = 0; i < N; i ++ ) scanf ( "%lf %lf" , &X [i] , &Y [i] );
	for ( i = 0; i < M; i ++ ) scanf ( "%lf %lf" , &X [100 + i] , &Y [100 + i] );

	for ( i = 0; i < N; i ++ )
		for ( j = 0; j < M; j ++ ) {
			d = ( X [i] - X [j + 100] ) * ( X [i] - X [j + 100] ) + ( Y [i] - Y [j + 100] ) * ( Y [i] - Y [j + 100] );
			graph [i] [j] = d <= Limit;
		}
	return true;
}

bool	find ( int v )
{
	int	i , t;
	for ( i = 0; i < M; i ++ ) if ( !mk [i] && graph [v] [i] ) {
		mk [i] = true;
		t = Link [i];
		Link [i] = v;
		if ( t == -1 || find ( t )) return true;
		Link [i] = t;
	}
	return false;
}

int	Ans ()
{
	int	Ret = 0 , i;
	memset ( Link , 0xff , sizeof ( Link ));
	for ( i = 0; i < N; i ++ ) {
		memset ( mk , 0 , sizeof ( mk ));
		if ( find ( i ) ) Ret ++;
	}
	return Ret;
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	while ( init () )
		printf ( "%d\n" , N - Ans ());
	return 0;
}
