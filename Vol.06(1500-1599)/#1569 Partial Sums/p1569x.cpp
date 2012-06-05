// 直接求累加后枚举 TLE 

#include <cstdio>

int main() {
	int	A[10000],	B[10001];
	int	M,	N,	count;
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		B[0] = count = 0;
		for( int i = 0; i < N; i++ ) {
			scanf( "%d", A + i );
			B[i + 1] = B[i] + A[i];
		}
		for( int i = 0; i < N; i++ )
			for( int j = i + 1; j <= N; j++ )
				if( ( B[j] - B[i] ) % M == 0 )
					count++;
		printf( "%d\n", count );
	}
}
