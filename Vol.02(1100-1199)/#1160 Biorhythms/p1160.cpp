#include <iostream>
using namespace std;

int main() {
	int	N,	p,	e,	i,	d;
	cin >> N;
	while( N-- ) {
		int	T = 1; 
		while( cin >> p >> e >> i >> d ) {
			if( p == -1 ) break;
			int	x = (  5544 * ( p % 23 )
				    + 14421 * ( e % 28 )
				    +  1288 * ( i % 33 )
				    ) % 21252 - d;
			if( x <= 0 ) x += 21252;
			cout << "Case " << T++
			     << ": the next triple peak occurs in " 
			     << x << " days." << endl;
		}
		if( N )	cout << endl; 
	} 
} 
