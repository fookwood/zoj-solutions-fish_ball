// p1466.cpp : Defines the entry point for the console application.
//#include "stdafx.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct	TData {
	int		len;
	char	Name [40] [3];
	int	Num [40];
	int		find ( char p [] );
	void	add ( char p [] , int value );
};

struct	TNode {
	char	Str	[200] , StrLen;
	TData	Data;
	void	Search ( int left , int right , int w );
	void	Work ();
	bool	EqualTo ( TNode & a );
}	Dic , Temp;

bool	TNode :: EqualTo ( TNode &a )
{
	if ( Data.len != a.Data.len ) return false;
	int		i , tmp;
	for ( i = 0; i < Data.len; i ++ ) {
		tmp = a.Data.find ( Data.Name [i] );
		if ( tmp != Data.Num [i] ) return false;
	}
	return	true;
}

int	TData :: find ( char p [] )
{
	int		i;
	for ( i = 0; i < len; i ++ ) if ( strcmp ( p , Name [i] ) == 0 ) return Num [i];
	return -1;
}

void	TData :: add ( char p [] , int value )
{
	int		i;
	for ( i = 0; i < len; i ++ ) if ( strcmp ( p , Name [i] ) == 0 ) {
		Num [i] += value; return;
	}
	strcpy ( Name [len] , p );
	Num [len ++] = value;
}

void	TNode :: Search ( int left , int right , int w )
{
	int	tmp , i , j , have;
	char	p [3];

	if ( Str [left] == '(' ) {
		for ( have = 1 , i = left + 1; have ; i ++ )
			if ( Str [i] == '(' ) have ++; else
				if ( Str [i] == ')' ) have --;

		for ( tmp = 0 , j = i; j <= right && isdigit ( Str [j] ); j ++ ) tmp = tmp * 10 + Str [j] - '0';
                if ( tmp == 0 ) tmp = 1;

		if ( j <= right ) Search ( j , right , w );
		Search ( left + 1 , i - 2 , w * tmp );
	} else
		if ( isdigit ( Str [left] ) ) {
			for ( tmp = 0; isdigit ( Str [left] ); left ++ ) tmp = tmp * 10 + Str [left] - '0';
			Search ( left , right , w * tmp );
		} else {
                        if ( islower ( Str [left + 1] ) ) p [0] = Str [left] , p [1] = Str [left + 1] , p [2] = 0 , left += 2;
                                else p [0] = Str [left] , p [1] = 0 , left ++;
                        for ( tmp = 0; left <= right && isdigit ( Str [left] ); left ++ ) tmp = tmp * 10 + Str [left] - '0';
                        if ( tmp == 0 ) tmp = 1;
                        Data.add( p , w * tmp );
                        if ( left <= right ) Search ( left , right , w );
	        }

}

void	TNode :: Work ()
{
	int		i , j;
	StrLen = strlen ( Str );
	for ( i = 0; i < StrLen; i = j + 1 ) {
		for ( j = i + 1; j < StrLen && Str [j] != '+'; j ++ );
		Search ( i , j - 1 , 1 );
	}
}

void	print ( TNode &a )
{
	int	i;
	printf ( "Len = %d\n" , a.Data.len );
	for ( i = 0; i < a.Data.len; i ++ ) 
		printf ( "name = %s num = %d\n" , a.Data.Name [i] , a.Data.Num [i] );
}

int main(int argc, char* argv[])
{
	int		total , N , i;
	for ( scanf ( "%d" , &total ); total; total -- ) {
		scanf ( "%s" , Dic.Str ); Dic.Data.len = 0;
		Dic.Work ();

		scanf ( "%d" , &N );
		for ( i = 0; i < N; i ++ ) {
			scanf ( "%s" , Temp.Str ); Temp.Data.len = 0;

			Temp.Work ();
			if ( Temp.EqualTo ( Dic ) ) printf ( "%s==%s\n" , Dic.Str , Temp.Str );
				else printf ( "%s!=%s\n" , Dic.Str , Temp.Str );
		}

		if ( total > 1 ) printf ( "\n" );
	}
	return 0;
}
