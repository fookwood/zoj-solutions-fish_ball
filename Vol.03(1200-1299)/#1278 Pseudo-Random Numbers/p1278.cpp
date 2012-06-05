// 血腥解决，超级暴力，很马虎的一道题，仔细做或许有公式 
#include <cstdio>
#include <cstring>

int main() {
	int	Z,	I,	M,	L,	T = 1;
	char	A[10000];
	while( scanf( "%d%d%d%d", &Z, &I, &M, &L ) != EOF ) {
		if( !Z && !I && !M && !L ) break;
		memset( A, 0, M + 1 );
		int	count = 0;
		while( !A[L] ) {
			count++;
			A[L] = 1;
			L = ( Z * L + I ) % M;
		}
		memset( A, 0, M + 1 );
		count = 0;
		while( !A[L] ) {
			count++;
			A[L] = 1;
			L = ( Z * L + I ) % M;
		}
		printf( "Case %d: %d\n", T++, count );
	}
}
