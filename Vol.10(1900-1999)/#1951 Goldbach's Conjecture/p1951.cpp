#include <cstdio>
#include <cstring>

int main() {
	// 生成质数表 
	char	A[1000000];
	memset( A, 1, 1000000 );
	for( int i = 2; i <= 1000; i++ ) {
		if( A[i] )
		for( int j = i + i; j < 1000000; j += i )
			A[j] = 0;
	}
	int	Prime[78498],	top = 0,	N;
	for( int i = 2; i < 1000000; i++ )
		if( A[i] ) Prime[top++] = i;
	// 检验 
	while( scanf( "%d", &N ) && N ) {
		for( int i = 0; i < N; i++ ) {
			if( A[N - Prime[i]] ) {
				printf( "%d = %d + %d\n", N, Prime[i], N - Prime[i] );
				break;
			}
		}
	}
}
