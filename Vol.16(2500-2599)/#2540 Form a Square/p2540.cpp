// 用 STL 偷懒了，枚举所有点对的组合，求出所有的两点间距离
// 将 6 个距离排序，那么只要前四个相等，后两个相等，就是正方形
// 注意精度问题 

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

inline bool equal( double x, double y ) {
	return	fabs( x - y ) < 1e-5;
}

int main() {
	int	T;
	vector<double>	D;
	double	X[4],	Y[4];
	cin >> T;
	for( int t = 1; t <= T; t++ ) {
		D.resize( 0 );
		for( int i = 0; i < 4; i++ ) {
			cin >> X[i] >> Y[i];
			for( int j = 0; j < i; j++ )
				D.push_back( hypot( X[j] - X[i], Y[i] - Y[j] ) );
		}
		sort( D.begin(), D.end() );
		cout << "Case " << t << ':' << endl;
		if( equal( D[0], D[1] ) && equal( D[0], D[2] ) &&
		    equal( D[0], D[3] ) && equal( D[4], D[5] ) )
			cout << "Yes" << endl;
		else	cout << "No" << endl;
		if( t != T )	cout << endl;
	}
}
