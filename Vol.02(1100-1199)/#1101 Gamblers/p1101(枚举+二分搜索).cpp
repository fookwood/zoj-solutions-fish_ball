#include <cstdlib>
#include <cstdio>
#include <cstring>

inline int icmp( const void *p, const void *q ) {
	const int *m = ( int* )p, *n = ( int* )q;
	return	*m > *n ? 1 : ( *m == *n ? 0 : -1 );
}

int search( int* A, int N ) {
	for( int pos = N - 1; pos >= 0; pos-- ) {
		for( int i = 0; i < N - 1; i++ ) {
			if( i == pos )	continue;
			for( int j = i + 1; j < N; j++ ) {
				if( j == pos ) continue;
				int	temp = A[pos] - A[i] - A[j];
				int*	p = ( int* )bsearch( &temp, A, N, sizeof( int ), icmp );
				if( p && p - A != j && p - A != i && p - A != pos )
					return	pos;
			}
		}
	}
	return	-1;
}

int main() {
	int	A[1001];
	int	N,	pos;
	while( scanf( "%d", &N ) && N ) {
		for( int i = 0; i < N; i++ )
			scanf( "%d", A + i );
		qsort( A, N, sizeof( int ), icmp );
		pos = search( A, N );
		if( pos == -1 )	printf( "no solution\n" );
		else			printf( "%d\n", A[pos]);
	}
}
