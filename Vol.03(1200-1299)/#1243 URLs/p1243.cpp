#include <cstdio>

int main() {
	char	url[61];
	int	N;
	scanf( "%d ", &N );
	for( int T = 1; T <= N; T++ ) {
		printf( "URL #%d\n", T );
		gets( url );
		int	a = 0,	b = 0,	c = 0, d = 0;
		for( int i = 0; url[i]; i++ ) {
			if( !a && url[i] == ':' ) {
				url[i] = 0;
				b = a = ( i += 3 );
			}
			if( a && url[i] == ':' ) {
				url[i++] = 0;
				c = i;
			}
			if( a && !d && url[i] == '/' ) {
				url[i] = 0;
				d = i + 1;
				break;
			}
		}
		printf( "Protocol = %s\nHost     = %s\n", url, url + b );
		printf( "Port     = " );
		if( c )	printf( "%s\n", url + c );
		else	printf( "<default>\n" );
		printf( "Path     = " );
		if( d )	printf( "%s\n\n", url + d );
		else	printf( "<default>\n\n" );
	}
}
