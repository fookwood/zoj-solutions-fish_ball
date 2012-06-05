// ¼òµ¥Ä£Äâ 
#include <cstdio>

int main() {
	int	G[20][20];
	int	M,	N;
	while( scanf( "%d%d", &M, &N ) != EOF ) {
		if( !M && !N ) break;
		for( int i = 1; i <= M; i++ ) {
			G[i][0] = G[i][N + 1] = 1;
			for( int j = 1; j <= N; j++ )
				scanf( "%d", &G[i][j] );
		}
		for( int j = 0 ; j <= N + 1; j++ )
			G[0][j] = G[M + 1][j] = 1;
		bool	all = false;
		bool	adj = false;
		for( int i = 1; i <= M; i++ )
		for( int j = 1; j <= N; j++ ) {
			if( G[i][j] ) continue;
			else {
				all = true;
				if( !( G[i - 1][j] && G[i + 1][j] &&
				       G[i][j - 1] && G[i][j + 1] )) {
					adj = true;
					break;
				}
			}
			if( adj ) break;
		}
		printf( ( all && !adj ) ? "Yes\n" : "No\n" );
	}
}
