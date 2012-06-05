// Í¼ ´«µÝ±Õ°ü DP Warshall Ëã·¨
#include <cstdio>
#include <cstring>

int main() {
	int	T,	N;
	char	A[26][26],	B[26][26];
	char	input[4];
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ ) {
		memset( A, 0, 676 );
		memset( B, 0, 676 );
		scanf( "%d", &N );
		while( N-- ) {
			scanf( "%s", input );
			switch( input[1] ) {
				case '<': A[ input[0] - 'A'][ input[2] - 'A'] =
					  B[ input[0] - 'A'][ input[2] - 'A'] = 1; break;
				case '>': A[ input[2] - 'A'][ input[0] - 'A'] =
					  B[ input[2] - 'A'][ input[0] - 'A'] = 1; break;
			}
		}
		for( int r = 0; r < 26; r++ )
			for( int i = 0; i < 26; i++ )
				for( int j = 0; j < 26; j++ )
					B[i][j] = B[i][j] || B[i][r] && B[r][j];
		printf( "Case %d:\n", t );
		bool	exist = 0;
		for( int i = 0; i < 26; i++ )
			for( int j = 0; j < 26; j++ )
				if( A[i][j] ^ B[i][j] ) {
					printf( "%c<%c\n", 'A' + i, 'A' + j );
					exist = 1;
				}
		if( !exist ) printf( "NONE\n" );
	}
}
 
