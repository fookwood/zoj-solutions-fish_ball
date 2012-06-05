// 遍历所有情况，翻动 16 个格子，共 2^16 种情况
// 用位运算简化逻辑 

#include <cstdio>

int	ans;
int	P[16] = { 0xC800, 0xE400, 0x7200, 0x3100,
		  0x8C80, 0x4E40, 0x2720, 0x1310,
		  0x08C8, 0x04E4, 0x0272, 0x0131,
		  0x008C, 0x004E, 0x0027, 0x0013 };
		  
void DFS( int X, int k, int t ) {
	if( ( X == 0x0000 || X == 0xFFFF ) && t < ans ) ans = t;
	if( k < 16 ) {
		DFS( X ^ P[k], k + 1, t + 1 );
		DFS( X, k + 1, t );
	}
}

int main() {
	int	N;
	scanf( "%d", &N );
	while( N-- ) {
		int	count = 16,	pos = 1;
		int	X = 0;
		while( count ) {
			char	c = getchar();
			if( c == 'w' ) {
				X |= pos;
				count--;
				pos <<= 1;
			}
			else if( c == 'b' ) {
				count--;
				pos <<= 1;
			}
		}
		ans = 0x7FFF;
		DFS( X, 0, 0 );
		if( ans == 0x7FFF )
			printf( "Impossible\n" );
		else	printf( "%d\n", ans );
		if( N )	printf( "\n" );
	}
}
