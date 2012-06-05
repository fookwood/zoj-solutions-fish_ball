// p1766.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

struct	TPos_ {
	int x , y;
}	D1 , D2 , D3;

double	dis ( TPos_ &a , TPos_ &b )
{
	double l1 = a.x - b.x , l2 = a.y - b.y;
	return sqrt ( l1 * l1 + l2 * l2 );
}


int main(int argc, char* argv[])
{
	int	total;
	double	l1 , l2 , l3;
	double	Ansx , Ansy;
	for ( scanf ( "%d\n" , &total ); total; total -- ) {
		scanf ( "%d,%d" , &D1.x , &D1.y );
		scanf ( "%d,%d" , &D2.x , &D2.y );
		scanf ( "%d,%d" , &D3.x , &D3.y );
		l1 = dis ( D2 , D3 ) , l2 = dis ( D1 , D3 ) , l3 = dis ( D1 , D2 );
		Ansx = ( l1 * D1.x + l2 * D2.x + l3 * D3.x ) / ( l1 + l2 + l3 );
		Ansy = ( l1 * D1.y + l2 * D2.y + l3 * D3.y ) / ( l1 + l2 + l3 );
		printf ( "(%d,%d)(%d,%d)(%d,%d):(%.4lf,%.4lf)\n" , D1.x , D1.y , D2.x , D2.y , D3.x , D3.y , int ( Ansx * 10000 ) / 10000.0 , int ( Ansy * 10000 ) / 10000.0 );
	}
	return 0;
}
