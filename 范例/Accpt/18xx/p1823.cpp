#include <stdio.h>

long long N , p;
int main(int argc, char* argv[])
{
	while ( scanf ( "%lld" , &N ) , N > 0 ) {
		for ( p = 2; p * p <= N; p ++ )
			while ( N % p == 0 ) printf ( "%lld\n" , p ) , N /= p;
		if ( N != 1 ) printf ( "%lld\n" , N );
		printf ( "\n" );
	}
	return 0;
}
