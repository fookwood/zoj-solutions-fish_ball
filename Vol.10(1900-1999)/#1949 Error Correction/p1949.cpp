#include <cstdio>

int main() {
	int	N,	A[100][100];
	int	col[100],	row[100];
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		for( int i = 0; i < N; i++ )
			col[i] = row[i] = 0;
		for( int i = 0; i < N; i++ ) {
			for( int j = 0; j < N; j++ ) {
				scanf( "%d", &A[i][j] );
				col[i] += A[i][j];
				row[j] += A[i][j];
			}
		}
		int	R = 0,	C = 0,	r = -1,	c = -1;
		for( int i = 0; i < N; i++ ) {
			if( row[i] % 2 ) {
				R++;
				r = i;
			}
			if( col[i] % 2 ) {
				C++;
				c = i;
			}
		}
		if( !R && !C )	
			printf( "OK\n" );
		else if( R == 1 && C == 1 )
			printf( "Change bit (%d,%d)\n", c + 1, r + 1 );
		else
			printf( "Corrupt\n" );
	}
} 
