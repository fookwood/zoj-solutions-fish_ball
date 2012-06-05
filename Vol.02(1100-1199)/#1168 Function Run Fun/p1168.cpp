// Simple Dynamic Programming

#include <cstdio>
#include <cstring>

int A[21][21][21];

int W( int a, int b, int c ) {
	if( a <= 0  || b <= 0  || c <= 0  )	return	1;
	if( a > 20 || b > 20 || c > 20 )
		return	W( 20, 20, 20 );
	if( A[a][b][c] )	return A[a][b][c];
	if( a < b && b < c ) {
		A[a][b][c] = W( a, b, c - 1 ) +
			     W( a, b - 1, c - 1 ) -
			     W( a, b - 1, c );
		return	A[a][b][c];
	}
	else {
		A[a][b][c] = W( a - 1, b, c ) +
			     W( a - 1, b - 1, c ) +
			     W( a - 1, b, c - 1 ) -
			     W( a - 1, b - 1, c - 1 );
		return	A[a][b][c];
	}
} 

int main() {
	int	a,	b,	c;
	memset( A, 0, 21 * 21 * 21 * sizeof( int ) );
	while( scanf( "%d%d%d", &a, &b, &c ) != EOF ) {
		if( a == -1 && b == -1 && c == -1 )	break;
		else	printf( "w(%d, %d, %d) = %d\n", a, b, c, W( a, b, c ) );
	}
} 
