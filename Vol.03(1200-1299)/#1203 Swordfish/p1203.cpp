// 最小生成树，贪心算法，两种:
// Prim's Algrithm
// Kruskal's Algorithm /via/ Dijkstra's Algorithm

#include <iostream>
#include <vector> 
#include <cmath>
using namespace std;

// 记录结构，第一个参数是当前最近相邻点，第二个参数是最近距离
struct Record {
	Record(){}
	Record( int i, double d ) : index( i ), distance( d ) {}
	int	index;
	double	distance;
};

inline double dis( double x1, double y1, double x2, double y2 ) {
	return	hypot( ( x1 - x2 ), ( y1 - y2 ) );
}

int main() {
	const double FINF = 200000.;
	int	N,	T = 0;
	double	x[1000],	y[1000];
	vector<Record>	Q;
	while( cin >> N ) {
		if( !N ) break;
		if( T++ ) cout << endl;
		Q.resize( 0 );
		cin >> x[0] >> y[0];
		// 初始化队列
		for( int i = 1; i < N; i++ ) {
			cin >> x[i] >> y[i];
			Q.push_back( Record( i, FINF ) );
		}
		double	tot = 0;
		int	current = 0;
		while( Q.size() ) {
			int	imin = 0;
			double	min = FINF;
			for( int i = 0; i < Q.size(); i++ ) {
				double	temp = dis( x[Q[i].index], y[Q[i].index],
						    x[current],    y[current]  );
				if( Q[i].distance > temp )
					Q[i].distance = temp;
				if( Q[i].distance < min ) {
					imin = i;
					min = Q[i].distance;
				}
			}
			current = Q[imin].index;
			tot += Q[imin].distance;
			Q.erase( Q.begin() + imin );
		}
		cout << "Case #" << T << ":\nThe minimal distance is: ";
		cout.setf( ios :: fixed );
		cout.precision( 2 );
		cout << tot << endl;
	}
}
