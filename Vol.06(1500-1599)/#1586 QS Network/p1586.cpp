// 最小生成树，Prim 算法

#include <cstdio> 

int main() {
	int ( *adj )[1000] = new int[1000][1000];
	int	adapter[1000],	point[1000],	N,	T;
	scanf( "%d", &T );
	while( T-- ) {
		scanf( "%d", &N );
		for( int i = 0; i < N; i++ )
			scanf( "%d", adapter + i ); 
		for( int i = 0; i < N; i++ ) {
			for( int j = 0; j < N; j++ ) {
				scanf( "%d", &adj[i][j] );
				if( i != j ) adj[i][j] += ( adapter[i] + adapter[j] );
			}
		}
		for( int i = 1; i < N; i++ ) {
			adapter[i - 1] = adj[0][i];
			point[i - 1] = i;
		}
		int	top = N - 1,  sum = 0,	prev = 0;
		for( int i = 1; i < N; i++ ) {
			int	mini = 0,	min = 0x7FFFFFFF;
			for( int j = 0; j < top; j++ ) {
				if( min > adapter[j] ) {
					min = adapter[j];
					mini = j;
				}
			}
			sum += min;
			prev = point[mini];
			for( int j = 0; j < top; j++ )
				if( adj[point[j]][point[mini]] < adapter[j] )
					adapter[j] = adj[point[j]][point[mini]];
			for( int j = mini; j < top - 1; j++ ) {
				adapter[j] = adapter[j + 1];
				point[j] = point[j + 1];
			}	
			top--;
		}
		printf( "%d\n", sum );
	}
	 
} 
