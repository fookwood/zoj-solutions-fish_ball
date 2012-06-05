#include <iostream>
using namespace std;

int perm( int a ) {
	int	prod = 1;
	for( int i = 2; i <= a; i++ ) prod *= i;
	return	prod;
}

int comb( int m, int n ) {
	if( n > m - n )	return comb( m, m - n ); 
	if( !n )	return 1; 
	int	prod1 = perm( n );
	int	prod2 = m;
	while( --n )	prod2 *= ( --m );
	return	prod2 / prod1;
}

int main() {
	int	A[12],	N,	temp;
	while( cin >> N ) {
		for( int i = 0; i < 12; i++)	A[i] = 0;
		int	sum = 0,	result = 1;
		for( int i = 0; i < N; i++ ) {
			cin >> temp;
			A[ temp - 1 ]++;
			sum += temp; 
		}
		for( int i = 0; i < 12; i++ ){
			if( A[i] ) {
				for( int j = 0; j < A[i]; j++ ) {
					result *= comb( sum, i + 1 );
					sum -= ( i + 1 ); 
				}
				result /= perm( A[i] ); 
			}
		}
		cout << result << endl; 
	} 
} 
