#include <cstdio> 

int main() {

	int	N,	p,	X,	A[16385];

	scanf( "%d", &N ); 

	A[0] = A[1] = 0;

	for( int i = 2; i < 16385; i++ )
		A[i] = A[i - 2] + ( i << 1 ) - 3;

	while( N-- ) {

		scanf( "%d", &X );

		if( X & 1 ) p = A[X >> 1] + A[( X >> 1 ) + 1];

		else p = A[X >> 1] << 1;

		printf( "%d\n", p ); 

	} 

} 
