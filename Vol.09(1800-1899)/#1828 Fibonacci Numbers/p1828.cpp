// 高精度
// 纯字符串加法，O(n) 

#include <cstdio>
#include <cstring>

int main() {
	char	f[3][1001];
	int	L[3],	index[3],	N;
	while( scanf( "%d", &N ) != EOF ) {
		index[0] = 0;
		index[1] = 1;
		index[2] = 2;
		f[2][0] = f[1][0] = f[0][0] = 1;
		L[0] = L[1] = L[2] = 1;
		for( int i = 2; i < N; i++ ) {
			// 交换指针
			index[0] = ( index[0] + 1 ) % 3;
			index[1] = ( index[1] + 1 ) % 3;
			index[2] = ( index[2] + 1 ) % 3;
			int	j = L[index[2]] = 0;
			char	carry = 0;
			for( ; j < L[index[0]]; j++ ) {
				f[index[2]][j] = carry +
				f[index[0]][j] + f[index[1]][j];
				if( f[index[2]][j] > 9 ) {
					carry = 1;
					f[index[2]][j] -= 10;
				}
				else	carry = 0;
			}
			for( ; j < L[index[1]]; j++ ) {
				f[index[2]][j] = carry +
				f[index[1]][j];
				if( f[index[2]][j] > 9 ) {
					carry = 1;
					f[index[2]][j] -= 10;
				}
				else	carry = 0;
			}
			if( carry ) f[index[2]][j++] = 1;
			L[index[2]] = j;
		}
		for( int i = L[index[2]] - 1; i >= 0; i-- )
			printf( "%d", int( f[index[2]][i] ) );
		putchar( '\n' );
	}
}
