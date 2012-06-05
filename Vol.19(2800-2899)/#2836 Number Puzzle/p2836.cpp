// 容斥原理，先用位二进制生成集合的所有子集
// 如果子集元素个数为奇，则 sum += M / 子集的最小公倍数
// 否则 sum -= ...
// 原则上算法复杂度为 2^N  NP完全，但胜在规模绝小，可以这样做 

// 我这道题 WA 了许多次，真是死不觉悟... 

#include <cstdio>
#include <cstring>

int lcm( int x, int y ) {
	int	m = x,	n = y,	r;
	if( m < n ) {
		r = n;
		n = m;
		m = r;
	}
	while( n ) {
		r = m % n;
		m = n;
		n = r;
	}
	return	x * y / m;
}

int main() {
	int	M,	N,	temp,	sum;
	int	A[11];
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		for( int i = 0; i < N; i++ )
			scanf( "%d", A + i );
		int	sum = 0;
		int	v = 1 << N;
		for( int comb = 1; comb < v; comb++ ) {
			int	count = 0,	factor = 1;
			for( int j = 0; j < N; j++ ) {
				if( ( 1 << j ) & comb ) {
					count++;
					factor = lcm( factor, A[j] );
				}
			}
			if( count % 2 )	sum += M / factor;
			else		sum -= M / factor;
		}
		printf( "%d\n", sum );
	}
}
