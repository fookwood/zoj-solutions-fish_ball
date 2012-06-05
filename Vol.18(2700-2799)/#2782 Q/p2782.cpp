#include <iostream>
using namespace std;

int main() {
	int	T,	N,	O,	x,	y,	A[22],	B[22];
	string	C[22];
	cin >> T; 
	while( T-- ) {
		cin >> N >> O;
		for( int i = 1; i <= N; i++ ) {
			A[i] = i;
			B[i] = -1;
			cin >> C[i];
		}
		while( O-- ) {
			cin >> x >> y;
			B[y] = x;
			A[x] = -1;
		}
		int	j = 1,	k = 1;
		while( j <= N && k <= N ) {
			while( A[j] == -1 && j <= N ) j++;
			while( B[k] != -1 && k <= N ) k++;
			B[k] = A[j];
			A[j] = -1;
		}
		for( int i = 1; i < N; i++ )
			cout << C[B[i]] << ' ';
		cout << C[B[N]] << endl;
	} 
} 
