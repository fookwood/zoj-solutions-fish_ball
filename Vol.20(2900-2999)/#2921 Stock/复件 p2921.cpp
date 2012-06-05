// Greedy
#include <cstdio>

int main() {
	int	A[100000],	p[100000],	m[100000],	sum;
	int	T,	N;
	scanf( "%d", &T ); 
	while( T-- ) {
		scanf( "%d", &N ); 
		sum = 0; 
		for( int i = 0; i < N; i++ )
			scanf( "%d%d%d", A + i, p + i, m + i );
		while( 1 ) { 
			int	max = 0, maxi = -1;
			for( int i = 0; i < N; i++ ) {
				if( p[i] && p[i] >= max ) {
					max = p[i];
					maxi = i;
				}
			}
			if( maxi == -1 ) break;
			int	a = 0;
			for( int i = 0; i <= maxi; i++ )	a += A[i];
			int	minus = ( a > m[maxi] ) ? m[maxi] : a;
			sum += minus * p[maxi];
			p[maxi] = 0;
			while( 1 ) {
				if( minus > A[maxi] ) {
					minus -= A[maxi];
					A[maxi--] = 0;
				}
				else {
					A[maxi] -= minus;
					break;
				}
			}
		}	
		printf( "%d\n", sum );
	} 
} 
