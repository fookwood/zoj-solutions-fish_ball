// p1893.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

unsigned int	N;

bool	StanWins ()
{
//	printf ( "%u\n" , N );
	if ( N == 1 ) return true;
	int	step;
	for ( step = 1; N > 1; step ++ )
		if ( step & 1 ) N = ( N - 1 ) / 9 + 1;
			else N = ( N + 1 ) / 2;
	return ( step & 1 ) == 0;
}

int main(int argc, char* argv[])
{
//	freopen ( "p.in" , "r" , stdin );

	while ( scanf ( "%u" , &N ) != EOF )
		if ( StanWins () ) printf ( "Stan wins.\n" );
			else printf ( "Ollie wins.\n" );
	return 0;
}
