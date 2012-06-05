// p1589.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using	namespace std;

bool	graph [26] [26];
int	len;
struct	TNode {
	char a , b;
}	Data [26 * 26];

bool	comp ( const TNode & a , const TNode & b )
{
	return	a.a == b.a ? a.b < b.b : a.a < b.a;	
}

void	debug ()
{
	int	k = 0; k /= k;
}

void	init ()
{
	memset ( graph , 0 , sizeof ( graph ));
	int	i , N;
	char	Str [5];
	for ( scanf ( "%d" , &N ) , i = 0; i < N; i ++ ) {
		scanf ( "%s" , Str );
		if ( Str [1] == '<' ) graph [Str [0] - 'A'] [Str [2] - 'A'] = true;
			else if ( Str [1] == '>' ) graph [Str [2] - 'A'] [Str [0] - 'A'] = true;
			else debug ();
		if ( !isupper ( Str [0] ) || !isupper ( Str [2] )) debug ();
	}
	len = 0;
}

void	Floyd ()
{
	int	i , j , k;
	for ( k = 0; k < 26; k ++ )
		for ( i = 0; i < 26; i ++ ) if ( graph [i] [k] )
			for ( j = 0; j < 26; j ++ ) if ( graph [k] [j] && !graph [i] [j] )
				graph [i] [j] = true , Data [len].a = i + 'A' , Data[len ++].b = j + 'A';
	sort ( Data , Data + len , comp );
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	int	total , i , t;
	for ( scanf ( "%d" , &total ), t = 1; t <= total; t ++ ) {
		printf  ( "Case %d:\n" , t );
		init ();
		Floyd ();
		for ( i = 0; i < len; i ++ ) printf ( "%c<%c\n" , Data [i].a , Data [i].b );
		if ( len == 0 ) printf ( "NONE\n" );
	}
	return 0;
}
