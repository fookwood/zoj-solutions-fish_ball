#include <iostream>
using namespace std;

int main() {
	int	T,	a,	b;
	cin >> T;
	while( T-- ) {
		cin >> a >> b; 
		if( ( a % 2 == 0 ) ^ ( b % 2 == 0 ) ) 
			cout << "impossible" << endl;
		else if( a >= b && a >= 0 && b >= 0 ) 
			cout << ( a + b ) / 2 << ' '
			     << ( a - b ) / 2 << endl;
		else	cout << "impossible" << endl; 
	} 
} 
