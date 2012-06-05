// 简单的几何题，注意精度就行 

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	const double EPS = 1e-5;
	double	a,	b,	r1,	r2;
	while( cin >> a >> b >> r1 >> r2 ) {
		double	x = a - r1 - r2,
			y = b - r1 - r2;
		if( x < -EPS || y < -EPS ) {
			cout << "No" << endl;
			continue;
		}
		if( fabs( ( r1 + r2 ) * ( r1 + r2 ) - x * x - y * y ) < EPS )
			cout << "Yes" << endl;
		else if( ( r1 + r2 ) * ( r1 + r2 ) - x * x - y * y > 0 )
			cout << "No"  << endl;
		else	cout << "Yes" << endl;
	}
}
