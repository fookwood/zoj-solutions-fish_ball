#include <iostream>
#include <string> 
using namespace std;

int main() {
	bool	A[26];
	int	N,	T = 1;
	while( cin >> N ) {
		if( !N ) break;
		cout << "Program #" << T++ << endl;
		A[0] = 1;
		for( int i = 1; i < 26; i++ )
			A[i] = 0;
		while( N-- ) {
			string	x,	y; 
			cin >> x >> y >> y;
			A[x[0] - 'a'] = A[y[0] - 'a'];
		}
		int	count = 0;
		for( int i = 0; i < 26; i++ ) {
			if( A[i] ) {
				putchar( 'a' + i );
				putchar( ' ' );
				count++;
			}
		}
		if( !count )	cout << "none";
		cout << endl << endl;
	} 
} 
