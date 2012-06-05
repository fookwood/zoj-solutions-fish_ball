// p1800.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int	N , L , M , NameLen;
char	Name [600] [20];
bool	edge [600] [600];
int	Opt [2] [600];

bool	init ()
{
	scanf ( "%d%d%d" , &N , &L , &M);
	if ( N == 0 && M == 0 && L == 0 ) return false;
	for ( int i = 0; i < M; i ++ ) scanf ( "%s" , Name [i] );
	NameLen = strlen ( Name [0] );
	return true;
}

int Work ()
{
	if ( NameLen > L ) return 0;

	int	i , j , k , a , b , Ret = 0;
	for ( i = 0; i < M; i ++ )
		for ( j = 0; j < M; j ++ ) {
			for ( k = 1; k < NameLen && Name [i] [k] == Name [j] [k - 1]; k ++ );
			edge [i] [j] = k == NameLen;
		}


	for ( i = 0; i < M; i ++ ) Opt [0] [i] = 1;
	for ( a = 0 , b = 1 , k = NameLen; k < L; k ++ , a = b , b = 1 - b )
		for ( i = 0; i < M; i ++ )
			for ( Opt [b] [i] = 0 , j = 0; j < M; j ++ ) if ( edge [j] [i] ) Opt [b] [i] += Opt [a] [j];
	for ( i = 0; i < M; i ++ ) Ret += Opt [a] [i];

	return Ret;
}

int main(int argc, char* argv[])
{
	while ( init () ) {
		printf ("%d\n" , Work () );
	}
	return 0;
}
