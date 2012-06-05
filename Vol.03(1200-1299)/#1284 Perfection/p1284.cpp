#include <cstdio>

int main() {
	int	N;
	printf( "PERFECTION OUTPUT\n" );
	while( scanf( "%d", &N ) != EOF ) {
		if( !N ) break;
		int	sum = 0;
		for( int i = N >> 1; i; i-- )
			if( !( N % i ) ) sum += i;
		printf( "%5d  ", N );
		if( sum == N )
			printf( "PERFECT\n" );
		else if( sum < N )
			printf( "DEFICIENT\n" );
		else	printf( "ABUNDANT\n" );
	}
	printf( "END OF OUTPUT\n" );
}
