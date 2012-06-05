#include <string>
#include <iostream>
using namespace std; 

string add( string s1, string s2 ) {
	if( s2.size() > s1.size() ) {
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}
	string v("");
	int	i = 1,	rem = 0; 
	for( ; i <= s2.size(); i++ ) {
		rem = rem + s1[ s1.size() - i ] + s2[ s2.size() - i ] - '0' - '0';
		v = char('0' + rem % 10) + v;
		rem /= 10; 
	}
	for( ; i <= s1.size(); i++ ) {
		if( !rem )
			v = s1[s1.size() - i] + v;
		else if( s1[s1.size() - i] == '9' )
			v = '0' + v;
		else {
			v = char(s1[s1.size() - i] + 1) + v;
			rem = 0; 
		} 
	}
	if( rem ) v = '1' + v;
	return v; 
} 

int main() {
	int	N;
	cin >> N; 
	while( N-- ) {
		string	s1(""),	s2;
		while( cin >> s2 ) {
			if( s2 == "0" )
				break;
			else
				s1 = add( s1, s2 );
		} 
		cout << s1 << endl;
		if( N )	cout << endl; 
	}
} 
