#include <iostream>
using namespace std;

void reverse( long &x ) {
	long	temp = 0;
	while( x ) {
		temp *= 10;
		temp += x % 10;
		x /= 10;
	}
	x = temp;
}

int main() {
	int	N;
	long	x,	y;
	cin >> N;
	while( N-- ) {
		cin >> x >> y;
		reverse( x );
		reverse( y );
		x += y;
		reverse( x );
		cout << x << endl;
	}
}
