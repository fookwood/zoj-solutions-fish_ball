#include <cstdio>

int main() {
	int	N,	a,	b,	sum;
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		a = sum = 0;
		while( N-- ) {
			scanf( "%d", &b );
			if( b - a > 0 )	sum += ( b - a ) * 6; 
			else		sum += ( a - b ) * 4; 
			sum += 5; 
			a = b; 
		}
		printf( "%d\n", sum ); 
	} 
} 
