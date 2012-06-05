// 最小生成树，Kruskal 算法

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int	value;
	int	x,	y;
};

bool icmp( Edge e1, Edge e2 ) {
	return	e1.value < e2.value;
}

struct Vertex {
	int	parent;
	int	index;
};

int main() {
	int	M,	N;
	vector<int>	V;
	vector<Edge>	E;
	vector<Edge>	result;
	while( scanf( "%d%d", &N, &M ) != EOF ) {
		V.resize( N );
		E.resize( M );
		result.resize( 0 );
		for( int i = 0; i < N; i++ )	V[i] = i;
		for( int i = 0; i < M; i++ )
			scanf( "%d%d%d", &E[i].x, &E[i].y, &E[i].value ); 
		sort( E.begin(), E.end(), icmp );
		int	count = 0;
		for( int i = 0; i < M; i++ ) {
			int	p = E[i].x - 1,	s,	t;
			// 并查运算 
			s = p;
			while( V[p] != p ) p = V[p];
			while( s != p ) {
				t = s;
				s = V[s];
				V[t] = p;
			}
			int	q = s = E[i].y - 1;
			while( V[q] != q ) q = V[q];
			while( s != q ) {
				t = s;
				s = V[s];
				V[t] = q;
			}
			// 检测是否在同一树中 
			if( p != q ) {	
				count++;
				V[q] = p;
				result.push_back( E[i] );
			}
			if( count == N - 1 ) break;
		}
		printf( "%d\n%d\n", result.back().value, result.size() );
		for( int i = 0; i < result.size(); i++ )
			printf( "%d %d\n", result[i].x, result[i].y );
	}
}
