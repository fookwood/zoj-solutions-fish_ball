// 很一般的字符串处理，做得很粗糙
// BS 自己，居然 2WA 
#include <iostream>
#include <string>
using namespace std;
	//	  a  b  c  d  e  f  g  h  i  j  k  l  m
bool type[26] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
	//        n  o  p  q  r  s  t  u  v  w  x  y  z
		  0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

int main() {
	string	s;
	while( cin >> s ) {
		if( s == "end" ) break;
		bool	vowel = false;
		for( int i = 0; i < s.size(); i++ ) {
			if( type[ s[i] - 'a' ] ) {
				vowel = true;
				break;
			}
		}
		bool	consc = true;
		for( int i = 0; i < int( s.size() - 2 ); i++ ) {
			if( type[s[i] - 'a'] && type[s[i+1] - 'a'] && type[s[i+2] - 'a'] ||
			   !type[s[i] - 'a'] &&!type[s[i+1] - 'a'] &&!type[s[i+2] - 'a'] ){
				consc = false;
				break;
			}
		}
		bool	doubl = true;
		for( int i = 0; i < int( s.size() - 1 ); i++ ) {
			if( s[i] == s[i + 1] )
				if( s[i] != 'o' && s[i] != 'e' ) {
					doubl = false;
					break;
				}
		}
		cout << '<' << s << "> is ";
		if( !( vowel && consc && doubl ) )
			cout << "not ";
		cout << "acceptable." << endl;
	}
}
