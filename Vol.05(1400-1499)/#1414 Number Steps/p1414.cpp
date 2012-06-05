#include <cstdio>

int main() {
	int	T,	x,	y;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d%d", &x, &y );
		if( x < 0 || y < 0 ) 
			printf( "No Number\n" );
		else if( x == y ) {
			if( y % 2 )
				printf( "%d\n", 2 * y - 1 );
			else
				printf( "%d\n", 2 * y );
		}
		else if( x - y == 2 ) {
			if( y % 2 ) {
				printf( "%d\n", 2 * y + 1 );
			}
			else
				printf( "%d\n", 2 * y + 2 );	
		}
		else	printf( "No Number\n" );
	} 
	 
} 
