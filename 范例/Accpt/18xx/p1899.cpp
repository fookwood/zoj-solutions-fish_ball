// p1899.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning (disable:4786)
#include <stdio.h>
#include <string>
#include <map>
using namespace std;
map <string,int> Data;
map <string,int>::iterator Iter;

int main(int argc, char* argv[])
{
	char	Str [40];
	int	NumTree , first = true;
	while ( gets ( Str ) ) {
		if ( first ) first = false; else printf ( "\n" );
		NumTree = 0;
		Data.clear ();
		do {
			NumTree ++;
			if ( Data.find ( (string) Str ) == Data.end () ) Data [(string) Str] = 1;
				else Data [(string) Str] ++;
		} while ( gets ( Str ) && Str [0] );
		
		for ( Iter = Data.begin (); Iter != Data.end (); Iter ++ )
			printf ( "%s %.4lf\n" , Iter->first.c_str () , Iter->second * 100.0 / NumTree );
	} 

	return 0;
}
