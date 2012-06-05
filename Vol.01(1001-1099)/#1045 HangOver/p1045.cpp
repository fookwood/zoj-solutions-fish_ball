#include <iostream>
using namespace std;

int main() {
	float	x;
	while( cin >> x ) {
		if( x == 0. )	break;
		int	n = 2;
		while( x > 0 )
			x -= 1. / float( n++ );
		cout << n - 2 << " card(s)" << endl; 
	} 
} 
