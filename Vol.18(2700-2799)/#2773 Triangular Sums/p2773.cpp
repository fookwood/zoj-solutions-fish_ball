// 有闭合公式，可用霍纳法则算多项式，注意数据范围 

#include <iostream>
using namespace std;

int main() {
	int	N;
	long long	X;
	cin >> N;
	for( int i = 1; i <= N; i++ ) {
		cin >> X;
		cout << i << ' ' << X << ' ' <<
		( X * ( X * ( X * ( X + 6 ) + 11 ) + 6 ) / 8 ) << endl;
	}
}
