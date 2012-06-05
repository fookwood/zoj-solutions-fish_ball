#include <cstdio>

void trans( int* A, int N ) {
	int	B[256];
	for( int i = 1; i < N; i <<= 1 ) {
		for( int j = 0; j < i; j ++ ) {
			B[j * 2] = ( A[j] + A[j + i] ) >> 1;
			B[j * 2 + 1] = ( A[j] - A[j + i] ) >> 1;
		}
		for( int j = 0; j < i << 1; j++ )
			A[j] = B[j];
	}	
}

int main() {
	int	N,	A[256];
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		for( int i = 0; i < N; i++ )
			scanf( "%d", A + i );
		trans( A, N );
		for( int i = 0; i < N - 1; i++ )
			printf( "%d ", A[i] );
		printf( "%d\n", A[N - 1] );
	} 
} 
