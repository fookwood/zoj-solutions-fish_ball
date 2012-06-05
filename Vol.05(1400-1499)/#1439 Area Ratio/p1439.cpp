#include <cmath>
#include <iostream>
using namespace std;

int main() {
	double x1, y1, z1, x2, y2, z2, x3, y3, z3;
	while( cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 ) {
		double	a = sqrt( ( x1 - x2 ) * ( x1 - x2 ) + 
				  ( y1 - y2 ) * ( y1 - y2 ) + 
				  ( z1 - z2 ) * ( z1 - z2 ) ); 
		double	b = sqrt( ( x1 - x3 ) * ( x1 - x3 ) + 
				  ( y1 - y3 ) * ( y1 - y3 ) + 
				  ( z1 - z3 ) * ( z1 - z3 ) ); 
		double	c = sqrt( ( x3 - x2 ) * ( x3 - x2 ) + 
				  ( y3 - y2 ) * ( y3 - y2 ) + 
				  ( z3 - z2 ) * ( z3 - z2 ) ); 
		cout.setf( ios::fixed );
		cout.precision( 3 ); 
		cout <<	( a + b - c ) * ( b + c - a ) * ( a + c - b ) *
			( a + b - c ) * ( b + c - a ) * ( a + c - b ) /
			( 4. * a * a * b * b * c * c ) << endl; 
	}
} 
