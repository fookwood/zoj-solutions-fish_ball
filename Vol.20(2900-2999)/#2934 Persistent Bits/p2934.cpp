#include <cstdio>
#include <cstring>  

int gcd( int m, int n) {
	if( !n ) return m;
	else	 return gcd( n, m % n ); 
}  

inline void trans( char str[], int n ) {
	for( int j = 32768, i = 0; i < 16; j >>= 1, i++ )
		str[i] = char( ( n & j ) != 0 ) + '0';
}

inline void compare( char str[], char temp[] ) {
	for( int i = 0; i < 16; i++ ) {
		if( str[i] == '?' ) continue;
		str[i] = ( str[i] == temp[i] ) ? str[i] : '?'; 
	} 
}

int main() {
	int	A,	B,	C,	S;
	char	str[17],	temp[17];
	while( scanf( "%d", &A ) != EOF ) {
		if( !A ) break;
		memset( str, 0, 17 );
		memset( temp, 0, 17 ); 
		scanf( "%d%d%d", &B, &C, &S );
		int	k = C / gcd( A, C );
		trans( str, S );
		for( int i = 1; i < k; i++ ) {
			S = ( A * S + B ) % C;
			trans( temp, S ); 
			compare( str, temp );
		} 
		printf( "%s\n", str ); 
	} 
} 
