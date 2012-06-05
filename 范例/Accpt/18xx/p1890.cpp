// p1890.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

char	Str [100];

int	Time , LastTime;
double	Speed , Sum;

int main(int argc, char* argv[])
{

//	printf ( "%009.3lf\n" , 0.1);
//	freopen ( "p.in" , "r" , stdin );
	
	int	H , M , S;
	double	Sp;

	for ( Speed = Sum = 0; gets ( Str ); ) 
		if ( strlen ( Str ) > 8 ) {
			sscanf ( Str , "%d:%d:%d %lf" , &H , &M , &S , &Sp );
			Time = H * 3600 + M * 60 + S;
			Sum += double ( Time - LastTime ) * Speed / 3600.0;
			Speed = Sp;
			LastTime = Time;
		} else {
			sscanf ( Str , "%d:%d:%d" , &H , &M , &S );
			Time = H * 3600 + M * 60 + S;
			Sum += double ( Time - LastTime ) * Speed / 3600.0;
			printf ( "%s %.2lf km\n" , Str , Sum );
			Speed = Sp;
			LastTime = Time;
		}


	return 0;
}
