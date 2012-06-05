#include <cstdio> 
#include <cstring>

int main() {
	int	N;
	char	s[1001]; 
	scanf( "%d", &N );
	while( N-- ) {
		scanf( "%s", s );
		int	L = strlen(s),	count = 1;
		for( int i = 0; i < L; i++ ) {
			if( s[i] == s[i + 1] && i < L - 1 )
				count++;
			else {
				printf( "%d%c", count, s[i] ); 
				count = 1; 
			}
		}
		putchar( '\n' ); 
	} 
} 
