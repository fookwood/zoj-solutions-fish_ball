// p1609.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define	MAX	6

const	int	Pow [7] = { 1 , 2 , 4 , 8 , 16 , 32 , 64 };

int		N , Value;
int		graph [MAX] [MAX] , mindis [MAX] [MAX];
bool	UseIt [MAX] [MAX];
int		Contain [MAX];

void	Search ( int x , int y , int cost ) 
{
	int		i;
	bool	flag = true;
	if ( x == N ) {
		for ( i = 0; flag && i < N; i ++ ) if ( Contain [i] + 1 != Pow [N] ) flag = false;
		if ( flag && cost < Value ) Value = cost;
		return;
	}
	if ( cost >= Value ) return;

	if ( y + 1 == N ) Search ( x + 1 , 0 , cost ); else Search ( x , y + 1 , cost );
	if ( x == y || !UseIt [x] [y] || Contain [x] & Pow [y] ) return;

	int		Save [MAX];
	memcpy ( Save , Contain , sizeof ( Contain ));
	Contain [x] |= Pow [y] | Contain [y];
	for ( i = 0; i < N; i ++ ) if ( Contain [i] & Pow [x] ) Contain [i] |= Contain [x];
	
	if ( y + 1 == N ) Search ( x + 1 , 0 , cost + graph [x] [y] ); else Search ( x , y + 1 , cost + graph [x] [y] );	
	memcpy ( Contain , Save , sizeof ( Contain ));
}

int main(int argc, char* argv[])
{
	int		i , j , k;
	while ( scanf ( "%d" , &N ) != EOF ) {
		for ( i = 0;i < N; i ++ )	
			for ( j = 0; j < N; j ++ )
				scanf ( "%d" , &graph [i] [j] ) , mindis [i] [j] = graph [i] [j];

		for ( k = 0; k < N; k ++ ) 
			for ( i = 0; i < N; i ++ ) if ( i != k )
				for ( j = 0; j < N; j ++ ) if ( j != i && j != k ) 
					if ( mindis [i] [k] + mindis [k] [j] < mindis [i] [j] ) 
						mindis [i] [j] = mindis [i] [k] + mindis [k] [j];

		for ( i = 0; i < N; i ++ )
			for ( j = 0; j < N; j ++ )
				UseIt [i] [j] = mindis [i] [j] == graph [i] [j];
		Value = 0x7fffffff;
		memset ( Contain , 0 , sizeof ( Contain ));
		Search ( 0 , 0 , 0 );
		printf ( "%d\n" , Value );
	}
	return 0;
}
