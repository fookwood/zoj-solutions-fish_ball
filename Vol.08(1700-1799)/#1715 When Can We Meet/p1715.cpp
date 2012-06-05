#include <iostream>
using namespace std;

int main() {
	int	N,	Q,	T;
	int	A[101];
	while( cin >> N >> Q ) {
		if( !N && !Q ) break; 
		for( int i = 0; i < 101; i++ )
			A[i] = 0; 
		while( N-- ) {
			cin >> T;
			while( T-- ) {
				int	temp;
				cin >> temp;
				A[temp]++; 
			} 
		} 
		int	t = 0,	pos = 1; 
		for( ; pos < 101; pos++ )
			if( A[pos] > A[t] )
				t = pos; 
		if( A[t] < Q )	cout << 0 << endl;
		else		cout << t << endl; 
	} 
} 
