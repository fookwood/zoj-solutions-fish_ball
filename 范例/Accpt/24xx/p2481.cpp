// p2481.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>

using namespace std;

int	N , i , t;
list <int> Data;
list <int>::iterator Iter;

int main(int argc, char* argv[])
{

	while ( scanf ( "%d" , &N ) , N ) {
		Data.clear ();
		for ( i = 0; i < N; i ++ ) scanf ( "%d" , &t ) , Data.push_back ( t );
		Data.sort ();
		Data.unique ();
		for ( Iter = Data.begin (); Iter != Data.end (); Iter ++ ) {
			if ( Iter != Data.begin () ) printf ( " " );
			printf ( "%d" , *Iter );
		}
		printf ( "\n" );
	}
	return 0;
}
