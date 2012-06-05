// p1500.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>

int	N , len1 , len2;
char	Order1 [40] , Order2 [40] , Pos [26];

int	C ( int a , int b )
{
	if ( a < b ) return 0;
	int	ret , i;
	if ( a - b < b ) b = a - b;
	for ( ret = i = 1; i <= b; i ++ ) ret = ret * ( a - i + 1 ) / i;
	return ret;
}

int	kind ( int left , int right )
{
	int	ret = 1 , l , SubTree , Last;
	l = Pos [Order1 [left]] + left - right , left ++;

	for ( SubTree = 0; left <= right; left += Last , l += Last , SubTree ++ )
		Last = Pos [Order1 [left]] - l + 1 , ret *= kind ( left , left + Last - 1 );
	ret *= C ( N , SubTree );
	return ret;
}

int	Ans ()
{
	int	i;
	len1 = strlen ( Order1 ) , len2 = strlen ( Order2 );
	for ( i = 0; i < len1; i ++ ) Order1 [i] -= 'a';
	for ( i = 0; i < len2; i ++ ) Order2 [i] -= 'a' , Pos [Order2 [i]] = i;
	return kind ( 0 , len1 - 1 );
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	while ( scanf ( "%d" , &N ) , N ) {
		scanf ( "%s %s" , Order1 , Order2 );
		printf ( "%d\n" , Ans () );
	}
	return 0;
}
