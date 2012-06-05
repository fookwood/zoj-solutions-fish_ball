#include <iostream>
using namespace std;

int main() {
	int	N,	a,	b;
	cin >> N; 
	while( N-- ) {
		cin >> a >> b;
		cout << ( ( a >= b ) ? "MMM BRAINS" : "NO BRAINS" ) << endl; 
	} 
} 
