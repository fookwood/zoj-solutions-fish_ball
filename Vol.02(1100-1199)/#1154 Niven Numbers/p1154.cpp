#include <iostream>
#include <string>
using namespace std; 

int main() {
	int	T;
	cin >>	T;
	while( T-- ) {
		int	B,	v1,	v2;
		string	S;
		while( cin >> B ) {
			if( !B ) break;
			cin >> S;
			v1 = v2 = 0;
			for( int i = 0; i < S.size(); i++ ) {
				int	temp = int( S[i] - '0' );
				v1 += temp;
				v2 *= B;
				v2 += temp;
			}
			cout << ( ( v2 % v1 ) ? "no" : "yes" ) << endl;
		}
		if( T ) cout << endl;
	}
}
