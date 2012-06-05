#include <cstdio>
#include <cstring> 

int main() {
	int	N;
	char	A[201];
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		scanf( "%s", A );
		int	L = strlen( A ); 
		for( int i = 0; i < N; i++ )
			for( int j = i, line = 1; j < L; j += N, line++ )
				if( line & 0x00000001 )	putchar( A[j] );
				else			putchar( A[j + N - 1 - i - i] );
		putchar( '\n' );
	} 
} 
