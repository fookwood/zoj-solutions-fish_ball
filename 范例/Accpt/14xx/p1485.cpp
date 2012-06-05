// p1485.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		N , Q;
int		map [100] [100];
bool	Reach [10001];
int		Line [10000] , len;

bool	check ( int sum ) 
{
	int		i;
	for ( i = 0; i < len; i ++ ) if ( Line [i] == sum ) return false;
	Line [len ++] = sum;
	return	true;
}

void	Gen ()
{
	int		i , j , k;
	int		sum;
	while ( true ) {
		memset ( Reach , 0 , sizeof ( Reach ) );
		for ( i = 0; i < N; i ++ )
			for ( j = 0; j < N; j ++ ) {
				for ( k = rand () % Q; Reach [k]; ) if ( ++k == Q ) k = 0;
				Reach [k] = true;
				map [i] [j] = k + 1;
			}

		len = 0;
		for ( i = 0; i < N; i ++ ) {
			for ( sum = j = 0; j < N; j ++ ) sum += map [i] [j];
			if ( !check ( sum ) ) break;
		}
		if ( i < N ) continue;

		for ( i = 0; i < N; i ++ ) {
			for ( sum = j = 0; j < N; j ++ ) sum += map [j] [i];
			if ( !check ( sum ) ) break;
		}
		if ( i < N ) continue;

		for ( sum = i = 0; i < N; i ++ ) sum += map [i] [i];
		if ( !check ( sum )) continue;

		for ( sum = i = 0; i < N; i ++ ) sum += map [i] [N - i - 1];
		if ( !check ( sum )) continue;

		for ( i = 0; i < N; i ++ ) {
			for ( j = 0; j < N; j ++ ) {
				if ( j ) printf ( " " );
				printf ( "%d" , map [i] [j] );
			}
			printf ( "\n" );
		}
		break;
	}
}

int main(int argc, char* argv[])
{
	while ( scanf ( "%d" , &N ) != EOF ) {
		Q = N * N;
		if ( N == 1 ) printf ( "1\n" ); else
			if ( N == 2 ) printf ( "1 3\n2 4\n" ); else
				Gen ();
		printf ( "\n" );
	}
	return 0;
}
