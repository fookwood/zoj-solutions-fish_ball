#include <cstdio>

int main() {
	int	N,	T,	temp;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d", &N );
		for( int i = 10; i < N ; i *= 10 ) {
			temp = N % i * 10 / i;
			if( temp >= 5 ) N += ( ( 10 - temp ) * i / 10 ); 
			else		N -= ( ( temp * i ) / 10 );
		}
		printf( "%d\n", N ); 
	} 
}
