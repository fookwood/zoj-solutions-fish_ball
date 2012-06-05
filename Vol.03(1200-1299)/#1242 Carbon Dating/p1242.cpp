#include <iostream>
#include <cmath> 
using namespace std;

int main() {
	double	x,	y; 
	int	count = 1; 
	while( cin >> x >> y ) {
		if( !x && !y ) break;
		cout << "Sample #" << count++ << endl;
		double	ans = - log( y / 810. / x ) / log( 2. ) * 5730.;
		long	output;
		if( ans < 10000 )	output = long( round( ans / 100 ) * 100 );
		else			output = long( round( ans / 1000 ) * 1000 );
		cout 	<< "The approximate age is " << output << " years.\n\n";
	}
} 
