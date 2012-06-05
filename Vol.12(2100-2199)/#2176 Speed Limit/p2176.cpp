#include <iostream>
using namespace std;

int main() {
	int 	N;
	while( cin >> N ) {
		if( N == -1 ) break;
		int	sum = 0, s, t, tt = 0; 
		while( N-- ) {
			cin >> s >> t;
			sum += s * ( t - tt );
			tt = t; 
		}
		cout << sum << " miles\n"; 
	}
} 
