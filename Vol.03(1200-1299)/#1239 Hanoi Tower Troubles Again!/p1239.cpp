// 模拟问题，蛮力思考，贪心策略，DP编码
// 最优性未经证明，一半是蒙的 
#include <iostream>
#include <cmath>
using namespace std;

inline bool isquad( int x ) {
	int	y = int( round( sqrt( double( x ) ) ) );
	return	y * y == x;
}

int main() {
	int	A[51],	B[51],	J = 1,	peg = 0;
	for( int i = 0; i < 51; i++ ) A[i] = 0;
	while( peg < 51 ) {
		bool	success = false;
		for( int i = 0; i < peg; i++ ) {
			if( isquad( A[i] + J ) ) {
				success = true;
				A[i] = J++;
				break;
			}
		}
		if( !success ) {
			A[peg] = J;
			B[peg++] = J++;
		}
	}
	cin >> J; 
	while( J-- ) {
		cin >> peg; 
		cout << B[peg] - 1 << endl;
	}
}
