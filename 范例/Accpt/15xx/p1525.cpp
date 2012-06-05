// p1525.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int	N , M , Ans;
bool	graph [130] [130] , Mark [130];
int	Link [130];

bool	find ( int v )
{
	int	i , t;
	for ( i = 1; i <= N; i ++ ) if ( !Mark [i] && graph [v] [i] ) {
		t = Link [i];
		Link [i] = v;
		Mark [i] = true;
		if ( t == 0 || find ( t ) ) return true;
		Link [i] = t;
	}
	return false;
}

int main(int argc, char* argv[])
{
	freopen ( "p.in" , "r" , stdin );

	int	total , i , a , b;
	for ( scanf ( "%d" , &total ); total; total -- ) {
		memset ( graph , 0 , sizeof ( graph ));
		scanf ( "%d%d" , &N , &M );
		for ( i = 0; i < M; i ++ ) scanf ( "%d%d" , &a , &b ) , graph [a] [b] = true;
		memset ( Link , 0 , sizeof ( Link ));
		for ( Ans = 0 , i = 1; i <= N; i ++ ) {
			memset ( Mark , 0 , sizeof ( Mark ));
			if ( find ( i ) ) Ans ++;
		}
		printf ( "%d\n" , N - Ans ); 
	}
	return 0;
}
