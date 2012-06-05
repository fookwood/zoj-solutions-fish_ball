// O(n^3) µÄÔ¤ÅÅÐò + Ö±½Ó DP
// TLE 
#include <cstdio>
#include <cstdlib>

int cmp ( const void *a, const void *b ) {
    return *( int* )a > *( int* )b;
}

int main() {
	int	max,	N,	A[1000];
	int	(*B)[1000] = new int[1000][1000];
	int	(*C)[1000] = new int[1000][1000];
	while( scanf( "%d", &N ) != EOF ) {
		for( int i = 0; i < N; i++ ) scanf( "%d", A + i );
		qsort( A, N, 4, cmp );
		for( int i = 0; i < N - 1; i++ )
			for( int j = i + 1; j < N; j++ )
				B[i][j] = A[j] - A[i];
		for( int i = 0; i < N - 1; i++ ) {
			for( int j = i + 1; j < N; j++ ) {
				for( int k = max = 0; k < i; k++ )
					if( B[k][i] == B[i][j] && C[k][i] > max )
						max = C[k][i];
				C[i][j] = max + 1;
			}
		}
		max = 0;
		for( int i = 0; i < N - 1; i++ )
			for( int j = i + 1; j < N; j++ )
				if( C[i][j] > max )
					max = C[i][j];
		printf( "%d\n", max + 1 );
	}
}
