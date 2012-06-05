#include <iostream>
using namespace std;

int main() {
	int	N;
	cin >> N;
	while( N-- ) {
		unsigned int	a,	b = 1;
		cin >> a;
		int	i = 0; 
		bool	first = 1; 
		for( ; b <= a; b <<= 1, i++ ) {
			if( b & a ) {
				if( !first ) cout << ' '; 
				cout << i;
				first = 0;
			} 
		}
		cout << endl;
		
	} 
} 
