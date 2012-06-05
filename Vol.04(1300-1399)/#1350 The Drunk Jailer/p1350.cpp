#include <cstdio>

bool	A[101];

int fun( int N ) {
	for( int i = 1; i <= N; i++ )
		A[i] = true;
	for( int n = 2; n <= N; n++ )
		for( int i = n; i <= N; i += n )
			A[i] = !A[i];
	int	count = 0;	
	for( int i = 1; i <= N; i++ )
		if( A[i] ) count++;
	return	count;
}

int main() {
	int	N,	T;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d", &N );
		printf( "%d\n", fun( N ) );
	}
} 
