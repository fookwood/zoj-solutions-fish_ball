#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	double	a,	b,	c;
	int	count = 1;
	cout.setf( ios:: fixed );
	cout.precision(3); 
	while( cin >> a >> b >> c ) {
		int	T;
		if( a == -1 )		T = 1;
		else if( b == -1 )	T = 2; 
		else if( c == -1 )	T = 3; 
		else			break;
		cout << "Triangle #" << count++ << endl;
		switch( T ) {
			case 1:	if( b >= c )	cout << "Impossible." << endl << endl;
				else		cout << "a = " << sqrt( c * c - b * b ) << endl << endl;
				break;
			case 2:	if( a >= c )	cout << "Impossible." << endl << endl;
				else		cout << "b = " << sqrt( c * c - a * a ) << endl << endl;;
				break;
			case 3:			cout << "c = " << sqrt( a * a + b * b ) << endl << endl;;
		}
	} 
} 
