#include <iostream> 
using namespace std;

int main() {
	int	N,	n;
	cin >> N; 
	while( N-- ) {
		cin >> n;
		int i = 0; 
		while( n % 2 == 0 ) {
			i++;
			n >>= 1; 
		}
		cout << n << ' ' << i << endl; 
	} 
} 
