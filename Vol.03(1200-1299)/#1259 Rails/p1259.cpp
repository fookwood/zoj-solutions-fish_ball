#include <cstdio>

int main() {
	int	N;
	int	A[1001], B[1001];
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		while( 1 ) {
			scanf( "%d", B + 1 );
			if( !B[1] ) break;
			for( int i = 2; i <= N; i++ )
				scanf( "%d", B + i );
			int	n = 2,	push = 2;
			bool	yes = 1; 
			A[0] = 0; A[1] = 1; 
			for( int i = 1; i <= N; ) {
				if( B[i] > A[n - 1] )
					A[n++] = push++;
				else if( B[i] == A[n - 1] ) {
					n--; 
					i++; 
				}
				else if( n - 1 && B[i] < A[n - 1] ) {
					yes = 0;
					break; 
				} 
			} 
			printf( yes ? "Yes\n" : "No\n" ); 
		} 
		putchar( '\n' );
	} 
} 
