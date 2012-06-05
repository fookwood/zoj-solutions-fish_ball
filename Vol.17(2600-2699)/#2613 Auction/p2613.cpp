// 简单的时空权衡即可 

#include <cstring>
#include <cstdio>

struct Price {
	char	name[200];
	int	count;
};

int main() {
	Price	bid[10001];
	char	name[200];
	int	T,	U,	M,	temp;
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ ) {
		scanf( "%d%d", &U, &M );
		memset( bid + 1, 0, U * sizeof( Price ) );
		for( int m = 0; m < M; m++ ) {
			scanf( "%s%d", name, &temp );
			if( !bid[temp].count ) strcpy( bid[temp].name, name );
			bid[temp].count++;
		}
		int	min = M + 1, mini;
		for( int i = 1; i <= U; i++ ) {
			if( bid[i].count && bid[i].count < min )	{
				min = bid[i].count;
				mini = i;
			}
		}
		printf( "Case %d:\n", t );
		printf( "The winner is %s.\n", bid[mini].name );
		printf( "The price is %d.\n", mini );
		if( t != T ) putchar( '\n' );
	}
}
