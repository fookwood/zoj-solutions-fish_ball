#include <iostream>
using namespace std;

int main() {
	int	A[101],	B[101],	N,	i,	j;
	while( cin >> N ) {
		if( !N ) break; 
		for( i = 1; i <= N; i++ )	cin >> A[i];
		for( i = 1, j = N; i <= N; i++ ) {
			if( j == 0 ) break;
			if( A[i] >= j ) j--;
			else	j = A[i] - 1; 
		}
		cout << N - i + 1 << endl; 
	} 
} 
