#include <cstdio>

int main() {
	int	M,	N,	T = 1,	A[100][100],	temp;
	while( scanf( "%d%d", &M, &N ) ) {
		if( !M && !N ) break;
		for( int k = 0; k < 3; k++ ) 
		for( int i = 0; i < M; i++ )
		for( int j = 0; j < N; j++ ) {
			if( !k )
			 	scanf( "%d", &A[i][j] ); 
			else {
				scanf( "%d", &temp ); 
				A[i][j] += temp;
			} 
		}
		printf( "Case %d:\n", T++ );
		for( int i = 0; i < M; i++ ) {
			for( int j = 0; j < N - 1; j++ )
				printf( "%d,", A[i][j] / 3 );
		 	printf( "%d\n", A[i][N - 1] / 3 );
		}
	}
} 
