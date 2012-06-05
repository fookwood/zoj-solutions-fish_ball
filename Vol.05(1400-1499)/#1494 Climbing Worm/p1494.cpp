#include <iostream>
using namespace std;

int main() {
	int	a,	b,	c;
	while( cin >> a >> b >> c ) {
		if( !a && !b && !c ) break;
		int	h = 0,	t = 0;
		while( h < a ) {
			if( t % 2 )	h -= c;
			else		h += b; 
			t++; 
		} 
		cout << t << endl; 
	} 
} 
