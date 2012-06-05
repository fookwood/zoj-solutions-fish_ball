// p1642.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#define	MaxSize	2000

int	LenA , LenB;
char	A [MaxSize] , B [MaxSize];
int	value [255] , N , Opt [MaxSize] [MaxSize];

bool	init ()
{
	if ( scanf ( "%d\n" , &N ) == EOF ) return false;
	char	tmp;
	memset ( value , 0 , sizeof ( value ));
	for ( int i = 0; i < N; i ++ )
			scanf ( "%c" , &tmp ) , scanf ( "%d\n" , &value [tmp] );
	scanf ( "%s" , A );
	scanf ( "%s" , B );
	LenA = strlen ( A ) , LenB = strlen ( B );
	return true;
}

int	Max ()
{
	int	i , j;
	for ( i = 0; i < LenA; i ++ ) Opt [0] [i] = A [0] == B [i] ? value [B [i]] : 0;
	for ( i = 1; i < LenB; i ++ ) Opt [i] [0] = A [i] == B [0] ? value [A [i]] : 0;

	for ( i = 1; i < LenA; i ++ )
		for ( j = 1; j < LenB; j ++ ) {
			Opt [i] [j] = Opt [i - 1] [j] > Opt [i] [j - 1] ? Opt [i - 1] [j] : Opt [i] [j - 1];
			if ( A [i] == B [j] )
				if ( Opt [i - 1] [j - 1] + value [A [i]] > Opt [i] [j] ) Opt [i] [j] = Opt [i - 1] [j - 1] + value [A [i]];
		}
	return Opt [LenA - 1] [LenB - 1];
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	while ( init () )
		printf ( "%d\n" , Max () );
	return 0;
}
