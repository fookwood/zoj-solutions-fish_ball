#include <iostream>
#include <string> 
using namespace std;

int main() { 
	const string list[7] = { "%20", "%21", "%24", "%25", "%28", "%29", "%2a" };
	string	s1,	s2; 
	while( getline( cin, s1 ) ) {
		if( s1 == "#" ) break; 
		s2 = "";
		for( int i = 0; i < s1.size(); i++ ) {
			switch( s1[i] ) {
				case ' ': s2 += list[0]; break;
				case '!': s2 += list[1]; break;
				case '$': s2 += list[2]; break;
				case '%': s2 += list[3]; break;
				case '(': s2 += list[4]; break;
				case ')': s2 += list[5]; break;
				case '*': s2 += list[6]; break;
				default : s2 += s1[i];
			} 
		} 
		cout << s2 << endl; 
	}
} 
