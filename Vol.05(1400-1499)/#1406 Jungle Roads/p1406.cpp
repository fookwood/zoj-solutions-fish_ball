// 最小生成树，Prim 算法
// 写得比较赤裸~~不太优美 
 
#include <cstdio>
#include <cstring>

int main() {
	int	N,	M,	adj[26][26];
	char	input[2];
	while( ( scanf( "%d", &N ) ) && N ) {
		memset( adj, 0, 4 * 26 * 26 );
		for( int i = 0; i < N - 1; i++ ) {
			scanf( "%s%d", input, &M );
			for( int j = 0; j < M; j++ ) {
				scanf( "%s", input );
				scanf( "%d", &adj[i][*input - 'A'] );
				adj[*input - 'A'][i] = adj[i][*input - 'A'];
			}
		}
		int	path[26];
		bool	label[26];
		for( int i = 0; i < N; i++ ) {
			path[i] = 0x7FFFFFFF;
			label[i] = true;
		}
		label[0] = false;
		int	current = 0,	sum = 0;
		for( int n = 1; n < N; n++ ) {
			int	min = 0x7FFFFFFF, mini = -1;
			for( int i = 0; i < N; i++ ) {
				if( label[i] && adj[current][i] ) {
					if( adj[current][i] < path[i] )
					path[i] = adj[current][i];
				}
				if( path[i] < min ) {
					min = path[i];
					mini = i;
				}
			}
			sum += min;
			label[mini] = false;
			path[mini] = 0x7FFFFFFF;
			current = mini;
		}
		printf( "%d\n", sum );
	}
}
