// 超简单，收敛性很好 

#include <iostream>
#include <string>
using namespace std;

int main() {
	string	skew;
	int	ans;
	while( ( cin >> skew ) && skew != "0" ) {
		ans = 0;
		for( int i = 1; i <= skew.size(); i++ )
			ans += ( ( 1 << i ) - 1 ) * ( skew[skew.size() - i] - '0' );
		cout << ans << endl;
	}
}
