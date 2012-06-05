#include <cstring>
#include <cstdio>

int main() {
	int	N;
	char	s[71];
	scanf( "%d", &N );
	getchar(); 
	while( N-- ) {
		gets( s );
		for( int i = strlen(s) - 1; i >= 0; i-- )
			putchar( s[i] );
		putchar( '\n' ); 
	} 
} 
