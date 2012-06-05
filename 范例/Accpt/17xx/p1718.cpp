// p1718.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

struct	TPos_ {
	double x , y , z , r;
}	Data [100];

int	N;
bool	mk [100];
double	Dis [100] [100] , min [100];

double sqr ( double t )
{ 
	return t * t;
}

double	Distance ( int a , int b )
{
	double l = sqrt ( sqr ( Data [a].x - Data [b].x ) + sqr ( Data [a].y - Data [b].y ) + sqr ( Data [a].z - Data [b].z ) );
	if ( l < Data [a].r + Data [b].r ) return 0;
		else return l - Data [a].r - Data [b].r;
}

bool	init ()
{
	scanf ( "%d" , &N );
	if ( N == 0 ) return false;
	int	i , j;
	for ( i = 0; i < N; i ++ ) scanf ( "%lf %lf%lf%lf" , &Data [i].x , &Data [i].y , &Data [i].z , &Data [i].r );
	for ( i = 0; i < N; i ++ )
		for ( j = i + 1; j < N; j ++ )
			Dis [i] [j] = Dis [j] [i] = Distance ( i , j );
	return true;
}

double Prim ()
{
	int	i , j ,k;
	double	Ret = 0;
	memset ( mk , 0 , sizeof ( mk ));
	for ( i = 0; i < N; i ++ ) min [i] = 1e10; min [0] = 0;
	for ( i = 0; i < N; i ++ ) {
		for ( k = -1 , j = 0; j < N; j ++ ) if ( !mk [j] )
			if ( k == -1 || min [j] < min [k] ) k = j;
		mk [k] = true;
		Ret += min [k];
		for ( j = 0; j < N; j ++ ) if ( !mk [j] && Dis [k] [j] < min [j] ) min [j] = Dis [k] [j];
	}
	return Ret;
}

int main(int argc, char* argv[])
{
	while ( init () ) {
		printf ( "%.3lf\n" , Prim () );
	}
	return 0;
}
