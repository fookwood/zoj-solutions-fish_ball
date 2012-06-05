// 再现质数表，这次有意识把质数表开大了... 

#include <cstdio>
#include <cstring>


int main() {
	char	A[1098304];
	int	Prime[85597],	top = 0;
	memset( A, 1, 1098304 );
	A[0] = A[1] = 0;
	for( int i = 2; i < 1048; i++ )
		if( A[i] ) for( int j = i + i; j < 1098304; j += i )
			A[j] = 0;
	for( int i = 0; i < 1098304; i++ )
		if( A[i] ) Prime[top++] = i;
	int	N;
	while( scanf( "%d", &N ) != EOF ) {
		if( A[N] ) {
			printf( "No\n" );
			continue;
		}
		int	count = 0, pos = 0;
		while( N > 1 ) {
			if( N % Prime[pos++] )	continue;
			N /= Prime[--pos];
			count++;
		}
		printf( count == 2 ? "Yes\n" : "No\n" );
	}
}
