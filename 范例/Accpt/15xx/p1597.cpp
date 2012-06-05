// p1597.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

#define	zero 1e-10
double	x [2] , y [2] , r [2];

double	distance ( double a , double b )
{
	return sqrt ( a * a + b * b );
}

void	Swap ( double &a , double &b )
{	double	t = a; a = b; b = t; }

double	banana ()
{
	double	l = distance ( x [1] - x [0] , y [1] - y [0] );
	if ( r [0] + r [1] <= l ) return 0;
	if ( r [0] > r [1] ) Swap ( r [0] , r [1] );
	if ( l + r [0] < r [1] + zero ) return acos ( -1 ) * r [0] * r [0];

	double	cos1 = ( l * l + r [1] * r [1] - r [0] * r [0] ) / 2 / l / r [1];
	double  cos0 = ( l * l + r [0] * r [0] - r [1] * r [1] ) / 2 / l / r [0];

	double	ret = ( acos ( cos0 ) - sqrt ( 1 - cos0 * cos0 ) * cos0 ) * r [0] * r [0] +
			( acos ( cos1 ) - sqrt (1 - cos1 * cos1 ) * cos1 ) * r[1] * r [1];
	return	ret;
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	while ( scanf ( "%lf%lf%lf%lf%lf%lf" , &x [0] , &y [0] , &r [0] , &x [1] , &y [1] , &r [1] ) != EOF )
		printf ( "%.3lf\n" , banana () );
	return 0;
}
