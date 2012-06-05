#include <iostream>
using namespace std;

int main() {
	int	N,	count = 1;
	int	h[50]; 
	while( cin >> N ) {
		if( !N ) break;
		int	mean = 0; 
		for( int i = 0; i < N; i++) {
			cin >> h[i];
			mean += h[i]; 
		}
		mean /= N;
		int	mov = 0;
		for( int i = 0; i < N; i++) {
			if( h[i] > mean )
				mov += (h[i] - mean);
		}
		cout << "Set #" << count++ << endl;
		cout << "The minimum number of moves is " << mov << ".\n\n";
	}
} 
