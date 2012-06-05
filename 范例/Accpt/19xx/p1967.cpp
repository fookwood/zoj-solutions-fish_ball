// p1967.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int		N;
int		Data [200] [200];
int		Pow [26];

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );
	//freopen ( "p.out" , "w" , stdout );

	int		i , j , k , a , b , len;
	for ( i = 0; i < 26; i ++ ) Pow [i] = 1 << i;

	char	str [30];
	while ( scanf ( "%d" , &N ) , N ) {
		for ( i = 0; i < N; i ++ ) for ( j = 0; j < N; j ++ ) Data [i] [j] = 0;
		while ( scanf ( "%d%d" , &a , &b ) , a && b ) {
			a -- , b -- , scanf ( "%s" , str );
			len = strlen ( str );
			for ( i = 0; i < len; i ++ ) Data [a] [b]  |= Pow [str [i] - 'a'];
		}
		for ( k = 0; k < N; k ++ )
			for ( i = 0; i < N; i ++ ) if ( i != k )
				for ( j = 0; j < N; j ++ ) if ( j != i && j != k )
					Data [i] [j] |= Data [i] [k] & Data [k] [j];

		while ( scanf ( "%d%d" , &a , &b ) , a && b ) {
			k = 0 , a -- , b --;
			for ( i = 0; i < 26; i ++ ) if ( Data [a] [b] & Pow [i] ) printf ("%c" , i + 'a' ) , k = 1;
			if ( !k ) printf ( "-" );
			printf ( "\n" );
		}
				
		printf ( "\n" );
	}
	return 0;
}
