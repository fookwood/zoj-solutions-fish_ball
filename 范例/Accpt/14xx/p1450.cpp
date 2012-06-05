// p1450.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#define	zero	1e-5

struct	TPoint {
	double	x , y;
};
struct	TCircle {
	TPoint	C;
	double	R;
};

int		N;
TPoint	Data [100];
TCircle	Ans; 

double	distance ( TPoint &a , TPoint &b )
{
	return	( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y );
}

bool	CoverAll ( TCircle &a )
{
	int		i;
	for ( i = 0; i < N; i ++ )
		if ( distance ( Data [i] , a.C ) > a.R + zero ) return false;
	return	true;
}

void	Func ( TPoint &a , TPoint &b , double &A , double &B , double &C )
{
	TPoint	Mid;
	Mid.x = ( a.x + b.x ) / 2 , Mid.y = ( a.y + b.y ) / 2;
	if ( a.x == b.x ) A = 0 , B = 1 , C = Mid.y; else
		if ( a.y == b.y ) A = 1 , B = 0 , C = Mid.x; else
			A = 1 , B = ( b.y - a.y ) / ( b.x - a.x ) , C = Mid.x + Mid.y * B;
}

TCircle	Min_Circle ()
{
	TCircle		Ret;

	Ret.R = 1e10;
	if ( N == 1 ) Ret.C = Data [1] , Ret.R = 0; else {
		int		i , j , k;
		TCircle	Mid;
		for ( i = 0; i < N; i ++ ) 
			for ( j = 0; j < N; j ++ ) {
				Mid.C.x = ( Data [i].x + Data [j].x ) / 2 , Mid.C.y = ( Data [i].y + Data [j].y ) / 2;
				Mid.R = distance ( Data [i] , Mid.C );
				if ( Mid.R + zero < Ret.R && CoverAll ( Mid ) ) Ret = Mid;
			}

		double	A1 , B1 , C1 , A2 , B2 , C2 , CC;
		for ( i = 0; i < N; i ++ )
			for ( j = i + 1; j < N; j ++ )
				for ( k = j + 1; k < N; k ++ ) {
					Func ( Data [i] , Data [j] , A1 , B1 , C1 );
					Func ( Data [j] , Data [k] , A2 , B2 , C2 );
					CC = A1 * B2 - A2 * B1;
					if ( CC < zero && CC > - zero ) continue;
					Mid.C.x = ( C1 * B2 - C2 * B1 ) / CC;
					Mid.C.y = ( A1 * C2 - A2 * C1 ) / CC;
					Mid.R = distance ( Data [i] , Mid.C );
					if ( Mid.R + zero < Ret.R && CoverAll ( Mid )) Ret = Mid;
				}
	}
	return	Ret;
}

int main(int argc, char* argv[])
{

	int		i;
	while ( scanf ( "%d" , &N ) , N ) {
		for ( i = 0; i < N; i ++ ) scanf ( "%lf%lf" , &Data [i].x , &Data [i].y );
		Ans = Min_Circle ();
		printf ( "%.2lf %.2lf %.2lf\n" , Ans.C.x , Ans.C.y , sqrt (Ans.R) );
	}
	return 0;
}
