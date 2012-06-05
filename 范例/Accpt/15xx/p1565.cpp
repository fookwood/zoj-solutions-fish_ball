// p1565.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

bool	Joint , Outside , Cover;
int	S , N , M , Tot;
int	Minx [100] , Miny [100] , Maxx [100] , Maxy [100];

void	init ()
{
	scanf ( "%d%d%d" , &N , &M , &Tot );
	for ( int i = 0; i < Tot; i ++ ) scanf ( "%d%d%d%d" , &Minx [i] , &Miny [i] , &Maxx [i] , &Maxy [i] );
}

bool	range ( int p )
{
	return Minx [p] >= 0 && Miny [p] >= 0 && Minx [p] <= N && Miny [p] <= M
		&& Maxx [p] >= 0 && Maxy [p] >= 0 && Maxx [p] <= N && Maxy [p] <= M;
}

bool	interrupt ( int p , int q )
{
	return ! ( Minx [p] >= Maxx [q] || Miny [p] >= Maxy [q] || Minx [q] >= Maxx [p] || Miny [q] >= Maxy [p] );
}

int	area ( int p )
{
	return ( Maxx [p] - Minx [p] ) * ( Maxy [p] - Miny [p] );
}

void	check ()
{
	int	i , j;
	Joint = Outside = false; Cover = true;
	S = 0;
	for ( i = 0; i < Tot; i ++ ) {
		S += area ( i );
		if ( ! range ( i )) Outside = true;
		for ( j = i + 1; j < Tot; j ++ )
			if ( interrupt ( i , j ) ) { Joint = true; return; }
	}
	if ( S != N * M ) Cover = false;
}

void	print ()
{
	if ( Joint ) { printf ( "NONDISJOINT\n" ); return; }
	if ( Outside ) { printf ( "NONCONTAINED\n" ); return; }
	if ( !Cover ) { printf ( "NONCOVERING\n" ); return; }
	printf ( "OK\n" );
}

int main(int argc, char* argv[])
{
	int	total;
	for ( scanf ( "%d" , &total ); total; total -- ) {
		init ();
		check ();
		print ();
	}
	return 0;
}
