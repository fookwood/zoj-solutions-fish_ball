#include <cstdio>

int	M,	N,	K;
int	A[1000][1000];

void kick( int i, int j ) {
	for( int x = i - 1; ; x-- ) {
		if( x < 0 ) break; 
		if( A[x][j] )	kick( x, j );
	}
	for( int k = 1; k <= A[i][j]; k++ ) {
		if( j - k < 0 ) break; 
		if( A[i][j - k] ) kick( i, j - k ); 
	}
	A[i][j] = 0; 
} 

int main() {
	while( scanf( "%d%d", &M, &N ) != EOF ) {
		for( int i = 0; i < M; i++ )
		for( int j = 0; j < N; j++ )
			scanf( "%d", &A[i][j] );
		K = 0; 
		for( int i = M - 1; i >= 0; i-- )
		for( int j = N - 1; j >= 0; j-- )
			if( A[i][j] ) {
				kick( i, j );
				K++;
			}
		printf( "%d\n", K ); 
	} 
} 
