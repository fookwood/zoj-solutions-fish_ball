// p1583.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int	N;
int	map [500] [500] , Change [500] [500];

bool	init ()
{
	scanf ( "%d", &N ); if ( N == 0 ) return false;
	int	i , j;
	for ( i = 0; i < N; i ++ ) for ( j = 0; j < N; j ++ ) scanf ( "%d" , &map [i] [j] );
	return true;
}

void	MakeAns ()
{
	int	i , j;
	for ( i = 0; i < N; i ++ )
		Change [i] [0] = map [i] [0] , Change [i] [N - 1] = map [i] [N - 1] ,
		Change [0] [i] = map [0] [i] , Change [N - 1] [i] = map [N - 1] [i];
	for ( i = 1; i + 1 < N; i ++ )
		for ( j = 1; j + 1 < N; j ++ )
			Change [i] [j] = ( (map [i] [j] << 2)
			+ (( map [i - 1] [j] + map [i + 1] [j] + map [i] [j - 1] + map [i] [j + 1] ) << 1) 
			+ map [i - 1] [j - 1] + map [i + 1] [j - 1] + map [i - 1] [j + 1] + map [i + 1] [j + 1] ) >> 4;
}

void	Print ()
{
	int	i , j;
	for ( i = 0; i < N; i ++ ) {
		for ( j = 0; j < N; j ++ ) {
			if ( j ) printf ( " " );
			printf ( "%d" , Change [i] [j] );
		}
		printf ( "\n" );
	}
}

int main(int argc, char* argv[])
{
	int	step = 0;
	while ( init () ) {
		printf ( "Case %d:\n" , ++ step );
		MakeAns ();
		Print ();
	}
	return 0;
}
