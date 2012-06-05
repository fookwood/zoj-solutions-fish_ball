// p1888.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#pragma warning ( disable:4786 )

#include <stdio.h>
#include <ctype.h>
#include <map>
#include <string>

using namespace std;

struct ltstr {
	bool operator () ( char * s1 , char * s2 )
	{
		return strcmp ( s1 , s2 ) < 0;	
	}
};

map < char * , int , ltstr >	Words;
map < char * , int , ltstr >::iterator	Iter;

char	name [10001] [30];

int main(int argc, char* argv[])
{
	int	N , len , i , j;
	int	first = true;
	char	Str [30];
	while ( scanf ( "%d" , &N ) != EOF ) {
		if ( first ) first = false; else printf ( "\n" );
		Words.clear ();
		scanf ( "%[^a-zA-Z]" , Str );
		j = 0;
		while ( scanf ( "%[a-zA-Z]" , Str ) , strcmp ( Str , "EndOfText" ) ) {
			for ( len = strlen ( Str ) , i = 0; i < len; i ++ ) Str [i] = tolower ( Str [i] );
			
			Iter = Words.find ( Str );
			if ( Iter != Words.end () ) Iter->second ++;
			else strcpy ( name [j] , Str ) , Words [ name [j++]] = 1;

			scanf ( "%[^a-zA-Z]" , Str );
		}
		int have = false;
		for ( Iter = Words.begin (); Iter != Words.end (); Iter ++ )
			if ( Iter->second == N ) printf ( "%s\n" , Iter->first ) , have = true;
		if ( !have ) printf ( "There is no such word.\n" );


	}
	return 0;
}
