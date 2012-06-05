#include <cstdio>

int main()
{
	int	N;
	scanf( "%d", &N );
	while( N-- ) {
		int	T;
		scanf( "%d", &T );
		int	sum = 1; 
		while( T-- ) {
			int	temp;
			scanf( "%d", &temp );
			sum += ( temp - 1 ); 
		}
		printf( "%d\n", sum ); 
	} 
} 
