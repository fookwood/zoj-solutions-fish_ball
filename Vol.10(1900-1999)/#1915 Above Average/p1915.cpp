#include <cstdio>

int main() {
	int	C,	N;
	float	mean,	A[1000];
	scanf( "%d", &C );
	while( C-- ) {
		scanf( "%d", &N );
		mean = 0;
		for( int i = 0; i < N; i++ ) {
			scanf( "%f", A + i );
			mean += A[i];
		}
		mean /= N;
		float	count = 0.;
		for( int i = 0; i < N; i++ )
			if( A[i] > mean )
				count += 100.;
		printf( "%0.3f%c\n", count / float( N ), '%' );
	}
} 
