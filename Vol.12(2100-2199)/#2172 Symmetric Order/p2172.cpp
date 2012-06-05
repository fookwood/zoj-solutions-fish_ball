#include <iostream>
using namespace std;

int main() {
	char	A[15][26];
	char*	B[15];
	int	N,	T = 1;
	while( cin >> N ) {
		if( !N ) break;
		int	j = 0;
		for( int i = 0; i < N; i++ ) 
			cin >> A[i];
		for( int i = 0; i < N; i += 2 ) 
			B[j++] = A[i];
		j = N;
		for( int i = 1; i < N; i += 2 ) 
			B[--j] = A[i];
		cout << "SET " << T++ << endl;
		for( int i = 0; i < N; i ++ ) 
			cout << B[i] << endl;
	}
} 
