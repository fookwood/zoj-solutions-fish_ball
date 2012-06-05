// p1539.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int	N;

int	f ( int n )
{
	if ( n == 3 ) return 1;
	if ( n < 3 ) return 0;
	return ( n & 1 )? f ( n >> 1 ) + f ( ( n + 1 ) >> 1 ) : f ( n >> 1 ) << 1;
}
int main(int argc, char* argv[])
{
	while ( scanf ( "%d" , &N ) != EOF )
		printf ( "%d\n" , f ( N ));
	return 0;
}
