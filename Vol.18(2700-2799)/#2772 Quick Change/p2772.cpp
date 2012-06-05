// 容易证明贪心的最优性 

#include <iostream>
using namespace std;

int main() {
	int	N,	X;
	cin >> N;
	for( int i = 1; i <= N; i++ ) {
		cin >> X;
		cout << i << ' ';
		cout << X / 25 << " QUARTER(S), ";
		X %= 25;
		cout << X / 10 << " DIME(S), ";
		X %= 10;
		cout << X / 5 << " NICKEL(S), ";
		X %= 5;
		cout << X << " PENNY(S)" << endl;
	}
}
