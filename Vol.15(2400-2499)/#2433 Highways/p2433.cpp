#include <cstdio>

int main() {
	int	T,	N;
	int	p,	min,	now,	temp,	i; 
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d", &N );
		i = 2;
		min = 0x7FFFFFFF;
		temp = 0; 
		for( int i = 2; i <= N; i++ ) {
			scanf( "%d", &now );
			if( i > 2 && i < N ) 
			if( now - temp < min ) {
				min = now - temp;
				p = i; 
			} 
			temp = now;
		}
		if( N < 4 )	printf( "0\n" );
		else		printf( "%d\n%d 1 %d %d\n", temp + min, p, N, p - 1 );
		if( T ) putchar( '\n' ); 
	}
} 
