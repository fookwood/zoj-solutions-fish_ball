#include <cstdio>

int main() {
	int	N,	K,	S;
	while( scanf( "%d%d", &N, &K ) != EOF ) {
		S = 0;
		for( int i = 1; i <= N; i++ ) {
			S += K % i;
			printf( "%d ", K % i );
		}
		puts("");
//		printf( "%d\n", S );
	}
}
