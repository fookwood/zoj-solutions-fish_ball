#include <cstdio>

int main() {
	int	T,	N,	min,	max,	temp;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d", &N );
		min = 99;
		max = 0;
		while( N-- ) {
			scanf( "%d", &temp );
			if( temp > max ) max = temp;
			if( temp < min ) min = temp;
		}
		printf( "%d\n", ( max - min ) * 2 );
	}
} 
