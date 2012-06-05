#include <cstdio>

int main() {
	int	N;
	while( scanf( "%d", &N ) != EOF ) {
		int	n = N,	count = 0; 
		for( int i = 0; i < 3; i++ ) {
			int	p = n % 10; 
			count += p * p * p;
			n /= 10; 
		} 
		if( count == N )
			printf( "Yes\n" );
		else
			printf( "No\n" );
	} 
} 
 
