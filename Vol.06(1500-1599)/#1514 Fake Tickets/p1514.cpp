#include <cstdio>

int main() {
	int	N,	M;
	int	A[10001];
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		if( !M && !N ) break;
		for( int i = 1; i <= N; i++ )
			A[i] = 0;
		int	count = 0,	temp; 
		while( M-- ) {
			scanf( "%d", &temp );
			if( A[temp] == 1 ) {
				count++;
				A[temp] = 2;
			}
			else if( A[temp] == 0 )
				A[temp] = 1; 
		} 
		printf( "%d\n", count ); 
	}
} 
