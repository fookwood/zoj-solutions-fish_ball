// 3067271 2008-09-12 12:24:25 Accepted 2777 C++ 00:00.10 392K 呆滞的慢板 

// 做成了一个 DP 

#include <cstdio>
#include <cstring>

inline int gcd( int m, int n ) {
	while( n ) {
		int	r = m % n;
		m = n;
		n = r;
	}
	return	m;
}

int main() {
	int	P[1001];
	P[0] = 0;
	P[1] = 3;
	for( int i = 2; i <= 1000; i++ ) {
		P[i] = 0;
		for( int j = 1; j < i; j++ )
			if( gcd( i, j ) == 1 ) P[i]++;
		P[i] *= 2;
		P[i] += P[i - 1];
	}
	int	T = 1,	N;
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ ) {
		scanf( "%d", &N );
		printf( "%d %d %d\n", t, N, P[N] );
	}
}
