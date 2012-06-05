#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string	lake;
	while( cin >> lake ) {
		if( lake == "END" ) break;
		int	mx = 0,	my = 1;
		int	mc = 0, ml = 0; 
		for( int x = 0; x < lake.size(); x++ ) {
			for( int y = 1; y <= lake.size() - x; y++ ) {
				int	c = 0;
				int	l = x; 
				while( 1 ) {
					if( lake[l] == '.' )	c++;
					else			break;
					if( l + y >= lake.size() ) break;
					l += y;
				}
				if( c * 1000000 + l * 10000 + x * 100 - y >
				    mc * 1000000 + ml * 10000 + mx * 100 - my ) {
					mx = x;
					my = y;
					mc = c;
					ml = l;
				}
			} 
		}
		cout << mx << ' ' << my << endl;
	} 
} 
