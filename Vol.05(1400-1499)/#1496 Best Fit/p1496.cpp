// ¼òµ¥Ã¶¾Ù 

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;
const double EPS = 1e-5;

inline double size( int x, int y, double D ) {
	return	double( double( x ) / double( y ) * PI * D );
}

int main() {
	int	T,	ff[3],	rr[9];
	double	D,	target;
	cin >> T;
	cout.setf( ios :: fixed );
	cout.precision( 3 );
	while( T-- ) {
		int	fmin,	rmin;
		double	min = 1e999,	diff,	value;
		cin >> ff[0] >> ff[1] >> ff[2]
		    >> rr[0] >> rr[1] >> rr[2]
		    >> rr[3] >> rr[4] >> rr[5]
		    >> rr[6] >> rr[7] >> rr[8]
		    >> D >> target;
		for( int i = 0; i < 3; i++ ) {
			for( int j = 0; j < 9; j++ ) {
				diff = size( ff[i], rr[j], D ) - target;
				if( fabs( diff ) < min ) {
					fmin = i;
					rmin = j;
					value = target + diff;
					min = fabs( diff );
				}
				if( diff < EPS )	break;
			}
		}
		cout << "A gear selection of " << ff[fmin] << '/' << rr[rmin]
		     << " produces a gear size of " << value << '.' << endl;
		if( T )	cout << endl;
	}
}
