#include <iostream>
using namespace std;
int main() {
	cout.setf( ios :: fixed );
	cout.precision( 2 );
	float	a = 0,	b;
	for( int i = 0; i < 12; i++ ) {
		cin >> b;
		a += b; 
	}
	cout << '$' << a / 12. << endl; 
} 
