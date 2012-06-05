#include <cstdio>
int main() {
	int	N;
	scanf( "%d", &N );
	while( N-- ) {
		int	temp,	ans = 0;
		scanf( "%d", &temp );
		for( int p = 5; p <= temp; p *= 5 )
			ans += temp / p; 
		printf( "%d\n", ans ); 
	} 
} 
