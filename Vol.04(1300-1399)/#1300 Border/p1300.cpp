// Simple
#include <cstring>
#include <cstdio>

int main() {
	char	A[32][32];
	char	path[999];
	int	T,	posX,	posY;
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ ) {
		scanf( "%d%d%s", &posX, &posY, path );
		printf( "Bitmap #%d\n", t );
		memset( A, '.', 1024 );
		for( int i = 0; path[i] != '.'; i++ ) {
			switch( path[i] ) {
				case 'N': A[posX][posY++] = 'X';	break;
				case 'S': A[posX - 1][--posY] = 'X';	break;
				case 'E': A[posX++][posY - 1] = 'X';	break;
				case 'W': A[--posX][posY] = 'X';	break;
			}
		}
		for( int i = 31; i >= 0; i-- ) {
			for( int j = 0; j < 32; j++ )
				putchar( A[j][i] );
			putchar( '\n' );
		}
		putchar( '\n' );
	}
}
