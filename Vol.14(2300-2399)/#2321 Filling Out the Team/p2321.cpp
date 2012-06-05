#include <iostream>
using namespace std;

int main() {
	float	x,	y,	z;
	float	A[3][3] = { { 4.5, 150., 200. },
			    { 6.0, 300., 500. },
			    { 5.0, 200., 300. } };
	char*	s[4] = { "Wide Receiver",
			 "Lineman",
			 "Quarterback",
			 "No positions" };
	while( cin >> x >> y >> z ) {
		if( x == 0. && y == 0. && z == 0. ) break;
		bool	begin = 1; 
		for( int i = 0; i < 3; i++ ) {
			if( x <= A[i][0] && y >= A[i][1] && z >= A[i][2] ) 
				if( !begin ) cout << ' ' << s[i];
				else	{ begin = 0; cout << s[i]; } 
		} 
		if( begin ) cout << s[3]; 
		putchar( '\n' );
		 
	} 
} 
