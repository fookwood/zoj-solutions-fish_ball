#include <cmath> 
#include <iostream>
using namespace std;

int	gcd( int m, int n ) {
	if( m < n ) return gcd( n, m ); 
	if( !n ) return m;
	return	 gcd( n, m % n );
} 

int main() {
	int	N,	A[50];
	cout.setf( ios::fixed );
	cout.precision(6);
	while( cin >> N ) {
		if( !N ) break;
		for( int i = 0; i < N; i++ )
			cin >> A[i];
		double	total = 0,	feasible = 0;
		for( int i = 0; i < N - 1; i++ )
		for( int j = i + 1; j < N; j++ ) {
			total += 1;
			if( gcd( A[i], A[j] ) == 1 )
				feasible += 1;
		}
		if( feasible == 0 )
			cout << "No estimate for this data set." << endl;
		else
			cout << sqrt( total / feasible * 6. ) << endl;
	} 
} 
