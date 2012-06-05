// 很有水平的一道数论题，不难，但要拐一下弯
// 从 p = 1..9
// 例如：2222 = 222 * 10 + 2
// 那么：如果 2222 % K = ( 222 * 10 % K + 2 % K ) % K 
// 同理，从一开始就可以推知 Xi = ( Xi-1 * 10 + p % K ) % K
// 然后再用 Xi 去对 K 求余即可 
// 而且，假如这样做了 K 次未有结果，那么 Xi 必有循环，那么就永远不可能了
// 我自己笨了~~后来看别人报告才知道了 

#include <iostream>
using namespace std;

int main() {
	int	N;
	while( cin >> N ) {
		bool	found = false;
		for( int i = 1; i < 10; i++ ) {
			int	sum = 0;
			for( int k = 1; k <= N; k++ ) {
				sum = ( sum * 10 + i ) % N;
				if( !sum ) {
					cout << i << ' ' << k << endl;
					found = true;
					break;
				}
			}
			if( found ) break;
		}
		if( found )	continue;
		cout << -1 << endl;
	}
}
