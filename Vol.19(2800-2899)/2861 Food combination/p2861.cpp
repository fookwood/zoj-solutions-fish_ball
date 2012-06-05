// 直接位运算会 TLE 
#include <cstdio>

int	N,	L,	temp;

inline bool isValid( const int &num ) {
	temp = 0;
	for( int i = 0; i < N; i++ )
		if( ( 1 << i ) & num )
			temp++;
	return	temp <= L;
}

int main() {
	int	M;
	while( scanf( "%d%d%d", &N, &L, &M ) != EOF ) {
		int	highest = 0;//( 1 << N ) - 1;
		int	count = 1;
		while( count < M ) {
			if( isValid( highest ) ) count++;
			highest++;
		}
		printf( "%d\n", highest );
	}
}
