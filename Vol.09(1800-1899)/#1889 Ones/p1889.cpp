#include <iostream>
using namespace std;

/*	algorithm 
note: x % n = a 
( 10 * x + 1 ) % n 	= ( ( 10 * x ) % n + 1 % n ) % n 
			= ( ( ( 10 % n ) * ( x % n ) ) % n + 1 ) % n
			= ( ( ( 10 % n ) * a ) % n + 1 ) % n
*/

int main() {
	int	n;
	while( cin >> n ) {
		int	a = 1,	count = 1;
		if( n == 1 ) a = 0; 
		while( a != 0 ) {
			a = ( ( ( 10 % n ) * a ) % n + 1 ) % n;
			count++; 
		} 
		cout << count << endl; 
	}  
} 
