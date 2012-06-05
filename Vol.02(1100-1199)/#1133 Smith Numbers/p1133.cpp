// 主要还是质数表的产生
// 可惜的是居然看错题 WA 若干次
// 质数是不算在内的！！ 

#include <cstdio>
#include <cstring>

inline int pack( int x ) {
	int	sum = 0;
	while( x ) {
		sum += x % 10;
		x /= 10;
	}
	return	sum;
}

int main() {
	char	A[11000];
	memset( A, 1, 11000 );
	A[0] = A[1] = 0;
	for( int i = 2; i < 106; i++ ) {
		if( A[i] )
		for( int j = i + i; j < 11000; j += i ) {
			A[j] = 0;
		}
	}
	int	Prime[1336],	top = 0;
	for(int i = 0; i < 11000; i++)
		if( A[i] )	Prime[top++] = i;
	int	N;
	while( scanf( "%d", &N ) && N ) {
		int	i,	sum,	x;
		for( i = N + 1; ; i++ ) {
			x = i;
			sum = 0;
			for( int j = 0; Prime[j] * Prime[j] <= i; j++ ) {
				if( x % Prime[j] == 0 ) {
					sum += pack( Prime[j] );
					x /= Prime[j--];
				}
				if( x == 1 ) break;
			}
			if( sum == 0 )	continue;
			if( x > 1 )	sum += pack( x );
			if( sum == pack( i ) ) break;
		}
		printf( "%d\n", i );
	}
}
