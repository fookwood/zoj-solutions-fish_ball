// p1542.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int	N , M;
int graph [1000] [1000] , Len [1000] , value [1000] [1000];
int	Contacta [1000] , Contactb [1000] , Min;

bool	init ()
{
	if ( scanf ( "%d%d" , &N , &M ) == EOF ) return false;
	int	i , a , b, c;
	memset ( Len , 0 , sizeof ( Len ));
	for ( i = 0; i < M; i ++ )
		scanf ( "%d%d%d" , &a , &b , &c ) , a -- , b -- , 
		value [a] [Len [a]] = c , graph [a] [Len [a] ++] = b , 
		value [b] [Len [b]] = c , graph [b] [Len [b] ++] = a;
	return true;
}

void	FindAns ()
{
	int	MinCost [1000] , father [1000] = {0} , i , j , k;
	bool	Mark [1000] = {0};

	Min = 0;
	for ( i = 0; i < N; i ++ ) MinCost [i] = 0x7fffffff;
	for ( i = 0; i < Len [0]; i ++ ) if ( value [0] [i] < MinCost [graph [0] [i]] ) MinCost [graph [0] [i]] = value [0] [i];

	for ( i = 0; i + 1 < N; i ++ ) {
		for ( k = -1 , j = 1; j < N; j ++ ) if ( !Mark [j] )
			if ( k == -1 || MinCost [j] < MinCost [k] ) k = j;

		Contacta [i] = father [k] , Contactb [i] = k;
		Mark [k] = true;
//		printf ( "%d %d\n" , k , MinCost [k] );
		if ( MinCost [k] > Min ) Min = MinCost [k];
		for ( j = 0; j < Len [k]; j ++ ) if ( !Mark [graph [k] [j]] && value [k] [j] < MinCost [graph [k] [j]] )
			MinCost [graph [k] [j]] = value [k] [j] , father [graph [k] [j]] = k;
	}
}

void	PrintAns ()
{
	printf ( "%d\n%d\n" , Min , N - 1 );
	for ( int i = 0; i + 1 < N; i ++ ) printf ( "%d %d\n" , Contacta [i] + 1 , Contactb [i] + 1 );
}

int main(int argc, char* argv[])
{
	while ( init () ) {
		FindAns ();
		PrintAns ();
	}
	return 0;
}
