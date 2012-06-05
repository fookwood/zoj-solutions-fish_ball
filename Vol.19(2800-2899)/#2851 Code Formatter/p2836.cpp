#include <iostream>
using namespace std;

int main() {
	int	N,	ts,	tabs,	spc,	spaces;
	string 	s; 
	cin >> N; 
	while( N-- ) {
		tabs = spaces = 0; 
		while(1) {
			getline( cin, s );
			if( s == "##" ) break; 
			ts = spc = 0;
			for( int i = 0; i < s.size(); i++ ) {
				if( s[i] == '\t' ) 	tabs++, ts++;
				else			ts = 0; 
				if( s[i] == ' ' ) 	spc++;
				else			spc = 0;
			}
			spaces += ( 4 * ts + spc ); 
		}
		cout << tabs << " tab(s) replaced" << endl;
		cout << spaces << " trailing space(s) removed" << endl; 
	} 
} 
