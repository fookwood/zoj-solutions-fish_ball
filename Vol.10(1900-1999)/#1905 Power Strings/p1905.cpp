#include <cstdio>
#include <cstring> 

bool	strequ( char* str1, char* str2, int n ) {
	bool	exit = 1;
	for( int i = 0; i < n; i++ ) {
		if( str1[i] != str2[i] ) {
			exit = 0; 
			break; 
		}
	} 
	return	exit; 
} 

int main() {
	char	s[1000000];
	while( scanf( "%s", s ) ) {
		if( *s == '.' ) break; 
		int	N = strlen( s );
		for( int i = 1; i <= N; i++) {
			if( N % i == 0 ) {
				int	M = N / i; 
				bool	match = 1;
				for( int j = 0; j < M; j++ ) {
					if( !strequ( s, s + j * i, i ) ) {
						match = 0;
						break; 
					}
				} 
				if( match ) {
					printf( "%d\n", M ); 
					break; 
				} 
			} 
		} 
	} 
} 
