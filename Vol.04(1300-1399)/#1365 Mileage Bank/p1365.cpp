#include <iostream>
using namespace std;

int main() {
	string	s;
	while( cin >> s ) {
		if( s[0] == '#' ) break;
		if( s[0] == '0' ) {
			cout << 0 << endl;
			continue;
		}
		int	temp,	sum = 0; 
		bool	first = 1;
		while( 1 ) {
			if( first ) first = 0;
			else {
				cin >> s;
				if( s[0] == '0' )
					break; 
			} 
			cin >> s >> temp >> s;
			switch( s[0] ) {
				case 'F': 	sum += ( temp + temp ); break; 
				case 'B': 	sum += ( ( temp - 1 ) / 2 + 1 + temp ); break; 
				case 'Y': 	if( temp <= 500 ) sum += 500;
						else	sum += temp;
			} 
		}
		cout << sum << endl; 
	} 
} 
