// 很精美的位运算题 

#include <iostream>
using namespace std;

int main() {
	unsigned short	A[7000];
	int	N;
	while( ( cin >> N ) && N != -1 ) {
		for( int i = 0; i < N; i++ ) cin >> A[i];
		int	temp,	sign,	sum = 0;
		for( int count = 0; count < N * 16; count++ ) {
			int	x = count / 16;
			int	y = count % 16;
			bool	bit = A[x] & ( ( ( unsigned short )( 0x8000 ) >> y ) );
			if( count % 7 == 0 ) {
				temp = 0;
				sign = bit ? -1 : 1;
			}
			else {
				temp *= 2;
				temp += bit ? 1 : 0;
				if( count % 7 == 6 ) sum += sign * temp;
			}
		}
		cout << sum << endl;
	}
}
