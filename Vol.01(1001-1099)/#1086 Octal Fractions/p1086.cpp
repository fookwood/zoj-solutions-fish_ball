#include <string>
#include <iostream>
using namespace std;

void div( string &dec ) {
	int	x,	y = 0;
	for( int i = 0; i < dec.size(); i++ ) {
		x = int( dec[i] - '0' );
		dec[i] = ( dec[i] + '0' ) / 2 + y;
		y = ( x % 2 ) ? 5 : 0;
	}
	if( y ) dec += '5';
}

void add( string &ans, string &dec ) {
	int	i;
	while( ans.size() < dec.size() )
		ans += '0';
	for( i = ans.size() - 1; i >= 0; i-- ) {
		ans[i] += ( dec[i] - '0' );
		if( ans[i] > '9' ) {
			ans[i] -= 10;
			ans[i - 1]++;
		}
	}
}

int main() {
	string	oct;
	while( cin >> oct ) {
		string	bin("");
		for( int i = 2; i < oct.size(); i++ ) {
			switch( oct[i] ) {
				case '0': bin += "000"; break;
				case '1': bin += "001"; break;
				case '2': bin += "010"; break;
				case '3': bin += "011"; break;
				case '4': bin += "100"; break;
				case '5': bin += "101"; break;
				case '6': bin += "110"; break;
				case '7': bin += "111";				 
			}
		}
		string	dec("5");
		string	ans("");
		for( int i = 0; i < bin.size(); i++ ) {
			if( bin[i] == '1' )
				add( ans, dec );
			div( dec );
		}
		cout << oct << " [8] = 0." << ans << " [10]" << endl;
	} 
} 
