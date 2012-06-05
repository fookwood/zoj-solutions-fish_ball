#include <iostream>
using namespace std;

int main() {
	const float	PI_100 = .03141592654; 
	int	N,	year;
	float	x,	y;
	cin >> N; 
	for( int i = 1; i <= N; i++ ) {
		cin >> x >> y;
		year = int( PI_100 * ( x * x + y * y ) ) + 1; 
		cout << "Property " << i 
		     << ": This property will begin eroding in year "
		     << year << "." << endl;
	}
	cout << "END OF OUTPUT." << endl; 
} 
