#include <cstdio>

int main() {
	int	T,	N,	X[10001];
	X[0] = 0;
	for( int i = 1, j = 1; j < 10001; i++ ) {
		for( int k = 0; k < i && j < 10001; k++ ) {
			X[j] = X[j - 1] + i;
			j++;
		}
	}
	scanf( "%d", &T );
	while( T-- ) {
		while( 1 ) {
			scanf( "%d", &N );
			if( !N ) break;
			printf( "%d %d\n", N, X[N] ); 
		} 
		if( T ) printf( "\n" ); 
	}
} 
